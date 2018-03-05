#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void busca_binaria(int array[30],int valor);
void busca_linear(int array[30],int  valor);
void busca_inter(int array[30],int valor);

int main()
{
   int array[30] = {2,4,6,7,8,10,11,12,14,16,18,20,22,24,25,26,28,30,32,34,36,38,39,40,42,44,46,48,49,50};
   busca_binaria(array,42);
   busca_linear(array, 42);
   busca_inter(array, 42);
}

void busca_linear(int array[30],int valor){
    clock_t inicio, fim;
    double tempo_total;
    inicio = clock();
    int i = 0, qntd = 0;
    while (qntd<100000000){
       while (array[i] != valor){
            i++;
        }
        if (i<42){
            i=0;
        }
        else{
            i=0;
        }
    qntd += 1;
    }
    fim = clock();
    tempo_total = (double)(fim - inicio)/CLOCKS_PER_SEC;
    printf("Tempo Busca linear: %.1f segundos.", tempo_total);
}
void busca_binaria(int array[30],int valor){
    clock_t inicio, fim;
    double tempo_total;
    inicio = clock();
    int i = 0, qntd = 0;
    while (qntd<100000000){
        int first, last;


        meio = (dir + esq) >> 1
        while (esq < dir) {
        meio = floor((esq + dir) / 2)
        if (vetor[meio] == valor) return meio
        if (vetor[meio] < valor) esq = meio + 1
        else if (vetor[meio] > valor) dir = meio - 1
    }
}
