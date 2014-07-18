#include "RandomizedQueue.h"
#include "Deque.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "vld.h"

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
	/*for (int i = 0; i < k; i++) {
		cout << RQ.dequeue() << endl;
	}*/
	cout << "Deque Iterator test" << endl;
	for (Deque<string>::Iterator iter = c_DQ.begin(); iter != c_DQ.end(); ++iter)
		cout << *iter << endl;
	cout << endl;
	cout << "Foreach test" << endl;
	for (string s : RQ)
		cout << s << " ";
	cout << endl;

	/*for (RandomizedQueue<string>::Iterator it = RQ.begin(); it != RQ.end(); ++it) {
		for (RandomizedQueue<string>::Iterator dit = RQ.begin(); dit != RQ.end(); ++dit)
			cout << *dit << " ";
		cout << endl;
		cout << "IT: " << *it << endl;
	}*/
	cout << endl;
	return 0;
}