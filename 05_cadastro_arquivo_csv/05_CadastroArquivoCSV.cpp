#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <locale.h>

static const int TAMANHO = 2; // Aqui definimos a quantidade de registro

// Define a estrutura para armazenar os dados dos alunos
typedef struct {
    char nome[100];
    char ru[10];
    char telefone[20];
    char email[120];
} Aluno;

int static manupulaArquivo(char nomeArquivo[25], Aluno alunos[TAMANHO]) {
    // Aqui vamos abrir o arquivo para iniciar a escrita
    FILE* arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        perror("OPS! Aconteceu um erro ao abrir o arquivo.");
        return 1;
    }
    // Nesse momento, vamos escrever os dados no arquivo CSV
    fprintf(arquivo, "Nome;RU;Telefone;Email\n");
    for (int i = 0; i < TAMANHO; i++) {
        fprintf(arquivo, "%s;%s;%s;%s\n", alunos[i].nome, alunos[i].ru, alunos[i].telefone, alunos[i].email);
    }
    // Aqui fechamos o arquivo
    fclose(arquivo);

    return 0;
}

void static recebeInformacao(Aluno alunos[TAMANHO]) {
    // Aqui solicitamos os dados dos estudantes

    for (int i = 0; i < TAMANHO; i++) {
        printf("Por favor informe o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        printf("Por favor informe o RU do aluno %d: ", i + 1);
        fgets(alunos[i].ru, sizeof(alunos[i].ru), stdin);

        printf("Por favor informe o telefone do aluno %d: ", i + 1);
        fgets(alunos[i].telefone, sizeof(alunos[i].telefone), stdin);

        printf("Por favor informe o e-mail do aluno %d: ", i + 1);
        fgets(alunos[i].email, sizeof(alunos[i].email), stdin);

        // Remove o caractere de nova linha '\n' da entrada
        // a função "strcspn" retorna o índice do primeiro caractere em uma string que está em um conjunto de caracteres.
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
        alunos[i].ru[strcspn(alunos[i].ru, "\n")] = '\0';
        alunos[i].telefone[strcspn(alunos[i].telefone, "\n")] = '\0';
        alunos[i].email[strcspn(alunos[i].email, "\n")] = '\0';
    }
}

int main() {
    //Essa função setlocale é usada para definir, modificar ou consultar algumas ou todas as informações de localidade do programa atual
    setlocale(LC_ALL, "Portuguese");
    Aluno alunos[TAMANHO]{};
    char nomeArquivo[25];
    
    recebeInformacao(alunos); // Chama a função que será responsavél pelo recebimento das informações

    // Estamos salvando apenas um arquivo para todos 10 estudades e para isso estamos usando o RU do primeiro estudante para usar como nome do arquivo
    snprintf(nomeArquivo, sizeof(nomeArquivo), "%s.csv", alunos[0].ru);

    manupulaArquivo(nomeArquivo, alunos); // Chama a função que vai manipular o arquivo

    printf("Dados salvos com sucesso no arquivo %s\n", nomeArquivo);

    return 0;
}
