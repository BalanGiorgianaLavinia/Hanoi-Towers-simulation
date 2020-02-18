/* Balan Giorgiana-Lavinia - 311CB */
#include "head.h"

int add(ALG SistemeH, char *culoare, int disc)
{
	TLG aux = *SistemeH;
	int rez = -1;
	if(*SistemeH == NULL)
	{
		//Adaug in lista generica primul sistem hanoi
		rez = InsSistem(SistemeH, culoare);
		if(rez != 0)
			return -1;
	}
	else
	{
		//Caut culoarea
		while(aux != NULL)
		{
			if(strcmp( ((THanoi)(aux->info))->culoare , culoare) == 0)
				break;
			aux = aux->urm;
		}

		//Daca nu s-a gasit culoarea, o adaug
		if(aux == NULL)
		{
			rez = InsSistem(SistemeH, culoare);
			if(rez != 0)
				return -1;
		}
	}

	aux = *SistemeH;
	while(aux != NULL)
	{
		if(strcmp(((THanoi)(aux->info))->culoare, culoare) == 0)
			break;
		aux = aux->urm;
	}

	if(aux != NULL)
		rez = InsDisc(((THanoi)(aux->info)), disc);

	return 0;
}

void show(FILE* output, TLG SistemeH, char *culoare)
{
	int gasit = 0;
	while(SistemeH)
	{
		if(strcmp(((THanoi)(SistemeH->info))->culoare, culoare) == 0)
		{
			//Am gasit sistemul de culoare
			gasit = 1;
			fprintf(output, "A_%s:", culoare);
			AfiseazaStiva(output, ((THanoi)(SistemeH->info))->A);
			fprintf(output, "\nB_%s:", culoare);
			AfiseazaStiva(output, ((THanoi)(SistemeH->info))->B);
			fprintf(output, "\nC_%s:", culoare);
			AfiseazaStiva(output, ((THanoi)(SistemeH->info))->C);
			fprintf(output, "\n");

			//Se opreste functia
			return;	
		}
		else
		{
			//Avansez in lista
			SistemeH = SistemeH->urm;
		}
	}

	if(gasit == 0)
	{
		//Sistemul nu a fost gasit
		fprintf(output, "A_%s:\n", culoare);
		fprintf(output, "B_%s:\n", culoare);
		fprintf(output, "C_%s:\n", culoare);
		return;
	}
}