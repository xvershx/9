#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    FILE *input_file = fopen("C:/Users/alexe/Desktop/GBIOT/New in  c/9/sixin.txt", "r");
    FILE *output_file = fopen("C:/Users/alexe/Desktop/GBIOT/New in  c/9/sixout.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Ошибка при открытии файлов.\n");
        return 1;
    }
    char input_string[MAX_LENGTH];
    int count = 0;
    fgets(input_string, MAX_LENGTH, input_file);
    char *word = strtok(input_string, " ");
    while (word != NULL) {
        int length = strlen(word);
        if (length > 0 && tolower(word[length - 1]) == 'a') {
            count++;
        }
        word = strtok(NULL, " ");
    }
    fprintf(output_file, "%d", count);
    fclose(input_file);
    fclose(output_file);

    return 0;
}
