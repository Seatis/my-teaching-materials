/**************************************************************************************************
 * Workshop: Practice Exceptions: Cascading problems 
 * 
 * What if there are lots of different types of errors?
 *
 * We've got an array and a mad man writing idiotic code (me!).  Deal with my mayhem and get to 
 * the ::::FINISH LINE::::
 **************************************************************************************************/
import java.util.*;

public class Workshop04{
    public static void main(String[] args){

        int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};
        String two = "2";

       System.out.println("Testing ...");
	a[2] = a[3]/a[0];
       System.out.println("Past hurdle 1");
        a[9] = (int) two;
       System.out.println("Past hurdle 2");
        a[10] = "ten"; 
       System.out.println("Past hurdle 3...  And I realized perhaps I'm wrong");
        a[10] = 10;
       System.out.println("Past hurdle 4");
        two = "two";
       System.out.println("Past hurdle 5");
        a[9] = (int) two;

   
       System.out.println("*** FINISH LINE ***");
    }
}



