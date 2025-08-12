#include <stdio.h>
#include <string.h>

// Estrutura par armazenar os dados da carta
struct Carta {
    char estado[50];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

//Função para calcular densidade e PIB per capita
void calcularDados(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir os dados da carta
void exibirCarta(struct Carta carta) {
    printf("\nEstado: %s", carta.estado);
    printf("\nCódigo: %s", carta.codigo);
    printf("\nCidade: %s", carta.nomeCidade);
    printf("\nPopulação: %d", carta.populacao);
    printf("\nÁrea: %2.f km²", carta.area);
    printf("\nPIB: %.2f bilhões", carta.pib);
    printf("\nPontos Turísticos: %d", carta.pontosTuristicos);
    printf("\nDensidade Populacional: %.2f hab/km²", carta.densidadePopulacional);
    printf("\nPIB per Capita: %.2f\n", carta.pibPerCapita);
}

int main() {
    struct Carta carta1, carta2;

    // Entrada dos dados da primeira carta
    printf("Digite o Estado da primeira carta: ");
    scanf(" %[^\n]", carta1.estado);
    printf("Digite o Código da primeira carta: ");
    scanf(" %[^\n]", carta1.codigo);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("Digite a População: ");
    scanf("%d", &carta1.populacao);
    printf("Digite a Área: ");
    scanf("%f", &carta1.area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    calcularDados(&carta1);

    // Entrada dos dados da segunda carta
    printf("\nDigite o Estado da segunda carta: ");
    scanf(" %[^\n]", carta2.estado);
    printf("Digite o Código da segunda carta: ");
    scanf("%[^\n]", carta2.codigo);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("Digite a População: ");
    scanf("%d", &carta2.populacao);
    printf("Digite a Área (km²): ");
    scanf("%f", &carta2.area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    calcularDados(&carta2);

    // Exibição das cartas
    printf("\n--- Carta 1 ---");
    exibirCarta(carta1);
    printf("\n--- Carta2 2 ---");
    exibirCarta(carta2);

    // Comparação direta - exemplo udando População
    printf("\nComparando atributo: População\n");
    if (carta1.populacao > carta2.populacao) {
        printf("Carta 1 (%s) venceu com %d habitantes contea %d.\n",
        carta1.nomeCidade, carta1.populacao, carta2.populacao);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Carta 2 (%s) venceu com %d habitantes contra %d.\n",
        carta2.nomeCidade, carta2.populacao, carta1.populacao);
    } else {
        printf("Empate! Ambas as cartas têm %d habitantes.\n", carta1.populacao);
    }

    return 0;
}


