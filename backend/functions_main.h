#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main_struct.h"
    // FUNCOES
int* arrumarTempo(int qtdtempo){        // 12332
    int *pointer2vet = (int*) malloc(4*sizeof(int));

    if (pointer2vet ==NULL){
        printf("Erro ao alocar memória para o vetor dentro de 'arrumar_Tempo' ");
            return NULL;
    }
        
    int totalSegundos = qtdtempo; // 12332
    int segundos = totalSegundos % 60; //32
    int minutosTotais = totalSegundos / 60; //205
    int minutos = minutosTotais % 60; //25
    int horasTotais = minutosTotais / 60; //3
    int horas = horasTotais % 24; //3
    //lógica do dia está errada, na real nem tem kakakkaa
    int dias = 0;
    //   vetor[0- "segundos" ,1- "minutos" ,2-"horas" ,3- "dias"]
    pointer2vet[0] = segundos;
    pointer2vet[1] = minutos;
    pointer2vet[2] = horas;
    pointer2vet[3] = dias;
              
    return pointer2vet;
}  
int atualizarTempo(totalTime *mainStructTime,int sec, int min, int hr, int days){
    int binary_validation;    
     if (mainStructTime != NULL){
        binary_validation = 1;
        
        mainStructTime -> seconds += sec;
        mainStructTime -> minutes += min;
        mainStructTime -> hours += hr;
        mainStructTime -> days += days; 
        
        return binary_validation;
    
     } else {
            binary_validation = 0;
            
            return binary_validation;
        }
    }

//int verify_If_Days(int qtdtempo){}
void daysSetter(){printf("Nothing");}
