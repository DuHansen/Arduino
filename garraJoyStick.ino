#include <Servo.h>

// Define os pinos do servo e do joystick
const int servoPin = 6;    // Pino do servo
const int vrxPin = A0;     // Pino do eixo X do joystick (deve ser um pino analógico)
const int vryPin = A1;     // Pino do eixo Y do joystick (deve ser um pino analógico)
const int swPin = 11;      // Pino do botão do joystick

Servo myServo;             // Instancia o objeto Servo

int angle = 90;            // Posição inicial do servo
const int stepSize = 10;   // Tamanho do incremento/decremento do ângulo
const int angleMin = 0;    // Ângulo mínimo do servo
const int angleMax = 180;  // Ângulo máximo do servo

void setup() {
  myServo.attach(servoPin); // Conecta o servo ao pino especificado
  myServo.write(angle);     // Define a posição inicial do servo

  pinMode(vrxPin, INPUT);   // Define o pino do eixo X como entrada
  pinMode(vryPin, INPUT);   // Define o pino do eixo Y como entrada
  pinMode(swPin, INPUT_PULLUP); // Define o pino do botão como entrada com pull-up interno

  Serial.begin(9600);       // Inicializa a comunicação serial
}

void loop() {
  int buttonState = digitalRead(swPin); // Lê o estado do botão
  int vrxValue = analogRead(vrxPin);    // Lê o valor do eixo X
  int vryValue = analogRead(vryPin);    // Lê o valor do eixo Y

  // Ajusta o ângulo do servo com base na leitura do eixo X
  int newAngle = map(vrxValue, 0, 1023, angleMin, angleMax);

  // Garante que o ângulo esteja dentro dos limites
  if (newAngle > angleMax) newAngle = angleMax;
  if (newAngle < angleMin) newAngle = angleMin;

  // Atualiza o ângulo do servo e armazena o novo ângulo
  if (newAngle != angle) {
    angle = newAngle;
    myServo.write(angle); // Move o servo para o novo ângulo
    Serial.print("Angulo: ");
    Serial.println(angle); // Imprime o ângulo atual no monitor serial
  }

  // Se o botão for pressionado, ajusta o ângulo
  if (buttonState == LOW) { // O botão é pressionado quando o pino está LOW (pull-up interno)
    angle += stepSize; // Incrementa o ângulo
    if (angle > angleMax) angle = angleMax; // Limita o ângulo máximo
    myServo.write(angle); // Move o servo para o novo ângulo
    Serial.print("Angulo: ");
    Serial.println(angle); // Imprime o ângulo atual no monitor serial
    delay(200); // Debounce para evitar múltiplas leituras do botão
  }

  Serial.print("Eixo X: ");
  Serial.print(vrxValue); // Imprime o valor do eixo X no monitor serial
  Serial.print(" | Eixo Y: ");
  Serial.println(vryValue); // Imprime o valor do eixo Y no monitor serial
  Serial.print(" Botao: ");
  Serial.println(buttonState); // Imprime o estado do botão no monitor serial

  delay(100); // Pequeno atraso para evitar leituras excessivas
}
