//All equation test cases are satisfied I think



#include <stdio.h>
#include <stdlib.h>

void PUSH(char stack[], char c);
char POP(char stack[]);
void CHECK(char stack[], char c);

int top=-1;

int main()
{
	char stack[50];
	char c;
	FILE *fptr;

	if ((fptr = fopen("program.txt", "r")) == NULL)
	{
		printf("Error in opening file");
		// Program exits if file pointer returns NULL.
		exit(0);         
	}

	// reads text until End of File
	while(1)
	{
		if (fscanf(fptr,"%c", &c)==EOF)
		{
			printf("Reached End of File\n");
			break;
		}
		CHECK(stack,c);	
	}
	if(top!=-1)
	{
		printf("Brackets are not balanced,top\n");
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
        	printf("Brackets are not balanced\n");
		exit(0);
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
	       	if(tempc=='(')
                {
                        printf("() Brackets are balanced\n");
                }
                else
                {
                        printf("() Brackets are not balanced");
                        exit(0);
                }
	}
        if(c=='}')
        {
		tempc=POP(stack);
                if(tempc=='{')
                {
                        printf("{} Brackets are balanced\n");
                }
                else
                {
                        printf("{} Brackets are not balanced");
                        exit(0);
                }
	}
	if(c==']')
        {
		tempc=POP(stack);
                if(tempc=='[')
                {
                        printf("[] Brackets are balanced\n");
                }
                else
                {
                        printf("[] Brackets are balanced");
                        exit(0);
                }
	}
}
