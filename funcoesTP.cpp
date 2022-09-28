#include <iostream>
#include <windows.h>
#include "lista.hpp"

#define MAXTAM 5

using namespace std;
void menu() // Menu inical do programa
{
    cout << " _________________________________________________________ " << endl;
    cout << "|                                                         | " << endl;
    cout << "|      Bem-vindo ao menu de cadastro de funcionarios      |" << endl;
    cout << "|                                                         | " << endl;
    cout << "|_________________________________________________________| " << endl
         << endl
         << endl;
    cout << " Insira a opcao desejada: (1 ao 6) " << endl;
    cout << "1 Inclusao de um novo funcionario. " << endl;
    cout << "2 Inclusao de novos projetos para um funcionario. " << endl;
    cout << "3 Exclusao de projetos de um funcionario. " << endl;
    cout << "4 Exclusao de um funcionario que nao trabalha em nenhum projeto. " << endl;
    cout << "5 Consulta de um funcionario. " << endl;
    cout << "6 Imprime contra-cheque. " << endl;
    cout << "7. Sair. " << endl;
}

void includeFuncionario(TListaEncadeada *lista) // Cadastro dos novos funcionarios
{
    TFuncionario funcionario;
    TProjeto projeto;
    char op;
    cout << " _______________________________ " << endl;
    cout << "|                               |" << endl;
    cout << "|       Novo Funionario         |" << endl;
    cout << "|                               |" << endl;
    cout << "|_______________________________|" << endl
         << endl
         << endl;
    cout << "Insira nome do funcionario: " << endl;
    cin.ignore();
    cin.getline(funcionario.nome, 30);

    cout << "Insira ID do funcionario: (Apenas Numeros)" << endl;
    cin >> funcionario.id;
    cin.ignore();

    cout << "Insira rua: " << endl;

    cin.getline(funcionario.endereco.rua, 50);
    cout << "Insira bairro: " << endl;

    cin.getline(funcionario.endereco.bairo, 20);
    cout << "Insira cidade: " << endl;

    cin.getline(funcionario.endereco.cidade, 20);

    cout << "Insira numero da casa: (Apenas Numeros)" << endl;
    cin >> funcionario.endereco.numCasa;
    cin.ignore();

    cout << "Dependentes: (Apenas Numeros)" << endl;
    cin >> funcionario.dependentes;

    InsereListaUltimo(lista, &funcionario); // chamando funcao pra salvar os funcionarios cadastrado na lista

    cout << "Para incrementar projeto digite S: " << endl;
    cin >> op;

    while (op == 'S' || op == 's')
    {
        IncludeProgetos(lista);
        cout << endl
             << endl
             << "Para continuar incrementar projeto digite S: ";
        cin >> op;
    }

    system("cls");
}

void CriaListaVazia(TListaEncadeada *lista) // Funçao que tera a tarefa de guardar dados em list ao longo do progeto
{
    if (!Listacriada)
    {
        lista->primeiro = new Tipoelemento;
        lista->ultimo = lista->primeiro;
        lista->ultimo->prox = NULL;
        cout << "Lista criada com sucesso!" << endl;
        Listacriada = true;
    }
    else
    {
        cout << "Lista ja existe!";
    }
    Sleep(1500);
}

