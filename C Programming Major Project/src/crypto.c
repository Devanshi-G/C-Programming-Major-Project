/*File: crypto.c
Description: Contains the core logic for the Secure File Vault.
Algorithm: XOR Cipher (Symmetric Encryption).
Note: XOR is reversible. (A ^ Key) ^ Key = A.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/crypto.h"

void encryptFile(char *filename, char *key) {
    FILE *src, *dest;
    char outName[105];
    int ch;
    int keyLen = strlen(key); // Get length of the secret key
    int i = 0;

    // Open source file in Binary Read mode
    src = fopen(filename, "rb");
    if (src == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        return;
    }

    // Prepare output filename (e.g., secret.txt -> secret.txt.enc)
    sprintf(outName, "%s.enc", filename);
    dest = fopen(outName, "wb"); // Binary Write mode

    printf("Encrypting...\n");

    // Process file byte by byte
    while ((ch = fgetc(src)) != EOF) {
        // XOR the character with the corresponding key character
        // We use modulo (%) to loop the key if the file is longer than the key
        char encryptedChar = ch ^ key[i % keyLen];
        fputc(encryptedChar, dest);
        i++;
    }

    // Close streams
    fclose(src);
    fclose(dest);
    
    // Optional: Delete original file for security
    // remove(filename); 
    
    printf("Success! Encrypted file saved as: %s\n", outName);
}

void decryptFile(char *filename, char *key) {
    FILE *src, *dest;
    char outName[100];
    int ch;
    int keyLen = strlen(key);
    int i = 0;

    // Open the encrypted file
    src = fopen(filename, "rb");
    if (src == NULL) {
        printf("Error: Encrypted file not found.\n");
        return;
    }

    // Remove the .enc extension for the output filename
    // Example: data.txt.enc -> decrypted_data.txt
    if(strstr(filename, ".enc")) {
        strncpy(outName, filename, strlen(filename) - 4);
        outName[strlen(filename) - 4] = '\0'; // Null terminate
    } else {
        strcpy(outName, "decrypted_output");
    }

    char finalName[120];
    sprintf(finalName, "decrypted_%s", outName);

    dest = fopen(finalName, "wb");

    printf("Decrypting...\n");

    // XOR Decryption Logic (Identical to encryption)
    while ((ch = fgetc(src)) != EOF) {
        char decryptedChar = ch ^ key[i % keyLen];
        fputc(decryptedChar, dest);
        i++;
    }

    fclose(src);
    fclose(dest);
    printf("Success! File restored as: %s\n", finalName);
}