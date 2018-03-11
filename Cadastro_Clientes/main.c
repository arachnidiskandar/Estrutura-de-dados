#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2
typedef     struct {
                char *nome;
                char sexo;
                int idade;
                char *data_nascimento;
                char *doencas;
    }cliente;

cliente cadastrar_cliente();
void buscar_cliente();
void listar_cliente();
void excluir_cliente();
int total_cliente = 0;
cliente lista_clientes[MAX];

int main()
{
    int opcao, executar = 1;
    while(executar == 1){
        printf("selecione uma opção:\n "
                   "1-Cadastrar cliente.\t2-Buscar Cliente\n3-listar todos os clientes\t"
                   "4-Excluir um cliente\n5-Sair.");
        scanf("%d",&opcao);
        switch (opcao){
            case 1:
                lista_clientes[total_cliente] = cadastrar_cliente();
                break;
            case 2:
                buscar_cliente();
                break;
            case 3:
                listar_cliente();
                break;
            case 4:
                excluir_cliente();
                break;
            case 5:
                executar = 0;
                break;
        }
    }
}
cliente cadastrar_cliente(){
    if (total_cliente>= MAX){
        printf("Maxima capacidade de cadastros atingido.");
    }
    else{
      cliente dados;
        dados.nome = "Augusto";
        dados.idade = 15;
        dados.doencas = "cancer";
        dados.sexo = "M";
        dados.data_nascimento = "09/11/1998";
        /*printf("Insira o nome:");
        scanf("%s",&dados.nome);
        printf("Data de nascimento:");
        scanf("%s",&dados.data_nascimento);
        dados.doencas = "Cancer";
        printf("Idade:");
        scanf("%d",dados.idade);
        printf("Sexo:")
        scanf("%c",dados.sexo);
        total_cliente += 1;*/
        total_cliente += 1;
        return dados;

    }
}
void buscar_cliente(){
    char nome_buscado[30];
    int i;
    printf("Nome do cliente:");
    scanf("%s",&nome_buscado);
    for (i=0;i<total_cliente;i++){
        if (strcmp(lista_clientes[i].nome, nome_buscado) == 0){
            printf("Cliente encontrado.\n\n");
            printf("Nome: %s\n", lista_clientes[i].nome);
            printf("Idade: %d\n", lista_clientes[i].idade);
            printf("Sexo: %c\n", lista_clientes[i].sexo);
            printf("Data de Nascimento: %s\n", lista_clientes[i].data_nascimento);
            printf("Doenças: %s\n", lista_clientes[i].doencas);
        }
        else{
            printf("Cliente não encontrado.");
        }
    }
}
void listar_cliente(){
    int i;
    if (total_cliente > 0){
        for (i=0;i<total_cliente;i++){
            printf("Nome: %s\n", lista_clientes[i].nome);
            printf("Idade: %d\n", lista_clientes[i].idade);
            printf("Sexo: %c\n", lista_clientes[i].sexo);
            printf("Data de Nascimento: %s\n", lista_clientes[i].data_nascimento);
            printf("Doenças: %s\n", lista_clientes[i].doencas);
        }
    }
    else{
        printf("Não há clientes cadastrados ainda.");
    }
}
void excluir_cliente(){
    char nome_buscado[30];
    int i,posicao;
    printf("Nome do cliente:");
    scanf("%s",&nome_buscado);

    for (i=0;i<total_cliente;i++){
        if (strcmp(lista_clientes[i].nome, nome_buscado) == 0){
            posicao = i;
        }
        else{
            printf("Cliente não encontrado.");
        }
    for (i=0;i<total_cliente-posicao;i++){
        lista_clientes[posicao]=lista_clientes[posicao+1];
        }
    }
}

