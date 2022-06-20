#ifndef _PROGRAMINTERFACE_HPP
#define _PROGRAMINTERFACE_HPP
#include <fstream>
#include "Container.h"
#include "Constants.h"
#include "LinkedStack.h"
#include "FilesInterface.h"
///class Program interface with a static function
class ProgramInterface
{
private:
public:
///deleted copy constructor
	ProgramInterface(ProgramInterface const& other) = delete;
	///deleted copy assignment
	ProgramInterface& operator=(ProgramInterface const& other) = delete;
	///static funciton for working with the program
	static void work();
};

#endif // !_PROGRAMINTERFACE_HPP

