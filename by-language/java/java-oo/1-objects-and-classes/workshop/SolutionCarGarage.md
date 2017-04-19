This solution consists of:-
+ Car
+ App which fills the Garage
This is not the *only* way to do such.

```java
public class Car {

    private String typeCar;
    private String color;
    private int ccs;
    private int kmOdometer;
    static private int carCount = -1;
    private enum tyWanted {CC, COLOR, MAKE};  //using enum type to ensure that we only define the options 1 time
    //define the variable list for random things one time to make the random assignment function faster
    private static final String[] lsCC = {"1100", "1400", "1600", "1800", "2500"}; 
    private static final String[] lsMAKE = {"Toyota", "Mazda", "BMW", "VW", "Opel", "Suzuki", "Ford", "Mercedes"};
    private static final String[] lsCOLOR ={"white", "blue", "red", "silver", "black", "green", "banana"};

    //Primary Constructor
    public Car(String typeCar, String color, int ccs, int kmOdometer) {
        this.typeCar=typeCar;
        this.color = color;
        this.ccs = ccs;
        this.kmOdometer = kmOdometer;
        // as all constructors calls this in the end, this is where carCount is done
        carCount++;
    }

    //NOTICE!! Alias Constructors
    public Car() {
        this(true);
    }

    public Car(String typeCar, String color) {
        this(typeCar, color, 1600, 10);
    }

    public Car(int ccs, int kmOdometer) {
        this("Mazda", "red", ccs, kmOdometer);
    }

    public Car (boolean flRandom) {

        // this must be the first statement in the constructor so if there's an alt it must be inline
        this( //this is calling the Car(4 element) constructor
                (flRandom)? getRandomItem(tyWanted.MAKE) : "Mazda",
                (flRandom)? getRandomItem(tyWanted.COLOR) : "red",
                (flRandom)? Integer.parseInt( getRandomItem(tyWanted.CC)) : 1600,
                12312
        );
    }


    public String getTypeCar() {
        return typeCar;
    }

    public void setTypeCar(String typeCar) {
        this.typeCar = typeCar;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public int getCcs() {
        return ccs;
    }

    public void setCcs(int ccs) {
        this.ccs = ccs;
    }

    public int getKmOdometer() {
        return kmOdometer;
    }

    public void setKmOdometer(int kmOdometer) {
        this.kmOdometer = kmOdometer;
    }

    public static int getCarCount() {
        return carCount;
    }

/* THIS IS WRONG in this situation; the carCount can not be set externally; it is only set by the constructor
    public static void setCarCount(int carCount) {
        Car.carCount = carCount;
    }
*/


    static String getRandomItem(tyWanted wants) {

        int rand;
        String ls[];

        switch (wants) {
            case CC:
                ls = lsCC.clone();
                break;
            case MAKE:
                ls = lsMAKE.clone();
                break;
            default: // else
                ls = lsCOLOR.clone();
        }

        rand = (int)(Math.random() * (ls.length - 1));
        return ls[rand];
    }

    public void drive (int distance) {
        kmOdometer+=distance; //did you have this
    }

    public String toString() {
        return String.format("This %s is %s, has %d cc engine and clocked %d km's", getTypeCar(), getColor(), getCcs(), getKmOdometer());
    }
}
```

```java
import java.util.ArrayList;

public class App {

    public static void main(String[] args) {

        ArrayList<Car> garage = new ArrayList<Car>();
        int ct = 40;

        for (int i = 0; i<ct; i++) {
            garage.add(new Car(true));
        }

        for (Car iCar: garage) {
            System.out.println(iCar.toString());
        }
    }
}

```
