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
struct node *insert(struct node *temp, int data)
{
  struct node *r;
  r = (struct node *)malloc(sizeof(struct node));
  r->data = data;
  r->left = r->right = NULL;
  if (temp == NULL)
    return r;
  if (temp->data > data)
    temp->left = insert(temp->left, data);
  else
    temp->right = insert(temp->right, data);

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

    printf("\t%d", s->data);
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
    printf("\t%d", temp->data);
    push(temp);
    temp = temp->left;
  }

  while (top != -1)
  {
    C = pop();

    C = C->right;

    while (C != NULL)
    {
      printf("\t%d", C->data);
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
      printf("\t%d",temp->data);
      temp = NULL;
    }
  } while (top != -1);
}

void inorder(struct node *temp)
{

  if (temp != NULL)
  {
    inorder(temp->left);
    printf("\t%d", temp->data);
    inorder(temp->right);
  }
}
void preorder(struct node *temp)
{

  if (temp != NULL)
  {

    printf("\t%d", temp->data);
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
    printf("\t%d",temp->data);
  }
}
struct node *create(struct node *temp)
{
  int i, n, x;
  printf("\nHOW MANY NODES YOU WANT TO CREATE\n");
  scanf("%d",&n);
  for (i = 0; i < n; i++)
  {
    printf("\nENTER A DATA\n");
    scanf("%d",&x);
    temp = insert(temp, x);
  }
  return temp;
}

struct node *search(struct node *temp, int data)
{
  if (temp == NULL)
  {
    printf("\nDATA IS NOT PRESENT");
    return NULL;
  }

  if (temp->data == data)
  {
    printf("\nDATA IS PRESENT\n");
    return temp;
  }

  if (temp->data > data)

    return (search(temp->left, data));

  else
    return (search(temp->right, data));
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

int main()
{
  struct node *temp,*temp1;
  root = NULL;
  temp=root;
  root = create(temp);
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
  printf("\nLEAF = %d",leaf(temp));
  getch();
}
