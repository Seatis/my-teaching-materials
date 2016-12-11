#Workshop03 - Practice with the constructs

Earlier we explained the basic underlying concept of IoC/DI with an example involving a TextEditor and a SpellChecker.

```java
public class TextEditor {
   private SpellChecker spellChecker;
   
   public TextEditor() {
      spellChecker = new SpellChecker();
   }
}
```

Namely, that Inversion of Control says we instead should pass in the instance of the SpellChecker:-

```java
public class TextEditor {
   private SpellChecker spellChecker;
   
   public TextEditor(SpellChecker spellChecker) {
      this.spellChecker spellChecker();
   }
}
```

In this Workshop, we want to implement the above with Beans and annotation.  

Some hints:-
- You saw @Configuration at the start of the DIConfiguration class in Workshop02; consider it as the model for AppConfig
- In my solution I had the following packages:-
  - configuration
  - services (for SpellChecker and TextEditor)
- Revisit this [Useful reference on using Annotation(spring.io)](http://docs.spring.io/spring-javaconfig/docs/1.0.0.M4/reference/html/ch02s02.html)

Some starter stuff for you, but you need to figure the rest out.
```java
package com.greenfox.services;
\\OTHER STUFF HERE FOR YOU TO FIGURE OUT
public class SpellChecker {

    public SpellChecker(){
        System.out.println("Inside SpellChecker constructor." );
    }

    public void checkSpelling(String tx){
        System.out.printf("Inside checkSpelling, %s is a word.\n", tx );
    }
}
```

```java
package com.greenfox.services;
\\OTHER STUFF

public class TextEditor {
    private SpellChecker spellChecker;

    public void setSpellChecker( SpellChecker spellChecker ){
        this.spellChecker = spellChecker;
    }
    public SpellChecker getSpellChecker( ) {
        return spellChecker;
    }
    public void spellCheck(String tx) {
        spellChecker.checkSpelling(tx);
    }
}

```

```java
package com.greenfox.configuration;

\\VARIOUS THINGS
public class AppConfig {

 \\NOT COMPLETE HERE EITHER
    public TextEditor textEditor() {
        return new TextEditor();
    }

    public SpellChecker spellChecker() {
        return new SpellChecker();
    }
}

```


```java
import com.greenfox.services.TextEditor;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import com.greenfox.configuration.AppConfig;

public class App {

    public static void main(String[] args) {
        \\REMOVED 2 lines HERE
        sc.spellCheck("Woof");
    }
}
```

You should get something like this when you run the code.
```
RED STUFF INFO: Refreshing org.springframework.context.annotation.AnnotationConfigApplicationContext@21b8d17c: startup date ...
MORE RED STUFF INFO: Overriding bean definition for bean 'textEditor' with a different definition: replacing [Generic bean: class [com.greenfox.services.TextEditor]; ...
MORE RED STUFF INFO: Overriding bean definition for bean 'spellChecker' with a different definition: replacing [Generic bean: class [com.greenfox.services.SpellChecker]; ...
Inside SpellChecker constructor.
Inside checkSpelling, Woof is a word.
RED STUFF
```

# Links
[Previous Workshop - ](../Workshop02.md)
[Next Workshop - ](../Workshop04.md)

