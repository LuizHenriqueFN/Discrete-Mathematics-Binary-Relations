#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Linha 10
#define Coluna 2
#define Lim 5

/**************************COMPONENTES DO GRUPO***************************
        LUIZ HENRIQUE FERREIRA NEVES E DANILO ARAUJO DOMINGUES SILVA
**************************************************************************/

//Função criada para exibição da matriz:
void ExibirMat(int Mat[][Coluna]){
    printf("\n");
    for(int i = 0; i < Linha; i++){
        for(int j = 0; j < Coluna; j++){
            printf("%d ", Mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Função para analisar se a matriz criada, que possui uma "divisão" por tuplas,
//possui ou não a caracteristica de ser reflexiva
void Reflexivo(int Mat[][Coluna], int *Boolean){
    srand(time(NULL));
    int Refle[Lim] = {}, Tam = 0, aux = 0;

    //Tam = Variável que contém quantos números apareceram.
    for(int i = 0; i < Lim; i++){
        Tam += Boolean[i];
    }

    //Verificando se os pares são reflexivos:
    for(int i = 0; i < Lim; i++){
        for(int j = 0; j < Linha; j++){
            //Condição para verificar se o par ordenado está presente na matriz:
            if(Mat[j][0] == i && Mat[j][1] == i && Boolean[i] == 1){
                Refle[i] = 1;
            }
        }
    }

    //aux = Variavel que contem quantos pares apareceram.
    for(int i = 0; i < Lim; i++){
        aux += Refle[i];
    }

    //Verificando se o a quantidade de números é igual a quantidade de pares de cada número presente:
    if(aux == Tam){
        printf("\tReflexivo: Sim.");
    }else{
        printf("\tReflexivo: Não.");
    }
    return 0;
}

//Função que verifica se a matriz criada, que possui uma "divisão" por tuplas,
//possui ou não a caracteristica de ser simetrica
void Simetrico(int Mat[][Coluna]){
    int x, y, aux = 0;

    for(int i = 0; i < Linha; i++){
        x = Mat[i][0]; //Os valores das casas são armazenados nas variáveis.
        y = Mat[i][1];

        for(int j = 0; j < Linha; j++){
            if(Mat[j][0] == y && Mat[j][1] == x){//É então verificado se, quando invertemos estes valores de posicão,
                aux++;                           //há algum par que seja igual ao que foi invertido, e caso haja, a função auxiliar terá a função de contador.
                break;                           
            }
        }
    }

    if(aux == 10){//Caso a soma total seja 10, ou seja todos os pares correspondem a um outro inverso, logo, é simétrico.
        printf("\n\tSimétrico: Sim.");
    }else{
        printf("\n\tSimétrico: Não.");
    }
}

//Função que analisa se a matriz gerada é antissimetrica:
void Antissimetrico(int Mat[][Coluna]){
    int x, y, aux = 0;

    for(int i = 0; i < Linha; i++){
        x = Mat[i][0]; //Os valores das casas são armazenados nas variáveis. 
        y = Mat[i][1];
        if(x == y){
            continue;
        }

        for(int j = 0; j < Linha; j++){
            if(Mat[j][0] == y && Mat[j][1] == x){//É então verificado se, quando invertemos estes valores de posição,
                aux = 1;                         //há algum par que seja igual ao que foi invertido
            }                                    //caso haja, então não é antissimetrico.
        }
    }

    if(aux == 0){
        printf("\n\tAntissimétrico: Sim.");
    }else{
        printf("\n\tAntissimétrico: Não.");
    }
}

//Função que verifica se a matriz gerada possui a propriedade transitiva:
void Transitivo(int Mat[][Coluna]){
    int x, y, z, Saida = 0;

    for(int i = 0; i < Linha; i++){
        x = Mat[i][0];//Os números das casas de cada linha são armazenados em variáveis cada vez que o ciclo 'for' é executado.
        y = Mat[i][1];

        for(int j = 0; j < Linha; j++){
            if(Mat[j][0] == y){//Caso o primeiro número de um par de uma linha qualquer seja igual a y,
                z = Mat[j][1];//então o segundo número deste par desta linha qualquer é armazenado na variavel z.
                for(int k = 0; k < Linha; k++){
                    if(Mat[k][0] == x && Mat[k][1] == z){//Caso haja um par de números em uma linha qualquer que possua x como o primeiro número e z como o segundo,
                        break;                           //temos então uma relacão transitiva.
                    }
                    if(k == Linha-1){//Condição que define para o algoritmo até onde ele vai ser executado.
                        Saida = 1;
                        break;
                    }
                    
                }
            }
            if(Saida == 1){
                break;
            }

        }
       
        if(Saida == 1){
            break;
        }
        
    }
    if(Saida == 0){//Se a saida for 0, o código foi executado e não foi achado nenhum erro, então a matriz é transitiva.
        printf("\n\tTransitivo: Sim.");
    }else{
        printf("\n\tTransitivo: Não.");
    }
}

int main(){//Função principal:
    srand(time(NULL));
    int Boolean[Lim] = {}, num, opcao;
    int Mat[Linha][Coluna] = {};//Criando matriz vazia para depois ser preenchida.

    for(int i = 0; i < Linha; i++){
        for(int j = 0; j < Coluna; j++){
            num = rand() % Lim;

            //Verificando os valores que existem na matriz:
            Boolean[num] = 1;
            Mat[i][j] = num;
        }
    }

    ExibirMat(Mat);

    //Chamando Funções para verificar se a matriz possui as propriedades reflexiva, simétrica, antissimétrica e transitiva, respectivamente.
    Reflexivo(Mat, Boolean);
    Simetrico(Mat);
    Antissimetrico(Mat);
    Transitivo(Mat);

    do{//Menu do programa principal:
        printf("\n************************** Menu **************************\n");
        printf("0- Sair;\n1- Gerar novos números;\nOpção: ");//Exibindo na tela as opções.
        scanf("%d", &opcao);//Recebendo as opções do usuário.

        if(opcao == 1){//Se o usuário tiver escolhido a posição 1, então uma nova matriz será gerada e analisada novamente.
            for(int i = 0; i < Linha; i++){
                for(int j = 0; j < Coluna; j++){
                    num = rand() % 5;

                    //Verificando os valores que existem  na matriz:
                    Boolean[num] = 1;
                    Mat[i][j] = num;
                }
            }

            ExibirMat(Mat);

            //Chamando Funções para verificar se a matriz possui as propriedades reflexiva, simétrica, antissimétrica e transitiva, respectivamente.
            Reflexivo(Mat, Boolean);
            Simetrico(Mat);
            Antissimetrico(Mat);
            Transitivo(Mat);
        }else{
            system("clear");//Limpando terminal.
            printf("Encerrando...");
        }
    }while(opcao);

    return 0;
}