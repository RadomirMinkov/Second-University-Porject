#ifndef _FILEINTERFACE_HPP
#define _FILEINTERFACE_HPP
#include <fstream>

#include "Types.h"
#include "Container.h"
#include "Constants.h"
#include "LinkedStack.h"
///class that controls the reading and writing with files
class FilesInterface
{
	///private properties
private:
///string that contains the first line of a file
	MyString firstLine;
	///string that contains the second line of a file
	MyString secondLine;
	///string that contains the third line of a file
	MyString thirdLine;
	///public properties
public:
///default constructor
	FilesInterface() = default;
	///deleted copy construcotr
	FilesInterface(FilesInterface const& other) = delete;
	///deleted copy assignment 
	FilesInterface& operator=(FilesInterface const& other) = delete;
	///reading from a text file
	void readFromFile(std::fstream& in, Container& container);
	///writing to a text file
	void writeToFile(std::fstream& out, Container const& container) const;
};

#endif // !_FILEINTERFACE_HPP


