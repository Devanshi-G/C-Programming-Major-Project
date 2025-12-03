/*File: auth.c
Description: Implementation of user authentication (Signup/Login).
Uses a text file 'users.txt' as a simple database.*/

#include <stdio.h>
#include <string.h>
#include "../include/auth.h"

// filename where user data is stored
const char *USER_DB = "users.txt";

void signup() {
    User u;
    FILE *fp;

    // Open file in Append mode
    fp = fopen(USER_DB, "a"); 
    if (fp == NULL) {
        printf("Error: Could not open user database.\n");
        return;
    }

    printf("\n--- SIGNUP ---\n");
    printf("Enter new username: ");
    scanf("%s", u.username);
    printf("Enter new password: ");
    scanf("%s", u.password);

    // Write username and password to file separated by space
    fprintf(fp, "%s %s\n", u.username, u.password);
    
    printf("User registered successfully!\n");
    fclose(fp); // Always close the file to save changes
}

int login() {
    char inputUser[50], inputPass[50];
    char fileUser[50], filePass[50];
    FILE *fp;
    int loginSuccess = 0;

    printf("\n--- LOGIN ---\n");
    printf("Username: ");
    scanf("%s", inputUser);
    printf("Password: ");
    scanf("%s", inputPass);

    // Open file in Read mode
    fp = fopen(USER_DB, "r");
    if (fp == NULL) {
        printf("No users found. Please signup first.\n");
        return 0;
    }

    // Read file line by line to match credentials
    while (fscanf(fp, "%s %s", fileUser, filePass) != EOF) {
        // strcmp returns 0 if strings are identical
        if (strcmp(inputUser, fileUser) == 0 && strcmp(inputPass, filePass) == 0) {
            loginSuccess = 1;
            break; // Stop searching if found
        }
    }

    fclose(fp);

    if (loginSuccess) {
        printf("Login Successful! Welcome, %s.\n", inputUser);
        return 1;
    } else {
        printf("Login Failed! Invalid credentials.\n");
        return 0;
    }
}