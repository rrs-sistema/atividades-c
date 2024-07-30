
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

using namespace std;

// Aqui criamos uma estrutura b�sica para armazenar o nome e Ru do aluno
struct Aluno {
    char nome[100];
    int ru;
};

static int imprimirRU(Aluno* aluno) {
    // Aqui estamos verificando se a Ru informado � par ou �mpar
    if (aluno->ru % 2 == 0) {
        printf("O RU informado � par.\n");
    }
    else {
        printf("O RU informado � impar.\n");
    }
    return 0;
}

static int imprimirNomeInvertido(Aluno* aluno) {
    // Imprimindo o nome de tr�s para frente (invertido)
    char nomeInvertido[100]{};
    int len = strlen(aluno->nome);
    for (int i = 0; i < len; i++) {
        nomeInvertido[i] = aluno->nome[len - i - 1];
    }
    nomeInvertido[len] = '\0'; // Adicionando o terminador de string

    printf("Esse eh o nome invertido: %s\n", nomeInvertido);

    // Liberando a mem�ria alocada
    return 0;
}

int main() {
    //Essa fun��o setlocale � usada para definir, modificar ou consultar algumas ou todas as informa��es de localidade do programa atual
    setlocale(LC_ALL, "Portuguese");

    // Criando um ponteiro para o registro
    Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));

    // Aqui verificamos se a aloca��o de mem�ria foi realizada com sucesso
    if (aluno == NULL) {
        printf("Ops! Erro ao alocar a mem�ria.\n");
        return 1;
    }

    // Vamos solicitar que o usu�rio digite o RU e o seu nome
    printf("Por favor, informe seu RU: ");
    (void)scanf("%d", &aluno->ru);
    (void)getchar(); // Aqui precisamos realizar a limpeza do buffer do enter ap�s o n�mero
    
    printf("Por favor, informe seu nome: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0'; // Remove o '\n' capturado pelo fgets

    imprimirRU(aluno);// Chama a fun��o para mostrar se o RU � par ou �mpar

    imprimirNomeInvertido(aluno);// Chama a fun��o para imprimir o nome invertido

    // Aqui precisamos liberar a mem�ria que foi dantes alocada
    free(aluno);

    return 0;
}

