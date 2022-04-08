#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <string>
using std::string;

// Struct containing dialogues and some printing functions.
struct Dialogue{
    static string printCurrentRoom(string& description);



};

namespace dialogue{
const static string welcome = "start\n"
                              "     info for help\n";
const static string inputError = "Invalid command, please try again\n";
const static string lockedRoom = "The lab\n"
                                 "Access to Stark, Anthony only. Please put on helmet and verify identity\n";
const string lockedRoomUnlocked = "Verification: Tony Stark, welcome home";
}

namespace wordle{
const string welcomeComputer = "Insert Password\n"
                               "hint: guess the correct five letter word\n";

const string passwordSuccess = "Welcome, STARK\n";

}

namespace RoomDialogue{
    const string lr_n = "you are facing the north wall of the living room\n"
                        "glass windows stretch along the wall from ceiling\n"
                        "to floor.\n"
                        "the sea stretches out in front of you, dark, dangerous.";
    const string lr_s = "you are facing the south wall of the living room\n"
                        "the tv is blaring quite loudly next to the sofa\n"
                        "                WORLD ON EDGE\n"
                        "              ------------------\n"
                        "            chaos reigns as city falls into\n"
                        "            disarray. who will save us now??";
    const string lr_e = "you are facing the east wall of the living room\n"
                        "there is a door in front of you, next to that awful plant";
    const string lr_w = "you are facing the west wall of the living room\n"
                        "there is a small waterfall installed into the wall\n"
                        "the water here is a huge contrast from the raging waters \n "
                        "outside\n"
                        "there is a door next to the waterfall";

    const string b_n="you are now facing the north wall of the bathroom\n"
                     "there is a mirror in front of you. when you look at your\n"
                     "reflection a tired man stares back. your\n"
                     " eyebags are far too prominent, \n"
                     "and your face far too weary. a multitude of bandages\n"
                     "and plasters cover your  face and body\n"
                     "would be nice to have something cover  your face. \n "
                     "you notice some sticky notes on the mirror\n"
                     "                 -------------------------\n"
                     "                |                        |\n"
                     "                |                        |\n"
                     "                |   you can change your  |\n"
                     "                |         legacy         |\n"
                     "                |   you can change the   |\n"
                     "                |          world         |\n"
                     "                |                        |\n"
                     "                 -------------------------\n";
    const string b_s="you are now facing the south wall of the bathroom\n"
                     "there is nothing here but the toilet and an open\n"
                     "first aid kit- oh wait! this is where you left that helmet";
    const string b_e="you are now facing the east wall of the bathroom\n"
                     "there's a bathtub, but i suppose now wouldn't\n"
                     "be prime bath time.";
    const string b_w="you are now in the bathroom\n"
                     "you are facing the west wall of the bathroom\n"
                     "there is a door in front of you, next to the fluffy\n"
                     "white towels";

    const string o_n="you are now facing the north wall of the office\n";
    const string o_s="you are now facing the south wall of the office\n";
    const string o_e="you are now facing the east wall of the office\n";
    const string o_w="you are now facing the west wall of the office\n";

    const string l_n="you are now facing the north wall of the lab\n";
    const string l_s="you are now facing the south wall of the lab\n";
    const string l_e="you are now facing the east wall of the lab\n";
    const string l_w="you are now facing the west wall of the lab\n";
}



/* namespace ItemDialogue{
    const string name = "text" ;

}
*/

namespace InteractionDialogue{
    const string inputError = "Invalid, please try again!";
}


/* namespace CompletionDialogues{
    const string task = "text";
}
*/

#endif // DIALOGUE_H
