#include "Level.h"


namespace SB {
	//-----------
	//IDs:
	// 1- Left
	// 2- Down
	// 3- Right 
	// 4- Up
	// 5- Center
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
				default:
					break;
				}
			}
		}
	}
	void cleanPrevLvl(){
		for (int i = 0; i < maxTLY; i++) {
			for (int j = 0; j < maxTLX; j++) {
				tile[i][j].id = 0;
				tile[i][j].tex = blank;
			}
		}
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


		player.posX = 3;
		player.posY = 5;
		player.rec.x = tile[3][5].rec.x;
		player.rec.y = tile[3][5].rec.y;

		

		assignTex();

	}
	void lvlTwo() {
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

		assignTex();
	}
	
}