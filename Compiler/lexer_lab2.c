#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define YES 1
#define NO 0

// Token structure definition
typedef struct {
    char type[20];
    char value[20];
} token;

token newToken(const char *type, const char *value) {
    token t;
    snprintf(t.type, sizeof(t.type), "%s", type);
    snprintf(t.value, sizeof(t.value), "%s", value);
    return t;
}

void retract(char c) {
    ungetc(c, stdin);
}

void fail() {
    printf("Lexical error.\n");
    exit(1);
}

// Function to recognize signed integers and real numbers
token getNum() {
    int state = 0;
    char c;
    char numBuffer[20];
    int index = 0;

    while (YES) {
        c = getchar();
        
        switch (state) {
            case 0: // Start state, looking for optional sign or digit
                if (c == '+' || c == '-') { // Signed number
                    numBuffer[index++] = c; // Store the sign
                    state = 1;
                } else if (isdigit(c)) { // Directly a number
                    numBuffer[index++] = c;
                    state = 2;
                } else {
                    fail(); // Invalid character
                }
                break;

            case 1: // After sign, expect digits
                if (isdigit(c)) {
                    numBuffer[index++] = c;
                    state = 2;
                } else {
                    fail(); // Invalid character after sign
                }
                break;

            case 2: // After first digit(s), looking for decimal point or end of number
                if (isdigit(c)) { // More digits, continue
                    numBuffer[index++] = c;
                } else if (c == '.') { // Decimal point, start recognizing real number
                    numBuffer[index++] = c;
                    state = 4;
                } else { // End of integer number
                    retract(c); // Retract the non-numeric character
                    numBuffer[index] = '\0'; // Terminate the string
                    return newToken("Integer", "INT"); // Return as integer token
                }
                break;
            case 3:
            	retract(c);
            	return newToken("Integer", "INT");
            	
            case 4: // After decimal point, expect more digits (real number)
                if (isdigit(c)) {
                    numBuffer[index++] = c;
                    state = 5; // Continue in real number state
                } else {
                    fail(); // Invalid character after decimal point
                }
                break;

            case 5: // After decimal digits, looking for more digits or end of number
                if (isdigit(c)) {
                    numBuffer[index++] = c; // More digits in real number
                } else { // End of real number
                    retract(c); // Retract the non-numeric character
                    numBuffer[index] = '\0'; // Terminate the string
                    return newToken("Real num", "FLOAT"); // Return as real number token
                }
                break;

            default:
                fail(); // Invalid state
        }
    }
}
token getId() {
    int state = 0;
    char c;

    while (YES) {
        c = getchar();  // Read the next character

        switch (state) {
            case 0: // Initial state, expecting a lowercase letter
                if (islower(c)) {  // If the character is a lowercase letter // Store the letter in the buffer
                    state = 1;  // Move to the next state
                } else {
                    fail();  // If it's not a lowercase letter, it's an error
                }
                break;

            case 1: // After a lowercase letter, continue reading letters or digits
                if (islower(c) || isdigit(c)) {  // Store the valid character
                }
                else if(c == '_'){
                    state = 2;
                    }
                     else {  // Encountered an invalid character
                    retract(c);  // Retract the invalid character
            // Null-terminate the identifier
                   return newToken("Identifier", "ID");  // Return the identifier token
                }
                break;

            case 2: // After continuing to add letters or digits, we can keep going
                if (islower(c) || isdigit(c)) {
             // Store the valid character
                }
                 else {  // Encountered an invalid character
                    retract(c);  // Retract the invalid character
                    return newToken("Identifier", "ID");  // Return the identifier token
                }
                break;

            default:
                fail();  // In case of an invalid state, fail
        }
    }
}

int main() {
    token result = getId();
    printf("Token Type: %s, Token Value: %s\n", result.type, result.value);
    return 0;
}