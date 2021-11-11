#include <stdio.h>

#define rownum 6
#define columnnum 9

char board[6][9];

char frame[17] = {"X 0 1 2 3 4 5 6 X"};

int move;
char player;
int k = 1;
int end = 0;
int turn = 1;


void printBoard();


int isWinner(char);

void insert(char, int);


int main() {
    printf("The game has started!\n");


    //filling the board
    for (int i = 0; i < 6; i++) {

        for (int k = 0; k < 9; k++) {
            board[i][k] = '_';
        }
    }
    int m = 48;//ASCII
    for (int j = 0; j < 6; j++) {//left right columns
        board[j][0] = (char) m;
        board[j][8] = (char) m;
        m++;
    }
    printBoard();
    printf("\n\n");


    while (end == 0 && turn <= 54 ) {


        if (k == 1) {
            printf("\nPlayer 1's Turn (R):\n");
            player = 'R';

            k = 2;

        } else if (k == 2) {
            printf("\nPlayer 2's Turn (Y):\n");
            player = 'Y';

            k = 1;

        }
        printf("Enter  move: \n");
        scanf(" %d", &move);


        insert(player, move);
        end = isWinner(player);


    }
    return 0;
}


void printBoard() {
    for (int i = 0; i < 17; i++) {
        printf("%c", frame[i]);

    }
    printf("\n");
    for (int i = 0; i < 6; i++) {
        for (int k = 0; k < 9; k++) {
            printf("%c ", board[i][k]);
        }

        printf("\n");

    }
    for (int i = 0; i < 17; i++) {
        printf("%c", frame[i]);

    }


}


void insert(char player1, int move1) {


    for (int i = 5; i >= 0; --i) {

        if (board[i][move1 + 1] == '_') {

            board[i][move1 + 1] = player1;
            printBoard();

            break;

        }
    }
}




int isWinner(char player1) {
    for (int row = 0; row < rownum; row++) {
        for (int col = 0; col < columnnum - 3; col++) {
            if (board[row][col] == player1 &&
                board[row][col + 1] == player1 &&
                board[row][col + 2] == player1 &&
                board[row][col + 3] == player1) {
                if (player1 == 'R')
                    printf("\nPlayer 1 has won!");
                else
                    printf("\nPlayer 2 has won!");
                return 1;
            }
        }
    }

    //up and down
    for (int row = 0; row < rownum - 3; row++) {
        for (int col = 0; col < columnnum; col++) {
            if (board[row][col] == player1 &&
                board[row + 1][col] == player1 &&
                board[row + 2][col] == player1 &&
                board[row + 3][col] == player1) {
                if (player1 == 'R')
                    printf("\nPlayer 1 has won!");
                else
                    printf("\nPlayer 2 has won!");
                return 1;
            }
        }
    }
    //diagonal
    for (int row = 3; row < rownum; row++) {
        for (int col = 0; col < columnnum - 3; col++) {
            if (board[row][col] == player1 &&
                board[row - 1][col + 1] == player1 &&
                board[row - 2][col + 2] == player1 &&
                board[row - 3][col + 3] == player1) {
                if (player1 == 'R')
                    printf("\nPlayer 1 has won!");
                else
                    printf("\nPlayer 2 has won!");
                return 1;
            }
        }
    }
    return 0;

}


