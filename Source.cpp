#include <iostream>
#include "stack.h"
stack<int> st;
template <typename T>
void outputStack(stack<T> _stack) {
	while (_stack.count()) {
		std::cout << _stack.pop() << " ";
	}
}
void f1() {
	int a = 8;
	int b = 2;
	st.push(1);
	st.push(2);
	stack<int> st2;
	st2.push(8);
	st2 = st;
	outputStack(st2);
}

int main() {
	f1();
	outputStack(st);
	system("pause");
	return 0;
}
