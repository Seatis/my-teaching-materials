/**************************************************************************************************
 * Workshop: Practice Exceptions: Read past the end of an array
 * 
 * Welcome to crap coding by a mentor week!
 *
 * You have an array and the program tries to read past the end.  How do you ensure that you
 * still get to the finish line?
 **************************************************************************************************/
import java.util.*;

public class Lesson01{
    public static void main(String... args){
        String[] numbers = new String[] { "one", "two", "three", "four", "five"};

        for(int i = 0; i <= numbers.length; i++) {
            System.out.print(i);
            System.out.print("=" + numbers[i] + "\n");

        }

       System.out.println("*** FINISH LINE ***");
    }
}



