#include <iostream>
#include <windows.h>
#include "lista.hpp"
#include "funcoesTP.cpp"

using namespace std;

int main()
{
  int op = 0;
  TListaEncadeada lista; // Criando a variavel lista para ser chamada e armazenada na função abaixoi.
  CriaListaVazia(&lista);
  Leitura_Arquivo(&lista);
  do { //encrementado para entender a opção desejada pelo usauario sendo eles de opção 1 a 7.
  menu();
  cin >> op;
  switch (op)
  {
  case 1:
    includeFuncionario(&lista);
    break;
  case 2:
    IncludeProjetos(&lista);
    break;
  case 3:
    Exclui_Projetos(&lista);
    break;
  case 4:
    Excluir_Func_Sem_Projetos(&lista);
    break;
  case 5:
    Consulta_funcionario(&lista);
    break;
  case 6:
    Imprime_Contracheque(&lista);
    break;
  case 7:
    break;
  default:
    break;
  }
  system("pause");
  system("cls");
  }
  while (op != 7); // quando usuario digitar qualquer numero diferente de 6 o programa para instantaneamente, ja que o case 7 também serve para sair do programa
  Inclui_Arquivo(&lista);
  return 0;
}