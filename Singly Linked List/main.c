#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "struct.h"
#include "create.h"
#include "insert.h"
#include "display.h"
#include "delete.h"
#include "search.h"
#include "meanu.h"


void main()
{
    head=NULL;
    system("cls");
    create();
    display();
    Meanu();
    getch();
}