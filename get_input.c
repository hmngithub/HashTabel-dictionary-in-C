#include <stdio.h>
#include <stdlib.h>
typedef char *string;
int get_int(string message)
{
    printf("%s", message);
    int input = 0;
    scanf("%i", &input);
    return input;
}

char get_char(string message)
{
    printf("%s", message);
    char input = 'a';
    scanf("%c", &input);
    return input;
}

double get_double(string message)
{
    printf("%s", message);
    double input = 0.0;
    scanf("%f", &input);
    return input;
}

string get_string(string message)
{
    printf("%s", message);
    string input = malloc(20 * sizeof(char));
    scanf("%s", input);
    return input;
}