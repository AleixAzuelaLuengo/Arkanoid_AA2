#pragma once
#include <string>
#include "Types.h"
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int FPS = 60;
const int DELAY_TIME = 1000.f / FPS;
const std::string BACKGROUND_MENU = "../res/img/Backgroung.jpg";
const std::string BRICK_SPRITESHEET = "../res/img/bricks.jpg";
const std::string XML_FILE = "../res/files/config.xml";
const std::string MENU_FONT = "../res/ttf/sunspire.ttf";
const std::string PLAYER_SPRITE = "../res/img/platform.png";
const std::string BALL_SPRITE = "../res/img/ball.png";
const std::string PAUSE_BG = "../res/img/bTrans.png";
const MyColor ButtonNotSelected = { 0 , 255 , 250 , 255 }; 
const MyColor Black = { 0, 0, 0, 255 };
const MyColor Red = { 255, 0, 0, 255 };
const MyColor ButtonSelected = { 0, 130, 250, 255 };
const int PLAYER_WIDTH = 60;
const int PLAYER_HEIGHT = 60;
const int BRICK_WIDTH = 20;
const int BRICK_HEIGHT = 40;
const int BALL_WIDTH = 15;
const int BALL_HEIGHT = 15;
const int MAP_START_X_AND_Y = 26;
const int MAP_END_X = 755;
const int MAP_END_Y = 455;
const Rect GREENBLOCK_FIRST = { 0,0, 40, 20 };
const Rect REDBLOCK_FIRST = { 0,20, 40, 20 };
const Rect FIXEDBLOCK_FIRST = { 0,20, 40, 20 };
#define FPS 60
