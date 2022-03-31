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
End: 30/03/2022
Author: Tales Barbosa Rodrigues
Github: github.com/tales-br/Estudos/C
*/


//TO DO:

/*
Relembrar 
	struct (ok)
	ponteiro (ok)
	Ler artigo: https://www.ic.unicamp.br/~ra069320/PED/MC102/1s2008/Apostilas/Cap10.pdf (ok)
	
Definir quais as fun��es vou usar (Ok)
Layout do menu igual a da prog. estrutura? N (Novo Menu)
*/


//OBS:

	//Decidi usar a abordagem de lista encadeada, ao inv�s de vetores. Queria usar algo mais complexo, que poderia ser mais �til no meu aprendizado.
/*
Carta ao estimado professor(kkk):
Reli todos os slides e invariavelmente fiz pesquisas na internet.
Usei a apostila do sr. para me basear, mas mesmo assim fiquei com d�vidas de implementa��o (ainda mais pq n�o usei as biblotecas do C++ que s�o quase um "hack" para esse trabalho kkk).
Achei um artigo da puc rio fant�stico ensinando a implementar listas encadeadas em C. N�o cai na tenta��o de CTRL+C e CTRL+V. Li, entendi e implementei.
Segue o link: https://www.ic.unicamp.br/~ra069320/PED/MC102/1s2008/Apostilas/Cap10.pdf ((ACESSADO EM 30/03/2022))
Por favor n�o reduza minha nota kkkkkkk
Forte ab�
*/



#include <iostream>
#include <stdlib.h>

//vontade de usar as bibliotecas de lista, fila e pilha do c++ kkKkKkK

const int Max = 10;


using namespace std;



//j� define como um tipo de dado para usar no futuro
typedef struct lista
{
	
	struct lista *nxt;
	int vlr;
	int qntd_elementos;
	
}Estrutura;



//Protótipos
Estrutura* start_estrutura (void); //tipo lista que retorna NULL (Estrutura* representa o primeiro elemento deste tipo)

Estrutura* insere_prim (Estrutura* e, int novoInteiro); //ponteiro para estrutura (que cai na primeira posicao) e aloca o espaco de uma estrutura e aponta

Estrutura* retira_prim (Estrutura* e);

Estrutura* retira_ult (Estrutura* e); 

Estrutura* pesq_retira (Estrutura* e, int v);

void mostra_estrutura (Estrutura* e);

int main()
{
	//O enunciado pediu para usar 3 estruturas diferentes... sen�o dava para usar uma s�
	Estrutura* pilha;
	
	pilha = start_estrutura (); // vai retornar NULL para a primeira posicao
	pilha = insere_prim(pilha, 10);
	
	mostra_estrutura (pilha);
	
	return 0;
}


//retorna null para a etrutura
Estrutura* start_estrutura (void)
{
	return NULL;
}


Estrutura* insere_prim (Estrutura* e, int novoInteiro)
{
	Estrutura* novo = (Estrutura*) malloc(sizeof(Estrutura));
	
	novo->vlr = novoInteiro;
	novo->nxt = e;
	
	return novo;
}


void mostra_estrutura (Estrutura* e)
{
	Estrutura* aux;
	
	for (aux = e; aux != NULL; aux = aux->nxt) //enquanto a variavel auxiliar n�o achar o NULL (�ltima posicao) ela recebe o ponteiro do prox
	{
		cout<<"vlr = "<<aux->vlr<<endl;
	}

}


Estrutura* pesq_retira (Estrutura* e, int v) 
{
	Estrutura* ant = NULL; //de cara o anterior tem que receber null para startar
	
	Estrutura* p = e; //aponta para o primeiro n� da lista (var�avel auxiliar pra percorrer)
	
	while (p != NULL && p->vlr!= v) 
	{
		ant = p;
		p = p->nxt;
	}
	
	if (p == NULL)
	{
		return e;	
	}

	
	if (ant == NULL)
	{
		
		e = p->nxt;
	
	}
	else
	{
		
		ant->nxt = p->nxt;
	
	}
	
	free(p);
	
	return e;
}

/*
	Como diria o s�bio:
	Algoritmos flutua acima do bem e do mau.
*/
