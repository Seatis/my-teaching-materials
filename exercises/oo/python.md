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
*If you've got time and/or want to dig deeper, consider the following:*

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

### Data Structure

- [Post-it](post-it)
- [BlogPost](blog-post)

### Use Class

- [Dominoes](dominoes/python)
- [Dice](dice/pyhton)
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

- [Animal](#)
- [Sharpie](#)
- [Counter](#)

### Complex Architectures

- [Teachers and Students](#)
- [Petrol Station](#)

### Classes as Fields

- [Sharpie Set](#)
- [Farm](#)
- [Blog](#)

### Alltogether

- [Pirates](pirates/python.md)
- Redo the 5 trees homework (with classes)
