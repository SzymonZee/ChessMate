#include "Board.h"



void Create_Board(Board* board, int Rows, int Columns) {

    board->Rows = Rows;
    board->Columns = Columns;
    board->array = (int**)calloc(Rows, sizeof(int*));

    if (board->array == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    for (int i = 0; i < Rows; i++)
    {
        board->array[i] = (int*)calloc(Columns, sizeof(int));
        if (board->array[i] == NULL) {
            fprintf(stderr, "Out of memory\n");
            exit(1);
        }


        for (int j = 0; j < Columns; j++)
        {
            if ((i + j) % 2 == 0) {
                board->array[i][j] = Black;
            }
            else {
                board->array[i][j] = White;
            }

        }

    }

}



