/* Balan Giorgiana-Lavinia - 311CB */
#include "head.h"
#define N 30

int main(int argc, char const *argv[])
{
	//deschidere fisiere
	FILE* input = fopen(argv[1], "rt");
	FILE* output = fopen(argv[2], "wt");

	int nrOperatii = 0;
	//Citeste nr de operatii
	fscanf(input, "%d", &nrOperatii);

	//Creez lista vida de sisteme
	TLG SistemeH = NULL;

	int i = 0;
	int k = 0;
	int disc = 0;
	int rez = -1;
	char operatie[N];
	char culoare[N];

	for(i = 0; i < nrOperatii; i++)
	{
		fscanf(input, "%s", operatie);

		if(strcmp(operatie, "add") == 0)
			k = 1;
		if(strcmp(operatie, "show") == 0)
			k = 2;
		if(strcmp(operatie, "show_moves") == 0)
			k = 3;
		if(strcmp(operatie, "play") == 0)
			k = 4;

		switch(k)
		{
			case 1:

				fscanf(input, "%s", culoare);
				fscanf(input, "%d", &disc);

				rez = add(&SistemeH, culoare, disc);
				if(rez != 0)
					printf("Nu s-a adaugat %s - %d\n", culoare, disc);

				break;

			case 2:

				fscanf(input, "%s", culoare);
				show(output, SistemeH, culoare);

				break;

			case 3:

				break;
			case 4:

				break;
		}

	}

	//inchidere fisiere
	fclose(input);
	fclose(output);
	//Distruge
	return 0;
}