# HelloBeanWorld application

Create a s Spring project.

Use the HelloWorld class as a base and create a bean from it.
```java
public class HelloWorld {
   private String message;

   public void setMessage(String message){
      this.message  = message;
   }
   
   public String getMessage(){
      System.out.println("Your message: " + message);
      return message;
   }
}
```

You should say hello to the world, the output should be the following:
```java
SOME SPRING INFO
Your message: Hello World!
SOME SPRING INFO
```
To do this, you will need to create a `HelloWorldConfig` and a `HelloWorldApplication` class (the second one will be created automatically, if you set everything well).
You should wire HelloWorld as bean, then `set` the message to "Hello World!", and then `get` the new message.
