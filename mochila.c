#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10  // Capacidade máxima da mochila

// -------------------------------------------------------------
// Struct Item: representa um item com nome, tipo e quantidade
// -------------------------------------------------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// -------------------------------------------------------------
// Funções obrigatórias
// -------------------------------------------------------------
void inserirItem(Item mochila[], int *total);
void removerItem(Item mochila[], int *total);
void listarItens(Item mochila[], int total);
void buscarItem(Item mochila[], int total);

// -------------------------------------------------------------
// Função principal
// -------------------------------------------------------------
int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU MOCHILA =====\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpar o buffer de entrada

        switch (opcao) {
            case 1:
                inserirItem(mochila, &total);
                listarItens(mochila, total);
                break;
            case 2:
                removerItem(mochila, &total);
                listarItens(mochila, total);
                break;
            case 3:
                listarItens(mochila, total);
                break;
            case 4:
                buscarItem(mochila, total);
                break;
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

// -------------------------------------------------------------
// Função: inserirItem()
// Permite cadastrar um novo item na mochila
// -------------------------------------------------------------
void inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\nA mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novoItem;

    printf("\nDigite o nome do item: ");
    fgets(novoItem.nome, sizeof(novoItem.nome), stdin);
    novoItem.nome[strcspn(novoItem.nome, "\n")] = '\0'; // remove o \n

    printf("Digite o tipo do item (ex: arma, municao, cura): ");
    fgets(novoItem.tipo, sizeof(novoItem.tipo), stdin);
    novoItem.tipo[strcspn(novoItem.tipo, "\n")] = '\0';

    printf("Digite a quantidade: ");
    scanf("%d", &novoItem.quantidade);
    getchar();

    mochila[*total] = novoItem;
    (*total)++;

    printf("\nItem '%s' adicionado com sucesso!\n", novoItem.nome);
}

// -------------------------------------------------------------
// Função: removerItem()
// Remove um item com base no nome informado
// -------------------------------------------------------------
void removerItem(Item mochila[], int *total) {
    if (*total == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item que deseja remover: ");
    fgets(nomeRemover, sizeof(nomeRemover), stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            for (int j = i; j < *total - 1; j++) {
                mochila[j] = mochila[j + 1]; // desloca os próximos
            }
            (*total)--;
            printf("\nItem '%s' removido com sucesso!\n", nomeRemover);
            return;
        }
    }

    printf("\nItem '%s' não encontrado!\n", nomeRemover);
}

// -------------------------------------------------------------
// Função: listarItens()
// Exibe todos os itens da mochila
// -------------------------------------------------------------
void listarItens(Item mochila[], int total) {
    if (total == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    printf("\n===== ITENS NA MOCHILA =====\n");
    for (int i = 0; i < total; i++) {
        printf("Item %d:\n", i + 1);
        printf("  Nome: %s\n", mochila[i].nome);
        printf("  Tipo: %s\n", mochila[i].tipo);
        printf("  Quantidade: %d\n", mochila[i].quantidade);
    }
    printf("=============================\n");
}

// -------------------------------------------------------------
// Função: buscarItem()
// Realiza busca sequencial por nome e exibe os dados do item
// -------------------------------------------------------------
void buscarItem(Item mochila[], int total) {
    if (total == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item para buscar: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado:\n");
            printf("  Nome: %s\n", mochila[i].nome);
            printf("  Tipo: %s\n", mochila[i].tipo);
            printf("  Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("\nItem '%s' não encontrado!\n", nomeBusca);
}
