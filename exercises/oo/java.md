# Object Oriented Programming

## Materials & Resources

### Materials
- Before starting the materials
- Do this little exercise: [Doable homework](homework.md)

| Material | Time |
|:---------|-----:|
| [Class and Object](https://www.youtube.com/watch?v=eKC04ztp09o) | 1:37 |
| [Fields](https://www.youtube.com/watch?v=UDVVPUqjsRg) | 1:37 |
| [Visibility](https://www.youtube.com/watch?v=aRQRV2PMHtk) | 7:53 |
| [Getter and Setter](https://www.youtube.com/watch?v=D3Arfy77Vok) | 15:22 |
| [Encapsulation](https://www.youtube.com/watch?v=szYzBC89CPE) | 1:08 |
| [Class and Object again](https://www.youtube.com/watch?v=0NPR8GFHNmE) | 13:43 |
| [This](https://www.youtube.com/watch?v=hUZ4jQmgwi4) | 4:11 |
| [New](https://www.youtube.com/watch?v=VyPFa1Slh7A#t=50) | 12:11 |
| [Static](https://www.youtube.com/watch?v=n4axao9LWWE) | 7:44 |


### Optional

| Material | Time |
|:---------|-----:|
| [One more Class and Object](https://www.youtube.com/watch?v=4XRy-TdfU0I) | 14:52 |
 

## Material Review
- Class
- Object
- Fields
- Visibility
  - Default
  - Private
  - Protected
  - Public
- Getter 'n Setter
- Encapsulation
- This
- New
- Static vs. !Static


## Workshop

### Data Structure

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
```
public class Human {
    private String name;
    private int age;
    private int iq, height, weight;

    public Human() {
        name = "unknow";
        age = iq = height = weight =0;
    }

    public Human(String name, int age) {
        this.name = name;
        this.age = age;
        this.iq = this.height = this.weight = 0;
    }

    public Human(String name, int age, int iq, int height, int weight) {
        this.name = name;
        this.age = age;
        this.iq = iq;
        this.height = height;
        this.weight = weight;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        if(isBiggerThanZero(age)){
            this.age = age;
        }
    }

    public int getIq() {
        return iq;
    }

    public void setIq(int iq) {
        if(isBiggerThanZero(iq)){
            this.iq = iq;
        }
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        if(isBiggerThanZero(height)){
            this.height = height;
        }
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        if(isBiggerThanZero(weight)){
            this.weight = weight;
        }
    }

    private boolean isBiggerThanZero(int number){
        return (number > 0);
    }

    @Override
    public String toString() {
        return "Human{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", iq=" + iq +
                ", height=" + height +
                ", weight=" + weight +
                '}';
    }

    public static void main(String[] args) {
        //empty || default Constructor
        Human human = new Human();
        System.out.println(human.toString());
        //"Human{ name=unknow, age=0, iq=0, height=0, weight=0}"

        // 2 args Constructor
        Human human2 = new Human("Teemo",4);
        System.out.println(human2.toString());
        //"Human{ name=Teemo, age=4, iq=0, height=0, weight=0}"

        // all args Constructor
        Human human3 = new Human("Nami",18,100,140,40);
        System.out.println(human3.toString());
        //"Human{ name=Nami, age=18, iq=100, height=140, weight=40}"

        //modify human's name
        human.setName("Hector");
        System.out.println("human's name is: "+human.getName());
        //human's anem is: Hector
        System.out.println(human.toString());
        //"Human{ name=unknow, age=0, iq=0, height=0, weight=0}"

        //modify human's age
        human.setAge(-1);
        System.out.println(human.getAge());
        //0
        human.setAge(1);
        System.out.println(human.getAge());
        //1
    }
}

```

- [Animal](animal)
- [Sharpie](sharpie)
- [Counter](counter/java)

### Complex Architectures

- [Teachers and Students](#)
- [Petrol Station](#)

### Classes as Fields

- [Sharpie Set](#)
- [Farm](#)
- [Blog](#)

### Alltogether

- [Pirates](pirates/java.md)
- Redo the 5 trees homework (with classes)
