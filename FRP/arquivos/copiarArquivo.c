/* 
   FAETERJ-Rio
   Fundamentos de Programa��o - FPR - Manh�
   Professor Leonardo Vianna
   Data: 22/05/2025
   
   Arquivos
   
   Desenvolver uma fun��o que, dado um arquivo texto, copie o seu 
   conte�do para outro.
*/

//importa��o de bibliotecas
#include <stdio.h>

//Prot�tipos das fun��es
int copiarArquivo (char nomeArqDestino[], char nomeArqOrigem[]);

//main
void main ()
{
	if (copiarArquivo ("novo.c", "copiarArquivo.c"))
	{
		printf ("Arquivo copiado com sucesso!\n");
	}
	else
	{
		printf ("Erro na abertura dos arquivos!\n");
	}	
}

//implementa��o das fun��es
int copiarArquivo (char nomeArqDestino[], char nomeArqOrigem[])
{
	//declara��o de vari�veis
	char caracter;
	FILE *arqO, *arqD;  
	
	//abrindo os arquivos
	arqO = fopen (nomeArqOrigem, "r");	
	arqD = fopen (nomeArqDestino, "w");
	
	//verificando se ocorreu erro na abertura dos arquivos
	if (!arqO || !arqD)  //ou if ((arqO == NULL) || (arqD == NULL))
	{
		fclose (arqO);
		fclose (arqD);
		
		return 0;
	}
	else
	{
		//copiando o conte�do do arquivo origem para o destino
		while (fscanf (arqO, "%c", &caracter) != EOF)   //eof - end of file
		{
			fprintf (arqD, "%c", caracter);
		}
		
		//fechando os arquivos
		fclose (arqO);
		fclose (arqD);
		
		return 1;
	}
}
