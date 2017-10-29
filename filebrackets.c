//All equation test cases are satisfied I think



#include <stdio.h>
#include <stdlib.h>

void PUSH(char stack[], char c);
char POP(char stack[]);
void CHECK(char stack[], char c);

int top=-1;
int flag;

int main()
{
	char stack[50];
	int c;
	flag=0;
	int expcount=0;
	FILE *fptr;

	if ((fptr = fopen("program.txt", "r")) == NULL)
	{
		printf("Error in opening file");
		// Program exits if file pointer returns NULL.
		exit(0);
	}

	// reads text until End of File
	c = getc(fptr);
	while(c != EOF)
	{
		if(c == '$')
		{
			c=getc(fptr);
			if(c==EOF)
              			break;
			while(c != '$')
			{
				CHECK(stack,c);
				c = getc(fptr);
			}
			if(top!=-1)
			{
				flag=1;
				printf("Brackets are not balanced,top not equals 0\n");
			}
            		expcount++;
			if(flag==1)
            		{
                		printf("False Expression present at expression number %d",expcount);
                		exit(0);
            		}
			top=-1;
			printf("\n\n\n");
		}
	}

	if(flag==0)
	{
		printf("True Expressions");
		exit(0);
	}
	fclose(fptr);
}

void PUSH(char stack[], char item)
{
         top=top+1;
         stack[top]=item;
}
char POP(char stack[])
{
	char item;
	if(top<0)
	{
        	flag=1;
        	printf("Brackets not balanced,stack underflow\n");
	}
        else
        {
                item=stack[top];
                top=top-1;
                return item;
        }
}
void CHECK(char stack[], char c)
{
	char tempc;
	if (c == '(' || c == '{' || c== '[')
	{
		PUSH(stack,c);
	}
	if(c==')')
        {
		tempc=POP(stack);
	       	if(tempc!='(')
                {
                        flag=1;
			printf("() Brackets are not balanced\n");
                }
	}
        if(c=='}')
        {
		tempc=POP(stack);
                if(tempc!='{')
                {
                        flag=1;
			printf("{} Brackets are not balanced\n");
                }
	}
	if(c==']')
        {
		tempc=POP(stack);
                if(tempc!='[')
                {
			flag=1;
                        printf("[] Brackets are not balanced\n");
                }
	}
}
