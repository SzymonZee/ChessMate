// Szachy_Function_Testing.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define White 0
#define Black 1
#define Zielony 2
#define Czerwony 3

typedef struct {
    int Position_On_X_Axis;
    int Position_On_Y_Axis;

} Player_Position;
typedef union {



}Power_Ups;

typedef struct {
    char Name[20];
    int Order;
    int Picked_Number;
    Player_Position Position;
   // Power_Ups Number_Of_Power_Up;
    int Player_Colour;
} Single_Player;


typedef struct {
    int Widht;
    int Lenght;
    int **Board;
    char Symbol[1];
}Game_Board;



Game_Board* Create_Board() {
    Game_Board*Board1=(Game_Board*)malloc(sizeof(Game_Board));
    int Rows;
    int Columns;
    printf("*************Creation of a Game Board**************\n");
   
    printf("Give number of Rows:\n ");
    scanf("%d", &Rows);
    printf("Give number of Columns:\n");
    scanf("%d", &Columns);
    Board1->Widht = Rows;
    Board1->Lenght = Columns;
    Board1->Board = (int**)calloc(Rows, sizeof(int*));

    if (Board1->Board == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    for (int i = 0; i < Rows; i++)
    {
        Board1->Board[i] = (int*)calloc(Columns, sizeof(int));
        if (Board1->Board[i] == NULL) {
            fprintf(stderr, "Out of memory\n");
            exit(1);
        }


        for (int j = 0; j < Columns; j++)
        {
            if ((i + j) % 2 == 0) {
                Board1->Board[i][j] = Black;
            }
            else {
                Board1->Board[i][j] = White;
            }

        }

    }
    return Board1;
}



Single_Player* Create_Player(int Number_Of_Player) {
    Single_Player* z;
    z = (Single_Player*)malloc(Number_Of_Player * sizeof(Single_Player));

    for (int i = 0; i < Number_Of_Player; i++) {
        printf("Enter your name (up to 19 characters):\n");
        fgets(z[i].Name, 20, stdin);
        z[i].Name[strcspn(z[i].Name, "\n")] = 0;  // remove newline from string
    }
    return z;
};

void Randomize_First_Move(int number_of_players, Single_Player* b) {
    int* Picked_Number = (int*)malloc(number_of_players * sizeof(int));
    int number;
    for (int i = 0; i < number_of_players; i++) {
        /// reference to player ////
        printf("Player:%s Give a number from 0 to 20\n", b[i].Name);
        while (1) {
            scanf("%d", &number);
            if (number < 0 || number > 20) {
                printf("Number out of range, please enter a number between 0 and 20.\n");
                continue;
            }
            int already_chosen = 0;
            for (int j = 0; j < i; j++) {
                if (Picked_Number[j] == number) {
                    already_chosen = 1;
                    break;
                }
            }
            if (!already_chosen) break;
            else printf("This number has already been chosen, try another one.\n");
        }
        b[i].Picked_Number = *(Picked_Number + i) = number;
    }
    int g = rand() % 21;
    printf("Number %d was drawn.\n", g);

    // Bubble sort
    for (int i = 0; i < number_of_players - 1; i++) {
        for (int j = 0; j < number_of_players - 1 - i; j++) {
            if (abs(b[j].Picked_Number - g) > abs(b[j + 1].Picked_Number - g)) {
                Single_Player temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    printf("Order of players, closest to furthest from %d:\n", g);
    for (int i = 0; i < number_of_players; i++) {
        printf("%s\n", b[i].Name);
    }

    free(Picked_Number);
};
void Player_Position_On_Board(Single_Player* b, int Number_Of_Players, int choice, Game_Board* B1) {
    for (int i = 0; i < Number_Of_Players; i++) {
        if (choice == 1) {
            for (int i = 0; i < Number_Of_Players; i++) {
                printf("........Randomizing......Player %s.....Position", b[i].Name);
                b[i].Position.Position_On_X_Axis = (rand() % (B1->Widht));
                b[i].Position.Position_On_Y_Axis = (rand() % (B1->Lenght));
            }
        }
        else {
            for (int i = 0; i < Number_Of_Players; i++) {
                printf("Player %s pick yours position\n", b[i].Name);
                printf("Position on x-Axis: \n");
                scanf("%d", &b[i].Position.Position_On_X_Axis);
                printf("Position on y-Axis: \n");
                scanf("%d", &b[i].Position.Position_On_Y_Axis);
            }
        }
    }
};
void Single_Game() {
    Single_Player* Players;
    Game_Board* Board; // Allocating memory for the Game_Board
    int Number_Of_Player;
    Board= Create_Board();
    printf("Enter number of players: ");
    scanf("%d", &Number_Of_Player);
    while ((getchar()) != '\n');  // clear input buffer
    Players = Create_Player(Number_Of_Player);
    Randomize_First_Move(Number_Of_Player, Players);
    printf("To randomize player starting position press [1]\n ");
    printf("To let players pick their starting positions press any number \n");
    int choice;
    scanf("%d", &choice);

    Player_Position_On_Board(Players, Number_Of_Player, choice, Board);
    free(Players);
    Players = NULL;
    // Remember to free the Board as well
    for (int i = 0; i < Board->Widht; i++) {
        free(Board->Board[i]);
    }
    free(Board->Board);
    free(Board);
}

int main() {
    srand(time(NULL));
    Single_Game();
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
