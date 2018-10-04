#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "parcial.h"
#include "ctype.h"





/*int pedirIndiceVacio(char* pArray, int len, int * indice)
{
    int retorno = -1;
     for (int i = 0; i <= len; i++)
     {
       if (pArray[i].flag == 0)
       {
         *indice = i;
         retorno = 0;
         break;
       }
     }
     printf("Indice vacio %d\n", *indice);

     return retorno;
}*//**/

int inicializarArray(char* pBuffer,int limite)
{
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i]=1;
    }
    return 0;
}
/*
int existeID(char* pBuffer,int limite,int ID)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].id==ID&&pBuffer[i].isEmpty==0){
            retorno=0;
        }
    }
    return retorno;

}*/

/*int ingresoForzado(Pantalla* pBuffer,int limite,char* nombre,char*direccion,char* tipo,float precio)
{
    int aux;
    buscarIndiceVacio(pBuffer,limite,&aux);
    strncpy(pBuffer[aux].nombre,nombre);
    strncpy(pBuffer[aux].tipo,tipo);
    strncpy(pBuffer[aux].direccion,direccion,);
    pBuffer[aux].ID=obtenerID();
    pBuffer[aux].isEmpty=0;
    pBuffer[aux].precio=precio;
    return 0;
}*/
int pan_obtenerID()
{
    static int ID=0;
    return ID++;

}
/*
int busquedaPorID(Pantalla* pBuffer,int limite,int ID,int* indiceID)
{
    int i;
    int retorno=-1;
    for (i=0;i<limite;i++){
        if(pBuffer[i].id.ID==ID&& pBuffer[i].isEmpty==0)
            {
            *indiceID=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}*/
/*
int pan_existeID(Pantalla* pBuffer,int limite,int ID)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].ID==ID&&pBuffer[i].isEmpty==0){
            retorno=0;
        }
    }
    return retorno;
}*/

