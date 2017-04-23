# Playing around with colors

There is one interface given:
```java
package com.greenfox.colors

public interface MyColor {

    public void printColor();
}
```
Any kind of color class (for i.e. RedColor) can implement this interface overriding `printColor();` sout-ing for i.e. `"It is red in color..."`.

Your task is to create a java based configuration file.

The Main class should look like this:

```java
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import com.greenfox.colors.MyColor;
import com.greenfox.colors.MyAppConfig;

public class ColorsMain {

    public static void main(String a[]){
        ApplicationContext context
                        = new AnnotationConfigApplicationContext(MyAppConfig.class);
        MyColor color = (MyColor) context.getBean("myColorBean");
        color.printColor();
    }
}
```
