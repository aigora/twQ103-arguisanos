#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MaxUsuarios 10
#define Ncaracteres 30
#define porcentajeVitaminas 35
#define porcentajeHidratos 40
#define porcentajeProteinas 25
#define porcentajeConsideracion1 66.7
#define porcentajeConsideracion2 33.3
#define promedioKcal_100 125
#define errorKcal_100 40.0
#define errorEstimacion 15.0
#define masaPlato1 350
#define masaPlato2 300
#define masaPlato3 450
struct Tcuentas{
	char usuario[100];
	char clave[100];
};
struct Platos{
	char nombrePlato[50];
	float kcal;
	char consideracion;
	char consideracion2;
	int tipoplato;
};

void menu_nivel_1();
void menu_nivel_2();
void menu_nivel_3(char opcion_2);
void banner_inicio(char identificador[]);
int iniciarSesion(struct Tcuentas cargarCuentas[], char usuario[]);
int salida(char opcion);
int cargarFicheros();
int registrarUsuario();
int recetario();
int calculadoraKcal(float kcal[],char letra, int porcentaje, int masa, float kcal_100);
int comprobador(float kcal[]);
int menu(struct Platos memoriaplatos[],int vectorMenu[],int numero);
int ficheroPlatos(struct Platos memoriaplatos[]);
void impresionMenu(struct Platos memoriaplatos[]);

int main(){
	
	int i=0, j=0, contador=0, verificador=1, recetas,intentos=0;
	char opcion,opcion_2,pulse_continuar, usuario[20], clave[20],cadena[20], verificar_clave[20];
	char*ctime(const time_t *timer);
	struct Platos memoriaplatos[200];
	struct Tcuentas cargarCuentas[MaxUsuarios];

	do{
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
				if(	iniciarSesion(cargarCuentas,usuario)==-1)
				return -1;
				
				else{
					system("cls");
					banner_inicio("usuario");
					printf("%s\n\n\n", usuario);
					time_t curtime;
					time(&curtime);
					strcpy(cadena,ctime(&curtime));
					printf("\t\t\t\t\t%s\n", cadena);
					
					do{
						
						impresionMenu(memoriaplatos);
						menu_nivel_2();
						intentos=0;
						do{
						if(intentos>0){
							printf("Error en la introduccion de opciones.Pruebe de nuevo\n");
						}
						scanf("%c",&opcion_2);
						fflush(stdin);
						intentos++;
						system("cls");
						}while(opcion_2!='r'&&opcion_2!='s'&&opcion_2!='c'&&intentos<3);
						if(opcion_2=='r'){
							break;
						}
						else if(opcion_2=='s'){
							return 0;
						}
						else if(intentos==3){
							return -1;
						}
						
					}while(opcion_2=='c');
				}
				
			break;	
			case '2':
				registrarUsuario();
				system("cls");
			break;
		
			case '3':
				
				recetas=recetario();
				if(recetas==-1)
					return -1;
						
			break;
				
	  		case 's':
	  			return 0;
				
			}
}while(opcion!='s');

}


