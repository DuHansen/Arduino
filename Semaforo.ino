const int redPin = 10;
const int yellowPin = 11;
const int greenPin = 12;
const int pedRedPin = 8;
const int pedGreenPin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(pedRedPin, OUTPUT);
  pinMode(pedGreenPin, OUTPUT);
}

void loop() {
  // Luz vermelha (carros) e verde (pedestres)
  digitalWrite(redPin, HIGH);
  digitalWrite(pedGreenPin, HIGH);
  digitalWrite(pedRedPin, LOW);
  delay(5000); // Espera 5 segundos
  
  // Desliga luz vermelha e verde do pedestre
  digitalWrite(redPin, LOW);
  digitalWrite(pedGreenPin, LOW);
  
  // Luz verde (carros) e vermelha (pedestres)
  digitalWrite(greenPin, HIGH);
  digitalWrite(pedRedPin, HIGH);
  delay(5000); // Espera 5 segundos
  
  // Desliga luz verde
  digitalWrite(greenPin, LOW);
  
  // Luz amarela (carros) e vermelho piscando (pedestres)
  digitalWrite(yellowPin, HIGH);
  for (int i = 0; i < 10; i++) { // Pisca 10 vezes em 2 segundos
    digitalWrite(pedRedPin, HIGH);
    delay(100); // Espera 0.1 segund
    digitalWrite(pedRedPin, LOW);
    delay(100); // Espera 0.1 segundo
  }
  digitalWrite(yellowPin, LOW);
}
