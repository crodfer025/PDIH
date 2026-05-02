// Guardamos los pines en un array para poder recorrerlos fácilmente
int pinesLeds[] = {10, 11, 12, 13}; 
int numLeds = 4; 

// Tiempo en milisegundos que cada LED estará encendido
int tiempoEspera = 150; 

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(pinesLeds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(pinesLeds[i], HIGH); 
    delay(tiempoEspera);              
    digitalWrite(pinesLeds[i], LOW);  
  }
  for (int i = numLeds - 2; i > 0; i--) {
    digitalWrite(pinesLeds[i], HIGH);
    delay(tiempoEspera);
    digitalWrite(pinesLeds[i], LOW);
  }
}