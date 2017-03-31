This solution consists of:-
+ Animal Class
+ Dog extends Animal
+ Bird extends Animal
+ AppTestAnimal() 

```java
public class Animal {
    public boolean isCarnivore = false;
    public int lifeExpectancy = 10;

    public Animal() {
        System.out.println("created an animal.");
    }

    public Animal(int lifeExpectancy, boolean isCarnivore) {
        this.lifeExpectancy = lifeExpectancy;
        this.isCarnivore = isCarnivore;
    }

    public void speak() {
        System.out.println("animal speaks");
    }

    public void sleep() {
        System.out.println("animal sleeps");
    }

    public String toString() {
        return String.format("isCarnivore=%b, lifeExpectancy=%d", isCarnivore, lifeExpectancy);
    }

}
```

```java
public class Dog extends Animal {
    boolean hasTail = false;

    public Dog() {
        super(15,true);
        System.out.println("new dog");
    }

    @Override
    public void speak() {
        System.out.println("dog barks");
    }
    public void beg() {
        System.out.println("dog begs");
    }
}

```

```java
public class Bird extends Animal {
    boolean hasWings = true;

    public Bird() {
        super(2,false);
        System.out.println("new bird");
    }

    @Override
    public void speak() {
        System.out.println("bird chirps");
    }
    public void fly() {
        System.out.println("bird flies");
    }
}

```

```java
public class AppTestAnimal {
    public static void main(String[] args) {
        Animal animal = new Animal();
        Bird bird = new Bird();
        Dog dog = new Dog();

        System.out.println("Testing Animal");
        animal.speak();
        animal.sleep();
        System.out.println(animal.toString());

        System.out.println("\nTesting Bird");
        bird.speak();
        bird.sleep();
        bird.fly();
        System.out.println("And a bird:" + bird.toString());

        System.out.println("\nTesting Dog");
        dog.speak();
        dog.sleep();
        dog.beg();
        System.out.println("And a dog:" + dog.toString() + ", and hasTail=" + dog.hasTail);

        System.out.println("\nTesting Dog2");
        Animal dog2 = new Dog();
        dog2.speak();
        dog2.sleep();
        if (dog2 instanceof Dog){
            Dog Y = (Dog) dog2;
            Y.hasTail=false;
            Y.lifeExpectancy=22;
            System.out.println("Casting dog2 into Y to see if it begs...");
            Y.beg();
            System.out.println("And a dog2 cast as (Dog) Y:" + Y.toString() + ", and hasTail=" + Y.hasTail);
        }

        System.out.println("\nTesting Dog 'd'");
        Dog d = new Dog();
        if (d instanceof Animal) {
            Animal a = (Animal) d;
            a.speak();
            a.sleep();
            System.out.println(a.toString());

        }
    }

}
```