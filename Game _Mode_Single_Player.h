#pragma once
#include "Player.h"
#include <stdbool.h>
typedef union {
	int freeze;
	int Second_Move;

	// other power-ups
} Power_Up;

typedef struct {
	int x;
	int y;


} Player_Position;

typedef union {


};

typedef struct {
	Player_Position Position;
	Power_Up Power_Ups;
	int score;
	int Pawn_Lvl;
	bool Player_Turn;
	
}Single_Player_Game_State;




void Single_Player_Game();