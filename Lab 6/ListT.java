public interface ListT<E> {

	/**
	 * Appends the specified element to the end of this list
	 * @param data
	 * @return boolean
	 */
	boolean add(E data);

	/**
	 * Inserts the specified element at the specified position in this list.
	 * Shifts the element currently at that position (if any) and any subsequent
	 * elements by adding one to their indices.
	 * @param index - index at which the specified element is to be inserted
	 * @param data - element to be inserted
	 * @return boolean
	 * @throws IndexOutOfBoundsException - if the index is out of range (index < 0 || index > size())
	 */
	boolean add(int index, E data);
	
	/**
	 * Removes all of the elements from this list
	 */
	void clear();

	/**
	 * Returns true if this list contains the specified element
	 * @param data
	 * @return boolean
	 */
	boolean contains(E data);

	/**
	 * Returns the element at the specified position in this list
	 * @param index
	 * @return E
	 */
	E get(int index) throws Exception;

	/**
	 * Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not
	 * contain the element
	 * @param data
	 * @return int
	 */
	int indexOf(E data);

	/**
	 * Returns true if this list contains no elements
	 * @return boolean
	 */
	boolean isEmpty();

	/**
	 * Removes the  element at the specified position in this list.
	 * Shifts any subsequent elements by subtracting one from their indices.
	 * @param index - index of the element to be removed
	 * @return E - the element that was removed from the list
	 * IndexOutOfBoundsException - if the index is out of range (index < 0 || index >= size())
	 */
	E remove(int index);

	/**
	 * Trims the capacity of this ArrayList instance to be the list's current size. An application can use this
	 * operation to minimize the storage of an ArrayList instance.
	 */
	void trimToSize();

	/**
	 * Returns the number of elements in this list
	 * @return int
	 */
	int size();

}