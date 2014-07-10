#include <stdexcept>
#include <iterator>
#include <time.h>

template <class T>
class RandomizedQueue{
public:
	class Iterator;

	RandomizedQueue();				// default constructor
	~RandomizedQueue();				// deconstructor
	RandomizedQueue(const RandomizedQueue &that);	// copy constructor
	RandomizedQueue &operator=(const RandomizedQueue &that);	// assignment operator
	bool isEmpty();					// checks if queue is empty
	int size();						// returns number of items in queue
	void enqueue(const T &item);	// adds an item to the queue
	T dequeue();					// randomly removes an item from queue
	T sample();						// returns a random item, but does not remove it
	Iterator begin();
	Iterator end();

	class Iterator : public std::iterator < std::forward_iterator_tag, T > {
	public:
		Iterator();
		~Iterator();
		Iterator(T* p);
		Iterator(const Iterator &other);
		Iterator &operator=(const Iterator &other);

		Iterator &operator++();
		Iterator operator++(int);
		bool operator==(const Iterator &other);
		bool operator!=(const Iterator &other);

		T& operator*();
		T* operator->();
		
	private:
		T *pos;
	};

private:
	T *a;						// queue stored in dynamically allocated array
	int N;							// number of items in queue
	int cap;						// capacity of the array
	void resize(int capacity);		// resizes the array
};

// Implementation

template <class T> RandomizedQueue<T>::RandomizedQueue() : N(0), cap(2) {
	srand((unsigned int)time(NULL));
	a = new T[2];
}

template <class T> RandomizedQueue<T>::~RandomizedQueue() {
	delete[] a;
}

template <class T> RandomizedQueue<T>::RandomizedQueue(const RandomizedQueue &that) : a(new T[that.N]),
N(that.N), cap(that.cap)
{
	for (int i = 0; i < that.N; i++)
		a[i] = that.a[i];
}

template <class T> RandomizedQueue<T> & RandomizedQueue<T>::operator=(const RandomizedQueue &that) {
	if (this == &that) return *this;

	// Deallocate old memory
	delete[] a;

	// Allocate new memory
	T *new_a = new T[that.N];

	// Copy elements
	for (int i = 0; i < that.N; i++)
		new_a[i] = that.a[i];

	// Assign new memory
	a = new_a;
	N = that.N;
	cap = that.cap;

	return *this;
}

template <class T> bool RandomizedQueue<T>::isEmpty() {
	return (N == 0);
}

template <class T> int RandomizedQueue<T>::size() {
	return N;
}

template <class T> void RandomizedQueue<T>::enqueue(const T &item) {
	if (&item == NULL) throw std::invalid_argument("Null pointer exception");
	if (N == cap) resize(2 * cap);
	a[N++] = item;
}

template <class T> void RandomizedQueue<T>::resize(int capacity) {
	T *new_a = new T[capacity];
	for (int i = 0; i < N; i++)
		new_a[i] = a[i];

	delete[] a;
	a = new_a;
	cap = capacity;
}

template <class T> T RandomizedQueue<T>::dequeue() {
	if (isEmpty()) throw std::underflow_error("Stack underflow");	// Check whats up with this line

	int x = rand() % N;
	T answer = a[x];
	
	a[x] = a[--N];
	

	if (N > 0 && N == cap / 4) resize(cap / 2);
	return answer;
}

template <class T> T RandomizedQueue<T>::sample() {
	if (isEmpty()) throw std::underflow_error("Stack underflow");

	int x = rand() % N;
	return a[x];
}

