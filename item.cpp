#include "item.h"
#include <sstream>


Item::Item(string inDescription) {
	description = inDescription;
}

Item::Item(string inDescription, float inValue=0) {
    description = inDescription;
    setValue(inValue);
}

Item::~Item(){

}

template <typename T>
void Item::setValue(const T& inValue)
{
       value = inValue;
}
template void Item::setValue<int>(const int&);
template void Item::setValue<float>(const float&);


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


float Item::getValue()
{
    return value;
}
