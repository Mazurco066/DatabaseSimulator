#include <stdio.h>

/*********************************************************************************************************************/

//Definição de Dados
extern struct ld_no{   //struct de um nó de uma lista dinamica
    char rg[13];    //id da struct
    char nome[51];
    char telefone[11];
    char idade[4];
};

extern struct ab_no{   //struct de um nó de uma arvore binaria
    struct ab_no *esquerda;
    char rg[13];    //id da struct
    int posicao;
    struct ab_no *direita;
};
//Definição de Dados

/*********************************************************************************************************************/

//Variáveis Globais
extern struct ld_no *ld_lista;
extern int ld_tamanho;
extern int ld_posicao;
//Variáveis Globais

/*********************************************************************************************************************/

//Chamadas Recursivas
extern struct ab_no *inicio;
extern ldl_adicionar_no(char dado[], char dado2[], int posi);
extern struct ab_no *ab_novo_no(char dado[], int posicao);
extern ab_adicionar(struct ab_no *aux, struct ab_no *add);
extern void ler_rg(char *s);
extern void ler_nome(char *s);
extern void ler_telefone(char *s);
//Chemadas Recursivas

/*********************************************************************************************************************/

//Funções Globais
void ld_adicionar(int posicao, char dado[]){ //ok - insere um novo registro na lista de dados

    if (posicao == ld_tamanho){
        ld_ExpandirLista();
        ld_adicionar(ld_posicao, dado);
    }
    else{

        strcpy(ld_lista[posicao].rg, dado);
        ler_nome(ld_lista[posicao].nome);
        ler_telefone(ld_lista[posicao].telefone);
        ler_idade(ld_lista[posicao].idade);

        //Chamadas Recursivas
        ldl_adicionar_no(ld_lista[posicao].rg, ld_lista[posicao].nome, posicao);
        ab_adicionar(inicio, ab_novo_no(ld_lista[posicao].rg, posicao));
        //Chamadas Recursivas

        ld_posicao++;
    }

}

/*********************************************************************************************************************/

int ld_quantidade(){  //ok - para ver qnts elementos estão resgistrados

    return ld_posicao;
}

/*********************************************************************************************************************/

int ld_IndiceValido(int indice){   //ok - para verificar se o indice especificado existe

    if(indice > 0 && indice < ld_posicao){

        return 1;
    }
    else{

        return 0;
    }
}

/*********************************************************************************************************************/

void ld_excluir(int indice){   //pendente - para excluir um registro da lista de dados

    int i;

    for (i = indice; i < ld_posicao; i++){

        ld_lista[i] = ld_lista[i + 1];
    }
    ld_posicao--;
}

/*********************************************************************************************************************/

void ld_ExpandirLista(){   //ok - para alocar mais posições para lista de dados

    int i;
    struct ld_no *l2;
    int Tam;

    Tam = ld_tamanho + (ld_tamanho/2);

    l2 = malloc(Tam* sizeof(struct ld_no));
    if (!l2){
        printf("\n Nao foi possivel alocar a memoria!\n\n ");
        system("pause");
        exit(-1);
    }

    for (i = 0; i < ld_posicao; i++){
        l2[i] = ld_lista[i];
    }

    free(ld_lista);
    ld_lista = l2;

    ld_tamanho = Tam;
}

/*********************************************************************************************************************/

void ld_finalizar(){    //ok - desaloca todos registros

    free(ld_lista);
}
//Funções Globais

/*********************************************************************************************************************/
