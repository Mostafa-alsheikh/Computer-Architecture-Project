#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int numBits = 4;
const int opBits = 3;

// Pins for input numbers A and B
int A[numBits] = {2, 3, 4, 5};
int B[numBits] = {6, 7, 8, 9};

// Pins for operation code
int Op[opBits] = {10, 11, 12};

// Pin for submit switch
const int submitSwitch = 13;

// Pins for output LEDs
int Result[numBits] = {A0, A1, A2, A3};

// LCD I2C address
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin();
  lcd.begin(16, 2);
  lcd.backlight();

  // Initialize input pins
  for (int i = 0; i < numBits; i++) {
    pinMode(A[i], INPUT_PULLUP);
    pinMode(B[i], INPUT_PULLUP);
  }
  for (int i = 0; i < opBits; i++) {
    pinMode(Op[i], INPUT_PULLUP);
  }

  // Initialize submit switch pin
  pinMode(submitSwitch, INPUT_PULLUP);

  // Initialize output LED pins
  for (int i = 0; i < numBits; i++) {
    pinMode(Result[i], OUTPUT);
  }
}

void loop() {
  if (digitalRead(submitSwitch) == LOW) {
    int a = readBinaryInput(A, numBits);
    int b = readBinaryInput(B, numBits);
    int op = readBinaryInput(Op, opBits);

    int result = 0;
    char operation = ' ';

    switch (op) {
      case 0: // Addition
        result = a + b;
        operation = '+';
        break;
      case 1: // Subtraction
        result = a - b;
        operation = '-';
        break;
      case 2: // AND
        result = a & b;
        operation = '&';
        break;
      case 3: // OR
        result = a | b;
        operation = '|';
        break;
      case 4: // XOR
        result = a ^ b;
        operation = '^';
        break;
      case 5: // NOT A
        result = ~a & 0xF; // Ensure result is 4-bit
        operation = '!';
        break;
      case 6: // Multiplication
        result = (a * b) & 0xF; // Ensure the result fits within 4 bits
        operation = '*';
        break;
      case 7: // Division
        if (b != 0) {
          result = a / b;
          operation = '/';
        } else {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("DIV BY ZERO");
          delay(1000);
          return;
        }
        break;
      default:
        result = 0;
        operation = ' ';
        break;
    }

    displayResult(a, b, operation, result);
    displayLEDs(result);
    delay(1000); // Delay for readability
  }
}

int readBinaryInput(int pins[], int length) {
  int value = 0;
  for (int i = 0; i < length; i++) {
    value |= !digitalRead(pins[i]) << i; // Use !digitalRead to account for INPUT_PULLUP
  }
  return value;
}

void displayResult(int a, int b, char operation, int result) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(a);
  lcd.print(" ");
  lcd.print(operation);
  lcd.print(" ");
  lcd.print(b);
  lcd.print(" = ");
  lcd.print(result);
}

void displayLEDs(int result) {
  for (int i = 0; i < numBits; i++) {
    digitalWrite(Result[i], (result >> i) & 1);
  }
}