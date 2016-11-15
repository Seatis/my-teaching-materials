#Create a `Reservation` object by implementing all the features as required by the Interface.  It should go into a package library name `com.greenfox.bx`.

```java
//package ??? should set this

public interface Reservationy {

    void setDowBooking(String dowBooking);
    String getDowBooking();

    void setCodeBooking(String codeBooking);
    String getCodeBooking();

    boolean PlaceReserved (String dowBooking, String codeBooking); //must return true if successful
    boolean PlaceCancelled (String dowBooking,String codeBooking); //must return true if successful

    String toString (); //format("Booking# %s for %s");
```
*DOW* stands for *Day of the Week*.  I'm using this as we've not yet discussed nor played with dates.  Hence, for this app, we're just looking for MON, TUE, etc.

*the PlaceReserved and PlaceCancelled would be things that another program might expect you to have so that it could call and/or work with the object that you'd define.  In our world, they'll just always return true.

*Did you know that IntelliJ can generate the Methods of an Interface for you?*  Check 
out alt-Insert (W10) %%N (MAC).

*Did you know, if you add data type / library that is not declared in your imports, Java will suggest sources to you and add them to your program?* Check out alt-Enter (W10) -\_Enter (MAC).

*Note however, that it's better if there are going to be *Getters* and *Setters* to first create the fields in the class, and then use the Generate function.  It will wire things up and also mark the setters, etc. as `@Override`.


#Tests
```java
import com.greenfox.bx.*;
import java.util.ArrayList;

public class App {

    final static String[] lsDow = { "MON","TUE","WED","THU","FRI","SAT","SUN"};

    public static void main(String[] args) {
        ArrayList<Reservation> bookings = new ArrayList<Reservation>();
        int ct = 10;

        for (int i = 0; i<ct; i++) {
            bookings.add(new Reservation(randomDow(10)));
        }

        for (Reservation iBooking: bookings){
            System.out.println(iBooking.toString());
        }
    }

    static String randomDow(int ct) {
        return lsDow[(int)( Math.random() * 6)];
    }
```
*Look at how we generate the random days of the week; could you explain it?

To build the random reservation code, I did something similar:-

```java
public class Reservation ... 
{    
   // this is somewhere in the code...
   final static String ls = "01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   
   // and someplace else in the code
   this.codeBooking = randomZeroToZ(8);

   ...

   // and this is how I got the code
    static String randomZeroToZ(int len) {
        String out = "";
        for(int i= 0; i<len; i++) {
            out += ls.charAt((int) (Math.random() * 36));
        }
        return out;
    }
}
```

This should give you a result sort of like:-
```
Booking# 1WBA3OMU for THU
Booking# 0V5OH7VS for WED
Booking# CV6QOAJO for MON
Booking# 03GHEJMV for SAT
Booking# M5JFB32I for THU
Booking# W30PF0E0 for SAT
Booking# S0R70GMN for SAT
Booking# 3E032B3C for WED
Booking# OD27E36J for SAT
Booking# 4MEU0657 for MON
```

