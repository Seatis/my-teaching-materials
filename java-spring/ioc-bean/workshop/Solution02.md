#Solution02 - Bean Lifecycle

```java
package com.greenfoxacademy.java.lesson.beans;
public class Foo {

  public void init() {
    println("Foo being initialised");
  }

  public void cleanup() {
    println ("Foo being destroyed");
  }
}

```

Instantiate such using the class AppConfig.

```java
@Configuration
public class AppConfig {
   @Bean(initMethod = "init", destroyMethod = "cleanup" )
   public Foo foo() {
      return new Foo();
   }
}
```

The output should be 
```
Foo being initialised
Foo being destroyed
```
