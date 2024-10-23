/*
  NAND Gate Test Bench for Arduino UNO 33
  -----------------------------------------
  This sketch tests a 2-input NAND gate by setting all possible
  input combinations on D2 and D3, reading the output on D4,
  and verifying it against the expected NAND truth table.

  Connections:
    - D2: Input 1 (controlled by Arduino)
    - D3: Input 2 (controlled by Arduino)
    - D4: Output (from NAND gate to Arduino)
*/

const int inputPin1 = 2; // D2
const int inputPin2 = 3; // D3
const int outputPin = 4;  // D4

// Structure to hold test cases
struct TestCase {
  bool input1;
  bool input2;
  bool expectedOutput;
};

TestCase testCases[] = {
  {LOW,  LOW,  HIGH}, // 0 NAND 0 = 1
  {LOW,  HIGH, HIGH}, // 0 NAND 1 = 1
  {HIGH, LOW,  HIGH}, // 1 NAND 0 = 1
  {HIGH, HIGH, LOW}   // 1 NAND 1 = 0
};

const int numTestCases = sizeof(testCases) / sizeof(TestCase);

void setup() {
  // Initialize Serial Communication
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for Serial port to connect. Needed for native USB
  }
  Serial.println("Starting NAND Gate Test Bench...");

  // Initialize input pins as OUTPUT
  pinMode(inputPin1, OUTPUT);
  pinMode(inputPin2, OUTPUT);

  // Initialize output pin as INPUT
  pinMode(outputPin, INPUT);

  delay(1000); // Wait for setup to stabilize
}

void loop() {
  for (int i = 0; i < numTestCases; i++) {
    // Apply inputs to the NAND gate
    digitalWrite(inputPin1, testCases[i].input1);
    digitalWrite(inputPin2, testCases[i].input2);

    // Small delay to allow signals to stabilize
    delay(100);

    // Read the output from the NAND gate
    bool actualOutput = digitalRead(outputPin);

    // Compare actual output with expected output
    bool testPassed = (actualOutput == testCases[i].expectedOutput);

    // Print the test results
    Serial.print("Test Case ");
    Serial.print(i + 1);
    Serial.print(": Input1=");
    Serial.print(testCases[i].input1 ? "HIGH" : "LOW");
    Serial.print(", Input2=");
    Serial.print(testCases[i].input2 ? "HIGH" : "LOW");
    Serial.print(" | Expected Output=");
    Serial.print(testCases[i].expectedOutput ? "HIGH" : "LOW");
    Serial.print(", Actual Output=");
    Serial.print(actualOutput ? "HIGH" : "LOW");
    Serial.print(" | ");
    Serial.println(testPassed ? "PASS" : "FAIL");
  }

  Serial.println("Test Bench Completed. Restarting Tests...\n");

  delay(5000); // Wait before restarting tests
}
