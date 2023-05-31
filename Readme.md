# 1 OBJETIVO

## 1.1 Projeto Pinball

Desenvolver um brinquedo simples para crianças com transtorno de especto
autista (TEA) que envolva circuitos elétricos.  
O projeto é um pinball, de dimensões portatil (um pouco maior que uma
caixa de sapatos), construido com **Arduino UNO R3**, quatro **LED** e
quatro sensores que mapeiam a movimentação da bola. Com base no
mapeamento da movimentação da bola os pontos do jogo são marcados ou a
partida é reiniciada.  

<figure>
<img src="./Imagem_pinball_arduino.png" style="width:30.0%"
alt="Exemplo pinball construido a partir de Arduino" />
<figcaption aria-hidden="true">Exemplo pinball construido a partir de
Arduino</figcaption>
</figure>

## 1.2 O que é o Arduino

O Arduino é uma pequena placa de microcontrolador. Contém diversos
terminais que permitem a conexão com dispositivos externos. Os Arduinos
podem ser energizados por um computador através de um plugue USB, por
uma bateria 9V ou por uma fonte de alimentação. Eles podem ser
programados pelo computador e, em seguida, desconectados, permitindo
assim que trabalhem independentemente do computador.Monk (2015)  

# 2 LISTA DE MATERIAIS

| Materiais                                      | Quantidade |
|:-----------------------------------------------|:----------:|
| Arduino UNO R3                                 |     1      |
| Case para Arduino UNO                          |     1      |
| LED Difuso 5mm Vermelho                        |     4      |
| Resistor de 220 Ohm                            |     4      |
| Resistor de 100 Ohm                            |     4      |
| Resistor de 150 Ohm                            |     4      |
| Resistor de 10k Ohm                            |     4      |
| Potenciometro 10k                              |     1      |
| Display LCD 16×2 Backlight Verde               |     1      |
| Sensor Óptico Reflexivo TCRT5000               |     4      |
| Cabos Jumper macho-macho                       |     1      |
| Protoboard                                     |     1      |
| Suporte Bateria 9V Plug P4                     |     1      |
| Bateria Recarregável 9v De Litio 680mah Rontek |     1      |

Lista de materiais

# 3 DESENVOLVIMENTO

## 3.1 Montagem do projeto

## 3.2 Bateria

## 3.3 Esquemático

# 4 CONCLUSÃO

# 5 APÊNDICE A - PROGRAMAÇÃO

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

# 6 BIBLIOGRAFIA

MONK, S. **Programação com Arduino: começando com Sketches**. \[s.l.\]
Bookman Editora, 2013.

\_\_\_. **Programação com Arduino II: Passos avançados com sketches**.
\[s.l.\] Bookman Editora, 2015.
