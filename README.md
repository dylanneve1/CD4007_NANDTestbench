# NAND Gate Test Bench for Arduino UNO 33 (CD4007 IC)

This repository contains an Arduino sketch that tests a 2-input NAND gate using an Arduino UNO 33 and the **CD4007** IC. The CD4007 is a versatile MOSFET array that can be configured to implement NAND gates. The sketch systematically applies input combinations to the configured NAND gate, reads its output, and verifies it against the expected NAND truth table. The results are printed to the Serial Monitor.

## Hardware Requirements

- **Arduino UNO 33**
- **CD4007** MOSFET array (configured as a NAND gate)
- Jumper wires
- Breadboard
- Resistors (for input and output stabilization, if needed)

#### Truth Table for NAND Gate

```
| Input 1 | Input 2 | Output (NAND) |
|---------|---------|---------------|
| LOW     | LOW     | HIGH          |
| LOW     | HIGH    | HIGH          |
| HIGH    | LOW     | HIGH          |
| HIGH    | HIGH    | LOW           |
```

## How to Use

1. **Connect the Hardware**  
   Configure the CD4007 IC as a NAND gate by wiring it as described above. Connect the Arduino to the inputs and output of the configured NAND gate.

2. **Upload the Sketch**  
   - Open the Arduino IDE.
   - Select the correct board (**Arduino UNO 33**) and port.
   - Upload the sketch to the Arduino.

3. **Open Serial Monitor**  
   - After uploading, open the Serial Monitor from the Arduino IDE.
   - Set the baud rate to **9600**.

4. **Observe the Results**  
   - The sketch will apply all possible input combinations to the NAND gate and check its output.
   - The test results will be displayed in the Serial Monitor, showing whether each test case passes or fails.

### Example Serial Monitor Output:

```
Starting NAND Gate Test Bench...
Test Case 1: Input1=LOW, Input2=LOW | Expected Output=HIGH, Actual Output=HIGH | PASS
Test Case 2: Input1=LOW, Input2=HIGH | Expected Output=HIGH, Actual Output=HIGH | PASS
Test Case 3: Input1=HIGH, Input2=LOW | Expected Output=HIGH, Actual Output=HIGH | PASS
Test Case 4: Input1=HIGH, Input2=HIGH | Expected Output=LOW, Actual Output=LOW | PASS
Test Bench Completed. Restarting Tests...
```

## Customization

- **Changing Inputs and Outputs:**  
  If you wish to use different pins for the inputs or output, modify the following lines in the code:

  ```
  const int inputPin1 = 2; // Change this to your desired input pin
  const int inputPin2 = 3; // Change this to your desired input pin
  const int outputPin = 4; // Change this to your desired output pin
  ```

- **Adding More Gates:**  
  The **CD4007** can be used to implement other logic gates. You can extend this test bench to test additional logic gates or functions by wiring more pins and modifying the code.

## License

This code is open source and licensed under the MIT License. Feel free to modify and distribute.

## Author

Developed by Dylan Neve. Feel free to reach out for any questions or contributions!
