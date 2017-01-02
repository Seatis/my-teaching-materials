#Workshop03 - Object relationships
In this exercise, you'll identify the relationships between tables, following from the guidance given in "[JPA Basic Mapping (Marinho)](https://www.youtube.com/watch?v=8FC_h1xuh-s)".

## Preparation
Set up an project as you did in Workshop02, using MySQL, Lombok, JPA, Take Workshop01 and redo it to instead use mySQL.

## Exercise
Marinho does this exercise in steps.  He does a little bit of work, then tests.  Resets the database, and then goes further.  This is typical.  

### Step 1 - Get the environment running
Ensure that you can connect to the database; that the database is running and reachable; that you can connect.

### Step 2 - Build the Customer
To save you a little time (around 7m30)

```java
package com.greenfox;
//Imports here 
//Annotations here; note that the table name should be "customers"
public class Customer {

    //Annotations here - this is an id, and a generated value whose strategy is  GenerationType.AUTO
    private long id;
    private String name;
}
```

With success, you'll see on the console that the table gets created; but check it also in MySQL.

### Step 3 - Add Orders
Around 12m30.

```java
package com.greenfox;

import lombok.Getter;
import lombok.Setter;
import javax.persistence.*;
//more imports

//Annotations - orders table
public class Order {

    // annotations
    private long id;
    private String name;
    private Date createdAt;

	// reference to the customer table
}
```

### Step 4 - Add Items &amp; Products
One quick way to do this is to copy paste what you've already built and change names.  

However, you'll have to get the relationships right

### Step 5 - Add PhoneNumbers
This amends the Customer class to point to the phone numbers, and phone numbers to point to the customer.  So there are 2 relationships that get defined here.  Around 27m00.

### Step 6 - Add repositories
Around 30m30, he explains how to add the three key repositories, which are all defined as interfaces.
- Customer - add a findByName
- Order - add findByCustomer
- Products - add findByName

These should extend the CrudRepository<?,?>.

### Step 7 - Set up testing
For this you need to be sure to point to the right Spring, class.

Ensure that 2 bits of SQL are set up to prepare the database (clear and populate).  These need to be in a resource file associated with the test.  To save time, here's the sql.

These goes to the resource file associated with the test.

```sql
SET FOREIGN_KEY_CHECKS = 0;
TRUNCATE TABLE items;
TRUNCATE TABLE customers_phones;
TRUNCATE TABLE orders;
TRUNCATE TABLE phone_numbers;
TRUNCATE TABLE customers;
TRUNCATE TABLE products;
SET FOREIGN_KEY_CHECKS = 1;
```

```sql
INSERT INTO customers (name) values ('Marcio');  //id=1
INSERT INTO customers (name) values ('Jonas');   //id=2
INSERT INTO customers (name) values ('Laura');   //id=3
INSERT INTO customers (name) values ('Scarlet'); //id=4
INSERT INTO customers (name) values ('Bishop');  //id=5

INSERT INTO phone_numbers (value) values ('123456');  //id=1
INSERT INTO phone_numbers (value) values ('898765');  //id=2
INSERT INTO phone_numbers (value) values ('333333');  //id=3
INSERT INTO phone_numbers (value) values ('555555');  //id=4
INSERT INTO phone_numbers (value) values ('777777');  //id=5
INSERT INTO phone_numbers (value) values ('888888');  //id=6

INSERT INTO customer_phones (customers_id, phone_numbers_id) values (1,1);  
INSERT INTO customer_phones (customers_id, phone_numbers_id) values (1,4);  
INSERT INTO customer_phones (customers_id, phone_numbers_id) values (3,1);  
INSERT INTO customer_phones (customers_id, phone_numbers_id) values (3,6);  

INSERT INTO products (name) values ('Java Book');  //id=1
INSERT INTO products (name) values ('Baby Pram');  //id=2
INSERT INTO products (name) values ('Ice Cream');  //id=3
INSERT INTO products (name) values ('Pop Corn');   //id=4
INSERT INTO products (name) values ('Mazda 3');    //id=5

INSERT INTO orders (created_at, customer_id) values (NOW(), 2);

INSERT INTO items (order_id, product_id, quantity) values (1,1,5);
INSERT INTO items (order_id, product_id, quantity) values (1,2,3);
INSERT INTO items (order_id, product_id, quantity) values (1,5,2);
```

