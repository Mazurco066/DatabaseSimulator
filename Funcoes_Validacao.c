#include <stdio.h>
#include <ctype.h>

/*********************************************************************************************************************/

//Variáveis Globais
extern char rg[13];
extern char nome[51];
extern char telefone[11];
extern char idade[4];
//Variáveis Globais

/*********************************************************************************************************************/

//Funções Globais
void ler_rg(char *s){   //Validação para RG

    int i = 0;
    int cont = 0;
    char *verificacao = s;
    char c;
    printf("\n[+]Entre com o RG -> ");
    do{
    fflush(stdin);
    c = getch();

        if(isdigit(c) != 0 && cont <= 8){

                rg[i] = c;
                printf("%c", rg[i]);
                i++;
                cont++;
                verificacao++;
                rg[i] = '\0';
        }
        else if(c==8&&i){

                i--;
                cont--;
                verificacao--;
                rg[i] = '\0';
                printf("\b \b");
        }

    }while(c != 13 || verificacao == &s[0]);

    for (i = 0; i <= strlen(rg); i++){
        s[i] = rg[i];
    }
}

/*********************************************************************************************************************/

void ler_nome(char *s){ //Validação para nome

    int i = 0;
    int cont = 0;
    char *verificacao = s;
    char c;
    printf("\n[+]Entre com o nome -> ");
    do{
    fflush(stdin);
    c = getch();

        if((isalpha(c) != 0 || c == 32) && cont <= 40){

            if (i == 0 && c == 32){

            }
            else{
                nome[i] = toupper(c);
                printf("%c", nome[i]);
                i++;
                cont++;
                verificacao++;
                nome[i] = '\0';
            }
        }
        else if(c==8&&i){

            i--;
            cont--;
            verificacao--;
            nome[i] = '\0';
            printf("\b \b");
        }

    }while(c != 13 || verificacao == &s[0]);

    for (i = 0; i <= strlen(nome); i++){
        s[i] = nome[i];
    }
}

/*********************************************************************************************************************/

void ler_telefone(char *s){ //Validação para telefone

    int i = 0;
    int cont = 0;
    char *verificacao = s;
    char c;
    printf("\n[+]Entre com o telefone -> ");
    do{
    fflush(stdin);
    c = getch();

        if((isdigit(c) != 0 || c == 32) && cont <= 10){

            telefone[i] = c;
            printf("%c", telefone[i]);
            i++;
            cont++;
            verificacao++;
            telefone[i] = '\0';
        }
        else if(c==8&&i){

            i--;
            cont--;
            verificacao--;
            telefone[i] = '\0';
            printf("\b \b");
        }

    }while(c != 13 || verificacao == &s[0]);

    for (i = 0; i <= strlen(telefone); i++){
        s[i] = telefone[i];
    }
}

/*********************************************************************************************************************/

void ler_idade(char *s){ //Validação para telefone

    int i = 0;
    int cont = 0;
    char *verificacao = s;
    char c;
    printf("\n[+]Entre com a Idade -> ");
    do{
    fflush(stdin);
    c = getch();

        if((isdigit(c) != 0) && cont <= 2){

            idade[i] = c;
            printf("%c", idade[i]);
            i++;
            cont++;
            verificacao++;
            idade[i] = '\0';
        }
        else if(c==8&&i){

            i--;
            cont--;
            verificacao--;
            idade[i] = '\0';
            printf("\b \b");
        }

    }while(c != 13 || verificacao == &s[0]);

    for (i = 0; i <= strlen(idade); i++){
        s[i] = idade[i];
    }
}
//Funções Globais

/*********************************************************************************************************************/
