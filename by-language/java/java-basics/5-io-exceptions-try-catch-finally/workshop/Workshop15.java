import java.util.Scanner;

public class Workshop15 {
    public static void main(String[] args) {

        System.out.println("Enter the file path, or q to Quit");

        Scanner userInput = new Scanner(System.in);
        String filePath;

        System.out.print("File path: ");

        while(userInput.hasNextLine()){
            filePath = userInput.nextLine();
            if(filePath.equals("q"))
                break;
            printFileContent(filePath);
            System.out.print("File path: ");
        }
    }

    private static void printFileContent (String filePath) {
        // Implement this function
        // Open and read the file and print it's content to the standard output
        // If a specified path does not exist write "The specified path does not exists!"
    }
}
