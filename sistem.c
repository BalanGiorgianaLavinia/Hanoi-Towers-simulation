/* Balan Giorgiana-Lavinia - 311CB */
#include "head.h"

THanoi AlocaHanoi(char *culoare)
{
	THanoi temp = (THanoi)malloc(sizeof(Hanoi));
	if(!temp)
		return NULL;

	temp->culoare = (char*)malloc((strlen(culoare)+1)*sizeof(char));
	memcpy(temp->culoare, culoare, strlen(culoare));
	if(!temp->culoare)
	{
		printf("Nu s-a alocat culoarea %s\n", culoare);

		free(temp);

		return NULL;
	}

	temp->A = INITs();
	if(!temp->A)
	{
		printf("Nu s-a alocat stiva A in %s\n", culoare);

		//eliberari
		free(temp->culoare);
		free(temp);

		return NULL;
	}

	temp->B = INITs();
	if(!temp->B)
	{
		printf("Nu s-a alocat stiva B in %s\n", culoare);

		//eliberari
		free(temp->culoare);
		free(temp);

		return NULL;
	}

	temp->C = INITs();
	if(!temp->C)
	{
		printf("Nu s-a alocat stiva C in %s\n", culoare);

		//eliberari
		free(temp->culoare);
		free(temp);

		return NULL;
	}

	return temp;
}

int InsSistem(ALG SistemeH, char *culoare)
{

	//Creez sistemul
	TLG cel = NULL;
	THanoi hanoi = NULL;

	//Initializez celula fara informatie (deocamdata)
	cel = InitCelula(NULL);	
	if(!cel)
	{
		printf("Nu a reusit alocarea celulei %s\n", culoare);
		return -1;
	}

	//Aloc spatiu pentru un sistem Hanoi
	hanoi = AlocaHanoi(culoare);	
	if(!hanoi)
	{
		printf("Nu a reusit alocarea hanoi %s\n", culoare);
		free(cel);
		return -1;
	}

	//Leg informatia in sistem
	cel->info = hanoi;

	if(*SistemeH == NULL)
	{
		*SistemeH = cel;
		return 0;
	}

	while((*SistemeH)->urm != NULL)
		//Ma deplasez la finalul listei de sisteme
		SistemeH = &(*SistemeH)->urm;	

	(*SistemeH)->urm = cel;

	return 0;
}

int InsDisc(THanoi hanoi, int disc)
{
	TLG cel = InitCelula(NULL);
	if(!cel)
	{
		printf("Nu s-a alocat celula pentru discul %d\n", disc);
		return -1;
	}

	int *Pdisc = (int*)malloc(sizeof(int));
	if(!Pdisc)
	{
		printf("Nu s-a alocat int pentru discul %d\n", disc);
		free(cel);

		return -1;
	}
	memcpy(Pdisc, &disc, sizeof(int));
	cel->info = Pdisc;

	if(hanoi->A == NULL)
	{
		Push(hanoi->A, cel);
		//S-a inserat primul disc
		return 0;	
	}
	else
	//Stiva are elemente	
	{
		//Stiva auxiliara
		TStiva saux = INITs();
		if(!saux)
			return -1;

		TLG temp = NULL;

		//Extrag din stiva toate elementele mai mici decat discul de inserat 
		while(hanoi->A->vs != NULL)
		{
			Pop(hanoi->A, &temp);

			//Daca discul scos e mai mic decat cel curent
			if(*(int*)(temp->info) < disc)
			{
				//Il reintroduc in stiva
				Push(hanoi->A, temp);

				break;
			}

			Push(saux, temp);
		}
		
		//Adaug discul curent in stiva
		Push(hanoi->A, cel);

		//Reintroduc discurile scoase
		while(saux->vs != NULL)
		{
			Pop(saux, &temp);
			Push(hanoi->A, temp);
		}

		free(saux);
		temp = NULL;
	}

	return 0;
}