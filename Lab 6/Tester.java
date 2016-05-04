/**
 * This is only a partial test program. Yours will test more functions and types.
 */
 
public class Tester {

	public static void main(String[] args) {

	   ArrayList<Integer> list = new ArrayList<Integer>(5);
	   
	   list.add(0);
	   list.add(1);
	   System.out.println(list);
	   
	   list.add(1,11);
	   System.out.println(list);
	   
	   list.add(3,33);
	   System.out.println(list);
	  
	   list.add(5,33);
	   System.out.println(list);
	   
	   ArrayList<String> slist = new ArrayList<String>(3);

	   slist.add("empty basket of fruit");
	   slist.add("apple");
	   System.out.println(slist);
	   
	   slist.add(1,"banana");
	   System.out.println(slist);
	   
	   slist.add(3,"cranberry");
	   System.out.println(slist);
	   
	   slist.add(5,"fresh fruit");
	   System.out.println(slist);
	}
}
