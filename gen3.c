#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "libPokemon2lf.h"

int obtenerClaveDescifrado(struct GEN_III *pokemon){
	return pokemon->PID ^ pokemon->idEntrenador;
}

unsigned char *descifrarDatos(struct GEN_III *pokemon){
	int clave = obtenerClaveDescifrado(pokemon);
	int *datos = (int *)malloc(48);

	for(int i = 0; i < 12; i++){
		datos[i] = pokemon->datos[i] ^ clave;
	};
	return (unsigned char *)datos;
}

char restoPID(struct GEN_III *pokemon){
	unsigned int PID = pokemon->PID;
	int resto = PID % 24;
	return resto;
}

char obtenerIndice(char resto, char indice){
	for(int i = 0; i < 4; i++){
		if(ordenDatos[resto][i] == indice){
			return (i) * 12;
		};
	}
	return 0;
}

void copiarDatos(struct GEN_III_SUBESTRUCTURA *subestructura, char *datos, char resto){
	void *indiceC = &datos[obtenerIndice(resto, 0)];
	void *indiceA = &datos[obtenerIndice(resto, 1)];
	void *indiceE = &datos[obtenerIndice(resto, 2)];
	void *indiceM = &datos[obtenerIndice(resto, 3)];
	
	memcpy(&subestructura->C, indiceC, 12);
	memcpy(&subestructura->A, indiceA, 12);
	memcpy(&subestructura->E, indiceE, 12);
	memcpy(&subestructura->M, indiceM, 12);
}



void invertirEstructura(struct GEN_III *pokemon){
	char buffer[8];

	limpiarLista(buffer, 8);
	memcpy(buffer, &pokemon->PID, 4);
	pokemon->PID = (int)bigEndian(buffer, 4);

	limpiarLista(buffer, 8);
	memcpy(buffer, &pokemon->idEntrenador, 4);
	pokemon->idEntrenador = (int)bigEndian(buffer, 4);

	limpiarLista(buffer, 8);
	memcpy(buffer, &pokemon->checksum, 2);
	pokemon->checksum = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &pokemon->sinUso, 2);
	pokemon->sinUso = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &pokemon->saludActual, 2);
	pokemon->saludActual = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &pokemon->saludMaxima, 2);
	pokemon->saludMaxima = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &pokemon->ataque, 2);
	pokemon->ataque = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &pokemon->defensa, 2);
	pokemon->defensa = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &pokemon->velocidad, 2);
	pokemon->velocidad = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &pokemon->ataqueEspecial, 2);
	pokemon->ataqueEspecial = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &pokemon->defensaEspecial, 2);
	pokemon->defensaEspecial = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &pokemon->condicionEstado, 4);
	pokemon->condicionEstado = (int)bigEndian(buffer, 4);
}

void invertirCrecimiento(struct GEN_III_SUBESTRUCTURA *subestructura){
	char buffer[8];

	limpiarLista(buffer, 8);
	memcpy(buffer, &subestructura->C.especie, 2);
	subestructura->C.especie = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &subestructura->C.item, 2);
	subestructura->C.item = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &subestructura->C.experiencia, 4);
	subestructura->C.experiencia = (int)bigEndian(buffer, 4);

	limpiarLista(buffer, 8);
	memcpy(buffer, &subestructura->C.sinUsar, 2);
	subestructura->C.sinUsar = (short)bigEndian(buffer, 2);
}

void invertirAtaques(struct GEN_III_SUBESTRUCTURA *subestructura){
	char buffer[8];

	limpiarLista(buffer, 8);
	memcpy(buffer, &subestructura->A.movimiento1, 2);
	subestructura->A.movimiento1 = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &subestructura->A.movimiento2, 2);
	subestructura->A.movimiento2 = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &subestructura->A.movimiento3, 2);
	subestructura->A.movimiento3 = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &subestructura->A.movimiento4, 2);
	subestructura->A.movimiento4 = (short)bigEndian(buffer, 2);
}

void invertirEVs(struct GEN_III_SUBESTRUCTURA *subestructura){
	char buffer[8];
	return;
}

