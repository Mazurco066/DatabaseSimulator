#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funcoes_mn.h"
#include "Funcoes_Validacao.h"
#include "Funcoes_ld.h"
#include "Funcoes_ldl.h"
#include "Funcoes_ab.h"

/*
VISÃO GERAL DO PROGRAMA - SIMULAÇÃO BANCO DE DADOS
[uso] Inserção de Dados, Impressão e Remoção via Menu Dinamico
[modo de uso] Seta pra baixo (Menu pra baixo), Seta pra cima (Menu pra cima), Enter (Confirmar), Esc (Sair)
[escrito por] mazurco066 (Gabriel Mazurco Ribeiro)
[email] mazurco066@gmail.com
[membros grupo] Gabriel Ribeiro, Eduardo Secolin
.......
.......
[objetivo] Simulação de um Banco de Dados com lista dinamica, lista duplamente ligada e arvore binaria
[arquitetura] Esse é um projeto modullarizado em 5 bibliotecas
*/

/*
BUGS E CORREÇÕES PENDENTES
[+]NENHUM BUG ENCONTRADO RECENTEMENTE
*/

/*********************************************************************************************************************/

int main(){

    resolucao();    //ajusta resolução do programa

    ld_lista = malloc(4 * sizeof(struct ld_no));    //inicia lista

    textcolor(15);  //set cor principal do texto

    inicios();

    do{
        menu_principal();   //loop principal do programa
    }while (mn_sair != 1);

    ld_finalizar();
    ldl_finalizar();
    ab_finalizar(inicio);

    return 0;
}

/*********************************************************************************************************************/
