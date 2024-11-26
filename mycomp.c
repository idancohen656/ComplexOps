#include "complex.h"

#define START_OVER 	{\
			memset(command, 0, sizeof(command));\
        		memset(operation, 0, sizeof(operation));\
			\
        		/*length = 0;*/\
        		state = START;\
			goto start;\
			}

/*typedef enum {COMMA, OPERATION, OPERATOR, START}status;*/


int is_number(char *str) 
{
	while(*str != '\0')
	{
        	if(*str <= '0' || *str > '9')
			return 1;
		str++;
	}
	return 0;
}
int main()
{

read_comp(&A,0,0);
read_comp(&B,0,0);
read_comp(&C,0,0);
read_comp(&D,0,0);
read_comp(&E,0,0);
read_comp(&F,0,0);
char str [200];
char command[200]="";
char operation[200]="";

int length = 0;
int p=0;
int b=0;
int v=0;
status state = START;
printf("Hello, please choose the operation you want to execute and the suitable operands.\n");
start:
fgets(str, 200, stdin); 
	
	/*for (v=0, b=0;v<199;v++)
	{
		if (str[v]!=' ' && str[v]!='\n' && str[v]!='\t')
		{
			command[b]=str[v];
			b++;
			length++;
		}
	}
	
	for (p=0;p<length;p++)
	{
		if ((command[p]>='a'&&command[p]<='z')||(command[p]=='_'))
		{
			if (state!=OPERATION && state!=START)
			{
				printf("using lower letter in wrong place, please try again\n");
				START_OVER;
			}
			state = OPERATION;
			continue;
		}
		if(((command[p]>='A') && (command[p]<='F'))/*||(is_number(command[p])))
		{
			if ((state!=COMMA)&&(state!=OPERATION))
			{
				printf("Wrong place of parameter, please try again\n");
				START_OVER;
			}
			state = OPERATOR;
			continue;
		}
		/*if(command[p]==',')
		{
			if (state==COMMA)
			{
				printf("Multiple consecutive commas, please try again\n");
				START_OVER;
			}
			if (state!=OPERATOR)
			{
				printf("Illegal comma, please try again\n");
				START_OVER;
			}
			if (p==length)
			{
				printf("Extraneous text after end of command, try again\n");
				START_OVER;
			}
			state=COMMA;
			continue;
		}
		
	}*/
	
	char* token = strtok(str, " ,\n\t"); 
	double x = 0,y = 0;
	char parameter[10][100] ;
	int i = 0;
	int k = 0;
	strcpy(operation,token);
	token = strtok(NULL, " ,\n\t"); 
	while (token != NULL && i < 10) 
	{
        strcpy(parameter[i], token);
	i++;
        token = strtok(NULL, " ,!");
	}
	for(k=0;k<strlen(operation);k++)
	{
		if ((operation[k] >= 'A' && operation[k] <= 'Z'))
		{
			printf("please use lowwer letters in operation name, please try again\n");
			START_OVER;
		}
			 
	}
	if (strcmp("read_comp",operation)==0) 
	{
		if (i!=3)
		{
			printf("Wrong number of prameters, please try again\n");
			START_OVER;
		}
		if (!is_number(parameter[1]) || !is_number(parameter[2]))
		{
			printf("wrong parameters, please try again\n");
			START_OVER;
		}
		complex* operand;
			
		switch (*parameter[0])
		{
			case 'A':
			operand=&A;
			break;
			case 'B':
			operand=&B;
			break;
			case 'C':
			operand=&C;
			break;
			case 'D':
			operand=&D;
			break;
			case 'E':
			operand=&E;
			break;
			case 'F':
			operand=&F;
			break;
			default :
			{
				printf("Undefined complex variable\n");
				START_OVER;
			}
		}
		x = atof(parameter[1]);
        	y = atof(parameter[2]);
		read_comp(operand,x,y);
		START_OVER;
	}
	if (strcmp("print_comp",operation)==0)
	{
		if (i!=1)
		{
			printf("Wrong number of prameters, please try again\n");
			START_OVER;
		}
		complex* operand;		
		switch (*parameter[0])
		{
			case 'A':
			operand=&A;
			break;
			case 'B':
			operand=&B;
			break;
			case 'C':
			operand=&C;
			break;
			case 'D':
			operand=&D;
			break;
			case 'E':
			operand=&E;
			break;
			case 'F':
			operand=&F;
			break;
			default :
			{
				printf("Undefined complex variable\n");
				START_OVER;
			}
		}
		print_comp(operand);
		START_OVER;
	
	}
	if (strcmp("add_comp",operation)==0)
	{
		if (i!=2)
		{
			printf("Wrong number of prameters, please try again\n");
			START_OVER;
		}
		complex* operand1;
		complex* operand2;
		switch (*parameter[0])
		{
			case 'A':
			operand1=&A;
			break;
			case 'B':
			operand1=&B;
			break;
			case 'C':
			operand1=&C;
			break;
			case 'D':
			operand1=&D;
			break;
			case 'E':
			operand1=&E;
			break;
			case 'F':
			operand1=&F;
			break;
			default :
			{
				printf("Undefined complex variable\n");
				START_OVER;
			}
		}
		switch (*parameter[1])
		{
			case 'A':
			operand2=&A;
			break;
			case 'B':
			operand2=&B;
			break;
			case 'C':
			operand2=&C;
			break;
			case 'D':
			operand2=&D;
			break;
			case 'E':
			operand2=&E;
			break;
			case 'F':
			operand2=&F;
			break;
			default :
			{
				printf("Undefined complex variable\n");
				START_OVER;
			}
		}
		add_comp(operand1, operand2);
		START_OVER;
	}
	if (strcmp("sub_comp",operation)==0)
	{
		if (i!=2)
		{
			printf("Wrong number of prameters, please try again\n");
			START_OVER;
		}
		complex* operand1;
		complex* operand2;
		switch (*parameter[0])
		{
			case 'A':
			operand1=&A;
			break;
			case 'B':
			operand1=&B;
			break;
			case 'C':
			operand1=&C;
			break;
			case 'D':
			operand1=&D;
			break;
			case 'E':
			operand1=&E;
			break;
			case 'F':
			operand1=&F;
			break;
			default :
			{
				printf("Undefined complex variable\n");
				START_OVER;
			}
		}
		switch (*parameter[1])
		{
			case 'A':
			operand2=&A;
			break;
			case 'B':
			operand2=&B;
			break;
			case 'C':
			operand2=&C;
			break;
			case 'D':
			operand2=&D;
			break;
			case 'E':
			operand2=&E;
			break;
			case 'F':
			operand2=&F;
			break;
			default :
			{
				printf("Undefined complex variable\n");
				START_OVER;
			}
		}
		sub_comp(operand1, operand2);
		START_OVER;
	}
	if (strcmp("mult_comp_real",operation)==0)
	{
		if (i!=2)
		{
			printf("Wrong number of prameters, please try again\n");
			START_OVER;
		}
		if (!is_number(parameter[1]))
		{
			printf("wrong parameters, please try again\n");
			START_OVER;
		}
		complex* operand;
		switch (*parameter[0])
		{
			case 'A':
			operand=&A;
			break;
			case 'B':
			operand=&B;
			break;
			case 'C':
			operand=&C;
			break;
			case 'D':
			operand=&D;
			break;
			case 'E':
			operand=&E;
			break;
			case 'F':
			operand=&F;
			break;
			default :
			{
				printf("Undefined complex variable\n");
				START_OVER;
			}
		}
		x = atof(parameter[1]);
		mult_comp_real(operand,x);
		START_OVER;
	}
	if (strcmp("mult_comp_img",operation)==0)
	{
		if (i!=2)
		{
			printf("Wrong number of prameters, please try again\n");
			START_OVER;
		}
		if (!is_number(parameter[1]))
		{
			printf("wrong parameters, please try again\n");
			START_OVER;
		}
		complex* operand;
		switch (*parameter[0])
		{
			case 'A':
			operand=&A;
			break;
			case 'B':
			operand=&B;
			break;
			case 'C':
			operand=&C;
			break;
			case 'D':
			operand=&D;
			break;
			case 'E':
			operand=&E;
			break;
			case 'F':
			operand=&F;
			break;
			default :
			{
				printf("Undefined complex variable\n");
				START_OVER;
			}
		}
		x = atof(parameter[1]);
		mult_comp_img(operand,x);
		START_OVER;
	}
	if (strcmp("mult_comp_comp",operation)==0)
	{
		if (i!=2)
		{
			printf("Wrong number of prameters, please try again\n");
			START_OVER;
		}
		complex* operand1;
		complex* operand2;
		switch (*parameter[0])
		{
			case 'A':
			operand1=&A;
			break;
			case 'B':
			operand1=&B;
			break;
			case 'C':
			operand1=&C;
			break;
			case 'D':
			operand1=&D;
			break;
			case 'E':
			operand1=&E;
			break;
			case 'F':
			operand1=&F;
			break;
			default :
			{
				printf("Undefined complex variable\n");
				START_OVER;
			}
		}
		switch (*parameter[1])
		{
			case 'A':
			operand2=&A;
			break;
			case 'B':
			operand2=&B;
			break;
			case 'C':
			operand2=&C;
			break;
			case 'D':
			operand2=&D;
			break;
			case 'E':
			operand2=&E;
			break;
			case 'F':
			operand2=&F;
			break;
			default :
			{
				printf("Undefined complex variable\n");
				START_OVER;
			}
		}
		mult_comp_comp(operand1, operand2);
		START_OVER;	
	}
	if (strcmp("abs_comp",operation)==0)
	{
		if (i!=1)
		{
			printf("Wrong number of prameters, please try again\n");
			START_OVER;
		}
		complex* operand;		
		switch (*parameter[0])
		{
			case 'A':
			operand=&A;
			break;
			case 'B':
			operand=&B;
			break;
			case 'C':
			operand=&C;
			break;
			case 'D':
			operand=&D;
			break;
			case 'E':
			operand=&E;
			break;
			case 'F':
			operand=&F;
			break;
			default :
			{
				printf("Undefined complex variable\n");
				START_OVER;
			}
		}
		abs_comp(operand);
		START_OVER;
	}
	if (strcmp("stop",operation)==0)
	{
		if (i>0)
		{
			printf("Extraneous text after end of command\n");
			START_OVER;
		}
		exit(0);
	}
	else
	{
		printf("Undefined command name, try again\n");
		START_OVER;	
	}
	
return 0;
}
