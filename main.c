#include <stdio.h>
#include <string.h>

#define ROWS 3
#define COLS 3

// make clean && make main && ./main
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
    {1,1,0},
    {1,0,1},
    {1,1,1}
  };

  // Algo steps
  // 1. Find column with minumum amount of 1's
  int colToRemove = 1; //minCol(test2);

  // 2. Find which rows were covered by this column
  // (at which index this column has 1's)

  // Add row indexes that we want to remove to an array
  int rowsToRemove[ROWS] = {0};
  int ind = 0;
  for (int i = 0; i < ROWS; i++) {
    if (test2[i][colToRemove] == 1) {
      rowsToRemove[ind] = i;
      ind++;
    }
  }

  // Iterate over row indexes that has to be removed
  // remove corresponding matrix row
  // int firstRun = 1;
  // for (int i = 0; i < ROWS; i++) {
  //   printf("%d\n", rowsToRemove[i]);
  //   if (firstRun) {
  //     delrow(test2, rowsToRemove[i]);
  //     firstRun = 0;
  //   } else {
  //     if (rowsToRemove[i] != 0) {
  //       delrow(test2, rowsToRemove[i-1]);
  //     }
  //   }
  // }

  // removeMatrRow(test2, 0);
  // delrow(test2, 0);
  removeMatrCol(test2, 1);


  // printf("%d\n", colToRemove);
  // int maxRoww = maxRow(test2);
  // printf("%d\n", maxRoww);
  // delcol(test2, 0);


  // Print
  // int i, j;
  // // i - row
  // for (i = 0 ; i < 1 ; i++) { 
  //   // j - col
  //     for (j = 0 ; j < 2 ; j++) {
  //         printf("%d ", test2[i][j]);
  //     }
  //     printf("\n");
  // }

  // Test

  // int matrica[][3] = {
  //   {1, 1, 1},
  //   {2, 2, 2},
  //   {3, 3, 3}
  // };

  return 0;
}

int minCol(int matr[ROWS][COLS]) {
  // Find colum with min amout of 1s
  // minSum has to be something other than 0
  // in the beginning
  int minColSum = ROWS;
  int colSum;
  int colNum;
  for (int col = 0; col < COLS; col++) {
    colSum = 0;
    for (int row = 0; row < ROWS; row++) {
      colSum += matr[row][col];
      // printf("%d %d %d %d\n", row, col, matr[row][col], colSum);
    }

    if (colSum <= minColSum) {
      minColSum = colSum;
      colNum = col;
    }
  }

  return colNum;
}


int maxRow(int matr[ROWS][COLS]) {
  // // Find row with max amount of 1s
  int maxRowSum = 0;
  int currRowSum = 0;
  int rowNum = 0;
  for (int i = 0; i < ROWS; i++) {
    currRowSum = 0;
    for (int j = 0; j < COLS; j++) {
      // if (matr[i][j] == 1) {
      //   maxRowSum += 1;
      // }

      currRowSum += matr[i][j];

      if (currRowSum > maxRowSum) {
        rowNum = i;
        maxRowSum = currRowSum;
      }
    }
  }

  return rowNum;
}

int removeMatrRow(int matr[ROWS][COLS], int rowToRemove) {
  int i, j, k;
  int no_of_rows = ROWS;
  int no_of_columns = COLS;

  for (i = 0 ; i < no_of_rows ; i++) { 
      if (i == rowToRemove) {
          for (k = i ; k < no_of_rows - 1 ; k++) {
              for (j = 0 ; j < no_of_columns ; j++) {
                  matr[k][j] = matr[k+1][j];
              }
          }
         i--;
         no_of_rows--;
      }
  }

  return matr;
}


void delrow(int a[ROWS][COLS], int row){
    if(row < ROWS - 1)
        memmove(&a[row], &a[row+1], (ROWS*COLS - ROWS*(row+1))*sizeof(int));
}

void removeMatrCol(int matr[ROWS][COLS], int col){
    int r;
    if(col < COLS - 1){
        for(r = 0; r < ROWS; ++r){
            memmove(&matr[r][col], &matr[r][col+1], (COLS - (col+1))*sizeof(int));
        }
    }
}
