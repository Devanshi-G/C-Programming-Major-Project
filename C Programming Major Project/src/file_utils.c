/*File: file_utils.c
Description: Utility to list files in the current directory.
Uses dirent.h for directory traversal.*/

#include <stdio.h>
#include <dirent.h> // Standard C library for directory manipulation
#include "../include/file_utils.h"

void listFiles() {
    struct dirent *de;  // Pointer for directory entry
    DIR *dr = opendir("."); // Open current directory

    if (dr == NULL) {
        printf("Could not open current directory.\n");
        return;
    }

    printf("\n--- Available Files ---\n");
    while ((de = readdir(dr)) != NULL) {
        // Skip . (current) and .. (parent) directories
        if (de->d_name[0] != '.') {
             printf("- %s\n", de->d_name);
        }
    }
    printf("-----------------------\n");
    closedir(dr);
}