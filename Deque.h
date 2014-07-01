#include <iterator>

template <class Item>
class Deque {
public:
	Deque();
	bool isEmpty();
	int size();
	void addFirst(Item item);
	void addLast(Item item);
	Item removeFirst();
	Item removeLast();

private:
	struct Node {
		Item item;
		Node *next;
		Node *prev;
	};
	Node first, last;
	int N;
};