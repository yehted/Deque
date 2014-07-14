#include <stdexcept>
#include <iterator>

template <class T>
class Deque {	
	class Node;

public:
	class Iterator;

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
	Iterator begin() { return Iterator(first); }
	Iterator end() { return Iterator(NULL); }

	class Iterator : public std::iterator < std::forward_iterator_tag, T >	{
	public:
		Iterator() : p_(NULL) {}			// Default constructor
		~Iterator() {}						// Destructor
		Iterator(Node* p) : p_(p) {}		// Single argument constructor
		Iterator(const Iterator &other) : p_(other.p_) {}	// Copy constructor
		Iterator &operator=(const Iterator &other) { p_ = other.p_; return *this; }	// Copy assignment operator

		Iterator &operator++()	{ p_ = p_->next; return *this; }	// prefix++
		Iterator operator++(int) { Node* previous = p_; p_ = p_->next; return Iterator(previous); }	// postfix++
		bool operator==(const Iterator &other) { return p_ == other.p_; }	// Equals operator
		bool operator!=(const Iterator &other) { return p_ != other.p_; }	// Not equals operator

		T &operator*(){ return p_->item; }	// Dereference
		T* operator->(){
			Iterator tmp = *this;
			T& value = *tmp;
			return (&value);
		}		

	private:
		Node* p_;
	};
	
private:
	class Node {	
	public:
		Node() : next(NULL), prev(NULL) {}
		Node(T item) : next(NULL), prev(NULL), item(item) {}
		T item;
		Node* next;
		Node* prev;		
	};

	Node *first, *last;
	int N;
};

// Implementation

// Default constructor
template <class T> Deque<T>::Deque() : first(NULL), last(NULL), N(0) {}

// Destructor
template <class T> Deque<T>::~Deque() {
	Node *current;
	while (first != NULL) {
		current = first;
		first = first->next;
		delete current;		
	}
}

// Copy constructor
template <class T> Deque<T>::Deque(const Deque &that) : N(0), first(NULL), last(NULL) {
	
	Node *current = that.first;	
	Node *t_prev = NULL;
	
	while (current != NULL) {
		Node *tmp = new Node;
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
	this->~Deque();
	// Creates copy
	Deque tmp(that);
	
	// Assigns elements
	first = tmp.first;
	last = tmp.last;
	N = tmp.N;

	// Deletes pointers to copy
//	tmp.first = NULL;
//	tmp.last = NULL;
//	tmp.N = 0;

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
	
	Node *newNode = new Node(item) ;
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

	Node *newNode = new Node(item) ;
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
	Node *tmp = first->next;
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
	Node *tmp = last->prev;
	delete last;
	last = tmp;
	N--;
	if (N == 0) 
		first = NULL;
	else
		last->next = NULL;
	return t_item;
}