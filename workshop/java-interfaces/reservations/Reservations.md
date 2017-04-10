# Reservations
Create a `Reservation` object by implementing all the features as required by the Interface.<br />
The booked reservations should look like the output below.<br />
Please note that the reservation code should contain 8 characters randomly from 0-Z, all uppercase letters.<br />
Also, the DOW is randomly ordered to the bookings from an array.<br />
*DOW* stands for *Day of the Week* (MON, TUE, etc.)

```java
//package name should be figured out

public interface Reservationy {

    void setDowBooking(String dowBooking);
    String getDowBooking();

    void setCodeBooking(String codeBooking);
    String getCodeBooking();

    boolean placeReserved (String dowBooking, String codeBooking); //must return true if successful
    boolean placeCancelled (String dowBooking,String codeBooking); //must return true if successful

    String toString (); //format("Booking# %s for %s");
```

```java
import com.greenfox.bx.*;
import java.util.ArrayList;

public class ReservationApp {

    public static void main(String[] args) {

    }
```

```java
public class Reservation ... {    

}
```

The output will be sort of like this:-
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
