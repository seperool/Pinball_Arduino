//Bibliotecas
#include <LiquidCrystal.h>

//Definindo os pinos que serão utilizados para ligação ao display LCD
LiquidCrystal lcd(6, 7, 5, 4, 3, 2);

//Definindo pinos dos LED
int pinoLed_1 = 13; //Pino digital utilizado pelo LED 1 - Azul
int pinoLed_2 = 12; //Pino digital utilizado pelo LED 2 - Verde
int pinoLed_3 = 11; //Pino digital utilizado pelo LED 3 - Amarelo
int pinoLed_4 = 10; //Pino digital utilizado pelo LED 4 - Vermelho
int pinoLed_5 = 9; //Pino digital utilizado pelo LED 5 - Verde
int pinoLed_6 = 8; //Pino digital utilizado pelo LED 6 - Azul

// Cores LED e Pontos
// Azul = LED 1 e 6 = 1 ponto
// Verde = LED 2 e 5 = 2 ponto
// Amarelo = LED 3 = 3 ponto
// Vermelho = LED 4 = 0 ponto

//Definindo pinos dos sensores óptico tcrt5000
int pinoSensor_1 = 18; //Pino analogico A0 transformado em pino digital utilizado pelo sensor 1
int pinoSensor_2 = 17; //Pino analogico A1 transformado em pino digital utilizado pelo sensor 2
int pinoSensor_3 = 15; //Pino analogico A2 transformado em pino digital utilizado pelo sensor 3
int pinoSensor_4 = 19; //Pino analogico A3 transformado em pino digital utilizado pelo sensor 4 (vermelho)
int pinoSensor_5 = 16; //Pino analogico A4 transformado em pino digital utilizado pelo sensor 5
int pinoSensor_6 = 14; //Pino analogico A5 transformado em pino digital utilizado pelo sensor 6

// Relação entre LED e sensores - Pinos
// pinoSensor_1 -> pinoLed_1 - Pinos A0 e 13
// pinoSensor_2 -> pinoLed_2 - Pinos A1 e 12
// pinoSensor_3 -> pinoLed_3 - Pinos A2 e 11
// pinoSensor_4 -> pinoLed_4 - Pinos A3 e 10
// pinoSensor_5 -> pinoLed_5 - Pinos A4 e 9
// pinoSensor_6 -> pinoLed_6 - Pinos A5 e 8

// Variáveis
int point = 0; //Contador de pontos
int stop = 500; //Tempo de parada para o delay

void setup() {
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  
  // Inicializando os Sensores
  pinMode(pinoSensor_1, INPUT); //Definindo o pino como entrada para o sensor 1
  pinMode(pinoSensor_2, INPUT); //Definindo o pino como entrada para o sensor 2
  pinMode(pinoSensor_3, INPUT); //Definindo o pino como entrada para o sensor 3
  pinMode(pinoSensor_4, INPUT); //Definindo o pino como entrada para o sensor 4
  pinMode(pinoSensor_5, INPUT); //Definindo o pino como entrada para o sensor 5
  pinMode(pinoSensor_6, INPUT); //Definindo o pino como entrada para o sensor 6

  // Inicializando os LED
  pinMode(pinoLed_1, OUTPUT); //Definindo o pino como saída para o LED 1 - Verde
  pinMode(pinoLed_2, OUTPUT); //Definindo o pino como saída para o LED 2 - Azul
  pinMode(pinoLed_3, OUTPUT); //Definindo o pino como saída para o LED 3 - Amarelo
  pinMode(pinoLed_4, OUTPUT); //Definindo o pino como saída para o LED 4 - Vermelho
  pinMode(pinoLed_5, OUTPUT); //Definindo o pino como saída para o LED 5 - Verde
  pinMode(pinoLed_6, OUTPUT); //Definindo o pino como saída para o LED 6 - Azul
  
  // Desligando os LED
  digitalWrite(pinoLed_1, LOW); //LED 1 inicia desligado
  digitalWrite(pinoLed_2, LOW); //LED 2 inicia desligado
  digitalWrite(pinoLed_3, LOW); //LED 3 inicia desligado
  digitalWrite(pinoLed_4, LOW); //LED 4 inicia desligado
  digitalWrite(pinoLed_5, LOW); //LED 5 inicia desligado
  digitalWrite(pinoLed_6, LOW); //LED 6 inicia desligado
}

void loop() {
  //Sensor
  if (digitalRead(pinoSensor_1) == LOW){ //Se a leitura do sensor 1 (Azul) for igual a LOW, faz
    digitalWrite(pinoLed_1, HIGH); //Acende o LED 1 - Azul
    point=point+1; //Adiciona 1 ponto
  }else if(digitalRead(pinoSensor_2) == LOW){ //Se a leitura do sensor 2 (Verde)) for igual a LOW, faz
		digitalWrite(pinoLed_2, HIGH); //Acende o LED 2 - Verde
    point=point+2; //Adiciona 2 ponto
  }else if(digitalRead(pinoSensor_3) == LOW){ //Se a leitura do sensor 3 (Amarelo) for igual a LOW, faz
		digitalWrite(pinoLed_3, HIGH); //Acende o LED 3 - Amarelo
    point=point+3; //Adiciona 3 ponto
  }else if(digitalRead(pinoSensor_5) == LOW){ //Se a leitura do sensor 5 (Verde) for igual a LOW, faz
    digitalWrite(pinoLed_5, HIGH); //Acende o LED 5 - Verde
    point=point+2; //Adiciona 2 ponto
  }else if(digitalRead(pinoSensor_6) == LOW){ //Se a leitura do sensor 6 (Azul) for igual a LOW, faz
    digitalWrite(pinoLed_6, HIGH); //Acende o LED 6 - Azul
    point=point+1; //Adiciona 1 ponto
  }else if(digitalRead(pinoSensor_4) == LOW){ //Se a leitura do sensor 4 (Vermelho) for igual a LOW, faz
		digitalWrite(pinoLed_4, HIGH); //Acende o LED 4 - Vermelho
    point=0; //Reinicia a contagem
  }
  
  //LCD
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 1, linha 0;
  lcd.setCursor(1, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Jogo Placar");
  //Posiciona o cursor na coluna 1, linha 1;
  lcd.setCursor(1, 1);
  //Imprime Contador de pontuação
  lcd.print(point);
  delay(stop);
  
  // Apagar LED
  digitalWrite(pinoLed_1, LOW); //Apaga o LED 1
  digitalWrite(pinoLed_2, LOW); //Apaga o LED 2
  digitalWrite(pinoLed_3, LOW); //Apaga o LED 3
  digitalWrite(pinoLed_4, LOW); //Apaga o LED 4
  digitalWrite(pinoLed_5, LOW); //Apaga o LED 5
  digitalWrite(pinoLed_6, LOW); //Apaga o LED 6
}
