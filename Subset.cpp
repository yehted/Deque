#include "RandomizedQueue.h"
#include <iostream>
#include <string>

using namespace std;

int main() {	
	int k;
	cin >> k;
	RandomizedQueue<string> RQ;
	string item;
	for (int i = 0; i < k; i++) {
		cin >> item;
		RQ.enqueue(item);
	}
	for (int i = 0; i < k;) {
		cout << RQ.dequeue() << " " << endl;
	}		
	return 0;
}