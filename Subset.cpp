#include "RandomizedQueue.h"
#include "Deque.h"
#include <iostream>
#include <string>
#include <algorithm>

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
	Deque<string> c_DQ;
	c_DQ = DQ;
	
	cout << "Deque" << "\t" << "RQ" << endl;
	for (int i = 0; i < k; i++) {
		cout << RQ.dequeue() << endl;
	}
	typedef Deque<string> my_Deque;
	cout << "Iterator test" << endl;
	for (my_Deque::Iterator iter = DQ.begin(); iter != DQ.end(); ++iter)
		cout << *iter << endl;
	return 0;
}