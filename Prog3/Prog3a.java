import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 * Program opens file, returns errors if not enough params or file not found 
 * @author Brandon Castro
 * @param args two command-line arguments
 */
public class Prog3a {
  
   public static void main (String[] args) {
     System.out.println("Program 3a, Brandon Castro, masc1733");
     
     FileReader read = null;
     String fileName = "";
     String word = "";
     
     if(args.length == 2) {
       fileName = args[0];
       word = args[1];
     }
     else {
       System.out.println("Usage: java Prog3a infileName searchWord");
       System.exit(0);
     }
     
     try {
       read = new FileReader(fileName);
     }
     catch(FileNotFoundException e) {
       System.out.println("File not found: "+e.getMessage());
       System.exit(0);
     }
     
     System.out.println("Opened file: "+fileName+" to search for '"+word+"'");
   }
}
