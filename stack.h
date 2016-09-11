#pragma once

template <typename T>
class stack
{
public:
	stack() : array_(nullptr), array_size_(0), count_(0) {}
	size_t count() const;
	void push(T const &);
	T pop();
	~stack();
private:
	T* array_;
	size_t array_size_;
	size_t count_;
	void rereserve(size_t new_size, size_t n_elements_to_copy);
};

template<typename T>
size_t stack<T>::count() const
{
	return count_;
}

template<typename T>
void stack<T>::push(T const & new_element)
{
	if (count_ < array_size_) {
		array_[count_] = new_element;
		count_++;
	}
	else {
		rereserve((array_size_ * 3) / 2 + 1, count_);
		array_[count_] = new_element;
		count_++;
	}
}

template<typename T>
T stack<T>::pop()
{
	if (count_ == 0) {
		throw ("count_ == 0");
	}
	else {
		count_--;
	}
	return array_[count_];
}

template<typename T>
stack<T>::~stack()
{
	delete[] array_;
}

template<typename T>
void stack<T>::rereserve(size_t new_size, size_t n_elements_to_copy) {
	T* new_array = new T[new_size];

	for (size_t i = 0; i < n_elements_to_copy; i++) {
		new_array[i] = array_[i];
	}
	delete[] array_;
	array_ = new_array;
	array_size_ = new_size;
}
