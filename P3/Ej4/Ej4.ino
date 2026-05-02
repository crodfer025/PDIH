int trigPin = 9;  // El que emite el sonido
int echoPin = 10; // El que escucha el rebote
int buzzer = 8;   // El altavoz

void setup() {
  // Configuramos los pines
  pinMode(trigPin, OUTPUT); // Sale el sonido
  pinMode(echoPin, INPUT);  // Entra el sonido
  pinMode(buzzer, OUTPUT);  
  
  // Iniciamos el "Monitor Serie" para ver los datos de la distancia en el ordenador
  Serial.begin(9600); 
}

void loop() {
  // Nos aseguramos de que el Trig esté apagado 2 microsegundos
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Disparamos un pulso de sonido durante 10 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // La función pulseIn() cuenta cuánto tiempo (en microsegundos) 
  // tarda el pin Echo en recibir el rebote (ponerse en HIGH)
  long duracion = pulseIn(echoPin, HIGH);

  // Aplicamos la fórmula matemática (Tiempo * 0.034 / 2)
  long distancia = (duracion * 0.034) / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Si el objeto está a menos de 1 metro (100 cm) pero no pegado (más de 5 cm)
  if (distancia < 100 && distancia > 5) {
    // La pausa entre pitidos será proporcional a la distancia.
    // Ej: Si está a 50cm, la pausa es 50 * 10 = 500 milisegundos.
    int pausa = distancia * 10; 
    
    tone(buzzer, 1000, 100); 
    delay(pausa);            
  } 
  // Si está muy, muy cerca (menos de 5 cm), pitido continuo de peligro
  else if (distancia <= 5) {
    tone(buzzer, 1000); // Pitido sin límite de tiempo
  } 
  // Si está a más de 1 metro, silencio
  else {
    noTone(buzzer); // Apagamos el buzzer
  }
}