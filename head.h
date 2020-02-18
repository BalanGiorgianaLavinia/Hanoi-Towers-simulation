/* Balan Giorgiana-Lavinia - 311CB */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celulag
{
	void *info;
	struct celulag *urm;
}Celulag, *TLG, **ALG;

typedef struct
{
	TLG vs;
	TLG bs;
}Stiva, *TStiva;

typedef struct
{
	char *culoare;
	TStiva A, B, C;
}Hanoi, *THanoi;

TLG InitCelula(void *info);
THanoi AlocaHanoi(char *culoare);
int InsDisc(THanoi hanoi, int disc);
int InsSistem(ALG SistemeH, char *culoare);
TStiva INITs();
int Push(TStiva s, TLG celula);
void Pop(TStiva s, ALG celula);
void AfiseazaStiva(FILE* output, TStiva stiva);
int add(ALG SistemeH, char *culoare, int disc);
void show(FILE* output, TLG SistemeH, char *culoare);
