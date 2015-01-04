/* 
 * File:   usbcomm.cpp
 * Author: usuario
 *
 * Created on 4 de enero de 2015, 08:49 AM
 */

#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include "cdc.h"

using namespace std;

/*
 * 
 */
int main(int argc, char *argv[]) {
    byte c;
    if (argc < 3) {
        printf("\nERROR 01: Sintaxis C:\\COntrolCom COMx [0|1 DATA]");
        exit(1);
    }

    _OPEN(*(argv + 1), 9600); // ABIR EL PUERTO COM1 y VELOCIDAD 9600

    switch (argv[2][0]) {
        case '0':
            SEND_TO('0');
            c = RECIVE_FROM();
            printf("\nDIPSWITCH = 0x%02X\n", c);
            break;
        case '1':
            SEND_TO('1');
            SEND_TO(atoi(*(argv + 3)));
            if (RECIVE_FROM() == '1') printf("\n---> ENVIADO CON EXITO ...\n");
            break;
    }

    _CLOSE(*(argv + 1));
    //system("PAUSE");
    return EXIT_SUCCESS;
}


