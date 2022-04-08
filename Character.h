#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <map>
#include <string>
#include <vector>
using namespace std;
using std::vector;


class Character {
protected:
	string description;
	 vector < string > itemsInCharacter;

public:
    void addItem(Item *item);
    void removeItem(Item *item);




public:
	Character(string description);
    Character(string name, string description);
	string shortDescription();
	string longDescription();

};

#endif //CHARACTER_H_
