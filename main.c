#include <stdio.h>
#include <stdlib.h> // rand() e srand()
#include <time.h>   // time(0)
#include <string.h> // strcpy

// Defines
#define LGTH_MAX 16 // largura máxima

// Structs
typedef struct {
    char value[LGTH_MAX + 1]; // senha com 16 caracteres + 1 (\0)
    short length;
    short hasUppercase;
    short hasNumbers;
    short hasSymbols;
    short strength;
} PasswordData;

// Funções e procedimentos
void displayWelcomePrompt();
void displayGeneratedPassword(const char *auth);
void generateBaseString(PasswordData *auth);
void addSpecialCharacters(PasswordData *auth);
void addUppercaseLetters(PasswordData *auth);

int main(void) {
    PasswordData authPassword = {0}; // Inicializando com valores padrão
    displayWelcomePrompt();          // Exibindo mensagem inicial

    generateBaseString(&authPassword);
    addUppercaseLetters(&authPassword);
    addSpecialCharacters(&authPassword);

    printf("Senha gerada: %s\n", authPassword.value);

    return 0;
}

// Procedimentos
void displayWelcomePrompt() {
    printf("Bem-Vindo\nPressione ENTER para gerar sua senha segura!\n$> ");
    while (getchar() != '\n');
}

// Funções
void generateBaseString(PasswordData *auth) {
    char alphabetic[] = "abcdefghijklmnopqrstuvwxyz";
    srand(time(0));
    for (short i = 0; i < LGTH_MAX; i++) {
        auth->value[i] = alphabetic[rand() % 26];
    }
    auth->value[LGTH_MAX] = '\0';
}

void addUppercaseLetters(PasswordData *auth) {
    char alphabetic[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (short i = 0; i < 3; i++) {
        short iRand = rand() % LGTH_MAX;
        auth->value[iRand] = alphabetic[rand() % 26];
    }
}

void addSpecialCharacters(PasswordData *auth) {
    char symbols[] = "*&$#!";
    for (short i = 0; i < 5; i++) {
        short iRand = rand() % LGTH_MAX;
        auth->value[iRand] = symbols[rand() % 5];
    }
}
