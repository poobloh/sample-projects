/**
 *  Program 6
 *  Tests the ArrayList generic type class
 *  CS108-2
 *  18 November 2015
 *  @author Brandon Castro
 */

public class ArrayListClient {

	public static void main(String[] args) {
	
	   System.out.println("Program 6, Brandon Castro, masc1733\n");
 	   System.out.println("Testing Integer Array:\n------------------------");
	   ArrayList<Integer> list = new ArrayList<Integer>(5);
	   
	   list.add(0);
	   list.add(1);
	   System.out.println("add(0), add(1):\t"+list);
	   
	   list.add(1,11);
	   System.out.println("add(1,11):\t"+list);
	   
	   list.add(3,33);
	   System.out.println("add(3,33):\t"+list);
	   System.out.println("Does array contain a 5? "+list.contains(5));
	   System.out.println("What is index of 11? "+list.indexOf(11));
	   System.out.println("Size is "+ list.size());
	   list.add(5,88);
	   System.out.println("add(5,88):\t"+list);
	   list.add(5,77);
	   System.out.println("add(5,77):\t"+list);
	   System.out.println("Is list empty? "+ (list.isEmpty()));
	   System.out.println("Size is "+ list.size());
	   System.out.println("get(3):\t\t"+ list.get(3));
	   list.clear();
	   System.out.println("Clear():\t"+list);
	   System.out.println("Is list empty? "+ (list.isEmpty()));
	   System.out.println("Size is "+ list.size());
	   
	   System.out.println("\nTesting String Array:\n------------------------");
	   ArrayList<String> slist = new ArrayList<String>(3);

	   slist.add("empty basket of fruit");
	   slist.add("apple");
	   System.out.println("Testing add() twice:\t"+slist);
	   
	   slist.add(1,"banana");
	   System.out.println("add(1,\"banana\"):\t"+slist);
	   
	   slist.add(3,"cranberry");
	   System.out.println("add(3,\"cranberry\":\t"+slist);
	   System.out.println("Does array contain \"pear\"? "+slist.contains("pear"));
	   System.out.println("Does array contain \"banana\"? "+slist.contains("banana"));
	   System.out.println("What is index of \"banana\"? "+slist.indexOf("banana"));
	   System.out.println("get(3):\t\t\t"+ slist.get(3));
	   slist.remove(0);
	   System.out.println("remove(0):\t\t"+slist);
	   System.out.println("\nTesting Exceptions and Errors:\n------------------------");
	   slist.add(5,"fresh fruit");
	   System.out.println(slist);
	   
	   
	   ArrayList<Integer> newList = new ArrayList<Integer>(5);
	   newList.add(512);
	   newList.add(6342);
	   newList.add(235);
	   System.out.println(newList);
	   newList.trimToSize();
	   System.out.println(newList);
	   
	}
}
