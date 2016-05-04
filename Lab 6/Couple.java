package lab6;

public class Couple<T> {

		   // fields
		   private T first;
		   private T second;
		   
		   // constructor
		   Couple(T f, T s) {
			   first = f; 
			   second = s;
		   }
		   
		   // ADT operations: getters and setters
		   T getFirst() {
			   return first;
		   }
		   T getSecond(){
			   return second;
		   }
		   void setFirst(T f){
			   first = f;
		   }
		   void setSecond(T s){
			   second = s;
		   }
		   
		   // override an Object method
		   // @override commented out because compiler cannot resolve type
		   public String toString() {
		      return "(" + first.toString() + ", " + second.toString() + ")"; 
		   }
		   
		   // override another Object method
		   @SuppressWarnings("unchecked")
		   public boolean equals(Object other) {
		      boolean eq = false;
		      Couple<T> rhs = null;
		      
		      if(this.getClass() == other.getClass()){
		         rhs = (Couple<T>) other;
		         eq = (this.first.equals(rhs.first) && this.second.equals(rhs.second));
		      }
		      return eq;
		   }

}
