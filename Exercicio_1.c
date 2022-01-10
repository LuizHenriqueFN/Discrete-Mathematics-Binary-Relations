#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
#define LIM 51

/**************************COMPONENTES DO GRUPO***************************
        LUIZ HENRIQUE FERREIRA NEVES E DANILO ARAUJO DOMINGUES SILVA
**************************************************************************/

//Variáveis globais:
int A[TAM], B[TAM];

//*************************** Funções para gerar e organizar valores ***************************//

//Função para verificar se existem números repetidos no conjunto:
int Repetido(int *Vet, int i, int num){
    for(int j = 0; j < i; j++){
        if(Vet[j] == num){
            return 1;
        }
    }
    return 0;
}

//Função para preencher o conjunto para que os valores não se repitam:
void GeraAleatorio(int *Vet){
    int num;
    srand(time(NULL));

    for(int i = 0; i < TAM; i++){
        num = rand() % LIM;

        while(Repetido(Vet, i, num)){
            num = rand() % LIM;
        }

        Vet[i] = num;
    }
}

//Função para ordenar o conjunto de forma crescente:
void Ordena_Vet(int *Vet, int tam){
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


//***************************** Funções para cálculos *****************************//

//Função para unir os dois conjuntos sem repetir os valores:
void Uniao(int *Resultado){
    int aux, posicao = TAM;

    for(int i = 0; i < TAM; i++){
        Resultado[i] = A[i];
    }
    for(int i = 0; i < TAM; i++){
        aux = 0;
        for(int j = 0; j < TAM; j++){
            if(B[i] == A[j]){
                aux++;
            }
        }
        if(aux == 0){
            Resultado[posicao++] = B[i];
        }
    }
    //Chamando a função que ordena o conjunto:
    Ordena_Vet(Resultado, posicao-1);

}

//Função que verifica quais os números aparecem nos dois conjuntos:
void Intersecao(int *Resultado){
    int aux = 0;
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if(A[i] == B[j]){
                Resultado[aux++] = A[i];
            }
        }
    }
    //Chamando a função que ordena o conjunto:
    Ordena_Vet(Resultado, aux-1);
}

//Função que calcula a diferença entre os conjuntos:
void Diferenca(int *Resultado, int opcao){
    int aux, Posicao = 0;

    //Opção: 1- A-B; 2- B-A.
    if(opcao == 1){
        for(int i = 0; i < TAM; i++){
            aux = 0;
            for(int j = 0; j < TAM; j++){
                if(A[i] == B[j]){
                    aux++;
                }
            }
            if(aux == 0){
                Resultado[Posicao++] = A[i];
            }
        }

    }else{
        for(int i = 0; i < TAM; i++){
            aux = 0;
            for(int j = 0; j < TAM; j++){
                if(B[i] == A[j]){
                    aux++;
                }
            }
            if(aux == 0){
                Resultado[Posicao++] = B[i];
            }
        }
    }
    //Chamando a função que ordena o conjunto:
    Ordena_Vet(Resultado, Posicao-1);
}

//Função que calcula quais os valores que não estão presentes no conjunto:
void Complemento(int *Resultado){
    int Saida = 1, num;
    srand(time(NULL));
    for(int i = 0; i < 41; i++){
        num = rand() % LIM;
        Saida = 1;
        while(Saida){
            Saida = Repetido(Resultado, i, num);
            for(int j = 0; j < TAM; j++){
                if(A[j] == num){
                    Saida++;
                }
            }
            if(Saida == 1){
                num = rand() % LIM;
            }
            printf("Saida:%d Num:%d\n", Saida, num);
        }
        Resultado[i] = num;
        
    }
    //Chamando a função que ordena o conjunto:
    Ordena_Vet(Resultado, 41);
}
//*********************************************************************************//

//Função MENU para verificar a escolha do usuário:
void MENU(int Operacao, int Tamanho){
    int Resultado[Tamanho];// !- Declarando uma váriavel utilizando uma variável para definir o tamanho.

    //Limpando Vetor:
    for(int i = 0; i < Tamanho; i++){
        Resultado[i] = 0;
    }

    switch(Operacao){
        case 1:
            Uniao(Resultado);
            break;
        case 2:
            Intersecao(Resultado);
            break;
        case 3:
            Diferenca(Resultado, 1);
            break;
        case 4:
            Diferenca(Resultado, 2);
            break;
        case 5:
            Complemento(Resultado);
            break;
        case 6:
            //Função para gerar números aleatórios diferentes:
            GeraAleatorio(A);
            sleep(1);//Pausa para não repetir os valores.
            GeraAleatorio(B);

            //Função para ordenar:
            Ordena_Vet(A, TAM);
            Ordena_Vet(B, TAM);
            return;
        default:
            printf("\nA operação escolhida não existe. Tente novamente:\n");
            sleep(2);
            system("clear");
            return;
    }
    
    //Exibindo Resultado:
    printf("\nResultado = %d ", Resultado[0]);
    for(int i = 1; i < Tamanho; i++){
        if(Resultado[i] != 0){
            printf("%d ", Resultado[i]);
        }
    }
    printf("\n");

}

int main(){
    system("clear");
    int operacao, Tamanho;

    //Função para gerar números aleatórios diferentes:
    GeraAleatorio(A);
    sleep(1);//Pausa para não repetir os valores.
    GeraAleatorio(B);

    //Função para ordenar:
    Ordena_Vet(A, TAM);
    Ordena_Vet(B, TAM);

    //Menu de operações:
    do{
        //Exibir conjuntos:
        printf("\tA = ");
        for(int i = 0; i < TAM; i++){
            printf("%d ", A[i]);
        }
        printf("\n\tB = ");
        for(int i = 0; i < TAM; i++){
            printf("%d ", B[i]);
        }

        //Menu:
        printf("\n************************** Menu **************************\n");
        printf("1 - A U B;\n2 - A ∩ B;\n3 - A - B;\n4 - B - A;\n5 - ¬A;\n6 - Gerar novos números;\n0 - Sair;\nEscolha: ");
        scanf("%d", &operacao);

        //Definindo tamanho do vetor resultado:
        switch(operacao){
            case 1:
                Tamanho = 20;
                break;
            case 2:
            case 3:
            case 4:
                Tamanho = 10;
                break;
            case 5:
                Tamanho = 41;
                break;
        }

        //Chamar MENU ou sair:
        if(operacao != 0){
            MENU(operacao, Tamanho);
        }else{
            system("clear");
            printf("\nEncerrando...");
        }

    }while(operacao != 0);

    return 0;
}