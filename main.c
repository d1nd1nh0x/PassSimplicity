#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <string.h> 

// Defines
#define LGTH_MAX 16

// Structs
typedef struct {
    char value[LGTH_MAX + 1]; 
    short length;
    short hasUppercase;
    short hasNumbers;
    short hasSymbols;
    short strength;
} PasswordData;

// Funções
void displayWelcomePrompt();
void displayGeneratedPassword(const PasswordData *auth);
void generatePassword(PasswordData *auth);

int main(void) {
    #ifdef WIN32
        system("chcp 65001");
        system("cls");
    #endif

    PasswordData authPassword = {0};
    srand((unsigned) time(NULL));

    displayWelcomePrompt();
    generatePassword(&authPassword);
    displayGeneratedPassword(&authPassword);

    return 0;
}

void displayWelcomePrompt() {
    printf("Bem-vindo!\nPressione ENTER para gerar sua senha segura!\n$> ");
    while (getchar() != '\n');
}

void displayGeneratedPassword(const PasswordData *auth) {
    printf("\nSenha Gerada: %s\n", auth->value);
    puts("================================");
    printf("Tamanho da senha: %d\n", auth->length);
    printf("Contém caracteres especiais: %s\n", auth->hasSymbols ? "Sim" : "Não");
    printf("Contém caracteres maiúsculos: %s\n", auth->hasUppercase ? "Sim" : "Não");
    printf("Contém caracteres numéricos: %s\n", auth->hasNumbers ? "Sim" : "Não");
    printf("Potência da senha: %s\n", auth->strength > 9 ? "Forte" : "Fraca");
}

void generatePassword(PasswordData *auth) {
    static const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    static const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static const char symbols[] = "*&$#!";
    static const char numbers[] = "0123456789";

    // Preencher com caracteres aleatórios base
    for (short i = 0; i < LGTH_MAX; i++) {
        auth->value[i] = lowercase[rand() % strlen(lowercase)];
    }
    auth->value[LGTH_MAX] = '\0';
    auth->length = LGTH_MAX;
    auth->strength += 3;

    // Adicionar maiúsculas, números e símbolos
    for (short i = 0; i < 3; i++) {
        auth->value[rand() % LGTH_MAX] = uppercase[rand() % strlen(uppercase)];
    }
    auth->hasUppercase = 1;
    auth->strength += 3;

    for (short i = 0; i < 3; i++) {
        auth->value[rand() % LGTH_MAX] = numbers[rand() % strlen(numbers)];
    }
    auth->hasNumbers = 1;
    auth->strength += 3;

    for (short i = 0; i < 3; i++) {
        auth->value[rand() % LGTH_MAX] = symbols[rand() % strlen(symbols)];
    }
    auth->hasSymbols = 1;
    auth->strength += 3;
}