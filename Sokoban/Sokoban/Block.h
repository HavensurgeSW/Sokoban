#ifndef BLOCK_H
#define BLOCK_H
#include "raylib.h"

namespace SB {
	
	struct Block {
		Rectangle rec;
		Texture2D tex;
		int posX;
		int posY;
		bool active;
	};

	extern Texture2D blockTex;

	extern Block block[6];

}
#endif
