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
		_framecounter = 0;
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
		gameMusic = LoadMusicStream("../res/Drip.mp3");
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
			screenId = screenID::pause;
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
			case screenID::pause:
				pauseScreen();
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

			DrawText(FormatText("SOKOBAN"), 20, 10, 120, SKYBLUE);

			if (CheckCollisionPointRec(GetMousePosition(), playButton))
				DrawText(FormatText("Play"), 20, GetScreenHeight() / 2, 30, SKYBLUE);
			else
				DrawText(FormatText("Play"), 20, GetScreenHeight() / 2, 30, WHITE);


			if (CheckCollisionPointRec(GetMousePosition(), creditsButton))
				DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100, 30, SKYBLUE);
			else
				DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100, 30, WHITE);

			if (CheckCollisionPointRec(GetMousePosition(), closeButton))
				DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150, 30, BLUE);
			else
				DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150, 30, WHITE);


			DrawText(FormatText("v 1.0"), GetScreenWidth() - 50, 1, 20, WHITE);
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
		case 5:
			lvlFive();
			break;
		}

		PlayMusicStream(gameMusic);
		SetMusicVolume(gameMusic, 0.5f);
		SetMusicVolume(bgMusic,0.1f);

		while (!WindowShouldClose() && screenId == screenID::game||screenId==screenID::pause) {

			UpdateMusicStream(bgMusic);
			UpdateMusicStream(gameMusic);
			if (screenId == screenID::game) {
				input();
				update();
				collisions();
				draw();
			}
			if (screenId == screenID::pause){
				pauseScreen();
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
		case 5:
			lvlFiveWincon(_level);
			if (_level==6){
				setScene(0);
			}
		}

		if (_framecounter < 6) {
			_framecounter++;
		}

		if (_framecounter > 5) {
			pause();
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
				break;
			case 4:
				lvlFour();
				break;
			case 5:
				lvlFive();
				break;
			}

		
	}

	void Mainframe::pauseScreen() {
		Rectangle resumeButton;
		resumeButton.x = 20.0f;
		resumeButton.y = (GetScreenHeight() / 2) + 150.0f;
		resumeButton.height = 30.0f;
		resumeButton.width = 113.75f;
		Rectangle menuButton;
		menuButton.x = 220.0f;
		menuButton.y = (GetScreenHeight() / 2) + 150.0f;
		menuButton.height = 30.0f;
		menuButton.width = 65.0f;


		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(menubg, 0, 0, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), resumeButton))
			DrawText(FormatText("Resume"), resumeButton.x, (GetScreenHeight() / 2.0f) + 150.0f, 30.0f, SKYBLUE);
		else
			DrawText(FormatText("Resume"),resumeButton.x, (GetScreenHeight() / 2.0f) + 150.0f, 30.0f, WHITE);



		if (CheckCollisionPointRec(GetMousePosition(), menuButton))
			DrawText(FormatText("Menu"), menuButton.x, (GetScreenHeight() / 2) + 150.0f, 30, SKYBLUE);
		else
			DrawText(FormatText("Menu"), menuButton.x, (GetScreenHeight() / 2) + 150.0f, 30, WHITE);

		//DrawRectangleRec(resumeButton,RED);
		//DrawRectangleRec(menuButton, GREEN);

		EndDrawing();

		if (CheckCollisionPointRec(GetMousePosition(), menuButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			setScene(0);
		}


		if (_framecounter < 6) {
			_framecounter++;
		}
		if (_framecounter > 5) {
			if (CheckCollisionPointRec(GetMousePosition(), resumeButton) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ESCAPE)||IsKeyPressed(KEY_P)) {
				unpause();
			}
		}

#if DEBUG

#endif
	}
	void Mainframe::pause() {
		if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_P) || CheckCollisionPointRec(GetMousePosition(),gamePauseButton)&&IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			screenId = screenID::pause;
			_framecounter = 0;
		}
	}
	void Mainframe::unpause() {
		screenId = screenID::game;
		_framecounter = 0;
	}
}