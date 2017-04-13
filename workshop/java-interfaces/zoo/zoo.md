# Worshop Couple animals

We are going to reprezent a Zoo.
The animals are more cute than humans, so we don't care about them right now.

So we need an abstract `Animal` class
- it has `name`, `age` field
- it has `greet()` and `wantChild()` methods

Have we got all fields and methods we should?
What about gender? Any other?
Write down at least 3 fields and/or methods that should be included in `Animal`!

Let's think about the species of animals `Mammal`s, `Reptile`s, `Birds`s etc, we call them as groups now.
In the group we need to define group specified fields and methods. For example every `Bird` `wantChild()` from an egg, doesn't matter if it is a penguin or parrot or ostrich.
Write down at least 2 of field and/or method what is common in each group above!

Most of the `Reptile`s `wantChild()` from an egg too, so if we exclude some of them (i.e. frogs) from our zoo, it is common with `Bird`s.
Write down 2 options at least that can solve this thing. 

Create the project and the classes above!

The Workshop should be invoked now by an Zoo Class:-
```java
import main.java.animals.*;

public class Zoo {

  public static void main(String[] args) {

    Reptile reptile = new Reptile("Crocodile");
    Mammal mammal = new Mammal("Koala");
    Bird bird = new Bird("Parrot");

    System.out.println("Who want a baby?");
    System.out.println(reptile.getName() + ", " + reptile.wantChild());
    System.out.println(mammal.getName() + ", " + mammal.wantChild());
    System.out.println(bird.getName() + ", " + bird.wantChild());
  }
}

```
We expect the following output:-

> Who want a baby?

> Crocodile, want a child from an egg!

> Koala, want a child from my uterus!

> Bird, want a child from an egg!

