/*********************************************************************************************************************/

//Definição de Dados
extern struct ldl_no{  //struct de um nó de uma lista duplamente ligada
    struct ldl_no *anterior;
    //char rg[13];
    char nome[51];  //id da struct
    int posicao;
    struct ldl_no *proximo;
};

extern struct ld_no{   //struct de um nó de uma lista dinamica
    char rg[13];    //id da struct
    char nome[51];
    char telefone[11];
    char idade[4];
};
//Definição de Dados

/*********************************************************************************************************************/

//Variáveis Globais
extern struct ldl_no *ldl_inicio;
extern struct ldl_no *ldl_aux;
extern struct ldl_no *ldl_novo;
extern struct ldl_no *ldl_antes;
//Variáveis Globais

/*********************************************************************************************************************/

//Chamadas Recursivas
extern struct ld_no *ld_lista;
//Chamadas Recursivas

/*********************************************************************************************************************/

//Funções Globais
struct ldl_no *ldl_novo_no(char dado[], char dado2[], int pos){    //ok - aloca memória para um novo nó

    struct ldl_no *n;
    n = malloc(sizeof(struct ldl_no));
    if(!n)
    {
        printf("\n não foi possivel alocar memoria!\n\n ");
        system("pause");
        exit(-1);
    }

    n->proximo = 0;
    //strcpy(n->rg, dado);
    strcpy(n->nome, dado2);
    n->posicao = pos;
    n->anterior = 0;

    return n;
}

/*********************************************************************************************************************/

int menorRG(char nome1[], char nome2[]){

    int i;

    for (i = 0; i <=strlen(nome1); i++){

        if(strcmp(nome1, nome2) < 0){
            return 1;
        }

        if(strcmp(nome1, nome2) > 0){
            return -1;
        }

    }

    return 0;
}

/*********************************************************************************************************************/

void ldl_adicionar_no_inicio(){ //ok - ligará o nó no inicio

    ldl_novo->proximo = ldl_inicio;
    ldl_inicio = ldl_novo;
    ldl_novo->proximo->anterior = ldl_novo;

    //printf("\n[+]Adicionado com Sucesso caso INICIO!\n\n ");
    //system("pause");
}

/*********************************************************************************************************************/

void ldl_adicionar_no_meio(){   //ok - ligará o nó no meio

    ldl_novo->proximo = ldl_aux;    //ligação nova
    ldl_novo->anterior = ldl_antes; //ligação nova
    ldl_antes->proximo = ldl_novo;  //religando elementos
    ldl_aux->anterior = ldl_novo;   //religando elementos

    //printf("\n[+]Adicionado com Sucesso caso MEIO!\n\n ");
    //system("pause");
}

/*********************************************************************************************************************/

void ldl_adicionar_no_fim(){    //ok - ligará o nó no fim

    ldl_aux->proximo = ldl_novo;
    ldl_novo->anterior = ldl_aux;


    //printf("\n[+]Adicionado com Sucesso caso FIM!\n\n ");
    //system("pause");
}

/*********************************************************************************************************************/

void ldl_adicionar_no(char dado[], char dado2[], int posi){   //ok - decosão para qual posição o nó ira se conectar

    ldl_novo = ldl_novo_no(dado, dado2,  posi);

    if(ldl_inicio == 0){
        ldl_inicio = ldl_novo;
        //printf("\n[+]Adicionado com sucesso caso INICIO!\n\n ");
        //system("pause");
    }
    else{
        // decisao para chamadas de funções de inserção de dados
        if(menorRG(dado2, ldl_inicio->nome) == 1 || strcmp(dado2, ldl_inicio->nome) == 0) {

            ldl_adicionar_no_inicio();
            }
            else{

            ldl_aux = ldl_inicio;
            ldl_antes = ldl_inicio;

            while(ldl_aux->proximo != 0 && menorRG(dado2, ldl_aux->nome) <= 0 ){

                ldl_antes = ldl_aux;
                ldl_aux = ldl_aux->proximo;
            }
            if(ldl_aux->proximo == 0 && menorRG(dado2, ldl_aux->nome) == -1){

                ldl_adicionar_no_fim();
            }
            else{

                ldl_adicionar_no_meio();
            }
        }
    }
    //decisao para chamadas de funções de inserção de dados
}

/*********************************************************************************************************************/

void ldl_excluir_no_inicio(){   //ok

    if (ldl_inicio->proximo ==0){

        free(ldl_inicio);
        ldl_inicio=0;
    }
    else{

        ldl_aux = ldl_inicio->proximo;
        ldl_inicio->proximo->anterior = 0;  //setando proximo para inicio
        free(ldl_inicio);
        ldl_inicio = ldl_aux;
    }

    //printf("\n Excluido com Sucesso caso INICIO! \n\n ");
    //system("pause");
}

/*********************************************************************************************************************/

void ldl_excluir_no_meio(){ //ok


    ldl_aux->anterior->proximo = ldl_aux->proximo;
    ldl_aux->proximo->anterior = ldl_aux->anterior;
    free(ldl_aux);

    //printf("\n Excluido com Sucesso caso MEIO! \n\n ");
    //system("pause");
}

