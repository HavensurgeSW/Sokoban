#include "Block.h"

namespace SB {
	Block block[6];
	Texture2D blockTex;

	void loadBlockTextures() {
		blockTex = LoadTexture("../res/Block.png");
	}
	void initBlocks() {
		loadBlockTextures();
		for (int i = 0; i < 6; i++){
			block[i].rec.height = 40;
			block[i].rec.width = 40;
			block[i].rec.x = -40;
			block[i].rec.y = -40;
			block[i].tex = blockTex;
			block[i].posX = -1;
			block[i].posY = -1;
			block[i].active = false;
		}
	}

	void drawBlocks() {
		for (int i = 0; i < 6; i++){
			if (block[i].active){
				DrawTexture(block[i].tex, block[i].rec.x, block[i].rec.y, RAYWHITE);
			}
		}
	}
}