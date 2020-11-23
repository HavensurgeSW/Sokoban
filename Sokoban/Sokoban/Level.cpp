#include "Level.h"


namespace SB {
	//-----------
	//IDs:
	// 1- Left
	// 2- Down
	// 3- Right 
	// 4- Up
	// 5- Center
	// 6- Walkable
	// 7- Objective

	//Checklist:
	// CLEAN->ASSIGN BORDERS->ASSIGN WALKABLES->SET BLOCKS->SET WINCON->SET PLAYER SPAWN->ASSIGN TEXTURES
	//-----------

	void assignTex(){
		for (int i = 0; i < maxTLY; i++) {
			for (int j = 0; j < maxTLX; j++) {
				switch (tile[i][j].id){
				case 0:
					tile[i][j].tex = blank;
					break;
				case 1:
					tile[i][j].tex = left;
					break;
				case 2:
					tile[i][j].tex = down;
					break;
				case 3:
					tile[i][j].tex = right;
					break;
				case 4:
					tile[i][j].tex = up;
					break;
				case 5:
					tile[i][j].tex = center;
					break;
				case 6:
					tile[i][j].tex = blank;
					break;
				}
				if (tile[i][j].winSlot){
					tile[i][j].tex = objective;
				}
			}
		}
	}
	void cleanPrevLvl(){
		for (int i = 0; i < maxTLY; i++) {
			for (int j = 0; j < maxTLX; j++) {
				tile[i][j].id = 0;
				tile[i][j].tex = blank;
				tile[i][j].winSlot = false;
			}
		}

			initBlocks();
	}

	void lvlOne(){
		cleanPrevLvl();
		tile[1][12].id = 2;
		tile[2][5].id = 2 ;
		tile[2][6].id = 2 ;
		tile[2][7].id = 2 ;
		tile[2][8].id = 2 ;
		tile[2][9].id = 2 ;
		tile[2][10].id = 2;
		tile[2][11].id = 5;
		tile[2][13].id = 1;
		tile[3][4].id = 3 ;
		tile[3][13].id = 1;
		tile[4][5].id = 4 ;
		tile[4][6].id = 4 ;
		tile[4][7].id = 4 ;
		tile[4][8].id = 5;
		tile[4][10].id = 5;
		tile[4][11].id = 5;
		tile[4][13].id = 1;
		tile[5][8].id = 3 ;
		tile[5][13].id =1 ;
		tile[6][9].id =4  ;
		tile[6][10].id =4 ;
		tile[6][11].id =4 ;
		tile[6][12].id =4 ;

		tile[2][12].id = 6;
		tile[3][5].id = 6;
		tile[3][6].id = 6;
		tile[3][7].id = 6;
		tile[3][8].id = 6;
		tile[3][9].id = 6;
		tile[3][10].id = 6;
		tile[3][11].id = 6;
		tile[3][12].id = 6;
		tile[4][9].id = 6;
		tile[4][12].id = 6;
		tile[5][9].id = 6;
		tile[5][12].id = 6;
		tile[5][10].id = 6;
		tile[5][11].id = 6;
		tile[5][12].id = 6;

		tile[2][12].id = 6;
		tile[2][12].winSlot = true;
		

		block[0].active = true;
		block[0].posX = 3;
		block[0].posY = 9;
		block[0].rec.x = tile[3][9].rec.x;
		block[0].rec.y = tile[3][9].rec.y;

	/*	block[0].active = true;
		block[0].posX = 3;
		block[0].posY = 8;
		block[0].rec.x = tile[3][8].rec.x;
		block[0].rec.y = tile[3][8].rec.y;*/


		player.posX = 3;
		player.posY = 5;
		player.rec.x = tile[3][5].rec.x;
		player.rec.y = tile[3][5].rec.y;

		assignTex();

	}
	int lvlOneWincon(int &level) {
		for (int i = 0; i < maxTLY; i++) {
			for (int j = 0; j < maxTLX; j++) {
				
				if (tile[2][12].rec.x == block[0].rec.x&&tile[2][12].rec.y == block[0].rec.y) {
					cout << "Win!" << endl;
					level++;
					lvlTwo();
					return level;
			
				}
			}
		}
	}
	void lvlTwo() {
		cleanPrevLvl();
		tile[2][4].id = 5;
		tile[2][5].id = 2;
		tile[2][6].id = 2;
		tile[2][7].id = 2;
		tile[2][8].id = 5;
		tile[3][4].id = 3;
		tile[3][8].id = 5;
		tile[3][9].id = 2;
		tile[3][10].id = 2;
		tile[3][11].id = 5;
		tile[4][4].id = 3;
		tile[4][11].id = 1;
		tile[5][4].id = 5;
		tile[5][5].id = 4;
		tile[5][6].id = 4;
		tile[5][7].id = 4;
		tile[5][8].id = 4;
		tile[5][9].id = 4;
		tile[5][10].id = 4;
		tile[5][11].id = 5;


		tile[3][5].id = 6;
		tile[3][6].id = 6;
		tile[3][7].id = 6;
		tile[4][5].id = 6;
		tile[4][6].id = 6;
		tile[4][7].id = 6;
		tile[4][8].id = 6;
		tile[4][8].id = 6;
		tile[4][9].id = 6;

		tile[4][10].id = 6;
		tile[4][10].winSlot = true;


		block[0].active = true;
		block[0].posX = 4;
		block[0].posY = 7;
		block[0].rec.x = tile[4][7].rec.x;
		block[0].rec.y = tile[4][7].rec.y;


		player.posX = 4;
		player.posY = 9;
		player.rec.x = tile[4][9].rec.x;
		player.rec.y = tile[4][9].rec.y;
		assignTex();
		
	}
	int lvlTwoWincon(int &level){

		for (int i = 0; i < maxTLY; i++) {
			for (int j = 0; j < maxTLX; j++) {
				if (tile[4][10].rec.x == block[0].rec.x&&tile[4][10].rec.y == block[0].rec.y){
					cout << "Win!" << endl;
					level++;
					lvlThree();
					return level;
				}

			}
		}
	}

