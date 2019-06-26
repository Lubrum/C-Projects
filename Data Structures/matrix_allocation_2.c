//Matrix creation with malloc.//
//Subject: pointers//
//Author: Luciano Moraes da Luz Brum//
#include<stdio.h>
#include<stdlib.h>
int main (void){
  int lines_number, colunms_number, lines, colunms;

  printf("Inform the lines and colunms of the matrix\n");
  scanf("%d%d", &lines_number, &colunms_number);

  int *mat;
  mat = (int*) malloc (lines_number * colunms_number * sizeof(int));

  printf("Inform values for the matrix.\n");
  for(lines = 0; lines < lines_number; lines++){
    for(colunms = 0; colunms < colunms_number; colunms++){
      scanf("%d", &mat[lines * colunms_number + colunms]);
    }
  }

  for(lines = 0; lines < lines_number; lines++){
    printf("\n");
      for(colunms = 0; colunms < colunms_number; colunms++){
         printf("%d", mat(lines * colunms_number + colunms));
      }
  }

  return 0;
}