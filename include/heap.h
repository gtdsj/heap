#ifndef __HEAP_H_PROTECTED__
#define __HEAP_H_PROTECTED__

#include <vector>
#include <algorithm>
template <typename T>
class heap
{
public:
	typedef std::vector<T> heap_t;
public:
	heap();
	virtual ~heap();

	void push(T data);
	void remove(T& data);
	const T& top();
	void pop();
	int size();
	bool empty();

protected:
	void head_up(int index);
	void head_down(int index);
protected:
	heap_t _heap;
};

template <typename T>
heap<T>::heap()
{
}

template <typename T>
heap<T>::~heap()
{
}

template <typename T>
void heap<T>::push(T data)
{
	_heap.push_back(data);
	int last = _heap.size() - 1;
	head_up(last);
}

template <typename T>
void heap<T>::remove(T& data)
{

}

template <typename T>
const T& heap<T>::top()
{
	return _heap[0];
}

template <typename T>
void heap<T>::pop()
{
	if (_heap.size() == 0) {
		return;
	}
	int size = _heap.size();
	std::swap(_heap[0], _heap[size - 1]);
	_heap.resize(size - 1);
	head_down(0);
	
}

template <typename T>
int heap<T>::size()
{
	return _heap.size();
}

template <typename T>
void heap<T>::head_up(int index)
{
	if (index >= (int)_heap.size()) {
		return;
	}
	int cur = index;
	int parent = cur;
	while (cur > 0) {
		parent = (cur - 1) / 2;
		if (_heap[cur] > _heap[parent]) {
			std::swap(_heap[parent], _heap[cur]);
		}else {
			break;
		}
		cur = parent;
	}
}

template <typename T>
void heap<T>::head_down(int index)
{
	if (index < (int)_heap.size()) {
		int cur = index, child = cur * 2 + 1;
		while (child < (int)_heap.size()){
			if (child + 1 < (int)_heap.size() && _heap[child] < (int)_heap[child + 1]) {
				child += 1;
			}
			if (_heap[child] > _heap[cur]) {
				std::swap(_heap[child], _heap[cur]);
				cur = child;
				child = cur * 2 + 1;
			}else {
				break;
			}
		}
		
	}
}

template <typename T>
bool heap<T>::empty()
{
	return _heap.empty();
}
#endif