void AtualizaUltimo(TListaEncadeada *lista)
{
    TApontador aux;
    aux = lista->primeiro;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

bool Verifica_Lista_Encadeada_Vazia(TListaEncadeada *lista) // verificar se a lista encadeada foi criada com sucesso
{
    return (lista->primeiro == lista->ultimo);
}

bool Verifica_Lista_Arranjo_Vazia(TListaSequencial *lista) // Verificar se a lista sequencial foi criada com sucesso
{
    return (lista->primeiro == lista->ultimo);
}

int TamanhoLista(TListaEncadeada *lista) // Retornar atualizaçoes do tamanho da lista
{
    return lista->tamanho;
}

void InsereListaUltimo(TListaEncadeada *lista, TFuncionario *item) // Incrementa dados na ultima posiçãpo valida na lista
{
    lista->ultimo->prox = new Tipoelemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
}

void Imprime_Lista_Arranjo(TListaSequencial lista) // Atraves do id busca qual projeto retornar o mesmo.
{
    if (!Verifica_Lista_Arranjo_Vazia(&lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    for (int i = 0; i < lista.tamanho; i++)
    {
        cout << "ID do projeto: " << lista.item[i].id << endl;
        cout << "Nome do projeto: " << lista.item[i].nome << endl;
        cout << "Horas trabalhadas no projeto: " << lista.item[i].horas << endl;
    }
    system("pause");
}

int PesquisaFuncionario(TListaEncadeada *lista, int id) // Criada para pesquisar os itens do funcionario, usada na main em "case 5"
{
    TApontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            cout << "ID: " << aux->item.id << endl;
            cout << "Nome: " << aux->item.nome << endl;
            cout << "Endereco: " << aux->item.endereco.rua << endl;
            cout << "Bairro: " << aux->item.endereco.bairo << endl;
            cout << "Cidade: " << aux->item.endereco.cidade << endl
                 << "Numero da casa: " << aux->item.endereco.numCasa << endl;
            cout << "Numero de dependentes: " << aux->item.dependentes << endl
                 << "Quantidade de projetos: " << aux->item.projetos.tamanho << endl;
            return 0;
        }
        aux = aux->prox;
    }
    return -1;
}

void Consulta_funcionario(TListaEncadeada *lista) // Retornar se o funcionario existe ou nao.
{
    TChave id;
    cout << "Insira ID: " << endl;
    cin >> id;
    PesquisaFuncionario(lista, id);
}

TApontador PesquisaItem(TListaEncadeada *lista, int id) // Retornar apenas se o funcionario existe ou nao.
{
    TApontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void RemoveItemPorId(TListaEncadeada *lista, int id) // Criada para remover itens que estão dentro da lista encadiada.
{
    if (Verifica_Lista_Encadeada_Vazia(lista))
    {
        return;
    }

    TApontador aux, anterior, x;

    x = lista->primeiro;

    while (x != NULL)
    {
        if (x->prox->item.id == id)
        {
            anterior = x;
            break;
        }

        x = x->prox;
    }

    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
    AtualizaUltimo(lista); // chamada para sempre atualizar as novas posições após alguma exclusão.
}

int remove_Item_porID_Sequencial(TListaSequencial *lista, int id) // Criada para remover itens que estão dentro da lista sequencial.
{

    for (int j = 0; j < lista->tamanho; j++) // Usado para procurar a lista inteira
    {
        if (lista->item[j].id == id)
        {
            for (int i = j; i < lista->tamanho; i++) // Decrementa todos os itens desejados uma casa.
            {
                lista->item[i] = lista->item[i + 1];
            }
            lista->tamanho--;
            return 0;
        }
    }
    return -1;
}

void IncludeProgetos(TListaEncadeada *projetos) // Feita para armazenar projetos na lista encadeada.
{
    TApontador aux;
    TProjeto b;
    TChave id;
    int c = 0;

    cout << " ___________________________________________" << endl;
    cout << "|                                           |" << endl;
    cout << "|           Cadastro de projetos            |" << endl;
    cout << "|                                           |" << endl;
    cout << "|___________________________________________|" << endl
         << endl
         << endl;
    cout << "Informe o Id do funcionario para incluir projeto: " << endl;
    cin >> id;
    system("cls");

    aux = projetos->primeiro->prox;

    while (aux != NULL)
    {
        if (aux->item.id == id)
        {

            if (aux->item.projetos.tamanho >= MAXTAM)
            {
                cout << "Nao e possivel incrementar um projeto, lista ja esta completa " << endl;
                Sleep(1000);
            }
            else
            {
                c = aux->item.projetos.tamanho;
                cout << "Insira nome do projeto: " << endl;
                cin >> aux->item.projetos.item[c].nome;
                cout << "Insira ID do projeto: (Utilize apenas numeros.)" << endl;
                cin >> aux->item.projetos.item[c].id;
                cout << "Insira horas trabalhadas no projeto: (Utilize apenas numeros.)" << endl;
                cin >> aux->item.projetos.item[c].horas;
                aux->item.projetos.tamanho++;
            }
        }
        aux = aux->prox;
    }
}

void Exclui_Projetos(TListaEncadeada *lista) // Exclui projetos ja criados.
{
    TApontador aux;
    TChave id;
    int c;

    cout << " ___________________________________________" << endl;
    cout << "|                                           |" << endl;
    cout << "|             Excluir Projetos              |" << endl;
    cout << "|                                           |" << endl;
    cout << "|___________________________________________|" << endl
         << endl
         << endl
         << endl;
    cout << "Informe o Id do funcionario para excluir projeto: " << endl;
    cin >> id;

    system("cls");

    aux = lista->primeiro->prox;

    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            PesquisaFuncionario(lista, id);            // Busca informação do funcionario
            Imprime_Lista_Arranjo(aux->item.projetos); // imprimir os projetos
            cout << "Insira ID do projeto deseja excluir: " << endl;
            cin >> id;
            c = remove_Item_porID_Sequencial(&aux->item.projetos, id);
            if (c == -1)
            {
                cout << "Erro ao encontrar projeto. " << endl;
            }
        }
        aux = aux->prox;
    }
}

