#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "libPokemon2lf.h"

long bigEndian(char *bytes, long longitud){
	long l = 0;
	for(int i = 0; i < longitud; i++){
		l = (l << 8) + bytes[i];
	};
	return l;
}

void hexPrint(unsigned char *datos, long largo){
	for(long i = 0; i < ceil(largo / (float)16); i++){
		for(int j = 0; j < 16; j++){
			if((i * 16 + j) >= largo) {
				continue;
			} else {
			  printf("%02X  ", datos[i*16 + j]);
			};
		};
		printf("\n");
	};
	printf("\n");
}

void limpiarLista(char *lista, long largo){
	for(long i = 0; i < largo; i++) lista[i] = 0;
};

