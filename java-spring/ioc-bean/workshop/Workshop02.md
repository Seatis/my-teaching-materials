#Workshop02 - RESTful Hello World

Let's take it up a notch.  Having done a simple *Hello World*, ala Spring, lets do it as a RESTful, web-based version.  This will appear in your browser.

To get this to work, when you start the project you need to be sure that you've informed IntelliJ that you're working with Spring.  Same as last time, but this time you need at least 1 library.

https://www.jetbrains.com/help/idea/2016.3/enabling-spring-support.html#addFacet

This is explained [here (by jetbrains)](https://www.jetbrains.com/help/idea/2016.2/enabling-spring-support.html).  And we include a snapshot:-

<img src="./Workshop01-1.jpg">

Here, you need to inform the engine that you want to work with Spring.  You'll only need the need all the libraries.  So you can select the one(s) potentially needed.

Create a package directory: `com.greenfoxacademy.java.lesson.beans`.

You'll need 2 classes
```java
package com.greenfoxacademy.java.lesson.beans;
public class HelloWorld {
    private String message;

    public void setMessage(String message){
        this.message  = message;
    }

    public void getMessage(){
        System.out.println("Your Message : " + message);
    }
}
```

```java
package com.greenfoxacademy.java.lesson.beans;
import org.springframework.context.annotation.*;

@Configuration
public class HelloWorldConfig {

    @Bean
    public HelloWorld helloWorld(){
        return new HelloWorld();
    }
}
```

And at the `src` level:-
```java
import com.greenfoxacademy.java.lesson.beans.*;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.*;


public class App {

    public static void main(String[] args) {
        ApplicationContext ctx =
                new AnnotationConfigApplicationContext(HelloWorldConfig.class);

        HelloWorld helloWorld = ctx.getBean(HelloWorld.class);

        helloWorld.setMessage("Hello World!");
        helloWorld.getMessage();
    }
}
```
