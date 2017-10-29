//Program to implement bag/multi-set
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char data[10];
    int count;
    struct node *link;
}NODE;
void insert(NODE *header,char data[])
{
    NODE *ptr,*new;
    int flag;
    ptr=header->link;
    flag=0;
    while(ptr->link!=NULL)
    {
        if(strcmp(ptr->data,data)==0)
        {
            flag=1;
            break;
        }
        ptr=ptr->link;
    }
    if(flag==0)
    {
        new=(NODE*)malloc(sizeof(NODE));
        strcpy(new->data,data);
        new->count=1;
        new->link=NULL;
        ptr->link=new;
        printf("\n%s %d inserted",data,ptr->count);
    }
    else
    {
        (ptr->count)++;
        printf("\nFirst %s inserted",data);
    }
}
void delete(NODE *header,char data[])
{
    NODE *ptr,*ptr1;
    int flag=0;
    ptr=header->link;
    if(ptr==NULL)
    {
        printf("\nThe bag is empty");
    }
    else
    {
        while(ptr->link!=NULL)
        {
            if(strcmp(ptr->data,data)==0)
            {
                flag=1;
                break;
            }
            ptr1=ptr;
            ptr=ptr->link;
        }    
        if(flag==0)
        {
            printf("\n%s is not present in the bag",data);
        }
        else
        {
            (ptr->count)--;
            printf("\nOne %s has been deleted from the bag",data);
            if(ptr->count==0)
            {
                printf("\nThere are no %s's remaining in the bag",data);
                ptr1->link=ptr->link;
                free(ptr);
            }
            else
            {
                printf("\nThere is/are %d %s's remaining in the bag",ptr->count,data);
            }
        }
    }
}
void display(NODE *header)
{
    NODE *ptr;
    char data[10];
    int i;
    ptr=header->link;
    if(ptr==NULL)
    {
        printf("\nThe bag is empty");
    }
    else
    {    
        printf("\nThe bag is:\n{");
        while(ptr->link!=NULL)
        {
            for(i=1;i<=(ptr->count);i++)
            {
                printf("%s, ",ptr->data);
            }
        }
        printf("}\n");
    }
} 
int main()
{
    NODE *header;
    int ch;
    char data[10];
    header=(NODE*)malloc(sizeof(NODE));
    header->count=0;
    header->link=NULL;
    printf("\nBag/multiset implemented using linked list");
    while(1)
    {
        printf("\n\nPress\n1. Insert an element into the bag\n2. Delete an element from the bag\n3. Display the elements of the bag\n4. Exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nEnter the element to be inserted ");
            scanf(" %s",data);
            insert(header,data);
        }
        else if(ch==2)
        {
            printf("\nEnter the element to be deleted ");
            scanf(" %s",data);
            delete(header,data);
        }
        else if(ch==3)
        {
            display(header);
        }
        else if(ch==4)
        {
            exit(0);
        }
        else
        {
            printf("\nWrong input");
        }
    }
    return 0;
}
