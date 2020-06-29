#include <iostream>
#include <mutex>
#include <memory>

template<typename T>
class CircularBuffer {
public:
	explicit CircularBuffer(size_t size)
		:_buff{std::unique_ptr<T[]>(new T[size])}, _max_size{size}{}

	bool push_back(const T& data);
	bool pop_back();
	bool pop_front();
	bool empty() const ;
	bool full() const ;
	size_t capacity() const ;
	size_t size() const;
	void reset();
	const T& operator[](size_t index) const;
	T& operator[](size_t index);
	

private:
	mutable std::mutex _mtx;
	std::unique_ptr<T[]> _buff;
	size_t _head = 0;
	size_t _tail = 0;
	size_t _max_size = 0;
	bool _full = false;
};

template<typename T>
inline 
bool CircularBuffer<T>::full() const{
	return _full;
}

template<typename T>
inline 
bool CircularBuffer<T>::empty() const{
	return (!_full &&(_head == _tail));
}

template<typename T>
inline 
size_t CircularBuffer<T>::capacity() const{
	return _max_size;
}

template<typename T>
inline 
size_t CircularBuffer<T>::size() const{
	std::lock_guard<std::mutex> _lck(_mtx);
	if(_full)
		return _max_size;
	else{
		if(_head >= _tail)
			return _head -_tail;
		else
			return _max_size - _tail +_head;
	}
}

template<typename T>
inline 
void  CircularBuffer<T>::reset(){
	std::lock_guard<std::mutex> _lck(_mtx);
	_head = _tail = 0;
	_full = false;
}





