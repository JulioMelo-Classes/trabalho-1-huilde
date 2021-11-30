 # Trabalho-1
Repositório contendo as especificações do Trabalho 1 da disciplina de LP1

# Para compilar o projeto:
Para compilar o trabalho, rode os seguintes comandos dentro da pasta que esse arquivo se encontra:
``
g++ src/main.cpp src/forca.cpp
``
# Para executar
``
./a.out data/palavras.txt data/scores.txt

``
# testando erros

## validando o arquivo palavras

## caso 1| Palavras com caracteres que não estejam entre [a - z] ou [A - Z] ou hífen ‘-’. 
``
./a.out data/palavrasErro1.txt data/scores.txt
``
## caso 2|Palavras que não tenham sua frequência correspondente, ou a frequência não seja um número inteiro positivo. 
``
./a.out data/palavrasErro2.txt data/scores.txt
``
## caso 3|Palavras com tamanho menor ou do que 4. 
``
 ./a.out data/palavrasErro3.txt data/scores.txt
``
## validando o arquivo scores
## caso 4|Presença de mais de 3 “;” em alguma linha 

``
 ./a.out data/palavras.txt data/scoresErro1.txt

``
## caso 5|Algum dos campos vazios 

``
 ./a.out data/palavras.txt data/scoresErro2.txt

``
# limitações
o programa sorteia apenas uma consoante para as palavras fáceis;

# Avaliação

## Código | Funcionalidades
1. Classe forca 10/10

2. Interface textual 10/10

3. Execução completa do jogo 13/15
- Ao errar uma palavra o jogo reexecuta automaticamente, esse não é o comportamento esperado.

4. Validação dos arquivos de texto 5/5

5. Arquivos de teste de validação dos casos de erro 5/5

6. Arquivos de teste de validação dos níveis de dificuldade 1/5
- A ideia aqui era vc prover alguns arquivos que ajudassem a testar os níveis de dificuldade, princpialmente
o gameover quando todas as palavras para aquela dificuldade acabam.

7. Observações gerais
- A indentação está realmente muito ruim se eu não usar o auto indent do vscode...
- vc poderia ter tentado escrever mais uma classe para a interface textual

## Código | Boas práticas

1. Documentação do código e readme 5/10
- Algumas funções/métodos ficaram sem documentação

2. Organização e indentação 5/10
- Não foi feita a divisão em src e include
- Embora você use alguma ide para indentar o código, na próxima vez que entregar tenha certeza de que a indentação está ok.

3. Compilação automatizada 0/5

