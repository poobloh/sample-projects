/**
 *  Program 6
 *  Implementation of ArrayList class using generic types
 *  CS108-2
 *  18 November 2015
 *  @author Brandon Castro
 */

import java.io.IOException;
import java.util.Arrays;

public class ArrayList<T> implements ListT<T> {
	
	/** Data is stored in array of data T */
	private T[] data;
	
	/** Stores default size in static integer variable */
	private static final int DEFAULT_SIZE = 10;
	
	/** Stores size in integer variable */
	private int size;
	
	/**
	* Construct a new ArrayList with the supplied initial capacity.
	* @param capacity initial capacity of this ArrayList
	* @throws IllegalArgumentException if capacity is negative
    */
	ArrayList(int capacity) {
		if (capacity < 0)
			throw new IllegalArgumentException();
		size = capacity;
		data = (T[]) new Object[capacity];
	}
	
	/** Construct a new ArrayList with the default initial capacity */
	ArrayList() {
		this(DEFAULT_SIZE);
	}
	
	/** 
	 * Increases current array size by copying contents into a temporary one with size+1,
	 * then copying temp array back into our array.
	 * DOES NOT INCREASE SIZE VARIABLE, IMPLEMENT MANUALLY IF USING THIS METHOD
	 */
	void increaseCapacity() {
		T[] temp = (T[]) new Object[size+1];
		System.arraycopy(this.data, 0, temp, 0, size);
		this.data = temp;
	}
	
	
	/**
	 * Appends the specified element to the end of this list
	 * @param data
	 * @return boolean
	 */
	public boolean add(T data) {
		for(int i = 0; i<size; i++) {
			if(this.data[i] == null) {
				this.data[i] = data;
				break;
			}
			else if(i == size-1) {
				increaseCapacity();
				size++;
				this.data[size] = data;
				break;
			}
		}
		return true;
	}
	
	/**
	 * Inserts the specified element at the specified position in this list.
	 * Shifts the element currently at that position (if any) and any subsequent
	 * elements by adding one to their indices.
	 * @param index - index at which the specified element is to be inserted
	 * @param data - element to be inserted
	 * @return boolean
	 * @throws IndexOutOfBoundsException - if the index is out of range (index < 0 || index > size())
	 */
	 public boolean add(int index, T data) {
		if(index < 0 || index > size)
				throw new IndexOutOfBoundsException();
		if(this.data[index] == null) {
			this.data[index] = data;
			return true;
		 }
		 else {
			 T[] temp = (T[]) new Object[size+1];
			 System.arraycopy(this.data, 0, temp, 0, index);
			 temp[index] = data;
			 System.arraycopy(this.data, index, temp, index+1, size-index);
			 this.data = temp;
			 size++;
		 }
		 return true;
	}
	
	/** Removes all of the elements from this list */
	public void clear() {
		if(size > 0) {
			Arrays.fill(data, null);
		}
		size = 0;
	}
	
	/**
	 * Returns true if this list contains the specified element
	 * @param data
	 * @return boolean
	 */
	 @SuppressWarnings("unchecked")
	public boolean contains(T data) {
		return (indexOf(data)>=0);
	}
	
	/**
	 * Returns the element at the specified position in this list
	 * @param index
	 * @return E
	 */
	public T get(int index) {
		return data[index];
	}
	
	/**
	 * Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not
	 * contain the element
	 * @param data
	 * @return int
	 */
	public int indexOf(T data) {
		for(int i = 0; i < size; i++)
			if(data == this.data[i])
				return i;
		return -1;
	}
	
	/**
	 * Returns true if this list contains no elements
	 * @return boolean
	 */
	public boolean isEmpty() {
		return size == 0;
	}
	
	/**
	 * Removes the  element at the specified position in this list.
	 * Shifts any subsequent elements by subtracting one from their indices.
	 * @param index - index of the element to be removed
	 * @return E - the element that was removed from the list
	 * IndexOutOfBoundsException - if the index is out of range (index < 0 || index >= size())
	 */
	public T remove(int index) {
		T toRet = data[index];
		
		if(index != --size)
			System.arraycopy(data, index+1, data, index, size - index);
		// Garbage collector aid
		data[size] = null;
		return toRet;
	}
	
	/**
	 * Trims the capacity of this ArrayList instance to be the list's current size. An application can use this
	 * operation to minimize the storage of an ArrayList instance.
	 */
	public void trimToSize() {
		if (size < data.length)
            data = Arrays.copyOf(data, size);
	}
	
	/**
	 * Returns the number of elements in this list
	 * @return int
	 */
	 public int size() {
		return size;
	 }
	 
	 /**
	  * Prints each element in the array inside brackets
	  * Includes null elements for bug testing purposes
	  */
	 @Override
	 public String toString() {
		 String toRet = "";
		 for(T element : data)
			 toRet += "["+element+"] ";
		 return toRet;
	 }
}