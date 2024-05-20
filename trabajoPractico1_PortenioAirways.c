#include <stdio.h>
#include <string.h>


void validacionUsuario(int identificaciones[3], char *contrasenias[]);//con esta funcion vamos a validar que el usuario y contrasenia coinncida con alguno de los datos

void procesoDestino(char *destinosNacionales[], char *destinosInternacionales[][6]);//esta funcion se encargara de mostrar los destinos disponibles, tanto nacionales como internacionales;

//funcion que usaremos para mostrar los destinos nacionales disponibles:
void mostrarDestinoNacional(char *destinoInternacional[]);

//funcion que usaremos dentro de mosrarDestinosDisponibles para mostrar los destinos de los diversos continentes:
void mostrarDestinoExterior(char *destinoInternacional[][6], int opc);

void seleccionDestinoNacional(int codigoDestino, char *destinoNacioanal[],char *nombreDestino);//esta funcion sera la encargada de retornar el destino Nacional seleccionado por el cliente;

void seleccionDestinoInternacional(int codigoDestino, char *destinosInternacioanles[][6],char *nombreDestino, int continente);//esta funcion sera la encargada de retornar el destino internacional seleccionado por el cliente;

int main(){
	
	int identificaciones[3] = {1111, 2222, 3333};//identificaciones
	
	char *contrasenias[] = {"JPK12","PERU","LMH65", NULL};// contraseñas
	
	//llamamos a la funcion de validacion:
	validacionUsuario(identificaciones, contrasenias);
	
	//creamos los arreglos de los destinos:
	
	char *destinosNacionales[] = {"Chabut", "Cordoba","Corrientes","Entre Rios","Formosa","Jujuy","Rio Negro","Salta","San Luis","Santa Fe","Santiago del Estero","Tierra de fuego","Tucuman", NULL};
	//al decirle [][6] significa que sera un arreglo de elementos donde cada elemento sera un arreglo de 6 elementos ya que como
	//vemos nuestro elelemnto de mayor cantidad de elementos es europa y tiene 6 elementos
	char *destinosInternacionales[][6] = {
		{"Francia","Espania","Italia","Alemania","Reino Unido",NULL},//posicio 0 europa
		{"Estados Unidos","Mexico",NULL},//Posicion 1 america del norte
		{"China","Tailandia",NULL},//posicion 2 asia
		{"Turquia",NULL},// posicion 3 Medio oriente
		NULL};
	
	procesoDestino(destinosNacionales,destinosInternacionales);//llamamos a la funcion que muestra los destinos y pasamos los arrelos como argumentos
	
	return 0;
}

//validacion de usuario:
void validacionUsuario(int identificaciones[3], char *contrasenias[]){
	
	int validoIndentificacion, 
	validoContrasenia,
	i,
	identificacion;
	
	char contrasenia[5];
	
	//mostramos las identificaciones:
	printf("--------------------\nIdentificaciones:\n");
	for(i = 0; i < sizeof(identificaciones) / sizeof(identificaciones[0]); i++){
		printf("( %d )\n", identificaciones[i]);
	}
	//mostramos las contrasenias
	printf("--------------------\nContrasenias:\n");
	for(i = 0; contrasenias[i] != NULL; i++){
		printf("( %s )\n", contrasenias[i]);	
	}
	printf("--------------------\n");
	
	do{
		validoIndentificacion = 0;
		validoContrasenia = 0;
		
		fflush(stdin);
		printf("Ingrese un numero de usuario\n");
		scanf("%d", &identificacion);
		
		printf("Ingrese la contrasenia\n");
		scanf("%s", &contrasenia);
		
		for(i = 0; i < sizeof(identificaciones) / sizeof(identificaciones[0]); i++){
			if(identificacion == identificaciones[i]){
				validoIndentificacion = 1;
				break;
			}
		}
		for(i = 0; contrasenias[i] != NULL; i++){
			if( strcmp(contrasenia, contrasenias[i]) == 0){//usamos strcmp  la cual toma dos argumnetos , Devuelve un valor negativo si la primera cadena es menor que la segunda. Devuelve 0 si las dos cadenas son iguales. Devuelve un valor positivo si la primera cadena es mayor que la segunda.
				validoContrasenia = 1;
				break;
			}	
		}
		//si se equivoca validamos en cual se equivoco
		if(validoIndentificacion == 0 && validoContrasenia == 0){
			printf("Su identificacion y contrasenia no se encuentran registrados\n");
		}else{
			if(validoIndentificacion == 0){
				printf("Su identificacion no es correcta\n");
			}else{
				if(validoContrasenia == 0){
					printf("Su contrasenia no es correcta\n");
	
				}
			}
		}
		
	}while(validoIndentificacion == 0 || validoContrasenia == 0);
	system("cls");
}




