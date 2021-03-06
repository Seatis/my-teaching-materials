# Object Oriented Programming

## Materials & Resources

### Materials
- Before starting the materials
- Do this little exercise: [Doable homework](homework.md)

| Material | Time |
|:---------|-----:|
| [Python Programming Tutorial - 29 - Classes and Objects](https://www.youtube.com/watch?v=POQIIKb1BZA) | 9:54 |
| [Python Programming Tutorial - 30 - init](https://www.youtube.com/watch?v=G8kS24CtfoI) | 7:52 |
| [Python Programming Tutorial - 31 - Class vs Instance Variables](https://www.youtube.com/watch?v=qSDiHI1kP98) | 3:54 |

### Optional
*If you"ve got time and/or want to dig deeper, consider the following:*

| Material | Time |
|:---------|-----:|
| [Hands-on Python Tutorial: Object Orientation (only section 2.1.1)](http://anh.cs.luc.edu/python/hands-on/3.1/handsonHtml/strings3.html#object-orientation) | |
| [Codecademy course - Introduction to Classes](https://www.codecademy.com/courses/python-intermediate-en-WL8e4/0/1) | |

## Material Review

 - object
 - `class`
 - `self`
 - method
 - instantiation
 - constructor
 - `__init__(self)`
 - class variable
 - instance variable

## Workshop

### Classes as Data Structure

```python
class Car(object):
    brand = ""
    model = ""
    color = ""

car1 = Car()
car2 = Car()

car1.brand = "Nissan"
car1.model = "Sunny"
car1.color = "green"
car2.brand = "Mercedes"
car2.model = "190"
car2.color = "red"

print("Brand of car1: " + car1.brand + ", Model: " + car1.model + ", Color: " + car1.color)
print("Brand of car2: " + car2.brand + ", Model: " + car2.model + ", Color: " + car2.color)
```
- [Post-it](post-it/python.md)
- [BlogPost](blog-post/python.md)

### Use Class

```python
class Texts(object):

    def __init__(self):
        self.status = "empty"
        self.texts = []

    def add_new_text(self, new_text):
        self.texts.append(new_text)
        self.status = "length of list: " + str(len(self.texts))
        return self.texts

    def check_state(self):
        print(self.status)

    def check_text(self):
        print(self.texts)


my_texts = Texts()      # instantiate my own texts
my_texts.check_state()  # check its state

my_texts.add_new_text("alma")   # add some new text
my_texts.check_state()          # then check the class"s state
my_texts.check_text()           # and its content

my_texts.add_new_text("korte")  # and another one
my_texts.check_state()
my_texts.check_text()
```

- [Dominoes](dominoes/python)
- [Dice](dice/python)
- [Fleet of Things](fleet-of-things/python)

### Encapsulation and Constructor

```python
class BankAccount(object):
    def __init__(self, name, balance=0.0):
        self.name = name
        self.balance = balance

    def withdraw(self, amount):
        self.balance -= amount
        return self.balance

    def deposit(self, amount):
        self.balance += amount
        return self.balance
```

- [Animal](animal)
- [Sharpie](sharpie/python.md)
- [Counter](counter/python)

### Complex Architectures

- [Teachers and Students](teachers-and-students)
- [Petrol Station](petrol-station/python.md)

### Classes as Fields

```python
class Page(object):
    def __init__(self, content=""):
        self.content = content

class Book(object):
    def __init__(self):
        self.pages = []

    def add(self, page):
        self.pages.append(page)

    def count_blank_pages(self):
        counter = 0
        for page in self.pages:
            if page.content == "":
                counter += 1
        return counter
```

- [Sharpie Set](sharpie-set/python.md)
- [Farm](farm)
- [Blog](blog)

### Alltogether

- [Pirates](pirates/python.md)
- Redo the 5 trees homework (with classes)
