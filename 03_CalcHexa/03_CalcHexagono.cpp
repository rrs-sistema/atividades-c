#include <stdio.h>
#include <math.h> // Para usar a fun��o sqrt

// Fun��o para calcular a �rea e o per�metro de um hex�gono
void calc_hexa(float l, float* area, float* perimetro) {
    *perimetro = 6 * l;
    *area = (3 * sqrt(3) * l * l) / 2;
}

static void mostraAreaPerimetro(double lado, double area, double perimetro) {
    // mostra/imprimir a �rea e o perimetro
    printf("Para um hexagono de lado %.2f:\n", lado);
    printf("Area: %.2f\n", area);
    printf("Perimetro: %.2f\n", perimetro);
}

int main() {
    float lado;
    float area, perimetro;
    printf("Por favor, informe o comprimento do lado do hexagono: \n");
    printf("Voce pode informar um valor negativo para sair: \n");

    while (100) { // Loop infinito at� que uma condi��o de parada seja encontrada
        (void)scanf("%f", &lado);

        if (lado < 0) {
            printf("Valor negativo detectado. Encerrando o programa.\n");
            break;
        }

        // Chamada � fun��o para calcular �rea e per�metro
        calc_hexa(lado, &area, &perimetro);

        // Chamada � fun��o para mostra/imprimir a �rea e o perimetro
        mostraAreaPerimetro(lado, area, perimetro);
    }

    return 0;
}
