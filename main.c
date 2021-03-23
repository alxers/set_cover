#include <stdio.h>

int main(int argv, char *argc[]) {

  // int HEIGHT = 9;
  // int WIDTH = 10;
  // int b_matr[HEIGHT][WIDTH] = {
  //     {1, 0, 0, 1, 0, 0, 0, 1, 0, 0},
  //     {0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
  //     {0, 1, 1, 0, 1, 0, 0, 1, 0, 0},
  //     {0, 0, 1, 1, 0, 0, 0, 1, 0, 1},
  //     {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
  //     {1, 0, 1, 0, 0, 1, 0, 0, 1, 0},
  //     {0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
  //     {1, 0, 0, 0, 1, 0, 0, 1, 1, 0},
  //     {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
  // };

  // int H = 2;
  // int W = 3;
  // int test[2][3] = {
  //   {11,12,13},
  //   {14,15,16}
  // };

  // int H = 3;
  // int W = 2;
  // int test2[3][2] = {
  //   {1,1},
  //   {1,1},
  //   {1,0}
  // };

  int H = 3;
  int W = 3;
  int test2[3][3] = {
    {1,1,1},
    {1,1,1},
    {1,0,1}
  };

  // Find colum with min amout of 1s
  // minSum has to be something other than 0
  // in the beginning
  int minColSum = H;
  int colSum;
  int colNum;
  for (int col = 0; col < W; col++) {
    colSum = 0;
    for (int row = 0; row < H; row++) {
      colSum += test2[row][col];
      // printf("%d %d %d %d\n", row, col, test2[row][col], colSum);
    }

    if (colSum <= minColSum) {
      minColSum = colSum;
      colNum = col;
    }
  }

  printf("Min column and sum %d %d\n", colNum+1, minColSum);

  // // Find row with min amount of 1s
  int minRowSum;
  int rowNum = 0;
  for (int i = 0; i < H; i++) {
    minRowSum = 0;
    for (int j = 0; j < W; j++) {
      if (test2[i][j] == 1) {
        rowNum = i;
        minRowSum += 1;
      }
    }
  }

  printf("Min row and sum %d %d\n", rowNum+1, minRowSum);

  return 0;
}
