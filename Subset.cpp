#include "RandomizedQueue.h"
#include "Deque.h"
#include <iostream>
#include <string>

using namespace std;

int main() {	
	int k;
	cout << "Number of items: ";
	cin >> k;
	RandomizedQueue<string> RQ;
	Deque<string> DQ;
	string item;
	for (int i = 0; i < k; i++) {
		cin >> item;
		RQ.enqueue(item);
		DQ.addFirst(item);
	}
	Deque<string> c_DQ = DQ;
	cout << "Deque" << "\t" << "RQ" << endl;
	for (int i = 0; i < k; i++) {
		cout << c_DQ.removeFirst() << "\t" << RQ.dequeue() << endl;
	}
	c_DQ.addLast("test");
	cout << DQ.removeLast() << endl;
	return 0;
}