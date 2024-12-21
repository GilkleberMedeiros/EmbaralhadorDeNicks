#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char * embaralha_string(char * str);
int notin(int num, int num_array[], int tamanho_array);

int main(int argc, char * argv[]) 
{
    if (argc < 2 || argc > 3) {
        printf(
            "Usage: program_name nick_name [number_of_nickname_options_returned]"
        );
        return 1;
    }

    srand(time(NULL));

    if (argc == 2) 
    {
        char * string_embalharada = embaralha_string(argv[1]);
        printf("%s", string_embalharada);
    }
    else if (argc == 3) 
    {
        int numero_de_opcoes = atoi(argv[2]);

        for (int i = 0; i < numero_de_opcoes; i++) 
        {
            char * string_embalharada = embaralha_string(argv[1]);
            printf("%s\n", string_embalharada);
        }
    }
}

char * embaralha_string(char * str)
{
    int tamanho_string = strlen(str);
    int numeros_sorteados[tamanho_string];
    int proximo_index = 0;

    while (proximo_index < tamanho_string) 
    {
        int num = (rand() % tamanho_string);

        if (notin(num, numeros_sorteados, tamanho_string)) 
        {
            numeros_sorteados[proximo_index] = num;
            proximo_index++;
        }
    }

    char * str_copy = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(str_copy, str);

    for (int i = 0; i < tamanho_string; i++) 
    {
        str[i] = str_copy[numeros_sorteados[i]];
    }

    free(str_copy);
    return str;
}

int notin(int num, int num_array[], int tamanho_array) 
{
    for (int i = 0; i < tamanho_array; i++) 
    {
        if (num_array[i] == num) 
        {
            return 0;
        }
    }

    return 1;
}