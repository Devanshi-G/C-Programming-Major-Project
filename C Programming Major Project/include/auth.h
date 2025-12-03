//Header file for authentication module.
//Defines User structure and function prototypes for login/signup.

#ifndef AUTH_H
#define AUTH_H

// Structure to hold user credentials strictly for this session
typedef struct {
    char username[50]; // Stores the username
    char password[50]; // Stores the password
} User;

/*Function: signup
 Purpose: Registers a new user by saving credentials to a file.*/
void signup();

/*Function: login
 Purpose: Verifies user credentials against stored records.
 Returns: 1 if successful, 0 if failed.*/
int login();

#endif