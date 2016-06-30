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
  // read the pushbutton input pin:
  knockState = digitalRead(knockPin);

  // compare the buttonState to its previous state
  if (knockState != lastKnockState) {
    // if state has changed, increment the counter
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
/*
  if (knockCounter % 3 == 0) {
    digitalWrite(ledPin0, HIGH);
  } else {
    digitalWrite(ledPin0, LOW);
  }

  if (knockCounter % 5 == 0) {
    digitalWrite(ledPin1, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
  }

  if (knockCounter % 2 == 0) {
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
  }

  if (knockCounter % 7 == 0) {
    digitalWrite(ledPin3, HIGH);
  } else {
    digitalWrite(ledPin3, LOW);
  }*/

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

/*
Wire up your Knock sensor. Connect it to VCC, GND, and a digital pin.
Hook up a couple of LEDs to digital pins.

In the setup:
Set up your LEDs as OUTPUT and the knock sensor as an INPUT
Define some variables: knockCounter, knockState, lastKnockState

In the loop:
Digital read the Knock sensor. Send this value to knockState.
Use some conditionals. If the state has changed then increment the counter,
Output some text to the serial monitor so you can track when shit happens.
After this, set lastKnockState equal to the current knockState
Then use some conditionals to create the FizzBuzz stuff. The modulus operator is useful.
In these conditionals, turn on the appropriate LEDs.

Upload. Tap breadboard lightly. Watch the serial monitor. Watch the LEDs.

Success.

*/

