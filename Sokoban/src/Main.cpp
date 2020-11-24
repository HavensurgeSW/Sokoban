#include "Mainframe.h"

void main() {
SB::Mainframe* game = new SB::Mainframe;
	game->init();
	game->mainLoop();

	delete game;	
}