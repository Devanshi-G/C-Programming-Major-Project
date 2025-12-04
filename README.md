Secure File Vault - C Major Project

Course: CSEG1032 - Programming in C

Institution: University of Petroleum and Energy Studies

Instructor: Dr. Srinivasan Ramachandran

Faculty: Mr. Mohsin Furkh Dar

Project Overview
Secure File Vault is a Command Line Interface (CLI) application designed to protect sensitive text data. 
It implements file handling and cryptographic logic to encrypt and decrypt files using a user-defined key. 
This project demonstrates modular C programming, separating logic into headers, source files, and reusable functions.

This project was developed to meet the Major Project requirements, focusing on:

File Input/Output (I/O) operations.
Modular programming (separation of .c and .h files).
Robust error handling and input validation.
Features
File Encryption: Transforms readable .txt files into encrypted formats using a custom algorithm and a secret key.
File Decryption: Restores encrypted files to their original readable state (requires the correct key).
Directory Listing: Displays available files in the current directory to help users select files for processing.
Input Validation: Handles buffer overflows and invalid inputs gracefully.
Repository Structure
This project strictly follows the mandatory folder structure defined in the project guidelines:

|-- src/ # Contains all source code (.c files)
|-- include/ # Contains all header files (.h files) 
|-- docs/ # Contains ProjectReport.pdf and design documents
|-- assets/ # Optional images or diagrams
|-- README.md # Project documentation (This file)
|__ sample_input.txt # Sample inputs for auto-evaluation testing
