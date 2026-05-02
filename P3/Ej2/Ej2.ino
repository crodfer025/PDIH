int ledRojo = 13;
int ledAmarillo = 12;
int ledVerde = 11;
int boton = 7; 
void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  
  
  pinMode(boton, INPUT); 
}

void loop() {
  
  int estadoBoton = digitalRead(boton);

  
  if (estadoBoton == HIGH) {
    
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledVerde, LOW);
  } 
  
  else {
    
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(ledVerde, HIGH);
  }
}