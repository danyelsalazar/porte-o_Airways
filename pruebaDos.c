#include <stdio.h>
#include <string.h>
//--------------ESTRUCTURA asDECENDENTE---------------------
//1.Usuario se identifica
//identificacion de 6 digitos
//contrasenia de 8 caracteres

//---------------------DECLARAMOS E INICIALIZAMOS LAS VARIBALES GLOBALES------------------------
const float prercioEEUU = 2800000, prercioEuropa = 3500000, prercioAsia = 4200000;
const float recargaPrimeraClase = 3000000;



//-----------------------------------------------------------------
//declaramos la funcion de inicio de sesion
void mostrarDatosInicioSesion(char usuriosContrasenias[2][2][10], int tamanioArreglo);

//declaramos la funcion de validacion de usuario:
void validacionUser(char usuriosContrasenias[2][2][10], int *comprobado);



//declaramos la funcion que usaremos para recorrer y mostrar los destino de europa la cual recibira una matriz
void mostrarDestinosEuropa(char europa[3][3][20]);
//declaramos la funcion que usaremos para recorrer y mostrar los destino de asia y america la cual recibira un vector
void mostrarDestinosAsiaAmerica(char vector[3][20]);
//declaramos la funcion que usaremos para la seleccion de destino europa:
void seleccionDestinosEuropa(char europa[3][3][20], int opc,  char *nombreDestino);
//declaramos la funcion que usaremos para la seleccion de destino america y asia:
void seleccionDestinoAmericaAsia(char vector[3][20], int opc, char *nombreDestino);


//declaramos la funcion que mostrara los servivios adicionales
void mostrarServiciosAdicionales(int *equipaje, int *asiento, int *comida, int claseVuelo);


//declaramos la funcion para calcular el precio del boleto:
float calculoPrecioBoleto(int continente, int tipoVuelo, int equipaje, int asiento, int comida);


