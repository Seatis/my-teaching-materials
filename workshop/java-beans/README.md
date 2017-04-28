# Beans

JavaBeans are classes that encapsulate many objects into a single object (the bean). It makes it easy to reuse software components.</br>
Developers can use software components written by others without having to understand their inner workings.</br>
To understand why software components are useful, think of a worker assembling a car. Instead of building a radio from scratch, he can simply obtains a radio and put it into the car.

## Materials & Resources

### Training

| Material | Time |
|:-------- |-----:|
|[Understanding Dependency Injection](https://www.youtube.com/watch?v=GB8k2-Egfv0)|14:51|
|[What is java bean?](https://www.javatpoint.com/java-bean)|reading|
|[Beans in Spring](https://www.youtube.com/watch?v=P0m1dW0LJeE&t)|1:58|
|[@Autowired](https://www.youtube.com/watch?v=HFt_q0wYYLU&t)|5:43|
|[Bean Factory](https://www.youtube.com/watch?v=xlWwMSu5I70)|6:52|
|[Java Based Configuration](https://www.tutorialspoint.com/spring/spring_java_based_configuration.htm)|reading|


### Optional
| Material | Time |
|:-------- |-----:|
|[Autowired example](https://www.youtube.com/watch?v=xTGkWSZkyNg)|18:20|
|[Java Bean Annotations](http://docs.spring.io/spring-javaconfig/docs/1.0.0.M4/reference/html/ch02s02.html)|reading|
|[Serialization](https://www.youtube.com/watch?v=6MisF1sxBTo)|9:24|
|[Dependency Injection](https://www.youtube.com/watch?v=IKD2-MAkXyQ)|4:46|

## Material Review
- DI
- bean
- spring container
- object lifecycle
- bean factory
- annotations
  - @Bean
  - @Autowired
  - @Component
  - @ComponentScan
  - @Configuration


#### Optional
- serialization

## Workshops

Example of injecting bean dependencies:

```java
package com.greenfox.texteditor.config;
import ...;

@Configuration
public class TextEditorConfig {
    @Bean
    public TextEditor textEditor() {
        return new TextEditor(spellChecker());
    }

    @Bean
    public SpellChecker spellChecker() {
        return new SpellChecker();
    }
}
```
```java
package com.greenfox.texteditor.services;
import ...

public class TextEditor {
    @Autowired
    SpellChecker spellChecker;

    public TextEditor(SpellChecker spellChecker) {
        System.out.println("Inside TextEditor constructor.");
        this.spellChecker = spellChecker;
    }

    public void spellCheck() {
        spellChecker.checkSpelling();
    }
}
```
```java
package com.greenfox.texteditor.services;

public class SpellChecker {
    public SpellChecker(){
        System.out.println("Inside SpellChecker constructor." );
    }

    public void checkSpelling(){
        System.out.println("Inside checkSpelling." );
    }
}
```
```java
package com.greenfox.texteditor;

import ...

@SpringBootApplication
public class SpellcheckerApplication implements CommandLineRunner {
	@Autowired
	TextEditor te;

	public static void main(String[] args) {
		SpringApplication.run(SpellcheckerApplication.class, args);
	}

	@Override
	public void run(String... args) throws Exception {
		te.spellCheck();
	}
}
```

- [01) Hello World bean project](helloworld/java.md)
- [02) Coloring beans around](coloring/java.md)
- [03) MessageService](messageservice/java.md)

### Optional

- [04) Test Beans](test/java.md)