### Test - shouldReturnManyPhonesForCustomer 
Find Mario who should have 2 phone numbers; this requires use injection (around 35m00 +).

__IMPORTANT__  In the sample code by Marinho, he used `@SpringApplicationConfiguration(classes = JPABasicMappings.class)`.  This is deprecated and replaced with `@SpringBootTest(classes = JPABasicMappings.class)`.  If you don't swap, you'll get  errors stating that it cannot find various javax or springboot.core classes.

Note also that Marinho used `org.hamcrest.MatcherAssert.assertThat` and `org.hamcrest.core.Is.is`.  These are found by Gradle.

```java
package com.greenfox;

import com.greenfox.model.Customer;
import com.greenfox.model.Item;
import com.greenfox.model.Order;
import com.greenfox.model.Product;
import com.greenfox.model.repository.CustomerRepository;
import com.greenfox.model.repository.OrderRepository;
import com.greenfox.model.repository.ProductRepository;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.SpringApplicationConfiguration;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.jdbc.Sql;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.test.context.web.WebAppConfiguration;
import org.springframework.transaction.annotation.Transactional;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import static org.hamcrest.MatcherAssert.assertThat;
import static org.hamcrest.core.Is.is;

@RunWith(SpringJUnit4ClassRunner.class)
@SpringBootTest(classes = JPABasicMappings.class)
@WebAppConfiguration
public class JPABasicMappingsTest {

    @Autowired
    private ProductRepository productRepository;

    @Autowired
    private CustomerRepository customerRepository;

    @Autowired
    private OrderRepository orderRepository;

    @Test
    @Sql({"/clear-tables.sql","/populate-tables.sql"})
    @Transactional
    public void shouldReturnManyPhonesForCustomer() {
        Customer marcio = customerRepository.findByName("Marcio");
        assertThat(marcio.getPhoneNumbers().size(), is(2));
    }
}
```

### Test - shouldDeleteOrder
In this test you have to find the ordres of the customer and that means navigating to the particular customer.

```java
    @Test
    @Sql({"/clear-tables.sql", "/populate-tables.sql"})
    @Transactional
    public void shouldCreateOrder() {

        Customer myself = customerRepository.findByName("Marcio");

        Order order = Order.builder()
                .customer(myself)
                .createdAt(new Date())
                .build();

        Product mazdaCar = productRepository.findByName("Mazda 3");

        Product myPopCorn = productRepository.findByName("Pop Corn");

        Item mazda = Item.builder()
                .product(mazdaCar)
                .order(order)
                .quantity(3)
                .build();

        Item popcorn = Item.builder()
                .product(myPopCorn)
                .order(order)
                .quantity(7)
                .build();

        List<Item> items = new ArrayList<Item>() {{
            add(mazda);
            add(popcorn);
        }};

        order.setItems(items);

        orderRepository.save(order);

        List<Order> orders = (List<Order>) orderRepository.findAll();
        Order foundOrder = orders.get(1);

        assertThat(orders.size(), is(2));
        assertThat(foundOrder.getItems().size(), is(2));
        assertThat(foundOrder.getItems().get(0).getProduct(), is(mazdaCar));
        assertThat(foundOrder.getItems().get(1).getProduct(), is(myPopCorn));

    }
```

### Test - ShouldDeleteOrder

```java
    @Test
    @Sql({"/clear-tables.sql", "/populate-tables.sql"})
    @Transactional
    public void shouldDeleteOrder() {

        Customer jonas = customerRepository.findByName("Jonas");
        Order jonasOrder = orderRepository.findByCustomer(jonas);
        orderRepository.delete(jonasOrder);

        List<Order> orders = (List<Order>)orderRepository.findAll();
        assertThat(orders.size(), is(0));

    }
```

# Links
- [Unit Overview](../../README.md)
- [Prev Workshop01](./Workshop02.md)
- [Next Workshop04](./Workshop04.md)
