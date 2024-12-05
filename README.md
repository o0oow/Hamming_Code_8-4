# Hamming Code Program

A C++ program that implements **Hamming (8,4) Code** for encoding, error detection, and correction of 4-bit data sequences. The program ensures data integrity by detecting and correcting single-bit errors while identifying cases with too many errors. This makes it particularly useful in **digital communication systems**, **memory storage**, and **data transmission**, where maintaining error-free data is critical.

---

## Features

- **Encoding**: Converts 4-bit input data into an 8-bit Hamming code.
- **Error Detection and Correction**:
  - Detects and corrects single-bit errors.
  - Identifies cases with multiple errors ("Too many errors").
- **User-Friendly Interface**: Simple prompts guide the user through the process.

---

## Table of Contents

- [Getting Started](#getting-started)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Example](#example)
- [Additional Notes](#additional-notes)

---

## Getting Started

### Prerequisites
- A C++ compiler (e.g., GCC)
- Basic knowledge of command-line tools

### Building the Project
1. Clone the repository:
   ```bash
   git clone https://github.com/o0oow/Hamming_Code_8-4.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Hamming_Code_8-4
   ```
3. Build the project:
   ```bash
   g++ main.cpp -L. -lMylib -o main
   ```

---

## Usage

Run the program:
```bash
./main
```

Follow the prompts to:
1. Input a **4-bit data sequence** for encoding.
2. Enter an **8-bit received code** for error detection and correction.

---

## How It Works

1. **Hamming (8,4) Encoding**:
   - Encodes 4 data bits (D1, D2, D3, D4) into an 8-bit Hamming code with parity bits (P1, P2, P3, P4).

   ```
   P1 D1 P2 D2 P3 D3 P4 D4
   ```

   The parity bits are calculated as:
   - `P1 = D1 ⊕ D2 ⊕ D4`
   - `P2 = D1 ⊕ D3 ⊕ D4`
   - `P3 = D2 ⊕ D3 ⊕ D4`
   - `P4 = D1 ⊕ D2 ⊕ D3 ⊕ D4`

2. **Error Detection and Correction**:
   - Checks parity bits using the same formula.
   - If there is a single-bit error, it is corrected.
   - If there are multiple errors, the program notifies the user without attempting to fix them.

---

## Example

### Encoding

**Input**:  
```
Enter 4 data bits (0 or 1): 1 0 1 1
```

**Output**:  
```
Encoded Hamming Code: 1 1 0 0 1 0 1 1
```

---

### Error Detection and Correction

**Input**:  
```
Enter the received code (8 bits): 1 1 0 1 1 0 1 1
```

**Output**:  
```
Error detected at position: 4
Corrected code: 1 1 0 0 1 0 1 1
Decoded data: 1 0 1 1
```

**Input (multiple errors)**:  
```
Enter the received code (8 bits): 0 1 0 0 1 1 1 0
```

**Output**:  
```
Too many errors detected! Unable to correct.
```

---

## Additional Notes

While the Hamming Code is effective for single-bit error correction, there are other algorithms that handle more complex error scenarios, such as:

- **BCH Codes**: Correct multiple errors in a fixed-size block.
- **Reed-Solomon Codes**: Widely used in CDs, DVDs, and QR codes.
- **LDPC (Low-Density Parity-Check) Codes**: Efficient for high-throughput communication.
- **Turbo Codes**: Used in wireless communication for high reliability.

These advanced algorithms provide improved error correction at the cost of higher computational complexity. For basic error detection and correction, however, the Hamming Code remains a practical and elegant solution.
