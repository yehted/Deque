#include <iterator>

template <class Item>
class Deque {
public:
	Deque();
	~Deque();
	Deque(const Deque &that);
	Deque &operator=(const Deque &that);
	bool isEmpty();
	int size();
	void addFirst(const Item &item);
	void addLast(const Item &item);
	Item removeFirst();
	Item removeLast();

private:
	struct Node {
		Item item;
		Node *next;
		Node *prev;
	};
	Node *first, *last;
	int N;
};

// Implementation

template <class Item> Deque<Item>::Deque() : first(NULL), last(NULL), N(0) {

}

template <class Item> Deque<Item>::~Deque() {
	Node *current = first;
	Node *next_N;
	while (current != last) {
		next_N = current->next;
		delete current;
		current = next_N;
	}
	delete current;
}

template <class Item> Deque<Item>::Deque(const Deque &that) : N(that.N) {
	first = that->first;
	Node *tmp = first;
	while (tmp != last) {
		Node *current = new Node;
		current = tmp;
		tmp = tmp->next;
	}
	last = tmp;
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
	}
	else {
		Node *oldfirst = first;
		first = new Node;
		first->next = oldfirst;
		oldfirst->prev = first;
	}
	first->item = item;
	N++;
}

template <class Item> void Deque<Item>::addLast(const Item &item) {
	if (&item == NULL) { throw std::out_of_range("Null pointer exception"); }
	if (isEmpty()) {
		last = new Node;
		first = last;
	}
	else {
		Node *oldlast = last;
		last = new Node;
		last->prev = oldlast;
		oldlast->next = last;
	}
	last->item = item;
	N++;
}

template <class Item> Item Deque<Item>::removeFirst() {
	if (isEmpty()) { throw std::out_of_range("Stack underflow"); }
	Node *tmp = first->next;
	delete first;
	first = tmp;
	if (N > 1) first->prev = NULL;
	N--;
	return first->item;
}

template <class Item> Item Deque<Item>::removeLast() {
	if (isEmpty()) { throw std::out_of_range("Stack underflow"); }
	Node *tmp = last->prev;
	delete last;
	last = tmp;
	if (N > 1) last->next = NULL;
	N--;
	return last->item;
}
