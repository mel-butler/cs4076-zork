#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
	string description;
    string longDescription;
    float value;

public:
    Item (string description);
    ~Item();
    Item (string description, float inValue);
	string getShortDescription();
    virtual string getLongDescription();

    template <typename T>
    void setValue(const T& value);

    float getValue();
};

#endif /*ITEM_H_*/
