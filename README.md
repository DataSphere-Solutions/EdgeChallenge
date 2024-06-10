<div align="center">
  <img src="https://github.com/DataSphere-Solutions/Python-Challenge/assets/152393807/5cefd3e4-9edf-46b6-9976-108b7c2a177a" alt="image">
</div> 

# 🤖 Edge Computing - Sprint 1 - Tech Mahindra
👋 Olá, bem-vindo ao nosso trabalho do Check Point 2 de Edge Computing! Nós somos a empresa Data Sphere da turma 1ESPH, e é um imenso prazer apresentar este projeto.

![Data Sphere1000x1000](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/0fe80a9b-6290-417d-8367-2abe3824d0b0)
Logo da nossa equipe
## 🔮 O que é a Data Sphere?
A Data Sphere Solutions é uma empresa fictícia representando a nossa equipe, formada pelos alunos: 
-  <a href="https://www.linkedin.com/in/artur-alves-tenca-b1ba862b6/">Artur Alves</a> - RM 555171 
- <a href="https://www.linkedin.com/in/giuliana-lucas-85b4532b6/">Giuliana Lucas</a> - RM 557597
- <a href="https://www.linkedin.com/in/ian-monteiro-moreira-a4543a2b7/">Ian Monteiro</a> - RM 558652 
- <a href="https://www.linkedin.com/in/igor-brunelli-ralo-39143a2b7/">Igor Brunelli</a> - RM 555035
- <a href="https://www.linkedin.com/in/matheus-estev%C3%A3o-5248b9238/">Matheus Alcântara</a> - RM 558193

## 👥 Quem é o nosso cliente?
- Nosso cliente é a Tech Mahindra, uma empresa indiana multinacinal de serviços de tecnologia da informação (TI) e consultoria, com sede em Pune, na Índia.
- Fundada em 1986, faz parte do Grupo Mahindra, um dos principais conglomerados empresariais da Índia.

## 🤔 O Problema que nos foi passado
- O Problema que nos foi passado pela Tech Mahindra é como podemos alcançar mais pessoas com a Fórmula E, uma modalidade de corrida de carros elétricos, que não é muito conhecida.

## ✅ A nossa Solução
- Após realizarmos algumas pesquisas de campo com as pessoas, descobrimos que as pessoas mais velhas até conhecem e gostam, mas não possuem tempo para assistir. Já os mais jovens simplesmente não connhecem a Fórmula E.
- Com esses dados, após um brainstorming de ideias, chegamos na ideia de firmar parcerias com escolas, para fins de realizar apresentações para os alunos sobre a Fórmula E, com diversos temas, entre eles:
  - A História da Fórmula E
  - O que são e como funcionam os Carros Elétricos
  - Grandes Pilotos que competiram na modalidade
  - A diferença da Fórmula E para a Fórmula 1
  - E mais
- Além das apresentações, planejamos organizar competições de carrinhos elétricos entre os alunos, estimulando o âmbito competitivo, introduzindo os alunos ao mundo das corridas e saciando a vontade de dirigir carros reais. A primeira competição será livre, com todos os alunos podendo participar. Já a partir da segunda, planejamos exigir uma nota mínima para a participação.
- Planejamos também agendar visitas de nomes importantes da Fórmula E às escolas, como pilotos.
- E por último, planejamos agendar passeios escolares para pistas de corrida, e para marcas que competem na Fórmula E.
- Tudo isso irá introduzir os alunos ao meio da Fórmula E, trazendo uma maior visibilidade a modalidade.

## 💡 Agregando Edge Computing à Solução Pensada
Para realização das competições vamos precisar de carrinhos elétricos. Portanto, desenvolvemos um protótipo no simulador online um protótipo de carrinho elétrico.
![image](https://github.com/DataSphere-Solutions/EdgeChallenge/assets/152393807/cfddd927-3c9b-458b-9306-d46e5f3949f8)
- O protótipo possui 2 motores e uma bateria para alimentá-los, além de 3 botões. O primeiro ao pressionado gira os motores para a esquerda, o do meio para os motores e o da direita os gira para a direita.
- Futuramente, pretendemos adicionar um controle via Bluetooth para os alunos controlarem o carrinho.
![Design sem nome](https://github.com/DataSphere-Solutions/EdgeChallenge/assets/152393807/66c5a84c-e64b-404a-b5c3-272f71c0cdd4)

## 🛠️ Link para o Projeto Desenvolvido no Tinkercad
- https://www.tinkercad.com/things/cMkN4QmE9Jf-copy-of-matriz-l293d-arduino-rotacao/editel?sharecode=K2ms_u634UgAHRU3HsnI3YgyF_ap7iMdj_KgEuqoKY0

## 📄 Vista Esquemática
![image](https://github.com/DataSphere-Solutions/EdgeChallenge/assets/152393807/7bb5b29b-6f5a-4bed-84e6-53083e1cbc14)

## 📝 Lista de Materiais
- x1 Placa Arduino Uno;
- x1 Breadboard;
- x1 Bateria 9V;
- x2 Motores CC;
- x1 Acionador de motor de ponte H L293D;
- x3 Botões;
- x3 Resistores de 150Ω;

## 👨🏻‍💻 O Código do Projeto
- O código do projeto foi desenvolvido 100% em C++, em um arquivo .ino:

```
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

```

## ✅ Créditos
Utilizamos diversas ferramentas e serviços para tornar a realização desse projeto possível, sendo elas:
- ChatGPT: https://chat.openai.com/
- Wokwi: https://wokwi.com/
- Tinkercad: https://www.tinkercad.com/
- Chareditor: https://chareditor.com/
- Wiki de Bibliotecas do Arduino: https://www.arduino.cc/reference/en/libraries/
- Microsoft Teams: https://teams.microsoft.com/
- Github: https://github.com/
- WhatsApp: https://web.whatsapp.com/
