# Object Oriented Programming

## Materials & Resources

### Doable homework
- Create 5 trees
  - Store the data of them in variables in your program
  - every tree should have
    - type
    - leave color
    - age
    - sex
  - you can use just variables, or lists and/or maps
- Create a function called `water` which can water one tree (specified in the parameter)
  - changes the color to `"green"`
  - increases the age by one

### Materials

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
| [Codecademy course - Introduction to Classes
](https://www.codecademy.com/courses/python-intermediate-en-WL8e4/0/1) | |

## Material Review

## Workshop

### Data Structure

#### Post-it
- Create a `PostIt` class that has
  - a `backgroundColor`
  - a `text` on it
  - a `textColor`

#### BlogPost
- Create a `BlogPost` class that has
  - an `authorName`
  - a `title`
  - a `text`
  - a `publicationDate`

### Use Class

#### Dominoes
- You have the list of Dominoes
- Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
  - eg: [2, 4], [4, 3], [3, 5] ...

##### MentorNote
- Use this as the list:
  - [5, 2], [4, 6], [1, 5], [6, 7], [2, 4], [7, 1]

#### Dice
- You have a `Dice` class which has 6 dice
- You can roll all of them with `roll()`
- Check the current rolled numbers with `getCurrent()`
- You can reroll with `reroll()`
- Your task is to get where all dice is a 6

##### MentorNote
- reroll and getCurrent should have
  - a no-param version doing it with all dice
  - and a int-param version where doing it with only one (index)
- part of the task is to check that (no need to specify it in the description)

#### Fleet of Things
- You have the `Thing`
- You have the `Fleet`
- Create this output with those:
```
1. [ ] Get milk
2. [ ] Remove the obstacles
3. [x] Stand up
4. [x] Eat lunch
```

##### MentorNote
- Thing should have
  - a contructor with the name
  - a complete method
  - a toString method for this format: `[?] name`
- Fleet should have
  - add new Thing method
  - toString method for this format `?. thing.toString`

### Encapsulation and Constructor

#### Animal
- Create `Animal` class
  - hunger
  - thirst
  - default constructor sets these
  - eat(), drink() -> increase
  - play() -> decrease both

#### Sharpie

#### Counter

### Complex Architectures

#### Teacher Student

#### Petrol Station

### Classes as Fields

#### Blog

#### Farm

#### Sharpie Set
