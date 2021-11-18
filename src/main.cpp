#include <iostream>
#include "Foca.hpp"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{

  std::string arquivoCorpus = argv[1];
  std::string arquivoScores = argv[2];

  
  // ../include/palavras.txt
  Forca Jogo = Forca(arquivoCorpus, arquivoScores);
  cout << ">>> Lendo arquivos de palavras"
       << " [" << arquivoCorpus << "] "
       << "e scores"
       << " [" << arquivoScores << "] ,"
       << "por favor aguarde.." << endl;
  //adicionar a validação dos arquivos.
  int escolha;
  cout << "--------------------------------------------------------------------" << endl;
  cout << "Bem vindo ao Jogo Forca! Por favor escolha uma das opções" << endl;
  cout << "1 - Iniciar Jogo" << endl;
  cout << "2 - Ver scores anteriores" << endl;
  cout<<"sua escolha:";
  cin >> escolha;
  if (escolha == 1)
  {
    Jogo.carrega_arquivos();      
    cout << "Vamos iniciar o jogo! Por favor escolha o nível de dificuldade" << endl;
    cout<<"1 - Fácil"<<endl;
    cout<<"2 - Médio"<<endl;
    cout<<"3 - Difícil"<<endl;
    cout<<"sua escolha: ";
    cin>>escolha;
    if(escolha==1){
      cout<<"fácil";
    }
    else if(escolha==2){
      cout<<"médio";
    }
    else if(escolha==3){
      cout<<"Difícil";
    }
    else{
      cout<<"Escolha uma opção válida"<<endl;
    }
  }
  else if (escolha == 2)
  {
     std::fstream arquivoPontos;
  arquivoPontos.open(arquivoScores, ios::in);
  std::string pontos;
  while (!arquivoPontos.eof())
  {getline(arquivoPontos,pontos);
  cout<<pontos<<endl;

  }
    
  }
else{
  cout<<"Escolha uma opção válida"<<endl;
}
  return 0;
}