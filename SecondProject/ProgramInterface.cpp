#include "ProgramInterface.h"


void ProgramInterface::work()
{
	Container container;
	FilesInterface files;
	MyString fileName;
	std::fstream file;
	bool isEnding = false;
	char buffer[BUFFER_LENGHT];
	do
	{
		for (unsigned i = 0; i < COMANDS; i++)
		{
			std::cout << i << ": ";
			for (unsigned j = 0; j < 2; j++)
			{
				std::cout << commandsArray[i][j];
				if (j == 0)
				{
					std::cout << "enter:\n";
				}
				else
				{
					std::cout << '\n';
				}
			}
		}
		std::cout << "To proceed enter a command of your choosing:";
		char command[BUFFER_LENGHT];
		std::cin >> command;
		if (strcmp(command, "help") == 0)
		{
			if (strcmp(command, "help") == 0)
			{
				for (unsigned i = 0; i < COMANDS; i++)
				{
					for (unsigned j = 2; j > 0; j--)
					{
						std::cout << commandsArray[i][j - 1] << "\n";
					}
					std::cout << '\n';
				}
			}
		}
		else if (strcmp(command, "close") == 0)
		{
			if (file.is_open())
			{
				file.close();
			}
		}
		else if (strcmp(command, "save") == 0)
		{
			files.writeToFile(file, container);
		}
		else if (strcmp(command, "exit") == 0)
		{
			isEnding = true;
		}
		else if (strcmp(command, "print") == 0)
		{
			container.print(std::cout);
		}
		else if (strcmp(command, "saveas") == 0)
		{
			std::cin >> command;
			std::fstream tempFile(command, std::ios::out);
			files.writeToFile(tempFile, container);
			tempFile.close();
		}
		else if (strcmp(command, "create") == 0)
		{
			std::cin >> command;
			if (strcmp(command, "rectangle") == 0)
			{
				try
				{
					float x;
					float y;
					MyString colour;
					MyString fill;
					float width;
					float height;
					float roundX;
					float roundY;
					std::cin >> x >> y >> colour >> fill
						>> width >> height >> roundX >> roundY;
					Point p(x, y);
					Rectangle rect(p, colour, fill, width, height, roundX, roundY);
					container.addShape(&rect);
				}
				catch (const std::exception& e)
				{
					std::cout << e.what();
				}
			}
			else if (strcmp(command, "circle") == 0)
			{
				try
				{
					float x;
					float y;
					float radius;
					MyString fill;
					std::cin >> x >> y >> radius >> fill;
					Point p(x, y);
					Circle circle(p, fill, radius);
					container.addShape(&circle);
				}
				catch (const std::exception& e)
				{
					std::cout << e.what();
				}
			}
			else  if (strcmp(command, "line") == 0)
			{
				try
				{
					float x1;
					float y1;
					float x2;
					float y2;
					unsigned strokeWidth;
					MyString stroke;
					std::cin >> x1 >> y1 >> x2 >> y2 >> stroke >> strokeWidth;
					Point A(x1, y1);
					Point B(x2, y2);
					Line line(A, B, stroke, strokeWidth);
					container.addShape(&line);
				}
				catch (const std::exception& e)
				{
					std::cout << e.what();
				}
			}
			else
			{
				std::cout << "Invalid data!";
			}
		}
		else if (strcmp(command, "open") == 0)
		{
			try
			{

				std::cin >> command;
				file.open(command, std::ios::in | std::ios::out);
				if (file.is_open())
				{
					files.readFromFile(file, container);
					std::cout << "File was successfully opened!";
				}
				else
				{
					std::cout << "File was not opened succesfully!";
				}
			}
			catch (const std::exception& e)
			{
				std::cout << e.what();
			}
		}
		else if (strcmp(command, "erase") == 0)
		{
			int number;
			std::cin >> number;
			container.eraseShape(number);
		}
		if (strcmp(command, "translate") == 0)
		{
			int vertical;
			int horizontal;
			char yesNoForNumber[10];
			std::cin >> vertical >> horizontal >> yesNoForNumber;
			if (strcmp(yesNoForNumber, "yes") == 0)
			{
				int number;
				std::cin >> number;
				container.translate(vertical, horizontal, number);
			}
			else
			{
				container.translate(vertical, horizontal);
			}

		}
		else if (strcmp(command, "within") == 0)
		{
			std::cin >> command;
			if (strcmp(command,"rectangle")==0)
			{
				try
				{
					float x;
					float y;
					float width;
					float height;
					MyString colour;
					MyString fill;
					std::cin >> x >> y >> width >> height >> colour >> fill;
					Point p(x, y);
					Rectangle region(p, colour, fill, width, height);
					container.withinRectangle(region);
				}
				catch (const std::exception& e)
				{
					std::cout << e.what();
				}
			}
			else if (strcmp(command, "circle") == 0)
			{
				float x;
				float y;
				float radius;
				MyString fill;
				std::cin >> x >> y >> radius >> fill;
				Point p(x, y);
				Circle region(p, fill, radius);
				container.withinCircle(region);
			}
		}
		std::cin.get();
		std::cin.get();
		system("CLS");

	} while (!isEnding);
}
