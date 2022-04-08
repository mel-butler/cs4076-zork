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

public:
    Item (string description);
    ~Item();
	string getShortDescription();
    virtual string getLongDescription();
};

#endif /*ITEM_H_*/
