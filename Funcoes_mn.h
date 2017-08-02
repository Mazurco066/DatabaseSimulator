//Variáveis Globais
char mn_opcoes[7][43] = {"Inserir Registro\t      |","Remover Registro\t      |","Buscar Registro por RG       |","Listar Todos os Registros    |","Listar Reverso\t\t      |","Documentacao\t\t      |","Sair do Programa\t      |"};
int mn_sair = 0;
int mn_pos = 1;
char MiniDecisao;
int MiniPos = 1;
int MiniSair = 0;
//Variáveis Globais

//Menu
void documentacao();
void resolucao();
void enter(int posicao);    //função local de decisão
void inicios();             //função local de inicios possíveis
void menu_principal();      //função local de captação de teclas
void MiniEnter(int posicao);
void MiniInicios(int posicao);
void MiniCaptura();
//Menu
