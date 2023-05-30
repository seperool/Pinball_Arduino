//Bibliotecas
#include <LiquidCrystal.h>

//Definindo os pinos que serão utilizados para ligação ao display LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Definindo pinos dos LED
int pinoLed_1 = 8; //Pino digital utilizado pelo LED 1
int pinoLed_2 = 9; //Pino digital utilizado pelo LED 2
int pinoLed_3 = 10; //Pino digital utilizado pelo LED 3
int pinoLed_4 = 13; //Pino digital utilizado pelo LED 4


//Definindo pinos dos sensores óptico tcrt5000
int pinoSensor_1 = 7; //Pino digital utilizado pelo sensor 1
int pinoSensor_2 = 6; //Pino digital utilizado pelo sensor 2
int pinoSensor_3 = 14; //Pino analogico A0 transformado em pino digital utilizado pelo sensor 3
int pinoSensor_4 = 15; //Pino analogico A1 transformado em pino digital utilizado pelo sensor 4

// Variáveis
int point = 0; //Contador de pontos
int stop = 300; //Tempo de parada para o delay

void setup() {
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  
  // Inicializando os Sensores
  pinMode(pinoSensor_1, INPUT); //Definindo o pino como entrada para o sensor 1
  pinMode(pinoSensor_2, INPUT); //Definindo o pino como entrada para o sensor 2
  pinMode(pinoSensor_3, INPUT); //Definindo o pino como entrada para o sensor 3
  pinMode(pinoSensor_4, INPUT); //Definindo o pino como entrada para o sensor 4
  
  // Inicializando os LED
  pinMode(pinoLed_1, OUTPUT); //Definindo o pino como saída para o LED 1
  pinMode(pinoLed_2, OUTPUT); //Definindo o pino como saída para o LED 2  
  pinMode(pinoLed_3, OUTPUT); //Definindo o pino como saída para o LED 3
  pinMode(pinoLed_4, OUTPUT); //Definindo o pino como saída para o LED 4
  
  // Desligando os LED
  digitalWrite(pinoLed_1, LOW); //LED 1 inicia desligado
  digitalWrite(pinoLed_2, LOW); //LED 2 inicia desligado
  digitalWrite(pinoLed_3, LOW); //LED 3 inicia desligado
  digitalWrite(pinoLed_4, LOW); //LED 4 inicia desligado
}

void loop() {
  //Sensor
  if (digitalRead(pinoSensor_1) == LOW){ //Se a leitura do sensor 1 for igual a LOW, faz
    digitalWrite(pinoLed_1, HIGH); //Acende o LED 1
    point=point+1; //Adiciona ponto
  }else if(digitalRead(pinoSensor_2) == LOW){ //Se a leitura do sensor 2 for igual a LOW, faz
		digitalWrite(pinoLed_2, HIGH); //Acende o LED 2
    point=point+1; //Adiciona ponto
  }else if(digitalRead(pinoSensor_3) == LOW){ //Se a leitura do sensor 3 for igual a LOW, faz
		digitalWrite(pinoLed_3, HIGH); //Acende o LED 3
    point=point+1; //Adiciona ponto
  }else if(digitalRead(pinoSensor_4) == LOW){ //Se a leitura do sensor 4 for igual a LOW, faz
		digitalWrite(pinoLed_4, HIGH); //Acende o LED 4
    point=0; //Reinicia a contagem
  }
  
  //LCD
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 1, linha 0;
  lcd.setCursor(1, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Jogo ON");
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
}
