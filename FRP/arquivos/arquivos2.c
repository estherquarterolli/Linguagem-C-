/* 
   FAETERJ-Rio
   Fundamentos de Programa��o - FPR - Manh�
   Professor Leonardo Vianna
   Data: 21/05/2025
   
   Arquivos
   
   Exemplo 2: adicionando n�meros ao final de um arquivo existente
   (append)
*/

//importa��o de bibliotecas
#include <stdio.h>

//Prot�tipos das fun��es

//main
void main ()
{
	//declara��o de vari�veis
	int i;
	FILE *arq;  //passo 1: declarar uma vari�vel FILE*, que representar� o arquivo sendo manipulado
	
	//Passo 2: associar a vari�vel FILE* a um arquivo em disco + abrir o arquivo
	arq = fopen ("numeros.txt","a");	
	
	//verificando se ocorreu erro na abertura do arquivo
	if (arq == NULL)  //ou apenas:   if (!arq)
	{
		printf ("\n\nErro na abertura do arquivo!\n");
	}
	else
	{
		for (i=1;i<=1000;i++)
		{
			//Passo 3: manipula��o do arquivo
			fprintf (arq, "%d\n", i);
		}
		
		//passo 4: fechar o arquivo
		fclose (arq);
	}
}

//implementa��o das fun��es

