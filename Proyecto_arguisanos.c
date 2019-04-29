#include<stdio.h>
#include<stdlib.h>
int main(){
	
	int opcion=0, opcion2=0,opcion3=0, i=0, j=0, contador=0, verificador=1;
	char pulse_continuar, usuario[20], clave[20], verificar_clave[20];
	
	do{
		do{
			
		printf("\n\t\t\t\tARGUISANOS\n\t");
		printf("    Asesor y planificador semanal de menus y recetas\n\n\n");
		printf("\tIntroduzca la opcion deseada:\n\n");
		printf("\t\t1-Iniciar sesion\n");
		printf("\t\t2-Crear cuenta nueva\n");
		printf("\t\t3-Recetario ARGUISANOS\n");
		printf("\t\t4-Salir\n");
		
			if(i>0){
			
				printf("\tPor favor, seleccione una de las opciones en pantalla\n");
			
			}
			
				
			scanf("%d",&opcion);
			fflush(stdin);
			
			switch(opcion){
				case 1: 
					system("cls");
					printf("\n\tIntroduzca usuario:\n");
					gets(usuario);
					
					printf("Si el usuario estaba registrado se verifica su contrasena, si no se le pregunta si lo que quiere es registrarse\n");
					printf("\tIntroduzca su clave:\n");
					gets(clave);
					
					printf("Si la clave no tiene relacion con el usuario devolver error y le quedan tantos intentos. \nSi intentos==0 entonces le decimos que ha realizado demasiados intentos y se cierra el programa al pulsar una tecla\n");
					printf("Si es correcta, continua dentro del menu del usuario\n El menu del usuario sera generico pero con ficheros que dependen del usuario\n");
					system("pause");
					break;
				
				case 2:
					do{
						verificador=1;
						if(contador>0)
							printf("Ha habido un error introduciendo la clave\n");
							
						printf("Crear una cuenta nueva");
						printf("\n\tIntroduzca usuario:\n");
						gets(usuario);
						
						printf("\tIntroduzca su clave:\n");
						gets(clave);
						
						printf("\tIntroduzca de nuevo su clave:\n");
						gets(verificar_clave);
						
						i=0, j=0;
						
						while(clave[i]!='\0')
						i++;
						
						while(verificar_clave[j]!='\0')
						j++;
						
						if(i==j){
							for(i=0;i<=j;i++){
								if(clave[i]!=verificar_clave[i])
									verificador=0;
							}
						}
						else{
							verificador=0;
						}	
	
						contador++;
					}
					while (verificador==0);
					printf("Bienvenido %s\n",usuario);
					system("pause");
					break;
					
				case 3:
					printf("\n\tRecetario ARGUISANOS\n");
					printf("Imprimira las opciones de recetas\n");
					system("pause");
					break;
				
				case 4:
	  				return 0;
				
			}
			i++;
			system("cls");
		}
			while(opcion!=1);
			
	
		
		printf("\n\t\t\t\tARGUISANOS\n\t");
		printf("    Asesor y planificador semanal de menus y recetas\n\n");
		printf("\nBienvenido %s\n\n", usuario);
		printf("\t\t1-Ver menu\n");
		printf("\t\t2-Planificar menu\n");
		printf("\t\t3-Recetario\n");
		printf("\t\t4-Cerrar sesion\n");
		printf("\t\t5-Salir\n");
			
		
		do{
			scanf("%i",&opcion2);
			switch(opcion2){
				case 1: 
					system("cls");
					printf("\t\t1-Menu semanal\n");
					printf("\t\t2-Menu mensual\n");
					printf("\t\t3-Menu proximo mes\n");
					printf("\t\t4-Volver a mi sesion\n");
					printf("\t\t5-Salir\n");
					scanf("%d",&opcion3);
					switch(opcion3){
						system("cls");
						case 1:
							printf("Aparece su menu semanal\n");
							break;
							
						case 2:
							printf("Aparece su menu mensual\n");
							break;
							
						case 3:
							printf("Aparece su menu del proximo mes\n");
							break;
						case 4:
							break;
						case 5:
							return 0;
				
					}
					if(opcion3!=4){
						printf("Pulse una tecla para volver al menu\n");
						system("pause");	
					}
				break;	
	
										
				case 2:
					system("cls");
					printf("Seleccione una de las siguientes opciones:\n");
					printf("\t\t1-Ofrecer una nueva alternativa\n");
					printf("\t\t2-Cambiar manualmente\n");
					printf("\t\t3-Ajustes de preferencias\n");
					printf("\t\t4-Volver al menu principal\n");
					printf("\t\t5-Salir\n");
					scanf("%d",&opcion3);
					switch(opcion3){
						case 1:
							printf("Plantea una alternativa.\nSe le pregunta si quiere realizar el cambio\n");
							break;
							
						case 2:
							printf("Se le pide el dia que cambiar y se le pregunta si quiere cambiarlo\n");
							break;
							
						case 3:
							printf("Se ajusta el menu a una serie de parametros, como kcal o no coger alimentos que no gustan\n");
							break;
						case 4:
							continue;
						case 5:
							return 0;	
					}
					if(opcion3!=4){
						printf("Pulse una tecla para volver al menu\n");
						system("pause");	
					}
				break;		
					
				case 3: 
					system("cls");
					printf("\t\tBienvenido a recetario ARGUISANOS");
					printf("Introduzca la opcion deseada:");
					printf("\t\t1-Ver mis recetas\n");
					printf("\t\t2-Ver recetas del sistema\n");
					printf("\t\t3-Anadir receta\n");
					printf("\t\t4-Modificar receta\n");
					printf("\t\t5-Volver al menu principal\n");
					printf("\t\t6-Salir\n");
					scanf("%d",&opcion3);
					switch(opcion3){
						case 1:
							printf("Te muestra una lista de recetas y tu decides cual quieres ver\n");
							break;
							
						case 2:
							printf("Te muestra una lista de recetas y tu decides cual quieres ver\n");
							break;
							
						case 3:
							printf("Anades una lista nueva de recetas, indica quien la ha subido\n");
							break;
						case 4: 
							printf("Modificas una nueva receta\n Al resto de usuarios se le preguntara al iniciar sesion si quieren guardarla\n");
							break;
						case 5:
							continue;
						case 6:
							return 0;	
					}
				break;
					
				case 4:
					printf("Si desea volver a su sesion pulse espacio, en caso contrario pulse cualquier otra tecla\n");
					scanf("%c",&pulse_continuar);
					fflush(stdin);
					if(pulse_continuar==' ')
						break;
					else
						opcion2=1;
					
				case 5:
					return 0;
			}
		}while(opcion2!=1&&opcion2!=2&&opcion2!=3);
	}
	while(opcion2==4); //Cuando cierras sesion vuelve al principio
}
