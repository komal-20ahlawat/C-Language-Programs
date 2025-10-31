/*
 ============================================================================
 Program Name: C FAQ Assistant
 Author: Komal
 Repository: Hacktoberfest 2025 - C Language Programs by Dimpesh Panwar
 ----------------------------------------------------------------------------
 Problem Statement:
 A simple FAQ-based chatbot that helps beginners understand core C programming
 concepts like variables, loops, pointers, structures, and more.

 ----------------------------------------------------------------------------
 How It Works:
 - The user types a query (e.g., "What is a pointer?")
 - The bot searches a small built-in knowledge base and gives the answer.
 - If the query is unknown, it suggests supported topics.
 - Type "exit" to end the program.

 ----------------------------------------------------------------------------
 Compilation:
 gcc -o faq_assistant faq_assistant.c

 Execution:
 ./faq_assistant

 ----------------------------------------------------------------------------
 Example Input/Output:

 Welcome to the C FAQ Assistant! Type your query or 'exit' to quit.

 Supported queries:
 - variable
 - constant
 - pointer
 - array
 - function
 - loop
 - struct
 - dynamic memory
 - header file
 - compile error
 - runtime error

 You: What is a pointer?
 Bot: A pointer is a variable that stores the memory address of another variable.

 You: What is dynamic memory?
 Bot: Dynamic memory allows runtime allocation using malloc(), calloc(), realloc(), and free().

 You: exit
 Bot: Goodbye! Have a great coding journey! 🌱

 ----------------------------------------------------------------------------
 Time Complexity: O(n) where n = number of FAQ entries
 ============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256

// Structure to store FAQs
typedef struct {
    char keyword[50];
    char answer[300];
} FAQ;

// List of FAQs (simple built-in database)
FAQ faqs[] = {
    {"variable", "A variable is a named memory location used to store data."},
    {"constant", "A constant is a fixed value that cannot be changed during program execution."},
    {"pointer", "A pointer is a variable that stores the memory address of another variable."},
    {"array", "An array is a collection of elements of the same type stored in contiguous memory."},
    {"function", "A function is a block of code that performs a specific task when called."},
    {"loop", "Loops execute a block of code repeatedly until a condition is met."},
    {"struct", "A structure (struct) is a user-defined data type that groups related variables."},
    {"dynamic memory", "Dynamic memory allows runtime allocation using malloc(), calloc(), realloc(), and free()."},
    {"header file", "Header files contain declarations and macros shared between multiple source files."},
    {"compile error", "Compile-time errors occur when code violates syntax rules or uses undeclared identifiers."},
    {"runtime error", "Runtime errors happen during program execution (e.g., division by zero or invalid memory access)."}
};

// Convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = (char)tolower(str[i]);
}

// Display supported keywords
void printSupportedQueries() {
    printf("\nSupported queries:\n");
    printf("- variable\n- constant\n- pointer\n- array\n- function\n");
    printf("- loop\n- struct\n- dynamic memory\n- header file\n");
    printf("- compile error\n- runtime error\n\n");
}

// Search for a keyword in the FAQ list
int searchFAQ(const char *input) {
    int found = 0;
    for (int i = 0; i < (int)(sizeof(faqs) / sizeof(faqs[0])); i++) {
        if (strstr(input, faqs[i].keyword) != NULL) {
            printf("Bot: %s\n\n", faqs[i].answer);
            found = 1;
            break;
        }
    }
    return found;
}

int main() {
    char input[MAX_INPUT];

    printf("=============================================\n");
    printf("🤖 Welcome to the C FAQ Assistant!\n");
    printf("Type your query or 'exit' to quit.\n");
    printf("=============================================\n");
    printSupportedQueries();

    while (1) {
        printf("You: ");
        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = 0; // Remove newline
        toLowerCase(input);

        if (strcmp(input, "exit") == 0) {
            printf("Bot: Goodbye! Have a great coding journey! 🌱\n");
            break;
        }

        if (!searchFAQ(input)) {
            printf("Bot: Sorry, I didn't understand that.\n");
            printSupportedQueries();
        }
    }

    return 0;
}
