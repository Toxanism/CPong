#include <stdio.h>

#define bool int
#define true 1
#define false 0

void draw(int X_border, int Y_border);

const int X_player1 = 2;
int Y_player1 = 20;

const int X_player2 = 39;
int Y_player2 = 20;

int main()
{
  bool Is_alive = true;
  while(Is_alive != false){
    draw(40, 40);
    Is_alive = false;
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
