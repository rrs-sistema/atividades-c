#include <stdio.h>

// Função recursiva para calcular a potenciação
static double potencia(double base, int expoente) {
    // Qualquer número elevado a 0 é 1
    if (expoente == 0) {
        return 1;
    }

    // Se o expoente informado for negativo, então vamos calcular de maneira inversa da base
    if (expoente < 0) {
        return 1 / potencia(base, -expoente);
    }

    // Aqui calculando o caso recursivo
    return base * potencia(base, expoente - 1);
}

int main() {
    double base;
    int expoente;

    // Solicita ao usuário a base e o expoente
    printf("Por favor informe a base: ");
    (void)scanf("%lf", &base);

    printf("Por favor informe o expoente: ");
    (void)scanf("%d", &expoente);

    // Calcula a potência usando a função recursiva
    double resultado = potencia(base, expoente);

    // Mostra/Imprimi o resultado do calculo
    printf("\n%.2lf elevado a %d eh %.2lf\n", base, expoente, resultado);

    return 0;
}
