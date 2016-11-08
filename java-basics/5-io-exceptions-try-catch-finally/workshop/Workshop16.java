/**
 * File I/O: Dont forget to Write
 * 
 * There was once just ones and zeroes.  And it was bad, to tell the machine anything was a long 
 * process of toggling these little switches Up or Down and then pressing a "Master" button.
 * Oh, but to be the head boy (there weren't any girls in our computer club back then) that got to 
 * restart the computer...
 * 
 * This challenge, back in the day, would have been awe inspiring.  You're going to take input
 * from the scanner and copy such to a file.
 * This is how it should work.
 * 
 * Note, >>> means that what the computer does; and <<< is what you the user does.
 * >>> Enter the filename (assuming writing to C:\TEMP\)?  
 * <<< Test.txt
 * >>> Writing to Test.txt; when done press enter 3 times.
 * <<< Mary had a little lamb
 * <<< Her fleece as white as snow
 * <<< And everywhere that Mary went
 * <<< Her lamb was sure to go.
 * <<<
 * <<<
 * <<<
 * >>> Done, wrote 102 Characters to C:\TEMP\Test.txt.
 *
 */

import java.io.File;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Scanner;

public class Workshop16 {

    public static void main(String[] args) {

        System.out.println("Enter the filename (assuming writing to C:\TEMP\), or q to Quit");

        Scanner userInput = new Scanner(System.in);

        String strNameOfFile;
	int ctCharacters;
        System.out.print("Path: ");

        while(userInput.hasNextLine()){
            strNameOfFile = userInput.nextLine();
            if(strNameOfFile.equals("q"))
                break;
            writeStuff (strNameOfFile, ctCharacters);
            System.out.print("!!"); //complete this, remember the ctCharacters
        }


    }

    private static void writeStuff (String pathToList) {
  	//open the file, blow up if already there

	//next Scanner While to take the input and transfer to the file
	// count the number of characters transferred
	// look for 3 empty strings in a row and then quit

	//after while close
    }
}
