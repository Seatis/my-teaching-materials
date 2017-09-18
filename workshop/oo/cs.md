# Object Oriented Programming

## Materials & Resources

### Materials
- Before starting the materials
- Do this little exercise: [Doable homework](homework.md)

| Material | Time |
|:---------|-----:|
|[Struct](https://www.youtube.com/watch?v=1UV1Pd20akM)|7.59|
|[Classes and Objects](https://www.youtube.com/watch?v=FCjoioi6xvM)|4:33|
|[Fields](https://www.youtube.com/watch?v=jcHBfa36gz0)|3:44|
|[Constructor](https://www.youtube.com/watch?v=MyWBU6IKl5U)|6:19|
|[This keyword](https://www.youtube.com/watch?v=m8hRUP1WL28)|2:28|
|[Struct vs Classes (only from 4:19)](https://youtu.be/4eDFpuDGosA?t=259)| 10:39|
|[Static(reading)](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/static-classes-and-static-class-members)|3:00|



### Optional
| Material | Time |
|:---------|-----:|
|[Overloading](https://www.youtube.com/watch?v=F9ygaxxbbz4)|11:17|


## Material Review
- struct 
- class
  - private
  - public
  - static
- fields
- constructor
- this
- new


## Workshop

### Data Structure
```java
public class Bicycle {
   int cadence;
   int gear;
   int speed;
}
```
```java
  public class FamilyMember {
    String name;
    int age;
    String surname;
}
```

- [Post-it](post-it/java.md)
- [BlogPost](blog-post/java.md)

### Use Class

```java
public class Usable {
  String status;
  public Usable() {
    status = "I'm not used at all";
  }

  public void use() {
    status = "Now, I was used at least once."
  }
}

public class Main {
  public static void main(String[] args) {
    Usable firstUsable = new Usable();
    firstUsable.use();
  }
}
```

- [Dominoes](dominoes/java)
- [Dice](dice/java)
- [Fleet of Things](fleet-of-things/java)

### Encapsulation and Constructor
```java
public class Human {
  String name;
  int age;
  int iq;

  public Human() {
    this("unkown", 0, 0);
  }

  public Human(String name, int age, int iq) {
    this.name = name;
    this.age = age;
    this.iq = iq;
  }

  public boolean isSmart(){
    return (iq > 100);
  }

  public boolean isNameless(){
    return (this.name.equals("unkown") || this.name.equals(""));
  }

  public void beSmarter(){
    this.iq += 20;
  }

  public static void main(String[] args) {
    Human human = new Human();
    Human human2 = new Human("Laci",18,110);

    human.name="Hector";
    human.age=1;

    if(human.isSmart()){
      System.out.println(human.name + " is smart, with iq: " + human.iq);
    }
  }
}
```

- [Animal](animal)
- [Sharpie](sharpie/java.md)
- [Counter](counter/java)

### Complex Architectures

- [Teachers and Students](teachers-and-students)
- [Petrol Station](petrol-station/java.md)

### Classes as Fields

```java
public class Page {
  String content;

  public Page() {
    this.content = "";
  }

  public Page(String content) {
    this.content = content;
  }

  public String getContent() {
    return content;
  }
}

public class Book {
  List<Page> pages;

  public Book() {
    this.pages = new ArrayList<>();
  }

  public void add(Page page) {
    pages.add(page);
  }

  public int countBlankPages() {
    int counter = 0;
    for (Page page : this.pages) {
      if (page.getContent().isEmpty()) {
        counter++;
      }
    }
    return counter;
  }
}
```

- [Sharpie Set](sharpie-set/java.md)
- [Farm](farm)
- [Blog](blog)

### Alltogether

- [Pirates](pirates/java.md)
- Redo the 5 trees homework (with classes)
