#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
typedef struct {

	int Points;
	char Name[20];
	
}Single_Player;


void Create_Single_Player(Single_Player*);
Single_Player* Create_Players(int);
Single_Player* Create_Multiplayer_Player();
void  Set_Player_Level(Single_Player*);