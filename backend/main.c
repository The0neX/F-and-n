#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "functions_main.h"
#include "files.h"

    //Convenções que eu adotei: Funções e struturas são escritas com camelCase. Variaveis são escritas com snake_case
    //LPCSTR titulo_janela = "It_Over_for_Beta"; Long pointer to constant string = const* char p
    //int teste = 12332;
    //Tempo_Total result = arrumar_Tempo(&teste);
    //printf("Segundos: %d, minutos: %d, horas: %d, dias: %d \n",result.segundos,result.minutos,result.horas,result.dias);

    //Declaração da variável que irá armazenar os valores de tempo em segundos, minutos e horas
   totalTime global_time = {0,0,0,0};
//LOGICA    
int main(){    
    char *ide_name = "Visual Studio Code"; // Fiz isso porque a pessoa pode usar diferentes IDE's
    int* contador_waka_time = (int *)malloc(sizeof(int));
    *contador_waka_time = 0;
    int length_of_window_name = 0;

    //Alvos das marcações de divisor das strings
    char *string_target = (char *)malloc(sizeof(char));    
        while(1){                      
            printf("If you wanna stop the loop, press: 'p'\n");
            if (_kbhit()){
                char user_pressed_letter = getchar();
                if (user_pressed_letter == 'p'){
                    printf("Getting out the program...\n");
                    break;
                }
            }

            HWND hwnd = GetForegroundWindow();
            
            if (hwnd != NULL || length_of_window_name == 0){   

                length_of_window_name = GetWindowTextLengthA(hwnd); //Pega o tamanho do nome da janela
                                                     
                char *window_title = (char *)malloc((length_of_window_name+1)*sizeof(char));  //Aloca tamanho(buffer) para "pegar" o título

                if (GetWindowTextA(hwnd,window_title,length_of_window_name+1) > 0){

                    //Logica maior: A janela em foco do usuario esta no vscode?

                    char *is_in_ide = strstr(window_title, ide_name);
                    if(!is_in_ide){
                        printf("You are not in %s", ide_name);
                        free(window_title);
                        Sleep(1000);
                        continue;
                    }
                    free(is_in_ide);
                    free(ide_name);                                        
                    //Explicacao em teste.c 
                    //LÓGICA PARA PEGAR A EXTENSÃO DO ARQUIVO QUE ESTÁ SENDO USADO

                    char *token; // string maior, contendo o título completo da janela (menos o nome do arquivo utilizado)
                    char *token2; // recebera a string menor, não contendo a extensao do arquivo utilizado 
                    
                    string_target = '.';
                    token = strchr(window_title, string_target);

                    if(!token){
                        printf("\nYour file does not have programing extension.\n ");
                        free(window_title);
                        Sleep(1000);
                        continue;
                    }

                    int tamanhodiferenca;

                    string_target = ' ';
                    token2 = strchr(token,string_target);
                    
                    if (token2 != NULL){
                        tamanhodiferenca = token2 - token;
                    } else{
                        tamanhodiferenca = strlen(token);
                    }
                    
                    char *projet_Extension = (char *) malloc((tamanhodiferenca+1)*sizeof(char));
                    if(projet_Extension == NULL){
                        printf("\nA alocacao de memoria para o nome da extensao falhou :( ");
                        continue;
                    }
                    
                    strncpy(projet_Extension,token,tamanhodiferenca);
                    projet_Extension[tamanhodiferenca] = '\0';  // projet_Extension contém o .extensaoDoArquivo
                    //lógica termina

                    //LÓGICA PARA PEGAR O NOME DO ARQUIVO QUE ESTA SENDO UTILIZADO         
                    string_target = '.';
                    token = window_title;
                    token2 = strchr(token,string_target);
                    tamanhodiferenca = token2 - token;

                    char *project_Name = (char *) malloc((tamanhodiferenca+1)*sizeof(char));
                    if (project_Name == NULL){

                        printf("\nAlocacao de memoria para o nome do projeto falhou. ");
                        break;
                    }
                    strncpy(project_Name,token,tamanhodiferenca);
                    project_Name[tamanhodiferenca] = '\0';

                    (*contador_waka_time)+=1;

                    printf("Titulo da janela: %s \n",window_title);
                    printf("Nome do projeto e: %s \n",project_Name);
                    printf("A extensao que voce esta usando e: %s \n",projet_Extension);
                    free(string_target);
                    free(project_Name);
                    free(projet_Extension);
                } else {

                    printf("GetwindowTextA falhou.");

                }

                free(window_title);        

            } else {
                printf("Janela sem titulo! \n");
            }
            
            Sleep(1000);
        }       
        // Eu tenho um contador (em segundos), quero armazenar a informação numa struct.
        // Depois vou printar as informações igual eu fiz lá em cima

    int *myArray = arrumar_Tempo(*contador_waka_time);
    if (myArray!=NULL){
        int bitVerificacao = atualizarTempo(&global_time,myArray[0],myArray[1],myArray[2],myArray[3]);
            if (bitVerificacao == 1){
                printf("Dados guardados com sucesso!");
            } else{
                    printf("Dados não guardados! Problemas na função: atualizarTempo"); 
                    exit(1);
                }
    } else {
        exit(1);
    }

    prtDados(&global_time);

free(myArray);
   
return 0;
}