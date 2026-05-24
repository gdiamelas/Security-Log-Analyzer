#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int failed_attempts = 0;

    // Opening the log file for reading
    file = fopen("server_logs.txt", "r");
    
    if (file == NULL) {
        printf("Error: Could not open server_logs.txt\n");
        return 1;
    }

    printf("=== SECURITY LOG ANALYZER ===\n");
    printf("Scanning for suspicious activities...\n\n");

    // Reading the file line by line
    while (fgets(line, sizeof(line), file)) {
        // Checking if the line contains the word "FAILED"
        if (strstr(line, "FAILED") != NULL) {
            printf("[ALERT] Suspicious Activity Found: %s", line);
            failed_attempts++;
        }
    }

    printf("\n=== ANALYSIS REPORT ===\n");
    printf("Total Failed Login Attempts Detected: %d\n", failed_attempts);
    
    if (failed_attempts > 3) {
        printf("Security Status: WARNING (Potential Brute-Force Attack)\n");
    } else {
        printf("Security Status: SECURE\n");
    }

    // Always close the file to prevent memory leaks
    fclose(file);
    return 0;
}