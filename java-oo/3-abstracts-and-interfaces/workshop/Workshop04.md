#Workshop04 - And object based upon 2 interfaces.
Extending from the work already done, lets now implement an interface using for the `CreditCard` and `Reservation` interfaces, implementing all the features as required by the Interface.  It should go into a package library name `com.greenfox.bx`.

```java
package com.greenfox.bx;

public class CreditCardReservation implements CreditCardy, Reservationy {
//alt+insert to get the list of routines to implement



```
You've already identified and defined the objects you need (*CreditCard* and *Reservation*); and their methods and fields are already in your package library.  

You've also got the "randomizing" function to fill in the data from previous encounters.

You'll have to think about how to get the constructor to work.

When configuring the required .toString, please join the items with xxx + " paid by " + yyy.

#Tests
```java
import com.greenfox.bx.*;
import java.util.ArrayList;

public class App {

    final static String[] lsDow = { "MON","TUE","WED","THU","FRI","SAT","SUN"};

    public static void main (String[] args) {
        ArrayList<CreditCardReservation> bookings = new ArrayList<CreditCardReservation>();
        int ct = 10;

        for (int i = 0; i<ct; i++) {
            bookings.add(new CreditCardReservation(randomDow(10),0,"DEF" + i , random16()));
        }

        for (CreditCardReservation iBooking: bookings){
            System.out.println(iBooking.toString());
        }

    }

/// other routines you've already built go here....
}

```

This should give you a result sort of like:-
```
Booking# W1JY0G2F for THU paid by Name=DEF0 CC#=4816517622284450 CVV=65
Booking# VF07H53A for WED paid by Name=DEF1 CC#=2658174467257148 CVV=69
Booking# J4D3E06I for THU paid by Name=DEF2 CC#=2112327854006586 CVV=54
Booking# X2TAKCLU for MON paid by Name=DEF3 CC#=2630505026073235 CVV=44
Booking# SK0H0WW2 for SAT paid by Name=DEF4 CC#=3212133326018817 CVV=44
Booking# YKN94EGC for TUE paid by Name=DEF5 CC#=1400838480307501 CVV=51
Booking# HE7KMY3R for SAT paid by Name=DEF6 CC#=8517042626047018 CVV=53
Booking# N1BNDOSI for WED paid by Name=DEF7 CC#=2247721652203033 CVV=46
Booking# 95OFM0S9 for SAT paid by Name=DEF8 CC#=1862050667630175 CVV=58
Booking# RI2M2QA4 for SAT paid by Name=DEF9 CC#=0488288404208460 CVV=66
```

