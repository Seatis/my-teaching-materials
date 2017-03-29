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

- [Post-it](#)
- [BlogPost](#)

### Use Class

- [Dominoes](#)
- [Dice](#)
- [Fleet of Things](fleet-of-things/java)

### Encapsulation and Constructor

- [Animal](#)
- [Sharpie](#)
- [Counter](#)

### Complex Architectures

- [Teachers and Students](#)
- [Petrol Station](#)

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

  public void addEmptyPage() {
    pages.add(new Page());
  }

  public void remove(int index) {
    pages.remove(index);
  }

  public void update(int index, Page page) {
    pages.set(index, page);
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

  public void removeBlankPages() {
    List<Page> pages = new ArrayList<>();
    for (Page page : this.pages) {
      if (!page.getContent().isEmpty()) {
        pages.add(page);
      }
    }
    this.pages = pages;
  }
}
```

- [Sharpie Set](#)
- [Farm](#)
- [Blog](#)

### Alltogether

- [Pirates](pirates/java.md)
- Redo the 5 trees homework (with classes)
