#include <stdio.h>
#include <conio.h>
#include <unistd.h>

void draw(int X_border, int Y_border);
void movement();
void ball_movement();
void AI_movement();

const int X_player1 = 2;
double Y_player1[5] = {18,19,20,21,22};

const int X_player2 = 29;
double Y_player2[5] = {18,19,20,21,22};

double X_ball = 15;
double Y_ball = 15;

char input = ' ';

int ball_flag = 1;

int Is_alive = 1;

int main(){
    while(Is_alive != 0){
        usleep(25);
        system("cls");
        movement();
        ball_movement();
	AI_movement();
        draw(30, 30);
    }
    printf("\n\n\n##########GAME OVER##########\n\n\n");
    return 0;
}

void draw(int X_border, int Y_border){
    for (int i = 1; i < X_border + 1; i++){
        printf("# ");
    }
    printf("\n");
    for (int y = 1; y < Y_border + 1; y++){
        for (int x = 1; x < X_border + 1; x++){
            int found = 0;
            for(int i = 0; i < 5; i++){
                if (x == X_player1 && y == Y_player1[i]){
                    printf("||");
                    found = 1;
                }
                if (x == X_player2 && y == Y_player2[i]){
                    printf("||");
                    found = 1;
                }
            }
            if (x == 1 || x == X_border || x == X_border/2){
                printf("# ");
                found = 1;
            }
            else if (x == X_ball && y == Y_ball){
                printf("@ ");
                found = 1;
            }
            else if (found != 1){
                printf("  ");
            }
        }
        printf("\n");
    }
    for (int i = 1; i < X_border + 1; i++){
        printf("# ");
    }
    printf("\n");
}

void movement(){
    if (kbhit()){
        input = _getch();
        switch (input){
            case 'w':
            for(int i = 0; i < 5; i++){
                Y_player1[i]--;
            }
            break;
            case 's':
            for(int i = 0; i < 5; i++){
                Y_player1[i]++;
            }
            break;
            default :
            break;
        }
    }
}

void ball_movement(){
    //player ball collision
    for (int i = 0; i < 5; i++){
      if((X_ball == X_player1 + 1 && Y_ball == Y_player1[i]) && ball_flag == 1){
        ball_flag = 3;
      }
      if((X_ball == X_player1 + 1 && Y_ball == Y_player1[i]) && ball_flag == 2){
        ball_flag = 4;
      }
      if((X_ball == X_player2 - 1 && Y_ball == Y_player2[i]) && ball_flag == 3){
        ball_flag = 1;
      }
      if((X_ball == X_player2 - 1 && Y_ball == Y_player2[i]) && ball_flag == 4){
        ball_flag = 2;
      }
    }
    
    // Border collision
    if (Y_ball < 1 && ball_flag == 1){
        ball_flag = 2;
    }
    if (Y_ball < 1 && ball_flag == 3){
        ball_flag = 4;
    }
    if (Y_ball > 30 && ball_flag == 2){
        ball_flag = 1;
    }
    if (Y_ball > 30 && ball_flag == 4){
        ball_flag = 3;
    }
    if (X_ball < 1){
      Is_alive = 0;
    }
    if (X_ball > 29){
	Is_alive = 0;
      }
      
    //ball move condition
    switch(ball_flag)
    {
        case 1:
        Y_ball -= 0.5;
        X_ball -= 0.5;
        break;
        case 2:
        Y_ball += 0.5;
        X_ball -= 0.5;
        break;
        case 3:
        Y_ball -= 0.5;
        X_ball += 0.5;
        break;
        case 4:
        Y_ball += 0.5;
        X_ball += 0.5;
        default:
        break;
    }
}

void AI_movement(){
  if (Y_ball > Y_player2[2]){
      for(int i = 0; i < 5; i++){
	Y_player2[i] += 0.5;
      }
    }
    if (Y_ball < Y_player2[2]){
      for(int i = 0; i < 5; i++){
	Y_player2[i] -= 0.5;
      }
    }
}
