#Workshop04 - Various positions of @Autowire

This workshop looks at how you can use `@Autowire` to get better control over how the Beans are connected up.  This workshop follows one of the Materials given earlier, namely "[Autowire Annotation (tutorialspoint)](https://www.tutorialspoint.com/spring/spring_autowired_annotation.htm)".  

We'll work with the code from the [previous Workshop](.\Workshop03.md), the one that has a TextEditor and SpellChecker.  Note that we are _not_ using *xml*.  So we have `@ComponentScan` to ensure we pick up our Beans.

Note you can also get some hints from the code in [Workshop02](.\Workshop02.md).

## Create a Constructor-based dependency injection
- Where do you do this?
- What happens when you do it?

## Switch to field/property based injection
- What do you change?  
- What happens when you do such?

## Switch to setter based injection
- What do you change?

## Set up required parameters
*While the tutorialpoint (mentioned above) does talk about this, you can also check "[Spring Autowiring section 8.4 (javacodegeeks)](https://examples.javacodegeeks.com/enterprise-java/spring/beans-spring/spring-autowire-example/)" for additional help.*
- Add to SpellChecker the following fields:
  - String textWord 
  - String codeLanguage = "EN";
- Add `SpellChecker.toString() {System.out.printf("SpellChecking '%s' in '%s'\n",this.textWord,this.codeLanguage);}`
- Add to main, a call to the instance of the TextEditor to get the spelling of the word "Woof"
- How do you pass in a Value at creation?

## Try the `@Autowired(required=false)` on `codeLanguage`
- What happens now

## Extra
- Replace @Autowired with @Required
