#Workshop05 - Configuration Class, Injecting Dependencies &amp; Init and Destroy methods with Beans

## Configuration
Based upon "[Authoring `@Configuration` classes`](http://docs.spring.io/spring-javaconfig/docs/1.0.0.M4/reference/html/ch02s02.html)", create the following code in a new Project that implements such with Annotation only.


```java
@Configuration
//stuff here
public class AppConfig {
    @Bean
    public Foo foo() {
        return new Foo(bar());
    }

    @Bean
    public Bar bar() {
        return new Bar();
    }
	
    public static void main(String[] args) {
	//stuff here
	}

}
        
```
This is supported by these 2 classes...

```java
public class Foo {

    Bar bar;
    public Foo(Bar bar) {
        this.bar = bar;

    }

    public String toString () { return "In Foo:" + bar.toString();}
}

public class Bar {

    public String toString() {return "new Bar";}
}
```

Obviously, as usual we've left *stuff* out.

The output should be:-
```
INFO in red
In Foo:new Bar
More red
```

## Add in an init and cleanup method
This was in the Materials for the day, "[Authoring `@Configuration` classes`](http://docs.spring.io/spring-javaconfig/docs/1.0.0.M4/reference/html/ch02s02.html)").  

To save you time, it's Foo that needs some preparatory and destructive methods; here they are ...
```
   public void init () {
        System.out.println("The Foo Man is awakening!");
    }

    public void cleanup () {
        System.out.println("The Foo Man is no more, and his mess is gone too!");
    }

```	

Note, however, the example suggests the configuration is `initMethodName` however, that was not right and `initMethod` did work.

The output should be 
```
RED STUFF
MORE RED STUFF
The Foo Man is awakening
In Foo:new Bar
RED STUFF
The Foo Man is no more, and his mess is gone too!

```

There is another way to do this, even closer to the Bean, by using the `@PostConstruct` and `@PreDestroy` annotations (see "[Spring @PostConstruct and @PreDestroy (Mkyong)](https://www.mkyong.com/spring/spring-postconstruct-and-predestroy-example/)").
