#Workshop02 - Swapping Services through Beans

To get this to work, when you start the project you need to be sure that you've informed IntelliJ that you're working with Spring.  Same as last time, but this time you need at least 1 library (but as I'm unsure which one, chose the first 4).

If you didn't select a particular library, there's help here.  https://www.jetbrains.com/help/idea/2016.3/enabling-spring-support.html#addFacet

For this exercise, construct the code described in this worked example. http://www.journaldev.com/2410/spring-dependency-injection.  You'll need to set up 4 package directories, which we renamed under com.greenfox in the solution:-
- configuration
- consumer
- services
- test

### into com.greenfox.configuration

```java
package com.greenfox.configuration;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

import com.greenfox.services.TwitterService;
import com.greenfox.services.MessageService;
import com.greenfox.services.EmailService;

/*
@Configuration annotation is used to let Spring know that it’s a Configuration class.
@ComponentScan annotation is used with @Configuration annotation to specify the packages to look for Component classes.
@Bean annotation is used to let Spring framework know that this method should be used to get the bean implementation to inject in Component classes.
 */

@Configuration
@ComponentScan(value={"com.greenfox.consumer"})
public class DIConfiguration {

    @Bean
    public MessageService getMessageService(){
        return new TwitterService();
    }
}
```
### into com.greenfox.consumer
```java
package com.greenfox.consumer;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.stereotype.Component;

import com.greenfox.services.MessageService;


@Component
public class MyApplication {

    //field-based dependency injection
    //@Autowired
    private MessageService service;

	//constructor-based dependency injection
	@Autowired
	public MyApplication(MessageService svc){
		this.service=svc;
	}

    @Autowired
    public void setService(MessageService svc){
        this.service=svc;
    }

    public boolean processMessage(String msg, String rec){
        //some magic like validation, logging etc
        return this.service.sendMessage(msg, rec);
    }
}

/*
@Component annotation is added to the class, so that when Spring framework will scan for the components, this class will be treated as component. @Component annotation can be applied only to the class and it’s retention policy is Runtime. If you are not not familiar with Annotations retention policy, I would suggest you to read java annotations tutorial.
@Autowired annotation is used to let Spring know that autowiring is required. This can be applied to field, constructor and methods. This annotation allows us to implement constructor-based, field-based or method-based dependency injection in our components.
For our example, I am using method-based dependency injection. You can uncomment the constructor method to switch to constructor based dependency injection.
 */
```
### into com.greenfox.services
```java
package com.greenfox.services;
public interface MessageService {
    boolean sendMessage(String msg, String rec);
}
```
```java
package com.greenfox.services;

public class EmailService implements MessageService {

    public boolean sendMessage(String msg, String rec) {
        System.out.println("Email Sent to "+rec+ " with Message="+msg);
        return true;
    }
}
```

```java
package com.greenfox.services;

public class TwitterService implements MessageService {

    public boolean sendMessage(String msg, String rec) {
        System.out.println("Twitter message Sent to "+rec+ " with Message="+msg);
        return true;
    }
}
```
### into com.greenfox.test
```java
package com.greenfox.test;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import com.greenfox.configuration.DIConfiguration;
import com.greenfox.consumer.MyApplication;

/*
AnnotationConfigApplicationContext is the implementation of AbstractApplicationContext abstract class and it’s used for
autowiring the services to components when annotations are used. AnnotationConfigApplicationContext constructor takes
Class as argument that will be used to get the bean implementation to inject in component classes.

getBean(Class) method returns the Component object and uses the configuration for autowiring the objects.
Context objects are resource intensive, so we should close them when we are done with it
*/

public class ClientApplication {

    public static void main(String[] args) {
        AnnotationConfigApplicationContext context = new AnnotationConfigApplicationContext(DIConfiguration.class);
        MyApplication app = context.getBean(MyApplication.class);

        app.processMessage("Hi Pankaj", "pankaj@abc.com");

        //close the context
        context.close();
    }

}
```

```java
package com.greenfox.test;

import com.greenfox.consumer.MyApplication;
import com.greenfox.services.MessageService;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan(value="com.greenfox.consumer")
public class MyApplicationTest {

    private AnnotationConfigApplicationContext context = null;

    @Bean
    public MessageService getMessageService() {
        return new MessageService(){

            public boolean sendMessage(String msg, String rec) {
                System.out.println("Mock Service");
                return true;
            }
        };
    }

    @Before
    public void setUp() throws Exception {
        context = new AnnotationConfigApplicationContext(MyApplicationTest.class);
    }

    @After
    public void tearDown() throws Exception {
        context.close();
    }

    @Test
    public void test() {
        MyApplication app = context.getBean(MyApplication.class);
        Assert.assertTrue(app.processMessage("Hi Pankaj", "pankaj@abc.com"));
    }
}
```
Specifically, copy and paste in his solution (provided above) and then review the code with his explanation so you understand it.

Test it, get familiar and then answer the following questions:-
- what does ComponentScan do?
- how does Autowired know what to pick up?
- how would one switch the service to do Twitter instead?
- what happens when you rename a Bean?
- Drawing out the way that one class calls the other with the annotation used to call upon the other.

# Links
- [Spring Bean Factory Overview](../README.md)
- [Previous Workshop - Intro to Beans](./Workshop01.md)
- [Next Workshop - Autowired &amp; Constructors](./Workshop03.md)
