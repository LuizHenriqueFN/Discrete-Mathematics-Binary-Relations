#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Linha 10
#define Coluna 2
#define Lim 5

/**************************COMPONENTES DO GRUPO***************************
        LUIZ HENRIQUE FERREIRA NEVES E DANILO ARAUJO DOMINGUES SILVA
**************************************************************************/


//Função responsável pela exibicão da matriz
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

//Função responsável pela verificacão da matriz
void Fecho_Reflexivo(int Mat[][Coluna], int *Boolean){
    int Fecho[15][Coluna] = {}, aux = 0;//delcaracão de uma matriz chamada fecho, com 15 posicoes, ja' que no maximo sera' necessario
                                        //adicionar todos os pares reflexivos de 0 a 4
    for(int i = 0; i < Linha; i++){
        for(int j = 0; j < Coluna; j++){
            Fecho[i][j] = Mat[i][j];//todas as posicoes da matriz são passadas de forma identica para a matriz fecho
        }
    }

    for(int i = 0; i < Lim; i++){
        if(Boolean[i] == 1){
            for(int j = 0; j < Linha; j++){
                if(Mat[j][0] == i && Mat[j][1] == i){//condicão que confere se as duas posicoes de uma mesma linha são iguais
                    break;
                }
                if(j == Linha-1){//estabelece o limite de ate' onde o codigo sera' executado
                    Fecho[Linha+aux][0] = i; 
                    Fecho[Linha+aux][1] = i; 
                    aux++;
                }
            }
        }
    }

    printf("\nFecho Reflexivo:\n");
    for(int i = 0; i < Linha + aux; i++){//'printando' na tela o resultado, ou seja, o fecho reflexivo
        for(int j = 0; j < Coluna; j++){
            printf("%d ", Fecho[i][j]);
        }
        printf("\n");
    }
}

//Função que avalia a matriz e a completa de forma simetrica gerando um fecho
void Fecho_Simetrico(int Mat[][Coluna]){
    int x, y, Fecho[20][Coluna] = {}, aux = 0;

    for(int i = 0; i < Linha; i++){
        for(int j = 0; j < Coluna; j++){
            Fecho[i][j] = Mat[i][j];//todas as posicoes da matriz são passadas de forma identica para a matriz fecho
        }
    }

    for(int i = 0; i < Linha; i++){
        x = Mat[i][0];//armazena os números de cada linha e cada coluna em tais variáveis
        y = Mat[i][1];

        for(int j = 0; j < Linha+aux; j++){
            if(Fecho[j][0] == y && Fecho[j][1] == x){//analisa se as posicoes de uma mesma linha são iguais, ja que em uma relacão simetrica 
                break;                               //pode ocorrer uma simetria (x,x) mas não uma (x,y) (y,x)
            }
            if(j == Linha+aux-1){
                Fecho[Linha+aux][0] = y;
                Fecho[Linha+aux][1] = x;
                aux++;
            }
        }
    }

    printf("\nFecho Simétrico:\n");
    for(int i = 0; i < Linha + aux; i++){//'printando' fecho simetrico
        for(int j = 0; j < Coluna; j++){
            printf("%d ", Fecho[i][j]);
        }
        printf("\n");
    }
}


//chamada principal
int main(){
    srand(time(NULL));
    int Mat[Linha][Coluna] = {}, num, Boolean[Lim] = {}, opcao;//declaracão de variáveis

    for(int i = 0; i < Linha; i++){//preenchimento da matriz
        for(int j = 0; j < Coluna; j++){
            num = rand() % Lim;
            Boolean[num] = 1;
            Mat[i][j] = num;
        }
    }

    ExibirMat(Mat);//exibicão da matriz

    //chamada da função reflexiva e simetrica
    Fecho_Reflexivo(Mat, Boolean);
    Fecho_Simetrico(Mat);

    do{
        printf("\n************************** Menu **************************\n");
        printf("\n0- Sair;\n1- Gerar novos números;\nOpção: ");
        scanf("%d", &opcao);
        
        if(opcao == 1){
            for(int i = 0; i < Linha; i++){
                for(int j = 0; j < Coluna; j++){
                    num = rand() % Lim;
                    Boolean[num] = 1;
                    Mat[i][j] = num;
                }
            }

            ExibirMat(Mat);//exibindo matriz

            Fecho_Reflexivo(Mat, Boolean);
            Fecho_Simetrico(Mat);
        }else{
            system("clear");
            printf("Encerrando...");
        }
    }while(opcao);

    return 0;
}