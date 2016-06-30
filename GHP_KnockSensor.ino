const int knockPin = 3;
const int ledPin0 = 15;
const int ledPin1 = 8;
const int ledPin2 = 7;
const int ledPin3 = 4;

int knockCounter = -1;
int knockState = 0;
int lastKnockState = 0;

void setup() {
  pinMode(knockPin, INPUT);
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  knockState = digitalRead(knockPin);

  if (knockState != lastKnockState) {
    if (knockState == HIGH) {
      // if knock detected
      knockCounter++;
      Serial.println("Knock detected.");
      Serial.print("Number of knocks:  ");
      Serial.println(knockCounter);
    } else {
      // If knock no longer detected
      Serial.println("Knock no longer detected.");
    }
  }
  lastKnockState = knockState;

  light(ledPin0, 3);
  light(ledPin1, 5);
  light(ledPin2, 2);
  light(ledPin3, 7);
  
}

void light(int ledPin, int mod) {
  if (knockCounter % mod == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
}
