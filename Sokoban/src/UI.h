#ifndef UI_H
#define UI_H
#include "raylib.h"

namespace SB {
	extern Rectangle restartButton;
	extern Rectangle gamePauseButton;

	void initUI();
	void drawUI();
}

#endif