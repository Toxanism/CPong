#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 2

int draw(int X_border, int Y_border);

int main()
{
  bool Is_alive = true;
  while(Is_alive != false){
    draw(40, 40);
    Is_alive = false;
  }
  return 0;
}

int draw(int X_border, int Y_border){
  
  for (int i = 1; i < X_border + 1; i++){
    printf("# ");
  }
  printf("\n");
  
  for (int i = 1; i < Y_border + 1; i++){
    for (int j = 1; j < X_border + 1; j++){
      if (j == 1 || j == X_border || j == X_border/2){
	printf("# ");
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
