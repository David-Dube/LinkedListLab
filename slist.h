/*

Header file for single linked list class library

*/

class Airport {
public:
  char code[5];
  double longitude;
  double latitude;

	double distance;

  bool operator==(Airport &other);
};

class node {
public:
  Airport *airport;
  node *next = nullptr;

	~node();
};

class linkedlist {
private:
  node *head = nullptr;
  node *tail = nullptr;

  int length;

public:
  ~linkedlist();

  // add(value)				//Adds a new value to the end of this
  // list.
  void add(Airport *value);

  // clear()					//Removes all elements from this
  // list.
  void clear();
  // equals(list)				//Returns true if the two lists contain
  // the same elements in the same order.
  bool equals(linkedlist *other);
  // get(index)				//Returns the element at the specified index
  // in this list.
  Airport *get(int index);

	node *get_node(int index);
  // insert(index, value)		//Inserts the element into this list before
  // the specified index.
  void insert(int index, Airport value);
  // exchg(index1, index2)		//Switches the payload data of specified
  // indexex.
  void exchg(int index1, int index2);
  // swap(index1,index2)		//Swaps node located at index1 with node
  // at index2
  void swap(int index1, int index2);
  // isEmpty()				//Returns true if this list contains no
  // elements.
  bool isEmpty();
  // mapAll(fn)				//Calls the specified function on each
  // element of the linkedlist in ascending index order.

  // remove(index)			//Removes the element at the specified index
  // from this list.
  void remove(int index);
  // set(index, value)		//Replaces the element at the specified index in
  // this list with a new value.
  void set(int index, Airport value);
  // size()					//Returns the number of elements in
  // this list.
  int size();
  // subList(start, length)	//Returns a new list containing elements from a
  // sub-range of this list.

  // toString()				//Converts the list to a printable
  // string representation.
};