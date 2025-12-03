/*File: crypto.h
Description: Header file for encryption and decryption logic.*/

#ifndef CRYPTO_H
#define CRYPTO_H

/*Function: encryptFile
Purpose: Reads a file and encrypts it using XOR cipher.
Parameters: filename (char*), key (char*)*/
void encryptFile(char *filename, char *key);

/*Function: decryptFile
Purpose: Reads an encrypted file and reverses the XOR cipher.
Params: filename (char*), key (char*)*/
void decryptFile(char *filename, char *key);

#endif