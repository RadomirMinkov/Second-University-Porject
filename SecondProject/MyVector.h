#ifndef _MYVECTOR_HPP
#define _MYVECTOR_HPP
#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>
///templaten class MyVector which contains an array of elements
template <typename T>
class MyVector
{
	///private properties
private:
///the inital capacity of the vector
	static unsigned const INIT_CAPACITY = 2;
	///array of type T
	T* data{ nullptr };
	///size of the vector
	size_t size;
	///capacity of the vector
	unsigned capacity;
	//deletes the vector
	void clear();
	///copies the vector from another
	void copy(MyVector const& other);
	///expand the vector
	void expand();
	///public properties
public:
///default constructor
	MyVector();
	///copy constructor
	MyVector(MyVector const& other);
	///copy assignment
	MyVector& operator=(MyVector const& other);
	///destructor
	~MyVector();
	///returns the array
	const T* getData() const { return data; }
	///return size of the vector
	size_t getSize() const { return size; }
	///returns of the vector
	unsigned getCapacity() const { return capacity; }
	///add element to the vector
	void addElement(const T& element);
	///removes an element from the vector
	void removeElement(T const& element);
	///return the first element of the vector
	const T& front() const;
	///return the last element of the vector
	const T& back() const;
	//return an element with an index
	const T& operator[](int index)const;
	///return an element with an index
	T& operator[](int index);
	///returns if the vector is equal to another vector
	bool operator==(MyVector<T> const& other);
	///returns if the vector is ddiffernet to another vector
	bool operator!=(MyVector<T> const& other);
	///checks if the vector is empty
	bool isEmpty()const { return size == 0; }
	///prints the vector
	void print() const;
};

template <typename T>
void MyVector<T>::clear()
{
	delete[] data;
}
template <typename T>
void MyVector<T>::expand()
{
	capacity *= 2;
	T* newData = new T[capacity];
	for (unsigned i = 0; i < size; i++)
		newData[i] = data[i];
	delete[] data;
	data = newData;
}

template <typename T>
void MyVector<T>::copy(MyVector<T> const& other)
{
	capacity = other.capacity;
	size = other.size;
	T* newData = new T[capacity];
	for (unsigned i = 0; i < size; i++)
		newData[i] = other.data[i];
}

template <typename T>
MyVector<T>::~MyVector()
{
	clear();
}
template <typename T>
MyVector<T>::MyVector()
	:size(0), capacity(INIT_CAPACITY), data(nullptr)
{
	data = new T[capacity];
}

template <typename T>
MyVector<T>::MyVector(MyVector const& other)
	:data(nullptr)
{
	copy(other);
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T> const& other)
{
	MyVector copy(other);
	std::swap(capacity, other.capacity);
	std::swap(size, other.size);
	std::swap(data, other.data);
	return *this;
}
template <typename T>
const T& MyVector<T>::operator[](int index)const
{
	if (index < 0)
		throw std::out_of_range("Invalid index");
	return data[index];
}
template <typename T>
T& MyVector<T>::operator[](int index)
{
	if (index < 0)
		throw std::out_of_range("Invalid index!");
	return data[index];
}

template <typename T>
const T& MyVector<T>::front() const
{
	if (!isEmpty())
		//throw std::out_of_range("Empty stack!");
		return *(data);
}
template <typename T>
const T& MyVector<T>::back() const
{
	if (!isEmpty())
	//	throw std::out_of_range("Empty stack!");
	return *(data+size-1);
}

template <typename T>
bool MyVector<T>::operator==(MyVector<T> const& other)
{
	if (size != other.size)
		return false;
	for (unsigned i = 0; i < size; i++)
	{
		if (data[i] != other.data[i])
			return false;
	}
	return true;
}

template <typename T>
bool MyVector<T>::operator!=(MyVector<T> const& other)
{
	return !(*this == other);
}
template <typename T>
void MyVector<T>::addElement(T const& element)
{
	if (size == capacity)
		expand();
	data[size++] = element;
}

template <typename T>
void MyVector<T>::removeElement(T const& element)
{
	T *searched= std::find(data,data+size-1, element);
	std::rotate(searched, searched+1, data + size );
	size--;
}
template <typename T>
void MyVector<T>::print()const
{
	for (unsigned i = 0; i < size; i++)
		std::cout << data[i]<<' ';
}
#endif 

