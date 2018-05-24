#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menu();
void ahorcado(int);
void ganaPierde(int );
int main(){
	char opcion; 		//PARA INGRESAR EL VALOR DEL JUEGO
	int estado=1; 		//SE USA PARA MOSTRAR EL AVATAR DEL AHORCADO SEGUN EL NIVEL DE VIDAS 1 (INICIAL),2,3,4(GAME OVER).
	int longitud=0;		//INDICA EL TAMAÑO DE LA PALABRA INGRESADA
	int banderaJuego=1; //PARA ROMPER EL BUCLE DEL JUEGO
	
	char palabraA[20]="";	//LA PALABRA CON LA CUAL SE JUGARA AL AHORCADO
	char cadena[40]="";		//ESTA CADENA ES USADA PARA MOSTRAR EN PANTALLA LOS ESPACION Y LETRAS ADIVINADAS
	char caracter;			//ES LA LETRA QUE INGRESARA PARA JUGAR
	int activar=0;			//ACTIVA EL JUEGO
	int muertes=0;			//contabiliza las fallas
	int vidas=3;			//SON LAS VIDAS DEL JUEGO  -- OJO --HAY QUE CAMBIAR AQUI Y ENTROS LUGARES SI SE DESEA MAS VIDAS
	char cadenaGanadora[20]; //para comparar si gano o no
	do{
		menu();										//LLAMA AL MENU CADA VEZ QUE SE ELIGE UNA OPCION
		estado=1;									//ES LA 'IMAGEN' DEL AVATAR 1 AL 4
		banderaJuego=1;								//CUANDO GANE O PIERDA SE TERMINA EL CICLO 
		activar=0;									//INICIA EL JUEGO
		muertes=0;									//SIRVE PARA VALIDAR LAS VIDAS
		vidas=3;									//DISMIYE CON CADA LETRA QUE SE EQUIVOCA EN EL JUEGO
		memset (cadena, 0, 40);						//MENSET => VACIA LA CADENA
		memset (cadenaGanadora, 0, 20);				
		scanf("%c",&opcion);						//INGRESA LA OPCION 1,2 O 3

						
		switch(opcion){						
			case '1':					//AQUI SE INGRESA LA PALABRA PARA EL JUEGO
				fflush(stdin);			//PARA LIMPIAR LA MEMORIA
				system("cls");			//LIMPIA LA PANTALLA
				printf("Ingrese la palabra con un tamano maximo de 20 caracteres: \n");
				gets(palabraA);			
				break;		
			case '2':							//****JUEGO*****
				if(palabraA[0]!= '\0'){					//PREGUNTA SE LA CADENA ESTA VACIA. /0 SIGNIFICA FIN DE UNA CADENA
					do{	
						banderaJuego=1;
						fflush(stdin);					
						system("cls");		
						printf("\n****************************");						//LIMPIA LA PANTALLA PARA JUGAR
						printf("\n********* A JUGAR **********");
						printf("\n****************************");
						printf("\n\n");
						ahorcado(estado);				//ENVIA EL ESTADO DEL AVATAR. POR DEFECTO SERA 1
						longitud = strlen(palabraA);	//CAPTURA EL TAMAÑO DE LA CADENA
						
						int j=0;
						muertes=0;
						int i=0;
						for (i=0;i<=(longitud+longitud-2);i++){
							if(i%2==0){
								if(activar==1){									//PREGUNTA SI ES LA PRIVERA VEZ QUE INICIO EL JUEGO			
									if(cadena[i]=='_'){							//PREGUNTA SI EN UN ESPACION YA ENCONTRO UNA LETRA: _ _ O _
										if(palabraA[j]==caracter){				//COMPARA SI LA LETRA INGRESADA EXISTE CASO CONTRARIO PIERDE LA VIDA
											cadena[i]=palabraA[j];				//AQUI LLENA LAS ESPACION _ _ _ ...
											cadenaGanadora[j]=palabraA[j];		//GRAVA LAS LETRAS PARA AL FINAL COMPARAR SI GANO
											muertes=muertes+1;					//SI PIERDE TIENE EL VALOR DE 0 CASO CONTRARIO >0
										}
									}	
								}else{
										cadena[i]='_';
										muertes=10;
									}
								
								j++;		
							}else{
								cadena[i]=' ';									//ASIGNADA LOS ESPACION ENTRE LOS GUIONES BAJOS _ _
							
							}	
						}
						printf("  %s",cadena);									//IMPRIME LOS ESPACIOS PARA LLENAR _ _ _
						if(muertes==0){											//SI PIERDE LE MERMA UNA VIDA. SI MUERTE=0=PIERDE
							estado=estado+1;
							vidas=vidas-1;
						}
						
						printf("\n\nMumero de vidas: %i",vidas);
						printf("\nIngrese una letra: ");
						if(strcmp(cadenaGanadora,palabraA)==0){					//COMPARA ENTRE LOS CARACTES INGRESADAS Y LA CADENA ORIGINAL. VALIDA SI GANA
							banderaJuego=0;										//FINALIZA EL JUEGO
							system("cls");
							ahorcado(estado);									//MUESTRA EL AVATAR
							ganaPierde(2);										//LLAMA AL METODO DE WINNER O GAME OVER
							printf("\n\n");
							system("pause");
						}
						if(estado>4){											//CUANDO ESTADO ES IGUAL A 4 PIERDE Y FINALIZA EL JUEGO
							banderaJuego=0;										//FINALIZA EL JUEGO
							estado=1; 	
							system("cls");
							ahorcado(4);
							ganaPierde(1);
							printf("\n\n");
							system("pause");
						}
						scanf("%c",&caracter);			//***CAPTURA EL CARACTER DEL JUEGO
						activar=1;
					}while(banderaJuego==1);
					
				}else{
					system("cls");
					printf("\n\nIngrese primero una palabra\n");
					system("pause");
					break;							
				}
			case '3':						
				system("cls");						//PARA SALIR DEL JUEGO
				printf("\nGracias por Jugar\n"); 
				break;
													
		}
	} while(opcion!='3');
	
	system("pause");
	return 0;
}

