#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "image.h"

using namespace std;
using std::vector;

class Room {

private:
	string description;
    bool locked;
    map<string, Room*> exits;
    vector <Item> itemsInRoom;
    vector <Image*> images;
    void addImage(Image *img);
    string exitString();


public:
    int numberOfItems();
    Room(string description, bool locked);
    void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);

    void setLocked(bool newLocked);
    bool getLocked();

    inline vector<Image*> getImages()
        {
            return images;
        }
    friend class ZorkUL;
};

#endif
