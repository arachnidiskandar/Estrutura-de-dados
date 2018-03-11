#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void busca_binaria(int array[30],int valor);
void busca_linear(int array[30],int  valor);
void busca_inter(int array[30],int valor);

int main()
{
   int array[30] = {2,4,6,7,8,10,11,12,14,16,18,20,22,24,25,26,28,30,32,34,36,38,39,40,42,44,46,48,49,50};
   busca_inter(array, 42);
   busca_binaria(array, 42);
   busca_linear(array, 42);
   return 0;
}

void busca_linear(int array[30],int valor){
    clock_t inicio, fim;
    double tempo_total;
    inicio = clock();
    int i = 0, qntd = 0;
    while (qntd<1000000000){
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
    tempo_total = (fim - inicio)/CLOCKS_PER_SEC;
    printf("Tempo Busca Linear: %.1f segundos.\n", tempo_total);
}
void busca_binaria(int array[30],int valor){
    clock_t inicio, fim;
    double tempo_total;
    inicio = clock();
    int qntd = 0;
    while (qntd<1000000000){
        int prim = 0, ult = 29, meio;
         meio = (ult + prim) >> 1;
        while (prim < ult) {
            if (array[meio] == valor){
                break;
            }
            else if (array[meio] < valor) {
                prim = meio + 1;
            }
            else{
                ult = meio - 1;
            }
            meio = (ult + prim) >> 1;
        }
        qntd += 1;
    }
    fim = clock();
    tempo_total = (fim - inicio)/CLOCKS_PER_SEC;
    printf("Tempo Busca Binária: %.1f segundos.\n", tempo_total);
}
void busca_inter(int array[30],int valor){
    clock_t inicio, fim;
    double tempo_total;
    inicio = clock();
    int esq = 0;
    int dir = 29;
    int meio;
    int qntd = 0;
    while (qntd<1000000000){
        while (esq < dir) {
            meio = esq + ((valor - array[esq]) * (dir - esq) / (array[dir] - array[esq]));
            if (array[meio] == valor){
                qntd +=1;
                break;
            }
            else if (array[meio] < valor){
                esq = meio + 1;
            }
            else{
                dir = meio - 1;
            }
        }
    }
    fim = clock();
    tempo_total = (fim - inicio)/CLOCKS_PER_SEC;
    printf("Tempo Busca Intercalada: %.1f segundos.\n", tempo_total);

}
