# Object Oriented Programming

## Materials & Resources

### Materials
- Before starting the materials
- Do this little exercise: [Doable homework](homework.md)

| Material | Time |
|:---------|-----:|
| [Class and Object](https://www.youtube.com/watch?v=eKC04ztp09o) | 1:37 |
| [Fields](https://www.youtube.com/watch?v=UDVVPUqjsRg) | 1:37 |
| [Encapsulation](https://www.youtube.com/watch?v=tt_astMjep0) | till 2:40 |
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
        this("unkown", 0, 0, 0, 0);
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

    public boolean isSmart(){
        return (iq > 100);
    }

    public boolean isNameless(){
        return (this.name.equals("unkown") || this.name.equals(""));
    }

    public void beSmarter(){
        this.iq += 20;
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

        Human human = new Human();
        System.out.println(human.toString());

        Human human2 = new Human("Teemo",4);
        System.out.println(human2.toString());

        Human human3 = new Human("Nami",18,110,140,40);
        System.out.println(human3.toString());

        human.name="Hector";
        System.out.println("human's name is: "+human.name);
        System.out.println(human.toString());

        human.age=1;
        System.out.println(human.age);

        human2.age=human2.height=human2.weight=1;
        human2.iq=-1;
        System.out.println(human2.toString());

        ArrayList<Human> humans = new ArrayList<>();
        humans.add(human);
        humans.add(human2);
        humans.add(human3);

        fameOrShame(humans);
        for (int i = 0; i < 11; ++i){
            human.beSmarter();
        }
        fameOrShame(humans);
    }

    public static void fameOrShame(ArrayList<Human> humans){
        for (Human human : humans
                ) {
            String output = "";
            if(human.isSmart()){
                output = human.name + "is smart";
                if(human.isNameless()){
                    System.out.println(output + "but nameless");
                }else {
                    System.out.println(output);
                }
            }else{
                System.out.println(human.name + " is not smart");
            }
        }
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
