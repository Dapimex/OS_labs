#include <stdio.h>
#include <mem.h>

int main() {
    printf("Print command in form [command] tee [file to read] [file to write] or [command] tee -a [file to write] [string to append");
    char* input;
    gets(input);
    char* argument1, argument2, argument3, argument4, argument5 = NULL;
    argument1 = strtok(input, "");
    argument2 = strtok(NULL, "");
    argument3 = strtok(NULL, "");
    argument4 = strtok(NULL, "");
    argument5 = strtok(NULL, "");

    printf("%s\n", argument1);
    printf("%s\n", argument2);
    printf("%s\n", argument3);
    printf("%s\n", argument4);
    printf("%s\n", argument5);

//    tee(argument1, argument2, argument3,argument4, argument5);
}

void tee(char* argument1, char* argument2, char* argument3, char* argument4, char* argument5) {
    //count - number of arguments, arguments[] - actually arguments

    FILE *read_file, *write_file;
    char temp;
    if (strcmp(argument2, "tee") && (argument5 == NULL)) { //without -a tag
        read_file = fopen(argument3, "r");
        write_file = fopen(argument4, "w");

        while (!feof(read_file)) {
            temp = fgetc(read_file);
            fputc(temp, write_file);
            printf("%c", temp);
        }
        fclose(read_file);
        fclose(write_file);
    }
    else if (strcmp(argument2, "tee") && strcmp(argument3, "-a") && (argument5 != NULL)) { //with tag -a
        write_file = fopen(argument4, "a");
        fputs(argument5, write_file);
        fclose(write_file);
    }
}