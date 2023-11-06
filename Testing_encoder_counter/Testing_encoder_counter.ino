const int encoderPinA = 16; // Replace with the GPIO pin connected to the encoder signal
const int encoderPinB = 17;

volatile int encoderValueA = 0;

void setup() {
  pinMode(encoderPinA, INPUT);
  attachInterrupt(digitalPinToInterrupt(encoderPinA), handleEncoder, CHANGE);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Your main loop code
  // Print the encoder value to the serial monitor
  Serial.println(encoderValueA);
  delay(100); // Add a delay to avoid printing too rapidly
}

void handleEncoder() {
  encoderValueA++; // Increment the encoder value on every change
}
