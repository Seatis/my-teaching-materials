# Object Oriented Programming

## Materials & Resources

### Materials
- Before starting the materials
- Do this little exercise: [Doable homework](homework.md)

| Material | Time |
|:---------|-----:|

### Optional

| Material | Time |
|:---------|-----:|

## Material Review

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

- [Post-it](post-it)
- [BlogPost](blog-post)

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

- [Animal](animal)
- [Sharpie](sharpie)
- [Counter](counter/java)

### Complex Architectures

- [Teachers and Students](teachers-and-students)
- [Petrol Station](petrol-station)

### Classes as Fields

```java
public class Page {
  private String content;

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
  private List<Page> pages;

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

- [Sharpie Set](sharpie-set)
- [Farm](farm)
- [Blog](blog)

### Alltogether

- [Pirates](pirates/java.md)
- Redo the 5 trees homework (with classes)
