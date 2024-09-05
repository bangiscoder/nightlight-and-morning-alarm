const int ldrPin = A0; // Analog pin connected to the LDR
const int bulbPin = 9;  // PWM-capable pin (e.g., pin 9 on most Arduino boards)
const int threshold = 300; // Threshold value for the LDR
const int buzzerPin = 11; // Define pin number for the buzzer
const long alarmDelay = 5000;  // 5 seconds
static bool alarm = false;

// Function to calculate the average LDR value
int readLdrValue() {
  int ldrValue = analogRead(ldrPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);
 return ldrValue;
}

// Function to turn off the pin
void turnOffPin() {
  digitalWrite(bulbPin, LOW);  
}

void setup() {
  Serial.begin(9600);
  pinMode(bulbPin, OUTPUT);
}

void loop() {
  // Call the ldrValue function and store the result in ldr
  int ldr = readLdrValue();

  // Check if the LDR value is less than the threshold
  if (ldr < threshold) {
    // Turn on the Bulb
    digitalWrite(bulbPin, HIGH);
     alarm = false;
     Serial.println(alarm);
  }
  
  if(ldr > threshold && alarm == false) {
    alarm = true;
    // Turn off the Bulb pin
    turnOffPin();
    
    tone(buzzerPin, 1000);  // Play a 1000 Hz tone
    delay(500);
    noTone(buzzerPin);  // Play a 1000 Hz tone
    delay(500);

    Serial.println(alarm);

    tone(buzzerPin, 1000);  // Play a 1000 Hz tone
    delay(500);
    noTone(buzzerPin);  // Play a 1000 Hz tone
    delay(500);

    Serial.println(alarm);

    tone(buzzerPin, 1000);  // Play a 1000 Hz tone
    delay(500);
    noTone(buzzerPin);  // Play a 1000 Hz tone
    delay(500);

    Serial.println(alarm);

    tone(buzzerPin, 1000);  // Play a 1000 Hz tone
    delay(500);
    noTone(buzzerPin);  // Play a 1000 Hz tone
    delay(500);

    Serial.println(alarm);

    tone(buzzerPin, 1000);  // Play a 1000 Hz tone
    delay(500);
    noTone(buzzerPin);  // Play a 1000 Hz tone
    delay(500);

    Serial.println("Alarm");
    
  }

  // Wait for 500 milliseconds before the next loop
  delay(500);
}
