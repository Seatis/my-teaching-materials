# Switching MessageServices

Let's create another Spring project, again we do not need to initialise just simply create a new one with IntelliJ.
Let’s say we want to send email message or twitter message to the users. The goal is to create an application where the way of sending message can be easily swicthed by moving @Bean annotation in the configuration.

You will need to have an interface, `MessageService`, with single method declaration for sending message.
Two classes that implements this interface, `EmailService` and `TwitterService`. You will need one `MessageConfiguration`, and one `MessageProceeder`class.

You'll need to set up 3 package directories under com.greenfox:
- configuration
- interface
- services

`MessageService` should be injected into `MessageProceeder` class using field-based, constructor-based and setter-based dependency injections, however only 1 of them should be wired.

The main class should look like this, with the below result:
```java
package com.greenfox.name

import com.greenfox.name.config.MessageConfig;
import com.greenfox.name.service.MessageProceeder;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class ClientApp {
    public static void main(String[] args) {
        AnnotationConfigApplicationContext context = new AnnotationConfigApplicationContext(MessageConfig.class);
        MessageProceeder app = context.getBean(MessageProceeder.class);

        app.processMessage("Hi Barba", "office@greenfox.com");

        //close the context
        context.close();
    }
}
```
Result:
`SOME RED INFO
Email Sent to pankaj@abc.com with Message=Hi Pankaj
SOME RED INFO AGAIN
`
