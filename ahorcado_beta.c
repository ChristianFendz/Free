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
	int vidas=3;
	char cadenaGanadora[20]; //para comparar si gano o no
	do{
		menu();		
		estado=1;
		banderaJuego=1;
		activar=0;
		muertes=0;
		vidas=3;
		memset (cadena, 0, 40);
		memset (cadenaGanadora, 0, 20);					
		scanf("%c",&opcion);	
		int c,cont=0;
						
		switch(opcion){							//CAPTURA LA OPCION REQUERIDA
			case '1':									//GUARDA LA PALABRA EN LA CADENA palabraA
				fflush(stdin);
				system("cls");
				printf("Ingrese la palabra con un tamano maximo de 20 caracteres: \n");
				gets(palabraA);
				break;		
			case '2':
				if(palabraA[0]!= '\0'){					//PREGUNTA SE LA CADENA ESTA VACIA. /0 SIGNIFICA FIN DE UNA CADENA
					do{	
						banderaJuego=1;
						fflush(stdin);					//PARA LIMPIAR LA MEMORIA
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
								if(activar==1){
									if(cadena[i]=='_'){
										if(palabraA[j]==caracter){
											cadena[i]=palabraA[j];
											cadenaGanadora[j]=palabraA[j];
											muertes=muertes+1;
										}
									}	
								}else{
										cadena[i]='_';
										muertes=10;
									}
								
								j++;		
							}else{
								cadena[i]=' ';
							
							}	
						}
						printf("  %s",cadena);
						if(muertes==0){
							estado=estado+1;
							vidas=vidas-1;
						}
						
						printf("\n\nMumero de vidas: %i",vidas);
						printf("\nIngrese una letra: ");
						if(strcmp(cadenaGanadora,palabraA)==0){
							banderaJuego=0;
							system("cls");
							ahorcado(estado);
							ganaPierde(2);
							printf("\n\n");
							system("pause");
						}
						if(estado>4){
							banderaJuego=0;
							estado=1; 	
							system("cls");
							ahorcado(4);
							ganaPierde(1);
							printf("\n\n");
							system("pause");
						}
						scanf("%c",&caracter);
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


