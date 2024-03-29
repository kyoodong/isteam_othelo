#include <stdio.h>
#include "game.h"

void startGame();
void endGame();
int choiceMenu();
void showRule();

int playCount = 0;
int playerWin1 = 0;
int playerWin2 = 0;
int draw = 0;

int main() {
    while (1) {
        switch (choiceMenu()) {
            case 1:
                // 게임 시작
                startGame();
                break;

            case 2:
                // 게임 규칙
                showRule();
                break;

            case 3:
                // 게임 종료
                return 0;
        }
    }
}


////////////////////////////////// Menu //////////////////////////////////

/*
 * TODO 게임 시작
 * */
void startGame() {
    playCount++;
    baseSetting(playerWin1, playerWin2, draw ,playCount);
    int turn = playCount % 2;
    while (checkGameable()) {
        if (turn) {
            if (!inputPin(PLAYER1)) {
                playCount--;
                system("cls");
                return;
            }
            turn--;
        }
        else {
            if (!inputPin(PLAYER2)) {
                playCount--;
                system("cls");
                return;
            }
            turn++;
        }
    }
    endGame();
}

/*
 * TODO 게임 끝
 * */
void endGame() {
    int player1Pin = getPinCount(PLAYER1);
    int player2Pin = getPinCount(PLAYER2);

    system("cls");
    if (player1Pin > player2Pin) {
        printf("PLAYER1 WIN\n");
        playerWin1++;
    } else if (player2Pin > player1Pin) {
        printf("PLAYER2 WIN\n");
        playerWin2++;
    } else {
        printf("DRAW!!\n");
        draw++;
    }
}


/*
 * TODO 메뉴 보여주기
 * */
int choiceMenu() {
    int menu = 0;
    printf("1. Game Start\n");
    printf("2. Game Rules\n");
    printf("3. End\n");
    scanf("%d", &menu);
    return menu;
}


/*
 * TODO 규칙 보여주기
 */
void showRule() {
    printf("게임 규칙\n\n");
    printf("-처음에 판 가운데에 사각형으로 엇갈리게 배치된 돌 4개를 놓고 시작한다.\n");
    printf("-돌은 반드시 상대방 돌을 양쪽에서 포위하여 뒤집을 수 있는 곳에 놓아야 한다.\n");
    printf("-돌을 뒤집을 곳이 없는 경우에는 차례가 자동적으로 상대방에게 넘어가게 된다.\n");
    printf("-아래와 같은 조건에 의해 양쪽 모두 더 이상 돌을 놓을 수 없게 되면 게임이 끝나게 된다.\n");
    printf("\t64개의 돌 모두가 판에 가득 찬 경우\n");
    printf("\t어느 한 쪽이 돌을 모두 뒤집은 경우\n");
    printf("\t한 차례에 양 쪽 모두 서로 차례를 넘겨야 하는 경우\n");
    printf("-게임이 끝났을 때 돌이 많이 있는 플레이어가 승자가 된다. 만일 돌의 개수가 같을 경우는 무승부가 된다.\n\n\n");
}

////////////////////////////////// Game //////////////////////////////////
