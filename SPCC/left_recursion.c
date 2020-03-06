


#include<stdio.h>
#include<string.h>
#define SIZE 10
int main () 
{
	char non_terminal;
	char beta[SIZE],alpha[SIZE];
	char production[SIZE];
	int index=3, i; /* starting of the string following "->" */
	printf("Enter the grammar: ");
	scanf("%s",production);
	for(i=0;i<SIZE;i++)
	{
		printf("%c",production[i]);
	}
	non_terminal=production[0];
	if (non_terminal == production[index])
	{
		printf("\nGrammar is left recursive\n");
		index=4;
		//alpha
		for(i=0;production[index]!='|';i++,index++)
		{
			alpha[i]=production[index];
		}
		if(production[index]=='|')
		{
		//beta
			index+=1;
			for(i=0;production[index]!='\0';i++,index++)
			{
				beta[i]=production[index];
			}
		}
	}
	else
	{
		printf("\nGrammar is not left recursive");
	}
	printf("Alpha: ");
	for(i=0;i<3;i++)
	{
		printf("%c",alpha[i]);
	}
	printf("\n");	
	printf("Beta: ");
	for(i=0;i<3;i++)
	{
		printf("%c",beta[i]);
	}
		
	printf("\n%c->%s%c'",non_terminal,beta,non_terminal);
	printf("\n%c'->e|%s%c'",non_terminal,alpha,non_terminal);

	return 0;
}