/*
MUSTRA EL MENU PRINCIPAL 
*/
void menu(){
	system("cls");
	printf("1. Ingresar palabras");
	printf("\n2. Jugar");
	printf("\n3. Salir");
	printf("\n\n");
	printf("\nIngrese el nUmero de la accion a realizar: ");
}

/**
METODO QUE DEVUELVE EL AVATAR SEGUN EL NIVEL DE VIDA
1. ESTADO INICIAL
2. PRIMERA MUERTE
3. SEGUNDA MUERTE
4. TERCERA MUERTE - GAME OVER
*/
void ahorcado(int estado){
	switch(estado){
		case 1:
			printf(" \n\n");
			printf("     +---+\n");
			printf("     |   |\n");
			printf("         |\n");
			printf("         |\n");
			printf("         |\n");
			printf("         |\n");
			printf("    =======\n");
			break;
		case 2:
			printf(" \n\n");
			printf("     +---+\n");
			printf("     |   |\n");
			printf("     O   |\n");
			printf("     |   |\n");
			printf("         |\n");
			printf("         |\n");
			printf("    =======\n");
			break;
		case 3:
			printf(" \n\n");
			printf("     +---+\n");
			printf("     |   |\n");
			printf("     O   |\n");
			printf("    /|\\  |\n");
			printf("         |\n");
			printf("         |\n");
			printf("    =======\n");
			break;
		case 4:
			printf(" \n\n");
			printf("     +---+\n");
			printf("     |   |\n");
			printf("     O   |\n");
			printf("    /|\\  |\n");
			printf("    / \\  |\n");
			printf("         |\n");
			printf("    =======\n");
			break;
	}
	
}

void ganaPierde(int gp){
	switch(gp){
		case 1:
			printf("   ____    _    __  __ _____    _____     _______ ____  \n");
			printf("  / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\ \n");
			printf(" | |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) |\n");
			printf(" | |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ /  \n");
			printf("  \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\ \n");
			break;
		case 2:	
			printf("           _                      \n");
			printf(" _      __(_)___  ____  ___  _____\n");
			printf("| | /| / / / __ \\/ __ \\/ _ \\/ ___/\n");
			printf("| |/ |/ / / / / / / / /  __/ /    \n");
			printf("|__/|__/_/_/ /_/_/ /_/\\___/_/     \n");
			break;
                                  

		}
}                                                                          


