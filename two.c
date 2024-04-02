
    /*FILE *input_file = fopen("C:/Users/alexe/Desktop/GBIOT/New in  c/9/input.txt", "r");
  FILE *output_file = fopen("C:/Users/alexe/Desktop/GBIOT/New in  c/9/output.txt", "w");
    */

#include <stdio.h>

#define MAX_LENGTH 1000

int main() {
    FILE *input_file = fopen("C:/Users/alexe/Desktop/GBIOT/New in  c/9/input.txt", "r");
    FILE *output_file = fopen("C:/Users/alexe/Desktop/GBIOT/New in  c/9/output.txt", "w");//было выполнение решение указать данный путь в связи с тем, что у меня по другому не открываются

    if (input_file == NULL || output_file == NULL) {
        printf("Ошибка при открытии файлов.\n");
        return 1;
    }

    char input_string[MAX_LENGTH];
    char output_string[MAX_LENGTH];

    fgets(input_string, MAX_LENGTH, input_file);

    for (int i = 0; input_string[i] != '\0'; i++) {
        if (input_string[i] == 'a') {
            output_string[i] = 'b';
        } else if (input_string[i] == 'b') {
            output_string[i] = 'a';
        } else if (input_string[i] == 'A') {
            output_string[i] = 'B';
        } else if (input_string[i] == 'B') {
            output_string[i] = 'A';
        } else {
            output_string[i] = input_string[i];
        }
    }

    fprintf(output_file, "%s", output_string);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
