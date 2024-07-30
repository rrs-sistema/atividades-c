
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

using namespace std;

// Aqui criamos uma estrutura básica para armazenar o nome e Ru do aluno
struct Aluno {
    char nome[100];
    int ru;
};

static int imprimirRU(Aluno* aluno) {
    // Aqui estamos verificando se a Ru informado é par ou ímpar
    if (aluno->ru % 2 == 0) {
        printf("O RU informado é par.\n");
    }
    else {
        printf("O RU informado é impar.\n");
    }
    return 0;
}

static int imprimirNomeInvertido(Aluno* aluno) {
    // Imprimindo o nome de trás para frente (invertido)
    char nomeInvertido[100]{};
    int len = strlen(aluno->nome);
    for (int i = 0; i < len; i++) {
        nomeInvertido[i] = aluno->nome[len - i - 1];
    }
    nomeInvertido[len] = '\0'; // Adicionando o terminador de string

    printf("Esse eh o nome invertido: %s\n", nomeInvertido);

    // Liberando a memória alocada
    return 0;
}

int main() {
    //Essa função setlocale é usada para definir, modificar ou consultar algumas ou todas as informações de localidade do programa atual
    setlocale(LC_ALL, "Portuguese");

    // Criando um ponteiro para o registro
    Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));

    // Aqui verificamos se a alocação de memória foi realizada com sucesso
    if (aluno == NULL) {
        printf("Ops! Erro ao alocar a memória.\n");
        return 1;
    }

    // Vamos solicitar que o usuário digite o RU e o seu nome
    printf("Por favor, informe seu RU: ");
    (void)scanf("%d", &aluno->ru);
    (void)getchar(); // Aqui precisamos realizar a limpeza do buffer do enter após o número
    
    printf("Por favor, informe seu nome: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0'; // Remove o '\n' capturado pelo fgets

    imprimirRU(aluno);// Chama a função para mostrar se o RU é par ou ímpar

    imprimirNomeInvertido(aluno);// Chama a função para imprimir o nome invertido

    // Aqui precisamos liberar a memória que foi dantes alocada
    free(aluno);

    return 0;
}

