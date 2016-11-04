import java.util.*;

public class Workshop10{
  public static void main(String... args){
    LinkedList<String> linkedList = new LinkedList<String>(Arrays.asList("first", "second", "third", "fourth", "fifth"));
    // Print all elements of the list

    // Solution
    for(int i=0;i<linkedList.size();i++){
      System.out.print(linkedList.get(i) + " ");
    }
    // End of solution
  }
}
