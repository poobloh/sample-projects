package lab6;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CoupleClient<T> {
	public static void main(String[] args) throws FileNotFoundException {
		checkUsage(args);
		Scanner fReader = null;
		try {
			File fInput = new File(args[0]);
			//File fInput = new File("c:\\users\\owner\\cs108\\genlab\\cclient.txt");
			fReader = new Scanner(fInput);
		}
		catch (FileNotFoundException fnfe) {
			System.out.println("File not found");
			System.exit(0);
		}
		Couple<String> cs = new Couple<String>(fReader.next(), fReader.next());
	    Couple<Double> cd = new Couple<Double>(fReader.nextDouble(), fReader.nextDouble());
	    Couple<Integer> ci = new Couple<Integer>(fReader.nextInt(), fReader.nextInt());		
	    
	      System.out.println(cs);
	      System.out.println(cd);
	      cs.setFirst("moonlit");
	      cd.setSecond(-12.34);
	      System.out.println(cs);
	      System.out.println(cd);

	      Couple<String> cs2 = new Couple<String>("one", "Couple");
	      Couple<Couple<String> > ccs = new Couple<Couple<String> >(cs, cs2);
	      System.out.println(ccs);
	      
	      Couple<String> cs3 = new Couple<String>("dark", "night");
	      
	      System.out.println("cs equals cd: " + cs.equals(cd));
	      System.out.println("cs equals cs2: " + cs.equals(cs2));
	      System.out.println("cs equals cs3: " + cs.equals(cs3));
	      System.out.println("cs equals ccs: " + cs.equals(ccs));
	      System.out.println("cs equals ccs.first: " + cs.equals(ccs.getFirst()));
	      System.out.println("cs equals ccs.second: " + cs.equals(ccs.getSecond()));
	      
	      System.out.println(cs2.getFirst() + " " + cs.getFirst() + " " + cs3.getSecond());
	}
	public static void checkUsage(String[] args)
	{
		if (args.length != 1) 
		{
			System.out.println("Usage: java CoupleClient inputFileName");
			System.exit(0);
		}
	}
}
/*	Output
 * 	

	      

*/
	

