#include <stdio.h>
#define ARRAY_SIZE 2

typedef struct data {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct aluno {
  int matricula;
  char nome[101];
  Data dataNascimento;
  float media;
} Aluno;

void descricaoComando(char *message) {
  printf("---------------------\n");  
  printf("%s\n", message);
  printf("---------------------\n");
}

void preencherAlunos(Aluno *alunos) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("Digite a matricula do aluno %d: ", i + 1);
    scanf("%d", &alunos[i].matricula);
    printf("Digite o nome do aluno %d: ", i + 1);
    scanf("%s", alunos[i].nome);
    printf("Digite a data de nascimento do aluno %d (dd/MM/AAAA/): ", i + 1);
    scanf (
        "%d/%d/%d", 
        &alunos[i].dataNascimento.dia,
        &alunos[i].dataNascimento.mes,
        &alunos[i].dataNascimento.ano
      );
    printf("Digite a media do aluno %d: ", i + 1);
    scanf("%f", &alunos[i].media);
  }
}

void imprimirAlunos(Aluno *alunos) {
  descricaoComando("Imprimindo todos os alunos");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("\nAluno %d:\n", i + 1);
    printf("Matricula: %d\n", alunos[i].matricula);
    printf("Nome: %s\n", alunos[i].nome);
    printf(
      "Data de Nascimento: %d/%d/%d\n", 
      alunos[i].dataNascimento.dia,
      alunos[i].dataNascimento.mes,
      alunos[i].dataNascimento.ano
    );
    printf("Media: %.2f\n", alunos[i].media);
  }
}

void imprimirAluno(Aluno aluno) {
  descricaoComando("Imprimindo um aluno");
  printf("\nAluno:\n");
  printf("Matricula: %d\n", aluno.matricula);
  printf("Nome: %s\n", aluno.nome);
}

void excluirAluno(Aluno *alunos, int matricula){
  int count = 0;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    if (alunos[i].matricula == matricula){
      alunos[i].matricula = 0;
      alunos[i].nome[0] = '\0';
      alunos[i].dataNascimento.dia = 0;
      alunos[i].dataNascimento.mes = 0;
      alunos[i].dataNascimento.ano = 0;
      alunos[i].media = 0;
      count++;
      descricaoComando("Excluindo aluno...");
    }
  }
  if (count == 0){
      descricaoComando("Aluno não encontrado");
  }
}

void buscarAluno(Aluno *alunos, int matricula){
  for (int i = 0; i < ARRAY_SIZE; i++) {
    if (alunos[i].matricula == matricula && alunos[i].matricula != 0) {
      descricaoComando("Buscando aluno...");
      imprimirAluno(alunos[i]);
    }
  }
  descricaoComando("Aluno não encontrado!");
}

int main(void) {
  Aluno alunos[ARRAY_SIZE];
  
  preencherAlunos(alunos);
  
  imprimirAlunos(alunos);

  // Lendo o input do usuário e excluindo o aluno que ele escolheu
  printf("\nDigite o número de matricula do aluno que deseja excluir: ");
  int matricula;
  scanf("%d", &matricula);
  excluirAluno(alunos, matricula);

  imprimirAlunos(alunos);

  // Lendo o input do usuário e buscando o aluno que ele escolheu
  printf("\nDigite o número de matricula do aluno que deseja buscar: ");
  scanf("%d", &matricula);
  buscarAluno(alunos, matricula);
  
  return 0;
}