#Workshop03 - Import Annotation

Create a bean that depends upon another bean and then create both beans.

To get this to work you'll need to create an A and B class.


Class A
``` 
public class A {

   public String toString () {
     return "I'm an A";
   }
}
```

And likewise for B.

Then you'll need Config classes.

ConfigA Class

```java
@Configuration
public class ConfigA {
   @Bean
   public A a() {
      return new A(); 
   }
}
```

ConfigB Class

```java
@Configuration
@Import(ConfigA.class)
public class ConfigB {
   @Bean
   public B a() {
      return new A(); 
   }
}
```

For the Workshop then create an App.

```java
public static void main(String[] args) {
   ApplicationContext ctx = 
   new AnnotationConfigApplicationContext(ConfigB.class);
   // now both beans A and B will be available...
   A a = ctx.getBean(A.class);
   B b = ctx.getBean(B.class);
   System.out.printf(%s\n%s,a.toString,b.toString);
}
```

Expect something like:
```
I'm an A
I'm a B
```
