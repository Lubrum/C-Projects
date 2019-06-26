//Stack of numbers and operations using Stack_operatorss and vectors with simple operations.//
//Subject: stacks//
//Author: Luciano Moraes da Luz Brum//

#include <stdio.h>
#include <stdlib.h>
struct Stack_operators
{
     char info;
     struct Stack_operators *next;
};
typedef struct Stack_operators Stack_operators;

struct Stack_values
{
     float vector[20];
     int n;
};
typedef struct Stack_values Stack_values;

struct Calculator
{
     Stack_values *values;
     Stack_operators *operators;
};
typedef struct Calculator Calculator;

Stack_operators* create_stack_operators (){
     return NULL;
}

void print_stack_operators (Stack_operators * p){
     Stack_operators * l;
     if(p == NULL){
          printf("Stack is empty of operators !!\n\n");
     }
     else{
          for (l = p; l != NULL; l = l -> next){
               printf ("%c\n", l -> info);
          }
          printf("\n");
     }
}

void push_stack_operators (Stack_operators ** p, char c){
     if ( c == '+' || c == '-' || c == '*' || c == '/'){
          Stack_operators* l = (Stack_operators *) malloc (sizeof (Stack_operators));
          l -> info = c;
          l -> next = *p;
          *p = l;
     }
     else{
          printf("Invalid operator. Try again.\n\n\n");
     }
}

char pop_stack_operators (Stack_operators ** p){
     if (*p != NULL){
          Stack_operators * aux = *p;
          *p = aux -> next;
          char valor = aux -> info;
          free (aux);
          return valor;
     }
     else {
          //printf ("Not possible. Stack of operators is empty !! \n");
          return '@';
     }
}

void free_stack_operators (Stack_operators * p){
     Stack_operators * aux = p;
     while (aux != NULL){
          Stack_operators * novo = aux -> next;
          free (aux);
          aux = novo;
     }
     free (p);
}

Stack_values* create_stack_values (){
     Stack_values *p = (Stack_values*)malloc (sizeof(Stack_values));
     p -> n = 0;
     return p;
}

void push_stack_values (Stack_values * p, float valor){
     if ( p -> n < 20) {
          p -> vector [p -> n] = valor;
          p -> n ++;
     }
     else {
          printf ("Full Stack !! \n");
     }
}

float pop_stack_values (Stack_values * p){
     if (p -> n > 0){ 
          float aux = p -> vector[p -> n - 1];
          p -> n --;
          return aux;
     }
     else {
          //printf ("Empty Stack !! \n");
          return -1;
     }
}

void free_stack_values (Stack_values * p){
     free (p);
}

void print_stack_values (Stack_values * p){
     int i;
     if( p -> n == 0){
          printf("Stack is empty of values!!\n\n");
     }
     else{
          for ( i = (p -> n) - 1; i >= 0; i--){
               printf ("%f\n", p -> vector[i]);
          }
          printf("\n");
     }
}

Calculator *create_calculator(){
     Calculator *calc = (Calculator*) malloc (sizeof(Calculator));
     calc -> operators = create_stack_operators();
     calc -> values = create_stack_values();
     return calc;
}

void print_calculator(Calculator * calc) {
     print_stack_values(calc -> values);
     print_stack_operators(calc -> operators);
}

void do_calculation (Calculator * calc){
	char c;
	float n1, n2;
     printf("Initial Stack:\n");
     print_stack_values(calc -> values);
     print_stack_operators(calc -> operators);
     do{ 
          c = pop_stack_operators(&calc -> operators);
          switch (c) {
               case '+':
                         n1 = pop_stack_values(calc -> values);
                         n2 = pop_stack_values(calc -> values);
                         if(n1 != -1 && n2 != -1){
                              printf("Operation: %f %c %f = %f.\n\nStack:\n\n", n1, c, n2, n1 + n2);
                              push_stack_values( calc -> values, n1 + n2);
                              print_stack_values(calc -> values);
                              print_stack_operators(calc -> operators);
                         }
                         break;

               case  '-':
                         n1 = pop_stack_values(calc -> values);
                         n2 = pop_stack_values(calc -> values);
                         if(n1 != -1 && n2 != -1){
                              printf("Operation: %f %c %f = %f.\n\nStack:\n\n", n1, c, n2, n1 - n2);
                              push_stack_values( calc -> values, n1 - n2);
                              print_stack_values(calc -> values);
                              print_stack_operators(calc -> operators);
                         }
                         break;

               case  '*':
                         n1 = pop_stack_values(calc -> values);
                         n2 = pop_stack_values(calc -> values);
                         if(n1 != -1 && n2 != -1){
                              printf("Operation: %f %c %f = %f.\n\nStack:\n\n", n1, c, n2, n1 * n2);
                              push_stack_values( calc -> values, n1 * n2);
                              print_stack_values(calc -> values);
                              print_stack_operators(calc -> operators);
                         }
                         break;

               case  '/':
                         n1 = pop_stack_values(calc -> values);
                         n2 = pop_stack_values(calc -> values);
                         if(n1 != -1 && n2 != -1){
                              printf("Operation: %f %c %f = %f.\n\nStack:\n\n", n1, c, n2, n1 / n2);
                              push_stack_values( calc -> values, n1 / n2);
                              print_stack_values(calc -> values);
                              print_stack_operators(calc -> operators);
                         }
                         break;
          }
     }
     while(c != '@' && n1 != -1 && n2 != -1);
}

void free_calculator(Calculator * calc){
    free_stack_values(calc -> values);
    free_stack_operators(calc -> operators);
    free(calc);
}

int main(void){
     float v;
     char c;
     int op;
     Calculator *calc;
     calc = create_calculator();
     do{
          printf("Menu:\n");
          printf("1 - Insert values on the stack.\n");
          printf("2 - Insert operation on the stack.\n");
          printf("3 - Calculate.\n");
          printf("4 - Print the Stack.\n");
          printf("5 - Exit program.\n\n");
          printf("Choose your option.\n");
          scanf("%d" , &op);
          switch(op){
               case 1:
                    printf("Enter a value:\n");
                    scanf("%f" , &v);
                    push_stack_values(calc -> values , v);
                    break;

               case 2:
                    printf("Enter a operator ( + , - , * , / ):\n");
                    fflush(stdin);
                    scanf("%c" , &c);
                    push_stack_operators(&calc -> operators , c);
                    break;

               case 3:
                    do_calculation(calc);
                    break;

               case 4:
                    print_calculator(calc);
                    break;

               case 5:
                    printf("Thank you for using this program !!");
                    free(calc);
                    break;

               default:
                    printf("\nInvalid Option!\n\n");
                    break;
          }
     }
     while(op != 5);
     return 0;
}

