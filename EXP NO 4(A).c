#include <stdio.h>
#define max 20
char stk[max];
int top =-1;
int isempty()
{
return top==-1;
}
int isfull()
{
return top==max-1;
}
char peek()
{
return stk[top];
}
char pop()
{
if (isempty())
	return -1;
else
	return stk[top--];
}
void push(char oper)
{
if (isfull())
	printf("Stack Full!\n");
else 
	stk[++top]=oper;
}
int checkifoperand(char ch)
{
	return (ch>='a'&& ch<='z') || (ch>='A' && ch<='Z');
}
int precedence (char ch)
{
	switch (ch)
	{
		case '+':
		case '-':
			return 1;
			
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}
void convinftopost(char * infix)
{
	int i,j=0;
	char postfix[max];
	for (i=0;infix[i];++i)
	{
	    if(checkifoperand(infix[i]))
			postfix[j++] = infix[i];
		else if (infix[i]=='(')
			push (infix[i]);
		else if (infix[i]==')')
			{
			while (!isempty() && peek() != '(')
				postfix[j++]=pop();
			if(!isempty() && peek() == '(')
				pop();
			}
	    else 
	    {
	    while (!isempty() && precedence(infix[i])<= precedence(peek()))
	    	postfix[j++]= pop();
	    push(infix[i]);
	    }
	}
	while (!isempty())
	
		postfix[j++]=pop();
	postfix[j]='\0';
	printf("Postfix Expression:%s\n",postfix);
}
int main()
{
	char infix[15];
	printf("Enter an infix expression:");
	scanf("%s",infix);
	convinftopost(infix);
	return 0;
}

			

