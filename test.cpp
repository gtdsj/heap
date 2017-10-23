#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
	heap<int> h;
	h.push(20);
	h.push(30);
	h.push(90);
	h.push(40);
	h.push(70);
	h.push(110);
	h.push(60);
	h.push(10);
	h.push(100);
	h.push(50);
	h.push(80);

	while (!h.empty()) {
		cout << h.top() << endl;
		h.pop();
	}
	return 0;
}