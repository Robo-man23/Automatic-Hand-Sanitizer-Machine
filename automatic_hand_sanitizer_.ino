// Automatic hand sanitizer machine
// By ~ Rhythm Shah

const int trigPin = 6;
const int echoPin = 5;
const int relayPin = 8;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Ensure the relay is off initially
  Serial.begin(9600); // For debugging
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  // If distance is within 4 cm
  if (distance > 0 && distance <= 4) {
    digitalWrite(relayPin, HIGH); // Turn on the pump
    delay(2000); // Keep the pump on for 2 seconds
    digitalWrite(relayPin, LOW); // Turn off the pump
    delay(10000); // Wait for 10 seconds before allowing another operation
  }

  delay(100); // Short delay to stabilize the sensor reading
}
