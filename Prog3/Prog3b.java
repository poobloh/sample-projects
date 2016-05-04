/**
 * Reads a csv file of doubles, writes a new file of same values with a space separating values
 * @author Brandon Castro
 * @param args two command-line arguments
 */
import java.util.Scanner;
import java.io.File;
import java.io.FileInputStream;
import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Prog3b {
  
   public static void main (String[] args) throws IOException {
     System.out.println("Program 3a, Brandon Castro, masc1733");
     
     FileInputStream read = null;
     Scanner inScan = null;
     PrintWriter write = null;
     File newFile = null;
     
     if(args.length != 2) {
       System.out.println("Usage: java Prog3a infileName outfileName");
       System.exit(0);
     }
     
     try {
       read = new FileInputStream(args[0]);
       newFile = new File(args[1]);
       if(newFile.exists())
         System.out.println("File already exists: "+args[1]);
     }
     catch(FileNotFoundException e) {
       System.out.println("File not found: "+e.getMessage());
       System.exit(0);
     }
     write = new PrintWriter(newFile);
     
     inScan = new Scanner(read);
     while(inScan.hasNextLine()) {
       String line = inScan.nextLine();
       Scanner scan = new Scanner(line);
       while(scan.hasNext()) {
         write.print(scan.nextDouble());
         if(scan.hasNext())
           write.print(",");
       }
       if(inScan.hasNextLine())
         write.println("");
       scan.close();
     }
     write.close();
   }
}