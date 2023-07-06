#include "Player.h"
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>

void Create_Single_Player(Single_Player* P1) {
    printf("Enter your name (up to 19 characters):\n");
    fgets(P1->c, 20, stdin);
    P1->c[strcspn(P1->c, "\n")] = 0;
    Set_Player_Level(P1);

}
void  Set_Player_Level(Single_Player* P1) {

    printf("Pick Level\n");
    printf("[0] Easy\n");
    printf("[1] Medium\n");
    printf("[2] Hard\n");
    scanf("%d", &(P1->LVL));

    while (1) {


        if (P1->LVL == 0) {
            printf("Easy\n");
            break;
        }
        else if (P1->LVL == 1) {
            printf("Medium\n");
            break;
        }
        else if (P1->LVL == 2) {
            printf("Hard\n");
            break;
        }
        else {
            printf("Nie wybrano odpowiedniego poziomu\n");
        }
    }


};
Single_Player* Create_Players(int Number_Of_Player) {
    Single_Player* Array_Of_Players;
    Array_Of_Players = (Single_Player*)malloc(number * sizeof(Single_Player));
    if (Array_Of_Players == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    for (int i = 0; i < number; i++) {
        Single_Player* newPlayer = Create_Multiplayer_Player();
        Array_Of_Players[i] = *newPlayer;
        // free the temporary player memory
        free(newPlayer);
    }
    return Array_Of_Players;
}

Single_Player* Create_Multiplayer_Player() {
    Single_Player* Player = (Single_Player*)malloc(sizeof Single_Player);
    if (Player == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    fgets(Player->c, 20, stdin);
    Player->c[strcspn(Player->c, "\n")] = 0;
    return Player;
}