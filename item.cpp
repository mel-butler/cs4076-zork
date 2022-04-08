#include "item.h"
#include <sstream>


Item::Item(string inDescription) {
	description = inDescription;
}


Item::~Item(){

}


string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
    stringstream str;
    str<< "Item: " << getShortDescription();
    return str.str();
}

