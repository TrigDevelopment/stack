#include <iostream>
#include "stack.h"
stack<int> st;
void f1() {
	int a = 8;
	int b = 2;
	st.push(b);
	st.pop();
	st.push(a);
}
void outputStack() {
	while (st.count()) {
		std::cout << st.pop() << " ";
	}
}
int main() {
	f1();
	outputStack();
	system("pause");
	return 0;
}
