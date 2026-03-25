#include <stdexcept>

template<typename T>
Array<T>::Array(void) : _array(NULL), _size(0){}

template<typename T>
Array<T>::Array(unsigned int size) : _size(size){
	_array = new T[size];
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size) {
	_array = new T[_size];
	for (size_t i = 0; i < _size; i++)
			_array[i] = other._array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (&other == this)
		return *this;
	delete[] _array;
	_size = other._size;
	_array = new T[_size];
	for (size_t i = 0; i < _size; i++)
		_array[i] = other._array[i];
	return *this;
}

template<typename T>
Array<T>::~Array(void) {
	delete[] _array;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template<typename T>
unsigned int Array<T>::size(void) const {
	return _size;
}