void Excluir_Func_Sem_Projetos(TListaEncadeada *lista) // Excluir todos os funcionarios ou apenas um.
{
    TApontador aux;
    TChave id;
    int op = 0;
    cout << " ___________________________________________" << endl;
    cout << "|                                           |" << endl;
    cout << "|           Excluir Funcionarios            |" << endl;
    cout << "|               Sem Projetos                |" << endl;
    cout << "|                                           |" << endl;
    cout << "|___________________________________________|" << endl
         << endl
         << endl;
    system("cls");
    cout << "1. Excluir um funcionario: " << endl;
    cout << "2. Excluir todos os funcionarios: " << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        cout << "Digite Id do funcionario que deseja excluir: " << endl;
        cin >> id;
        aux = PesquisaItem(lista, id); // armzena funcionario encotrado
        if (aux == NULL)
        {
            cout << "Funcionario nao encontrado. " << endl;
        }
        else
        {
            if (aux->item.projetos.tamanho != 0)
            {
                cout << "Obtem projetos cadastrado. " << endl;
            }
            else
            {
                RemoveItemPorId(lista, id);
            }
        }
        break;
    case 2:
        aux = lista->primeiro->prox;
        while (aux != NULL)
        { // percorree a lista
            if (aux->item.projetos.tamanho == 0)
            {
                RemoveItemPorId(lista, aux->item.id);
            }
            aux = aux->prox;
        }
        break;
    default:
        break;
    }
}

void Imprime_Contracheque(TListaEncadeada *lista) // Calculo do valor que o funcionario receberá após a entrega dos projetos.
{
    TApontador aux;
    float salarioB = 0.0, salarioL = 0.0, inss = 0, imposto = 0.0;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        cout << "Nome: " << aux->item.nome << endl
             << "Id: " << aux->item.id << endl;
        int cont = 0;

        for (int i = 0; i < aux->item.projetos.tamanho; i++)
        {
            cont = +aux->item.projetos.item[i].horas;
        }
        salarioB = 45 * cont + 35 * aux->item.dependentes;
        inss = salarioB * 8.5 / 100;
        imposto = salarioB * 15 / 100;
        salarioL = salarioB - inss - imposto;
        cout << "Horas Trabalhadas: " << cont << endl
             << "Salario Bruto: " << salarioB << endl
             << "Desconto INSS: " << inss << endl;
        cout << "Imposto de Renda: " << imposto << endl
             << "Salario Liquido: " << salarioL << endl;
        aux = aux->prox;
    }
}

void Leitura_Arquivo(TListaEncadeada *listaFuncionarios) // Lê o arquivo e caso exista a função inclui todos os funcionarios na bin.
{
    FILE *file = fopen("funcionarios.bin", "r");
    TFuncionario funcionario;
    if (file != NULL)
    {
        while (fread(&funcionario, sizeof(TFuncionario), 1, file))
        {

            InsereListaUltimo(listaFuncionarios, &funcionario);
        }
    }
}

void Inclui_Arquivo(TListaEncadeada *listaFuncionarios) // Apenas salva os funcionarios na lista.
{
    FILE *file = fopen("funcionarios.bin", "w");
    TApontador aux = listaFuncionarios->primeiro->prox;
    while (aux != NULL)
    {
        fwrite(&aux->item, sizeof(TFuncionario), 1, file);
        aux = aux->prox;
    }
}