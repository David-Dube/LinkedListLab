#include "slist.h"
#include <string>

/*
Class Library File
*/

bool Airport::operator==(Airport &other) {
	if (std::string(code) == std::string(other.code) &&
			longitude == other.longitude && latitude == other.latitude) {
		return true;
	} else {
		return false;
	}
}


node::~node() { delete airport; }


	// Destructor
linkedlist::~linkedlist() { clear(); }

	// add(value)				//Adds a new value to the end of this
	// list.
	void linkedlist::add(Airport *value) {
		node *temp = new node();
		temp->airport = value;

		if (length > 0) {
			tail->next = temp;
		} else {
			head = temp;
		}
		tail = temp;

		length++;
	}

	// clear()					//Removes all elements from this
	// list.
	void linkedlist::clear() {
		node *temp;
		while (true) {
			temp = head->next;
			delete head;
			head = temp;

			if (head == nullptr) {
				break;
			}
		}

		length = 0;
	}

	// equals(list)				//Returns true if the two lists
	// contain the same elements in the same order.
	bool linkedlist::equals(linkedlist *other) {
		if (length != other->length)
			return false;
		int i = 0;
		while (true) {
			if (!(*other->get(i) == *(this->get(i)))) {
				return false;
			}
		}

		return true;
	}

	// get(index)				//Returns the element at the specified
	// index in this list.
	Airport* linkedlist::get(int index) {
		node *n = this->head;
		for (int i = 0; i < index; i++) {
			n = n->next;
		}
		return n->airport;
	}

	node* linkedlist::get_node(int index) {
		node *n = this->head;
		for (int i = 0; i < index; i++) {
			n = n->next;
		}
		return n;
	}

	// insert(index, value)		//Inserts the element into this list
	// before the specified index.
	void linkedlist::insert(int index, Airport value) {
		node *n = new node();
		n->airport = &value;
		if (index == 0) {
			n->next = head;
			head = n;
		}

		node *current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}

		n->next = current->next;
		current->next = n;

		length++;
	}

	// exchg(index1, index2)		//Switches the payload data of specified
	// indexex.
	void linkedlist::exchg(int index1, int index2) {
		Airport *data1, *data2;
		data1 = get(index1);
		data2 = get(index2);

		Airport temp = *data1;
		*data1 = *data2;
		*data2 = temp;
	}

	// swap(index1,index2)		//Swaps node located at index1 with node
	// at index2
	void linkedlist::swap(int index1, int index2) {
		node *n1, *n2;
		n1 = get_node(index1);
		n2 = get_node(index2);
		Airport *temp = n1->airport;
		n1->airport = n2->airport;
		n2->airport = temp;
	}

	// isEmpty()				//Returns true if this list contains no
	// elements.
	bool linkedlist::isEmpty() {
		return length == 0;
	}

	// remove(index)			//Removes the element at the specified
	// index from this list.
	void linkedlist::remove(int index) {
		if (index == 0) {
			if (length == 1) {
				delete get_node(0);
				return;
			}
			node *n = get_node(1);
			delete head;
			head = n;
		} else {
			node *before = get_node(index - 1);
			if (get_node(index)->next == nullptr) {
				delete get_node(index);
				return;
			}
			node *after = get_node(index + 1);
			delete get_node(index);
			before->next = after;
		}

		length--;
	}

	// set(index, value)		//Replaces the element at the specified index in
	// this list with a new value.
	void linkedlist::set(int index, Airport value) {
		get_node(index)->airport = &value;
	}

	// size()					//Returns the number of elements
	// in this list.
	int linkedlist::size() {
		return length;
	}

	// DO NOT IMPLEMENT >>> subList(start, length)	//Returns a new list
	// containing elements from a sub-range of this list.

	// DO NOT IMPLEMENT >>> toString()				//Converts the
	// list to a printable string representation.
