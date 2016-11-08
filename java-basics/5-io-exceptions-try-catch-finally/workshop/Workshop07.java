/**************************************************************************************************
 * Workshop: Practice Exceptions: Throw an Exception
 * 
 * Let's face it, the number "7" is a bad egg.  It might be a lucky number for some people, but they
 * don't see if for what it is.  It's a "cannibal."  It's the Elephant in the Room and EVERYBODY 
 * knows it.  You know it.  Shaking your head?  You do...  
 * Just start counting
 * one, two, three, four, five, six, seven, ate, nine,
 * That's right, 7 ate 9...  
 * 
 * And for that reason, 7 isn't allowed in my input anymore...  If a user enters a 7, I want an exception!
 *
 * So write a routine that throws an exception on the presence of 7.
 *
 * NOTE. Extra points if you knew the definition of "reprobate" without having to check the "Urban
 * Dictionary"
 *
 * NOTE NOTE: get this right.  We use this again in further exercises!
 *
 **************************************************************************************************/
import java.util.*;

public class Workshop07{

    public void myMethod(int testnum) // something should appear here before 
    {
     	if (testnum == 7) // do that thing that chucks the reprobate out
        return;
    }

    public static void main(String[] args){

        Scanner userInput = new Scanner(System.in);
        int age;
        String prompt = "Enter any number, 0 to exit?";

        System.out.println(prompt);
        while (userInput.hasNextInt()) {
            age = userInput.nextInt();
            if (age==0) {
		break; 
	    } else {
                try {
                    System.out.println("try - first statement");
                    myMethod(testnum);
                    System.out.println("try - last statement");
                }
                catch ( Exception ex) {
                    System.out.println("An Exception");
                }
          } //while
      } // main
} //Workshop
