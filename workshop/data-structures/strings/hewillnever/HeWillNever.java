import java.util.*;

public class HeWillNever {
  public static void main(String... args){
    String out = "";
    int[] notSoCrypticMessage = {1, 12, 1, 2, 11, 1, 7, 11, 1, 49, 1, 3, 11, 1, 50, 11};

    Map<String, String> map = new HashMap<String, String>();

    map.put(7, "run around and desert you");
    map.put(50, "tell a lie and hurt you");
    map.put(49, "make you cry,");
    map.put(2, "let you down");
    map.put(12, "give you up,");
    map.put(1, "Never gonna");
    map.put(11, "\n");
    map.put(3, "say goodbye");

    // Things are a little bit messed up
    // Your job is to decode the notSoCrypticMessage by using the hashmap as a look up table
    // Assemble the fragments into the out variable

    System.out.println(out);
  }
}
