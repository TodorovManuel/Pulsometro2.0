// Definiciones de pines
const int PulseSensorPin = A0; // Pin analógico donde está conectado el sensor de pulso

// Variables
unsigned long previousMillis = 0; // Almacena el tiempo del último segundo
const unsigned long interval = 1000; // Intervalo de tiempo en milisegundos (1 segundo)
int beatsInInterval = 0; // Número de pulsos detectados en el intervalo actual
int BPM = 0; // Pulsaciones por minuto

void setup() {
  Serial.begin(9600); // Inicializa la comunicación serial
}

void loop() {
  // Lee el valor del sensor de pulso
  int sensorValue = analogRead(PulseSensorPin);
  
  // Si el valor del sensor está por encima de un umbral, consideramos que hay un pulso
  if (sensorValue > 500) {
    // Incrementa el contador de pulsos
    beatsInInterval++;
  }

  // Verifica si ha pasado el intervalo de tiempo
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // Calcula las pulsaciones por minuto (BPM)
    BPM = beatsInInterval * 60 / (interval / 1000);
    
    // Imprime las BPM en el monitor serial
    Serial.print("BPM: ");
    Serial.println(BPM);
    
    // Reinicia el contador de pulsos y actualiza el tiempo del último segundo
    beatsInInterval = 0;
    previousMillis = currentMillis;
  }
}
