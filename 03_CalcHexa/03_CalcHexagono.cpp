#include <stdio.h>
#include <math.h> // Para usar a fun��o sqrt
#include <locale.h>

// Fun��o para calcular a �rea e o per�metro de um hex�gono
static void calc_hexa(float l, float* area, float* perimetro) {
    *perimetro = 6 * l;
    *area = (3 * sqrt(3) * l * l) / 2;
}

static void mostraAreaPerimetro(double lado, double area, double perimetro) {
    // mostra/imprimir a �rea e o perimetro
    printf("Para um hex�gono de lado %.2f:\n", lado);
    printf("�rea: %.2f\n", area);
    printf("Perimetro: %.2f\n", perimetro);
}

int main() {
    //Essa fun��o setlocale � usada para definir, modificar ou consultar algumas ou todas as informa��es de localidade do programa atual
    setlocale(LC_ALL, "Portuguese");

    float lado;
    float area, perimetro;
    printf("Por favor, informe o comprimento do lado do hex�gono : \n");
    printf("Voc� pode informar um valor negativo para sair: \n\n");

    while (100) { // Loop infinito at� que uma condi��o de parada seja encontrada
        (void)scanf("%f", &lado);

        if (lado < 0) {
            printf("\nOPS! Voc� digitou um n�mero negativo. Estamos finalizando o programa.\n");
            break;
        }

        // Chamada � fun��o para calcular �rea e per�metro
        calc_hexa(lado, &area, &perimetro);

        // Chamada � fun��o para mostra/imprimir a �rea e o perimetro
        mostraAreaPerimetro(lado, area, perimetro);
    }

    return 0;
}
