#include <stdio.h>
#include <string.h>

int main() {
    char choice1, choice2;
    int p1, p2, i, j, position, move = 1, count = 0, a[3][3], flag = 1;

    // Initialize the game board
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            a[i][j] = 3; // 3 represents an empty cell
        }
    }

    printf("Welcome to play TIC-TAC-TOE world\n");
    printf("for reference to players\n");
    printf(" ______________\n");
    printf("|a[0]|a[1]|a[2]|\n");
    printf("|____|____|____|\n");
    printf("|a[3]|a[4]|a[5]|\n");
    printf("|____|____|____|\n");
    printf("|a[6]|a[7]|a[8]|\n");
    printf("|____|____|____|\n");

    while (flag == 1) {
        printf("Enter X or O for Player1\n");
        scanf(" %c", &choice1);
        if (choice1 == 'X' || choice1 == 'x' || choice1 == 'O' || choice1 == 'o') {
            flag = 0;
        } else {
            flag = 1;
            printf("Invalid choice\n");
        }
    }

    if (choice1 == 'X' || choice1 == 'x') {
        choice2 = 'O';
    } else {
        choice2 = 'X';
    }

    printf("Player2 choice is %c\n", choice2);
    if (choice1 == 'X' || choice1 == 'x') {
        p1 = 1;
        p2 = 0;
    } else {
        p1 = 0;
        p2 = 1;
    }

    while (move < 3) {
        count = 0;
        if (move == 1) {
            printf("Player1 Enter the position\n");
            scanf("%d", &position);

            int row = position / 3;
            int col = position % 3;

            if (a[row][col] == 3) {
                a[row][col] = p1;
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        if (a[i][j] == 3)
                            printf("\t-");
                        if (a[i][j] == 1)
                            printf("\tX");
                        if (a[i][j] == 0)
                            printf("\tO");
                    }
                    printf("\n");
                }

                // Check for winning condition
                if ((a[0][0] == p1 && a[0][1] == p1 && a[0][2] == p1) ||
                    (a[1][0] == p1 && a[1][1] == p1 && a[1][2] == p1) ||
                    (a[2][0] == p1 && a[2][1] == p1 && a[2][2] == p1) ||
                    (a[0][0] == p1 && a[1][0] == p1 && a[2][0] == p1) ||
                    (a[0][1] == p1 && a[1][1] == p1 && a[2][1] == p1) ||
                    (a[0][2] == p1 && a[1][2] == p1 && a[2][2] == p1) ||
                    (a[0][0] == p1 && a[1][1] == p1 && a[2][2] == p1) ||
                    (a[0][2] == p1 && a[1][1] == p1 && a[2][0] == p1)) {
                    printf("Player1 wins\n");
                    printf("Thank you for playing this game\n");
                    move = 3;
                    break;
                } else {
                    move = 2;
                }
            } else {
                printf("This place is not empty. Please give another position\n");
                move = 1;
            }
        }

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (a[i][j] == 3)
                    count++;
            }
        }
        if (count == 0) {
            move = 3;
            break;
        }

        if (move == 2) {
            printf("Player2 Enter position\n");
            scanf("%d", &position);

            int row = position / 3;
            int col = position % 3;

            if (a[row][col] == 3) {
                a[row][col] = p2;
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        if (a[i][j] == 3)
                            printf("\t-");
                        else if (a[i][j] == 1)
                            printf("\tX");
                        else
                            printf("\tO");
                    }
                    printf("\n");
                }

                // Check for winning condition
                if ((a[0][0] == p2 && a[0][1] == p2 && a[0][2] == p2) ||
                    (a[1][0] == p2 && a[1][1] == p2 && a[1][2] == p2) ||
                    (a[2][0] == p2 && a[2][1] == p2 && a[2][2] == p2) ||
                    (a[0][0] == p2 && a[1][0] == p2 && a[2][0] == p2) ||
                    (a[0][1] == p2 && a[1][1] == p2 && a[2][1] == p2) ||
                    (a[0][2] == p2 && a[1][2] == p2 && a[2][2] == p2) ||
                    (a[0][0] == p2 && a[1][1] == p2 && a[2][2] == p2) ||
                    (a[0][2] == p2 && a[1][1] == p2 && a[2][0] == p2)) {
                    printf("Player2 wins\n");
                    printf("Thank you for playing this game\n");
                    move = 3;
                    break;
                } else {
                    move = 1;
                }
            } else {
                printf("This place is not empty. Please give another position\n");
                move = 2;
            }
        }
    }

    if (move != 3) {
        printf("Draw Match\n");
        printf("Thank you for playing this game\n");
    }

    return 0;
}

