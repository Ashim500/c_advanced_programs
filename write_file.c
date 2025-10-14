#include <stdio.h>

int main() {
    FILE *file;
    
    file = fopen("message.txt", "w");
    
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a text file.\n");
    fprintf(file, "Number: %d\n", 42);
    
    fclose(file);
    printf("File written successfully!\n");
    
    return 0;
}