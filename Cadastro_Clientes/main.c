#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef     struct {
                char nome[30];
                char sexo;
                int idade;
                char data_nascimento[10];
                char doencas[100];
    }cliente;

cliente cadastrar_cliente();
void buscar_cliente();
void listar_cliente();
void excluir_cliente();
int total_cliente = 0;
cliente *lista_clientes;

int main()
{   lista_clientes = (cliente*)calloc(0,sizeof(cliente));
    int opcao, executar = 1;
    while(executar == 1){
        printf("\nselecione uma opção:\n "
                   "1-Cadastrar cliente.\t2-Buscar Cliente\n3-listar todos os clientes\t"
                   "4-Excluir um cliente\n5-Sair.\n");
        scanf("%d",&opcao);
        switch (opcao){
            case 1:
                lista_clientes = (cliente*)realloc(lista_clientes,total_cliente+1);
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
    total_cliente++;
    cliente dados;
    char nome[30];
    char sexo;
    int idade;
    char data[10];
    char doencas[100];
    printf("Insira o nome:");
    nome[30] = fgets(nome, sizeof(nome), stdin);
    strcpy(dados.nome, nome);
    fflush(stdin);
    printf("Data de nascimento:");
    scanf("%s",&data);
    strcpy(dados.data_nascimento,data);
    printf("Idade:");
    scanf("%d",&dados.idade);
    printf("Sexo:");
    scanf("%s",&dados.sexo);
    printf("Doenças:");
    scanf("%s",&doencas);
    strcpy(dados.doencas,doencas);
    return dados;
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
            printf("\nNome: %s\n", lista_clientes[i].nome);
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
            return;
        }
    }
    for (i=0;i<total_cliente-posicao;i++){
        lista_clientes[posicao+i]=lista_clientes[posicao+1+i];
    }
    total_cliente--;
    lista_clientes = (cliente*)realloc(lista_clientes,total_cliente*sizeof(cliente));
}
