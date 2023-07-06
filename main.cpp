// SZACHY.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.		c	5	int

//
#include"Board.h"
#include <iostream>
#include<stdio.h>
#include "Chess_Piece_Movement.h"
#include"Player.h"
#include<string.h>
#include"Board.h"
#include"Game_Modes.h";
#include"Guide.h"
#define _CRT_SECURE_NO_WARNINGS


int main()
{

    Single_Player P1;
   
   

    Board B1;
    int c;
    int d;
    int g;
    printf("Give a size of a board\n");
    printf("Rows:\n");
    scanf("%d", &c);
    printf("Columns:\n");
    scanf("%d", &d);
    printf("Give numbers of players\n");
    scanf("%d", &g);
    Create_Board(&B1, c, d);
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < d; j++)
        {
            printf("%d",  B1.array[i][j]);
        }
        printf("\n");
    }
    //title of a ChessMate!//////

    int choice;
    while (1) {
        printf("***** GAME MENU *****\n");
        printf("1. Start Single Player\n");
        printf("2. Start Multi Player\n");
        printf("3. Settings\n");
        printf("4. Guide\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // code to start single player
        }
        else if (choice == 2) {
            // code to start multi player
        }
        else if (choice == 3) {
            // code to open settings
        }
        else if (choice == 4) {
            // code to open guide 
            Guide();
        }

        else if (choice == 5) {
            printf("Exiting game...\n");
            break;
        }
        else {
            printf("Invalid choice, please try again.\n");
        }

    }

    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
