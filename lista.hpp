#ifndef LISTA_H
#define LISTA_H

#define MAXTAM 5 // Usado para definir quantidade maxima de projetos.
// #define INICIO 1
typedef int TChave;

typedef struct Tipoelemento *TApontador;

typedef struct TProjeto
{
    TChave id;     // codigo do projeto
    char nome[30]; // nome do projeto
    int horas;    // numero de horas trabalhas no projeto
};

typedef struct TListaSequencial // projeto
{
    TProjeto item[MAXTAM];
    int primeiro = 0;
    int ultimo = 0;
    int tamanho = 0;
};

typedef struct endfuncionario //dados do endereço do funcionario.
{
    char rua[50];
    int numCasa;
    char bairo[20];
    char cidade[20];
    char estado[20];
};

typedef struct TFuncionario // dados funcionario
{
    int id;
    char nome[30];
    int numero;                // codigo do funcionario
    int dependentes;           // numero de dependentes do funcionario
    TListaSequencial projetos; // Lista Sequencial que guarda os projetos nos quais o funcionario trabalha
    endfuncionario endereco;
};

typedef struct Tipoelemento // apontar funcionario
{
    TFuncionario item;
    TApontador prox;
};

typedef struct TListaEncadeada // posiÃ§oes do projeto
{
    TApontador primeiro;
    TApontador ultimo;
    int tamanho = 0;
};

bool Listacriada = false; // variavel setada com false apenas para conferir se a lista esta criada ou nao.

void menu();
void includeFuncionario(TFuncionario funcionario);

void CriaListaVazia(TListaEncadeada *lista);
bool Verifica_Lista_Encadeada_Vazia(TListaEncadeada *lista);
bool Verifica_Lista_Arranjo_Vazia(TListaSequencial *lista);
int TamanhoLista(TListaEncadeada *lista);
void InsereListaUltimo(TListaEncadeada *lista, TFuncionario *item);
void Imprime_Lista_Arranjo(TListaSequencial lista);

TApontador PesquisaItem(TListaEncadeada *lista, int id);
int PesquisaFuncionario(TListaEncadeada *lista, int id);
void RemoveItemPorId(TListaEncadeada *lista, int id);
int remove_Item_porID_Sequencial(TListaSequencial *lista, int id);
void IncludeProgetos(TListaEncadeada *projetos);
void Imprime_Contracheque(TListaEncadeada *lista);
void Excluir_Func_Sem_Projetos(TListaEncadeada *lista);
void Exclui_Projetos(TListaEncadeada *lista);
void Consulta_funcionario(TListaEncadeada *lista);
void Leitura_Arquivo(TListaEncadeada* listaFuncionarios);
void Inclui_Arquivo(TListaEncadeada* listaFuncionarios);
#endif