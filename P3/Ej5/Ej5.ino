int pinLDR = A0; // Pin analógico para leer el sensor
int pinLED = 9;  // Pin digital con PWM

void setup() {
  // El pin A0 no hace falta declararlo como INPUT, los pines analógicos lo son por defecto
  pinMode(pinLED, OUTPUT); 
  
  Serial.begin(9600);
}

void loop() {
  // analogRead nos dará un número entre 0 y 1023 dependiendo de la luz
  int valorLuz = analogRead(pinLDR);

  // Usamos map(valorLeido, minimoLeido, maximoLeido, minimoDeseado, maximoDeseado)
  // Convertimos el rango de 0-1023 al rango de 0-255 del LED
  int brilloLED = map(valorLuz, 50, 950, 255, 0); 
  //Nos aseguramos de que el resultado NUNCA baje de 0 ni pase de 255
  brilloLED = constrain(brilloLED, 0, 255);

  analogWrite(pinLED, brilloLED); 
  delay(100); // Pequeña pausa para dar estabilidad al programa
}