/*********************************************************************************************************************/

void ldl_excluir_no_fim(){  //ok

    ldl_aux = ldl_aux->anterior;    //bug do excluir : corrigido na chamada do excluir
    free(ldl_aux->proximo);
    ldl_aux->proximo = 0;

    //printf("\n Excluido com Sucesso caso FIM! \n\n ");
    //system("pause");
}

/*********************************************************************************************************************/

void ldl_excluir_no(char dado[], int Indice){  //ok

    if (ldl_inicio == 0){

        printf("\n Nao ha nada para excluir!\n\n ");
        system("pause");
        return;
    }
    else{

    if(strcmp(ldl_inicio->nome, dado) == 0 && ldl_inicio->posicao == Indice){

            ldl_excluir_no_inicio();
            }
            else{

            ldl_aux = ldl_inicio;

            while(ldl_aux->proximo != 0 && (strcmp(ldl_aux->nome, dado) <= 0 && ldl_aux->posicao != Indice)){

                //Procura pela struct desejada
                ldl_aux = ldl_aux->proximo;
            }

            if (strcmp(ldl_aux->nome, dado) == 0 && ldl_aux->posicao == Indice){

                //Ver se é caso fim ou meio
                if (ldl_aux->proximo == 0){ //ponto de backup

                        ldl_excluir_no_fim();   //chamada caso fim

                }
                else{

                    ldl_excluir_no_meio();  //chamada caso fim
                }
                //Ver se é caso fim ou meio

            }
            else{

                //Dado não encontrado
            }
        }
    }
}

/*********************************************************************************************************************/

void ldl_listar(){  //ok - lista todos os registros cadastrados

    printf("\n\n");

    if(ldl_inicio != 0){

        printf("[+]Listando Registros . . . .\n\n");
        printf("[+]--------------------------------------------------------------------[+]\n");
        ldl_aux = ldl_inicio;
        while(ldl_aux->proximo != 0){

            printf("[+]RG: %s \n", ld_lista[ldl_aux->posicao].rg);
            printf("[+]Nome: %s \n", ld_lista[ldl_aux->posicao].nome);
            printf("[+]Telefone: %s \n", ld_lista[ldl_aux->posicao].telefone);
            printf("[+]Idade: %s \n", ld_lista[ldl_aux->posicao].idade);
            printf("[+]--------------------------------------------------------------------[+]\n");
            ldl_aux = ldl_aux->proximo;
        }
        printf("[+]RG: %s \n", ld_lista[ldl_aux->posicao].rg);
        printf("[+]Nome: %s \n", ld_lista[ldl_aux->posicao].nome);
        printf("[+]Telefone: %s \n", ld_lista[ldl_aux->posicao].telefone);
        printf("[+]Idade: %s \n", ld_lista[ldl_aux->posicao].idade);
        printf("[+]--------------------------------------------------------------------[+]");
    }
    else{
        printf("[+]Nao ha Registros Disponiveis!\n");
    }

    printf("\n\n");
}

/*********************************************************************************************************************/

void ldl_listar_reverso(){

    printf("\n\n");

    if(ldl_inicio != 0){

        printf("[+]Listando Registros . . . .\n\n");
        printf("[+]--------------------------------------------------------------------[+]\n");
        ldl_aux = ldl_inicio;

        while(ldl_aux->proximo != 0){

            if (ldl_aux->proximo == 0){

                break;
            }

            ldl_aux = ldl_aux->proximo;
        }
        while(ldl_aux->anterior != 0){

            printf("[+]RG: %s \n", ld_lista[ldl_aux->posicao].rg);
            printf("[+]Nome: %s \n", ld_lista[ldl_aux->posicao].nome);
            printf("[+]Telefone: %s \n", ld_lista[ldl_aux->posicao].telefone);
            printf("[+]Idade: %s \n", ld_lista[ldl_aux->posicao].idade);
            printf("[+]--------------------------------------------------------------------[+]\n");
            ldl_aux = ldl_aux->anterior;
        }
        printf("[+]RG: %s \n", ld_lista[ldl_aux->posicao].rg);
        printf("[+]Nome: %s \n", ld_lista[ldl_aux->posicao].nome);
        printf("[+]Telefone: %s \n", ld_lista[ldl_aux->posicao].telefone);
        printf("[+]Idade: %s \n", ld_lista[ldl_aux->posicao].idade);
        printf("[+]--------------------------------------------------------------------[+]");
    }
    else{
        printf("[+]Nao ha Registros Disponiveis!\n");
    }

    printf("\n\n");
}

/*********************************************************************************************************************/

void ldl_finalizar(){   //ok - verifica se é necessário desalocar a memória

    if(ldl_inicio != 0)
    {
        ldl_finalizar_elemento(ldl_inicio);
        ldl_inicio = 0;
    }
}

/*********************************************************************************************************************/

void ldl_finalizar_elemento(struct ldl_no *elemento){    //ok - libera memória de um nó

    if(elemento->proximo != 0)
        ldl_finalizar_elemento(elemento->proximo);
    free(elemento);
}
//Funções Globais

/*********************************************************************************************************************/
