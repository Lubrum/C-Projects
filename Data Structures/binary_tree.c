//Binary tree of integers.//
//Subject: binary trees.//
//Author: Luciano Moraes da Luz Brum//

#include<stdio.h>
#include<stdlib.h>
struct tree{
   int info;
   struct tree *left;
   struct tree *right;
};
typedef struct tree Tree;

Tree *tree_create(){
   return NULL;
}

Tree *tree_insert(Tree *t, int value){
   if(t == NULL){
      t = (Tree*) malloc (sizeof(Tree));
      t -> info = value;
      t -> left = NULL;
      t -> right = NULL;
   }
   else{
      if(value < t -> info){
         t -> left = tree_insert(t -> left, value);
      }
      else{
         if(value > t -> info){
            t -> right = tree_insert(t -> right, value);
         }
      }
   }
   return t;
}

Tree *tree_remove(Tree *t, int value){
   if(t == NULL){
      return NULL;
   }
   else{
      if(value < t -> info){
         t -> left = tree_remove(t -> left, value);
      }
      else{
         if(value > t -> info){
            t -> right = tree_remove(t -> right, value);
         }
         else{
            if(t -> left == NULL && t -> right == NULL){
               free(t);
               return NULL;
            }
            else{
               if(t -> right == NULL){
                  Tree *aux = t;
                  t = t->left;
                  free(aux);
               }
               else{
                  if(t -> left == NULL){
                     Tree *aux = t;
                     t = t -> right;
                     free(aux);
                  }
                  else{
                     Tree *temp = t -> left;
                     while(temp -> right != NULL){
                        temp = temp -> right;
                     }
                     t -> info = temp -> info;
                     temp -> info = value;
                     t -> left = tree_remove(t -> left, value);
                  }
               }
            }
         }
      }
   }
   return t;
}
int tree_empty(Tree* t){
   return (t == NULL);
}


void tree_print_pre_order(Tree *t){
   printf("<");
   if(t != NULL){
      printf("%d", t -> info);
      tree_print_pre_order(t -> left);
      tree_print_pre_order(t -> right);
   }
   printf(">");
}

void tree_print_in_order(Tree *t){
   printf("<");
   if(t != NULL){
      tree_print_in_order(t -> left);
      printf("%d", t -> info);
      tree_print_in_order(t -> right);
   }
   printf(">");
}

void tree_print_post_order(Tree *t){
   printf("<");
   if(t != NULL){
      tree_print_post_order(t -> left);
      tree_print_post_order(t -> right);
      printf("%d", t -> info);
   }
   printf(">");
}

int max(int a, int b){
   return (a > b ? a : b);
}

int tree_height(Tree *t){
   if(t == NULL){
      return -1;
   }
   else{
      return 1 + max( tree_height( t -> left ) , tree_height( t -> right ) );
   }
}

Tree *tree_free(Tree *t){
   if(t != NULL){
      t -> left = tree_free(t -> left);
      t -> right = tree_free(t -> right);
      free(t);
   }
   return NULL;
}

int main(void){
   Tree *tree;
   tree = tree_create();
   int op, value;

   while(op != 5){
      printf("Menu:\n");
      printf("1 - Insert a value on the tree.\n");
      printf("2 - Remove a value from the tree.\n");
      printf("3 - Print values from the tree.\n");
      printf("4 - Print the tree height.\n");
      printf("5 - Exit program.\n\n");
      printf("Choose your option.\n");
      scanf("%d", &op);
      switch(op){
         case 1:
            printf("Enter a value:\n");
            scanf("%d", &value);
            tree = tree_insert(tree, value);
            break;

         case 2:
            if(!tree_empty(tree)){
               printf("Enter a value:\n");
               scanf("%d", &value);
               tree = tree_remove(tree, value);
            }
            else{
               printf("The tree is empty !!");
            }
            break;

         case 3:
            if(!tree_empty(tree)){
               tree_print_pre_order(tree);
               printf("\n");
               tree_print_in_order(tree);
               printf("\n");
               tree_print_post_order(tree);
               printf("\n");
            }
            else{
               printf("The tree is empty !!");
            }
            break;

         case 4:
            printf("Tree Height: %d.\n", tree_height(tree));
            break;

         case 5:
            printf("Thank you for using this program !!");
            tree_free(tree);
            break;

         default:
            printf("\nInvalid Option!\n\n");
            break; 
      }
   }
   return 0;
}