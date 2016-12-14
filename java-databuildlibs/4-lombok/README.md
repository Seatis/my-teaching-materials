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

*Excerpted from stackOverflow [Method Chaining/Fluent Interface (stackoverflow)](http://stackoverflow.com/questions/2872222/how-to-do-method-chaining-in-java-o-m1-m2-m3-m4) - and specifically the response from **subhashis** who kindly created a worked example (but was not voted the best answer to the question, hence our wanting to highlight such here instead).*

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
|[Lombok Project Summary](http://jnb.ociweb.com/jnb/jnbJan2010.html)|reading|
|[Method Chaining](https://www.youtube.com/watch?v=CZfEHRrLA80) - dreadful, jargoned without illustrations, but explains what is method chaining; here until we find something better.|2:46|

## Material Review
- `@Data` - super annotation for `@Getter`, `@Setter`, `@ToString`, `@EqualsAndHashCode`
- `@Getter`, `@Setter` - avoiding having to regenerate code; used on a particular field
- `@ToString`
- `@NonNull`
- `@EqualsAndHashCode`
- `@NoArgsConstructor`
- `@AllArgsConstructor` 
  - a static constructor - `@AllArgsConstructor(staticName="of"`) leads to xOfClass`.of()`
- `@Builder` - build an object using a *fluent* API (Java 8, chaining)
- `@Log`
  - utility logger
- pom.iml
- *pojo*
- The Terminal - in IntelliJ
- Fluent Interfaces
- Method Chaining

## Workshop
- Create a pojo (that is *plain old java object*, meaning not using special features) with constructors, then
  - replace with @getter for all items; prove it works
  - experiment with just a single field @getter on one field
- Change to use @Build
  - remove the constructor
- Use the @Log
- Write something that chains stuff together
