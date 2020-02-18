/* Balan Giorgiana-Lavinia - 311CB */
#include "head.h"

TStiva INITs()
{
	TStiva temp = (TStiva)malloc(sizeof(Stiva));
	if(!temp)
		return NULL;

	temp->vs = NULL;
	temp->bs = NULL;

	return temp;
}

int Push(TStiva s, TLG celula)
{
	celula->urm = s->vs;
	s->vs = celula;

	return 0;
}

void Pop(TStiva s, ALG celula)
{
	if(s->vs == NULL)
	{
		*celula = NULL;
		return;
	}

	*celula = s->vs;
	s->vs = s->vs->urm;
}

void AfiseazaStiva(FILE* output, TStiva stiva)
{
	if(stiva->vs == NULL)
		return;

	TLG tempCel = NULL;
	TStiva saux = INITs();
	if(saux == NULL)
		return;

	while(stiva->vs != NULL)
	{
		Pop(stiva, &tempCel);
		fprintf(output, " %d", *(int*)tempCel->info);
		Push(saux, tempCel);
	}

	while(saux->vs != NULL)
	{
		Pop(saux, &tempCel);
		Push(stiva, tempCel);
	}

	free(saux);
	
}