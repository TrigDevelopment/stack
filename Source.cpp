#include <iostream>
#include "stack.h"
stack<int> st;
void f1() {
	int a = 8;
	int b = 2;
	st.push(b);
	st.pop();
	st.push(a);
	/*st.push(a);
	st.push(b);
	st.push(a);*/ //example of error situation
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
