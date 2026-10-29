# F&n - A free tool for every developer 🛠️
> **Hey !! How are you? <br>Im gonna do the documentation of F&n project 😃**
## F&n version: 0.2.1

## What is F&n❓ 
- F&n is a open **sourced application designed to be a counter of how much time do you spend programming**. <br>
- The idea is that the person who use this app will be able choose which IDE use and the "timer" starts automatically. <br>
- This application uses only native c and some libraries (stdio.h, stdlib.h, stdbool.h, string.h). <br>
- Firts of all i want make the application work appropriately and then make it for all OS (because it uses windows.h for now). <br>
- Starting from now, this is the 0.1.1 version.<br>
Enjoy to see through the code :) <br>
### Used technologies (correspond to this version) 
| Programing language | Reason |
|:---------:|:-------:|
| C         | C is fast and runs the "kernel" of my project |
<br>

> Down here you have some of my notes about the project,
> **but** I suggest you don't try to understand that (it's outdated).
---

<br>
And for now, 28/06/2026, I dont really now what I was thinking when I started...

Lógica (main):
    // Explicação do que acontece: Temos o tempo passado no vscode contado em segundos, todo esse processo acontece em 1 segundo (loop -> while)
    // Aí eu quis armazenar esse valor numa struct, mas eu quis armazenar em segundos,minutos, horas e dias
    // Para isso eu tive que transformar esses segundos em min,segund,etc...       -> Fiz isso usando a função arrumarTempo
    // Ok, primeiro passo feito. Agora eu devo realmente armazenar os dados numa struct global, chamada de tempoGlobal
    // Fiz isso declarando uma struct do tipo Tempo_Total, a própria tempoGlobal. E usei a função atualizarTempo para armazenar os valores na estrutura global
    // Precisa de muito polimento e de mais funções (resetar, deletar, ver em qual projeto vc gastou mais tempo, etc...)

Funções:
1- arrumar_Tempo -> Essa função pega um valor inteiro em segundos e o divide em: segundos,minutos,horas e dias para as informações ficarem em ordem e úteis. Até o momento, sua lógica de transformação está correta
