
#include "Guide.h"



void Guide() {

    Guide_Road_Map();
}
void Guide_Road_Map() {
    while (1) {
        printf("***** GAME GUIDE *****\n");
        printf("1. Power Ups\n");
        printf("2. Movement\n");
        printf("3.Game Info \n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            // code to start single player
            Power_Ups_Info();
        }
        else if (choice == 2) {
            // code to start multi player

            Movment();
        }
        else if (choice == 3) {
            // code to open settings
            Game_Info();
        }
        else if (choice == 4) {
            printf("Exiting game...\n");
            break;
        }
        else {
            printf("Invalid choice, please try again.\n");
        }
    }
};

void Game_Info() {
    printf("***** Game Info *****\n");
    printf("ChessMate! is a  project which was mine tool to learn C programig, whislist beeing creative.\n");
    printf("Whole permis of the game is to offer a player, a quick portion of fun brain stimulating  activity.\n.");
    printf("Rigtht now it is a console adaptation of the game to see if it is even engaing or fun.\n.");
    printf("Feel free to contac  me at  s.zelkowski66@gmail.com and give honset feedback");
    printf ("****Cheers Simon!")

};

void Power_Ups_Info() {

    printf("*****ChessMate!*****\n");
    printf("1. Freeze\n");
    printf("2. Movement\n");
    printf("3. \n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    while(1){
    if (choice == 1) {
        // code to start single player
        Freeze_Overwiew();
    }
    else if (choice == 2) {
        // code to start multi player
    }
    else if (choice == 3) {
        // code to open settings
    }
    else if (choice == 4) {
        printf("Exiting game...\n");
        break;
    }
    else {
        printf("Invalid choice, please try again.\n");
    }
}
};





void Movment() {


}



void Freeze_Overwiew() {

    printf("****** Freeze ******\n");
    printf("This power-up allows a player to freeze a chosen opponent for a certain number of rounds.\n");
    printf("However, there is a 5% chance that the player will be frozen upon picking up the power-up.\n");
    printf("'F' is the symbol for the Freeze power-up. The number next to 'F' indicates how long the freeze effect lasts.\n");
    printf("For example, 'F2' means that the opponent or the player is frozen for two full rounds.\n");



};

void Second_Move() {
    printf("****** Second Move ******\n");
    printf("This power-up allows a player to make a second move during player's turn.\n");
};

