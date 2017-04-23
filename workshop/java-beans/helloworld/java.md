# HelloBeanWorld application

Create a simple Spring project (do not need to use spring initialiser)

Use the HelloWorld class as a base and create a bean from it.
```java
public class HelloWorld {
   private String message;

   public void setMessage(String message){
      this.message  = message;
   }
   public void getMessage(){
      System.out.println("Your message: " + message);
   }
}
```

You should say hello to the world, the output should be the following:
```java
SOME RED INFO
Your message: Hello World!
```
To do this, you will need to create a ```HelloWorldConfig``` and a ```MainApp``` class.
You should instantiate HelloWorld as bean, then `set` the message to "Hello World!", and then `get` the new message.
