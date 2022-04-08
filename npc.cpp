#include "npc.h"

NPC::NPC(string name, string description, bool status) : Character(name, description)
{
    this->status = false;
}

NPC::~NPC(){}


