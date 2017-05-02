# Model stringed instruments.

The classes referenced should be in a package called `main.java.music`.

We start with a base, abstract class `Instrument`.
- it reserves (e.g. protected) the `name` of the instrument
- it should provide a `play()` method.

Next, we add another abstract class, `StringedInstrument` which *extends* `Instrument`.  It
- introduces `numberOfStrings` and
- has a final `formatForPlay` string field that is the format of the String that the `play()` will include(which prints a *confirmation message* of the sound of the instruments).

```java
final String formatForPlay ="%s, a %d-stringed instrument that %s\n";
```  
Hint: If you haven't seen the above before use `System.out.printf();` for printing.

`StingedInstrument`has 3 descendants, namely:-
- Electric Guitar (6 strings, "Twang")
- Bass Guitar (4 strings, "Duum-duum-duum")
- Violin (4 strings, "Screech")

The Workshop should be invoked by an App Class which is placed outer than the package:-
```java
import main.java.music.*;

public class AppMusic {


    public static void main(String[] args) {

        System.out.println("Test 1, create Electric Guitar, Bass Guitar and Violin with default strings.");
        ElectricGuitar guitar = new ElectricGuitar();
        BassGuitar bassGuitar = new BassGuitar();
        Violin violin = new Violin();

        System.out.println("Test 1 Play");
        guitar.play();
        bassGuitar.play();
        violin.play();

        System.out.println("Test 2, create Electric Guitar, Bass Guitar with 7 and 5 strings .");
        ElectricGuitar guitar2 = new ElectricGuitar(7);
        BassGuitar bassGuitar2 = new BassGuitar(5);

        System.out.println("Test 2 Play");
        guitar2.play();
        bassGuitar2.play();
    }

}

```
We expect the following output:-

>Test 1 Play

> Electric Guitar, a 6-stringed instrument that twangs

> Bass Guitar, a 4-stringed instrument that Duum-duum-duum

> Violin, a 4-stringed instrument that screeches

> Test 2, create Electric, Bass Guitar with 7 and 5 strings.

> Test 2 Play

> Electric Guitar, a 7-stringed instrument that twangs

> Bass Guitar, a 5-stringed instrument that Duum-duum-duum
