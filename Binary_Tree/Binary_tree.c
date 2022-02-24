#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
} * root;
struct node *st[100];
int top = -1;

void push(struct node *temp)
{
  st[++top] = temp;
}

struct node *pop()
{
  return st[top--];
}

struct node *peak(){
    if (top==-1){
      return NULL;
    }
    return st[top];
}

struct node *create()
{
  struct node *temp;
  int x;
  printf("Enter data(0 for no data):");
  scanf("%d",&x);
  if (x == 0)
    return NULL;
  
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data=x;
  printf("\nENTER A LEFT OF %d\n",temp->data);
  temp->left = create();

  printf("\nENTER A RIGHT OF %d\n",temp->data);
  temp->right = create();
  return temp;
}

void inorderNR(struct node *temp)
{
  struct node *s;
  while (temp != NULL)
  {
    push(temp);
    temp = temp->left;
  }

  while (top != -1)
  {
    s = pop();

    printf("%d ", s->data);
    s = s->right;
    while (s != NULL)
    {
      push(s);
      s = s->left;
    }
  }
}

void preorderNR(struct node *temp)
{
  struct node *C;

  while (temp != NULL)
  {
    printf("%d ", temp->data);
    push(temp);
    temp = temp->left;
  }

  while (top != -1)
  {
    C = pop();

    C = C->right;

    while (C != NULL)
    {
      printf("%d ",C->data);
      push(C);
      C = C->left;
    }
  }
}



void postorderNR(struct node *root)
{
  struct node *temp = root;
    do {
    while (temp != NULL) {
      if(temp->right!=NULL)
        push(temp->right);
      push(temp);
      temp = temp->left;
    }
    temp = pop();
    if (temp->right != NULL && temp->right == peak()) {
      pop();
      push(temp);
      temp = temp->right;
    } else {
      printf("%d ",temp->data);
      temp = NULL;
    }
  } while (top != -1);
}


void inorder(struct node *temp)
{

  if (temp != NULL)
  {
    inorder(temp->left);
    printf("%d ",temp->data);
    inorder(temp->right);
  }
}
void preorder(struct node *temp)
{

  if (temp != NULL)
  {

    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
  }
}

void postorder(struct node *temp)
{

  if (temp != NULL)
  {
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);
  }
}

int leaf(struct node *T)
{

  if (T == NULL)
    return 0;

  if (T->left == NULL && T->right == NULL)
  {
    return 1;
  }
  return(leaf(T->left) + leaf(T->right));
}

struct node *mirror(struct node *r)
{
  struct node *temp;
  if(r==NULL)
    return NULL;
  else
  {
    temp=r->left;
    r->left=mirror(r->right);
    r->right=mirror(temp);
    return r;
  }
}


int main()
{
  struct node *temp,*temp1;
  root = NULL;
  root = create();
  temp = root;
  printf("\ninorder\n");
  inorder(temp);
  printf("\npreorder\n");
  preorder(temp);
  printf("\npostorder\n");
  postorder(temp);
  printf("\ninorder non recursive\n");
  inorderNR(temp);
  printf("\npreorder non recursive\n");
  preorderNR(temp);
  printf("\npostorder non recursive\n");
  postorderNR(temp);

  printf("\nmirror\n");
  temp1=mirror(temp);
  inorder(temp1);

  printf("\nLEAF = %d",leaf(temp));
  getch();
}

