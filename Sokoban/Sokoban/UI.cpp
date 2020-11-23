
#include "UI.h"

namespace SB {
	Rectangle restartButton;

	void initUI() {
		restartButton.x = 20.0f;
		restartButton.y = GetScreenHeight()- 50.0f;
		restartButton.height = 30.0f;
		restartButton.width = 150.0f;
	}

	void drawUI() {
		DrawRectangle(restartButton.x-2,restartButton.y-2, restartButton.width, restartButton.height,BLUE);
		DrawRectangleLines(restartButton.x - 2, restartButton.y - 2, restartButton.width, restartButton.height, WHITE);
		if (CheckCollisionPointRec(GetMousePosition(), restartButton))
			DrawText(FormatText("[R]estart"), 20, restartButton.y, 29, SKYBLUE);
		else
			DrawText(FormatText("[R]estart"), 20, restartButton.y, 29, WHITE);
	}


}

