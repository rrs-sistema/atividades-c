#include <iostream>
#include <vector>
#include <locale.h>


static int imprimirRU(int* maiorNumero, int* menorNumero) {
    // Imprime o maior e menor valor encontrado
    printf("Maior digito informado �: %d\n", *maiorNumero);
    printf("Menor digito informado �: %d\n", *menorNumero);
    return 0;
}

int main() {
    //Essa fun��o setlocale � usada para definir, modificar ou consultar algumas ou todas as informa��es de localidade do programa atual
    setlocale(LC_ALL, "Portuguese");

    char ru[20]{}; // Criamos a variavel para armazena a Ru como string
    int digitos[20]{};    // Esse vetor ser� usado para armazenar os d�gitos da Ru
    int *maiorNumero, *menorNumero; // Esss dois ponteiros s�o para guardar o maior e menor d�gito

    // Aqui solicitamos ao usu�rio que informe o n�mero do seu RU
    printf("Por favor, informe seu RU: ");
    (void)scanf("%s", ru);

    int tamanho = strlen(ru); // Calcula o tamanho da string

    // Converte cada caractere para um n�mero inteiro e armazena no vetor
    for (int i = 0; i < tamanho; ++i) {
        digitos[i] = ru[i] - '0'; // Converte caractere para inteiro
    }

    // Nas duas linhas abaixo criamos os ponteiros para pegar o maior e menor valor informado
    maiorNumero = &digitos[0];
    menorNumero = &digitos[0];

    // Criamos um la�o de repeti��o para rercorrer o vetor e encontrar o maior e menor valor usando ponteiros
    for (int i = 1; i < tamanho; ++i) {
        if (*(digitos + i) > *maiorNumero) {// Aqui verificamos o maior digito informado no RU
            maiorNumero = (digitos + i);
        }
        if (*(digitos + i) < *menorNumero) {// Aqui verificamos o menor digito informado no RU
            menorNumero = (digitos + i);
        }
    }

    imprimirRU(maiorNumero, menorNumero);// Chama a fun��o para mostrar o maior e o menor n�mero contido no vetor

    return 0;
}
