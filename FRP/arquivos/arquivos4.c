/* 
   FAETERJ-Rio
   Fundamentos de Programa��o - FPR - Manh�
   Professor Leonardo Vianna
   Data: 21/05/2025
   
   Arquivos
   
   Exemplo 4: lendo o conteudo de um arquivo e exibindo-o na tela
   (qualquer arquivo)
*/

//importa��o de bibliotecas
#include <stdio.h>

//Prot�tipos das fun��es

//main
void main ()
{
	//declara��o de vari�veis
	char caracter;
	FILE *arq;  //passo 1: declarar uma vari�vel FILE*, que representar� o arquivo sendo manipulado
	
	//Passo 2: associar a vari�vel FILE* a um arquivo em disco + abrir o arquivo
	arq = fopen ("arquivos4.c","r");	
	
	//verificando se ocorreu erro na abertura do arquivo
	if (arq == NULL)  //ou apenas:   if (!arq)
	{
		printf ("\n\nErro na abertura do arquivo!\n");
	}
	else
	{
		while (fscanf (arq, "%c", &caracter) != EOF)   //eof - end of file
		{
			//Passo 3: manipula��o do arquivo			
			printf ("%c", caracter);
		}
		
		//passo 4: fechar o arquivo
		fclose (arq);
	}
}

//implementa��o das fun��es