int utn_calcularNumeroMaximo(int *pArray,int limite,int *maximo)
{
    int auxMax;
    int i;
    int retorno=-1;
    if(limite>0 && pArray!=NULL){
        retorno=0;
        for (i=0;i<limite;i++){
            if(i==0){
                auxMax=pArray[i];
            }else if(pArray[i]>auxMax){
                auxMax=*(pArray+i);
            }
        }
    }
    *maximo=auxMax;
    return retorno;
}
/*int ModificarEmployeesPorId(Employees *list, int len,int id )

{
    int retorno = -1;
    int opcion;
    char auxNombre[50];
    char auxApellido[50];
    float auxSalario;
    int auxSector;
    if(list != NULL && len > 0 && len>0 && id >= 0 && id < len )
    {
        if (list[id].isEmpty == 1)
        {
            printf("\n Desea modificar : \n 1-Nombre: \n 2-Apellido: \n 3-Salario: \n 4 Sector: \n 5-Salir \n");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    fflush(stdin);
                if (utn_getNombre(auxNombre, 50, "\n Ingrese nombre :\n", "Nombre Invalido! \n", 2)==0)
                {
                    strncpy(list[id].name, auxNombre, 50);
                    printf("\n Se ha modificado el nombre con exito!!\n");
                    break;
                }
                case 2:
                                        fflush(stdin);

                if (utn_getNombre( auxApellido,50, "\n Ingrese apellido: \n","\Apellido invalido!\n", 2) == 0)
                {
                    strncpy(list[id].lastName, auxApellido, 51);
                    printf("Apellido modicado\n");
                    break;
                }
                case 3:
                                        fflush(stdin);

                if (utn_getFloat(&auxSalario,20, "\n Ingrese Salario:\n", " \nError de datos\n",2 )== 0)
                {
                    list[id].salary =  auxSalario;
                    printf("\n Se ha modificado el salario con exito!!\n");
                    break;
                }
                case 4:
                                        fflush(stdin);

                if (utn_getEntero( &auxSector , 20, "\nIngrese numero de Sector\n", "\n sector invalido!\n", 2) == 0)
                {
                   list[id].sector =  auxSector;
                    printf("\nSe ha modificado el sector con exito!\n");
                    break;
                }
                default :
                printf("Opcion no valida\n");
            }
            retorno = 0;
        }else
        {
            printf("\nEl id ingresado es inexistente!!\n");
        }
    }
return retorno;
}
int removeEmployee(Employees* list, int len , int id)
{
    int retorno = -1;


    fflush(stdin);

     if(list != NULL && len > 0  && id >= 0 && list[id].isEmpty == 1)
        {
            list[id].isEmpty=0;
            retorno = 0;
        }
        else
            {
               printf("\n Error, el id ingresado no existe... \n");
            }


return retorno;


 }
 int sortEmployees(Employees* list, int len, int order)
{
  int i, j;
  int auxiliarId;
  char auxNombre[50];
  char auxApellido[50];
  int auxSector;
  float auxSalario;
  if (list!= NULL && len > 0 && (order == 0 || order == 1))
    {
        for(i = 0; i < len; i++)
        {
          j = i + 1;
                fflush(stdin);
                if(list[i].isEmpty == 1&& list[j].isEmpty == 1 && order == 1 && strcmp(list[i].lastName,list[j].lastName) >0
                   || (strcmp(list[i].lastName,list[j].lastName) ==0 && list[i].sector > list[j].sector))
                {
                    auxiliarId = list[j].id;
                    list[j].id = list[i].id;
                    list[i].id = auxiliarId;

                    strncpy(auxApellido, list[j].lastName, 50);
                    strncpy(list[j].lastName,list[i].lastName, 50);
                    strncpy(list[i].lastName,auxApellido, 50);

                    strncpy(auxNombre, list[j].name, 50);
                    strncpy(list[j].name,list[i].name, 50);
                    strncpy(list[i].name,auxNombre, 50);

                    auxSalario = list[j].salary;
                    list[j].salary = list[i].salary;
                    list[i].salary = auxSalario;

                    auxSector = list[j].sector;
                    list[j].sector = list[i].sector;
                    list[i].sector = auxSector;
                }else if(list[i].isEmpty == 1&& list[j].isEmpty == 1 && order == 0 && strcmp(list[i].lastName,list[j].lastName) <0
                         || strcmp(list[i].lastName,list[j].lastName) ==0 && list[i].sector < list[j].sector)
                {
                    auxiliarId = list[j].id;
                   list[j].id = list[i].id;
                    list[i].id = auxiliarId;

                    strncpy(auxApellido, list[j].lastName, 50);
                    strncpy(list[i+1].lastName,list[i].lastName, 50);
                    strncpy(list[i].lastName,auxApellido, 50);

                    strncpy(auxNombre, list[j].name, 50);
                    strncpy(list[i+1].name,list[i].name, 50);
                    strncpy(list[i].name,auxNombre, 50);

                    auxSalario = list[j].salary;
                    list[j].salary = list[i].salary;
                    list[i].salary = auxSalario;

                    auxSector = list[j].sector;
                   list[j].sector = list[i].sector;
                    list[i].sector = auxSector;
                }
        }
    }
    return 1;
}

void EmployeesPromedio(Employees* list, int len)
{
   	int i, j;
	float acumuladorSalarios = 0;
	int superanPromedio = 0;
    int contadorSalarios = 0;
	if(list != NULL && len > 0 && len>0 )
	{
		for (i =0; i< len; i++ )
		{
			if(list[i].isEmpty == 1)
			{
				acumuladorSalarios = acumuladorSalarios + list[i].salary;
				contadorSalarios++;
			}
		}
		if (acumuladorSalarios > 0)
		{
			printf("\n El total de los salarios es : %f\n", acumuladorSalarios);
			printf("\n El promedio de los sueldos  es: %f\n", acumuladorSalarios/contadorSalarios);
		}
		for (j =0; j< len; j++)
		{
			if (list[j].isEmpty == 1 && list[j].salary > (acumuladorSalarios/contadorSalarios))
			{
				printf("\nId: %d\n", list[j].id);
				printf("\nNombre: %s\n", list[j].name);
				printf("\nApellido: %s\n ", list[j].lastName);
				printf("\nSalario: %f\n", list[j].salary);
				printf("\nSector: %d\n", list[j].sector);
				printf("                             \n");
				superanPromedio++;
				fflush(stdin);
			}
		}
		printf("\nLa cantidad de empleados que superan el sueldo promedio son : %d\n", superanPromedio);
	}
}

int utn_ordenarArray(int *pArray,int limite,int flagMaxMin)
{
    int i=0;
    int aux;
    int retorno=-1;
    int flag=1;

    if(pArray!=NULL&&limite>0){
        retorno=0;
        aux=pArray[i];
        while(flag==1){
            flag=0;
            for(i=0;i<(limite-1);i++){
                if( (flagMaxMin==1&& pArray[i]>pArray[i+1]) ||
                    (flagMaxMin==0&&pArray[i]<pArray[i+1]))
                {
                    flag=1;
                    aux=pArray[i];
                    pArray[i]=pArray[i+1];
                    pArray[i+1]=aux;
                }
            }
        }

    }
    return retorno;
}
int addEmployees(Employees* list, int len)
{
int i;
int retorno =-1;
char auxNombre [50];
char auxApellido [50];
float auxSalario;
int auxSector ;

        if(list != NULL && len > 0)
            {
                 for(i=0;i<len;i++)
                 {
                     fflush(stdin);
                        if( list[i].isEmpty ==0
                        &&
                         utn_getNombre(auxNombre,50,"\n Ingrese nombre \n","\n Error, nombre Invalido\n", 2)==0
                         &&
                         utn_getNombre(auxApellido,50,"\n Ingrese apellido \n","\n Error, apellido Invalido\n", 2)==0
                         &&
                         utn_getFloat(&auxSalario,len,"\n Ingrese salario \n","\n Error, salario Invalido\n", 2)==0
                         &&
                         utn_getEntero(&auxSector,len,"\n Ingrese sector \n","\n Error, sector Invalido\n", 2)== 0)
                        {
                            list[i].id = i;
                            strncpy(list[i].name, auxNombre, 50);
                            strncpy(list[i].lastName, auxApellido, 50);
                            list[i].salary =  auxSalario;
                            list[i].sector = auxSector;
                            list[i].isEmpty =  1;
                            retorno = 0;


                            retorno = 0;
                            break;
                         }
                    }

            }




return retorno;
}

*/
/*void imprimirEmpleados(Employees* list, int len)
{
      if (list != NULL && len > 0)
      {
      	for (int i =0; i< len; i++ )
		{
			if(list[i].isEmpty == 1)
            {
                printf("\nId: %d\n", list[i].id);
                printf("Nombre: %s\n", list[i].name);
                printf("Apellido: %s\n", list[i].lastName);
                printf("Salario: %f\n", list[i].salary);
                printf("Sector: %d\n", list[i].sector);
                printf("**********************\n");                }
        }
      }
}*/

int ordenarInsertion(int* pArray,int limite)
{
    int i,j;
    int temp;
    for (i=1;i<limite;i++){
        temp=*(pArray+i);
        j=i-1;
        while (j>=0 && temp<*(pArray+j)){
            *(pArray+j+1)=*(pArray+j);
            j--;
        }
        *(pArray+j+1)=temp;
    }
    return 0;
}


