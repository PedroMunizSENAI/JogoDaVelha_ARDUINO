int velha;
int linha;
int coluna;
bool HaVencedor;
HaVencedor = false;
int tabuleiro [3][3] = {
  {0, 1, 2} ,
  {3, 4, 5} ,
  {6, 7, 8} ;
};
for (int linha = 0; linha < 3; linha++) {
  for (int coluna = 0; coluna < 3; coluna++)
};
char jogador1;
char jogador2;
jogador1 = "jogador1";
jogador2 = "jogador2";
char jogada;
int jogadordavez;
jogadordavez = 1;
velha = 1;

Serial.println(tabuleiro [3][3]);
jogada = "";
Serial.println("Digite a posição da sua peça jogador" & jogadordavez);
if(Serial.available()) {
    char jogada = Serial.read();
}
if(validaPosicao(jogada)) {
    linha.toInt
}
