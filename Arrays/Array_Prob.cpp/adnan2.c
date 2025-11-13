#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DOCS 10
#define MAX_LEN 300

// Function to convert string to lowercase
void toLower(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
}

int main() {
    int n;
    char docs[MAX_DOCS][MAX_LEN], query[MAX_LEN];

    // Input number of documents
    printf("Enter number of documents: ");
    scanf("%d", &n);
    getchar();  // Consume newline after number input

    // Input documents
    printf("Enter documents:\n");
    for (int i = 0; i < n; i++) {
        fgets(docs[i], MAX_LEN, stdin);
        docs[i][strcspn(docs[i], "\n")] = '\0';  // Remove newline character
    }

    // Input query word
    printf("Enter search query: ");
    fgets(query, MAX_LEN, stdin);
    query[strcspn(query, "\n")] = '\0';  // Remove newline character
    toLower(query);  // Convert query to lowercase

    // Search for query word in each document
    int found = 0;
    for (int i = 0; i < n; i++) {
        char docCopy[MAX_LEN];
        strcpy(docCopy, docs[i]);
        toLower(docCopy);  // Convert document to lowercase

        // If query word is found in document
        if (strstr(docCopy, query) != NULL) {
            printf("Document %d: %s\n", i + 1, docs[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching documents found.\n");
    }

    return 0;
}
