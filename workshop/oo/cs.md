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
- properties
- events
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
    // Fields, properties, methods and events go here...
}
```

```csharp
class FamilyMember
{
    string name;
    int age;
    string surname;
    //Fields, properties, methods and events go here...
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
    public class Usable
    {
        public string status;
        public static int count;
        public Usable()
        {
            status = "I am not used at all";
        }
        public static void Use()
        {
            count++;
            Console.WriteLine("I am used: {0} times", count);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Usable usable = new Usable();
            Console.WriteLine(usable.status);

            Usable.Use();

            Usable.Use();

            Console.ReadLine();
        }
    }
}

```


### Encapsulation and Constructor
```csharp
using System;

namespace GreenFox
{
    class Program
    {
        public class Human
        {
            public string name;
            public int age;
            public int iq;

            public Human(string nm, int a, int iQ)
            {
                name = nm;
                age = a;
                iq = iQ;
            }
            public bool IsSmart()
            {
                return (iq > 100);
            }
            public bool IsNameLess()
            {
                return (this.name.Equals("unkown") || this.name.Equals(""));
            }
            public void BeSmarter()
            {
                this.iq += 20;
            }
        }
        static void Main(string[] args)
        {
            Human human = new Human("John", 37, 95);

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


### Complex Architectures



### Classes as Fields

```csharp
```


### Alltogether


- Redo the 5 trees homework (with classes)
