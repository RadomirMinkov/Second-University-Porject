#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

const int COMANDS = 11;
const int BUFFER_LENGHT = 201;
const char MAX_STRING_LENGTH = 100;

const char commandsArray[COMANDS][2][MAX_STRING_LENGTH] = {
	{{"To see all the commands enter"}, {"help "}},
{{"To open a file "},{"open [length of the path] [file] "}},
{{"To close the file "},{"close "}},
{{"To save the file "},{"save "}},
{{"To save the file as a new file "},{"saveas [length of the path] [file] "}},
{{"To exit the program "},{ "exit "}},
{{"To print all the shapes "},{"print "}},
{{"To create new shape "},{"create [shape] [listing all the needed properties of the shape with an interval"}},
{ {"To delete the figure with number in the list "},{"erase [n]"} },
{{"To translate a shape with a number n or if it is not stated translates all the shapes "},{"translate {[n]} [vertical] [horizontal]"}},
{{"To see if a shape is in a cirlce or a rectangle "},{"within [shape] [listing all the needed properties of the shape with an interval]"}}
};
#endif // !CONSTANTS_HPP
