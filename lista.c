/* Balan Giorgiana-Lavinia - 311CB */
#include "head.h"

TLG InitCelula(void *info)
{
	TLG temp = (TLG)malloc(sizeof(Celulag));
	if(!temp)
		return NULL;

	temp->info = info;
	temp->urm = NULL;
	
	return temp;
}