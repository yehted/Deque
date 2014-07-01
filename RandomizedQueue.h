#include <vector>

template <class Item>
class RandomizedQueue{
public:
	RandomizedQueue();
	bool isEmpty();
	int size();
	void enqueue(Item);
	void resize(int capacity);
	Item dequeue();
	Item sample();

private:
	std::vector<Item> a;
	int N;
};