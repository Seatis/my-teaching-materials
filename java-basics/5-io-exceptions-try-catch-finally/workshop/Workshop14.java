/** Workshop14: Working with I/O
 *  Input/Output are referred to as "streams" of data.  They're just characters, one-after-the-other.
 *  Files can be constructed in different ways.  Sometimes the data is:-
 *  Fixed Columns - eg. from column 1 to 6 is the code, 7-25 the name, etc.
 *  - this poses a problem if the space isn't enough; but it's fast to read
 *  Delimited with commas, tabs, or some other character - eg. 12,41,Joe
 *  - this poses a challenge if, for example, you want to send a comma - in this case 12,"joe, tim & harry",15
 *  Serialised - for example like xml <P>here's some data</P>
 *
 *  Streams are the basis for databases; but with a database we have the ability to find specific records
 *  (usually with a key, for example a customer code).
 *  
 *  Before you run, change the D:/Eric/JavaBits/ to a directory on your pc.
 *  Set a breakpoint early on; and then run in the debugger.
 *  After you've run this, go look at directory where you wrote the data.
 */

import  java.io.*;

public class Workshop14{

    private static String filePathAndName = "D:/Eric/JavaBits/customers.txt";

    public static void main(String[] args){

        // Create an array of type Customer
        Customer[] customers = getCustomers();

        // PrintWriter is used to write characters to a file in this situation
        PrintWriter custOutput = createFile(filePathAndName);

        // Enhanced for loop for arrays
        // Cycles through all of the people in the customers array
        for(Customer person : customers){
            createCustomers(person, custOutput);
        }

        // Closes the connection to the PrintWriter
        custOutput.close();
        getFileInfo();
    }

    // class that defines all the fields for my customers

    private static class Customer{

        public String firstName, lastName;
        public int custAge;

        // constructor that's called when a customer is made
        public Customer(String firstName, String lastName, int custAge){
            this.firstName = firstName;
            this.lastName = lastName;
            this.custAge = custAge;
        }
    }

    // Creates an array of Customer Objects
    private static Customer[] getCustomers(){

        Customer[] customers = new Customer[5];
        customers[0] = new Customer("John", "Smith", 21);
        customers[1] = new Customer("Sally", "Smith", 30);
        customers[2] = new Customer("Paul", "Ryan", 21);
        customers[3] = new Customer("Mark", "Jacobs", 21);
        customers[4] = new Customer("Steve", "Nash", 21);

        return customers;
    }

    // Create the file and the PrintWriter that will write to the file
    private static PrintWriter createFile(String fileName){

        try{

            // Creates a File object that allows you to work with files on the hardrive
            File listOfNames = new File(fileName);

            // FileWriter is used to write streams of characters to a file
            // BufferedWriter gathers a bunch of characters and then writes
            // them all at one time (Speeds up the Program)
            // PrintWriter is used to write characters to the console, file

            PrintWriter infoToWrite = new PrintWriter(
                    new BufferedWriter(
                            new FileWriter(listOfNames)));
            return infoToWrite;
        }

        // You have to catch this when you call FileWriter

        catch(IOException e){

            System.out.println("An I/O Error Occurred");

            // Closes the program

            System.exit(0);

        }
        return null;

    }

    // Create a string with the customer info and write it to the file

    private static void createCustomers(Customer customer, PrintWriter custOutput){

        // Create the String that contains the customer info

        String custInfo = customer.firstName + " " + customer.lastName + " ";
        custInfo += Integer.toString(customer.custAge);

        // Writes the string to the file

        custOutput.println(custInfo);

    }

    // Read info from the file and write it to the screen

    private static void getFileInfo(){

        System.out.println("Info Written to File\n");

        // Open a new connection to the file
        File listOfNames = new File(filePathAndName);

        try {

            // FileReader reads character files
            // BufferedReader reads as many characters as possible
            BufferedReader getInfo = new BufferedReader(
                    new FileReader(listOfNames));

            // Reads a whole line from the file and saves it in a String
            String custInfo = getInfo.readLine();

            // readLine returns null when the end of the file is reached
            while(custInfo != null){

                // System.out.println(custInfo);

                // Break lines into pieces
                String[] indivCustData = custInfo.split(" ");

                // Convert the String into an integer with parseInt
                int custAge = Integer.parseInt(indivCustData[2]);

                System.out.print("Customer " + indivCustData[0] + " is " + custAge +"\n");

                custInfo = getInfo.readLine();
            }
        }

        // Can be thrown by FileReader
        catch (FileNotFoundException e) {
            System.out.println("Couldn't Find the File");
            System.exit(0);
        }

        catch(IOException e){
            System.out.println("An I/O Error Occurred");
            System.exit(0);
        }
    }
}