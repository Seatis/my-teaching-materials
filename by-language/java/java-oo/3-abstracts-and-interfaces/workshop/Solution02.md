# `src` contains 

## App.java
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
}
```

## com.greenfox.bx contains

### Reservationy.java
```java
package com.greenfox.bx;

public interface Reservationy {

    void setDowBooking(String dowBooking);
    String getDowBooking();

    void setCodeBooking(String codeBooking);
    String getCodeBooking();

    boolean PlaceReserved (String dowBooking, String codeBooking); //must return true if successful
    boolean PlaceCancelled (String dowBooking,String codeBooking); //must return true if successful

    String toString (); //format("Booking# %s for %s");
}
```

### Reservation.java
```java
package com.greenfox.bx;

public class Reservation implements Reservationy {

    String dowBooking;
    String codeBooking;
    final static String ls = "01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";


    public Reservation(String dowBooking) {
        this.dowBooking = dowBooking;
        this.codeBooking = randomZeroToZ(8);
    }

    static String randomZeroToZ(int len) {
        String out = "";
        for(int i= 0; i<len; i++) {
            out += ls.charAt((int) (Math.random() * 36));
        }
        return out;
    }

    @Override
    public String toString() {

        return String.format("Booking# %s for %s", this.codeBooking, this.dowBooking);
    }


    @Override
    public String getDowBooking() {
        return this.dowBooking;
    }

    @Override
    public void setDowBooking(String dowBooking) {
        this.dowBooking = dowBooking;
    }

    @Override
    public String getCodeBooking() {
        return codeBooking;
    }

    @Override
    public void setCodeBooking(String codeBooking) {
        this.codeBooking = codeBooking;
    }

    @Override
    public boolean PlaceReserved(String dowBooking, String codeBooking) {
        return true;
    }

    @Override
    public boolean PlaceCancelled(String dowBooking, String codeBooking) {
        return true;
    }
}
```

