#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
} Aluno;

void ordenar(Aluno *, unsigned short);

int main() {
    unsigned short qtsAlunos, alunoPremiado;
    scanf("%hu %hu", &qtsAlunos, &alunoPremiado);
    
    Aluno alunos[qtsAlunos];
    for (unsigned short i = 0; i < qtsAlunos; i++) {
        scanf("%s", alunos[i].nome);
    }

    ordenar(alunos, qtsAlunos);
    printf("%s\n", alunos[alunoPremiado - 1].nome);

    return 0;
}

void ordenar(Aluno *alunos, unsigned short tam) {
    for (unsigned short i = 1; i < tam; i++) {
        Aluno atual = alunos[i];
        short j = i - 1;
        while (j >= 0 && strcmp(alunos[j].nome, atual.nome) > 0) {
            alunos[j + 1] = alunos[j];
            j--;
        }
        alunos[j + 1] = atual;
    }
}
