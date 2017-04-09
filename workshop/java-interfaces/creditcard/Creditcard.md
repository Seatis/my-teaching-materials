# CreditCard

Create a `CreditCard` object by implementing all the features as required by the Interface.

```java

interface CreditCardy {

    void setSumCVV(int sumCVV);
    int getSumCVV();
    void setNameCardholder(String nameCardholder);
    String getNameCardholder();
    void setCodeAccount(String codeAccount);
    String getCodeAccount();

    int cumeSumCVV(String codeAccount); // computes codeAccount checksum (see below)
    boolean ValidCard (String codeAccount, int sumCVV); // compare sumCVV with checksum of codeAccount

    String toString (); //String.format("Name=%s CC#=%s CVV=%d");
}
```

*What's a checksum*?  It's derived from adding values together.  For example if codeAccount = 1935, then the check sum is 1+9+3+5 or 18.

# Tests

```java
import java.util.ArrayList;

public class App {

    public static void main(String[] args) {


        ArrayList<CreditCard> cards = new ArrayList<CreditCard>();
        int ct = 10;

        for (int i = 0; i<ct; i++) {
            cards.add(new CreditCard(0,"ABC" + i, random16())); //parameters are CVV, name, cardnumber; when CVV is 0, then the Constructor computes the CVV, otherwise it uses the value sent
        }

        for (CreditCard iCard: cards) {
            System.out.println(iCard.toString() + (ValidCard(iCard.getCodeAccount, iCard.getSumCVV)? " (validated) " : 
" (invalid) "));
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
Name=ABC0 CC#=0832572706713808 CVV=59 (validated)
Name=ABC1 CC#=7358743437116556 CVV=69 (validated)
Name=ABC2 CC#=5234352635810043 CVV=51 (validated)
Name=ABC3 CC#=8746006842881022 CVV=64 (validated)
Name=ABC4 CC#=1125887725821251 CVV=64 (validated)
Name=ABC5 CC#=8241682314633624 CVV=59 (validated)
Name=ABC6 CC#=3422056400811670 CVV=49 (validated)
Name=ABC7 CC#=3187260122423745 CVV=52 (validated)
Name=ABC8 CC#=7621381805013844 CVV=57 (validated)
Name=ABC9 CC#=3250546364831081 CVV=58 (validated)
```
