#include <stdio.h>
#include <math.h> // Para usar a função sqrt
#include <locale.h>

// Função recursiva para calcular a potenciação
static double calculaPotencia(double base, int expoente) {

    // Qualquer número elevado a 0 é 1
    if (expoente == 0) {
        return 1;
    }

    // Se o expoente informado for negativo, então vamos calcular de maneira inversa da base
    if (expoente < 0) {
        return 1 / calculaPotencia(base, -expoente);
    }

    // Aqui calculando o caso recursivo
    return base * calculaPotencia(base, expoente - 1);
}

int main() {
    //Essa função setlocale é usada para definir, modificar ou consultar algumas ou todas as informações de localidade do programa atual
    setlocale(LC_ALL, "Portuguese");

    double base;
    int expoente;

    // Aqui solicitamos ao usuário que forneça a base e o expoente para o calculo
    printf("Por favor informe a base: ");
    (void)scanf("%lf", &base);

    printf("Por favor informe o expoente: ");
    (void)scanf("%d", &expoente);

    // Aqui chamamos a função para calcular a potência usando a função recursiva
    double resultado = calculaPotencia(base, expoente);

    // Mostra/Imprimi o resultado do calculo
    printf("\n%.2lf elevado a %d e  %.2lf\n", base, expoente, resultado);

    return 0;

}
