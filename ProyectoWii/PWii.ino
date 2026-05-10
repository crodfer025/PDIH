// ==========================================
// BARRA SENSORA IR CON INDICADORES DE ESTADO
// ==========================================

const int pinTransistor = 10; // Control del NPN PN2222 (La potencia IR)
const int pinLedVerde = 13;   // Indicador visual de ON
const int pinLedRojo = 12;    // Indicador visual de OFF (Corregido)
const int pinBoton = 2;       // Pin de lectura del botón físico (Corregido)

// Variables para la Máquina de Estados
bool estadoBarra = false;       // Comienza apagada por defecto
bool estadoBotonAnterior = LOW; 

void setup() {
  // Configuramos todos los actuadores como salidas
  pinMode(pinTransistor, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinLedRojo, OUTPUT);
  
  // Configuramos el botón como entrada con resistencia interna
  pinMode(pinBoton, INPUT_PULLUP); 

  // --- ESTADO INICIAL DEL SISTEMA ---
  // Nos aseguramos de que al enchufar el Arduino, la placa refleje 
  // visualmente que la barra está apagada.
  digitalWrite(pinTransistor, LOW);  // IR apagado
  digitalWrite(pinLedVerde, LOW);    // Verde apagado
  digitalWrite(pinLedRojo, HIGH);    // Rojo encendido
}

void loop() {
  // Leemos el botón
  bool estadoBotonActual = digitalRead(pinBoton);

  // Detectamos el "Flanco de Bajada" (pulsación exacta)
  if (estadoBotonActual == LOW && estadoBotonAnterior == HIGH) {
    
    // Invertimos el estado lógico
    estadoBarra = !estadoBarra;
    
    // --- APLICAMOS EL NUEVO ESTADO AL HARDWARE ---
    if (estadoBarra == true) {
      // SISTEMA ACTIVO (ON)
      digitalWrite(pinTransistor, HIGH); // Abre el transistor (IR ON)
      digitalWrite(pinLedVerde, HIGH);   // Enciende aviso Verde
      digitalWrite(pinLedRojo, LOW);     // Apaga aviso Rojo
      
    } else {
      // SISTEMA EN REPOSO (OFF)
      digitalWrite(pinTransistor, LOW);  // Cierra el transistor (IR OFF)
      digitalWrite(pinLedVerde, LOW);    // Apaga aviso Verde
      digitalWrite(pinLedRojo, HIGH);    // Enciende aviso Rojo
    }
    
    // Filtro anti-rebote (Debounce)
    delay(50);
  }

  // Guardamos el estado para el siguiente ciclo
  estadoBotonAnterior = estadoBotonActual;
}