void banner_inicio(char identificador[]){
	char codigo[20]="inicio";
	if (strcmp(identificador,"inicio")==0){
		printf("\n\t\tBienvenido a ARGUISANOS\n\n");
		}
	else if(strcmp(identificador,"usuario")==0){
		printf("\n\tBienvenid@ a ARGUISANOS ");
		return;
		}
	else if(strcmp(identificador,"usuario2")==0){
		printf("\n\n");
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
void menu_nivel_2(){
	printf("\n\n\t\t-Si desea cargar de nuevo un menu introduzca c\n");
	printf("\t\t-Si desea volver al menu de inicio pulse r\n");
	printf("\t\t-Para salir pulse s\n");	
}

void menu_nivel_3(char opcion_2){
	char cadena[Ncaracteres];
	if(opcion_2=='1'||opcion_2=='2'){
		if(opcion_2=='1')
			strcpy(cadena,"la proxima semana");
		if(opcion_2=='2')
			strcpy(cadena,"el proximo mes");
	
		printf("-Si desea modificar una fecha introduzca: modificar\n");
		printf("-Si desea ver %s introduzca: siguiente\n",cadena);
		
	}
	else if(opcion_2=='3'){
	printf("\tIntroduzca la opcion deseada:\n\n");
	printf("\t\t1-Distribucion de platos\n");
	printf("\t\t2-Eliminar plato\n");
	printf("\t\t3-Alergias\n");
	printf("\t\ts-Restricciones de calendario\n");
	}
	
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
	if(n>=MaxUsuarios-1){
		printf("Se ha superado el limite de usuarios registrados. Elimine alguno o revise el codigo\n");
		system("pause");
		return -1;
	}
	
	do{
		do{
			printf("Introduzca usuario:\n");
			fflush(stdin);
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
				system("cls");
				banner_inicio("null");
				printf("Este usuario, sin tener en cuenta mayusculas y minusculas, ya existe\nIntente crear otro nuevo o dirijase a iniciar sesion\n\n");
			}
		}while(validar==0);
		printf("Introduzca su clave:\n");

		gets(cuentas[n].clave);
		printf("-Si desea guardar pulse g\n-Para salir y no guardar pulse s\n-Pulse otra tecla para introducir otro usuario\n");
		
		scanf("%c",&opcion);
	
		if (opcion=='g'){
			fichero=fopen("cuentas.txt","w");
			if (fichero == NULL){
				printf("Error en la apertura de fichero. Compruebe que tiene todos los ficheros en la carpeta del programa\n");
				return -1;
			}
			for(i=0;i<=n;i++)
				fprintf(fichero,"%s\t%s\n",cuentas[i].usuario,cuentas[i].clave);
			fclose(fichero); 

			return 0;	
		}
		else if(opcion=='s')
			return 0;
			
		n++;
	}while(opcion!='s'&&n<MaxUsuarios);
	if(n==MaxUsuarios)
		printf("Ha sobrepasado el limite de registros. Modifique la configuracion para poder introducir mas usuarios\n");

}


iniciarSesion(struct Tcuentas cargarCuentas[],char usuario[]){

	int j, h, i=0, intentos=0, intentosUsuario=0, validar=0;
	char usuarioMayus[Ncaracteres], usuarioCuentasMayus[Ncaracteres];
	char clave[20];
	
	FILE*fichero2;
	fichero2=fopen("cuentas.txt","r");
	if (fichero2 == NULL){
		printf("Error en la apertura de fichero");
		return -1;
	}
		while(fscanf(fichero2,"%s %s",cargarCuentas[i].usuario,cargarCuentas[i].clave)!=EOF){
		i++;
	fclose(fichero2);
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
					return -1;
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
		return -1;
	}
}
int recetario(){
	float valor;
	char excluir[35];
	int i=0, j=0, intentos=0,numero;
	char opcion[20],op, letra, plato[50], platoMayus[50], comparaplato[50];
	struct Platos memoriaplatos[200];
	int numerolineas=0;
	FILE *puntero;
	char cadenaleida[200];
	char *ptrToken;

	
	puntero=fopen("platos.csv","a+");
	
	if (puntero==NULL)
	{
		printf("No es posible abrir el fichero\n %i",puntero);
		return -1;
	}
	

	while (fgets(cadenaleida,200,puntero)!=NULL)
	{
		ptrToken = strtok(cadenaleida,";");
		j=0;
		while (ptrToken != NULL)
		{
			switch (j)
			{
				case 0: 
					strcpy(memoriaplatos[i].nombrePlato,ptrToken);
					break;
				case 1:
					memoriaplatos[i].kcal=atoi(ptrToken);
					break;
				case 2:
					memoriaplatos[i].consideracion=*ptrToken;
					break;
				case 3:
					memoriaplatos[i].consideracion2=*ptrToken;
					break;
				case 4:
					memoriaplatos[i].tipoplato=atoi(ptrToken);
					break;
			}
			ptrToken=strtok(NULL,";");
			j++;
		}
		numerolineas++;
		i++;
	}

	fclose(puntero);


	intentos=0;
	do{
		
		if(intentos>0)
			printf("La opcion introducida no es correcta, compruebe que ha seleccionado correctamente una de las opciones\n");
			
		for(i=0;i<numerolineas;i++){	
			printf(" %d-%s\n",i+1,memoriaplatos[i].nombrePlato,memoriaplatos[i].kcal);
		}
		printf("\n\t-Si desea consultar una receta introduzca: consultar\n\t-Si desea incluir una nueva receta introduzca: incluir\n\t-Si desea eliminar una receta introduzca: eliminar\n\t-Para salir pulse s\n");

		
		gets(opcion);
		_strupr(opcion);

		if(strcmp(opcion,"CONSULTAR")==0)
			op='1';
		if(strcmp(opcion,"INCLUIR")==0)
			op='2';
		if(strcmp(opcion,"ELIMINAR")==0)
			op='3';		
		if(strcmp(opcion,"S")==0)
			op='s';
			
		intentos++;

	}while(op!='1'&&op!='2'&&op!='3'&&op!='s'&&intentos<3);
	
		if(intentos==3){
			printf("Demasiados intentos, intentelo mas tarde\n");
			return -1;
		}

		switch(op){
			case '1':
				system("cls");
				banner_inicio("NULL");
				printf("Introduzca el numero de receta\n");
				scanf("%d", &numero);
				
			break;
			
			case '2':
				system("cls");
				banner_inicio("NULL");
				printf("A continuacion puede introducir un nuevo plato, pero recuerde, necesita conocer su aporte calorico\n\n");
				printf("Si desea cancelar y salir pulse s, para continuar pulse otra tecla\n");
				scanf("%c", &letra);
				fflush(stdin);
				if(letra=='s'||letra=='S'){
					return 0;
				}
				
				printf("Introduzca el nombre del plato que desea registrar\n");
				gets(plato);
				strcpy(platoMayus,plato);
				_strupr(platoMayus);
				for (i=0;i<numerolineas;i++){
					strcpy(comparaplato,memoriaplatos[i].nombrePlato);
					_strupr(comparaplato);
					if(strcmp(comparaplato,platoMayus)==0){
						printf("No se introdujo el plato porque ya existe, eliminelo antes de escribirlo de nuevo\n");
						return -1;
					}
				}
				strcpy(memoriaplatos[numerolineas].nombrePlato,plato);
				
				
				printf("Introduzca la cantidad de Kcal por 100g\n");
				scanf("%f",&valor);
				printf("Introduzca:\nh-El aporte principal es de hidratos de carbono y grasas\nv-El aporte es vitaminico\np-Aporta proteinas\n");
				intentos=0;
				do{
					if(intentos>0)
						printf("La opcion introducida no es correcta, compruebe que ha seleccionado correctamente una de las opciones\n");
					fflush(stdin);	
					scanf("%c",&letra);
			
					if(letra<='z'&&letra>='a')
						letra+='A'-'a';
			
					intentos++;
				}while(letra!='H'&&letra!='V'&&letra!='P'&&intentos<3);
				if(intentos==3){
					printf("Demasiados intentos, intentelo mas tarde\n");
					return -1;
				}
				memoriaplatos[numerolineas].kcal=valor;
				memoriaplatos[numerolineas].consideracion=letra;
				printf("Repita la operacion anterior indicando el nutriente secundario, de no haberlo pulse el mismo que en la opcion anterior\n");
				intentos=0;
				do{
					if(intentos>0)
						printf("La opcion introducida no es correcta, compruebe que ha seleccionado correctamente una de las opciones\n");
					fflush(stdin);	
					scanf("%c",&letra);
				
					if(letra<='z'&&letra>='a')
						letra=letra+'A'-'a';
			
					intentos++;
				}while(letra!='H'&&letra!='V'&&letra!='P'&&intentos<3);
				if(intentos==3){
					printf("Demasiados intentos, intentelo mas tarde\n");
					return -1;
				}
				memoriaplatos[numerolineas].consideracion2=letra;
				
				printf("Introduzca 1 si su plato es un plato principal, 2 si es un segundo plato\n");
				intentos=0;
				do{
					if(intentos>0)
						printf("La opcion introducida no es correcta, compruebe que ha seleccionado correctamente una de las opciones\n");
						
					scanf("%d",&numero);	
					intentos++;
				}while(numero!=1 &&numero!=2 &&intentos<3);
				if(intentos==3){
					printf("Demasiados intentos, intentelo mas tarde\n");
					return -1 ;
				}
				memoriaplatos[numerolineas].tipoplato=numero;
				
				printf("Recuerde que los calculos se hacen a partir del aporte calorico introducido.\nSi esta de acuerdo con los datos pulse g para guardar\n");
				fflush(stdin);
				scanf("%c",&letra);
			
				if(letra!='g'&&letra!='G'){
					return 0;
				}
				puntero=fopen("platos.csv","a+");
				fprintf(puntero,"%s;%f;%c;%c;%i\n",memoriaplatos[numerolineas].nombrePlato,memoriaplatos[numerolineas].kcal,memoriaplatos[numerolineas].consideracion,memoriaplatos[numerolineas].consideracion2,memoriaplatos[numerolineas].tipoplato);
				numerolineas++;
				fclose(puntero);
			break;
				
			case '3':
	
				numero=0;
				intentos=0;
				printf("Introduzca el numero del plato que desea eliminar de la lista\n");
				do{
					if(intentos>0)
						printf("La opcion introducida no es correcta, compruebe que ha seleccionado correctamente una de las opciones\n");
						
				scanf("%d",&numero);	
				numero-=1;
				intentos++;
				}while((numero<1||numero>=numerolineas)&&intentos<3);
				if(intentos==3){
					printf("Demasiados intentos, intentelo mas tarde\n");
					return -1;
				}
				printf("¿Esta seguro de que desea eliminar el plato '%s'? Esto puede afectar al resto de usuarios\n",memoriaplatos[numero].nombrePlato);
				printf("-Si desea eliminar el plato de sus preferencias inicie sesion y vaya a preferencias\n");
				printf("-Si desea eliminar el plato para siempre pulse g para salir y guardar los cambios\n-Pulse s si desea salir sin guardar\n");
				intentos=0;
				do{
					if(intentos>0)
						printf("La opcion introducida no es correcta, compruebe que ha seleccionado correctamente una de las opciones\n");
					fflush(stdin);	
					scanf("%c",&letra);
				
					if(letra<='z'&&letra>='a')
						letra=letra+'A'-'a';
					intentos++;
				}while(letra!='G' &&letra!='S' &&intentos<3);
				
				if(letra=='S'||intentos==3)
				return 0;
			
				else{
					for(j=numero;j<=numerolineas-1;j++){
						strcpy(memoriaplatos[j].nombrePlato,memoriaplatos[j+1].nombrePlato);
						memoriaplatos[j].kcal=memoriaplatos[j+1].kcal;
						memoriaplatos[j].consideracion=memoriaplatos[j+1].consideracion;
						memoriaplatos[j].consideracion2=memoriaplatos[j+1].consideracion2;
						memoriaplatos[j].tipoplato=memoriaplatos[j+1].tipoplato;
					}
					numerolineas=numerolineas-1;
					for(i=0;i<numerolineas;i++){
						printf(" %d-%s\n",i+1,memoriaplatos[i].nombrePlato);
					}
					puntero=fopen("platos.csv","w");
					for(i=0;i<numerolineas;i++){
						fprintf(puntero,"%s;%f;%c;%c;%i\n",memoriaplatos[i].nombrePlato,memoriaplatos[i].kcal,memoriaplatos[i].consideracion,memoriaplatos[i].consideracion2,memoriaplatos[i].tipoplato);
					}
					fclose(puntero);
				}
	}

}

int comprobador(float kcal[]){
	float masa, promedioVitaminas,errorVitaminas,promedioHidratos,errorHidratos,promedioProteinas,errorProteinas;
	int caloriasAceptadas=0;
	masa=masaPlato1+masaPlato2+masaPlato2;
    promedioVitaminas=masa/100*porcentajeVitaminas/100*promedioKcal_100;
    errorVitaminas=(errorEstimacion/100+errorKcal_100/promedioKcal_100)*promedioVitaminas;
    
    promedioHidratos=masa/100*porcentajeHidratos/100*promedioKcal_100;
    errorHidratos=(errorEstimacion/100+errorKcal_100/promedioKcal_100)*promedioHidratos;
    
    promedioProteinas=masa/100*porcentajeProteinas/100*promedioKcal_100;
    errorProteinas=(errorEstimacion/100+errorKcal_100/promedioKcal_100)*promedioHidratos;

	if(promedioVitaminas+errorVitaminas>kcal[0]&&kcal[0]>promedioVitaminas-errorVitaminas){
    		caloriasAceptadas++;
	}
    		
	if(promedioHidratos+errorHidratos>kcal[1]&&kcal[1]>promedioHidratos-errorHidratos){
		caloriasAceptadas++;
	}
	if(promedioProteinas+errorProteinas>kcal[2]&&kcal[2]>promedioProteinas-errorProteinas){
		caloriasAceptadas++;
	}
	
	return caloriasAceptadas;
}
int menu(struct Platos memoriaplatos[],int vectorMenu[],int numero){
 
	int numerolineas=0,i=0,j=0,n, h, primerPlato, segundoPlato, tercerPlato, porcentaje, masa, caloriasAceptadas;
	int random, random_2, random_3;
	int vectorPrimeros[50], vectorSegundos[50], vectorRandom[30];
	float kcal_100, kcalVitaminas,kcalHidratos,kcalProteinas;
	
	float kcal_plato_1[3]={0,0,0}, kcal_plato_2[3]={0,0,0}, kcal_plato_3[3]={0,0,0}, kcal[3]={0,0,0};	
	char letra;
	char cadenaleida[200];
	char *ptrToken;
	FILE *puntero;
	FILE *fichero;
	numerolineas=ficheroPlatos(memoriaplatos);
	n=0;
	j=0;
	for (i=0;i<numerolineas;i++){
		if(memoriaplatos[i].tipoplato==1){
			vectorPrimeros[n]=i;
			n++;
		}
		else{
			vectorSegundos[j]=i;
			j++;
		}
	}
   	srand(time(NULL)+numero); 
	random = rand() % n;
	primerPlato=vectorPrimeros[random];
    letra=memoriaplatos[primerPlato].consideracion;
    porcentaje=1;
    masa=1;
    kcal_100=memoriaplatos[primerPlato].kcal;
    calculadoraKcal(kcal_plato_1,letra, porcentaje, masa, kcal_100);

    letra=memoriaplatos[primerPlato].consideracion2;
    porcentaje=2;
    masa=1;
    kcal_100=memoriaplatos[primerPlato].kcal;
    calculadoraKcal(kcal_plato_1,letra, porcentaje, masa, kcal_100);
	   
	i=0;
	
	do{
		random_2 = (rand()+2*random) % j;
		do{ 
			random_3=(random+rand())% j;	
		}while (random_3==random_2);
		
	    kcal[0]=0; 	
	    kcal[1]=0; 	
	    kcal[2]=0;
	    kcal_plato_2[0]=0; 	
	    kcal_plato_2[1]=0; 
	    kcal_plato_2[2]=0;
		kcal_plato_3[0]=0; 	
	    kcal_plato_3[1]=0; 
	    kcal_plato_3[2]=0; 
		caloriasAceptadas=0;
		
		segundoPlato=vectorSegundos[random_2];
	    letra=memoriaplatos[segundoPlato].consideracion;
		porcentaje=1;
		masa=2;
		kcal_100=memoriaplatos[segundoPlato].kcal;
		calculadoraKcal(kcal_plato_2,letra, porcentaje, masa, kcal_100);
	
		    
		letra=memoriaplatos[segundoPlato].consideracion2;
	    porcentaje=2;
	    masa=2;

	    calculadoraKcal(kcal_plato_2,letra, porcentaje, masa, kcal_100);
	
    	tercerPlato=vectorSegundos[random_3];
	    letra=memoriaplatos[tercerPlato].consideracion;
	    porcentaje=1;
	    masa=3;
	    kcal_100=memoriaplatos[tercerPlato].kcal;
	    calculadoraKcal(kcal_plato_3,letra, porcentaje, masa, kcal_100);
		
	    letra=memoriaplatos[tercerPlato].consideracion2;
	    porcentaje=2;
	    masa=3;
	    calculadoraKcal(kcal_plato_3,letra, porcentaje, masa, kcal_100);
	    
	    
	    
		    
	    kcal[0]=kcal_plato_3[0]+kcal_plato_2[0]+kcal_plato_1[0]; 	//Vitaminas
	    kcal[1]=kcal_plato_3[1]+kcal_plato_2[1]+kcal_plato_1[1]; 	//Hidratos
	    kcal[2]=kcal_plato_3[2]+kcal_plato_2[2]+kcal_plato_1[2];	//Proteinas
	    	
	
	    caloriasAceptadas=comprobador(kcal);
	    i++;	
	}while (caloriasAceptadas<3||i==30);
	
    for (i=0;i<3;i++)
    vectorMenu[0]=primerPlato;
	vectorMenu[1]=segundoPlato;
	vectorMenu[2]=tercerPlato;
}
int calculadoraKcal(float kcalEntrada[],char letra, int porcentaje, int masa, float kcal_100){

  	float consideracionPorcentaje, consideracionMasa;
  	
  	if(porcentaje==1){
  		consideracionPorcentaje=porcentajeConsideracion1;
	}
	else if(porcentaje==2){
  		consideracionPorcentaje=porcentajeConsideracion2;
	}
	else{
	  	printf("El porcentaje introducido no es valido\n");
	  	return -1;
	}
  	
  	if(masa==1){
  		consideracionMasa=masaPlato1;
	}
	else if(masa==2){
  		consideracionMasa=masaPlato2;
	}
	else if(masa==3){
  		consideracionMasa=masaPlato3;
	}
	else{
	  	printf("El peso introducido no es valido\n");
	  	return -1;
	}
	
  	if(letra=='V'){
  		kcalEntrada[0]=consideracionMasa/100*kcal_100*consideracionPorcentaje/100;
	  }
	else if(letra=='H'){
  		kcalEntrada[1]=consideracionMasa/100*kcal_100*consideracionPorcentaje/100;
	  }
	else if(letra=='P'){
  		kcalEntrada[2]=consideracionMasa/100*kcal_100*consideracionPorcentaje/100;
	  }
	else{
		printf("Ha habido un error en la lectura de tipo de platos del fichero platos.csv. Reviselo y vuelva a abrir el programa\n");
		return -1;
	}
	return 0;
  }
  int ficheroPlatos(struct Platos memoriaplatos[]){
	char cadenaleida[200];
	char *ptrToken;
	FILE *puntero;
	FILE *fichero;
	int i=0, j=0,numerolineas=0,vectorCompruebaPlatos[3],platos[7][3];
	puntero=fopen("platos.csv","a+");
	
	if (puntero==NULL){
		printf("No es posible abrir el fichero\n %i",puntero);
		return -1;
	}
	
	while (fgets(cadenaleida,200,puntero)!=NULL){
		ptrToken = strtok(cadenaleida,";");
		j=0;
		struct Platos copiaplatos[100];
		while (ptrToken != NULL){
			switch (j){
				case 0: 
					strcpy(memoriaplatos[i].nombrePlato,ptrToken);
					break;
				case 1:
					memoriaplatos[i].kcal=atoi(ptrToken);
					break;
				case 2:
					memoriaplatos[i].consideracion=*ptrToken;
					break;
				case 3:
					memoriaplatos[i].consideracion2=*ptrToken;
					break;
				case 4:
					memoriaplatos[i].tipoplato=atoi(ptrToken);
					break;
			}
			ptrToken=strtok(NULL,";");
			j++;
		}
		numerolineas++;
		i++;
	}
	fclose(puntero);
	return numerolineas;
}
void impresionMenu(struct Platos memoriaplatos[]){
	char dias[7]={'L','M','X','J','V','S','D'};
	int q=0, n=0, i,h,j,error, platos[7][3];

	for(i=0;i<7;i++){
		do{
			menu(memoriaplatos,platos[i],i+n);
			for(h=0;h<i;h++){
				for(j=0;j<3;j++){
					if(platos[i][j]==platos[h][j]){
						error=-1;
						break;
					}
					n++;
					}
					if(error==-1){
						break;
				}
			
			}
			q++;
		}while(error==-1&&q<30);
		
		
	}

	printf("\n______________________________________________________________________________________________________________________\n");	
	for(j=0;j<7;j++){
		for(h=0;h<7;h++)
		printf(" ");
		
		printf("%c",dias[j]);
	for(h=8;h<14;h++)
		printf(" ");	
		printf(" | ");
	}
	printf("\n______________________________________________________________________________________________________________________\n");
	printf("\t\t\t\t\t\t    C O M I D A\n______________________________________________________________________________________________________________________\n");
	for(i=0;i<3;i++){
			
		for(j=0;j<7;j++){
			
			for(h=0;h<14;h++)
			printf("%c",memoriaplatos[platos[j][i]].nombrePlato[h]);
			printf(" | ");
		}
		printf("\n");
		for(j=0;j<7;j++){
			for(h=14;h<28;h++)
			printf("%c",memoriaplatos[platos[j][i]].nombrePlato[h]);
			printf(" | ");
		}
		printf("\n______________________________________________________________________________________________________________________\n");
		if(i==1)
			printf("\t\t\t\t\t\t      C E N A\n______________________________________________________________________________________________________________________\n");
	}

}
