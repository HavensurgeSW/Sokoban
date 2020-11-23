#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "raylib.h"
#include "Tile.h"
#include "Level.h"
#include "Player.h"
#include "Block.h"
#include <iostream>
using namespace std;


namespace SB {
	class Mainframe {
	private:
		int _winWidth;
		int _winHeight;
		bool _pause;
		bool _mainBool;
		int _level;

	public:

		enum class screenID {
			menu,
			game,
			options,
		};
		screenID screenId;
		Mainframe();
		~Mainframe();
		void init();
		void deInit();

		void setScene(int scene);
		void mainLoop();
		void menuScreen();
		void gameScreen();
		void optionsScreen();

		void update();
		void draw();
		void input();
		void collisions();


	};
}

#endif