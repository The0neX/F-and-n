#include <stdio.h>
#include <windows.h>
//#define ARQ_BIN "arq.bin"
//  LOGICA DOS ARQUIVOS
//Eu tenho que salvar o log do tempo e a extensão do arquivo em um binário e mostrar em um txt...

    // Para retornar NULL a função deve ter o tipo de retorno de um ponteiro (char,int,etc). Posso fazer um retorno de int* e uma verificação binária. Se retornar 0
    // o programam falhou, se retornar 1 o prgrama continua normalmente
    
//    void coolWrite(int waka_Time){
//        Tempo_Total time = arrumar_Tempo(&waka_Time);
//        printf("Segundos: %d, minutos: %d, horas: %d, dias: %d \n",time.segundos,time.minutos,time.horas,time.dias);
//    }
    
    //Funcao de salvar os dados em bin
    void salvarDadosBin(Tempo_Total *dados) {
        FILE *f = fopen("arq.bin", "wb");
            if (f == NULL){
                printf("Erro ao abrir o arquivo");
                return 0;
            }
        if(fwrite(dados, sizeof(Tempo_Total), 1, f) == 1){
            printf("Salvado em binario c/ sucesso!\n");
        }
        else{
            printf("Dados não foram salvos em binário.\nDiganosticar o problema?\n");
        } 
    }
   void prtDados(Tempo_Total *dados) {

        FILE* logDeTempo = fopen("logdeTempo.txt","w");
        if (logDeTempo == NULL){
            printf("Erro ao criar o arquivo de print dos dados!");
            fclose(logDeTempo);
            exit(1);
        }else{
            fprintf(logDeTempo,"Tempo que você gastou programando:\n");
            fprintf(logDeTempo,"%dd %dh %dm %dseg",dados->dias,dados->horas,dados->minutos,dados->segundos);
            fprintf(logDeTempo,"\nTempo ainda está sendo contado!");  
            fclose(logDeTempo);
        }   
    }
