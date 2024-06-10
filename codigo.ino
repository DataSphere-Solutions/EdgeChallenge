// Definição dos pinos do Arduino Uno
int PinoVelocidade = 3;    // Velocidade do motor, ligado ao pino 3 do Arduino
int input1_motor1 = 6;     // Motor 1, pino 6 do Arduino
int input2_motor1 = 5;     // Motor 1, pino 5 do Arduino
int input2_motor2 = 10;    // Motor 2, pino 10 do Arduino
int input1_motor2 = 9;     // Motor 2, pino 9 do Arduino
int botaoEsquerda = 2;     // Botão para a esquerda, ligado ao pino 2 do Arduino
int botaoParar = 7;        // Botão para parar, ligado ao pino 7 do Arduino
int botaoDireita = 4;      // Botão para a direita, ligado ao pino 4 do Arduino

boolean motorEsquerdaLigado = false;
boolean motorDireitaLigado = false;

void setup()
{
  // Inicialização do Serial
  Serial.begin(9600);
  Serial.println("Controle do motor:");
  Serial.println("Aperte os botoes para controlar os motores");
  
  // Configuração dos pinos como saída
  pinMode(PinoVelocidade, OUTPUT);
  pinMode(input1_motor1, OUTPUT);
  pinMode(input2_motor1, OUTPUT);
  pinMode(input1_motor2, OUTPUT);
  pinMode(input2_motor2, OUTPUT);
  
  // Configuração dos pinos dos botões como entrada
  pinMode(botaoEsquerda, INPUT_PULLUP);
  pinMode(botaoParar, INPUT_PULLUP);
  pinMode(botaoDireita, INPUT_PULLUP);
}

void loop()
{
  // Velocidade de rotação [0 - 255] PWM
  int pwm = 255;
  analogWrite(PinoVelocidade, pwm);
  
  // Leitura dos botões
  if (digitalRead(botaoEsquerda) == LOW)
  {
    if (!motorEsquerdaLigado) {
      // Motor gira para a esquerda
      digitalWrite(input1_motor1, HIGH);
      digitalWrite(input2_motor1, LOW);
      digitalWrite(input1_motor2, HIGH);
      digitalWrite(input2_motor2, LOW);
      Serial.println("Motores girando para a esquerda <<<");
      motorEsquerdaLigado = true;
    }
  }
  else {
    motorEsquerdaLigado = false;
  }
  
  if (digitalRead(botaoDireita) == LOW)
  {
    if (!motorDireitaLigado) {
      // Motor gira para a direita
      digitalWrite(input1_motor1, LOW);
      digitalWrite(input2_motor1, HIGH);
      digitalWrite(input1_motor2, LOW);
      digitalWrite(input2_motor2, HIGH);
      Serial.println("Motores girando para a direita >>>");
      motorDireitaLigado = true;
    }
  }
  else {
    motorDireitaLigado = false;
  }

  // Verifica se o botão de parar foi pressionado
  if (digitalRead(botaoParar) == LOW)
  {
    // Desliga ambos os motores
    digitalWrite(input1_motor1, LOW);
    digitalWrite(input2_motor1, LOW);
    digitalWrite(input1_motor2, LOW);
    digitalWrite(input2_motor2, LOW);
    Serial.println("Motores parados");
    // Adiciona um pequeno atraso para evitar múltiplas detecções do botão
    delay(50);
  }
}
