#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxUsuarios 8
#define Ncaracteres 30
struct Tcuentas{
	char usuario[100];
	char clave[100];
};


void menu_nivel_1();
void banner_inicio(char identificador[]);
int salida(char opcion);
int cargarFicheros();
int registrarUsuario();
int iniciarSesion();

int main(){
	
	int i=0, j=0, contador=0, verificador=1;
	char opcion,pulse_continuar, usuario[20], clave[20], verificar_clave[20];
	
	cargarFicheros();
	banner_inicio("inicio");
	menu_nivel_1();
	do{
		if(i>0)
			printf("\tPor favor, seleccione una de las opciones en pantalla\n");
			
		scanf("%c",&opcion);
		fflush(stdin);

		i++;		
	}while(opcion!='1'&&opcion!='2'&&opcion!='3'&&opcion!='s');
		
		system("cls");
		banner_inicio("null");	
		switch(opcion){
			case '1': 
				if(iniciarSesion()==-2)
				break;
				
				/*else{
					switch(opcion_2){
						
					}
				}*/	
			case '2':
				registrarUsuario();
			break;
		
			case '3':
				//abrirRecetario();
					printf("\n\tRecetario ARGUISANOS\n");
					printf("Imprimira las opciones de recetas\n");
					system("pause");
					break;
				
	  		case 'r':
	  			break;
	  		case 's':
	  			return 0;
				
			}
			i++;
			system("cls");
		}


void banner_inicio(char identificador[]){
	char codigo[20]="inicio";
	if (strcmp(identificador,"inicio")==0){
		printf("\n\t\tBienvenido a ARGUISANOS\n\n");
		}
	else{
		printf("\n\t\t\tARGUISANOS\n\n");
	}
	printf("\tAsesor y planificador de menus y recetas\n\t");
	printf("________________________________________\n\n");

}
void menu_nivel_1(){
	printf("\tIntroduzca la opcion deseada:\n\n");
	printf("\t\t1-Iniciar sesion\n");
	printf("\t\t2-Crear cuenta nueva\n");
	printf("\t\t3-Recetario ARGUISANOS\n");
	printf("\t\ts-Salir\n");
}

int cargarFicheros(){
	
}


int registrarUsuario(){
	struct Tcuentas cuentas[MaxUsuarios];
	int i=0,n=0, validar;
	char opcion, usuarioMayus[Ncaracteres], usuarioCuentasMayus[Ncaracteres];
	FILE*fichero;
	fichero=fopen("cuentas.txt","r") ;
	if (fichero == NULL){
		printf("Error en la apertura de fichero. Compruebe que tiene todos los ficheros en la carpeta del programa\n");
		return -1;
	}
	while(fscanf(fichero,"%s %s", cuentas[n].usuario,cuentas[n].clave)!=EOF){
		n++;
	}
	
	fclose(fichero);
	
	do{
		do{
			printf("Introduzca usuario:\n");
			gets(cuentas[n].usuario);
			strcpy(usuarioMayus,cuentas[n].usuario);
			_strupr(usuarioMayus);
			validar=1;
			for(i=0;i<n;i++){
				strcpy(usuarioCuentasMayus,cuentas[i].usuario);
				_strupr(usuarioCuentasMayus);
				if(strcmp(usuarioCuentasMayus,usuarioMayus)==0)
					validar=0;
			}
			if(validar==0){
				banner_inicio("null");
				printf("Este usuario, sin tener en cuenta mayusculas y minusculas, ya existe\nIntente crear otro nuevo o dirijase a iniciar sesion\n\n");
			}
		}while(validar==0);
		printf("Introduzca su clave:\n");
		gets(cuentas[n].clave);
		printf("-Si desea guardar pulse c\n-Para salir y no guardar pulse s\n-Pulse otra tecla para introducir otro usuario\n");
		scanf("%c",&opcion);
		fflush(stdin);
		switch(opcion){
			case 'c':
			fichero=fopen("cuentas.txt","w");
			if (fichero == NULL){
				printf("Error en la apertura de fichero. Compruebe que tiene todos los ficheros en la carpeta del programa\n");
			return -1;
			}
			for(i=0;i<=n;i++)
				fprintf(fichero,"%s\t%s\n",cuentas[i].usuario,cuentas[i].clave);
			fclose(fichero); 

			return 0;	
			case 's':
				return 0;
		}
		n++;
	}while(opcion!='s'&&n<MaxUsuarios);
	if(n==MaxUsuarios)
		printf("Ha sobrepasado el limite de registros. Modifique la configuracion para poder introducir mas usuarios\n");

}


int iniciarSesion(){
struct Tcuentas cargarCuentas[MaxUsuarios];
	int j, h, i=0, intentos=0, intentosUsuario=0, validar=0;
	char usuario[20], usuarioMayus[Ncaracteres], usuarioCuentasMayus[Ncaracteres];
	char clave[20];
	
	FILE*fichero;
	fichero=fopen("cuentas.txt","r");
	if (fichero == NULL){
		printf("Error en la apertura de fichero");
		return -1;
	}
		while(fscanf(fichero,"%s %s",cargarCuentas[i].usuario,cargarCuentas[i].clave)!=EOF){
		i++;
	fclose(fichero);
	}
	do{		
		printf("Introduzca usuario:\n");
		gets(usuario);		
		strcpy(usuarioMayus,usuario);
		_strupr(usuarioMayus);
	
		for (j=0;j<=i;j++){
			strcpy(usuarioCuentasMayus,cargarCuentas[j].usuario);
			_strupr(usuarioCuentasMayus);
			
			if(strcmp(usuario,cargarCuentas[j].usuario)==0){
				do{
					printf("Contrasena:\n");
					gets(clave);
					if(strcmp(clave,cargarCuentas[j].clave)==0){
						printf("El usuario y contrasena son correctas\n");
						validar=1;
						}
					else{
						system("cls");
						banner_inicio("null");
						printf("Error en la validacion de su contasena\n");
					}
					
					intentos++;
				}while(intentos<3&&validar!=1);
				
				if(intentos==3){
					printf("\nIntentelo de nuevo mas tarde\n");
					return -2;
				}
			break;
			}
				
			else if(strcmp(usuarioMayus, usuarioCuentasMayus)==0){
				system("cls");
				banner_inicio("null");
				printf("Ha habido un error en la introduccion de usuario\nCompruebe mayusculas\n\n");
			}
		
		}
		intentosUsuario++;
	}while(validar!=1&&intentosUsuario<3);
	
	if(intentosUsuario==3){
		printf("\nIntentelo de nuevo mas tarde\n");
		return -2;
	}
}
