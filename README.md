# Hamming Code Program (8/4)

A C++ program implementing **Hamming (8,4) Code** for encoding, error detection, and correction of 4-bit data sequences. The program adheres to the standard bit arrangement where parity bits are placed at positions corresponding to powers of two (1, 2, 4, 8). It ensures reliable data transmission by detecting single-bit errors, correcting them when possible, and identifying cases with multiple errors.

---

## Features

- **Encoding**: Converts 4-bit input data into an 8-bit Hamming code with parity bits at positions 1, 2, 4, and 8.
- **Error Detection and Correction**:
  - Corrects single-bit errors in received data.
  - Detects and reports multiple errors without attempting blind correction.
- **User Interface**: Simple prompts guide the user to input and review results interactively.

---

## Table of Contents

- [Getting Started](#getting-started)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Example](#example)

---

## Getting Started

### Prerequisites
- C++ compiler (e.g., GCC)
- Basic knowledge of using terminal commands

### Building the Project
1. Clone the repository:
   ```bash
   git clone https://github.com/o0oow/Hamming_Code_8-4.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Hamming_Code_8-4
   ```
3. Compile the program:
   ```bash
   g++ main.cpp -L. -lMylib -o main
   ```

---

## Usage

Run the program:
```bash
./main
```

Follow the on-screen prompts to:
1. Enter **4 data bits** (0s and 1s) for encoding.
2. Provide an **8-bit received code** to detect and correct errors.

---

## How It Works

1. **Hamming (8,4) Encoding**:
   - The program arranges data bits (D1, D2, D3, D4) and parity bits (P1, P2, P3, P4) into the following structure:
     ```
     P1 P2 D1 P3 D2 D3 D4 P4
     ```
   - The parity bits are calculated as follows:
     - `P1` checks bits 1, 3, 5, 7.
     - `P2` checks bits 2, 3, 6, 7.
     - `P3` checks bits 4, 5, 6, 7.
     - `P4` checks bits 8.

2. **Error Detection and Correction**:
   - For the received code, the program calculates parity bits again.
   - If a single error is detected, it identifies and corrects the erroneous bit.
   - If multiple errors are detected, the program outputs a message: **"Too many errors detected!"** without attempting correction.

---

## Example

### Encoding

**Input**:  
```
Enter 4 data bits (0 or 1): 1 0 1 1
```

**Output**:  
```
Encoded Hamming Code: 0 1 1 0 0 1 1 0
```

---

### Error Detection and Correction

#### Single-Bit Error:
**Input**:  
```
Enter the received code (8 bits): 1 1 1 0 0 1 1 0
```

**Output**:  
```
Error detected at position: 8
Corrected code: 0 1 1 0 0 1 1 0
Decoded data: 1 0 1 1
```

#### Multiple Errors:
**Input**:  
```
Enter the received code (8 bits): 1 1 0 1 0 0 1 1
```

**Output**:  
```
Too many errors detected! Unable to correct.
```

---

## Notes and Extensions

The Hamming (8,4) Code is widely used for error detection and correction in memory systems and telecommunications. However, it has limitations:
- Can only correct single-bit errors.
- Cannot handle burst or multiple-bit errors.

For more robust error correction, consider exploring advanced algorithms like BCH codes or Reed-Solomon codes.
