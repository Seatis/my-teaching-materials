# Switching MessageServices

Let's create another Spring project.
Let’s say we want to send email message or twitter message to the users. The goal is to create an application where the way of sending message can be easily swicthed by moving @Bean annotation in the configuration.

You will need to have an interface, `MessageService`, with single method declaration for sending message.
Two classes that implements this interface, `EmailService` and `TwitterService`. You will need one `MessageConfiguration`, and one `MessageProceeder`class.

You will need to set up 3 package directories under com.greenfox.messageservice:
- configuration
- interface
- services

`MessageService` should be injected into `MessageProceeder` class using field-based, constructor-based and setter-based dependency injections, however only one of them should be wired.</br>
Hint: Don't forget to scan for components(beans) in the relevant package.

One of the two possible results below should look like this:

Output:</br>
SOME SPRING INFO</br>
`Email Sent to office@greenfox.com with Message=Hi Barba! How are you?`</br>
SOME SPRING INFO
