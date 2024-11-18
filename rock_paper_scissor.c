#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char computer_choice();
int game(char player,char computer);
void game_result(int result);


int main() {
    char player,computer;
    int result;

    while (player != 'R' && player != 'P' && player != 'S') {
        system("cls");
        puts("Rock     (r)");
        puts("Paper    (p)");
        puts("Scissor  (s)");
        printf("Choose:>_ ");
        player = toupper(getchar());
    }
    computer = computer_choice();
    printf("computer: %c",computer);
    result = game(player,computer);
    game_result(result);
    return 0;
}

char computer_choice() {
    int n;
    char computer;
    srand(time(NULL));
    n = rand() % 100;

    if (n < 33) {
        computer = 'r';
    } else if (n < 66) {
        computer = 'p';
    } else {
        computer = 's';
    }

    return computer;
}

int game(char player,char computer) {
    player = toupper(player);
    computer = toupper(computer);
    if (player == computer) {
        return -1;
    }
    if (player == 'R' && computer == 'P'){
        return 0;
    } else if (player == 'P' && computer == 'R') {
        return 1;
    }
    if (player == 'P' && computer == 'S'){
        return 0;
    } else if (player == 'S' && computer == 'P') {
        return 1;
    }
    if (player == 'S' && computer == 'R'){
        return 0;
    } else if (player == 'R' && computer == 'S') {
        return 1;
    }
}

void game_result(int result) {
    if (result == -1) {
        puts("\ndraw");
    } else if (result == 1) {
        puts("\nyou win");
    } else {
        puts("\nyou loose");
    }
}