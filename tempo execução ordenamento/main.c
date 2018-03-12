#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QNTD 1
double tempo_insertion_sort(int array[30]);
void tempo_counting_sort(int array[30]);
int main()
{
    int array[30] = {10,24,2,25,11,8,32,42,16,49,40,20,22,32,50,32,28,48,11,25,30,46,18,39,32,6,11,44,4,8};
    //printf("Insertion sort: %lf segundos.",tempo_insertion_sort(array));
    //printf("Counting sort: %lf segundos.", tempo_insertion_sort(array));
    tempo_counting_sort(array);
}

double tempo_insertion_sort(int array[30]){
    clock_t inicio, fim;
    int i,j,aux,vezes = 0;
    double tempo_final;
    inicio = clock();
    while (vezes < QNTD){
        for (i=0;i<30;i++){
            for (j=i;j>0 && array[j-1] > array[j];j--){
                aux = array[j];
                array[j] = array[j-1];
                array[j-1] = aux;
            }
        }
        vezes += 1;
    }
    fim = clock();
    return tempo_final = (fim - inicio)/CLOCKS_PER_SEC;
}
void tempo_counting_sort(int array[30]){
    clock_t inicio, fim;
    int i,vezes = 0, count[50], maior = 50, ordenado[30];
    double tempo_final;
    inicio = clock();
    for (i=0;i<maior;i++){
        count[i] = 0;
        ordenado[i] = 0;
    }
    while (vezes < QNTD){
        for (i=0;i<30;i++){
            /*if (count[array[i]] > maior){
                maior = count[array[i]];
                printf("%d\n",maior);
            }*/
            count[array[i]]++;
        }
        for (i=1;i<maior;i++){
            count[i] += count[i-1];
        }
        for (i=0;i<30;i++){
            ordenado[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }
        for (i=0;i<maior;i++){
            printf("%d\n",ordenado[i]);
        }
        vezes++;
    }
    fim = clock();
    //return tempo_final = (fim - inicio)/CLOCKS_PER_SEC;
}
