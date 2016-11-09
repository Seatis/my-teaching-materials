/**************************************************************************************************
 * Workshop: Practice With Exceptions: InputMismatchException
 * Write a routine that catches an InputMismatchException.
 *
 * Use the Scanner routine to take the input from the keyboard; if the value is okay then
 * print "Yum", and show the first half of the value entered, for example:-
 *
 * INPUT or 0 to end?  12334556677723131
 * Too High
 * (and the Java exception messages)
 * INPUT or 0 to end?  12345678
 * Yum 1234
 * INPUT or 0 to end?  12345
 * Yum 12
 * INPUT or 0 to end? 0
 * Bye!
 **************************************************************************************************/
import java.util.*;
public class Workshop03{
    static Scanner userInput = new Scanner(System.in);
    public static void main(String[] args) {
        Integer number = 1;
        String s ;
        while (number !=0 ) {
            number = checkIfValid();
            s = number.toString();
            System.out.println("Yum" +  s.substring(0,s.length()/2));
        }
    }
    public static Integer checkIfValid() {
        int i =0;
        boolean flLoop = true;
        while (flLoop) {
            System.out.print("Type in a number: ");
            i = userInput.nextInt();
            flLoop = false;
            userInput.nextLine();
        }
        return i;
    }
 } //Workshop03
