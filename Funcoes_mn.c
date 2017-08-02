#include <stdio.h>
#include <windows.h>

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
extern char mn_opcoes[7][43];
extern mn_sair;
extern mn_pos;
extern ld_posicao;
extern char MiniDecisao;
extern int MiniPos;
extern int MiniSair;
//Variáveis Globais

/*********************************************************************************************************************/

//Chamadas Recursivas
extern struct ld_no *ld_lista;
extern struct ab_no *inicio;
extern void ld_adicionar(int posicao, char dado[]);
extern void ldl_listar();
extern void ldl_excluir_no(char dado[], int Indice);
extern void ab_excluir(char dado[]);
extern struct ab_no *ab_busca(struct ab_no *aux, char dado[]);
extern void ler_rg(char *s);
//Chamadas Recursivas

/*********************************************************************************************************************/

//Função visual de cores de texto
typedef enum{BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,LIGHTGRAY,DARKGRAY,
LIGHTBLUE,LIGHTGREEN,LIGHTCYAN,LIGHTRED,LIGHTMAGENTA,YELLOW,WHITE} COLORS;

static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

void textcolor (int color)
{
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    color + (__BACKGROUND << 4));
}

/*********************************************************************************************************************/

//Funções Globais
void documentacao(){

    printf("\n\nVISAO GERAL DO PROGRAMA - SIMULACAO BANCO DE DADOS");
    printf("\n[+][uso] Inserção de Dados, Impressao e Remocao via Menu Dinamico");
    printf("\n[+][modo de uso] Seta pra baixo (Menu pra baixo), Seta pra cima (Menu pra \ncima), Enter (Confirmar), Esc (Sair)");
    printf("\n[+][escrito por] mazurco066 (Gabriel Mazurco Ribeiro)");
    printf("\n[+][email] mazurco066@gmail.com");
    printf("\n. . . .");
    printf("\n. . . .");
    printf("\n[+][objetivo] Simulacao de um Banco de Dados com lista dinamica, lista \nduplamente ligada e arvore binaria");
    printf("\n[+][arquitetura] Esse é um projeto modullarizado em 5 bibliotecas");
    printf("\n\n");
    system("pause");
}

/*********************************************************************************************************************/

void resolucao(){

    //system("mode con:cols=80 lines=30");
}

/*********************************************************************************************************************/

void enter(int posicao){    //menu ao pressionar a tecla enter / decisão

    if (posicao == 1){  //Adicionar

        char Bsc_rg[13];
        ler_rg(Bsc_rg);
        struct ab_no *pesquisa;
        if (inicio != 0){
        pesquisa = ab_busca(inicio, Bsc_rg);
        }

        if (inicio == 0){

            ld_adicionar(ld_posicao, Bsc_rg);
        }
        else if (pesquisa != 0){

            printf("\n\n[+]Esse RG ja existe no Sistema . . . .\n[+]Cadastre novamente com um RG nao cadastrado\n\n");
            system("pause");
        }
        else{

            ld_adicionar(ld_posicao, Bsc_rg);
        }
    }
    else if(posicao == 2){  //Exclusão

        char bsc_rg[13];    //String de Busca

        if (inicio == 0){

            printf("\n[+]Nao ha nada para se excluir!\n\n");
            system("pause");
        }
        else{

            ler_rg(bsc_rg);     //método novo com validação

            int bsc_pos;
            struct ab_no *result;
            result = ab_busca(inicio, bsc_rg);

            if(result == 0){

                printf("\n[+]Impossivel Excluir, esse registro nao existe!\n\n");
                system("pause");
            }
            else{

                //Verificação de Segurança
                system("cls");
                printf("\n[+]Tem Certeza que deseja Excluir?\n\n");
                MiniInicios(MiniPos);
                do{
                    MiniCaptura();
                }while(MiniSair != 1);

                if (MiniDecisao == 'S'){

                    bsc_pos = result->posicao;
                    ldl_excluir_no(ld_lista[bsc_pos].nome, bsc_pos);
                    ab_excluir(bsc_rg);

                    //Resetando Valores
                    MiniDecisao = ' ';
                    MiniPos = 1;
                    MiniSair = 0;
                }
                else{
                    //Nada Acontece mais reseta valores
                    MiniDecisao = ' ';
                    MiniPos = 1;
                    MiniSair = 0;
                }
                //Verificação de Segurança
            }
        }
    }
    else if(posicao == 3){  //Buscar

        char bsc_rg[13];    //string de busca

        if (inicio == 0){

                printf("\n[+]Nao ha nada para se buscar!\n\n");
                system("pause");
        }
        else{

                ler_rg(bsc_rg);     //método novo com validação

                if (ab_busca(inicio, bsc_rg) == 0){

                    printf("\n[+]Dado nao encontrado!\n\n");
                    system("pause");
                }
                else{

                    struct ab_no *resultado;
                    int indice;
                    resultado = ab_busca(inicio, bsc_rg);
                    indice = resultado->posicao;
                    printf("\n[+]DADO ENCONTRADO\n\n[+]--------------------------------------------------------------------[+]\n");
                    printf("RG: %s\n", ld_lista[indice].rg);
                    printf("Nome: %s\n", ld_lista[indice].nome);
                    printf("Telefone: %s\n", ld_lista[indice].telefone);
                    printf("Idade: %s\n", ld_lista[indice].idade);
                    printf("[+]--------------------------------------------------------------------[+]\n\n");
                    system("pause");
                }
        }
    }
    else if(posicao == 4){  //Listar

        ldl_listar();
        system("pause");
    }
    else if(posicao == 5){  //Listar Reverso

        ldl_listar_reverso();
        system("pause");
    }
    else if(posicao == 6){  //Documentação

        documentacao();
    }
    else if(posicao == 7){  //Sair

        mn_sair = 1;
    }

}

