#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 6
struct department
{
	char depcode[10];
	char* depname;
	int numofsales;
}typedef department;
void inputdepartmeninfo(department* p);
void arrangrpointers(department* p, department* s[]);
void calcuatethebestandtheworstsales(department* p, department* s[]);
void printresult(department* s[]);
int main()
{
	int i;
	department p[N];
	department* cl_data_ptr_vec[N];
	inputdepartmeninfo(p);
	arrangrpointers(p, cl_data_ptr_vec);
	calcuatethebestandtheworstsales(p, cl_data_ptr_vec);
	printresult(cl_data_ptr_vec);
	for (i = 0; i < N; i++)
		free(p[i].depname);
	return 0;
}
// function name : inputdepartmeninfo //
// input : an department array //
// output : input the information of the sections from the user //
// algorithim : for loop //
void inputdepartmeninfo(department* p)
{
	int i;
	char str[20];
	for (i = 0; i < N; i++)
	{
		printf("**section %d \n", i + 1);
		printf("Enter the section code :");
		scanf("%s", p[i].depcode);
		printf("\n");
		printf("Enter the section name :  ");
		scanf("%s", str);
		p[i].depname = (char*)malloc((strlen(str) + 1) * sizeof(char));
		if (p[i].depname == NULL)
		{
			printf("Cannot allocate memory ");
			exit(1);
		}
		strcpy(p[i].depname, str);
		printf("\n");
		printf("Enter the number of sales : ");
		scanf("%d", &p[i].numofsales);
		printf("\n");
		printf("______________________\n");
	}
}
// function name : arrangrpointers //
// input : the department array (sections information) and a void array //
// output : arrange structs pointers in the "s" array so that each struct has a paralell pointer //
// algorithim : for loop //
void arrangrpointers(department* p, department* s[])
{
	int i;
	for (i = 0; i < N; i++)
		s[i] = &p[i];
}
// function name : calcuatethebestandtheworstsales //
// input : the department array (sections information) and the pointers array // 
// output : transmit the pointer of the section which have the most sales to the first place in the array and the pointer of the section which have the lowest sales to the second place in the array //
// algorithim : for loop //
void calcuatethebestandtheworstsales(department* p, department* s[])
{
	department* m[1];
	int i = 0, biggestsales = 0, j, lowestsales = p[0].numofsales, k = 0;
	for (i = 0; i < N; i++)
	{
		if (p[i].numofsales > biggestsales)
		{
			biggestsales = p[i].numofsales;
			j = i;
		}
		if (p[i].numofsales < lowestsales)
		{
			lowestsales = p[i].numofsales;
			k = i;
		}
	}
	m[0] = s[0];
	s[0] = &p[j];
	s[j] = m[0];
	m[0] = s[1];
	s[1] = &p[k];
	s[k] = m[0];
}
// function name : printresult //
// input : the pointers array //
// output : prints the information of the section with most sales and the information of the lowest one //
// algorithim : none // 
void printresult(department* s[])
{
	printf("The section with best sales  : %s   %s\n", s[0]->depname, s[0]->depcode);
	printf("The section with worst sales : %s   %s\n", s[1]->depname, s[1]->depcode);
}
