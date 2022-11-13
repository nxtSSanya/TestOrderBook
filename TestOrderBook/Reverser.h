#pragma once
template <typename T>
class ReverseIterator {
public:
	ReverseIterator(T& container) : container(container)
	{}
	typename T::const_reverse_iterator begin() const {
		return container.crbegin();
	}
	typename T::const_reverse_iterator end() const {
		return container.crend();
	}
private:
	T& container;
};

template <typename T>
auto reverse(T& container) {
	return ReverseIterator<T>(container);
}