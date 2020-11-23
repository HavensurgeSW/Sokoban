#include "Mainframe.h"

namespace SB {
	Mainframe::Mainframe() {
		_winWidth = 800;
		_winHeight = 450;
		_pause = false;
		_mainBool = true;
		screenID screenId;
		setScene(0);
		SetTargetFPS(60);
		_level = 0;
	}

	Mainframe::~Mainframe() {
		deInit();
	}
	void Mainframe::init() {

		InitWindow(_winWidth, _winHeight, "HSS - Sokoban");
		SetTargetFPS(60);
		setScene(0);
		SetExitKey(KEY_VOLUME_UP);
		InitAudioDevice();
		bgMusic = LoadMusicStream("../res/Wind.mp3");
		menubg = LoadTexture("../res/background.png");
		initTile();
		initPlayer();
		initBlocks();
		initUI();
	}
	void Mainframe::deInit() {
		CloseAudioDevice();
		CloseWindow();
	}
	void Mainframe::setScene(int scene) {
		switch (scene) {
		case 0:
			screenId = screenID::menu;
			break;
		case 1:
			screenId = screenID::game;
			break;
		case 2:
			screenId = screenID::options;
			break;
		}
	}

	void Mainframe::mainLoop() {

		while (!WindowShouldClose() && _mainBool) {
			switch (screenId) {
			case screenID::menu:
				menuScreen();
			case screenID::game:
				gameScreen();
			case screenID::options:
				optionsScreen();
			}
		}
	}

	void Mainframe::menuScreen() {
		Rectangle playButton;
		playButton.x = 20.0f;
		playButton.y = GetScreenHeight() / 2.0f;
		playButton.height = 30.0f;
		playButton.width = 65.0f;

		Rectangle creditsButton;
		creditsButton.x = 20.0f;
		creditsButton.y = (GetScreenHeight() / 2) + 100.0f;
		creditsButton.height = 30.0f;
		creditsButton.width = 113.0f;
		Rectangle closeButton;
		closeButton.x = 20.0f;
		closeButton.y = (GetScreenHeight() / 2) + 150.0f;
		closeButton.height = 30.0f;
		closeButton.width = 81.25f;


		PlayMusicStream(bgMusic);
		SetMusicVolume(bgMusic, 0.2f);


		while (!WindowShouldClose() && screenId == screenID::menu&&_mainBool) {

			UpdateMusicStream(bgMusic);

			BeginDrawing();
			ClearBackground(BLACK);

			DrawTexture(menubg,0,0,RAYWHITE);

			DrawText(FormatText("SOKOBAN"), 20, 10, 120, WHITE);

			if (CheckCollisionPointRec(GetMousePosition(), playButton))
				DrawText(FormatText("Play"), 20, GetScreenHeight() / 2, 30, RED);
			else
				DrawText(FormatText("Play"), 20, GetScreenHeight() / 2, 30, WHITE);


			if (CheckCollisionPointRec(GetMousePosition(), creditsButton))
				DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100, 30, RED);
			else
				DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100, 30, WHITE);

			if (CheckCollisionPointRec(GetMousePosition(), closeButton))
				DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150, 30, RED);
			else
				DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150, 30, WHITE);


			DrawText(FormatText("v 0.8"), GetScreenWidth() - 50, 1, 20, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), creditsButton)) {
				DrawText(FormatText("Engine: Raylib 3.0"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 3) + 20, 30, WHITE);
				DrawText(FormatText("Created by:"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 3) + 100, 30, WHITE);
				DrawText(FormatText("Matias P. Karplus"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 3) + 130, 30, WHITE);
			}
			EndDrawing();
			if (CheckCollisionPointRec(GetMousePosition(), closeButton) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
				exit(0);
			}
			if (CheckCollisionPointRec(GetMousePosition(), playButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
				setScene(1);
				_level = 1;

			}
		}
	}
	void Mainframe::gameScreen() {
		
		switch (_level) {
		case 1:
			lvlOne();
			break;
		case 2:
			lvlTwo();
			break;	
		case 3:
			lvlThree();
			break;
		case 4:
			lvlFour();
			break;
		}

		while (!WindowShouldClose() && screenId == screenID::game&&_mainBool) {

			UpdateMusicStream(bgMusic);
			if (!_pause) {
				input();
				update();
				collisions();
				draw();
			}
		
		}
	}
	void Mainframe::optionsScreen() {

	}
	void Mainframe::update() {
		switch (_level) {
		case 1:
			lvlOneWincon(_level);
			break;
		case 2:
			lvlTwoWincon(_level);
			break;
		case 3:
			lvlThreeWincon(_level);
			break;
		case 4:
			lvlFourWincon(_level);
			break;
		}

	}
	void Mainframe::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		drawTiles();
		drawPlayer();
		drawBlocks();
		drawUI();
		/*for (int i = 0; i < maxTLY; i++) {
			for (int j = 0; j < maxTLX; j++) {
				DrawRectangleRec(tile[i][j].rec, RED);
			}
		}*/
		EndDrawing();
	}
	void Mainframe::input() {
		movePlayer();

		if (CheckCollisionPointRec(GetMousePosition(), restartButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsKeyPressed(KEY_R)) {
			resetLevel();
		}

#if DEBUG
		//Util: Tile Coord finder
		for (int i = 0; i < maxTLY; i++) {
			for (int j = 0; j < maxTLX; j++) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), tile[i][j].rec)) {
					cout << "X:" <<i << endl <<"Y:"<< j << endl <<"ID:"<<tile[i][j].id <<endl <<"-----" << endl;
				}
			}
		}
#endif
	}
	void Mainframe::collisions() {
	}
	void Mainframe::resetLevel(){
			switch (_level) {
			case 1:
				lvlOne();
				break;
			case 2:
				lvlTwo();
				break;
			case 3:
				lvlThree();
			}

		
	}
}