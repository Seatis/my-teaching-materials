# Project Lombok &amp; Method Chaining
Project Lombok is an extension to Java that delivers a set of annotations that can reduce the amount of *boilerplate* code (English definition follow) one needs to write.  Lombok, for example, provides one word commands that add *getters*, *setters*, *constructors*.  It also provides functionality by which one can pipe output to a log file (say the console).  Given its usefulness, we introduce it here.

*Boilerplate* - means a repetitive, standard document; one that is usually served up for repetitive situations.  It might be used in describing a response, or something that is then extended.  For example, as a bureaucratic response or when generating a contract (that is to say a *Standard Lease Agreement* or *Boilerplate Lease*).

## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
|[Introduction to Project Lombok (Cortez)](https://youtu.be/DXnUpcOPOYA)|5:42|
|[Lombok, invoked from (aka created using) IntelliJ (Vega)](https://www.youtube.com/watch?v=E-_Qs_NeHMQ) - note that we'll revisit the  Spring Initialzr (SpringBoot) and JPA in the Spring Module that comes next.|10:15|
|[Project Lombok](https://projectlombok.org) - yet more of same, but quick*ish*; extra credit if you can master his pronunciation of "Java"|3:49|

#### Method Chaining
We cover this as there are several examples where this technique is used.

*Excerpted from stackOverflow [Method Chaining/Fluent Interface (stackoverflow)](http://stackoverflow.com/questions/2872222/how-to-do-method-chaining-in-java-o-m1-m2-m3-m4) - and specifically the response from _subhashis_ who kindly created a worked example (but was not voted the best answer to the question, hence our wanting to highlight such here instead).*

**Method chaining**, also known as named **parameter idiom**, is a common syntax for invoking multiple method calls in object-oriented programming languages. Each method returns an object, allowing the calls to be chained together in a single statement. Chaining is syntactic sugar which eliminates the need for intermediate variables. A method chain is also known as a train wreck due to the increase in the number of methods that come one after another in the same line that occurs as more methods are chained together even though line breaks are often added between methods.

A similar syntax is **method cascading**, where after the method call the expression evaluates to the current object, not the return value of the method. Cascading can be implemented using method chaining by having the method return the current object itself (this). Cascading is a key technique in fluent interfaces, and since chaining is widely implemented in object-oriented languages while cascading isn't, this form of "cascading-by-chaining by returning this" is often referred to simply as "chaining". Both chaining and cascading come from the Smalltalk language.

Without chaining ...
```java
  class Person {
    private String name;
    private int age;

    // Per normal Java style, the setters return void.

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void introduce() {
        System.out.println("Hello, my name is " + name + " and I am " + age + " years old.");
    }

    // Usage:
    public static void main(String[] args) {
        Person person = new Person();
        // Not using chaining; longer than the chained version above.
        // Output: Hello, my name is Peter and I am 21 years old.
        person.setName("Peter");
        person.setAge(21);
        person.introduce();
    }
}
```
And with ...
```java
class PersonMethodChaining {
private String name;
private int age;

// In addition to having the side-effect of setting the attributes in question,
// the setters return "this" (the current Person object) to allow for further chained method calls.

public PersonMethodChaining setName(String name) {
    this.name = name;
    return this;
}

public PersonMethodChaining setAge(int age) {
    this.age = age;
    return this;
}

public void introduce() {
    System.out.println("Hello, my name is " + name + " and I am " + age + " years old.");
}

// Usage:
public static void main(String[] args) {
    PersonMethodChaining person = new PersonMethodChaining();
    // Output: Hello, my name is Peter and I am 21 years old.
    person.setName("Peter").setAge(21).introduce();
}
```

Note that this is not the same as [Constructor Chaining (Degee)](https://www.youtube.com/watch?v=m6t8z3CWskA), which we've already covered.

### Optional
| Material | Time |
|:-------- |-----:|
|[Project Lombok Summary](http://jnb.ociweb.com/jnb/jnbJan2010.html)|reading|
|[Method Chaining](https://www.youtube.com/watch?v=CZfEHRrLA80) - dreadful, machine-voice, jargoned and lacking illustrations.  However it does explains what is *method chaining* and it's here until we find something better.|2:46|

## Material Review
- `@Data` - super annotation for `@Getter`, `@Setter`, `@ToString`, `@EqualsAndHashCode`
- `@Getter`, `@Setter` - avoiding having to regenerate code; used on a particular field
- `@ToString`
- `@NonNull`
- `@EqualsAndHashCode`
- `@NoArgsConstructor`
- `@AllArgsConstructor`
- instructions
  - `staticName` - e.g. `@AllArgsConstructor(staticName="of"`) leads to xOfClass`.of()`
  - `callToSuper`
  - `AccessLevel.NONE`
- `@Builder` - build an object using a *fluent* API (Java 8, chaining)
- `@Log`
  - utility logger
- pom.iml
- *pojo* - stands for "plain old java object" - meaning not using special features
- The Terminal - in IntelliJ
- Fluent Interfaces
- Method Chaining

## Workshop

### Create project with lombok
- Create a new gradle project as first task on Tue. (group id: com.greenfoxacademy; artifact id: samplelombok)
- Install the Lombok plugin to your IntelliJ environment
  - You do this through System/Preferences &gt;&gt; Plugins &gt;&gt; Browse repository &gt;&gt; Lombok Plugin &gt;&gt; Install; **Remember, you must restart IntelliJ for the Plugin to take effect**
  - Ensure that annotations are enabled which can be found System/Preferences &gt;%gt; Build, Execution &gt;&gt; Compiler &gt;&gt; Annotation Processors
- Replace the gradle settings and src folder with source supplied in this lesson (**Note that the zip file contains all the same source files.**)
  - Ensure that you *refresh* Gradle.
- Run the tests and MainApp. Both have to run without failures.

**Note that if you recompile your gradle project, you might lose the reference connections in the Test bed.  If so, you need to alt-Enter to reset these in TestHorse to recover `@Log`.  This is due to having `compileonly "org.projectlombok:lombok:1.16.12"` in the gradle.build; if this is `compile "org.projectlombok:lombok:1.16.12"` then it will be resilient, but that means the jar will be compiled and held locally instead of resolved when build.**.

In next excercises you will modify the classes in main/animals and main/foods packages.  

You will **not** change either the App or Test sets.

Keep in mind that it's not always just an annotation (e.g. `@Setter`) at the start of the Class and you're done.  Sometimes, it's the placement of the annotation, or instructions given, to the annotation that are necessary.

### Replace getters
- Replace all getter methods with @Getter annotation.
  - Observe that there are different levels at which Getters (and Setters) can be set

Keep in mind that when you add methods, you need to sometimes ask IntelliJ to refresh. Remember Alt-Enter.

### Replace setters
- Replace all setter methods with @Setter annotation.
- You can use AccessLevel.NONE if you do want to avoid a setter.

### Replace Equals and HashCode
- Replace all equals and hashCode methods with @EqualsAndHashCode annotation.

Hint, when something is an extension of a base class, Lombok doesn't necessarily realize such and needs a hint to so as to check on the super's equivalent method.

### Replace toString
- Replace all toString methods with @ToString annotation.

### Replace logging
- Replace logging with @Log annotation.

### Replace constructors and implement Builder pattern
- Replace static builder classes with @Builder annotation on constructors or top ot the classes.
