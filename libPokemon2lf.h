
struct GEN_I {
	char	especie;
	short	saludRestante;
	char	nivel;
	char	condicionEstado;
	char	tipo1;
	char	tipo2;
	char	ratioDeCaptura;
	char	indiceMovimiento1;
	char	indiceMovimiento2;
	char	indiceMovimiento3;
	char	indiceMovimiento4;
	short	idEntrenador;
	char	experiemcia[3];
	short	puntosEsfuerzoSalud;
	short	puntosEsfuerzoAtaque;
	short	puntosEsfuerzoDefensa;
	short	puntosEsfuerzoVelocidad;
	short	puntosEsfuerzoEspecial;
	short	datosIV;
	char	puntosPoderMovimiento1;
	char	puntosPoderMovimiento2;
	char	puntosPoderMovimiento3;
	char	puntosPoderMovimiento4;
	char	_nivel;
	short	saludMaxima;
	short	ataque;
	short	defensa;
	short	velocidad;
	short	especial;
} __attribute__((packed));

struct GEN_II{
	char	especie;
	char	item;
	char	indiceMovimiento1;
	char	indiceMovimiento2;
	char	indiceMovimiento3;
	char	indiceMovimiento4;
	short	idEntrenador;
	char	experiencia[3];
	short	puntosEsfuerzoSalud;
	short	puntosEsfuerzoAtaque;
	short	puntosEsfuerzoDefensa;
	short	puntosEsfuerzoVelocidad;
	short	puntosEsfuerzoEspecial;
	short	datosIV;
	char	puntosPoderMovimiento1;
	char	puntosPoderMovimiento2;
	char	puntosPoderMovimiento3;
	char	puntosPoderMovimiento4;
	char	amistadCiclosHuevo;
	char	pokerus;
	short	datosCaptura;
	char	nivel;
	char	condicionEstado;
	char	byteSinUso;
	short	saludActual;
	short	saludMaxima;
	short	ataque;
	short	defensa;
	short	velocidad;
	short	ataqueEspecial;
	short	defensaEspecial;
} __attribute__((packed));

struct GEN_III_SUB_CRECIMIENTO {
	short	especie;
	short	item;
	int	experiencia;
	char	bonusPP;
	char	amistad;
	short	sinUsar;
} __attribute__((packed));

struct GEN_III_SUB_ATAQUES {
	short	movimiento1;
	short	movimiento2;
	short	movimiento3;
	short	movimiento4;
	char	puntosPoder1;
	char	puntosPoder2;
	char	puntosPoder3;
	char	puntosPoder4;
} __attribute__((packed));

struct GEN_III_SUB_EV_CONDICION {
	char	puntosEsfuerzoSalud;
	char	puntosEsfuerzoAtaque;
	char	puntosEsfuerzoDefensa;
	char	puntosEsfuerzoVelocidad;
	char	puntosEsfuerzoAtaqueEspecial;
	char	puntosEsfuerzoDefensaEspecial;
	char	carisma;
	char	belleza;
	char	dulzura;
	char	ingenio;
	char	dureza;
	char	sentimiento;
} __attribute__((packed));

struct GEN_III_SUB_MISC {
	char	pokerus;
	char	lugarEncuentro;
	short	informacionOrigen;
	int	IVHuevoHabilidad;
	int	cintasObediencia;
} __attribute__((packed));

struct GEN_III_SUBESTRUCTURA {
	struct GEN_III_SUB_CRECIMIENTO		C;
	struct GEN_III_SUB_ATAQUES		A;
	struct GEN_III_SUB_EV_CONDICION		E;
	struct GEN_III_SUB_MISC		 	M;
} __attribute__((packed));

struct GEN_III {
	int	PID;
	int	idEntrenador;
	char	nick[10];
	char	lenguaje;
	char	banderas;
	char	nombreEntrenador[7];
	char	marcas;
	short	checksum;
	short	sinUso;

	union {
		struct 	GEN_III_SUBESTRUCTURA sub;
		int	datos[12];
	};

	int	condicionEstado;
	char	nivel;
	char	idCorreo;
	short	saludActual;
	short	saludMaxima;
	short	ataque;
	short	defensa;
	short	velocidad;
	short	ataqueEspecial;
	short	defensaEspecial;
} __attribute__((packed));

