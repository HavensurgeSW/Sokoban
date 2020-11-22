#include "Player.h"


namespace SB {
	Player player;
	
	void initPlayer(){
		player.rec.height = 40;
		player.rec.width = 40;
		player.rec.x = 0;
		player.rec.y = 0;
		player.tex = LoadTexture("../res/CloakGuy.png");
		player.posX = 0;
		player.posY = 0;
	}
	void drawPlayer() {
		DrawTexture(player.tex, player.rec.x, player.rec.y,RAYWHITE);
	}

	void movePlayer(){
		bool canMove = true;
		if (IsKeyPressed(KEY_D)||IsKeyPressed(KEY_RIGHT)){
#if DEBUG
			cout << "Enter Key D" << endl;
			cout << player.posX << endl;
			cout << player.posY << endl;

#endif
				for (int i = 0; i < 6; i++){
					if (block[i].posY==player.posY+1&&block[i].posX==player.posX&& tile[player.posX][player.posY + 2].id == 6){
						block[i].rec.x = tile[player.posX][player.posY + 2].rec.x;
						block[i].rec.y = tile[player.posX][player.posY + 2].rec.y;
						block[i].posY++;
					}
				}
					if ((player.posY + 1 == block[0].posY&&player.posX==block[0].posX && tile[player.posX][player.posY+2].id!=6)&&canMove&&block[0].active||tile[player.posX][player.posY + 1].id != 6){
						canMove = false;
					}
					else {
						player.rec.x = tile[player.posX][player.posY + 1].rec.x;
						player.rec.y = tile[player.posX][player.posY + 1].rec.y;
						player.posY++;
						canMove = false;
					}

		}
		if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
#if DEBUG
			cout << "Enter Key A" << endl;
			cout << player.posX << endl;
			cout << player.posY << endl;
#endif
			

				for (int i = 0; i < 6; i++) {
					if (block[i].posY == player.posY - 1 &&block[i].posX == player.posX&& tile[player.posX][player.posY - 2].id == 6) {
						block[i].rec.x = tile[player.posX][player.posY-2].rec.x;
						block[i].rec.y = tile[player.posX][player.posY-2].rec.y;
						block[i].posY--;
					}
				}
					if ((player.posY - 1 == block[0].posY&&player.posX == block[0].posX && tile[player.posX][player.posY - 2].id != 6) && canMove&&block[0].active || tile[player.posX][player.posY - 1].id != 6) {
						canMove = false;
					}
					else {
						player.rec.x = tile[player.posX][player.posY - 1].rec.x;
						player.rec.y = tile[player.posX][player.posY - 1].rec.y;
						player.posY--;
						canMove = false;
					}
			
		}
		if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
#if DEBUG
			cout << "Enter Key W" << endl;
			cout << player.posX << endl;
			cout << player.posY << endl;
#endif
			if (tile[player.posX-1][player.posY].id == 6) {

				for (int i = 0; i < 6; i++) {
					if (block[i].posX == player.posX - 1 && block[i].posY == player.posY && tile[player.posX-2][player.posY].id == 6) {
						block[i].rec.x = tile[player.posX-2][player.posY].rec.x;
						block[i].rec.y = tile[player.posX-2][player.posY].rec.y;
						block[i].posX--;
					}
				}
					if ((player.posX - 1 == block[0].posX&&player.posY == block[0].posY && tile[player.posX-2][player.posY].id != 6) && canMove&&block[0].active || tile[player.posX-1][player.posY].id != 6) {
						canMove = false;
					}
					else {
						player.rec.x = tile[player.posX - 1][player.posY].rec.x;
						player.rec.y = tile[player.posX - 1][player.posY].rec.y;
						player.posX--;
						canMove = false;
					}

			}
		}
		if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
#if DEBUG
			cout << "Enter Key S" << endl;
			cout << player.posX << endl;
			cout << player.posY << endl;
#endif
			if (tile[player.posX+1][player.posY].id == 6) {

				for (int i = 0; i < 6; i++) {
					if (block[i].posX == player.posX + 1 && block[i].posY == player.posY && tile[player.posX + 2][player.posY].id == 6) {
						block[i].rec.x = tile[player.posX + 2][player.posY].rec.x;
						block[i].rec.y = tile[player.posX + 2][player.posY].rec.y;
						block[i].posX++;
					}
				}
				
					player.rec.x = tile[player.posX+1][player.posY].rec.x;
					player.rec.y = tile[player.posX+1][player.posY].rec.y;
					player.posX++;
	
			}
		}
	}
}