/*********************************************************************************************************************/

void inicios(){ //possibilidades do menu

    int i;

    system("cls");

    printf("[+]Simulador de um Banco de Dados - by Mazurco066 (Gabriel ribeiro)\n");
    printf("[+]Pressione seta para baixo, seta para cima, enter e esc para navegar\n\n");
    printf("\t\t    [+]-----------------------------[+]\n\t\t    |\t\t\t\t      |\n");

    for (i = 1; i <=7; i++){

            if (mn_pos == i){
                printf("\t\t    |");
                textcolor(2);
                printf(" ->");
                textcolor(15);
                printf(" %s \n", &mn_opcoes[i - 1]);
            }
            else{
                printf("\t\t    |    %s \n", &mn_opcoes[i - 1]);
            }

    }
    printf("\t\t    |\t\t\t\t      |\n\t\t    [+]-----------------------------[+]\n");

}

/*********************************************************************************************************************/

void menu_principal(){  //captura de teclas

    int ch;
    ch=getch();
    if (ch== 27){  //esc
        mn_sair = 1;
    }
    else if (ch==13){   // enter
        enter(mn_pos);
    }
    if (ch==72){    //acima
        mn_pos--;
        if (mn_pos < 1){
            mn_pos = 7;
        }
    }
    else if (ch==80){   //abaixo
        mn_pos++;
        if(mn_pos > 7){
            mn_pos = 1;
        }
    }

    //impressão
    inicios();
}
//Funções Globais

/*********************************************************************************************************************/

void MiniEnter(int posicao){

    if (posicao == 1){

        MiniDecisao = 'S';
        MiniSair = 1;
    }
    else{

        MiniDecisao = 'N';
        MiniSair = 1;
    }
}

/*********************************************************************************************************************/

void MiniInicios(int posicao){

    if (posicao == 1){

        textcolor(2);
        printf(" ->");
        textcolor(15);
        printf(" Sim\n");
        printf("    Nao\n");
    }
    else{

        printf("    Sim\n");
        textcolor(2);
        printf(" ->");
        textcolor(15);
        printf(" Nao\n");
    }
}

/*********************************************************************************************************************/

void MiniCaptura(){

    int ch;
    ch=getch();

    if (ch==13){   // enter
        MiniEnter(MiniPos);
    }
    if (ch==72){    //acima
        MiniPos--;
        if (MiniPos < 1){
            MiniPos = 2;
        }
    }
    else if (ch==80){   //abaixo
        MiniPos++;
        if(MiniPos > 2){
            MiniPos = 1;
        }
    }

    //impressão
    system("cls");
    printf("\n[+]Tem Certeza que deseja Excluir?\n\n");
    MiniInicios(MiniPos);
}

/*********************************************************************************************************************/
