#include "FilesInterface.h"

void FilesInterface::readFromFile(std::fstream& in, Container& container)
{
	char* arr = new char[BUFFER_LENGHT];
	in.getline(arr, BUFFER_LENGHT);
	firstLine.copy(arr);
	in.getline(arr, BUFFER_LENGHT);
	secondLine.copy(arr);
	in.getline(arr, BUFFER_LENGHT);
	thirdLine.copy(arr);
	container.readFromText(in);
	delete[] arr;
}

void FilesInterface::writeToFile(std::fstream& out, Container const& container) const
{
	firstLine.println(out);
	secondLine.println(out);
	thirdLine.println(out);
	container.writeToText(out);
}