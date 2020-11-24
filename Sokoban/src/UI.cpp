
#include "UI.h"

namespace SB {
	Rectangle restartButton;
	Rectangle gamePauseButton;

	void initUI() {
		restartButton.x = 20.0f;
		restartButton.y = GetScreenHeight()- 50.0f;
		restartButton.height = 30.0f;
		restartButton.width = 150.0f;

		gamePauseButton.x = 220.0f;
		gamePauseButton.y = GetScreenHeight() - 50.0f;
		gamePauseButton.height = 30.0f;
		gamePauseButton.width = 114.0f;
	}

	void drawUI() {
		DrawRectangle(restartButton.x-2,restartButton.y-2, restartButton.width, restartButton.height,BLUE);
		DrawRectangleLines(restartButton.x - 2, restartButton.y - 2, restartButton.width, restartButton.height, WHITE);
		if (CheckCollisionPointRec(GetMousePosition(), restartButton))
			DrawText(FormatText("[R]estart"), 20, restartButton.y, 29, SKYBLUE);
		else
			DrawText(FormatText("[R]estart"), 20, restartButton.y, 29, WHITE);

		DrawRectangle(gamePauseButton.x - 2, gamePauseButton.y - 2, gamePauseButton.width, gamePauseButton.height, BLUE);
		DrawRectangleLines(gamePauseButton.x - 2, gamePauseButton.y - 2, gamePauseButton.width, gamePauseButton.height, WHITE);
		if (CheckCollisionPointRec(GetMousePosition(), gamePauseButton))
			DrawText(FormatText("[P]ause"), gamePauseButton.x, gamePauseButton.y, 29, SKYBLUE);
		else
			DrawText(FormatText("[P]ause"), gamePauseButton.x, gamePauseButton.y, 29, WHITE);
	}


}