	void lvlThree(){
		cleanPrevLvl();
		tile[0][10].id = 2;
		tile[0][11].id = 2;
		tile[0][12].id = 2;
		tile[1][7] .id=  5;
		tile[1][8] .id= 2;
		tile[1][9] .id=  5;
		tile[1][13].id = 1;
		tile[2][7] .id=  3;
		tile[2][13].id = 1;
		tile[3][5] .id=  2;
		tile[3][6] .id=  2;
		tile[3][7] .id=  5;
		tile[3][10].id = 5;
		tile[3][13].id = 1;
		tile[4][4] .id=  3;
		tile[4][11].id = 5;
		tile[4][12].id = 4;
		tile[5][5] .id=  4;
		tile[5][6] .id=  5;
		tile[5][7] .id=  5;
		tile[5][11].id = 1;
		tile[6][6] .id=  3;
		tile[6][11].id = 1;
		tile[7][6] .id=  3;
		tile[7][10].id = 5;
		tile[8][7] .id=  4;
		tile[8][8] .id=  4;
		tile[8][9] .id=  4;

		tile[1][10].id = 6;
		tile[1][11].id = 6;
		tile[1][12].id = 6;
		tile[2][8].id = 6;
		tile[2][9].id = 6;
		tile[2][10].id = 6;
		tile[2][11].id = 6;
		tile[2][12].id = 6;
		tile[3][8].id = 6;
		tile[3][9].id = 6;
		tile[3][11].id = 6;
		tile[3][12].id = 6;
		tile[4][5].id = 6;
		tile[4][6].id = 6;
		tile[4][7].id = 6;
		tile[4][8].id = 6;
		tile[4][9].id = 6;
		tile[4][10].id = 6;
		tile[5][8].id = 6;
		tile[5][9].id = 6;
		tile[5][10].id = 6;
		tile[6][7].id = 6;
		tile[6][8].id = 6;
		tile[6][9].id = 6;
		tile[6][10].id = 6;
		tile[7][7].id = 6;
		tile[7][8].id = 6;
		tile[7][9].id = 6;
			   		 
		tile[1][12].winSlot = true;
		tile[2][12].winSlot = true;

		block[0].active = true;
		block[0].posX = 5;
		block[0].posY = 9;
		block[0].rec.x = tile[5][9].rec.x;
		block[0].rec.y = tile[5][9].rec.y;

		block[1].active = true;
		block[1].posX = 6;
		block[1].posY = 9;
		block[1].rec.x = tile[6][9].rec.x;
		block[1].rec.y = tile[6][9].rec.y;

		player.posX = 4;
		player.posY = 5;
		player.rec.x = tile[4][5].rec.x;
		player.rec.y = tile[4][5].rec.y;

		assignTex();
	}
	int lvlThreeWincon(int &level) {
		for (int i = 0; i < maxTLY; i++) {
			for (int j = 0; j < maxTLX; j++) {
				for (int k = 0; k < 2; k++){
					if (tile[1][11].rec.x == block[k].rec.x&&tile[1][11].rec.y == block[k].rec.y&&tile[1][11].winSlot&&
						tile[2][11].rec.x == block[k].rec.x&&tile[2][11].rec.y == block[k].rec.y&&tile[2][11].winSlot){

						level++;
						lvlFour();
						return level;
					}

				}

			}
		}
	}

