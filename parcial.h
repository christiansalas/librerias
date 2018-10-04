
int utn_getString(char* pBuffer, int limite);

int isValidMail(char* pBuffer, int limite);

int utn_getEmial(char* pBuffer,int limite,char msj,char*msjError,int reintentos);

int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos);

int utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos);

int utn_getEntero(  int *pEntero, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
int esTelefono(char str[]);

int getString(char* pBuffer, int limite);
 int isValidNombre(char* pBuffer,int limite);
 int isValidFloat(char *pBuffer, int limite);







