#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "raylib.h"
#include "Tile.h"
#include "Level.h"
#include "Player.h"
#include "Block.h"
#include "UI.h"
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
		int _framecounter;

	public:

		enum class screenID {
			menu,
			game,
			pause
		};
		screenID screenId;
		Texture2D menubg;
		Music bgMusic;
		Music gameMusic;
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

		void resetLevel();

		void pauseScreen();
		void pause();
		void unpause();


	};
}

#endif