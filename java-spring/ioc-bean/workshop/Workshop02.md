#Workshop02 - Bean Lifecycle

As illustrated in the video, using annotation to add an initialization and destruction call back for an instance of the class Foo.

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

Instantiate such using the class AppConfig which you'll have to identify as providing configuration information

```java

 ...
   @Bean(initMethod = "?", destroyMethod = "?" )
   public Foo foo() // need to do something 

```

The output should be 
```
Foo being initialised
Foo being destroyed
```
