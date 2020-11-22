#include "Tile.h"

namespace SB {
	/*
	for (int i = 0; i < maxTLY; i++) {
			for (int j = 0; j < maxTLX; j++) {
				
			}
		}
	
	*/
	Tile tile[maxTLY][maxTLX];
	Texture2D left;
	Texture2D down;
	Texture2D right;
	Texture2D up;
	Texture2D center;
	Texture2D blank;
	Texture2D objective;

	void loadTileTextures() {
		left = LoadTexture("../res/Left.png");
		down =  LoadTexture("../res/Down.png");
		right = LoadTexture("../res/Right.png");
		up = LoadTexture("../res/Up.png");
		center = LoadTexture("../res/Center.png");
		blank = LoadTexture("../res/Blank.png");
		objective = LoadTexture("../res/WinSlot.png");

	}

	void initTile() {
		for (int i = 0; i < maxTLY; i++){
			for (int j = 0; j < maxTLX; j++){
				tile[i][j].rec.height = 40;
				tile[i][j].rec.width = 40;
				tile[i][j].rec.x = 40 + 40 * j;
				tile[i][j].rec.y = 25 + 40 * i;
			}
		}

		loadTileTextures();
	}

	void drawTiles() {
		for (int i = 0; i < maxTLY; i++) {
			for (int j = 0; j < maxTLX; j++) {
				DrawTexture(tile[i][j].tex,tile[i][j].rec.x, tile[i][j].rec.y,RAYWHITE);
			}
		}
	}

	
}