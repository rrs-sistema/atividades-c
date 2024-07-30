#include <iostream>
#include <vector>
#include <locale.h>

static int imprimirRU(int* maiorNumero, int* menorNumero) {
    // Imprime o maior e menor valor encontrado
    printf("Maior digito informado eh: %d\n", *maiorNumero);
    printf("Menor digito informado eh: %d\n", *menorNumero);
    return 0;
}

int main() {
    //Essa função setlocale é usada para definir, modificar ou consultar algumas ou todas as informações de localidade do programa atual
    setlocale(LC_ALL, "Portuguese");

    char ru[20]{}; // Criamos a variavel para armazena a Ru como string
    int digitos[20]{};    // Esse vetor será usado para armazenar os dígitos da Ru
    int* maiorNumero, * menorNumero; // Esss dois ponteiros são para guardar o maior e menor dígito

    // Aqui solicitamos ao usuário que informe o número do seu RU
    printf("Por favor, informe seu RU: ");
    (void)scanf("%s", ru);

    int tamanho = strlen(ru); // Calcula o tamanho da string

    // Converte cada caractere para um número inteiro e armazena no vetor
    for (int i = 0; i < tamanho; ++i) {
        digitos[i] = ru[i] - '0'; // Converte caractere para inteiro
    }

    // Inicializa os ponteiros maior e menor para o primeiro elemento do vetor
    maiorNumero = &digitos[0];
    menorNumero = &digitos[0];

    // Percorre o vetor para encontrar o maior e menor valor usando ponteiros
    for (int i = 1; i < tamanho; ++i) {
        if (*(digitos + i) > *maiorNumero) {
            menorNumero = (digitos + i);
        }
        if (*(digitos + i) < *menorNumero) {
            menorNumero = (digitos + i);
        }
    }

    imprimirRU(maiorNumero, menorNumero);// Chama a função para mostrar o maior e o menor número contido no vetor

    return 0;
}
