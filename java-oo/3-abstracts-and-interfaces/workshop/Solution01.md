# `src` contains 

## App.java
```java
import main.java.music.*;

public class App {


    public static void main(String[] args) {

        System.out.println("Test 1, create ElectricGuitar, Bass and Violin with default strings.");
        ElectricGuitar guitar = new ElectricGuitar();
        ElectricBassGuitar bassGuitar = new ElectricBassGuitar();
        Violin violin = new Violin();

        System.out.println("Test 1 Play");
        guitar.play();
        bassGuitar.play();
        violin.play();

        System.out.println("Test 2, create ElectricGuitar, Bass with 7 and 5 strings.");
        guitar = new ElectricGuitar(7);
        bassGuitar = new ElectricBassGuitar(5);

        System.out.println("Test 2 Play");
        guitar.play();
        bassGuitar.play();
    }
}
```

## main.java.music

### ElectricBassGuitar.java
```java
package main.java.music;

public class ElectricBassGuitar extends StringedInstrument {

    public ElectricBassGuitar() {
        super();
        this.name = "Bass Guitar";
        this.numberOfStrings = 4;
    }

    public ElectricBassGuitar(int numberOfStrings) {
        super();
        this.name = "Bass Guitar";
        this.numberOfStrings = numberOfStrings;
    }

    @Override
    public void play() {
        System.out.printf(super.formatForPlay,this.name, this.numberOfStrings, "Duum-duum-duum");
    }
}
```

### ElectricGuitar.java
```java
package main.java.music;

public class ElectricGuitar extends StringedInstrument {

    final String nameDef = "Electric Guitar";
    final String soundDescription = "twangs";

    public ElectricGuitar() {
        super();
        this.name = nameDef;
        this.numberOfStrings = 6;
    }

    public ElectricGuitar(int numberOfStrings) {
        super();
        this.name = nameDef;
        this.numberOfStrings = numberOfStrings;
    }

    @Override
    public void play() {
        System.out.printf(super.formatForPlay,this.name, this.numberOfStrings, this.soundDescription);
    }
}
```

### Instrument.java
```java
package main.java.music;

abstract class Instrument {
    protected String name;

    abstract public void play();
}
```

### StringedInstrument.java
```java
package main.java.music;

abstract class StringedInstrument extends Instrument {
   protected int numberOfStrings;
   final String formatForPlay ="%s, a %d-stringed instrument that %s\n";

   abstract public void play();

}
```

### Violin.java
```java
package main.java.music;


public class Violin extends StringedInstrument {

    final String nameDef = "Violin";
    final String soundDescription = "screeches";

    public Violin() {
        super();
        this.name = nameDef;
        this.numberOfStrings = 4;
    }


    @Override
    public void play() {
        System.out.printf(super.formatForPlay,this.name, this.numberOfStrings, this.soundDescription);
    }
}
```

