# `src` contains 

## App.java
```java
import com.greenfox.bx.*;
import java.util.ArrayList;

/**
 * Created by eric.hofer on 11/15/2016.
 */
public class App {

    public static void main(String[] args) {


        ArrayList<CreditCard> cards = new ArrayList<CreditCard>();
        int ct = 10;

        for (int i = 0; i<ct; i++) {
            cards.add(new CreditCard(0,"ABC" + i, random16()));
        }

        for (CreditCard iCard: cards) {
            System.out.println(iCard.toString());
        }

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

