int flamePin = A1;    // Flame sensor OUT
int smokePin = A2;    // Smoke sensor OUT
int pumpPin  = 8;     // Relay IN pin
int buzzer   = 9;     // Buzzer pin

// Change these if sensor logic is inverted
bool FLAME_ACTIVE_LOW  = true;   // LOW = flame detected
bool SMOKE_ACTIVE_HIGH = true;   // HIGH = smoke detected

void setup() {
  pinMode(flamePin, INPUT);
  pinMode(smokePin, INPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(pumpPin, LOW);   // Pump OFF
  digitalWrite(buzzer, LOW);    // Buzzer OFF

  Serial.begin(9600);
  Serial.println("System Started");
}

void loop() {
  int flameRaw = digitalRead(flamePin);
  int smokeRaw = digitalRead(smokePin);

  bool flameDetected = FLAME_ACTIVE_LOW  ? (flameRaw == LOW)  : (flameRaw == HIGH);
  bool smokeDetected = SMOKE_ACTIVE_HIGH ? (smokeRaw == HIGH) : (smokeRaw == LOW);

  // Flame → Pump control
  if (flameDetected) {
    digitalWrite(pumpPin, HIGH);   // Pump ON
    Serial.println("Flame detected - Pump ON");
  } else {
    digitalWrite(pumpPin, LOW);    // Pump OFF
  }

  // Smoke → Buzzer control
  if (smokeDetected) {
    digitalWrite(buzzer, HIGH);    // Buzzer ON
    Serial.println("Smoke detected - Buzzer ON");
  } else {
    digitalWrite(buzzer, LOW);     // Buzzer OFF
  }

  delay(200);
}