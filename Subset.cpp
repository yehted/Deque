#include "RandomizedQueue.h"
#include "Deque.h"
#include <iostream>
#include <string>
#include <algorithm>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main() {	
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);


	int k;
	cout << "Number of items: ";
	cin >> k;
//	RandomizedQueue<string> RQ;
	Deque<string> DQ;
	string item;
	for (int i = 0; i < k; i++) {
		cin >> item;
//		RQ.enqueue(item);
		DQ.addFirst(item);
	}
	Deque<string> c_DQ;
	c_DQ = DQ;
	
	cout << "Deque" << "\t" << "RQ" << endl;
	//for (int i = 0; i < k; i++) {
	//	cout << RQ.dequeue() << endl;
	//}
	cout << "Iterator test" << endl;
	for (Deque<string>::Iterator iter = DQ.begin(); iter != DQ.end(); ++iter)
		cout << *iter << endl;
	cout << endl;
	/*for (RandomizedQueue<string>::Iterator it = RQ.begin(); it != RQ.end(); ++it)
		cout << *it << " ";
	cout << endl;*/
	_CrtDumpMemoryLeaks();
	return 0;
}