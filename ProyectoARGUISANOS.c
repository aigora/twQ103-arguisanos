#include<stdio.h>
int main(){
	
	//Declaración de variables
	int x=0;
	
	
	//Funcionalidades
	//Menu de Bienvenida y Opciones
	
	do{
		printf("Bienvenido a su asesor y planificador semanal del menu\n");
		printf("Por favor, seleccionen la tarea que desea realizar\n");
		printf("Pulse 1 para introducir nuevas recetas o platos\nPulse 2 para componer un nuevo menu\nPulse 3 para cambiar los filtros de creacion de menu\n");
		scanf("%i",&x);
		switch(x){
			case 1: printf("Usted ha seleccionado la introduzccion o consulta de su recetario");break;
			case 2: printf("Siga los siguientes pasos y en seguida tendrá su menú planteado");break;
			case 3: printf("Usted ha seleccionado realizar ajustes en los filtros de creación de menu, cualquier alteración sera guardada");break;
		}
	}while(x!=1&&x!=2&&x!=3);
}
