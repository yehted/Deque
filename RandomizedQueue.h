#include <stdexcept>
#include <time.h>

template <class Item>
class RandomizedQueue{
public:
	RandomizedQueue();				// default constructor
	~RandomizedQueue();				// deconstructor
	RandomizedQueue(const RandomizedQueue &that);	// copy constructor
	RandomizedQueue &operator=(const RandomizedQueue &that);	// assignment operator
	bool isEmpty();					// checks if queue is empty
	int size();						// returns number of items in queue
	void enqueue(const Item &item);	// adds an item to the queue
	Item dequeue();					// randomly removes an item from queue
	Item sample();					// returns a random item, but does not remove it

private:
	Item *a;						// queue stored in dynamically allocated array
	int N;							// number of items in queue
	int cap;						// capacity of the array
	void resize(int capacity);		// resizes the array
};

// Implementation

template <class Item> RandomizedQueue<Item>::RandomizedQueue() : N(0), cap(2) {
	srand((unsigned int)time(NULL));
	a = new Item[2];
}

template <class Item> RandomizedQueue<Item>::~RandomizedQueue() {
	delete[] a;
}

template <class Item> RandomizedQueue<Item>::RandomizedQueue(const RandomizedQueue &that) : a(new Item[that.N]),
N(that.N), cap(that.cap)
{
	for (int i = 0; i < that.N; i++)
		a[i] = that.a[i];
}

template <class Item> RandomizedQueue<Item> & RandomizedQueue<Item>::operator=(const RandomizedQueue &that) {
	if (this == &that) return *this;

	// Deallocate old memory
	delete[] a;

	// Allocate new memory
	Item *new_a = new Item[that.N];

	// Copy elements
	for (int i = 0; i < that.N; i++)
		new_a[i] = that.a[i];

	// Assign new memory
	a = new_a;
	N = that.N;
	cap = that.cap;

	return *this;
}

template <class Item> bool RandomizedQueue<Item>::isEmpty() {
	return (N == 0);
}

template <class Item> int RandomizedQueue<Item>::size() {
	return N;
}

template <class Item> void RandomizedQueue<Item>::enqueue(const Item &item) {
	if (&item == NULL) throw std::invalid_argument("Null pointer exception");
	if (N == cap) resize(2 * cap);
	a[N++] = item;
}

template <class Item> void RandomizedQueue<Item>::resize(int capacity) {
	Item *new_a = new Item[capacity];
	for (int i = 0; i < N; i++)
		new_a[i] = a[i];

	delete[] a;
	a = new_a;
	cap = capacity;
}

template <class Item> Item RandomizedQueue<Item>::dequeue() {
	if (isEmpty()) throw std::underflow_error("Stack underflow");	// Check whats up with this line

	int x = rand() % N;
	Item answer = a[x];
	N--;
	a[x] = a[N];
	

	if (N > 0 && N == cap / 4) resize(cap / 2);
	return answer;
}

template <class Item> Item RandomizedQueue<Item>::sample() {
	if (isEmpty()) throw std::underflow_error("Stack underflow");

	int x = rand() % N;
	return a[x];
}

