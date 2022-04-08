
#include "ZorkUL.h"
#include "dialogue.h"
#include "Room.h"

#include <iostream>
#include <QApplication>

#include <QTextStream>
#include <QDebug>
#include <QLabel>

/*int main(int argc, char argv[]) {

    ZorkUL temp;
        temp.play();
        return 0;
}
*/

ZorkUL::ZorkUL() {
    createRooms();
}


void ZorkUL::createRooms()  {
    Room *lr_n, *lr_s, *lr_e, *lr_w, //living room
            *b_n, *b_s, *b_e, *b_w, // bathroom
            *o_n, *o_s, *o_e, *o_w, //office
            *l_n, *l_s, *l_e, *l_w; //lab

    lr_n = new Room(RoomDialogue::lr_n, false);
        lr_n->addImage(new Image(":/img/lr_n.png"));
    lr_s = new Room(RoomDialogue::lr_s, false);
        lr_s->addImage(new Image(":/img/b_e.png"));
        lr_s->addItem(new Item("leg_armour"));
    lr_e = new Room(RoomDialogue::lr_e, false);
        lr_e->addImage(new Image(":/img/door.png"));
    lr_w = new Room(RoomDialogue::lr_w, false);
        lr_w->addImage(new Image(":/img/b_e.png"));

    b_n = new Room(RoomDialogue::b_n, false);
        b_n->addImage(new Image(":/img/b_n.png"));
    b_s = new Room(RoomDialogue::b_s, false);
        b_s->addImage(new Image(":/img/b_e.png"));
        b_s->addItem(new Item("helmet"));
    b_e = new Room(RoomDialogue::b_e, false);
        b_e->addImage(new Image(":/img/b_e.png"));
    b_w = new Room(RoomDialogue::b_w, false);
        b_w->addImage(new Image(":/img/b_w.png"));

    o_n = new Room(RoomDialogue::o_n, false);
    o_s = new Room(RoomDialogue::o_s, false);
    o_e = new Room(RoomDialogue::o_e, false);
    o_w = new Room(RoomDialogue::o_w, false);
        o_w->addItem(new Item("arm_gauntlets"));

    l_n = new Room(RoomDialogue::l_n, false);
        o_w->addItem(new Item("chestplate"));
    l_s = new Room(RoomDialogue::l_s, true);
    l_e = new Room(RoomDialogue::l_e, false);
    l_w = new Room(RoomDialogue::l_w, false);





//             (N, E, S, W) // EAST IS ON THE RIGHT
    lr_n->setExits(NULL, lr_e, NULL, lr_w);
    lr_e->setExits(b_w, lr_s, NULL, lr_n);
    lr_s->setExits(NULL, lr_w, NULL, lr_e);
    lr_w->setExits(o_e, lr_n, NULL, lr_s);

    b_n->setExits(NULL, b_e, NULL, b_w);
    b_e->setExits(NULL, b_s, NULL, b_n);
    b_s->setExits(NULL, b_w, NULL, b_e);
    b_w->setExits(lr_e, b_n, NULL, b_s);

    o_n->setExits(l_s, o_e, NULL, o_w);
    o_e->setExits(lr_w, o_s, NULL, o_n);
    o_s->setExits(NULL, o_w, NULL, o_e);
    o_w->setExits(NULL, o_n, NULL, o_s);

    l_n->setExits(NULL, l_e, NULL, l_w);
    l_e->setExits(NULL, l_s, NULL, l_n);
    l_s->setExits(o_n, l_w, NULL, l_e);
    l_w->setExits(NULL, l_n, NULL, l_s);


        currentRoom = lr_n; // start in the living room, facing north
}


/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}



void ZorkUL::printWelcome() {
    cout << "start"<< endl;
    cout << "info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}
/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << " [???]   ---               ---    " << endl;
        cout << "                   |         " << endl;
        cout << "                   |         " << endl;
        cout << "[office] --- [living room] --- [bathroom]" << endl;
		}

    else if (commandWord.compare("turn") == 0)
		goRoom(command);
    else if (commandWord.compare("open") == 0)
        openDoor(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else {
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}



void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();
    if (direction == "door"){
        cout << "why are you trying to turn the door? fool." << endl;
    } else {
        // Try to leave current room.
        Room* nextRoom = currentRoom->nextRoom(direction);

        if (nextRoom == NULL)
            throw Exception();
        else {
            currentRoom = nextRoom;
            cout << currentRoom->longDescription() << endl;
        }
    }
}

void ZorkUL::openDoor(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();
    if (direction != "door"){
        cout << "you can only open doors >:(" << endl;
    } else {
        // Try to leave current room.
        Room* nextRoom = currentRoom->nextRoom(direction);

        if (nextRoom == NULL)
            throw Exception();
       // else if (nextRoom->getLocked() == true){
       //     cout << "this room is locked!" << endl;
       // }
    else {
            currentRoom = nextRoom;
            cout << currentRoom->longDescription() << endl;
        }
    }
}

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        throw Exception();
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}






