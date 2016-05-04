/**
 * Reads double values from file and prints them as longitude/longitude pairs
 * @author Brandon Castro
 * @param args one command-line argument
 */
import java.util.Scanner;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Prog3c {
  
  public static void main (String[] args) throws IOException {
    System.out.println("Program 3a, Brandon Castro, masc1733");
    
    FileInputStream read = null;
    Scanner inScan = null;
    File newFile = null;
    
    if(args.length != 1) {
      System.out.println("Usage: java Prog3a infileName");
      System.exit(0);
    }
    
    try {
      read = new FileInputStream(args[0]);
    }
    catch(FileNotFoundException e) {
      System.out.println("File not found: "+e.getMessage());
      System.exit(0);
    }
    
    Scanner temp = new Scanner(read);
    int r = 0;
    while(temp.hasNextLine()) {
      r++;
      temp.nextLine();
    }
    
    double[][] array = new double[r][2];
    r = 0;
    read = new FileInputStream(args[0]);
    inScan = new Scanner(read);
    
    
    while(inScan.hasNextLine()) {
      String line = inScan.nextLine();
      Scanner scan = new Scanner(line);
      int i = 0;
      while(scan.hasNextDouble()) {
        array[r][i] = scan.nextDouble();
        i++;
      }
      scan.close();
      if(inScan.hasNextLine()) r++;
    }
    printArray(array);
  }
  
  public static void printArray(double[][] a) {
    for(int i = 0; i < a.length; i++)
      for(int j = 0; j < a[i].length; j++) {
      if(j==0)
        System.out.print("latitude: "+a[i][j]+", ");
      else
        System.out.print("longitude: "+a[i][j]+"\n");
    }
  }
}