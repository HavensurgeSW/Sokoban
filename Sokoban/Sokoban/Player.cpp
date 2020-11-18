#include "Player.h"


namespace SB {
	Player player;

	void initPlayer(){
		player.rec.height = 40;
		player.rec.width = 40;
		player.rec.x = 0;
		player.rec.y = 0;
		player.tex = LoadTexture("../res/CloakGuy.png");
	}
	void drawPlayer() {
		DrawTexture(player.tex, player.rec.x, player.rec.y,RAYWHITE);
	}

	void move(){
		if (IsKeyPressed(KEY_D)||IsKeyPressed(KEY_RIGHT)){
			if (tile[][]){

			}
		}
	}
}