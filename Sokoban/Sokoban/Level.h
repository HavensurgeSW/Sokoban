#ifndef LEVEL_H
#define LEVEL_H
#include "Tile.h"
#include "Player.h"
#include "Block.h"
namespace SB{

	//-----------
	//IDs:
	// 1- Left
	// 2- Down
	// 3- Right 
	// 4- Up
	// 5- Center
	//-----------

	void lvlOne();
	int lvlOneWincon(int &level);

	void lvlTwo();
	int lvlTwoWincon(int &level);

	void lvlThree();
	int lvlThreeWincon(int &level);

	void lvlFour();

	void lvlFive();
}
#endif