/*#include "Character.h"
#include <vector>

Character::Character(string description) {
	this->description = description;
}

Character::Character(string name, string description){
    this->name = name;
    this->description = description;
}

string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getLongDescription() + "\n";
  return ret;
}

void Character::addItem(Item *item)
{
    itemsInCharacter.push_back(item);
}

void Character::removeItem(Item *item)
{
    for(int i=0; i< static_cast<int>(itemsInCharacter.size()); i++){
        if(itemsInCharacter.at(i) == item){
              itemsInCharacter.erase(itemsInCharacter.begin() + i);
        }
    }
}

*/
