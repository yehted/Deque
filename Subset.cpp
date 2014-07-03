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
	cout << "Deque" << "\t" << "RQ" << endl;
	for (int i = 0; i < k; i++) {
		cout << DQ.removeLast() << "\t" << RQ.dequeue() << endl;
	}		
	return 0;
}