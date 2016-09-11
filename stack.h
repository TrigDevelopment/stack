#pragma once

template <typename T>
class stack
{
public:
	stack() : array_(nullptr), array_size_(0), count_(0) {}
	size_t count() const;
	void push(T const &);
	T pop();
private:
	T* array_;
	size_t array_size_;
	size_t count_;
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
		T* new_array = new T(array_size_ + 1);
		
		for (size_t i = 0; i < array_size_; i++) {
			new_array[i] = std::move(array_[i]);
		}
		new_array[array_size_] = new_element;
		array_ = new_array;
		array_size_++;
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
