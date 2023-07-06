#pragma once
#include<stdio.h>
#include "Board.h"
#include <stdlib.h>
#define White 0;
#define Black 1;

#define _CRT_SECURE_NO_WARNINGS

typedef struct {
    int Rows;
    int Columns;

    int  **  array;

} Board;

// Now you can do

void Create_Board(Board*, int, int);


void Zone(Board);


