#include <iostream>
#include "Foca.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;
int main(int argc, char *argv[])
{
  std::fstream arquivoPontos;
  std::string arquivoCorpus = argv[1];
  std::string arquivoScores = argv[2];
  char letra;
  // ../include/palavras.txt
  Forca Jogo = Forca(arquivoCorpus, arquivoScores);
  cout << ">>> Lendo arquivos de palavras"
       << " [" << arquivoCorpus << "] "
       << "e scores"
       << " [" << arquivoScores << "] ,"
       << "por favor aguarde.." << endl;
  if(!Jogo.eh_valido().first){
    cout<<Jogo.eh_valido().second<<endl;
    return 0;
  }
  int escolha;
  cout<<"--------------------------------------------------------------------"<<endl;
  cout<<">>> Arquivos OK!"<<endl;
  //while  englobando todo o escopo da função;

  while (true)
  {
    int pontos = 0;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Bem vindo ao Jogo Forca! Por favor escolha uma das opções" << endl;
    cout << "1 - Iniciar Jogo" << endl;
    cout << "2 - Ver scores anteriores" << endl;
    cout << "sua escolha:";
    cin >> escolha;
    if (escolha == 1)
    {
      std::string dificuldade;
      std::vector<std::string> Acertadas;
      std::vector<char> LetrasDigitadas;

      Jogo.carrega_arquivos();
      cout << "Vamos iniciar o jogo! Por favor escolha o nível de dificuldade" << endl
           << "1 - Fácil" << endl
           << "2 - Médio" << endl
           << "3 - Difícil" << endl;
      cout << "Sua escolha: ";
      cin >> escolha;
      if (escolha == 1)
      {
        dificuldade = "FÁCIL";
        Forca::Dificuldade i = Forca::Dificuldade::FACIL;
        Jogo.set_dificuldade(i);
        cout<<"Iniciando o Jogo no nível Fácil, será que você conhece essa palavra?"<<endl;
      }
      else if (escolha == 2)
      {
        dificuldade = "MÉDIO";
        Forca::Dificuldade i = Forca::Dificuldade::MEDIO;
        Jogo.set_dificuldade(i);
        cout<<"Iniciando o Jogo no nível Médio, será que você conhece essa palavra?"<<endl;
      }
      else if (escolha == 3)
      {
        dificuldade = "DIFÍCIL";
        Forca::Dificuldade i = Forca::Dificuldade::DIFICIL;
        Jogo.set_dificuldade(i);
        cout<<"Iniciando o Jogo no nível Difícil, será que você conhece essa palavra?"<<endl;
      }
      while (Jogo.ContaPalavras())
      {
        std::string secreta = Jogo.proxima_palavra();
        while (!Jogo.game_over() && Jogo.GetpalavraSecreta() != Jogo.get_palavra_atual())
        {
          Jogo.imprimeForca();

          cout << endl;
          for (size_t i = 0; i < Jogo.get_palavra_atual().size(); i++)
          {
            cout << Jogo.GetpalavraSecreta()[i] << " ";
          }
          cout <<endl<< "pontos: " << Jogo.getpontos() << endl;
          cout << "palpite: ";
          cin >> letra;
          std::string teste = Jogo.get_palavra_atual();
          if(verificaPalavra(letra,LetrasDigitadas)){
          LetrasDigitadas.push_back(letra);
          if (Jogo.palpite(letra))
          {
            cout << "Muito bem! A palavra contém a letra " << letra << "!" << endl;
            Jogo.imprimeForca();
            cout << "pontos: " << Jogo.getpontos() << endl;
          }
          else
          {
            cout << "Meh, não achei a letra " << letra << " :<" << endl;
          }
          }
        }
          LetrasDigitadas.clear();
        if (Jogo.GetpalavraSecreta() == Jogo.get_palavra_atual())
        {
          cout << "Parabéns, você acertou a palavra" << endl;
          Acertadas.push_back(Jogo.GetpalavraSecreta());
          Jogo.imprimeForca();
          cout << "pontos: " << Jogo.getpontos() << endl;
          cout << "Deseja continuar jogando?" << endl;
          cout << "1 - Continuar" << endl
               << "2 -Parar" << endl;
          int decisao;
          cout << "Escolha: ";
          cin >> decisao;
          if (decisao == 2)
          {
            break;
          }
        }
        else
        {
          cout << "Vixe, Fim de Jogo!" << endl;
          Jogo.imprimeForca();
          cout << "pontos: " << Jogo.getpontos() << endl;
          cout << "O jogo acabou a palavra era " << Jogo.get_palavra_atual() << endl;
        }
      
        Jogo.set_tentativas_restantes(6);
      }
       Jogo.MaiorMedia.clear();
       Jogo.MenorMedia.clear();
      if(!Jogo.ContaPalavras()){
        cout<<"O Jogo foi encerrado pois você acertou todas as palavras disponivéis"<<endl;
      }
      cout<<"Digite seu nome para podermos Guardar a sua pontuaçao"<<endl;
      std::string nomeUsuario; 
      cin.ignore();
      getline(cin,nomeUsuario,'\n');
      std::fstream EscreverPontos;
      EscreverPontos.open(arquivoScores,ios::app);
      EscreverPontos<<endl<<dificuldade<<"; "<<nomeUsuario<<";";
      for(int i =0;i< Acertadas.size();i++){
        EscreverPontos<<Acertadas[i]<<",";
      }
     EscreverPontos<<";"<<Jogo.getpontos();

    }
    else if (escolha == 2)
    {
      arquivoPontos.open(arquivoScores, ios::in);
      std::string pontos;
      while (!arquivoPontos.eof())
      {
        getline(arquivoPontos, pontos);
        cout << pontos << endl;
      }
    
         cout<<"Deseja Jogar?"<<endl
              <<"1 - Sim"<<endl
              <<"2 - Não"<<endl;
               int decisao;
          cout << "Escolha: ";
          cin >> decisao;
          if (decisao == 2)
          {
            break;
          }

    }
  }
  return 0;
}
