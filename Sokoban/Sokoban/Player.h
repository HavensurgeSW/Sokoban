#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "Tile.h"

namespace SB {
	struct Player {
		Rectangle rec;
		Texture2D tex;	
	};

	extern Player player;
	
	
	void initPlayer();
	void drawPlayer();
	void move();

}


#endif