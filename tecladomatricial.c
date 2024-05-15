#include "TECLADOMATRICAL.h"
#include "MKL25Z4.h"
int Columnas [4]{1,2,3,4}
int Filas []{5,6,7,8};

char teclado[4][4]{
                    {'1','2','3','A'},
                    {'4','5','6','B'},
                    {'7','8','9','C'},
                    {'*','0','#','D'}
                };
void(char puerto){
swich(puerto){
    case 'A':
    for(i=0; i<8; i++){
    PORTA -> PCR[Columnas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PS_MASK;
    PORTA -> PCR[Filas[i]]|=PORT_PCR_MUX(1);
    }
    break;
    case 'B':
    for(i=0; i<8; i++){
    PORTB -> PCR[Columnas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PS_MASK;
    PORTB -> PCR[Filas[i]]|=PORT_PCR_MUX(1);
    }
    break;
    case 'C':
    for(i=0; i<8; i++){
    PORTC -> PCR[Columnas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PS_MASK;
    PORTC -> PCR[Filas[i]]|=PORT_PCR_MUX(1);
    }
    break;
    case 'D':
    for(i=0; i<8; i++){
    PORTD -> PCR[Columnas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PS_MASK;
    PORTD -> PCR[Filas[i]]|=PORT_PCR_MUX(1);
    }
    break;
    case 'E':
    for(i=0; i<8; i++){
    PORTE -> PCR[Columnas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PS_MASK;
    PORTE -> PCR[Filas[i]]|=PORT_PCR_MUX(1);
    }
    break;
    }
void escaneo(char puerto){
    swich(puerto){
        case 'A':

                    for(i=0; i<4; i++){
                        PTA-> PSOR|=(0u<< Filas[i]);
                        
                        for(j=0; j<4; j++){
                            int ESTADO = PTA->PDIR & (1<<Columnas[j]);
                                if(ESTADO==0){
                                 return teclado[i][j];
                        }
                    }
                        PTA-> PSOR|=(1u<< Filas[i]);
                    }
                    break:
        case 'B':
                    for(i=0; i<4; i++){
                        PTB-> PSOR|=(0u<< Filas[i]);
                        
                        for(j=0; j<4; j++){
                            int ESTADO = PTB->PDIR & (1<<Columnas[j]);
                                if(ESTADO==0){
                                return teclado[i][j];
                        }
                    }
                        PTB-> PSOR|=(1u<< Filas[i]);
                    }
                    break:
        case 'C':
                    for(i=0; i<4; i++){
                        PTC-> PSOR|=(0u<< Filas[i]);
                        
                        for(j=0; j<4; j++){
                            int ESTADO = PTC->PDIR & (1<<Columnas[j]);
                                if(ESTADO==0){
                                return teclado[i][j];
                        }
                    }
                        PTC-> PSOR|=(1u<< Filas[i]);
                    }
                    break:
        case 'D':
                    for(i=0; i<4; i++){
                        PTD-> PSOR|=(0u<< Filas[i]);
                        
                        for(j=0; j<4; j++){
                                int ESTADO = PTD->PDIR & (1<<Columnas[j]);
                                if(ESTADO==0){
                                return teclado[i][j];
                        }
                    }
                        PTD-> PSOR|=(1u<< Filas[i]);
                    }
                    break:
        case 'E': 
                    for(i=0; i<4; i++){
                        PTE-> PSOR|=(0u<< Filas[i]);
                        
                        for(j=0; j<4; j++){
                            int ESTADO = PTE->PDIR & (1<<Columnas[j]);
                            if(ESTADO==0){
                            return teclado[i][j];
                        }
                    }
                        PTE-> PSOR|=(1u<< Filas[i]);
                    }
                    break:
        }
    }
}
