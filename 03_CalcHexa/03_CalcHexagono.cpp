#include <stdio.h>
#include <math.h> // Para usar a função sqrt
#include <locale.h>

// Função para calcular a área e o perímetro de um hexágono
static void calc_hexa(float l, float* area, float* perimetro) {
    *perimetro = 6 * l;
    *area = (3 * sqrt(3) * l * l) / 2;
}

static void mostraAreaPerimetro(double lado, double area, double perimetro) {
    // mostra/imprimir a área e o perimetro
    printf("Para um hexágono de lado %.2f:\n", lado);
    printf("Área: %.2f\n", area);
    printf("Perimetro: %.2f\n", perimetro);
}

int main() {
    //Essa função setlocale é usada para definir, modificar ou consultar algumas ou todas as informações de localidade do programa atual
    setlocale(LC_ALL, "Portuguese");

    float lado;
    float area, perimetro;
    printf("Por favor, informe o comprimento do lado do hexágono : \n");
    printf("Você pode informar um valor negativo para sair: \n\n");

    while (100) { // Loop infinito até que uma condição de parada seja encontrada
        (void)scanf("%f", &lado);

        if (lado < 0) {
            printf("\nOPS! Você digitou um número negativo. Estamos finalizando o programa.\n");
            break;
        }

        // Chamada à função para calcular área e perímetro
        calc_hexa(lado, &area, &perimetro);

        // Chamada à função para mostra/imprimir a área e o perimetro
        mostraAreaPerimetro(lado, area, perimetro);
    }

    return 0;
}
