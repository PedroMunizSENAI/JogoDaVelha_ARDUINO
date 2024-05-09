//Declarar variavel inteira velha eatribuir valor 1
int velha = 1;
//Declarar variavel inteira mensagem
int mensagem;
//Declarar variavel inteira linha
int linha;
//Declarar variavel inteira coluna
int coluna;
//Declarar variavel booleana HaVencedor e atribuir false
bool HaVencedor = false;
//Declarar variavel inteira matriz bidimensional tabuleiro
int tabuleiro[3][3] = {
  { 0, 0, 0 },
  { 0, 0, 0 },
  { 0, 0, 0 }
};
//Declarar String jogada
String jogada;
//Declarar variavel inteira JogadorDaVez e atribuir valor 1
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
  //Velocidade de processamento da porta Serial
  Serial.begin(115200);
  //Imprime o tabuleiro
  for (int linha = 0; linha < 3; linha++) {
    for (int coluna = 0; coluna < 3; coluna++) {
      Serial.print(tabuleiro[linha][coluna]);
    }
    Serial.println();
  }
  //Pede para o jogador da vez digitar a posição da jogada
  Serial.print("Digite a posicao da sua peca Jogador ");
  Serial.println(JogadorDaVez);
}


void loop() {
  //Atribui valor 1 a variavel velha
  velha = 1;
  //Atribui valor false a variavel HaVencedor
  HaVencedor = false;
  //Comando do while verifica se há vencedor ou se a jogada é invalida
  do {
  //Verifica se tem bytes disponiveis e transforma a String em Inteiro
    if (Serial.available() > 0) {
      jogada = Serial.readString();
      linha = jogada.substring(0, 1).toInt();
      coluna = jogada.substring(2, 3).toInt();
      if (tabuleiro[linha][coluna] == 0) {
        tabuleiro[linha][coluna] = JogadorDaVez;
        //Verifica se ha vencedores e imprime mensagem "Parabens, voce ganhou"
        if ((tabuleiro[0][0] == JogadorDaVez && tabuleiro[0][1] == JogadorDaVez && tabuleiro[0][2] == JogadorDaVez) || (tabuleiro[1][0] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[1][2] == JogadorDaVez) || (tabuleiro[2][0] == JogadorDaVez && tabuleiro[2][1] == JogadorDaVez && tabuleiro[2][2] == JogadorDaVez)) {
          HaVencedor = true;
          mensagem = 1;
        } else if ((tabuleiro[0][0] == JogadorDaVez && tabuleiro[1][0] == JogadorDaVez && tabuleiro[2][0] == JogadorDaVez) || (tabuleiro[0][1] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[2][1] == JogadorDaVez) || (tabuleiro[0][2] == JogadorDaVez && tabuleiro[1][2] == JogadorDaVez && tabuleiro[2][2] == JogadorDaVez)) {
          HaVencedor = true;
          mensagem = 1;
        } else if ((tabuleiro[0][0] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[2][2] == JogadorDaVez) || (tabuleiro[0][2] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[2][0] == JogadorDaVez)) {
          HaVencedor = true;
          mensagem = 1;
        //Troca o jogador da vez
        } else if (JogadorDaVez == 1) {
          JogadorDaVez = 2;
        } else {
          JogadorDaVez = 1;
        }
        //Toda vez que executar o if, acrescentará 1 ao valor da variavel velha
        velha++;
        //Imprime o tabuleiro com a jogada do jogador anterior
        for (int linha = 0; linha < 3; linha++) {
          for (int coluna = 0; coluna < 3; coluna++) {
            Serial.print(tabuleiro[linha][coluna]);
          }
          Serial.println();
        }
        //Pede para o jogador da vez digitar a posição da sua peça
        Serial.print("Digite a posicao da sua peca Jogador ");
        Serial.println(JogadorDaVez);
        //Se a posição já tiver ocupada, pede para digitar novamente
      } else {
        Serial.println("Jogada invalida, digite novamente");
      }
    }
  //Comando do while verifica se há vencedor ou se a jogada é invalida
  } while (!HaVencedor && velha <= 9);
  //Se der empate, aparece a mensagem "Deu Velha"
  if (!HaVencedor) {
    mensagem = 2;
  }
  //Se "mensagem" for igual a 1 executará o case 1, se for igual a 2 executará o case 2
  switch (mensagem) {
    case 1:
      Serial.println("Parabens, voce ganhou!");
      break; 
    case 2:
      Serial.println("Deu Velha!");
      break;
  }
}