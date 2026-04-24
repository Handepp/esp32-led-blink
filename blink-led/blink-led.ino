#define LED_PIN 2

// interval blink (ms)
unsigned long interval = 1000;

// state tracking
bool ledState = false;

// timing control
unsigned long previousMillis = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

  Serial.println("=== ESP32 LED Blink System Started ===");
  Serial.print("Blink interval: ");
  Serial.print(interval);
  Serial.println(" ms");
}

void loop() {
  unsigned long currentMillis = millis();

  // non-blocking timer
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // toggle LED state
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);

    // logging
    if (ledState) {
      Serial.println("[STATE] LED ON");
    } else {
      Serial.println("[STATE] LED OFF");
    }

    Serial.print("[DEBUG] Uptime: ");
    Serial.print(currentMillis / 1000);
    Serial.println(" seconds");
  }
}