/* programa arv0300.c - Arvore binaria de busca */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINHA 80

typedef struct stNo {
  int info;
  struct stNo *esq, *dir;
} tNo;

tNo *cria_arvore(int);
tNo *cria_no(void);
void pos_esq(tNo *, int);
void pos_dir(tNo *, int);
void libera_arvore(tNo *);
void em_ordem(tNo *);

int main(void) {
  tNo *raiz = NULL, *p, *q;
  char linha[TAM_LINHA], *numero;
  int num;

  if (fgets(linha, sizeof(linha), stdin) == NULL)
    return 1;
  /* remove newline se existir */
  linha[strcspn(linha, "\n")] = '\0';

  numero = strtok(linha, " ");
  if (numero == NULL) {
    puts("Nenhum numero informado.");
    return 0;
  }
  num = atoi(numero);
  printf("Li numero %d\n", num);
  raiz = cria_arvore(num);
  if (raiz == NULL) {
    puts("Faltou espaco para alocar no.");
    return 1;
  }

  numero = strtok(NULL, " ");
  while (numero != NULL) {
    q = raiz;
    p = raiz;
    num = atoi(numero);
    printf("Li numero %d\n", num);
    while (num != p->info && q != NULL) {
      p = q;
      if (num < p->info)
        q = p->esq;
      else
        q = p->dir;
    }
    if (num == p->info)
      printf("O numero %d ja existe na arvore.\n", num);
    else {
      if (num < p->info)
        pos_esq(p, num);
      else
        pos_dir(p, num);
    }
    numero = strtok(NULL, " ");
  }

  printf("Arvore em ordem (ordem simetrica): ");
  em_ordem(raiz);
  putchar('\n');

  libera_arvore(raiz);
  return 0;
}

tNo *cria_arvore(int x) {
  tNo *p;

  p = cria_no();
  if (p != NULL) {
    p->info = x;
    return p;
  }
  return NULL;
}

tNo *cria_no(void) {
  tNo *p;

  p = malloc(sizeof(tNo));
  if (p == NULL)
    return NULL;
  p->esq = NULL;
  p->dir = NULL;
  return p;
}

void pos_esq(tNo *p, int x) {
  tNo *q;

  if (p->esq != NULL)
    puts("Operacao de insercao a esquerda ilegal.");
  else {
    q = cria_arvore(x);
    if (q != NULL)
      p->esq = q;
    else
      puts("Faltou espaco para alocar no.");
  }
}

void pos_dir(tNo *p, int x) {
  tNo *q;

  if (p->dir != NULL)
    puts("Operacao de insercao a direita ilegal.");
  else {
    q = cria_arvore(x);
    if (q != NULL)
      p->dir = q;
    else
      puts("Faltou espaco para alocar no.");
  }
}

void libera_arvore(tNo *r) {
  if (r == NULL)
    return;
  libera_arvore(r->esq);
  libera_arvore(r->dir);
  free(r);
}

void em_ordem(tNo *r) {
  if (r == NULL)
    return;
  em_ordem(r->esq);
  printf("%d ", r->info);
  em_ordem(r->dir);
}
