/**************************COMPONENTES DO GRUPO***************************
        LUIZ HENRIQUE FERREIRA NEVES E DANILO ARAUJO DOMINGUES SILVA
**************************************************************************/

/*
Exercício 2.
    Considere como universo de valores o conjunto de números inteiros 0 ≤ x ≤ 50.
    Considere dois conjuntos A e B, onde |A| = 20 e |B| = 5, compostos por elementos aleatórios dentro do
    universo de valores possíveis.
    Deve ser criado um algoritmo para analisar se B ⊆ A.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM 51
#define TAM_A 20
#define TAM_B 5


//*************************** Funções para gerar e organizar valores ***************************//
int Repetido(int *Vet, int i, int num){//Função que avaliará se o vetor possui ou não números repetidos
    for(int j = 0; j < i; j++){
        if(Vet[j] == num){
            return 1;
        }
    }
    return 0;
}

void GeraAleatorio(int *Vet, int tam){//Função responsável por gerar números aleatórios
    int num;
    srand(time(NULL));//'Plantando' seed de números aleatórios

    for(int i = 0; i < tam; i++){
        num = rand() % LIM;

        while(Repetido(Vet, i, num)){
            num = rand() % LIM;
        }

        Vet[i] = num;
    }
}

void Ordena_Vet(int *Vet, int tam){//Função responsável pela ordenação do vetor
    int aux;
    for(int j = 0; j < tam; j++){
        for(int i = 0; i < tam; i++){
            if(Vet[i] > Vet[i+1] && i+1 != tam){
                aux = Vet[i];
                Vet[i] = Vet[i+1];
                Vet[i+1] = aux;
            }
        } 
    }
}
//**********************************************************************************************//

//Função para verificar se B é subconjunto de A
int Subconjunto(int *A, int *B){
    int aux = 5;
    for(int i = 0; i < TAM_B; i ++){
        for(int j = 0; j < TAM_A; j++){
            if(B[i] == A[j]){
                aux--;
            }
        }
    }
    return aux;
}

//Chamada principal
int main(){
    int A[TAM_A] = {}, B[TAM_B] = {}, opcao, Sub;
    system("clear");

    //Função para gerar números aleatórios diferentes:
    GeraAleatorio(A, TAM_A);
    sleep(1);//Pausa para não repetir os valores.
    GeraAleatorio(B, TAM_B);

    //Função para ordenar:
    Ordena_Vet(A, TAM_A);
    Ordena_Vet(B, TAM_B);

    do{
        //Exibindo conjuntos:
        printf("A = ");
        for(int i = 0; i < TAM_A; i ++){
            printf("%d ", A[i]);
        }
        printf("\nB = ");
        for(int i = 0; i < TAM_B; i ++){
            printf("%d ", B[i]);
        }

        Sub = Subconjunto(A, B);
        if(Sub == 0){
            printf("\n\n\t\tB ⊆ A\n");
        }else{
            printf("\n\n\t\tB ⊈ A\n");
        }
        
        //Menu:
        printf("\n************************** Menu **************************\n");
        printf("0- Sair;\n1- Gerar novos números;\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                system("clear");
                printf("Encerrando...");
                break;
            case 1:
                system("clear");
                //Função para gerar números aleatórios diferentes:
                GeraAleatorio(A, TAM_A);
                sleep(1);//Pausa para não repetir os valores.
                GeraAleatorio(B, TAM_B);

                //Função para ordenar:
                Ordena_Vet(A, TAM_A);
                Ordena_Vet(B, TAM_B);
                break;
            default:
                system("clear");
                printf("\nOpção escolhida não existe. Tente novamente:\n");
                break;
        }

    }while(opcao != 0);
    
    return 0;
}