//Distance between two Points, using malloc and structs.//
//Subject: Pointers//
//Author: Luciano Moraes da Luz Brum//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct point{
  float x, y;
};
typedef struct point Point;

Point *create_point(){
  Point *aux;
  aux=(Point*)malloc(sizeof(Point));
  return aux;
}

void read_point(Point *p){
  printf("Inform x\n");
  scanf("%f", &p->x);
  printf("Inform y\n");
  scanf("%f", &p->y);
}

float distance(Point *p1, Point *p2){
  return sqrt(((p2->x-p1->x)*(p2->x-p1->x))+((p2->y-p1->y)*(p2->y-p1->y)));
}

int main(void){
  float result;
  Point *p;
  Point *w;

  p=create_point();
  read_point(p);

  w=create_point();
  read_point(w);

  result=distance(p,w);
  printf("Distance between x(%f,%f) and y(%f,%f) is %f\n", p->x, p->y, w->x, w->y, result);

  return 0;  
}


