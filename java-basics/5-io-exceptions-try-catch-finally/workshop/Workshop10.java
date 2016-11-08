/**************************************************************************************************
 * Workshop: Practice Exceptions: There are many types of exceptions, in the code that follows
 * look through what the problem is, and then figure out how to trap and continue
 * 
 * Write this as 3 separate; and then repeat, as 1 total try/catch
 **************************************************************************************************/

public class Workshop10{

   public static void main(String  args[]) {

   // you'll be putting these in try/catch and looking at the exception message; then figuring 
   // out how to trap for that specific exception to continue through the code.

   String strTest=null;
   System.out.println("Hurdle 01");
   System.out.println(strTest.length);

   strTest="The quick brown fox jump over the lazy dog";
   println("Hurdle 02: Setup");
   System.out.println(strTest.length());

   char c = strTest.charAt(0);
   System.out.println("Char 0 = " + c);

   System.out.println("Hurdle 02: Catch");
   c = strTest.charAt(strTest.length); // I'm numerically challenged here

   System.out.println("Hurdle 03");
   int num = Integer.parseInt(strTest); 




   
}