void invertirMiscelaneo(struct GEN_III_SUBESTRUCTURA *subestructura){
	char buffer[8];

	limpiarLista(buffer, 8);
	memcpy(buffer, &subestructura->M.informacionOrigen, 2);
	subestructura->M.informacionOrigen = (short)bigEndian(buffer, 2);

	limpiarLista(buffer, 8);
	memcpy(buffer, &subestructura->M.IVHuevoHabilidad, 4);
	subestructura->M.IVHuevoHabilidad = (int)bigEndian(buffer, 4);

	limpiarLista(buffer, 8);
	memcpy(buffer, &subestructura->M.cintasObediencia, 4);
	subestructura->M.cintasObediencia = (int)bigEndian(buffer, 4);
}

void invertirDatos(struct GEN_III_SUBESTRUCTURA *subestructura){
	invertirCrecimiento(subestructura);
	invertirAtaques(subestructura);
	invertirEVs(subestructura);
	invertirMiscelaneo(subestructura);
}

struct GEN_III_SUBESTRUCTURA *crearSubestructura(struct GEN_III *pokemon, char descifrar){
	char 		*datos = descifrarDatos(pokemon);
	hexPrint(datos, 48);

	unsigned char	 resto = abs(restoPID(pokemon));
	struct GEN_III_SUBESTRUCTURA *substructura = (struct GEN_III_SUBESTRUCTURA *)malloc(48);

	if(descifrar == 1){
		hexPrint(datos, 48);
		memcpy(substructura, datos, 48);
	} else if (descifrar == 2) {
		copiarDatos(substructura, datos, resto);
	};
	//invertirDatos(substructura);
	
	free(datos);
	return substructura;
}
void imprimirGEN_III(struct GEN_III *pokemon){
	printf("PID: %08X\n", pokemon->PID);
	printf("idEntrenador: %08X\n", pokemon->idEntrenador);
	
	char *nick = convertirTextoGenIII(pokemon->nick, 10);
	printf("Nick: %s\n", nick);
	free(nick);

	printf("Lenguaje: %s\n", GEN_III_LENGUAJE[pokemon->lenguaje]);
	printf("Banderas: %u\n", pokemon->banderas);

	char *entrenador = convertirTextoGenIII(pokemon->nombreEntrenador, 7);
	printf("Entrenador: %s\n", entrenador);
	free(entrenador);

	printf("Marcas: %u\n", pokemon->marcas);
	printf("Suma: %04X\n", pokemon->checksum);
	printf("Sin uso: %u\n", pokemon->sinUso);

	printf("--------- SUBESTRUCTURA ---------\n");
	printf("Crecimiento:\n");
	printf("\tEspecie: %i\n", pokemon->sub.C.especie);
	printf("\tItem: %i\n", pokemon->sub.C.item);
	printf("\tExperiencia: %i\n", pokemon->sub.C.experiencia);
	printf("\tBonus PP: %i\n", pokemon->sub.C.bonusPP);
	printf("\tAmistad: %i\n", pokemon->sub.C.amistad);
	printf("\tSin Usar: %i\n", pokemon->sub.C.sinUsar);
	printf("Ataques:\n");
	printf("\tMovimiento 1: %i\n", pokemon->sub.A.movimiento1);
	printf("\tMovimiento 2: %i\n", pokemon->sub.A.movimiento2);
	printf("\tMovimiento 3: %i\n", pokemon->sub.A.movimiento3);
	printf("\tMovimiento 4: %i\n", pokemon->sub.A.movimiento4);
	printf("\tPP 1: %i\n", pokemon->sub.A.puntosPoder1);
	printf("\tPP 2: %i\n", pokemon->sub.A.puntosPoder2);
	printf("\tPP 3: %i\n", pokemon->sub.A.puntosPoder3);
	printf("\tPP 4: %i\n", pokemon->sub.A.puntosPoder4);
	printf("EVs:\n");
	printf("\tSalud: %i\n", pokemon->sub.E.puntosEsfuerzoSalud);
	printf("\tAtaque: %i\n", pokemon->sub.E.puntosEsfuerzoAtaque);
	printf("\tDefensa: %i\n", pokemon->sub.E.puntosEsfuerzoDefensa);
	printf("\tVelocidad: %i\n", pokemon->sub.E.puntosEsfuerzoVelocidad);
	printf("\tAt. Esp: %i\n", pokemon->sub.E.puntosEsfuerzoAtaqueEspecial);
	printf("\tDe. Esp: %i\n", pokemon->sub.E.puntosEsfuerzoDefensaEspecial);
	printf("\tCarisma: %i\n", pokemon->sub.E.carisma);
	printf("\tBelleza: %i\n", pokemon->sub.E.belleza);
	printf("\tDulzura: %i\n", pokemon->sub.E.dulzura);
	printf("\tIngenio: %i\n", pokemon->sub.E.ingenio);
	printf("\tDureza: %i\n", pokemon->sub.E.dureza);
	printf("\tSentimiento: %i\n", pokemon->sub.E.sentimiento);
	printf("Miscelaneo:\n");
	printf("\tPokérus: %i\n", pokemon->sub.M.pokerus);
	printf("\tLugar de Encuentro: %u\n", pokemon->sub.M.lugarEncuentro);
	printf("\tInformación de Origen: %u\n", pokemon->sub.M.informacionOrigen);
	printf("\tIV, huevos y habilidad: %u\n", pokemon->sub.M.IVHuevoHabilidad);
	printf("\tCintas y Obediencia: %u\n", pokemon->sub.M.cintasObediencia);
	printf("---------------------------------\n");

	printf("Estado: %08x\n", pokemon->condicionEstado);
	printf("Nivel: %u\n", pokemon->nivel);
	printf("ID Correo: %u\n", pokemon->idCorreo);
	printf("Salud: %u/%u\n", pokemon->saludActual, pokemon->saludMaxima);
	printf("Ataque: %u\n", pokemon->ataque);
	printf("Defensa: %u\n", pokemon->defensa);
	printf("Velocidad: %u\n", pokemon->velocidad);
	printf("Ataque Especial: %u\n", pokemon->ataqueEspecial);
	printf("Defensa Especial: %u\n", pokemon->defensaEspecial);
}

