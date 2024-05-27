#include <stdio.h>
#include <string.h>
#include <time.h>

//---ESTRUCTURA ASCENDENTE---

//------Variables globales------
int CapacidadAvion_Eco = 200;
int CapacidadAvion_Premium = 50;

float ValorDest_America = 2800000;
float ValorDest_Europa = 3500000;
float ValorDest_Asia = 4200000;

float PorcFecha_Eco = 30;
float PorcFecha_Premium = 40;

float PorcAnticipacion = 50;

float Diferencia_EcoPremium = 3000000;

float Serv_EquipAdd = 150000;
float Serv_Asiento = 40000;
float Serv_Comida = 20000; //Solo para clase economica



//---------------FUNCIONES---------------



//---------------FUNCIONN PARA VALIDACION DE USUARIO---------------

//funcion que usaremos para mostrar los usuarios y contrasenias para asi poder iniciar secion, sus parametros seran la matriz y el tamanio de elementos que tiene linealmente.
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

//funcion que validara los datos del usuario y nos dara acceso o no a la plataforma del aereopuero:
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
//-----------------------------------------------------------------



//---------------FUNCION PARA SELECCION DE DESTINO---------------

//creamos la funcion que mostrara los destinos de europa:
void mostrarDestinosEuropa(char europa[3][3][20]){
	int f, c, datos = 0;	
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
//----------------------------------------------------------------



//---------------FUNCION PARA VALIDACION DE LA FECHA DE HOY---------------

//Validacion de fecha desde 1 Enero 2024 hasta 1 de Enero de 2025
int FechaValida(int year, int month, int day) {
    if ((year == 2024 && (month <= 12 && month >= 1) && (day <= 31 && day >= 1)) || (year == 2025 && month == 1 && day == 1)) {
        return 0;
    }
    else{
    	return 1;
	}
}
//----------------------------------------------------------------




//---------------FUNCION PARA CALCULAR MESES DE DIFERENCIA---------------

//Se calcula los meses de diferencia sin tener en cuenta el d√≠a
int Calc_MesesDiferencia(struct tm fechaHoy, char nombreDestino[20]){
    struct tm Fecha_Destino = {0};
    int year_dest, month_dest;


    if(strcmp(nombreDestino, "Francia") == 0){
        year_dest = 2024;
        month_dest = 11;
    } else if(strcmp(nombreDestino, "Espania") == 0){
        year_dest = 2024;
        month_dest = 11;
    } else if(strcmp(nombreDestino, "Estados Unidos") == 0){
        year_dest = 2024;
        month_dest = 12;
    } else if(strcmp(nombreDestino, "China") == 0){
        year_dest = 2025;
        month_dest = 1;
    } else {
        year_dest = 2025;
        month_dest = 1;
    }

    Fecha_Destino.tm_year = year_dest - 1900;
    Fecha_Destino.tm_mon = month_dest - 1;

    int year_diff = Fecha_Destino.tm_year - fechaHoy.tm_year;
    int month_diff = Fecha_Destino.tm_mon - fechaHoy.tm_mon;

    int MesesDif = year_diff * 12 + month_diff;

    return MesesDif;
}
//----------------------------------------------------------------

//----------------------------------------------------------------


//--------------------------FUNCION PARA SERVICIOS ADICIONALES---------------------------

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
		printf("1- Equipaje adicional\n2- Seleccion de asiento especifico\n3- Comida\n");
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

//----------------------------------------------------------------------------------------

//-------FUNCION PARA EL CALCULO PRECIO BOLETO---------------

//creamos la funcion que hara el calculo del boleto:
float calculoPrecioBoleto(int continente, int tipoVuelo, int equipaje, int asiento, int comida,int MesesDiferencia){
	float boleto = 0;
	
	switch(continente){
		case 1:
			boleto +=  ValorDest_Europa;
			break; 
		case 2: 
			boleto += ValorDest_America;
			break;
		case 3:
			boleto += ValorDest_Asia;
			break;
	}
	
	//verificamos si es economica o primera clase:
	if(tipoVuelo == 2){
		boleto += Diferencia_EcoPremium;
		boleto += (boleto * PorcFecha_Premium)/ 100;// ya que todos los vuelos estan en vacaciones de verano le agregamos el 40% por ser primera clase
	}else{
		boleto += (boleto * PorcFecha_Eco)/ 100;// ya que todos los vuelos estan en vacaciones de verano le agregamos el 30% por ser clase economica
	}
	 //verificamos si solicito algun servicio:
	if(equipaje == 1){
		boleto += Serv_EquipAdd;
	}
	
	if(asiento == 1){
		boleto += Serv_Asiento;
	}
	
	if(comida == 1){
		boleto += Serv_Comida;
	}
	
	//verificamos los meses de anticipacion asi le asignamos o no el descuento al precio total por anticipacion
	//el valor que tomaremos sera el boleto total que ya incluye los servicios, vacaciones de verani, clase de vuelo.
    if (MesesDiferencia >= 5) {
        boleto = (boleto * PorcAnticipacion) / 100;
    }
    //retornamos el valor total del vuelo
    return boleto;

}



//-------------------------------------------------------------FUNCION MAIN-------------------------------------------------------------

int main(){

	//---------------------------------INICIALIZACI√ON DE VARIABLES---------------------------------
	
	// ------------------------------acumuladores y contadores FINAL DEL PROGRAMA------------------------------------------
	int totalPasajeros;
	float totalRecaudado;
	//aqui recuerda poner el vector que usaras para buscar elo destino mas solicitado
	
	//------------------------------PREGUNTA INICIO SESION------------------------------
	
	char RTA[2]; //Se preguntarpa° si se desea iniciar sesion (SI/NO)
	
	//----------------------------------------------------------------
	
	
	//------------------------------VALIDACION DE USUARIO------------------------------
	
	//creamos una matriz de strings
	//[cantidad de arreglos dentro del arreglo][cantidad de elementos que tendra cada arreglo adentro][cantidad de carancteres que tendra cada elemento]
	char usuriosContrasenias[2][2][10] = {{"JDKKKK","12345678"},{"FDMMMM","87654321"}};
	//guaradamos el tamanio del arreglo:
	int tamanioArreglo = sizeof(usuriosContrasenias) / sizeof(usuriosContrasenias[0]);
	int comprobado; // esta varibale la usaremos como referencia para saber si se valido o no el usuario: 0(no), 1(si).
	
	//----------------------------------------------------------------
	
	
	
	//------------------------------DESTINO------------------------------
	
	//cremaos las matrices/vectores de los destinos:
	char europa[3][3][20] ={{"Espania","15 de Noviembre","15:30pm"},{"Francia","3 de Noviembre","14:00pm"},{"Italia","28 de Enero","11:00am"}};
	char americaDelNorte[3][20] = {"Estados Unidos","12 de Diciembre","18:00pm"};
	char asia[3][20] = {"China","9 de Enero","10:00am"};
	
	int opc; //numero de la opci√≥n escogida
	char nombreDestino[20]; // Codigo del destino
	
	int continente, sigue = 1;
	
	//----------------------------------------------------------------
	
	
	
	//------------------------------FECHA y ANTICIPACION-----------------------------
	struct tm fechaHoy = {0};
    int year, month, day;
    
    int MesesDiferencia;
	//-----------------------------------------------------------------

	
	//------------------------------CAPACIDAD DEL AVION-----------------------------------
	
	//Capacidad del avion [Clase economica, Primera Clase]
    int Plane_FranciaEco = 200, Plane_FranciaFirstC = 50; 
    int Plane_EspaniaEco = 200, Plane_EspaniaFirstC = 50;
    int Plane_EEUUEco = 200, Plane_EEUUFirstC = 50;
    int Plane_ChinaEco = 200, Plane_ChinaFirstC = 50;
    int Plane_ItaliaEco = 200, Plane_ItaliaFirstC = 50;
	
	//-----------------------------------------------------------------
	
	
	//------------------------------------TIPO DE VUELO Y SERVIVIO ADICIONAL-------------------------------------
	int tipoVuelo, servicioAdicional, adicional, 
		equipaje = 0, 
		asiento = 0,
		comida= 0 ;
	//-----------------------------------------------------------------
	
	
	//----------------------------VALOR TOTAL DEL VUELO------------------------------------------------
	float costoBoleto = 0;
	
	//-----------PREGUNTA----------
	do{
		printf("Desea iniciar sesion? SI/NO: ");
		scanf("%s", &RTA);
		//Limpiar buffer
	}while(strcmp(RTA, "SI")!=0&&strcmp(RTA,"NO")!=0);
	
	
	if(strcmp(RTA,"NO")==0){
		printf("Cerrando Sesion...\n");
		Sleep(2000);
	}
	//------------------------------
	
	system("cls");
	
	//-----------BUCLE WHILE--------------
	while(strcmp(RTA,"SI")==0){
		//--Se ingresan datos
		
			//---------------VALIDAR USUARIO------------
			//llamamos a la funcion que nos muestra los datos de inicio de sesion:
			mostrarDatosInicioSesion(usuriosContrasenias, tamanioArreglo);
			
			//llamamos a la funcion de validacion de usuario:
			validacionUser(usuriosContrasenias, &comprobado);
			printf("Comprobado: %d", comprobado);
			
			system("cls");
			//------------------------------------------
			
			while(comprobado == 1){
			
			totalPasajeros ++;//incrementamos la cantidad de pasajeros 
			
				//------------------SELECCIONAR DESTINO------------------
				
				//preguntamos el continente de destino:
				printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");
				printf("------------------\nDESTINOS INTERNACIONALES DISPONIBLES\n------------------\n");
				printf("1- Europa\n2- America del Norte\n3- Asia\n");
				scanf("%d", &continente);
				system("cls");
			    printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");
		
				switch(continente){
					case 1:
						printf("------------------------\n   DESTINOS EUROPA\n------------------------\n");
						mostrarDestinosEuropa(europa);// llamamaos la funcion de mostrar el destino
						do{
							scanf("%d", &opc);//recibimos la opcion de destino
							if(opc != 1 && opc != 2 && opc != 3){
								printf("El destino selecionado no se encuentra registrado, ingresa un dato correcto\n");
							}
						}while(opc != 1 && opc != 2 && opc != 3);
						
						seleccionDestinosEuropa(europa, opc, nombreDestino);//asignamos el destino por medio de la funcion a la varibale nombreDestino
						printf("Nombre del destino: %s", nombreDestino);
						break;
					case 2:
						printf("------------------------\nDESTINOS AMERICA DEL NORTE\n------------------------\n");
						mostrarDestinosAsiaAmerica(americaDelNorte);
						do{
							scanf("%d", &opc);
							if(opc != 1){
					    		printf("El destino selecionado no se encuentra registrado, ingresa un dato correcto\n");
							}
						}while(opc != 1);
						
						seleccionDestinoAmericaAsia(americaDelNorte, opc, nombreDestino);
						printf("Nombre del destino: %s", nombreDestino);
						break;
					case 3: 
						printf("------------------------\n   DESTINOS ASIA\n------------------------\n");
					    mostrarDestinosAsiaAmerica(asia);
					    do{
					    	scanf("%d", &opc);
					    	if(opc != 1){
					    		printf("El destino selecionado no se encuentra registrado, ingresa un dato correcto\n");
							}
						}while(opc != 1);
						
					    seleccionDestinoAmericaAsia(asia, opc, nombreDestino);
					break;
				}
				//---------------------------------------------------------
				
				system("cls");
				
				//----------------------------------------FECHA DE HOY-------------------------------------------
				printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");
				do{
					printf("------------------\nFECHA (AAAA MM DD)\n------------------\n");
				    printf("\nIngrese la fecha de hoy: ");
				    scanf("%d %d %d", &year, &month, &day);
				    fechaHoy.tm_year = year - 1900;
				    fechaHoy.tm_mon = month - 1;
				    fechaHoy.tm_mday = day;
					//Limpiar buffer
				}while(FechaValida(fechaHoy.tm_year + 1900, fechaHoy.tm_mon + 1, fechaHoy.tm_mday));
				//-----------------------------------------------------------------------------------
				
				system("cls");// limpiamos
				
				MesesDiferencia = Calc_MesesDiferencia(fechaHoy, nombreDestino); //Se calculan los meses de diferencia
				
				//-------------------------------------------------------TIPO DE VUELO-------------------------------------------------------------------------------
				
				printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");
		
				printf("---------------------------------\n         Ingrese la clase de vuelo:\n---------------------------------\n1- Economica\n2- Primera Clase\n");
				do{
					scanf("%d", &tipoVuelo);
					if(tipoVuelo != 1 && tipoVuelo != 2){
						printf("La opcion ingresada no corresponde a ninguna clase\n");
					}
				}while(tipoVuelo != 1 && tipoVuelo != 2);
				
				//-----------------------------------------------------------------------------------------------------------------------------------------------------
				
				system("cls");//limpiamos
				
				//------------------------------------------------------------SERVICIOS ADICIONALES---------------------------------------------------------------------
				
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
					//printf("Equipaje: %d, asiento: %d , comida: %d\nTipo de clase (1 economica) (2 primera clase): %d\n", equipaje, asiento, comida, tipoVuelo);
					//printf("nombre destino: %s\n", nombreDestino);
				}

				//-----------------------------------------------------------------------------------------------------------------------------------------------------
				
				system("cls");
				
				
				
				//------------------------------------------------------------SE MUESTRA BOLETO---------------------------------------------------
				
				//llamamos a la funcion que calcula el precio del boleto:
				costoBoleto = calculoPrecioBoleto(continente, tipoVuelo, equipaje, asiento, comida, MesesDiferencia);
				
				//mostramos los datos del boleto
				printf("--------------------------------------------\n______________PORTENIO AIRWAYS______________\n--------------------------------------------\n");
				printf("---------------------------------------\n                 BOLETO\n---------------------------------------\n\n");
				printf("Equipaje: %d, asiento: %d , comida: %d\nTipo de clase:\n(1 economica) (2 primera clase): %d\n\n", equipaje, asiento, comida, tipoVuelo);
				printf("nombre destino: %s\nContinente: %d\n\n", nombreDestino, continente);
				printf("Meses de anticipacion: %d\n\n", MesesDiferencia);
				printf("El costo total del voleto es: %.2f $\n\n---------------------------------------\n---------------------------------------", costoBoleto);
				//---------------------------------------------------------------------------------------------------------------------------------
				
				//system("cls");
				
				//INICIALIZAMOS LAS VARIABLES NECESARIAS A 0
				equipaje = 0;
				comida = 0;
				asiento = 0;
				totalRecaudado += costoBoleto;
				//----------------
				comprobado = 0; //Para salir del bucle
			}
		
			//----Pregunta----------
			do{
				printf("\nDesea iniciar sesion? SI/NO: ");
				scanf("%s", &RTA);
				//Limpiar buffer
			}while(strcmp(RTA, "SI")!=0&&strcmp(RTA,"NO")!=0);
			system("cls");//limpiamos	
	}
	
	//--Se muestran resultados finales
	
	
	return 0;
}


