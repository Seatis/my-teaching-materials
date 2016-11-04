import java.util.*;

public class Workshop08{
  public static void main(String... args){
    LinkedList<String> linkedList = new LinkedList<String>(Arrays.asList("second", "third", "fourth"));
    // Add "first" to the beginning of the list and add "fifth" to the end of the list
    // Expected output: [first, second, third, fourth, fifth]

    System.out.println(linkedList);
  }
}

