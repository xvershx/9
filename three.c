#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_NUMBERS 100

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *input_file = fopen("C:/Users/alexe/Desktop/GBIOT/New in  c/9/twoinput.txt", "r");
    FILE *output_file = fopen("C:/Users/alexe/Desktop/GBIOT/New in  c/9/twooutput.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Ошибка при открытии файлов.\n");
        return 1;
    }
    char input_string[MAX_LENGTH];
    int numbers[MAX_NUMBERS];
    int count = 0;
    fgets(input_string, MAX_LENGTH, input_file);
    int i = 0;
    while (input_string[i] != '\0') {
        if (isdigit(input_string[i])) {
            numbers[count++] = atoi(input_string + i);
            while (isdigit(input_string[i])) {
                i++;
            }
        } else {
            i++;
        }
    }
    qsort(numbers, count, sizeof(int), compare);
    for (int i = 0; i < count; i++) {
        fprintf(output_file, "%d ", numbers[i]);
    }
    fclose(input_file);
    fclose(output_file);

    return 0;
}
