//Program to implement bag/multi-set
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

void delay(unsigned int ms)
{
	clock_t goal=ms+clock();
	while(goal>clock());
}


void SetColorAndBackground(int ForgC,int BackC)
{

WORD wColor=((BackC & 0x0F) << 4)+(ForgC & 0x0F);;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
return;

}





COORD coordinate={0,0};
void gotoxy(int x,int y)
{
	coordinate.X=x;
	coordinate.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);
}



typedef struct node
{
    char data[10];
    int count;
    struct node *link;
}NODE;
void insert(NODE *header)
{
    NODE *ptr,*n;
    int flag;
    char data[10];
    ptr=header;
    flag=0;
    system("cls");
    SetColorAndBackground(15,1);

	gotoxy(25,17);

	printf("Enter the element to be inserted: ");
    gotoxy(60,17);
    printf("{ ");


	scanf(" %s",data);
    gotoxy(63,17);
	printf("}");

    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
        if(strcmp(ptr->data,data)==0)
        {
            flag=1;
            goto increment;
        }

    }
    if(flag==0)
    {
        n=(NODE*)malloc(sizeof(NODE));
        strcpy(n->data,data);
        n->count=1;
        n->link=NULL;
        ptr->link=n;
        gotoxy(27,19);
        printf("%s inserted",data);
    }
    else
    {
        increment:
        ptr->count++;
        gotoxy(27,19);
        printf("%s inserted",data);
    }

//goto hello;
}

void delete1(NODE *header)
{
    NODE *ptr,*ptr1;
    int flag=0;
    char data[5];
    system("cls");
	SetColorAndBackground(15,1);

	ptr=header;
	gotoxy(25,17);
    printf("Enter the element to be deleted ");
	gotoxy(60,17);
	scanf(" %s",data);
	if(ptr==NULL)
    {
    	gotoxy(25,19);
        printf("The bag is empty");
    }
    else
    {
        while(ptr->link!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->link;
            if(strcmp(ptr->data,data)==0)
            {
                flag=1;
                break;
            }

        }
        if(flag==0)
        {
        	gotoxy(25,19);
            printf("%s is not present in the bag",data);
        }
        else
        {
            (ptr->count)--;
            gotoxy(25,19);
            printf("One %s has been deleted from the bag",data);
            if(ptr->count==0)
            {
                gotoxy(25,19);
				printf("There are no %s's remaining in the bag",data);
                ptr1->link=ptr->link;
                free(ptr);
            }
            else
            {
                gotoxy(25,20);
				printf("There is/are %d %s's remaining in the bag",ptr->count,data);
            }
        }
    }
  //  goto hello;
}
void display(NODE *header)
{
    NODE *ptr;
    char data[10];
    int i;
    SetColorAndBackground(15,1);
	ptr=header->link;
    system("cls");
    if(ptr==NULL)
    {
    	gotoxy(25,17);
        printf("The bag is empty");
    }
    else
    {   //
    	gotoxy(25,17);
        printf("The bag is:{");
        while(ptr!=NULL)
        {
            if(header->link==ptr)
                {
                    printf("%d%s",ptr->count,ptr->data);
                }
            else
                {
                    printf(",%d%s",ptr->count,ptr->data);
                }

            ptr=ptr->link;

        }
        //


        printf("}");
    }
}

void end()
{	int i;
	SetColorAndBackground(15,1);
	for(i=1;i<40;i++)
	{
		system("cls");
		gotoxy(35,3);
		printf("DEVELOPERS OF THIS PROGRAM......");
		gotoxy(i+6,8);
		printf("NANDAGOPAL");
		gotoxy(80-i+4,10);
		printf("SARATH");
		gotoxy(i+6,12);
		printf("SIDHARTH");
		gotoxy(80-i+4,14);
		printf("VIVEK");
		delay(30);

	}
}



int main()
{
    NODE *header;
    int i, ch;
    char data[10];
    header=(NODE*)malloc(sizeof(NODE));
    strcpy(header->data,"NULL");
    header->count=0;
    header->link=NULL;
    SetColorAndBackground(15,1);

	system("cls");
	hello:
    {
    	gotoxy(35,4);
        printf("Bag/multiset implementation using linked list");
    	gotoxy(40,8);
		printf("1. Insert an element into the bag");
		gotoxy(40,9);
		printf("2. Delete an element from the bag");
		gotoxy(40,10);
		printf("3. Display the elements of the bag");
		gotoxy(40,11);
		printf("4. Exit");
        gotoxy(40,15);
        printf("your choice:");
		scanf("%d",&ch);
        switch(ch)
        {

			case 1: insert(header);
					getchar();
					break;

			case 2: delete1(header);
					getchar();
 					break;

			case 3: display(header);
            		getchar();
        			break;

        	case 4: end();
					exit(0);
					break;
        	default :printf("Wrong input");


        };
    goto hello;
    }
    return 0;
}
