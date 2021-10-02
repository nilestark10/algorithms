#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
  int coeff;
  int pow;
  struct link *next;
} my_poly;
 
void create(my_poly **);
void display(my_poly *);
 
int main(void)
{
  int ch;
  do
  {
    my_poly *poly1, *poly2;
 
    printf("\nCreate 1st expression\n");
    create(&poly1);
    printf("\nStored the 1st expression");
    display(poly1);
 
    printf("\nCreate 2nd expression\n");
    create(&poly2);
    printf("\nStored the 2nd expression");
    display(poly2);
 
    printf("\nAdd two more expressions? (Y = 1/N = 0): ");
    scanf("%d", &ch);
  } while (ch);
  return 0;
}
 
void create(my_poly **node)
{
  int flag;
  int coeff, pow;
  my_poly *tmp;
  tmp = (my_poly *)malloc(sizeof(my_poly));
  *node = tmp;
  do
  {
 
    printf("\nEnter Coeff:");
    scanf("%d", &coeff);
    tmp->coeff = coeff;
    printf("\nEnter Pow:");
    scanf("%d", &pow);
    tmp->pow = pow;
 
    tmp->next = NULL;
    printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
    scanf("%d", &flag);
    if (flag)
    {
      tmp->next = (my_poly *)malloc(sizeof(my_poly));
      tmp = tmp->next;
      tmp->next = NULL;
    }
  } while (flag);
}
 
void display(my_poly *node)
{
  printf("\nThe polynomial expression is:\n");
  while (node != NULL)
  {
    printf("%dx^%d", node->coeff, node->pow);
    node = node->next;
    if (node != NULL)
      printf(" + ");
  }
}
