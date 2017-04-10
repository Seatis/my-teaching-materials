# CreditCard

Create a `CreditCard` class by implementing all the features as required by the interface.<br />
The task is to reach the output below and create 10 instances of CreditCards in a list.<br />
CC# equals to 16 randomly generated number.<br />
`String.format` acts similarly as `System.out.printf();` in the previous exercise, however the string will not be automatically printed.<br />
*What's a checksum*?  It's derived from adding values together.<br />
For example if codeAccount = 1935, then the check sum is 1+9+3+5 or 18.

```java

interface CreditCardy {

    void setSumCVV(int sumCVV);
    int getSumCVV();
    void setNameCardholder(String nameCardholder);
    String getNameCardholder();
    void setCodeAccount(String codeAccount);
    String getCodeAccount();

    int cumeSumCVV(String codeAccount); // computes codeAccount checksum
    boolean validCard (String codeAccount, int sumCVV); // compare sumCVV with checksum of codeAccount

    String toString (); //String.format("Name=%s CC#=%s CVV=%d");
}
```

```java
public class CreditCardApp {

    public static void main(String[] args) {

    }
}
```

This should give you a result sort of like:-
```
Name=ABC0 CC#=6765350286622461 CVV=69 (validated)
Name=ABC1 CC#=8783542566213117 CVV=69 (validated)
Name=ABC2 CC#=3771087365240408 CVV=65 (validated)
Name=ABC3 CC#=4816248346664688 CVV=84 (validated)
Name=ABC4 CC#=7260457613354654 CVV=68 (validated)
Name=ABC5 CC#=2202157751114048 CVV=50 (validated)
Name=ABC6 CC#=6472773572875471 CVV=82 (validated)
Name=ABC7 CC#=8741321673234632 CVV=62 (validated)
Name=ABC8 CC#=8406518208481772 CVV=71 (validated)
Name=ABC9 CC#=3518857486015857 CVV=81 (validated)
```
