const int button1 = A1;
const int button2 = A2;
const int button3 = 2;
const int button4 = 3;
const int button5 = 4;
const int button6 = 5;
const int button7 = 6;
const int button8 = 7;
const int button9 = 8;

// Define the array to hold the button states
int buttonState[9];

// Define a separate array to store the previous button states
int prevButtonState[9];

// Variables for timing
unsigned long previousMillis = 0;
const unsigned long interval = 50;  // Interval between button state checks (in milliseconds)

void setup() {
  // Initialize the pins for the push buttons as inputs with pull-up resistors
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);
  pinMode(button7, INPUT_PULLUP);
  pinMode(button8, INPUT_PULLUP);
  pinMode(button9, INPUT_PULLUP);

  // Initialize the arrays to all zeros
  for (int i = 0; i < 9; i++) {
    buttonState[i] = 0;
    prevButtonState[i] = 0;
  }

  // Start the serial communication
  Serial.begin(9600);
}

void loop() {
  // Check if it's time to read the button states
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Read the state of each button
    int newState[9] = {
      !digitalRead(button1),
      !digitalRead(button2),
      !digitalRead(button3),
      !digitalRead(button4),
      !digitalRead(button5),
      !digitalRead(button6),
      !digitalRead(button7),
      !digitalRead(button8),
      !digitalRead(button9)
    };

    // Update the button state only if it has changed
    bool stateChanged = false;
    for (int i = 0; i < 9; i++) {
      if (newState[i] != prevButtonState[i]) {
        buttonState[i] = newState[i];
        prevButtonState[i] = newState[i];
        stateChanged = true;
      }
    }

    // Print out the current state of the array if any button state has changed
    if (stateChanged) {
      for (int i = 0; i < 9; i++) {
        if (buttonState[i] == 1) {
          Serial.print(1);
        } else {
          Serial.print(0);
        }
        if (i < 8) {
          Serial.print(",");
        }
      }
      Serial.println();
    }
  }
}
