HANDLE h; /* handler, sera el descriptor del puerto */
DCB dcb; /*  estructura de configuracion */
DWORD dwEventMask; /* mascara de eventos */
 
void _OPEN(char *PORT, int BAUD_RATE){
    /* abrimos el puerto */
    h=CreateFile(PORT,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
    dcb.BaudRate = BAUD_RATE;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;
    dcb.StopBits = ONESTOPBIT;
    dcb.fBinary = TRUE;
    dcb.fParity = TRUE;
    dcb.fDtrControl = DTR_CONTROL_ENABLE;
    /* Establecemos la nueva configuracion */
    if(!SetCommState(h, &dcb)) {
        /* Error al configurar el puerto */
    }
    /* Para que WaitCommEvent espere el evento RXCHAR */
    SetCommMask(h, EV_RXCHAR);
}

void _CLOSE(char *PORT){
	//printf("%s CLOSED ...\n",PORT);
    CloseHandle(h);
}

void SEND_TO(char enviar){
    DWORD n;
    if(!WriteFile(h, &enviar/*puntero al buffer*/, 1/* 1 byte*/, &n, NULL)){
            /* Error al enviar */
    }    
}

char RECIVE_FROM(){
    char recibido;
    DWORD n;
    /* De la llamada a WaitCommEvent solo se retorna cuando ocurra
    * el evento seteado con SetCommMask */
    WaitCommEvent(h, &dwEventMask, NULL);
    /* Recibimos algun dato!*/
    ReadFile(h, &recibido, 1/* leemos un byte */, &n, NULL);
    return recibido;
}
