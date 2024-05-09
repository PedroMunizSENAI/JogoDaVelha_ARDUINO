int velha = 1;
int mensagem;
int linha;
int coluna;
bool HaVencedor = false;
//Matriz tabuleiro
int tabuleiro[3][3] = {
  { 0, 0, 0 },
  { 0, 0, 0 },
  { 0, 0, 0 }
};
String jogada;
//Primeiro a jogar é o jogador "1"
int JogadorDaVez = 1;
//Zerar o tabuleiro
void ZerarTabuleiro() {
  for (int linha = 0; linha < 3; linha++) {
    for (int coluna = 0; coluna < 3; coluna++) {
      tabuleiro[linha][coluna] = 0;
    }
  }
}
void setup() {
  Serial.begin(115200);
  for (int linha = 0; linha < 3; linha++) {
    for (int coluna = 0; coluna < 3; coluna++) {
      Serial.print(tabuleiro[linha][coluna]);
    }
    Serial.println();
  }
  Serial.print("Digite a posicao da sua peca Jogador ");
  Serial.println(JogadorDaVez);
}


void loop() {
  velha = 1;
  HaVencedor = false;
  do {

    if (Serial.available() > 0) {
      jogada = Serial.readString();
      linha = jogada.substring(0, 1).toInt();
      coluna = jogada.substring(2, 3).toInt();
      if (tabuleiro[linha][coluna] == 0) {
        tabuleiro[linha][coluna] = JogadorDaVez;
        if ((tabuleiro[0][0] == JogadorDaVez && tabuleiro[0][1] == JogadorDaVez && tabuleiro[0][2] == JogadorDaVez) || (tabuleiro[1][0] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[1][2] == JogadorDaVez) || (tabuleiro[2][0] == JogadorDaVez && tabuleiro[2][1] == JogadorDaVez && tabuleiro[2][2] == JogadorDaVez)) {
          HaVencedor = true;
          mensagem = 1;
        } else if ((tabuleiro[0][0] == JogadorDaVez && tabuleiro[1][0] == JogadorDaVez && tabuleiro[2][0] == JogadorDaVez) || (tabuleiro[0][1] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[2][1] == JogadorDaVez) || (tabuleiro[0][2] == JogadorDaVez && tabuleiro[1][2] == JogadorDaVez && tabuleiro[2][2] == JogadorDaVez)) {
          HaVencedor = true;
          mensagem = 1;
        } else if ((tabuleiro[0][0] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[2][2] == JogadorDaVez) || (tabuleiro[0][2] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[2][0] == JogadorDaVez)) {
          HaVencedor = true;
          mensagem = 1;

        } else if (JogadorDaVez == 1) {
          JogadorDaVez = 2;
        } else {
          JogadorDaVez = 1;
        }

        velha++;

        for (int linha = 0; linha < 3; linha++) {
          for (int coluna = 0; coluna < 3; coluna++) {
            Serial.print(tabuleiro[linha][coluna]);
          }
          Serial.println();
        }
        Serial.print("Digite a posicao da sua peca Jogador ");
        Serial.println(JogadorDaVez);
      } else {
        Serial.println("Jogada invalida, digite novamente");
      }
    }
  } while (!HaVencedor && velha <= 9);

  if (!HaVencedor) {
    mensagem = 2;
  }

  switch (mensagem) {
    case 1:
      Serial.println("Parabens, voce ganhou!");
      break;
    case 2:
      Serial.println("Deu Velha!");
      break;
  }
}