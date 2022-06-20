#include "Container.h"

size_t Container::shapesNumber() const
{
	return shapes.getSize();
}

Container::Container(MyVector<Shape*> _shapes)
	:shapes(_shapes) {}
void Container::addShape(const Shape* newShape)
{
	shapes.addElement(newShape->clone());
	std::cout << "Successfully added " << newShape->getShape();

}
void Container::eraseShape(unsigned number)
{
	if (number > shapesNumber())
		throw std::out_of_range("There aren't that many shapes in the container!");
	Shape* searchedShape= shapes[number - 1];
	std::cout << "Erased " << shapes[number - 1]->getShape() << " witn number " << number;
	shapes.removeElement(searchedShape);
		delete searchedShape;
}

void Container::print(std::ostream& out)const noexcept
{
	for (unsigned i = 0; i < shapesNumber(); i++) {
		out << i + 1 << ". ";
		shapes[i]->println(out);
	}
}
void Container::translate(int vertical, int horizontal, int number)const noexcept
{
	if (number <= 0)
	{
		for (unsigned i = 0; i < shapesNumber(); i++)
		{
			shapes[i]->translate(vertical, horizontal);
			
		}
		std::cout << "Translated all figures";
	}
	//nqmam vrreme da hvastam greshkata
	else if (number<shapes.getSize())
	{
		shapes[number - 1]->translate(vertical, horizontal);
		std::cout << "Translated " << shapes[number - 1]->getShape() << " with number" << number;
	}
	else
	{
		std::cout << "Invalid data!";
	}
}
void Container::withinCircle(Circle const& region) const noexcept
{
	for (unsigned i = 0; i < shapesNumber(); i++)
	{
		if (shapes[i]->withinCircle(region))
			shapes[i]->println();
	}
}
void Container::withinRectangle(Rectangle const& region)const noexcept
{
	for (unsigned i = 0; i < shapesNumber(); i++)
	{
		if (shapes[i]->withinRectangle(region))
			shapes[i]->println();
	}
}

void Container::readFromText(std::fstream& in)
{
	LinkedStack stack;
	char arr[BUFFER_LENGHT];
	in.getline(arr, BUFFER_LENGHT);
	stack.push(arr);
	while (!stack.isEmpty())
	{
		in.get();
		in >> arr;
		if (strcmp(arr, "rectangle") == 0)
		{
			Rectangle rect;
			rect.readFromText(in);
			shapes.addElement(&rect);
		}
		else if (strcmp(arr, "circle") == 0)
		{
			Circle circle;
			circle.readFromText(in);
			shapes.addElement(&circle);
		}
		else if (strcmp(arr, "line") == 0)
		{
			Line line;
			line.readFromText(in);
			shapes.addElement(&line);
		}
		else if(strcmp(arr,"/svg>")==0)
		{
			stack.pop();
		}
		else
		{
			std::cout << "Invalid data!";
		}
	}
}
void Container::writeToText(std::fstream& out)const
{
	out << "<svg>\n";
	for (unsigned i = 0; i < shapes.getSize(); i++)
	{
		shapes[i]->writeToText(out);
	}
	out << "</svg>";
}