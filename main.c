#include <stdio.h>
#include "libPokemon2lf.h"

int main(){
	FILE *fp = fopen("memdump.dmp", "rb");
	char datos[100];
	fread(datos, 100, 1, fp);
	fclose(fp);

	struct GEN_III *pokemon = leerDesdeDatos(datos, 2);
	pokemon->sub.C.especie = 0x96;

	struct GEN_III *pokemonEditado = exportarPokemonGEN_III(pokemon);
	exportarArchivoGEN_III("dump.bin", pokemonEditado);
	destruirGEN_III(pokemon);
	destruirGEN_III(pokemonEditado);
	return 0;
}






