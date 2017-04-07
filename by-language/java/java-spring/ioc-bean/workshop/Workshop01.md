#Workshop01 - Bean Factory, getting started

Create the standard *Hello World*, ala Spring.  This will appear in your sout and not in a browser window.

To get this to work, when you start the project you need to be sure that you've informed IntelliJ that you're working with Spring.

This is explained [here (by jetbrains)](https://www.jetbrains.com/help/idea/2016.2/enabling-spring-support.html).  And we include a snapshot:-

<img src="./Workshop01-1.jpg">

Here, you need to inform the engine that you want to work with Spring; select only the top level.  You'll not need any of the extra libraries.

Create a package directory: `com.greenfoxacademy.java.lesson.beans`.

You'll need the following classes
```java
package com.greenfoxacademy.java.lesson.beans;
public class HelloWorld {
    private String message;

    public void setMessage(String message){
        this.message  = message;
    }

    public void getMessage(){
        System.out.println("Your Message (from HelloWorld.java): " + message);
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
    
    //Note "1" covered later
    @Bean
    public WithFries withFries() {
      return new withFries();
    }
}
```

```java
package com.greenfoxacademy.java.lesson.beans;

public class WithFries {
    boolean flSalted = true;

    public WithFries(boolean flSalted) {
        this.flSalted = flSalted;
    }

    public WithFries() {
    }

    @Override
    public String toString() {
        return (flSalted? "Salted" : "Unassaulted");
    }

    public void toggleFlSalted() {
        this.flSalted = ! this.flSalted;
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
		
        WithFries withFries = new WithFries();
        System.out.println(withFries.toString());
        withFries.toggleFlSalted();
        System.out.printf("Just toggled withFries and now they are '%s'.", withFries.toString());

    }
}
```



Output, as pretty much expected:
```
RED STUFF
Your Message (from HelloWorld.java) : Hello World!
Salted Fries
Just toggled withFries and now they are 'Unassaulted.'
```

The basics of this exercise are that you understand and can use such as a basis:-
- where is the Spring configuration being held?
- what is ctx?  What is it holding?
- how did Spring know where to find the the HelloWorld?
- if we didn't use ctx.getBean, how would we have created `helloWorld` (the variable)?
- as we don't have a "new HelloWorld()" instantiated, where is the helloWorld object *living*?

## Now You Do It
Change withFries into a *Bean*!

Your output could be:-
```
Your Message (from HelloWorld.java) : Hello World!
Salted
Just toggled withFries and now they are 'Unassaulted'.
```

## Expand to passing parameters
What if we want to do the following?
`WithFries withFries = new WithFries (false); `

You should get the following output
```
Your Message (from HelloWorld.java) : Hello World!
Unassaulted
Just toggled withFries and now they are 'Salted'.
```

Could you do that with annotation and the Bean?

Google to find an answer, we found 2 but this was most palatable [Passing Constructor Parameter to getBean when using Annotation (stackoverflow)](http://stackoverflow.com/questions/16997034/how-to-pass-parameters-dynamically-to-spring-beans).

To make it work we needed to amend the Configuration where you see `note "1" LATER`:
```java
@Bean
@Scope("prototype")  //or @Scope(configurableBeanFactor.SCOPE_PROTYPE)
  public WithFries withFries(boolean salted) {  //IntelliJ will complain, but still compile
      return new withFries(salted); 
    }
```
And in the App, call
```java
   WithFries withFries = ctx.getBean(WithFries.class, false);
```

Note, however, now the empty contstructor for Fries won't work.


# Links
- [Spring Bean Factory Overview](../README.md)
- [Next Workshop - Swapping Services ](./Workshop02.md)
