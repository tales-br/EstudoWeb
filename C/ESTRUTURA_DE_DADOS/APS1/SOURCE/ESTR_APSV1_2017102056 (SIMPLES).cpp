//Problema

/*
01- Elabore um algoritmo em DEV C++ (C) que possibilite montar uma LISTA, uma
FILA e uma PILHA. O usu�rio escolhe que estrutura deseja montar.
IMPLEMENTA��O - VETOR DE 10 POSI��ES DE INTEIRO.
*/



//"REQUISITOS"


	//ESPECIFICA��O DAS ESTRUTURAS
	
		
		//LISTA
		
			/*
			Opera��es
			� Inser��o - ordenada de acordo com o valor inserido
			� Exclus�o - realoca os valores da LISTA ap�s a exclus�o. O usu�rio informa o
			valor a ser exclu�do.
			
			Controles
			� Inclus�o - verificar se a LISTA est� CHEIA
			� Exclus�o - verificar se a LISTA est� VAZIA ou se o elemento a ser exclu�do N�O
			EXISTE na LISTA.
			*/
		
		
		//FILA
		
			/*
			Opera��es
			� Inser��o - sempre no FINAL
			� Exclus�o - sempre no TOPO
			
			Controles
			� Inclus�o - verificar se a FILA est� CHEIA
			� Exclus�o - verificar se a FILA est� VAZIA
			*/
		
		
		//PILHA
		
			/*
			Opera��es
			� Inser��o - sempre no TOPO
			� Exclus�o - sempre no TOPO
			
			Controles
			� Inclus�o - verificar se a PILHA CHEIA
			� Exclus�o - verificar se a PILHA est� VAZIA
			*/
		
	



//INFO:

/*
Start: 29/03/2022
End: 31/03/2022
Author: Tales Barbosa Rodrigues
Github: github.com/tales-br/Estudos/C
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 10

int fila[MAX];
int pilha[MAX];
int lista[MAX];

typedef enum opt
{
	PRIM, ULT, PESQ
}Opt;


int main ()
{
	cout<<"Alo mundo";
}
