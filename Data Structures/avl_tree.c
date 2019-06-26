//AVL tree of integers.//
//Subject: AVL trees.//
//Author: Luciano Moraes da Luz Brum//

#include<stdio.h>
#include<stdlib.h>
struct avl_tree{
   int height;
   int info;
   struct avl_tree *left;
   struct avl_tree *right;
};
typedef struct avl_tree avl_tree;

avl_tree *avl_tree_create(){
   return NULL;
}


int avl_tree_empty(avl_tree *t){
   return (t == NULL);
}

int max(int a, int b){
   if(a >= b){
      return a;
   }
   else{
      return b;
   }
}

int avl_tree_height(avl_tree *t){
   if(avl_tree_empty(t)){
      return -1;
   }
   else{
      return t->height;
   }
}

avl_tree *rotate_right(avl_tree *t){
   avl_tree *aux;
   aux = t -> left;
   t -> left = aux -> right;
   aux -> right = t;
   t -> height = 1 + max(avl_tree_height(t -> left), avl_tree_height(t -> right));
   aux -> height = 1 + max(avl_tree_height(aux -> left), avl_tree_height(aux -> right));
   return aux;
}

avl_tree *rotate_left(avl_tree *t){
   avl_tree *aux;
   aux = t -> right;
   t -> right = aux -> left;
   aux -> left = t;
   t -> height = 1 + max(avl_tree_height(t -> left), avl_tree_height(t -> right));
   aux -> height = 1 + max(avl_tree_height(aux -> left), avl_tree_height(aux -> right));
   return aux;
}

avl_tree *rotate_left_right(avl_tree *t){
   t -> left = rotate_left(t -> left);
   t = rotate_right(t);
   return t;
}

avl_tree *rotate_right_left(avl_tree *t){
   t -> right = rotate_right(t -> right);
   t = rotate_left(t);
   return t;
}

avl_tree *balance(avl_tree *t){
   if(avl_tree_height(t -> left) - avl_tree_height(t -> right) == 2){
  		if(avl_tree_height(t -> left -> left) - avl_tree_height(t -> left -> right) == 1){
  		   t = rotate_right(t);
  		}
      else{
  		   t = rotate_left_right(t);
      }
   }
   else{
  		if(avl_tree_height(t -> left) - avl_tree_height(t -> right) == -2){
  			if(avl_tree_height(t -> right -> left) - avl_tree_height(t -> right -> right) == -1){
  			   t = rotate_left(t);
  			}
         else{
  		      t = rotate_right_left(t);
         }
  		}
   }
   t -> height = 1 + max(avl_tree_height(t -> left), avl_tree_height(t -> right));
   return t;
}

avl_tree *avl_tree_insert(avl_tree *t, int i){
   if(avl_tree_empty(t)){
      t = (avl_tree*) malloc (sizeof(avl_tree));
      t -> info = i;
      t -> height = 0;
      t -> left = NULL;
      t -> right = NULL;
   }
   else{
      if(i < t -> info){
         t -> left = avl_tree_insert(t -> left, i);
      }
      else{
         if(i > t -> info){
            t -> right = avl_tree_insert(t -> right, i);
         }
      }
   }
   t = balance(t);
   return t;
 }

avl_tree *avl_tree_remove(avl_tree *t, int i){
   if(avl_tree_empty(t)){
      return NULL;
   }
   else{
		if(i < t -> info){
         t -> left = avl_tree_remove(t -> left, i);
      }
      else{
			if(i > t -> info){
            t -> right = avl_tree_remove(t -> right, i);
         }
         else{
				if(t -> left == NULL && t -> right == NULL){
                free(t);
                return NULL;
				}
            else{
					if(t -> right == NULL){
                  avl_tree *aux = t;
                  t = t -> left;
                  free(aux);
               }
               else{
						if(t -> left == NULL){
                     avl_tree *aux = t;
                     t = t -> right;
                     free(aux);
                  }
                  else{
                     avl_tree *temp = t -> left;
                     while(temp -> right != NULL){
                        temp = temp -> right;
                     }
                     t -> info = temp -> info;
                     temp -> info = i;
                     t -> left = avl_tree_remove(t -> left, i);
                  }
               }
            }
         }
      }
   }
   t = balance(t);
   return t;
}

void avl_tree_print_pre_order(avl_tree *t){
   printf("<");
   if(!avl_tree_empty(t)){
      printf("%d", t -> info);
      avl_tree_print_pre_order(t -> left);
      avl_tree_print_pre_order(t -> right);
   }
   printf(">");
}

void avl_tree_print_in_order(avl_tree *t){
   printf("<");
   if(!avl_tree_empty(t)){
      avl_tree_print_in_order(t -> left);
      printf("%d", t -> info);
      avl_tree_print_in_order(t -> right);
   }
   printf(">");
}

