#include "MyString.h"

MyString::MyString(MyString const& other)
	:data(nullptr)
{
	copy(other);
}

void MyString::deleteString()
{
	delete[] data;
}

MyString::~MyString()
{
	deleteString();
}

MyString::MyString(const char* _data)
	:data(nullptr),size(strlen(_data))
{
	data = new char[size+1];
	strcpy(data, _data);
}
MyString& MyString::operator=(MyString const& other)
{
	MyString copy{ other };
	std::swap(size, copy.size);
	std::swap(data, copy.data);
	return *this;
}
void MyString::copyNSymbols(const char* other,int& n)
{
	//deleteString();
	strncpy(data, other, n);
	data[n] = '\0';
	size = strlen(data);
}
void MyString::printString(std::ostream& out)const
{
	out << data;
}
void MyString::print(std::ostream& out) const
{
	out << "The string is: " << data << " with the length of " << size;
}
void MyString::println(std::ostream& out)const
{
	print(out);
	out << '\n';
}

void MyString::copy(MyString const& other)
{
	if (other.data==nullptr)
	{
		throw std::invalid_argument("There is no string to cpy from!");
		return;
	}
	size = other.size;
	deleteString();
	data = new char[size + 1];
	strcpy(data, other.data);
}

bool MyString::operator==(MyString const& other) const
{
	return  strcmp(data, other.data) == 0;
}

bool MyString::operator!=(MyString const& other) const
{
	return !(*this == other);
}

std::istream& operator>>(std::istream& in, MyString& other)
{
		/*if (&in==&std::cin)
		std::cout << "Enter the length of the string: ";*/
		in >> other.size;
		in.get();
		if (!std::cin.good())
			throw std::exception("Invalid data entered!");
		other.data = new char[other.size + 1];
		in.getline(other.data, other.size + 1);
			if (!std::cin.good())
				throw std::exception("Invalid data entered!");
	return in;
}

std::ostream& operator<<(std::ostream& out, MyString const& other)
{
	other.println(out);
	return out;
}
