#include <stdexcept>
#include <iterator>

template <class T> 
class Node {	
public:
	T item;
	Node *next;
	Node *prev;
	Node();				// Empty constructor
	Node(T item);	// Constructor
};

template <class T>
class Iterator : public std::iterator < std::forward_iterator_tag, T > {
public:
	Iterator(Node<T> *p);
	

private:
	Node<T> *current;
};

template <class T>
class Deque {	
public:
	Deque();								// Default constructor
	~Deque();								// Deconstructor
	Deque(const Deque &that);				// Copy constructor
	Deque &operator=(const Deque &that);	// Assignment operator
	bool isEmpty();							// Checks if deque is empty
	int size();								// Returns number of items in deque
	void addFirst(const T &item);			// Adds an item to the beginning of the deque
	void addLast(const T &item);			// Adds an item to the end of the deque
	T removeFirst();						// Removes an item from the beginning of the deque
	T removeLast();							// Removes an item from the end of the deque
	Iterator<T> begin();						// Returns iterator at beginning of deque
	Iterator<T> end();							// Returns iterator at end of deque	
	
private:	
	Node<T> *first, *last;
	int N;
};

// Implementation

// Empty Node constructor
template <class T> Node<T>::Node() : next(NULL), prev(NULL) {

}

// Node constructor
template <class T> Node<T>::Node(T item) : next(NULL), prev(NULL) {
	this->item = item;
}

// Default constructor
template <class T> Deque<T>::Deque() : first(NULL), last(NULL), N(0) {
	
}

// Destructor
template <class T> Deque<T>::~Deque() {
	Node<T> *current;
	while (first != NULL) {
		current = first;
		first = first->next;
		delete current;
	}
}

// Copy constructor
template <class T> Deque<T>::Deque(const Deque &that) : N(0), first(NULL), last(NULL) {
	
	Node<T> *current = that.first;	
	Node<T> *t_prev = NULL;
	
	while (current != NULL) {
		Node<T> *tmp = new Node<T>;
		if (N == 0) first = tmp;
		
		tmp->item = current->item;
		tmp->prev = t_prev;
		if (t_prev != NULL) t_prev->next = tmp;
			
		t_prev = tmp;
		current = current->next;
		N++;
	}
	last = t_prev;
	if (t_prev != NULL) t_prev->next = NULL;
	if (N != that.N)
		cerr << "Error, copy constructor did not work!" << endl;
	
}

// Copy assignment operator
template <class T> Deque<T> & Deque<T>::operator=(const Deque &that) {
	if (this == &that) return *this;
	
	// Creates copy
	Deque<T> tmp(that);
	
	// Assigns elements
	first = tmp.first;
	last = tmp.last;
	N = tmp.N;

	// Deletes pointers to copy
	tmp.first = NULL;
	tmp.last = NULL;
	tmp.N = 0;

	return *this;
}

template <class T> bool Deque<T>::isEmpty() {
	return (N == 0);
}

template <class T> int Deque<T>::size() {
	return N;
}

template <class T> void Deque<T>::addFirst(const T &item) {
	if (&item == NULL) { throw std::out_of_range("Null pointer exception"); }
	
	Node<T> *newNode = new Node < T >(item) ;	
	newNode->next = first;	
	if (!isEmpty())
		first->prev = newNode;
	else
		last = newNode;
	first = newNode;
	N++;
}

template <class T> void Deque<T>::addLast(const T &item) {
	if (&item == NULL) { throw std::out_of_range("Null pointer exception"); }

	Node<T> *newNode = new Node < T >(item) ;
	newNode->prev = last;	
	if (!isEmpty())
		last->next = newNode;
	else
		first = newNode;
	last = newNode;
	N++;	
}

template <class T> T Deque<T>::removeFirst() {
	if (isEmpty()) { throw std::out_of_range("Stack underflow"); }
	T t_item = first->item;
	Node<T> *tmp = first->next;
	delete first;
	first = tmp;
	N--;
	if (isEmpty()) 
		last = NULL;
	else	
		first->prev = NULL;	
	return t_item;
}

template <class T> T Deque<T>::removeLast() {
	if (isEmpty()) { throw std::out_of_range("Stack underflow"); }
	T t_item = last->item;
	Node<T> *tmp = last->prev;
	delete last;
	last = tmp;
	N--;
	if (N == 0) 
		first = NULL;
	else
		last->next = NULL;
	return t_item;
}

template <class T> Iterator<T>::Iterator(Node<T> *p) : current(p) {

}

template <class T> Iterator<T> Deque<T>::begin() {
	return Iterator<T>(first);
}

template <class T> Iterator<T> Deque<T>::end() {
	return Iterator<T>(last->next);
}