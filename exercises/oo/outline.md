# Object Oriented Programming

## Materials

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

### Videos


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
  - eat(), drink() -> decrease
  - play() -> increase both

#### Sharpie
- Create `Sharpie` class
  - color, width, inkAmount
  - constructor(color, width)
    - inkAmount set to 100
  - use()
    - decreases inkAmount

#### Counter
- Create `Counter` class
  - private value
  - add(int)
  - add() -> +1
  - get()
  - reset() -> 0

### Complex Architectures

#### Teacher Student
- Create `Student` and `Teacher` classes
- `Student`
  - learn()
  - question(teacher) -> calls the teachers answer
- `Teacher`
  - teach(student) -> calls the students learn
  - answer()

#### Petrol Station
- Create `Station` and `Car` classes
- `Station`
  - gasAmount
  - refill(car) -> decreases the gasAmount by the capacity of the car and increases the cars amount
- `Car`
  - gasAmount
  - capacity
  - constructor
    - inits gasAmount -> 0
    - capacity -> 100

### Classes as Fields

#### Sharpie Set
- Reuse your `Sharpie` class
- Create `SharpieSet` class
  - list of Sharpies
  - countUsable() -> sharpie is usable if it has ink in it
  - removeTrash() -> removes all unusable sharpies

#### Farm
- Reuse your `Animal` class
- Create a `Farm` class
  - list of Animals
  - slots
  - breed() -> creates a new animal if there's place for it
  - slaughter() -> removes the least hungry animal

#### Blog
- Reuse your `BlogPost` class
- Create a `Blog` class
  - list of BlogPosts
  - add(BlogPost)
  - delete(int)
  - update(int, BlogPost)

### Alltogether
#### Pirates

#### Redo the 5 trees
