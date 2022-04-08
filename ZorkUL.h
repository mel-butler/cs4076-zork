#ifndef ZORKUL_H_
#define ZORKUL_H_

#define INTRO "Welcome"

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "exception.h"
#include <iostream>
#include <string>

using namespace std;

class ZorkUL {

private:
    Parser parser;
    Room *currentRoom;
    void createRooms();

	bool processCommand(Command command);
	void printHelp();
    void goRoom(Command command);
    void openDoor(Command command);
    string go(string direction);
    void createItems();
    void displayItems();




public:
	ZorkUL();
	void play();
    void printWelcome();


    inline Room* getCurrentRoom() const
        {
            return currentRoom;
        }

        inline void setCurrentRoom(Room* r)
        {
            currentRoom = r;
        }


    friend class MainWindow;
};

#endif /*ZORKUL_H_*/
