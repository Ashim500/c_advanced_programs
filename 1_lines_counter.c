#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    int ch;
    int line_count = 0;
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
  
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            line_count++;
        }
    }
    if (ch == EOF && line_count > 0) {
        fseek(file, -1, SEEK_END);
        ch = fgetc(file);
        if (ch != '\n') {
            line_count++;
        }
    }
    
    fclose(file);
    printf("Number of lines: %d\n", line_count);
    
    return 0;
}