void avl_tree_print_post_order(avl_tree *t){
   printf("<");
   if(!avl_tree_empty(t)){
      avl_tree_print_post_order(t -> left);
      avl_tree_print_post_order(t -> right);
      printf("%d", t -> info);
   }
   printf(">");
}

FILE avl_tree_print_pre_order_file(avl_tree *t, FILE *fptr){
   fputc('<', fptr);
   if(!avl_tree_empty(t)){
      fprintf(fptr, "%d", t -> info);
      avl_tree_print_pre_order_file(t -> left, fptr);
      avl_tree_print_pre_order_file(t -> right, fptr);
   }
   fputc('>', fptr);
}

FILE avl_tree_print_in_order_file(avl_tree *t, FILE *fptr){
   fputc('<', fptr);
   if(!avl_tree_empty(t)){
      avl_tree_print_in_order_file(t -> left, fptr);
      fprintf(fptr, "%d", t -> info);
      avl_tree_print_in_order_file(t -> right, fptr);
   }
   fputc('>', fptr);
}

FILE avl_tree_print_post_order_file(avl_tree *t, FILE *fptr){
   fputc('<', fptr);
   if(!avl_tree_empty(t)){
      avl_tree_print_post_order_file(t -> left, fptr);
      avl_tree_print_post_order_file(t -> right, fptr);
      fprintf(fptr, "%d", t -> info);
   }
   fputc('>', fptr);
}

avl_tree *avl_tree_free(avl_tree *t){
   if(!avl_tree_empty(t)){
      t -> left = avl_tree_free(t -> left);
      t -> right = avl_tree_free(t -> right);
      free(t);
   }
   return NULL;
}

int avl_tree_max(avl_tree *t){
   while(!avl_tree_empty(t -> right)){
      t = t -> right;
   }
   return t -> info;
}

int avl_tree_min(avl_tree *t){
   while(!avl_tree_empty(t -> left)){
      t = t -> left;
   }
   return t -> info;
}

int main(void){
   FILE *fptr;
   avl_tree *t;
   int menu, value;
   t = avl_tree_create();
   while(menu != 8){
      printf("Menu:\n");
      printf("1 - Insert a value on the tree.\n");
      printf("2 - Remove a value from the tree.\n");
      printf("3 - Print values from the tree.\n");
      printf("4 - Print values from the tree on text file.\n");
      printf("5 - Print the smallest number of the tree.\n");
      printf("6 - Print the greatest number of the tree.\n");
      printf("7 - Print the tree height.\n");
      printf("8 - Exit program.\n\n");
      printf("Choose your option.\n");
      scanf("%d", &menu);
      switch(menu){
         case 1:
            printf("\nEnter a value:\n");
            scanf("%d", &value);
            t = avl_tree_insert(t, value);
            break;

         case 2:
            if(!avl_tree_empty(t)){
               printf("\nEnter a value:\n");
               scanf("%d", &value);
               t = avl_tree_remove(t, value);
            }
            else{
               printf("\nThe tree is empty !!\n\n");
            }
            break;

         case 3:
            if(!avl_tree_empty(t)){
               avl_tree_print_pre_order(t);
               printf("\n");
               avl_tree_print_in_order(t);
               printf("\n");
               avl_tree_print_post_order(t);
               printf("\n");
            }
            else{
               printf("\nThe tree is empty !!\n\n");
            }
            break;

         case 4:
            if(!avl_tree_empty(t)){
               if ((fptr = fopen("arvore.txt","a")) == NULL){
                  printf("\nNot possible to open the file.\n");
                  break;
               }
               avl_tree_print_pre_order_file(t, fptr);
               fputs("\n", fptr);
               avl_tree_print_in_order_file(t, fptr);
               fputs("\n", fptr);
               avl_tree_print_post_order_file(t, fptr);
               fputs("\n", fptr);
               fclose(fptr);
            }
            else{
               printf("\nThe tree is empty !!\n\n");
            }            
            break;

         case 5:
            if(!avl_tree_empty(t)){
               printf("\nMinimum value: %d\n", avl_tree_min(t));
            }
            else{
               printf("\nAvl tree without elements.\n\n");
            }
            break;

         case 6:
            if(!avl_tree_empty(t)){
              printf("\nMaximum value: %d\n", avl_tree_max(t));
            }
            else{
               printf("\nAvl tree without elements.\n\n");
            }
            break;

         case 7:
            printf("\nAvl tree height: %d\n\n", avl_tree_height(t));
            break;

         case 8:
            printf("\nThank you for using this program !!\n\n");
            avl_tree_free(t);
            break;

         default:
            printf("\nInvalid Option!\n\n");
            break; 
      }
   }
   return 0;
}