//iniciamos el main :
int main(){
	
	//-------------------------------VALIDACION DE USUARIO---------------------------------------------
	//creamos una matriz de strings
	//[cantidad de arreglos dentro del arreglo][cantidad de elementos que tendra cada arreglo adentro][cantidad de carancteres que tendra cada elemento]
	char usuriosContrasenias[2][2][10] = {{"JDKKKK","12345678"},{"FDMMMM","87654321"}};
	//guaradamos el tamanio del arreglo,:
	int tamanioArreglo = sizeof(usuriosContrasenias) / sizeof(usuriosContrasenias[0]);
    //printf("Tamanio arreglo: %d", tamanio);

	//llamamos a la funcion que nos muestra los datos de inicio de sesion:
	mostrarDatosInicioSesion(usuriosContrasenias, tamanioArreglo);
	
	//llamamos a la funcion de validacion de usuario:
	int comprobado; // esta varibale la usaremos como referencia para saber si se valido o no el usuario o(no) 1(si)
	validacionUser(usuriosContrasenias, &comprobado);
	printf("Comprobado: %d", comprobado);

	//-----------------------------------------------------------------------------------------------------------
	system("cls");
	//--------------------------DESTINOS DE VIAJE---------------------------------------------------------
	
	//cremaos las matrices/vectores de los destinos:
	char europa[3][3][20] ={{"Espania","15 de Noviembre","15:30pm"},{"Francia","3 de Noviembre","14:00pm"},{"Italia","28 de Enero","11:00am"}};
	char americaDelNorte[3][20] = {"Estados Unidos","12 de Diciembre","18:00pm"};
	char asia[3][20] = {"China","9 de Enero","10:00am"};
	
	int opc; 
	char nombreDestino[20];
	
	
	printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");
	int continente, sigue = 1;
	
	do{
		//preguntamos el continente de destino:
		printf("------------------\nDESTINOS INTERNACIONALES DISPONIBLE\n------------------\n");
		printf("1- Europa\n2- America del Norte\n3- Asia\n");
		scanf("%d", &continente);
		system("cls");//limpiamos la consola
	    printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");

		switch(continente){
			case 1:
				
				mostrarDestinosEuropa(europa);// llamamaos la funcion de mostrar el destino
				do{
					scanf("%d", &opc);//recinimos la opcion de destino
					if(opc != 1 && opc != 2 && opc != 3){
						printf("El destino selecionado no se encuentra registrado, ingresa un dato correcto\n");
					}
				}while(opc != 1 && opc != 2 && opc != 3);
				
				seleccionDestinosEuropa(europa, opc, nombreDestino);//asigamos el destino por medio de la funcion a la varibale nombreDestino
				printf("nombre destino: %s", nombreDestino);
				break;
			case 2:
				mostrarDestinosAsiaAmerica(americaDelNorte);
				do{
					scanf("%d", &opc);
					if(opc != 1){
			    		printf("El destino selecionado no se encuentra registrado, ingresa un dato correcto\n");
					}
				}while(opc != 1);
				
				seleccionDestinoAmericaAsia(americaDelNorte, opc, nombreDestino);
				printf("nombre destino: %s", nombreDestino);
				break;
			case 3: 
			    mostrarDestinosAsiaAmerica(asia);
			    do{
			    	scanf("%d", &opc);
			    	if(opc != 1){
			    		printf("El destino selecionado no se encuentra registrado, ingresa un dato correcto\n");
					}
				}while(opc != 1);
				
			    seleccionDestinoAmericaAsia(asia, opc, nombreDestino);
			    //printf("nombre destino: %s", nombreDestino);
			break;
		}
		
		//------------------------------------TIPO DE VUELO Y SERVIVIO ADICIONAL-------------------------------------
		system("cls");//limpiamos la consola
		int tipoVuelo, servicioAdicional, adicional, 
			equipaje = 0, 
			asiento = 0,
			comida= 0 ;
		
		printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");

		printf("---------------------------------\n         Ingrese la clase de vuelo:\n---------------------------------\n1- Economica\n2- Primera Clase\n");
		do{
			scanf("%d", &tipoVuelo);
			if(tipoVuelo != 1 && tipoVuelo != 2){
				printf("La opcion ingresada no corresponde a ninguna clase\n");
			}
		}while(tipoVuelo != 1 && tipoVuelo != 2);
		
		system("cls");//limpiamos
		printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");
		printf("-----------------------------------\n         Solicitud de servicios\n-----------------------------------\n");
		//preguntamos si desea servivios adicionales: 
		printf("1- Desplegar menu de servicios adicionales \n2- Continuar sin servicios adicionales\n");
		do{
			scanf("%d", &adicional);
			if(adicional != 1 && adicional != 2){
				printf("La opcion ingresada es incorrecta vuleve a intentarlo\n");
			}	
		}while(adicional != 1 && adicional != 2);
		
		if(adicional == 1){
			system("cls");//limpiamos
	    	printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");
			//llamamos a la funcion de que muetra los servicios adicionales
			mostrarServiciosAdicionales(&equipaje, &asiento, &comida, tipoVuelo);
			printf("Equipaje: %d, asiento: %d , comida: %d\nTipo de clase (1 economica) (2 primera clase): %d\n", equipaje, asiento, comida, tipoVuelo);
			printf("nombre destino: %s", nombreDestino);
		}
		
		//----------------------------------------CALCULO DEL PRECIO DEL BOLETO-----------------------
		
		float costoBoleto = 0;
		//llamamos a la funcion de calcular el precio del boleto:
		
		
		
		
		
		//---------preguntamos si desea realizar otro tramite osea otro proceso
		printf("Hacer otro tramite de vuelo: 1(si) 2(no)\n");
		scanf("%d", &sigue);
		
		
		break;
		
	}while(comprobado == 1 && sigue == 1);
	
	
	
	return 0;
}

//funcion que usaremos para mostrar los usuarios y contrasenias para asi poder iniciar secion,
//sus parametros seran la matriz y el tamanio de elementos que tiene linealmente
void mostrarDatosInicioSesion(char usuriosContrasenias[2][2][10], int tamanioArreglo){
	int f, c;
    //recorremos y mostramos las identificaciones con sus contrasenias
    printf("----------------------------------------------------------\n            DATOS PARA INICIAR SESION\n----------------------------------------------------------\n");
    for(f = 0; f < tamanioArreglo; f++){
    	for(c = 0; c == 0; c++){
    		printf("----------------------------------------------------------\nDATOS USER %d\nIDENTIFICACION: ( %s ) , CONTRASENIA: ( %s )\n----------------------------------------------------------\n", (f+1),usuriosContrasenias[f][c], usuriosContrasenias[f][c+1] );
		}
	}
}

//funcio que validara los datos del usuario y nos dara acceso o no a la plataforma del aereopuero:
void validacionUser(char usuriosContrasenias[2][2][10], int *comprobado){
	char identificacion[10], contrasenia[10];
	int validacion = 0;
	do{
		//solicitamos identificacion:
		printf("Ingresa la identificacion: \n");
		scanf("%s", &identificacion);
		//solicitamos la contrasenia:
		printf("Ingresa la contrasenia\n");
		scanf("%s", &contrasenia);
		
		if((strcmp(identificacion, usuriosContrasenias[0][0]) == 0) && (strcmp(contrasenia,usuriosContrasenias[0][1]) == 0)){
			validacion = 1; // validacion sera 1 cuando la identificacion y la contrasenia coincidan
		}else{
			if((strcmp(identificacion,usuriosContrasenias[1][0]) == 0) && (strcmp(contrasenia,usuriosContrasenias[1][1]) == 0)){
				validacion = 1; // validacion sera 1 cuando la identificacion y la contrasenia coincidan
			}else{
				printf("!!!--Usuario o contrasenia incorrectos--!!!\n"); // si no son correctos le informamos al usuario y se repite el bucle
			}
		}
	}while(validacion == 0);
	
	*comprobado = validacion;
}


