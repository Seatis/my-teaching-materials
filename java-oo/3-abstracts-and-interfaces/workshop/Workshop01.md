Model stringed instruments.

The classes referenced should be in a package called `main.java.music`.

We start with a base, abstract class `Instrument`.
- it reserves (e.g. protected) the `name` of the instrument 
- it expects those who extend it to provide a `play()` method (which will print a *confirmation message*).

Next, we add another abstract class, `StringedInstrument` which builds (*extends*) `Instrument`.  It 
- introduces `numberOfStrings` and 
- has a final `formatForPlay` that its children reference in their implementations of `play()`.

```java
final String formatForPlay ="%s, a %d-stringed instrument that %s\n";
```  

Next, we have 3 constructs of the `StingedInstrument`, namely:-
- Electric Guitar (6 strings, "Twang")
- Electric BassGuitar (4 strings, "Duum-duum-duum")
- Violin (4 strings, "Screech")

The Workshop should be invoked now by an App Class:-
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

        System.out.println("Test 2, create ElectricGuitar, Bass with 7 and 5 strings .");
        guitar = new ElectricGuitar(7);
        bassGuitar = new ElectricBassGuitar(5);

        System.out.println("Test 2 Play");
        guitar.play();
        bassGuitar.play();
    }

}

```
We expect the following output:-

>Test 1 Play

> Electric Guitar, a 6-stringed instrument that twangs

> Bass Guitar, a 4-stringed instrument that Duum-duum-duum

> Violin, a 4-stringed instrument that screeches

> Test 2, create ElectricGuitar, Bass with 7 and 5 strings.

> Test 2 Play

> Electric Guitar, a 7-stringed instrument that twangs

> Bass Guitar, a 5-stringed instrument that Duum-duum-duum

