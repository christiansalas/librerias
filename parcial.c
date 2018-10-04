#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "parcial.h"
#include "ctype.h"
#include "arrays.h"



/**
* \brief El usuario ingresa una cadena con fgets
 \param pBuffer Recibe el texto ingresado en caso de exito
 \param limite Es el tamano maximo del string
 \return En caso de exito retorna 0, si no -1
/*/
int utn_getString(char *pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[4096];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        //__fpurge(stdin);
        fflush(stdin);
        fgets(bufferStr,limite,stdin);
        len = strlen(bufferStr);
        if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer,bufferStr,limite);
    }
    return retorno;
}

int isValidMail(char* pBuffer, int limite)
{
    int retorno = 0;
    int contadorDeArrobas = 0;
    int contadorDePuntosTrasArroba = 0;
    int flagLetraIntroducida = 0;
    int i;
    if( pBuffer != NULL && limite > 0 &&
        tolower(pBuffer[0]) >= 'a' &&
        tolower(pBuffer[0]) <= 'z')
    {
        retorno = 1;
        flagLetraIntroducida = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if( (tolower(pBuffer[i]) >= 'a' && tolower(pBuffer[i]) <= 'z' ) ||
                (pBuffer[i] >= '0' && tolower(pBuffer[i]) <= '9' && contadorDeArrobas == 0))
            {
                flagLetraIntroducida = 1;
            }
            else if(pBuffer[i] == '@' && contadorDeArrobas == 0 && flagLetraIntroducida == 1)
            {
                contadorDeArrobas++;
                flagLetraIntroducida = 0;
            }
            else if(pBuffer[i] == '.' && flagLetraIntroducida == 1)
            {
                flagLetraIntroducida = 0;
                if(contadorDeArrobas == 1)
                {
                    contadorDePuntosTrasArroba++;
                }
            }
            else if(pBuffer[i] == '_' && flagLetraIntroducida == 1 && contadorDeArrobas == 0)
            {
                flagLetraIntroducida = 0;
            }
            else
            {
                retorno = 0;
                break;
            }
        }
    }
    if(retorno == 1 && contadorDeArrobas == 1 && contadorDePuntosTrasArroba > 0)
    {
        retorno = 1;
    }
    else
    {
        printf("\nejemplo_123@mail.com.ar");
        retorno = 0;
    }
    return retorno;
}



int utn_getEmial(char* pBuffer,int limite,char msj,char*msjError,int reintentos)
{
    int retorno=-1;
    char buffer[limite];

    if(pBuffer!=NULL && limite >0 && reintentos >=0)
    {
        do{
            reintentos--;
            printf("%s",msj);
            if(utn_getString(pBuffer,limite)==0 && isValidMail(pBuffer, limite)==1)
            {
                //strncpy(pArray,buffer,limite);
                retorno=0;
                break;
            }else
                printf("%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}
int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferNombre[100];

    if( pNombre != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferNombre,limite) == 0 &&
                isValidNombre(bufferNombre,limite))
            {
                strncpy(pNombre,bufferNombre,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

int utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferFloat[4096];
    if( pFloat != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferFloat, limite) == 0 &&
                isValidFloat(bufferFloat, limite))
            {
                *pFloat = atof(bufferFloat);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;

}
 int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[100];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
       // __fpurge(stdin);
        fgets(bufferStr,limite,stdin);
        len = strlen(bufferStr);
        if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer,bufferStr,limite);
    }
    return retorno;
}
 int isValidNombre(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int isValidFloat(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    int contadorDePuntos = 0;
    if  ((pBuffer != NULL && limite > 0 ) &&
        (((pBuffer[0] == '-' || pBuffer[0] == '+') && pBuffer[1] != '.') ||
        (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1;i < limite && pBuffer[i] != '\0';i++)
        {
            if(pBuffer[i]=='.' && contadorDePuntos==0)
            {
                contadorDePuntos++;
            }
            else if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


