/*
	FAETERJ-RIO
	Fundamentos de Programa��o - Manh�
	Data: 11/06/2025
	
	Ponteiros
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//main
void main ()
{
	//declara��o de vari�veis
	char s[20];
	char *p;
	
	strcpy (s,"ALGORITMOS");
	
	p = s;
	
	while (*p != '\0')
	{
		printf ("%p - %c\n", p, *p);
		p++;
	}
}
