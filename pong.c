#include <stdio.h>
#include <conio.h>
#include <unistd.h>

void draw(int X_border, int Y_border);
void movement();
void ball_movement();

/*
turn the player's axes into an array so the padel can be bigger
*/

const int X_player1 = 2;
int Y_player1 = 20;

const int X_player2 = 39;
int Y_player2 = 20;

int X_ball = 20;
int Y_ball = 20;

int X_flag = -1;
int Y_flag = -1;

char input = ' ';

int main(){
  int Is_alive = 1;
  while(Is_alive != 0){
    usleep(25);
    system("cls");
    movement();
    ball_movement();
    draw(40, 40);
 }
  return 0;
}

void draw(int X_border, int Y_border){
  for (int i = 1; i < X_border + 1; i++){
    printf("# ");
  }
  printf("\n");
  for (int y = 1; y < Y_border + 1; y++){
    for (int x = 1; x < X_border + 1; x++){
      if (x == 1 || x == X_border || x == X_border/2){
	printf("# ");
      }
      else if ((x == X_player1 && y == Y_player1) || (x == X_player2 && y == Y_player2)){
	printf("||");
      }
      else if (x == X_ball && y == Y_ball){
	printf("@ ");
      }
      else{
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
      Y_player1--;
      break;
    case 's':
      Y_player1++;
      break;
    default :
      break;
    }
  }
}

void ball_movement(){
  /*
    Finish all conditions for the ball movement with the borders 
    and try to switch it to switch cases
  
    Use a mathmatical equation that takes in the move flag condition 
    and adds them together to make a simple move condition with the added
    move variables so it may better be put inside a switch statement. 

    make the plater padel bigger 
  */
}
