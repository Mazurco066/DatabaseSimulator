/*********************************************************************************************************************/

//Definição de Dados
extern struct ab_no{   //struct de um nó de uma arvore binaria
    struct ab_no *esquerda;
    char rg[13];    //id da struct
    int posicao;
    struct ab_no *direita;
};
//Definição de Dados

/*********************************************************************************************************************/

//Variáveis globais
extern struct ab_no *inicio;
extern struct ab_no *novo;
extern struct ab_no *anterior;
extern struct ab_no *auxiliar;
extern char ab_ultimo_movimento;
//Variáveis Globais

/*********************************************************************************************************************/

//Funções Globais
struct ab_no *ab_novo_no(char dado[], int posicao){  //ok - aloca uma nova posição na memoria para a lista

    struct ab_no *n;
    n = malloc(sizeof(struct ab_no));   //aloca memoria do tamanho da struct lista
    if(!n)                              //lista não foi alocada
    {
        printf("Nao consegui alocar memoria!\n");   //mensagem de erro
        exit(-1);                                   //saída do programa
    }

    n->esquerda = 0;    //setando posição esquerda para inativa
    n->direita = 0;     //setando posição direita para inativa
    strcpy(n->rg, dado);
    n->posicao = posicao;     //setando o indice para o dado informado

    return n;
}

/*********************************************************************************************************************/

void ab_adicionar(struct ab_no *aux, struct ab_no *add){   //ok - parametros = posição inicial e a nova posição alocada

    if(inicio == 0){    //primeira vez inserindo um elemento

        inicio = add;   //inicia a lista
    }
    else{

        if (aux->esquerda == 0 && atoi(add->rg) < atoi(aux->rg)){ //verifica se posição esquerda esta vazia

            aux->esquerda = add;    //se sim posição esquerda recebe nova alocação
            return;
        }
        if (aux->direita == 0 && atoi(add->rg) > atoi(aux->rg)){  //verifica se posição direita esta vazia

            aux->direita = add;     //se sim posição direita recebe nova alocação
            return;
        }

        if (atoi(add->rg) < atoi(aux->rg)){    //verifica se dado vai pra esquerda
            aux = aux->esquerda;       //variavel auxiliar recebe proxima posição para refazer as verifcações
            ab_adicionar(aux, add);       //chamada recursiva da função adicionar ate achar uma posição vazia
        }

        if (atoi(add->rg) > atoi(aux->rg)){    //verifica se dado vai pra direita
            aux = aux->direita;
            ab_adicionar(aux, add);
        }
    }
}

/*********************************************************************************************************************/

struct ab_no *ab_busca(struct ab_no *aux, char dado[]){ //ok - busca um registro na arvore binária

    if (inicio == 0){   //quando não ha nada cadastrado

        printf("\n Não ha elementos na lista para se buscar!\n\n ");    //mensagem de erro
        system("pause");
        return 0;  //saída da função
    }
    else{

        if (strcmp(dado, aux->rg) == 0){ //dado encontrado

            return aux;   //retornando dado
        }
        else{

            if (aux->esquerda != 0 && atoi(dado) < atoi(aux->rg)){    //caso não seja o dado procurar para esquerda

                anterior = aux; //váriável para uso na função excluir
                ab_ultimo_movimento = 'E'; //variável para uso na função excluir
                aux = aux->esquerda;    //setando posição para esquerda
                return ab_busca(aux, dado);    //chamada recursiva da função
            }

            if (aux->direita != 0 && atoi(dado) > atoi(aux->rg)){ //caso não seja o dado procurar para direita

                anterior = aux; //variável para uso na função excluir
                ab_ultimo_movimento = 'D'; //variável para uso na função excluir
                aux = aux->direita; //setando posição para esquerda
                return ab_busca(aux, dado);    //chamada recursiva da função
            }

        }

        return 0;   //caso não encontre o dado

    }
}

/*********************************************************************************************************************/

void ab_excluir(char dado[]){  //ok - Libera da memória uma posição da estrutura

    auxiliar = ab_busca(inicio, dado); //variável equivalente ao dado encontrado
    if(auxiliar == 0){  //caso o dado não seja encontrado

        printf("\n[+]Impossivel excluir, registro nao existe!\n\n"); //mensagem de erro!
        system("pause");
    }
    else{   //caso encontre corretamente

        if(auxiliar == inicio)  //caso de dado ser igual ao dado inicial da arvore binária
        {
            inicio = 0; //desabilitando inicio da arvore
            if(auxiliar->esquerda != 0){    //inserindo novamente ramificação esquerda

                ab_adicionar(inicio, auxiliar->esquerda);  //chamada recursiva da função
            }
            if(auxiliar->direita != 0){ //inserindo novamente ramificação direita

                ab_adicionar(inicio, auxiliar->direita);   //chamada recursiva da função
            }
            free(auxiliar); //desalocando a posição equivalente ao dado encontrado

            printf("\n[+]Excluido com Sucesso!\n\n");    //mensagem de sucesso!
            system("pause");
        }
        else
        {
            if(ab_ultimo_movimento == 'D'){    //verificação do lado da ramificação equivalente

                anterior->direita = 0;  //desabilitando posição para reinserção de dados
            }
            else{

                anterior->esquerda = 0;     //desabilitando posição para reinserção de dados
            }

            if(auxiliar->esquerda != 0){    //caso posição esquerda tenha dados

                ab_adicionar(inicio, auxiliar->esquerda);  //reinserindo posição esquerda
            }
            if(auxiliar->direita != 0){ //caso posição direita tenha dados

                ab_adicionar(inicio, auxiliar->direita);   //reinserindo ramificação direita
            }
            free(auxiliar); //desalocando a posição equivalente ao dado encontrado

            printf("\n[+]Excluido com Sucesso!\n\n");    //mensagem de sucesso!
            system("pause");
        }
    }
}

/*********************************************************************************************************************/

void ab_finalizar(struct ab_no *aux){  //ok - desaloca todas posições da arvore binária

    if(aux != 0){

            if (aux->esquerda != 0){

                ab_finalizar(aux->esquerda);
            }

            if (aux->direita != 0){

                ab_finalizar(aux->direita);
            }

            free(aux);
    }

}
//Funções Globais

/*********************************************************************************************************************/
