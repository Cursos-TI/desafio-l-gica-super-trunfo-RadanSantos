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
    printf("Digite o Estado da segunda carta: ");
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

    // Menu interativo para escolher o atributo
    int opcao;
    printf("\n=== Escolha o atributo para comprar ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    // Comparação com switch-case
    switch (opcao) {
        case 1:
        printf("\nComparando População:\n");
        printf("%s: %d hab | %s: &d hab\n", carta1.nomeCidade, carta1.populacao, carta2.nomeCidade, carta2.populacao);
        if (carta1.populacao > carta2.populacao)
        printf("Vencedor: %s\n", carta1.nomeCidade);
        else if (carta2.populacao > carta1.populacao)
        printf("Vencedor: %s\n", carta2.nomeCidade);
        else
        printf("Empate!\n");
        break;

        case 2:
        printf("\nComparando Área:\n");
        printf("%s: %.2f km²\n", carta1.nomeCidade, carta1.area, carta2.nomeCidade, carta2.area);
        if (carta1.area > carta2.area)
        printf("Vencedor: %s\n", carta1.nomeCidade);
        else if (carta2.area > carta1.area)
        printf("Vencedor: %s\n", carta2.nomeCidade);
        else
        printf("Empate!\n");
        break;

        case 3:
        printf("\nComparando PIB:\n");
        printf("%s %.2f bilhões | %s %.3f bilhões\n", carta1.nomeCidade, carta1.pib, carta2.nomeCidade, carta2.pib);
        if (carta1.pib > carta2.pib)
        printf("Vencedor: %s\n", carta1.nomeCidade);
        else if (carta2.pib > carta1.pib)
        printf("Vencedor :%s\n", carta2.nomeCidade);
        else
        printf("Empate!");
        break;

        case 4:
        printf("\nComparando Pontos Turísticos:\n");
        printf("%s: %d | %s: %d\n", carta1.nomeCidade, carta1.pontosTuristicos, carta2.nomeCidade, carta2.pontosTuristicos);
        if (carta1.pontosTuristicos > carta2.pontosTuristicos)
        printf("Vencedor: %s\n", carta1.nomeCidade);
        else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
        printf("Vencedor: %s\n", carta2.nomeCidade);
        else
        printf("Empate!\n");
        break;

        case 5:
        printf("\nComparando Densidade Populacional (menor vence):\n");
        printf("%s: %.2f hab/km² | %s: %.2f han/km²\n", carta1.nomeCidade, carta1.densidadePopulacional, carta2.nomeCidade, carta2.densidadePopulacional);
        if (carta1.densidadePopulacional < carta2.densidadePopulacional)
        printf("Vencedor: %s\n", carta1.nomeCidade);
        else if (carta2.densidadePopulacional < carta1.densidadePopulacional)
        printf("Vencedor: %s\n", carta2.nomeCidade);
        else
        printf("Empate!\n");
        break;

        default:
        printf("Opção inválida!\n");
        break;
    }
}

return 0;
}