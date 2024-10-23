#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) 
{
    bool foundSpellbook = false;
    bool foundPotion = false;
    bool foundWand = false;
    MazeCell* currentCell = start;
    
    if(currentCell->whatsHere == Item::SPELLBOOK) foundSpellbook = true;
    else if(currentCell->whatsHere == Item::POTION) foundPotion = true;
    else if(currentCell->whatsHere == Item::WAND) foundWand = true;
    
    for(int i = 0; i < moves.size(); i++)
    {
        
        if(moves[i] == 'N') currentCell = currentCell->north;
        else if(moves[i] == 'S') currentCell = currentCell->south;
        else if(moves[i] == 'E') currentCell = currentCell->east;
        else currentCell = currentCell->west;

	if(currentCell == nullptr) {
            return false;
        }

        if(currentCell->whatsHere == Item::SPELLBOOK) foundSpellbook = true;
        else if(currentCell->whatsHere == Item::POTION) foundPotion = true;
        else if(currentCell->whatsHere == Item::WAND) foundWand = true;
    }
    
    return foundWand && foundPotion && foundSpellbook;
}
