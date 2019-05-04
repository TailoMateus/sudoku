#include <stdio.h>

int sudoku[9][9] = {
    {1,0,0,0,9,0,0,0,5},
    {0,0,7,0,0,8,0,0,0},
    {0,0,0,4,0,7,0,9,0},
    {0,2,4,0,0,0,8,0,0},
    {5,0,0,0,0,0,0,0,2},
    {0,0,6,0,0,0,1,3,0},
    {0,4,0,2,0,6,0,0,0},
    {0,0,0,1,0,0,4,0,0},
    {3,0,0,0,8,0,0,0,6}
};

void imprime() {
  int l, c;

  for (l = 0; l < 9; l++) {
    for (c = 0; c < 9; c++) {
      printf("%d ", sudoku[l][c]);
      if (c % 3 == 2) printf("  ");
    }
    printf("\n");
  }
  printf("\n");
}

int verifica(int lin, int col, int n) {
  int l, c, lr, cr;

  if (sudoku[lin][col] == n) return 1;
  if (sudoku[lin][col] != 0) return 0;
  for (c = 0; c < 9; c++)
    if (sudoku[lin][c] == n) return 0;
  for (l = 0; l < 9; l++)
    if (sudoku[l][col] == n) return 0;
  lr = lin / 3;
  cr = col / 3;

  for (l = lr * 3; l < (lr + 1) * 3; l++)
    for (c = cr * 3; c < (cr + 1) * 3; c++)
      if (sudoku[l][c] == n) return 0;
      
  return 1;
}

void resolve(int lin, int col) {
  int n, t;

  if (lin == 9)
    imprime();
  else
    for (n = 1; n <= 9; n++)
      if (verifica(lin, col, n)) {
        t = sudoku[lin][col];
        sudoku[lin][col] = n;

        col == 8 ? resolve(lin + 1, 0) : resolve(lin, col + 1);
        sudoku[lin][col] = t;
      }
}

int main() {
  resolve(0,0);
  return 0;
}
