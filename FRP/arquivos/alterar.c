/* 
   FAETERJ-Rio
   Fundamentos de Programa��o - FPR - Manh�
   Professor Leonardo Vianna
   Data: 22/05/2025
   
   Arquivos
   
   Dado um arquivo texto contendo n�meros inteiros, um por linha,
   desenvolver uma fun��o que altere todas as ocorr�ncias de um valor
   por outro.
*/

//importa��o de bibliotecas
#include <stdio.h>

//Prot�tipos das fun��es
int alterarValores (char nomeArq[], int velho, int novo);

//main
void main ()
{	
	switch (alterarValores ("novo.txt", 10, 20))
	{
		case -1: printf ("Erro na abertura do arquivo!\n");
		         break;
			
		case 0:  printf ("Valor nao encontrado no arquivo!\n");
		         break;
			
		default: printf ("Alteracoes realizadas com sucesso!\n");
	}
}

//implementa��o das fun��es
int alterarValores (char nomeArq[], int velho, int novo)
{
	//declara��o de vari�veis
	int numero, cont = 0;
	FILE *arq, *temp;  
	
	//abrindo os arquivos
	arq = fopen (nomeArq, "r");	
	temp = fopen ("temp.txt", "w");
	
	//verificando se ocorreu erro na abertura dos arquivos
	if (!arq || !temp)  //ou if ((arq == NULL) || (temp == NULL))
	{
		fclose (arq);
		fclose (temp);
		
		return -1;
	}
	else
	{
		//lendo os dados do arquivo e promovendo as altera��es
		while (fscanf (arq, "%d", &numero) != EOF)   //eof - end of file
		{
			if (numero != velho)
			{
				fprintf (temp, "%d\n", numero);
			}
			else
			{
				fprintf (temp, "%d\n", novo);
				
				//atualizando o n�mero de altera��es realizadas
				cont++;
			}
		}

		//fechando os arquivos
		fclose (arq);
		fclose (temp);
		
		//apagando o arquivo original
		remove (nomeArq);
		
		//renomeando o tempor�rio para o nome do arquivo original
		rename ("temp.txt", nomeArq);
		
		return cont;
	}
}