	void lvlFour() {
		cleanPrevLvl();

		tile[1][6].id = 5;
		tile[1][7].id = 2;
		tile[1][8].id = 2;
		tile[1][9].id = 5;
		tile[2][6].id = 3;
		tile[2][9].id = 1;
		tile[3][6].id = 3;
		tile[3][9].id = 1;
		tile[4][6].id = 3;
		tile[4][9].id = 1;
		tile[5][2].id = 5;
		tile[5][3].id = 2;
		tile[5][4].id = 2;
		tile[5][5].id = 2;
		tile[5][6].id = 5;
		tile[5][9].id = 1;
		tile[6][2].id = 3;
		tile[6][9].id = 1;
		tile[7][2].id = 3;
		tile[7][9].id = 1;
		tile[8][2].id = 5;
		tile[8][3].id = 4;
		tile[8][4].id = 4;
		tile[8][5].id = 4;
		tile[8][6].id = 4;
		tile[8][7].id = 4;
		tile[8][8].id = 4;
		tile[8][9].id = 5;

		tile[2][7].id = 6;
		tile[2][8].id = 6;
		tile[3][7].id = 6;
		tile[3][8].id = 6;
		tile[4][7].id = 6;
		tile[4][8].id = 6;
		tile[5][7].id = 6;
		tile[5][8].id = 6;
		tile[6][3].id = 6;
		tile[6][4].id = 6;
		tile[6][5].id = 6;
		tile[6][6].id = 6;
		tile[6][7].id = 6;
		tile[6][8].id = 6;
		tile[7][3].id = 6;
		tile[7][4].id = 6;
		tile[7][5].id = 6;
		tile[7][6].id = 6;
		tile[7][7].id = 6;
		tile[7][8].id = 6;

		tile[7][5].winSlot = true;
		tile[4][8].winSlot = true;
		// CLEAN->ASSIGN BORDERS->ASSIGN WALKABLES->SET BLOCKS->SET WINCON->SET PLAYER SPAWN->ASSIGN TEXTURES

		block[0].active = true;
		block[0].posX = 5;
		block[0].posY = 7;
		block[0].rec.x = tile[5][7].rec.x;
		block[0].rec.y = tile[5][7].rec.y;

		block[1].active = true;
		block[1].posX = 7;
		block[1].posY = 4;
		block[1].rec.x = tile[7][4].rec.x;
		block[1].rec.y = tile[7][4].rec.y;


		player.posX = 3;
		player.posY = 7;
		player.rec.x = tile[3][7].rec.x;
		player.rec.y = tile[3][7].rec.y;

		assignTex();
	}
	


	void lvlFive(){
		cleanPrevLvl();

		tile[1][6].id = 2;
		tile[1][7].id = 2;
		tile[1][8].id = 2;
		tile[1][9].id =2 ;
		tile[2][5].id = 3;
		tile[2][10].id = 1;
		tile[3][4].id = 2;
		tile[3][5].id = 5;
		tile[3][10].id =1 ;
		tile[4][3].id = 5;
		tile[4][10].id =1 ;
		tile[5][3].id = 3;
		tile[5][9].id = 5;
		tile[6][4].id = 4;
		tile[6][5].id = 4;
		tile[6][6].id = 5;
		tile[6][9].id = 1;
		tile[7][7].id = 4;
		tile[7][8].id = 4;

		tile[2][6].id = 6;
		tile[2][7].id = 6;
		tile[2][8].id = 6;
		tile[2][9].id = 6;
		tile[3][6].id = 6;
		tile[3][7].id = 6;
		tile[3][8].id = 6;
		tile[3][9].id = 6;
		tile[4][4].id = 6;
		tile[4][5].id = 6;
		tile[4][6].id = 6;
		tile[4][7].id = 6;
		tile[4][8].id = 6;
		tile[4][9].id = 6; 
		tile[5][4].id = 6;
		tile[5][5].id = 6;
		tile[5][6].id = 6;
		tile[5][7].id = 6;
		tile[5][8].id = 6;
		tile[6][7].id = 6;
		tile[6][8].id = 6;

		tile[4][7].winSlot = true;
		tile[4][8].winSlot = true;
		tile[5][6].winSlot = true;
		tile[5][7].winSlot = true;
		tile[5][8].winSlot = true;

		block[0].active = true;
		block[0].posX = 3;
		block[0].posY = 6;
		block[0].rec.x = tile[3][6].rec.x;
		block[0].rec.y = tile[3][6].rec.y;

		block[1].active = true;
		block[1].posX = 3;
		block[1].posY = 7;
		block[1].rec.x = tile[3][7].rec.x;
		block[1].rec.y = tile[3][7].rec.y;

		block[2].active = true;
		block[2].posX = 3;
		block[2].posY = 8;
		block[2].rec.x = tile[3][8].rec.x;
		block[2].rec.y = tile[3][8].rec.y;

		block[3].active = true;
		block[3].posX = 4;
		block[3].posY = 6;
		block[3].rec.x = tile[4][6].rec.x;
		block[3].rec.y = tile[4][6].rec.y;

		block[4].active = true;
		block[4].posX = 5;
		block[4].posY = 5;
		block[4].rec.x = tile[5][5].rec.x;
		block[4].rec.y = tile[5][5].rec.y;


		player.posX = 4;
		player.posY = 4;
		player.rec.x = tile[4][4].rec.x;
		player.rec.y = tile[4][4].rec.y;
		assignTex();
	}
}