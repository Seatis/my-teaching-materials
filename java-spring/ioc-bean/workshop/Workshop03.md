#Workshop03 - Create a Bean Dependency

Create a bean that calls another bean, demonstrating how beans interact.

To get this to work, when you start the project you need to be sure that you've informed IntelliJ that you're working with Spring.  Create the following classes:-

```java
package com.greenfoxacademy.java.lesson.beans;
public class TextEditor {
   private SpellChecker spellChecker;

   public TextEditor(SpellChecker spellChecker){
      System.out.println("Inside TextEditor constructor." );
      this.spellChecker = spellChecker;
   }
   public void spellCheck(){
      spellChecker.checkSpelling();
   }
}
```

```java
package com.greenfoxacademy.java.lesson.beans;

public class SpellChecker {
   public SpellChecker(){
      System.out.println("Inside SpellChecker constructor." );
   }

   public void checkSpelling(){
      System.out.println("Inside checkSpelling." );
   }
   
}
```
You'll have to create a TextEditorConfig class that the Workshop03App.main can call.  This will define the 2 beans.

The main routine:

```java
package com.greenfoxacademy.java.lesson.beans;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.*;

public class Workshop03App {
   public static void main(String[] args) {
      ApplicationContext ctx = 
      new AnnotationConfigApplicationContext(TextEditorConfig.class);

      TextEditor te = ctx.getBean(TextEditor.class);

      te.spellCheck();
   }
}
```

Your results should be:-

```
Inside SpellChecker constructor.
Inside TextEditor constructor.
Inside checkSpelling.
```

