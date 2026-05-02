// Importamos la librería que controla el servomotor
#include <Servo.h>

int pinBoton = 7;
int pinServo = 9;

// Creamos un objeto servo para poder darle órdenes
Servo miMotor; 

void setup() {
  // Configuramos el botón como ENTRADA
  pinMode(pinBoton, INPUT);
  
  // Le decimos al Arduino a qué pin está conectado nuestro servo
  miMotor.attach(pinServo);
  
  // Ponemos el motor en la posición inicial (0 grados)
  miMotor.write(0);
}

void loop() {
  // Leemos si el botón está pulsado
  int estadoBoton = digitalRead(pinBoton);

  // Si lo estamos pulsando
  if (estadoBoton == HIGH) {
    // Le ordenamos al servo que gire hasta los 90 grados
    miMotor.write(90);
  } 
  else {
    miMotor.write(0);
  }
  delay(15); 
}