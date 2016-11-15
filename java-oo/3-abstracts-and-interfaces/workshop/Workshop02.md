#Create a `Reservation` object by implementing all the features as required by the Interface.  It should go into a package library name `com.greenfox.bx`.

```java
//package ??? should set this
import java.util.Date; // described in an Optional Video

public interface Reservationy {

    void setDateBooking(Date dateBooking);
    Date getDateBooking();

    void setCodeBooking(String codeBooking);
    String getCodeBooking();

    boolean PlaceReserved (Date dateBooking, String codeBooking); //must return true if successful
    boolean PlaceCancelled (Date dateBooking,String codeBooking); //must return true if successful
    
    String toString (); //format("Booking# %s for #s")

}

```

*the PlaceReserved and PlaceCancelled would be things that another program might expect you to have so that it could call and/or work with the object that you'd define.

*Did you know that IntelliJ can generate the Methods of an Interface for you?*  Check 
out alt-Insert (W10) %%N (Mac).

*Note however, that it's better if there are going to be *Getters* and *Setters* to first create the fields in the class, and then use the Generate function.  It will wire things up and also mark the setters, etc. as `@Override`.


#Tests
```java
import java.util.ArrayList;
//there's another import missing (if you set this up right

public class App {

    public static void main(String[] args) {


        ArrayList<Reservation> bookings = new ArrayList<Reservation>();
        int ct = 10;

        for (int i = 0; i<ct; i++) {
            cards.add(new Reservation(randomDate(10), random16()));
        }

        for (Reservation iBooking: bookings{
            System.out.println(iBooking.toString());
        }

    }

    static String random16() {
        String out ="";
        for(int i = 0; i<16; i++) {
            out += Integer.toString( (int) ( Math.random() * 9));
        }

        return out;
    }

    //static Date randomDate(int ctDaysFromTomorrow) // generates a random date between tomorrow and ctDaysFromTomorrow
}
```

This should give you a result sort of like:-
```
!!TBA
```

