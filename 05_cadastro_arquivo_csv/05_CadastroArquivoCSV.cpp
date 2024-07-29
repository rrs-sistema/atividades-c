#include <stdio.h>
#include <stdlib.h>
#include <memory>

// Define a estrutura para armazenar os dados dos alunos
typedef struct {
    char nome[100];
    char ru[20];
    char telefone[15];
    char email[100];
} Estudante;

int main() {
    Estudante estudantes[2];
    char nomeArquivo[25];

    // Solicita os dados de 2 estudantes
    for (int i = 0; i < 2; i++) {
        printf("Digite o nome do estudante %d: ", i + 1);
        fgets(estudantes[i].nome, sizeof(estudantes[i].nome), stdin);

        printf("Digite o RU do estudante %d: ", i + 1);
        fgets(estudantes[i].ru, sizeof(estudantes[i].ru), stdin);

        printf("Digite o telefone do estudante %d: ", i + 1);
        fgets(estudantes[i].telefone, sizeof(estudantes[i].telefone), stdin);

        printf("Digite o email do estudante %d: ", i + 1);
        fgets(estudantes[i].email, sizeof(estudantes[i].email), stdin);

        // Remove o caractere de nova linha '\n' da entrada
        estudantes[i].nome[strcspn(estudantes[i].nome, "\n")] = '\0';
        estudantes[i].ru[strcspn(estudantes[i].ru, "\n")] = '\0';
        estudantes[i].telefone[strcspn(estudantes[i].telefone, "\n")] = '\0';
        estudantes[i].email[strcspn(estudantes[i].email, "\n")] = '\0';
    }

    // Usa o RU do primeiro estudante como nome do arquivo
    snprintf(nomeArquivo, sizeof(nomeArquivo), "%s.csv", estudantes[0].ru);

    // Abre o arquivo para escrita
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Escreve os dados no arquivo CSV
    fprintf(arquivo, "Nome;RU;Telefone;Email\n");
    for (int i = 0; i < 10; i++) {
        fprintf(arquivo, "%s;%s;%s;%s\n", estudantes[i].nome, estudantes[i].ru, estudantes[i].telefone, estudantes[i].email);
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Dados salvos com sucesso no arquivo %s\n", nomeArquivo);

    return 0;
}
