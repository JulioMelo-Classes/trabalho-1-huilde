using namespace std;
//using std::make_pair;
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>
#include <iterator>
#include "Foca.hpp"
/**
         * Cria a classe Forca
         * O construtor pode ou não validar os arquivos de entrada, no entanto, mesmo com 
         * os arquivos inválidos o objeto deve ser construído. Para o caso de arquivos de palavras
         * ou scores inválidos, use o método eh_valido.
         * @param palavras o arquivo que contém as palavras
         * @param scores o nome do arquivo que contém os scores
         * @see eh_valido
         */
Forca::Forca(std::string palavras, std::string scores)
{
  m_arquivo_palavras = palavras;
  m_arquivo_scores = scores;
};

/**
         * Valida os arquivos de entrada de acordo com as especificações.
         * Ao validar os arquivos, no caso de arquivos inválidos, este método deve retornar a 
         * razão correspondente de acordo com as especificações.
         * @return {T,""} se os arquivos estiverem válidos, {F,"razão"} caso contrário.
         */
std::pair<bool, std::string> eh_valido();

/**
         * Carrega os arquivos de scores e palavras preenchendo **ao menos** a estrutura m_palavras
         */
void Forca::carrega_arquivos()
{
  std::fstream arquivoPalavras;
  arquivoPalavras.open(m_arquivo_palavras, ios::in);
  int frequencia;
  std::string palavra;
  while (!arquivoPalavras.eof())
  {
    arquivoPalavras >> frequencia >> palavra;
    m_palavras.push_back(make_pair(palavra, frequencia));
  }
  m_palavras.pop_back();
  int media = 0;
  std::random_device rd;
  std::mt19937 g(rd());

  // Embaralha o vetor `v` usando o motor de números aleatórios `g`.
  std::shuffle(m_palavras.begin(), m_palavras.end(), g);
  for (int i = 0; i < m_palavras.size(); i++)
  {
    media += m_palavras[i].second;
  }
  media = media / (m_palavras.size());
  for (int i = 0; i < m_palavras.size(); i++)
  {
    if (m_palavras[i].second > media)
    {
      MaiorMedia.push_back(m_palavras[i]);
    }
    else
    {
      MenorMedia.push_back(m_palavras[i]);
    }
  }
}

/**
         * Modifica a dificuldade do jogo.
         * De acordo com a dificuldade configurada, o método proxima_palavra retornará palavras
         * diferentes.
         * @param d a dificuldade desejada
         * @see proxima_palavra
         */
void Forca::set_dificuldade(Dificuldade i)
{
  d = i;
}

/**
         * Retorna a próxima palavra de acordo com a dificuldade atual.
         * Este método deve atualizar o atributo m_palavra_atual e retornar a palavra um texto no formato
         * "_ _ _ _ ... _" dependendo do tamanho de m_palavra_atual. O método também deve sortear as 
         * letras que devem aparecer dependendo do nível de dificuldade.
         * @return a próxima palavra do conjunto de palavras disponível de acordo com a dificuldade atual.
         */
std::string Forca::proxima_palavra()
{
  //retornando a palavra correta com base na dificuldade do jogo
  std::string retorno;
  if (d == FACIL)
  {m_palavra_atual = MaiorMedia[0].first;
  for (int i = 0 ; i < MaiorMedia[0].first.size(); i++)
  {
   retorno.push_back('_');
  }
  MaiorMedia.erase(MaiorMedia.begin());

  }
else if(d == MEDIO)
{m_palavra_atual = MaiorMedia[0].first;
  for (int i = 0 ; i < MaiorMedia[0].first.size(); i++)
  {
    retorno.push_back('_');
  }
   MaiorMedia.erase(MaiorMedia.begin());
}
  
  else
  {m_palavra_atual = MenorMedia[0].first;
  for (int i = 0 ; i < MenorMedia[0].first.size(); i++)
  {
   retorno.push_back('_');
  }
  MenorMedia.erase(MenorMedia.begin());
  }
m_palavraSecreta = retorno;
return retorno;}

/**
         * Retorna a palavra atual que está sendo jogada.
         * @return o valor do atributo m_palavra_atual.
         */
std::string Forca::get_palavra_atual(){
  return m_palavra_atual;
}

/**
         * Testa se uma letra pertence á palavra atual, retorna T se a letra pertence.
         * Este método testa se uma letra pertence à palavra atual e retorna True caso pertença. 
         * Caso contrário, o método deve atualizar o atributo m_tentativas_restantes, decrementando 
         * em 1, e retornar False.
         * @param palpite uma letra, que deve ser testada se pertence à palavra.
         * @return T se a palpite pertence à palavra, F caso contrário.
         */
bool Forca::palpite(char palpite){
  bool resultado = false;
  for (int i = 0; i <m_palavra_atual.size(); i++)
  {if(toupper(palpite) == m_palavra_atual[i]){
    m_palavraSecreta[i] = m_palavra_atual[i];
    resultado = true;
    m_pontos+=1;
  }
  }
  if(resultado == false){
    m_tentativas_restantes =m_tentativas_restantes -1;
    m_pontos-=1;
  }
 
return resultado;}

/**
         * Em caso de Game Over este método deve retornar T.
         * @return T caso o m_tentativas_restantes do jogo esteja igual a 0, F caso contrário.
         */
bool Forca::game_over(){
  if(m_tentativas_restantes>0){
    return false;
  }
  else{
    return true;
  }
}

/**
         * Atualiza o número de tentativas restantes.
         * Este método é útil no caso do jogador escolher continuar o jogo.
         * @param tentativas atualiza o valor da variável m_tentativas_restantes.
         */
void Forca::set_tentativas_restantes(int tentativas){
  m_tentativas_restantes = 6;
}

/**
         * Retorna a quantidade de tentativas restantes.
         * @return a quantidade de tentativas restantes.
         */
int Forca::get_tentativas_restantes(){
  return m_tentativas_restantes;
}
std::string Forca::GetpalavraSecreta(){
return m_palavraSecreta;
}
void Forca::SetpalavraSecreta(std::string palavra){
  m_palavraSecreta = palavra;
}
 int Forca::getpontos(){
   return m_pontos;
 }
bool Forca::ContaPalavras(){
if(d == MEDIO||d==FACIL && MaiorMedia.size()>0){
return true;
}
else if(d==DIFICIL&& MenorMedia.size()>0){
  return true;
}
else{
  return false;
}
}
void Forca::imprimeForca(){
  switch(m_tentativas_restantes)
  {
  case 6:
    cout<<endl<<endl<<endl<<endl<<endl;
    break;
  case 5:
    cout<<"O"<<endl<<endl<<endl<<endl;
    break;
    case 4:
    cout<<' '<<"O"<<endl;
    cout<<" "<<"|"<<endl<<endl<<endl;
    break;
    case 3:
    cout<<" O"<<endl;
     cout<<"/|"<<endl<<endl<<endl;
    break;
    case 2:
    cout<<" O"<<endl;
     cout<<"/|\\"<<endl<<endl<<endl;
    break;
    case 1:
    cout<<" O"<<endl;
    cout<<"/|\\"<<endl;
    cout<<"/"<<endl<<endl;;
    break;
    case 0:
    cout<<" O"<<endl;
    cout<<"/|\\"<<endl;
    cout<<"/ \\"<<endl<<endl;
    break;

  }
}