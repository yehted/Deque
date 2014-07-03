#include <iterator>
#include <stdexcept>

template <class Item> class DequeIter;

template <class Item>
class Deque {
	friend class DequeIter < Item >;
public:
	Deque();								// Default constructor
	~Deque();								// Deconstructor
	Deque(const Deque &that);				// Copy constructor
	Deque &operator=(const Deque &that);	// Assignment operator *unfinished*
	bool isEmpty();							// Checks if deque is empty
	int size();								// Returns number of items in deque
	void addFirst(const Item &item);		// Adds an item to the beginning of the deque
	void addLast(const Item &item);			// Adds an item to the end of the deque
	Item removeFirst();						// Removes an item from the beginning of the deque
	Item removeLast();						// Removes an item from the end of the deque

private:
	struct Node {
		Item item;
		Node *next;
		Node *prev;
	};
	Node *first, *last;
	int N;	
};

template <class Item>
class DequeIter {
	typedef DequeIter<Item> iterator;

};

// Implementation

// Default constructor
template <class Item> Deque<Item>::Deque() : first(NULL), last(NULL), N(0) {

}

// Destructor
template <class Item> Deque<Item>::~Deque() {
	Node *current;
	while (first != NULL) {
		current = first;
		first = first->next;
		delete current;
	}
}

// Copy constructor
template <class Item> Deque<Item>::Deque(const Deque &that) : N(0), first(NULL), last(NULL) {
	//if (that.N == 0) return *this;

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
		cout << "Error!" << endl;
	
}

template <class Item> bool Deque<Item>::isEmpty() {
	return (N == 0);
}

template <class Item> int Deque<Item>::size() {
	return N;
}

template <class Item> void Deque<Item>::addFirst(const Item &item) {
	if (&item == NULL) { throw std::out_of_range("Null pointer exception"); }
	if (isEmpty()) {
		first = new Node;
		last = first;
		first->next = NULL;
	}
	else {
		Node *oldfirst = first;
		first = new Node;
		first->next = oldfirst;
		oldfirst->prev = first;
	}
	first->item = item;
	first->prev = NULL;
	N++;
}

template <class Item> void Deque<Item>::addLast(const Item &item) {
	if (&item == NULL) { throw std::out_of_range("Null pointer exception"); }
	if (isEmpty()) {
		last = new Node;
		first = last;
		last->prev = NULL;
	}
	else {
		Node *oldlast = last;
		last = new Node;
		last->prev = oldlast;
		oldlast->next = last;
	}
	last->item = item;
	last->next = NULL;
	N++;
}

template <class Item> Item Deque<Item>::removeFirst() {
	if (isEmpty()) { throw std::out_of_range("Stack underflow"); }
	Item t_item = first->item;
	Node *tmp = first->next;
	delete first;
	first = tmp;
	N--;
	if (N == 0) {
		last = NULL;
		return t_item;
	}
	first->prev = NULL;	
	return t_item;
}

template <class Item> Item Deque<Item>::removeLast() {
	if (isEmpty()) { throw std::out_of_range("Stack underflow"); }
	Item t_item = last->item;
	Node *tmp = last->prev;
	delete last;
	last = tmp;
	N--;
	if (N == 0) {
		first = NULL;
		return t_item;
	}
	last->next = NULL;
	return t_item;
}
