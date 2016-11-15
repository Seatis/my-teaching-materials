# `src` contains 

## App.java
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

    static String randomDow(int ct) {
        return lsDow[(int)( Math.random() * 6)];
    }

    static String random16() {
        String out ="";
        for(int i = 0; i<16; i++) {
            out += Integer.toString( (int) ( Math.random() * 9));
        }

        return out;
    }
}
```

## com.greenfox.bx contains

### CreditCardReservation.java
```java
package com.greenfox.bx;

public class CreditCardReservation implements CreditCardy, Reservationy {
//alt+insert to get the list of routines to implement

    CreditCard creditcard;
    Reservation reservation;

    public CreditCardReservation(String dowBooking, int sumCVV, String nameCardholder, String codeAccount) {
        reservation= new Reservation(dowBooking);
        creditcard  = new CreditCard(sumCVV, nameCardholder, codeAccount);
    }

    @Override
    public void setSumCVV(int sumCVV) {
        creditcard.setSumCVV(sumCVV);
    }

    @Override
    public void setDowBooking(String dowBooking) {
        reservation.setDowBooking(dowBooking);
    }

    @Override
    public int getSumCVV() {
        return creditcard.getSumCVV();
    }

    @Override
    public void setNameCardholder(String nameCardholder) {
        creditcard.setNameCardholder(nameCardholder);
    }

    @Override
    public String getDowBooking() {
        return reservation.getDowBooking();
    }

    @Override
    public String getNameCardholder() {
        return creditcard.getNameCardholder();
    }

    @Override
    public void setCodeBooking(String codeBooking) {
        reservation.setCodeBooking(codeBooking);
    }

    @Override
    public void setCodeAccount(String codeAccount) {
        creditcard.setCodeAccount(codeAccount);
    }

    @Override
    public String getCodeBooking() {
        return reservation.getCodeBooking();
    }

    @Override
    public String getCodeAccount() {
        return creditcard.getCodeAccount();
    }

    @Override
    public boolean PlaceReserved(String dowBooking, String codeBooking) {
        return reservation.PlaceReserved(dowBooking, codeBooking);
    }

    @Override
    public int cumeSumCVV(String codeAccount) {
        return creditcard.cumeSumCVV(codeAccount);
    }

    @Override
    public boolean ValidCard(String codeAccount, int sumCVV) {
        return creditcard.ValidCard(codeAccount, sumCVV);
    }

    @Override
    public boolean PlaceCancelled(String dowBooking, String codeBooking) {
        return true;
    }

    @Override
    public String toString() {
        return reservation.toString() + " paid by " + creditcard.toString();
    }
}

```

### CreditCardy.java
```java
package com.greenfox.bx;

interface CreditCardy {

    void setSumCVV(int sumCVV);
    int getSumCVV();
    void setNameCardholder(String nameCardholder);
    String getNameCardholder();
    void setCodeAccount(String codeAccount);
    String getCodeAccount();

    int cumeSumCVV(String codeAccount); // computes codeAccount checksum (see below)
    boolean ValidCard (String codeAccount, int sumCVV); // compare sumCVV with checksum of codeAccount
    String toString ();

}
```

### CreditCard.java
```java
package com.greenfox.bx;

public class CreditCard implements CreditCardy {

    private int sumCVV;
    private String nameCardholder;
    private String codeAccount;

    public CreditCard(int sumCVV, String nameCardholder, String codeAccount) {

        this.sumCVV = (sumCVV==0)?cumeSumCVV(codeAccount):sumCVV;
        this.nameCardholder=nameCardholder;
        this.nameCardholder=nameCardholder;
        this.codeAccount =codeAccount;

    }

    @Override
    private int cumeSumCVV(String codeAccount) {

        int sum = 0;
        char c;

        for (int i = 0; i < codeAccount.length()-1; i++) {
            c = codeAccount.charAt(i);
            sum += (c >= '0' && c <= '9') ? Character.getNumericValue(c) : 0;
        }

        return sum;

    }

    @Override
    public String toString () {
        return String.format("Name=%s CC#=%s CVV=%d", this.nameCardholder, this.codeAccount, this.sumCVV);
    }

    @Override
    public void setSumCVV(int sumCVV) {
        this.sumCVV = sumCVV;
    }

    @Override
    public int getSumCVV() {
        return sumCVV;
    }

    @Override
    public void setNameCardholder(String nameCardholder) {
        this.nameCardholder= nameCardholder;

    }

    @Override
    public String getNameCardholder() {
        return this.nameCardholder;
    }

    @Override
    public void setCodeAccount(String codeAccount) {
        this.codeAccount = codeAccount;
    }

    @Override
    public String getCodeAccount() {
        return this.codeAccount;
    }

    @Override
    public boolean ValidCard(String codeAccount, int sumCVV) {
        return (cumeSumCVV(codeAccount)==sumCVV);
    }
}
```

### Reservationy.java
```java
package com.greenfox.bx;

        public interface Reservationy {

            void setDowBooking(String dowBooking);

            String getDowBooking();

            void setCodeBooking(String codeBooking);

            String getCodeBooking();

            boolean PlaceReserved(String dowBooking, String codeBooking); //must return true if successful

            boolean PlaceCancelled(String dowBooking, String codeBooking); //must return true if successful

            String toString(); //format("Booking# %s for %s");
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