//creamos la funcion que se encargara de todo el proceso de viaje: 
void procesoDestino(char *destinosNacionales[], char *destinosInternacionales[][6]){
	
	int i, tipo, continente,
		numeroDestino;
		
	char nombreDestino[20];// esta variable la usaremos como parametro por referencia y va a contener el nombre del destino selecionado
	
	do{
		printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");
		printf("1- Destinos Nacionales\n2-Destinos Internacionales\n");
		scanf("%d", &tipo);//leemos tipo de destino
		system("cls");//limpiamos la consola
	}while(tipo != 1 && tipo != 2);//validamos tipo de destino
	
	printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");
	
	if(tipo == 1){
		mostrarDestinoNacional(destinosNacionales);
		scanf("%d", &numeroDestino);
		//aqui le pasamos pais a la funccion que retorna el pais de selleccion:
		seleccionDestinoNacional(numeroDestino, destinosNacionales, nombreDestino);
		
	}else{
		do{
			printf("------------------------------------------\n   DESTINOS INTERNACIONALES DISPONIBLES:\n------------------------------------------\n");
			printf("1- Europa \n2- America del Norte \n3- Asia \n4- Medio Oriente\n");
			scanf("%d", &continente);//leemos el continente
			system("cls");//limpiamos la consola cada vez que se equivoca
		}while(continente <= 0 || continente > 4);//validamos el continente de destino
	    
	    printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");

	    //hacemos un switch que llamara la funcion que muestra los paises segun cada continente
		switch(continente){
			case 1:
				printf("------------------------------------------\n   DESTINOS DISPONIBLES EUROPA:\n------------------------------------------\n");
				//llamamos a la funcion que muetra los paises disponibles segun el continente, recibe como parametro el arreglo de destinosInternacionales
				//y continente que sera la posicion de elemento que vamos a iterar en el arreglo destinosInternacionales que contiene los paises segun el continente
				mostrarDestinoExterior(destinosInternacionales,continente);
				scanf("%d", &numeroDestino);
				break;
			case 2:
				printf("------------------------------------------\n   DESTINOS DISPONIBLES AMERICA DEL NORTE:\n------------------------------------------\n");
				//llamamos a la funcion que muetra los paises disponibles segun el continente
				mostrarDestinoExterior(destinosInternacionales,continente);
				scanf("%d", &numeroDestino);
				break;
			case 3:
				printf("------------------------------------------\n   DESTINOS DISPONIBLES ASIA:\n------------------------------------------\n");
				//llamamos a la funcion que muetra los paises disponibles segun el continente
				mostrarDestinoExterior(destinosInternacionales,continente);
				scanf("%d", &numeroDestino);
				break;
			case 4:
				printf("------------------------------------------\n   DESTINOS DISPONIBLES MEDIO ORIENTE:\n------------------------------------------\n");
				//llamamos a la funcion que muetra los paises disponibles segun el continente
				mostrarDestinoExterior(destinosInternacionales,continente);
				scanf("%d", &numeroDestino);
				break;
		}
		
		seleccionDestinoInternacional(numeroDestino, destinosInternacionales, nombreDestino, continente);
	}
	/*asi podemos saber el tamaño de un elemnto de destinosInternacionales elementos tamaño elemento 0 entre el tamaño de alguno de los elementos de 0:
	int e = sizeof(destinosInternacionales[0])/sizeof(destinosInternacionales[0][0]);
	printf("%d", e);*/
	system("cls");
    printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");
	printf("Destino seleccionado: %s", nombreDestino);
}
//funcion que nos mostrara los destinos nacionales
void mostrarDestinoNacional(char *destinosNacionales[]){
	int i;
	printf("------------------------------------------\n     DESTINOS NACIONALES DISPONIBLES:\n------------------------------------------\n");
	//mostramos los destinos nacionales disponibles, se ejecuta hasta encontrar el elemento NULL
	for(i = 0; destinosNacionales[i] != NULL; i ++){
		printf("%d- %s \n", (i+1), destinosNacionales[i]);
	}
}

//funcion que nos mostrara los destinos internacionales

void mostrarDestinoExterior(char *destinoInternacional[][6], int opc){
	
	int j, i;
	i = opc - 1;// le restamos 1 a opc asi es la posicion correcta en el arreglo
	
	/*el siguiente for recorrera el areglo en la posicion elejida por el usuario osea opc que hace referencia al contiente, asi que muestra
	solo los elementos del continente selecciona, i va a ser opc - 1 y j va a ir incrementandose en 1 , esto se ejecutara hasta que
	se encuentre el elemento NULL en el elemento que se esta iterando 
	*/
	for(j = 0; destinoInternacional[i][j] != NULL; j++){ 
		printf("%d- %s\n", (j+1), destinoInternacional[i][j]);
	}
	
}

//esta es la que se encargara de asignar el destino nacional seleccionado
void seleccionDestinoNacional(int numeroDestino, char *destinoNacioanal[], char *nombreDestino){
	int i;
	char nombre[20];
	//recorremos cada elemento de destinoNacional osea cada provincia
	for(i = 0; destinoNacioanal[i] != NULL; i++){
		if((numeroDestino - 1) == i){//si coincide numero de destino con i que es el elemento que se esta iterando entonces quiere decir que enconytramos el destino
			strcpy(nombreDestino,destinoNacioanal[i]);//le asignamos el valor del destino a nombreDestino que es el parametro que tenemos por referencia en la funcion 
			return;//cuando encuentra el destino sale inmediatamente del for
		}
	}
	
}

//esta es la que se encargara de asignar el destino internacional seleccionado
void seleccionDestinoInternacional(int numeroDestino, char *destinosInternacionales[][6], char *nombreDestino, int continente) {
    int i, j;
    i = continente - 1;
    /*el siguiente for recorrera el areglo en la posicion elejida por el usuario osea continente que hace referencia al contiente, asi que recorre
	solo los elementos del continente selecciona, i va a ser continente - 1 y j va a ir incrementandose en 1 , esto se ejecutara hasta que
	se encuentre el elemento NULL en el elemento que se esta iterando 
	*/
    for(j = 0; destinosInternacionales[i][j] != NULL; j++){
    	if((numeroDestino - 1) == j){
    		strcpy(nombreDestino,destinosInternacionales[i][j]);//le asignamos el valor del destino a nombreDestino que es el parametro que tenemos por referencia en la funcion
    		return;
		}
	}
}







