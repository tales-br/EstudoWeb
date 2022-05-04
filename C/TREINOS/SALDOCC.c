/*[SALDOCC]

Considere um ambiente de transa��es bancarias. O programa deve processar um arquivo, em formato texto,
com movimenta��es financeiras realizadas em contas correntes (cr�ditos e d�bitos).
Cada linha desse arquivo cont�m uma transa��o de cr�dito ou d�bito para/de uma conta corrente.
Transa��o = {  Conta Corrente + Valor Transa��o }
Conta Corrente * n�mero inteiro de at� 2 posi��es, formato com zeros � esquerda *
Valor Transa��o * Valor num�rico, com separador de casa decimal, com o seguinte formato: *
*sinal ( - ou +), parte inteira com at� 5 d�gitos formatado com zeros � esquerda, *
* ponto e parte decimal com 2 d�gitos formatado com zeros � direita *
Considere que todas as contas correntes (no m�ximo 100 contas correntes) possuem,
no momento inicial, saldo zero. Processe cada um dos registros de transa��o e informe,
ao t�rmino do processamento, o saldo de cada uma das contas.
Usando o arquivo de transa��es contendo os registros mostrados anteriormente, o resultado ser�:
Exemplo de Arquivo TRANS.TXT:


01+00100.40
02+00050.05
01-00005.10
02+00050.06
09+43555.02
01-00006.00
03+00010.03
04-00100.54
01-00008.22
04+00050.87
07+00001.11
05+01300.03
05-00030.03
01-00001.22
08-01000.78
06+00044.00
07-00100.01

Resultado at� a conta 9:
C/C: 0 - Saldo:     0.00
C/C: 1 - Saldo:    79.86
C/C: 2 - Saldo:   100.11
C/C: 3 - Saldo:    10.03
C/C: 4 - Saldo:   -49.67
C/C: 5 - Saldo:  1270.00
C/C: 6 - Saldo:    44.00
C/C: 7 - Saldo:   -98.90
C/C: 8 - Saldo: -1000.78
C/C: 9 - Saldo: 43555.02
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
    float saldo_contas[100];
    int i=0,j=0,conta=0;
    float movimento=0;
    char info[11], cpInfo[11];

    FILE *arquivo;
    arquivo= fopen("TRANS.txt","rt");

    for(i=0;i<=99;i++) //limpa o vetor
    {
    saldo_contas[i]=0;
    }

    while(fgets(info,12,arquivo)!= NULL)
    {
        if(strlen(info)>10)//tivemos que por esse if... o fgets estava puxando valores aleatorios entre as linhas do texto !!(?)!! eu hein..
            {
            strcpy(cpInfo,"");//zera a string cpInfo (string temporaria)
            strncat(cpInfo,info,2);//pega os dois primeiros numeros e depois converte pra inteiro, armazenando no numero da conta
            conta=atoi(cpInfo);

            strcpy(cpInfo,"");
            j=0;
            for (i=2;i<=10;i++)//pula 2 casas da string (pois � onde fica a conta) e depois armazena todos os valores seguintes (valor da movimentacao)
            {
                cpInfo[j]=info[i];
                j=j+1;
            }

            movimento=atof(cpInfo);//converte pra float e armazena a movimentacao ((PROCEDIMENTO DISPENSAVEL))
            saldo_contas[conta]=saldo_contas[conta]+movimento;
            }
    }

    fclose(arquivo);

    for (i=0;i<100;i++)
    {
        printf("\nC/C: %i - Saldo:%.2f",i,saldo_contas[i]);
    }

    return 0;
}
