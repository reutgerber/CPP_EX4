//reutgerber@gmail.com
#include "node.hpp"
#include <vector>
#include <stack>
template<typename T>
class HeapIterator{
public:
	using pointer = T*;
	using reference = T&;

	HeapIterator(int index,vector<T>& min_heap)
	{
		this->min_heap = min_heap;
		this->currentIndex=index;
		
	
	}

	HeapIterator operator++()
	{
	
		advance();

		return *this;

	}
	HeapIterator operator++(int)
	{
		HeapIterator tmp = *this;
		advance();
		return tmp;
	}
	reference operator*()
	{
		return min_heap[currentIndex];

	}
	pointer operator->()
	{
		return &min_heap[currentIndex];
	}
	bool operator== (const HeapIterator& other)
	{
		return (other.currentIndex == this->currentIndex && this->min_heap == other.min_heap);
	}
	bool operator != (const HeapIterator& other)
	{
		return !(*this == other);

	}
private:
	vector<T> min_heap;
	int currentIndex;


	void advance()
	{
		currentIndex++;
	}
};

