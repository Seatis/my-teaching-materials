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
|[Refresher on Inheritance and Polymorphism](https://www.youtube.com/watch?v=gWpg3yMiL0M)|3:03|
|[When to use an abstract class in Java (Degee.39)](https://www.youtube.com/watch?v=hZ1EU-F-0nU)|4:25|
|[Java Interface Tutorial](https://www.youtube.com/watch?v=5Aef6vnAxR8)|1:08|
|[Interfaces and Abstracts (Bana.15)](https://www.youtube.com/watch?v=1PPDoAKbaNA)|8:29|
|[Abstract and Concrete Classes](https://www.youtube.com/watch?v=TyPNvt6Zg8c)|8:26|


### Optional
| Material | Time |
|:-------- |-----:|
|[Abstract Classes and Interfaces](https://www.youtube.com/watch?v=AU07jJc_qMQ)|26:33|
|[Abstract Classes and methods](https://www.youtube.com/watch?v=pt1S11yX-7k)|14:37|
|[Java Interfaces Explained (Degee.40)](https://www.youtube.com/watch?v=fX1xNMBTMfg)|7:11|


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

## Workshops
- [01) Instruments to Stringed Instruments](workshop/Workshop01.md) - 2 levels of abstraction

#Links
- [Parent - Java OO Module](../README.md)
- [Prev - Inheritance &amp; Packages](../2-packages-and-inheritance/README.md)
- [Next - Project: Todo App](../4-project-todo-app/README.md)


