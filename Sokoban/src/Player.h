#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "Tile.h"
#include "Block.h"
#include <iostream>
using namespace std;

namespace SB {
	struct Player {
		Rectangle rec;
		Texture2D tex;
		int posX;
		int posY;
		Sound move;
	};

	extern Player player;
	
	
	void initPlayer();
	void drawPlayer();
	void movePlayer();

}


#endif