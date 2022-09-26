#include <iostream>
#include <windows.h>
#include "lista.hpp"
#include "funcoesTP.cpp"

using namespace std;

int main()
{
  int op = 0;
  TListaEncadeada lista;
  CriaListaVazia(&lista);
  do {
  menu();
  cin >> op;
  switch (op)
  {
  case 1:
    includeFuncionario(&lista);
    break;
  case 2:
    IncludeProgetos(&lista);
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
  while (op != 7);

  return 0;
}