public class Squared {

// Examine first the process_array method
// Why is this an O(N²) complexity?
// Play with the size of the collection and notice how the execution time changes
// Try to make the process_array it cubic (hint: keep the collection size low)

  public static void main(String[] args) {

//    Generating a big array of numbers

    int sizeOfCollection = 1000;
    int[] collection = new int[sizeOfCollection];

    for (int i = 0; i < sizeOfCollection; i++) {
      collection[i] = i;
    }

    long start = System.nanoTime();

//    call the array processor function
    processArray(collection);

    double elapsedTime = (System.nanoTime() - start) / 1000000000.;

    System.out.println(elapsedTime);


  }

//  A function that makes some operation
  private static int[] processArray(int[] numberArray) {
    for (int i : numberArray) {
      for (int j = 0; j < numberArray.length; j++) {
//        some nonsense calculation to make the CPU tick a bit
        numberArray[j] *= i;
      }
    }
    return numberArray;
  }

}
