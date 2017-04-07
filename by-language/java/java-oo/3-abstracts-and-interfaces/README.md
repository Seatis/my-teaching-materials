# Abstracts & Interfaces
*There are times when we need common features in classes but they don't work on their own.*
In some situations either:-
- we want to inherit from multiple classes
- the base classes have expectations in order to be used, or in order to support a much larger framework.  

Java gets round this through Abstracts and Interfaces.

## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
|[Refresher on Inheritance and Polymorphism (Guru.08)](https://www.youtube.com/watch?v=gWpg3yMiL0M)|3:03|
|[When to use an abstract class in Java (Degee.39)](https://www.youtube.com/watch?v=hZ1EU-F-0nU)|4:25|
|[Java Interface Tutorial (Guru)](https://www.youtube.com/watch?v=5Aef6vnAxR8)|1:08|
|[Interfaces and Abstracts (Bana.15)](https://www.youtube.com/watch?v=1PPDoAKbaNA)|8:29|
|[Abstract and Concrete Classes (NewBoston.58)](https://www.youtube.com/watch?v=TyPNvt6Zg8c)|8:26|


### Optional
| Material | Time |
|:-------- |-----:|
|[Abstract Classes and Interfaces (Wertz)](https://www.youtube.com/watch?v=AU07jJc_qMQ)|26:33|
|[Abstract Classes and methods (CodeMonkey.17)](https://www.youtube.com/watch?v=pt1S11yX-7k)|14:37|
|[Java Interfaces Explained (Degee.40)](https://www.youtube.com/watch?v=fX1xNMBTMfg)|7:11|
|[SimpleDateFormat (ProgrammingKnowledge)](https://www.youtube.com/watch?v=JtAplwiTOXc)|10.46|
|[Comparator (mkyong)](https://www.mkyong.com/java/java-object-sorting-example-comparable-and-comparator/)||

## Material Review
- inheriting from more than 1 class
  - need to insert functionality from a 2nd class
  - want to be sure that functionality is implemented in order to use a larger framework
  - we are unsure how to implement a method in the child class, but we know it must exist
for the parent class to work
- values set at the base level in an interface are final (e.g. the Pi example)
- if there's a method in an abstract, then the class must be defined as abstract
  - however, that does not mean that all items must be abstract, in that class, fields and methods can still be defined
- abstract classes cannot be instantiated
- the declaration of the child class elements cannot be less restrictive than the forefather abstract
  - guarantees us compile time safety as the bare minimum must be met
- for interfaces, the entire definition is an abstract (e.g. not defined)
- `implements`
- `Object`
- Comparison functionality for objects
  - `implements Comparable<T>` and `compareTo()`
  - public static Comparator<Model> ModelSizeComparator = new Comparator<Model>()

## Workshops
- [01) Instruments to Stringed Instruments](workshop/Workshop01.md) - 2 levels of abstraction
- [02) Reservation based upon an Interface](workshop/Workshop02.md)
- [03) Credit Card based upon an Interface](workshop/Workshop03.md) - a bit more complex
- [04) Credit Card &amp; Reservation](workshop/Workshop04.md) - implements 2 interfaces
- [05) Comparable](workshop/Workshop05.md) - something we'd use to compare values
- [06) Add Comparator support to the Credit Card &amp; Reservation classes](workshop/Workshop06.md)


## Individual Workshop Review
As always neatness counts in coding.

Please be sure you're well acquainted with the guidelines on coding: [GreenFox Academy's Java Styleguide](../../styleguide/java.md)

#Links
- [Parent - Java OO Module](../README.md)
- [Prev - Inheritance &amp; Packages](../2-packages-and-inheritance/README.md)
- [Next - Project: Todo App](../4-project-todo-app/README.md)
