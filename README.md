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
##caso 1| Palavras com caracteres que não estejam entre [a - z] ou [A - Z] ou hífen ‘-’. 
``
./a.out data/palavrasErro1.txt data/scores.txt
``
##caso 2|Palavras que não tenham sua frequência correspondente, ou a frequência não seja um número inteiro positivo.
``
./a.out data/palavrasErro2.txt data/scores.txt
``
##caso 3|Palavras com tamanho menor ou do que 4.
``
./a.out data/palavrasErro3.txt data/scores.txt
``
##validando o arquivo scores
##caso 4|Presença de mais de 3 “;” em alguma linha

``
./a.out data/palavras.txt data/scoresErro1.txt

``
##caso 5|Algum dos campos vazios
``
./a.out data/palavras.txt data/scoresErro2.txt

``
# limitações
o programa sorteia apenas uma consoante para as palavras fáceis;
