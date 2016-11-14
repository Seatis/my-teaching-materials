First create an `Animal` class which has the following attributes:
+ lifeExpectancy:int  //years
+ isCarnivore:boolean

It has the usual constructors:-
+ The *default* constructor (without any parameter) which sets lifeExpectancy to 10, and false for isCarnivore
+ An alternative that takes `lifeExpectancy` and `isCarnivore` parameters.

Both constructors tell us "created an animal".

There are no need for getters nor setters.

An there are some other Methods:-
- speak() - sout("speaks")
- sleep() - sout("sleeps")
- toString() - returns "isCarnivore=%b, lifeExpectancy=%d"


Next extend `Animal` with the class `Dog`.
- How do you tell the environment that Dog inherits from Animal?
- How do you create the item, especially as for dogs the default would be lifeExpectancy 15 and true for isCarnivore
- dogs override 
  - speak() - sout("barks")
- have an additional method
  - beg() - sout("begs")
- dogs usually have tails (`hasTail`)

Next extend `Animal` with the class `Bird`.
- Birds only usually live 2 years and are not carnivores (in general)
- speak() - sout("chirp")
- fly() - sout("flies")

```java
/**
 * Created by eric.hofer on 11/14/2016.
 */
public class AppTestAnimal {
    public static void main(String[] args) {
        Animal animal = new Animal();
        Bird bird = new Bird();
        Dog dog = new Dog();

        System.out.println("Testing Animal");
        // how does it speak, sleep, and tell me about its lifeExpectancy and if its a carnivore

        System.out.println("\nTesting Bird");
        // how does it speak, sleep, what else it can do and tell me about its lifeExpectancy and if its a carnivore

        System.out.println("\nTesting Dog");
        // how does it speak, sleep, what else it can do and tell me about its lifeExpectancy and if its a carnivore, and what about the tail?


        System.out.println("\nTesting Dog2");
        Animal dog2 = new Dog();
        // how does it speak, sleep, what else it can do and tell me about its lifeExpectancy and if its a carnivore, and what about the tail?

        }

        System.out.println("\nTesting Dog 'd'");
        // how does it speak, sleep, what else it can do and tell me about its lifeExpectancy and if its a carnivore, and what about the tail?

        }
    }
}

```

The output expected is:-

```
created an animal.
new bird
new dog
Testing Animal
animal speaks
animal sleeps
isCarnivore=false, lifeExpectancy=10

Testing Bird
bird chirps
animal sleeps
bird flies
And a bird:isCarnivore=false, lifeExpectancy=2

Testing Dog
dog barks
animal sleeps
dog begs
And a dog:isCarnivore=true, lifeExpectancy=15, and hasTail=true

Testing Dog2
new dog
dog barks
animal sleeps
Casting dog2 into Y to see if it begs...
dog begs
And a dog2 cast as (Dog) Y:isCarnivore=true, lifeExpectancy=22, and hasTail=false

Testing Dog 'd'
new dog
dog barks
animal sleeps
isCarnivore=true, lifeExpectancy=15
```
