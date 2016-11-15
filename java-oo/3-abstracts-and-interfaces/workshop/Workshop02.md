#Create a `CreditCard` object by implementing all the features as required by the Interface.  It should go into a package library name `com.greenfox.bx`.

```java
//package ??? should set this

interface CreditCardy {

    void setSumCVV(int sumCVV);
    int getSumCVV();
    void setNameCardholder(String nameCardholder);
    String getNameCardholder();
    void setCodeAccount(String codeAccount);
    String getCodeAccount();

    int cumeSumCVV(String codeAccount); // computes codeAccount checksum (see below)
    boolean ValidCard (String codeAccount, int sumCVV); // compare sumCVV with checksum of codeAccount

    String toString (); \\String.format("Name=%s CC#=%s CVV=%d");
}
```

*What's a checksum*?  It's derived from adding values together.  For example if codeAccount = 1935, then the check sum is 1+9+3+5 or 18.

*Did you know that IntelliJ can generate the Methods of an Interface for you?*  Check 
out alt-Insert (W10) %%N (Mac).


#Tests
```java
import java.util.ArrayList;
//there's another import missing (if you set this up right

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

This should give you a result sort of like:-
```
Name=ABC0 CC#=0832572706713808 CVV=59
Name=ABC1 CC#=7358743437116556 CVV=69
Name=ABC2 CC#=5234352635810043 CVV=51
Name=ABC3 CC#=8746006842881022 CVV=64
Name=ABC4 CC#=1125887725821251 CVV=64
Name=ABC5 CC#=8241682314633624 CVV=59
Name=ABC6 CC#=3422056400811670 CVV=49
Name=ABC7 CC#=3187260122423745 CVV=52
Name=ABC8 CC#=7621381805013844 CVV=57
Name=ABC9 CC#=3250546364831081 CVV=58
```

##Also
- Why did we create the gets and sets in the CreditCardy interface?
- Why did we call it CreditCard_y_ ?