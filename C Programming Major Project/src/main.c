/*File: main.c
Description: Entry point. (buffer clearing to prevent menu looping/glitches.)*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/auth.h"
#include "../include/crypto.h"
#include "../include/file_utils.h"

// Helper function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice;
    int loggedIn = 0; // Flag to track login status (0=Guest, 1=User)

    printf("========================================\n");
    printf("      SECURE FILE VAULT SYSTEM          \n");
    printf("========================================\n");

    while (1) {
        if (!loggedIn) {
            // Guest Menu
            printf("\n1. Signup\n2. Login\n3. Exit\n");
            printf("Enter Choice: ");
            
            // Check if input is valid integer
            if(scanf("%d", &choice) != 1) {
                printf("Invalid input! Please enter a number.\n");
                clearInputBuffer(); // Clear bad input
                continue;
            }
            clearInputBuffer(); // Clear the 'Enter' key from buffer

            switch (choice) {
                case 1: 
                    signup(); 
                    break;
                case 2: 
                    loggedIn = login(); 
                    break;
                case 3: 
                    printf("Exiting... Goodbye!\n");
                    exit(0);
                default: 
                    printf("Invalid Choice.\n");
            }
        } else {
            // User Menu (Only visible after login)
            char filename[100];
            char key[50];

            printf("\n--- VAULT OPERATIONS ---\n");
            printf("1. List Files\n2. Encrypt File\n3. Decrypt File\n4. Logout\n");
            printf("Enter Choice: ");
            
            if(scanf("%d", &choice) != 1) {
                printf("Invalid input! Please enter a number.\n");
                clearInputBuffer();
                continue;
            }
            clearInputBuffer(); // Clear the 'Enter' key

            switch (choice) {
                case 1:
                    listFiles();
                    break;
                case 2:
                    printf("Enter filename to encrypt (e.g., test.txt): ");
                    scanf("%s", filename);
                    clearInputBuffer(); // Clear buffer after string input

                    printf("Enter a secret key: ");
                    scanf("%s", key);
                    clearInputBuffer(); // Clear buffer after string input
                    
                    encryptFile(filename, key);
                    break;
                case 3:
                    printf("Enter filename to decrypt (e.g., test.txt.enc): ");
                    scanf("%s", filename);
                    clearInputBuffer();

                    printf("Enter the secret key: ");
                    scanf("%s", key);
                    clearInputBuffer();
                    
                    decryptFile(filename, key);
                    break;
                case 4:
                    loggedIn = 0; // Reset login flag
                    printf("Logged out successfully.\n");
                    break;
                default:
                    printf("Invalid Choice.\n");
            }
        }
    }
    return 0;
}