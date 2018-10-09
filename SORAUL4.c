#include <stdio.h>
#include <stdlib.h>

char comando [1000];
char *dir = "";

void menu();
void numArch();
void numSubDic();
void fichGrande();
void fichPeque();
void diskUsed();
void numFichLec();
void numFichEsc();
void numFichEjec();
void numFichEjecTodos();


int main(int argc, char *argv[]){
	if(argc ==0)
		dir = ".";

	else if(argc == 1){
		dir = argv[1];
	}
	else{
		exit(-1);
	}

	menu();
}

void menu(){
	int num = 0;
	int opcion = 0;

	//scanf("%d", &opcion); 

	do{
		printf("\n==============OPCIONES==================\n\n");
		printf("\n1)Numero de archivos\n");
		printf("\n2)Numero de subdirectorios\n");
		printf("\n3)Ficheros mas grande\n");
		printf("\n4)Fichero mas pequeño\n");
		printf("\n5)Espacio total ocupado\n");
		printf("\n6)Numero de ficheros con permiso de lectura para el usuario que ejecuta\n");
		printf("\n7)Numero de ficheros con permiso de escritura para el ususario que lo ejecuta\n");
		printf("\n8)Numero de ficheros con permiso de ejecucion para el usuario que ejecuta\n");
		printf("\n9)Ficheros con permiso de ejecucion para todos los usuarios\n");
		printf("\nSalir\n");
		printf("\n========================================\n\n");

		printf("\nIntroduce una opcion: ");
		scanf("%d", &opcion); 

		switch(opcion){
			case 1: printf("\nNumero de archivos en el directorio\n");
					numArch();

				break;
			case 2: printf("\nNumero de subdirectorios\n");
					numSubDic();
				break;
			case 3: printf("\nFichero mas grande:\n");
					fichGrande();
				break;
			case 4: printf("\nFichero mas pequeño\n");
					fichPeque();
				break;
			case 5: printf("\nEspacio total ocupado\n");
					diskUsed();
				break;
			case 6: printf("\nPermiso lectura para el usuario\n");
					numFichLec();
				break;
			case 7: printf("\nPermiso escritura para el usario\n");
					numFichEsc();
				break;
			case 8: printf("\nPermiso ejecucion para el usario\n");
					numFichEjec();
				break;
			case 9: printf("\nPermiso ejecucion para todos los usuarios\n");
					numFichEjecTodos();
				break;
			case 10: printf("\nSaliendo del programa\n");
					exit(-1);
			break;
			default: printf("\nNumero Incorrecto\n");

		}

	}while(opcion != 10);
}


void numArch(){
	sprintf(comando, "ls | wc -l", dir);
	int i = system(comando);
}

void numSubDic(){
	sprintf(comando, "ls -l | grep ^d | wc -l", dir);
	int i = system(comando);
}

void fichGrande(){
	sprintf(comando, "du -sm * | sort -nr | head -1 | cut -f2", dir);
	int i = system(comando);
}

void fichPeque(){
	sprintf(comando, "du -sm * | sort -n | head -1 | cut -f2", dir);
	int i = system(comando);
}

void diskUsed(){
	sprintf(comando, "du -sh | cut -f1", dir);
	int i = system(comando);
}

void numFichLec(){
	sprintf(comando, "ls -l | grep '^-r' |wc -l", dir);
	int i = system(comando);
}

void numFichEsc(){
	sprintf(comando, "ls -l | grep '^-.w' |wc -l", dir);
	int i = system(comando);
}

void numFichEjec(){
	sprintf(comando, "ls -l | grep '^-..x' |wc -l", dir);
	int i = system(comando);
}

void numFichEjecTodos(){
	sprintf(comando, "ls -l | grep '^-..x..x..x' |wc -l", dir);
	int i = system(comando);
}




















