//Matrix creation with malloc.//
//Subject: pointers//
//Author: Luciano Moraes da Luz Brum//
#include<stdio.h>
#include<stdlib.h>
int** create_matrix(int lines_number, int colunms_number){
  int **aux;
  int i;
  aux=(int**) malloc(lines_number*sizeof(int*));
  for(i = 0; i < lines_number; i++){
    *(aux+i) = (int*) malloc (colunms_number*sizeof(int));
  }
  return aux;
}

void insert_into_matrix(int **matrix, int lines_number, int colunms_number){
  int i, j;
  for(i = 0; i < lines_number; i++){
    for(j = 0; j < colunms_number; j++){
      scanf("%d", &matrix[i][j]);
    }
  }
}

void show_matrix(int **matrix, int lines_number, int colunms_number){
  int i, j;
  printf("\n\nMatrix received.\n");
  for(i = 0; i < lines_number; i++){
    printf("\n");
    for(j = 0; j < colunms_number; j++){
      printf("%d  ", matrix[i][j]);
    }
  }
}

int main(void){
  int **matrix;
  int lines_number, colunms_number;
  printf("Inform the lines and colunms of the matrix\n");
  scanf("%d%d", &lines_number, &colunms_number);
  matrix = create_matrix(lines_number, colunms_number);
  insert_into_matrix(matrix,lines_number, colunms_number);
  show_matrix(matrix,lines_number, colunms_number);
  return 0;
}