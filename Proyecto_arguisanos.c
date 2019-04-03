#include<stdio.h>
int main(){
	
	//Declaración de variables
	int x=0;
	char Usuario[15];
	int funcion1;
	
	//Funcionalidades
	//Menu de Bienvenida y Opciones
	
	do{
		printf("Bienvenido a su asesor y planificador semanal del menu\n");
		printf("Por favor, seleccionen la tarea que desea realizar\n");
		printf("Pulse 1 para iniciar sesion con una cuenta de usuario\n");
		printf("Pulse 2 para acceder como invitado\n");
		printf("Pulse 3 para crear una cuenta\n");
		printf("Pulse 4 para abandonar el programa");
		scanf("%i",&x);
		switch(x){
			//Usuario previo
			case 1: printf("Bienvenido\n");
			break;
			//Acceso como invitado
			case 2: printf("Siga los siguientes pasos y en seguida tendrá su menú planteado\n");
			break;
			//Creación de cuenta
			case 3: printf("Usted ha seleccionado realizar ajustes en los filtros de creación de menu, cualquier alteración sera guardada\n");
			break;
			//Abandono del programa
			case 4: printf("¿Usted a seleccionado abandonar el programa, ¿seguro que desea salir (Los cambios no guardados se perderán)\n");
			break;
		}
	}while(x!=1&&x!=2&&x!=3&&x!=4);
}

int funcion1(){
	//Variables
	char Ususario[15];
	//Funcionalidades
	printf("Introduzca su Usuario\n");
	gets(Ususario[15]);
}
