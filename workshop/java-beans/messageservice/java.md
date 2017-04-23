# Switching MessageServices

Let's create another Spring project, again we do not need to initialise just simply create a new one with IntelliJ.
Let’s say we want to send email message or twitter message to the users. The goal is to create an application where the way of sending message can be easily swicthed by moving @Bean annotation in the configuration.

You will need to have an interface, `MessageService`, with single method declaration for sending message.
Two classes that implements this interface, `EmailService` and `TwitterService`. You will need one `MessageConfiguration`, and one `MessageProceeder`class.

You will need to set up 3 package directories under com.greenfox.messageservice:
- configuration
- interface
- services

`MessageService` should be injected into `MessageProceeder` class using field-based, constructor-based and setter-based dependency injections, however only one of them should be wired.</br>
Hint: Don't forget to scan for components(beans) in the relevant package.

The main class should look like this, with one of the two possible results below:
```java
package com.greenfox.name

import com.greenfox.messageservice.config.MessageConfig;
import com.greenfox.messageservice.service.MessageProceeder;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class ClientApp {
    public static void main(String[] args) {
        AnnotationConfigApplicationContext context = new AnnotationConfigApplicationContext(MessageConfig.class);
        MessageProceeder app = context.getBean(MessageProceeder.class);

        app.processMessage("Hi Barba! How are you?", "office@greenfox.com");

        //close the context
        context.close();
    }
}
```
Result:</br>
SOME RED INFO</br>
`Email Sent to office@greenfox.com with Message=Hi Barba! How are you?`</br>
SOME RED INFO AGAIN