//creamos la funcion que mostrara los destinos de europa:
void mostrarDestinosEuropa(char europa[3][3][20]){
	int f, c, datos = 0;
	printf("------------------------\nDESTINOS EUROPA\n------------------------\n");
	
	for(f = 0; f < 3; f++){
		for(c = 0; c < 1; c++){
			printf("%d- %s / %s / %s\n", (f+1), europa[f][c], europa[f][datos + 1], europa[f][datos + 2]);
		}
	}
	printf("------------------------------------------------\n");
}

//creamosa la funcion que mostrara los destinos de asia y america del norte:
void mostrarDestinosAsiaAmerica(char vector[3][20]){
	int f;
	printf("1- ");
	for(f = 0; f < 3; f++){
		printf("%s / ", vector[f]) ;
	}
	
}

//creamos la funcion de seleccion de destino de europa:
void seleccionDestinosEuropa(char europa[3][3][20], int opc, char *nombreDestino){
	int f,c;
	
	for(f = 0; f < 3; f++){
		for(c = 0; c < 1; c++){
			if(opc == f+1){
				strcpy(nombreDestino, europa[f][c]);
				return;
			}
		}
	}
	
}
//cremaos la funcion de selecio de destino de asia y america
void seleccionDestinoAmericaAsia(char vector[3][20], int opc, char *nombreDestino){
	int f;
	
	for(f = 0; f < 1; f++){
		if(opc == f+1){
			strcpy(nombreDestino, vector[f]);
		}
	}
}


//creamos la funcion de los servicios adicionales:
void mostrarServiciosAdicionales(int *equipaje, int *asiento, int *comida, int claseVuelo){
	
	int continuar = 0, 
	 auxEquipaje = 0,
	 auxAsiento = 0,
	 auxComida = 0,
	 tipoServicioAdi;
	 
	//mostramos los servivios disponibles y esperamos la entrada del usuario
	printf("-----------------------------------------------\n           SERVICIOS ADICIONALES\n-----------------------------------------------\n");
    //leemos y validamos el tipo de servivio adicional:
    do{
		printf("1- Equipaje adicional\n2- Seleccion de asiento espesifico\n3- Comida\n");
		do{
    		scanf("%d", &tipoServicioAdi);
    		//si ingresa una opcion erronea le informamos:
    		if(tipoServicioAdi != 1 && tipoServicioAdi != 2 && tipoServicioAdi != 3){
    			printf("El servivo solicitado no existe, vuelve a ingresar el numero de servivo\n");
			}else{
				//ahora validamos que no vuelva a elegir el mismo servivio que ya solicito:
				switch(tipoServicioAdi){
					case 1: 
						if(auxEquipaje == 0){
							*equipaje = 1; // le asignamos 1 a la variable que veiene por referencia para asi saber que contrato ese servicio adicional
							auxEquipaje = 1;
						}else{
							printf("El servicio ingresado ya lo solicitaste\n");
						}
						break;
					case 2: 
						if(auxAsiento == 0){
							*asiento = 1;// le asignamos 1 a la variable que veiene por referencia para asi saber que contrato ese servicio adicional
							auxAsiento = 1;
				  	  	}else{
							printf("El servicio ingresado ya lo solicitaste\n");
				   	 	}
				   	 	break;
					case 3:
						//verificamos si es primera clase o no y en caso de serlo le informamos que ya trae incluida la comida
						if(claseVuelo == 2){
							printf("La primera clase ya incluye comida\n");
						}else{
							if(auxComida == 0){
								*comida = 1;// le asignamos 1 a la variable que veiene por referencia para asi saber que contrato ese servicio adicional
								auxComida = 1;
				   			}else{
								printf("El servicio ingresado ya lo solicitaste\n");
				  	    	}
						}
				    	break;
				}
			}
		}while(tipoServicioAdi != 1 && tipoServicioAdi != 2 && tipoServicioAdi != 3);
		
		//preguntamos si desea aniadir otro servicio:
		printf("Deseas aniadir otro servicio adicional? 1(SI) 2(NO)\n");
		scanf("%d", &continuar);
		
	}while(continuar == 1);
	
}


//creamos la funcion que hara el calculo del boleto:
float calculoPrecioBoleto(int continente, int tipoVuelo, int equipaje, int asiento, int comida){
	float calculo = 0;
	
	switch(continente){
		case 1:
			calculo +=  europa;
			break; 
	}
	
}