static unsigned char ordenDatos[24][4] = {
					{0, 1, 2, 3},
					{0, 1, 3, 2},
					{0, 2, 1, 3},
					{0, 2, 3, 1},
					{0, 3, 1, 2},
					{0, 3, 2, 1},
					{1, 0, 2, 3},
					{1, 0, 3, 2},
					{1, 2, 0, 3},
					{1, 2, 3, 0},
					{1, 3, 0, 2},
					{1, 3, 2, 0},
					{2, 0, 1, 3},
					{2, 0, 3, 1},
					{2, 1, 0, 3},
					{2, 1, 3, 0},
					{2, 3, 0, 1},
					{2, 3, 1, 0},
					{3, 0, 1, 2},
					{3, 0, 2, 1},
					{3, 1, 0, 2},
					{3, 1, 2, 0},
					{3, 2, 0, 1},
					{3, 2, 1, 0},
				};

static char GEN_III_TEXTO[256][5] = {
	" ", "À", "Á", "Â", "Ç", "È", "É", "Ê", "Ë", "Ì", " ", "Î", "Ï", "Ò", "Ó", "Ô",
	"Œ", "Ù", "Ú", "Û", "Ñ", "ß", "à", "á", " ", "ç", "è", "é", "ê", "ë", "ì", " ",
	"î", "ï", "ò", "ó", "ô", "œ", "ù", "ú", "û", "ñ", "º", "ª", "ᵉʳ", "&", "+", " ",
	" ", " ", " ", " ", "-", "=", ";", " ", " ", " ", " ", " ", " ", " ", " ", " ",
	" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ",
	"|", "¿", "¡", "PK", "MN", "PO", "KÉ", "CU", "BO", " ", "Í", "%", "(", ")", " ", " ",
	" ", " ", " ", " ", " ", " ", " ", " ", "â", " ", " ", " ", " ", " ", " ", "í",
	" ", " ", " ", " ", " ", " ", " ", " ", " ", "↑", "↓", "←", "→", "*", "*", "*",
	"*", "*", "*", "*", "ᵉ", "<", ">", " ", " ", " ", " ", " ", " ", " ", " ", " ",
	" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ",
	" ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "!", "?", ".", "-", "・",
	"…", "“", "”", "‘", "’", "♂", "♀", "$", ",", "×", "/", "A", "B", "C", "D", "E",
	"F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
	"V", "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
	"l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "►",
	":", "Ä", "Ö", "Ü", "ä", "ö", "ü", " ", " ", " ", "-", "-", "-", "-", "\n", "\0"
};

static char *GEN_III_LENGUAJE[8] = {
	"N/A", "Japonés", "Inglés", "Francés", "Italiano", "Alemán", "Sin uso", "Español"
};

long 				bigEndian(char *bytes, long longitud);
void 				hexPrint(unsigned char *datos, long largo);
int 				obtenerClaveDescifrado(struct GEN_III *pokemon);
unsigned char  		       *descifrarDatos(struct GEN_III *pokemon);
char 				restoPID(struct GEN_III *pokemon);
char 				obtenerIndice(char resto, char indice);
void 				copiarDatos(struct GEN_III_SUBESTRUCTURA *subestructura, char *datos, char resto);
void 				limpiarLista(char *lista, long largo);
void 				invertirEstructura(struct GEN_III *pokemon);
void 				invertirCrecimiento(struct GEN_III_SUBESTRUCTURA *subestructura);
void 				invertirAtaques(struct GEN_III_SUBESTRUCTURA *subestructura);
void 				invertirEVs(struct GEN_III_SUBESTRUCTURA *subestructura);
void 				invertirMiscelaneo(struct GEN_III_SUBESTRUCTURA *subestructura);
void 				invertirDatos(struct GEN_III_SUBESTRUCTURA *subestructura);
struct GEN_III_SUBESTRUCTURA   *crearSubestructura(struct GEN_III *pokemon, char descifrar);
void				imprimirGEN_III(struct GEN_III *pokemon);
char 			       *convertirTextoGenIII(unsigned char *entrada, long longitud);
struct GEN_III 		       *leerDesdeDatos(char *datos, char descifrar);
void 				destruirGEN_III(struct GEN_III *pokemon);
unsigned short 			obtenerSumaGEN_III(struct GEN_III *pokemon);
void 				ordenarSubEstructura(struct GEN_III *pokemon);
void 				encriptarSubestructura(struct GEN_III *pokemon);
struct GEN_III 		       *exportarPokemonGEN_III(struct GEN_III *pokemon);
void 				exportarArchivoGEN_III(char *nombre, struct GEN_III *pokemon);
