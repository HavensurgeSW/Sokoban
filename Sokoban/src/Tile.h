#ifndef TILE_H
#define TILE_H
#include "raylib.h"

namespace SB {

	//-----------
	//IDs:
	// 1- Left
	// 2- Down
	// 3- Right 
	// 4- Up
	// 5- Center
	// 6- Walkable
	//-----------

	struct Tile {
		Texture2D tex;
		Rectangle rec;
		int id;
		bool winSlot;
	};

	extern Texture2D left;
	extern Texture2D down;
	extern Texture2D right;
	extern Texture2D up;
	extern Texture2D center;
	extern Texture2D blank;
	extern Texture2D objective;


	const int maxTLX = 18;
	const int maxTLY = 9;
	extern Tile tile[maxTLY][maxTLX];

	void initTile();
	void drawTiles();
	
}


#endif