char *convertirTextoGenIII(unsigned char *entrada, long longitud){
	char *texto;	unsigned long largo;
	FILE *buff   = 	open_memstream(&texto, &largo);

	for(long i = 0; i < longitud; i++){
		fprintf(buff, "%s", GEN_III_TEXTO[entrada[i]]);
		if(entrada[i] == 0xFF) break;
	};

	fflush(buff);
	fclose(buff);
	return texto;
}

struct GEN_III *leerDesdeDatos(char *datos, char descifrar){
	struct GEN_III *pokemon = (struct GEN_III *)malloc(100);
	memcpy(pokemon, datos, 100);

	if(descifrar){
		struct GEN_III_SUBESTRUCTURA *sub = crearSubestructura(pokemon, descifrar);
		memcpy(&pokemon->sub, sub, 48);
		free(sub);
	};
	
	return pokemon;
}

void destruirGEN_III(struct GEN_III *pokemon){
	free(pokemon);
}

unsigned short obtenerSumaGEN_III(struct GEN_III *pokemon){
	unsigned int suma = 0;
	for(int i = 0; i < 12; i++){
		//printf("Suma: %08x\tValor: %08X\n", suma, pokemon->datos[i]);
		suma += pokemon->datos[i];
	};
	printf("PreSuma: %08x\n", suma);
	suma = (suma & 0xFFFF) + ((suma >> 16) & 0xFFFF) - 1;
	return suma & 0xFFFF;
}

void ordenarSubEstructura(struct GEN_III *pokemon){
	char resto = restoPID(pokemon);
	char *datos = (char *)malloc(48);
	
	for(int i = 0; i < 4; i++){
		memcpy(&datos[i * 12], &pokemon->datos[ordenDatos[resto][i] * 3], 12);
	};
	memcpy(pokemon->datos, datos, 48);
	free(datos);
	return;
}


void encriptarSubestructura(struct GEN_III *pokemon){
	int clave	= obtenerClaveDescifrado(pokemon);
	printf("Clave: %08x\n", clave);

	ordenarSubEstructura(pokemon);
	for(int i = 0; i < 12; i++){
		pokemon->datos[i] = pokemon->datos[i] ^ clave;
	};
	return;
}


struct GEN_III *exportarPokemonGEN_III(struct GEN_III *pokemon){
	struct GEN_III *datos = (struct GEN_III *)malloc(100);
	memcpy(datos, pokemon, 100);

	short checksum 	= obtenerSumaGEN_III(datos);
	encriptarSubestructura(datos);

	datos->checksum = checksum;
	return datos;
}

void exportarArchivoGEN_III(char *nombre, struct GEN_III *pokemon){
	FILE *file = fopen(nombre, "wb+");
	fwrite(pokemon, 100, 1, file);
	fclose(file);
	return;
}
