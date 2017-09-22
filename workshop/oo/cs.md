# Object Oriented Programming

## Materials & Resources

### Materials
- Before starting the materials
- Do this little exercise: [Doable homework](homework.md)

| Material | Time |
|:---------|-----:|
|[Classes and Objects](https://www.youtube.com/watch?v=FCjoioi6xvM)|4:33|
|[Object Oriented Programming Basics](https://www.youtube.com/watch?v=0K2EsvAz5Pg)|8:08|
|[Fields](https://www.youtube.com/watch?v=jcHBfa36gz0)|3:44|
|[Propertis](https://www.youtube.com/watch?v=7jD_T04XfpE)|10:51|
|[Constructor](https://www.youtube.com/watch?v=MyWBU6IKl5U)|6:19|
|[Static vs Non Static](https://www.youtube.com/watch?v=86ymhq54V5k)|13:33|
|[This keyword](https://www.youtube.com/watch?v=m8hRUP1WL28)|2:28|
|[Struct](https://www.youtube.com/watch?v=1UV1Pd20akM)|7:59|
|[Structs](https://www.youtube.com/watch?v=4yoAojPY5aI)|6:24|
|[Struct vs Classes (only from 4:19)](https://youtu.be/4eDFpuDGosA?t=259)| 10:39|



### Optional
| Material | Time |
|:---------|-----:|
|[Overloading](https://www.youtube.com/watch?v=F9ygaxxbbz4)|11:17|
|[Static(reading)](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/static-classes-and-static-class-members)|3:00|


## Material Review
- struct
- class
  - private
  - public 
- static
- fields
- properties
- constructor
- this
- new


## Workshop

```csharp
public struct Home
{
    string name;
    int roomsNumber;
    int price;
}
```

```csharp
class FamilyMember
{
    string name;
    int age;
    string surname;
}
```

#### What are the main diferences between struct and class?
- Within a struct declaration, fields cannot be initialized unless they are declared as const or static.

- A struct cannot declare a default constructor (a constructor without parameters) or a finalizer.

- Structs are value types and classes are reference types.

- Unlike classes, structs can be instantiated without using a `new` operator.

- Structs can declare constructors that have parameters.

- A struct cannot inherit from another struct or class, and it cannot be the base of a class. All structs inherit directly from `System.ValueType`, which inherits from `System.Object`.

- A struct can implement interfaces.

- A struct can be used as a nullable type and can be assigned a null value.

### Data Structures

- [Post-it](post-it/cs.md)
- [BlogPost](blog-post/cs.md)

### Use Class

```csharp
using System;

namespace GreenFox
{
    public class FishTank
    {
        public static int FishCount = 0;

        public string Status;

        public FishTank()
        {
            Status = "There is no fish in the tank!";
        }

        public static void Add()
        {
            FishCount++;
            Console.WriteLine("There is {0} fish in the tank.", FishCount);
        }

        public void HowMuchIsTheFish()
        {
            Console.WriteLine("Hyper! Hyper!");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var tank = new FishTank();
            Console.WriteLine(tank.Status);

            FishTank.Add();

            tank.HowMuchIsTheFish();

            Console.ReadLine();
        }
    }
}

```

- [Dominoes](dominoes/cs)
- [Dice](dice/cs)
- [Fleet of Things](fleet-of-things/cs)

### Encapsulation and Constructor
```csharp
using System;

namespace GreenFox
{
    class Program
    {
        public class Human
        {
            private string Name;
            private int Age;
            private int IQ;

            public Human(string name, int age, int iq)
            {
                Name = name;
                Age = age;
                IQ = iq;
            }
            
            public bool IsSmart()
            {
                return (IQ > 100);
            }
            
            public bool IsNameLess()
            {
                return (this.Name.Equals("unkown") || this.Name.Equals(""));
            }
            
            public void BeSmarter()
            {
                this.IQ += 20;
            }
        }
        
        static void Main(string[] args)
        {
            var human = new Human("John", 37, 95);

            Console.WriteLine("Is our human nameless? " + human.IsNameLess());
            Console.WriteLine("Our human is {0} and he is {1} old", human.name, human.age);
            Console.WriteLine("Is our human smart: " + human.IsSmart());

            human.BeSmarter();
            Console.WriteLine("Is our human smart now? " + human.IsSmart());

            Console.ReadLine();
        }
    }
}
```

- [Animal](animal)
- [Sharpie](sharpie/cs.md)
- [Counter](counter/cs)

### Complex Architectures


- [Teachers and Students](teachers-and-students)
- [Petrol Station](petrol-station/cs.md)

### Classes as Fields

```csharp
public class Page 
{
    public string Content { get; set; }
}

public class Book 
{
    private List<Page> Pages;

    public Book() 
    {
        this.Content = new List<Page>();
    }

    public void Add(Page page) 
    {
        Pages.Add(page);
    }

    public int CountBlankPages() 
    {
        int counter = 0;
        for (var page in Pages) 
        {
            if (page.Content.isEmpty()) 
            {
                counter++;
            }
        }

        return counter;
    }
}
```

- [Sharpie Set](sharpie-set/cs.md)
- [Farm](farm)
- [Blog](blog)


### Alltogether

- [Pirates](pirates/cs.md)
- Redo the 5 trees homework (with classes)
