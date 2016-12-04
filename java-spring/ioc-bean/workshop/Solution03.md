This is	 also covered [here (by jetbrains)](https://www.jetbrains.com/help/idea/2016.2/enabling-spring-support.html).  


```java
package com.greenfoxacademy.java.lesson.beans;
import org.springframework.context.annotation.*;

@Configuration
public class TextEditorConfig {

   @Bean 
   public TextEditor textEditor(){
      return new TextEditor( spellChecker() );
   }

   @Bean 
   public SpellChecker spellChecker(){
      return new SpellChecker( );
   }
}
```
