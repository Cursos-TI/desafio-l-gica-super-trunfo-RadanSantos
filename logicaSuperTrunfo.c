#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da carta
struct Carta {
    char estado[50];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular densidade e PIB per capita
void calcularDados(struct Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1e9) / c->populacao; // PIB per capita em reais
}

// Função para exibir atributos para escolha
void exibirMenuAtributos(int excluir) {
    printf("\n=== Escolha um atributo ===\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Populacional (menor vence)\n");
    if (excluir != 6) printf("6 - PIB per Capita\n");
}

// Função para obter valor do atributo
float obterValorAtributo(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadePopulacional;
        case 6: return c.pibPerCapita;
        default: return 0;
    }
}

// Função para imprimir nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área (km²)";
        case 3: return "PIB (bilhões)";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional (hab/km²)";
        case 6: return "PIB per Capita (R$)";
        default: return "Atributo inválido";
    }
}

int main() {
    struct Carta carta1 = {"SP", "SP01", "São Paulo", 12300000, 1521.0, 699.28, 50};
    struct Carta carta2 = {"RJ", "RJ01", "Rio de Janeiro", 6775561, 1182.3, 341.16, 35};

    calcularDados(&carta1);
    calcularDados(&carta2);

    int atr1, atr2;

    // Escolha do primeiro atributo
    exibirMenuAtributos(0);
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atr1);

    while (atr1 < 1 || atr1 > 6) {
        printf("Opção inválida! Escolha novamente: ");
        scanf("%d", &atr1);
    }

    // Escolha do segundo atributo (sem repetir)
    exibirMenuAtributos(atr1);
    printf("Escolha o segundo atributo: ");
    scanf("%d", &atr2);

    while (atr2 < 1 || atr2 > 6 || atr2 == atr1) {
        printf("Opção inválida ou repetida! Escolha novamente: ");
        scanf("%d", &atr2);
    }

    // Comparação atributo 1
    float v1_c1 = obterValorAtributo(carta1, atr1);
    float v1_c2 = obterValorAtributo(carta2, atr1);

    int vencedor1;
    if (atr1 == 5) // Densidade: menor vence
        vencedor1 = (v1_c1 < v1_c2) ? 1 : (v1_c2 < v1_c1 ? 2 : 0);
    else
        vencedor1 = (v1_c1 > v1_c2) ? 1 : (v1_c2 > v1_c1 ? 2 : 0);

    // Comparação atributo 2
    float v2_c1 = obterValorAtributo(carta1, atr2);
    float v2_c2 = obterValorAtributo(carta2, atr2);

    int vencedor2;
    if (atr2 == 5) // Densidade: menor vence
        vencedor2 = (v2_c1 < v2_c2) ? 1 : (v2_c2 < v2_c1 ? 2 : 0);
    else
        vencedor2 = (v2_c1 > v2_c2) ? 1 : (v2_c2 > v2_c1 ? 2 : 0);

    // Soma para decisão final
    float soma1 = v1_c1 + v2_c1;
    float soma2 = v1_c2 + v2_c2;

    int vencedorFinal = (soma1 > soma2) ? 1 : (soma2 > soma1 ? 2 : 0);

    // Exibição dos resultados
    printf("\n=== Resultados ===\n");
    printf("Atributo 1: %s\n", nomeAtributo(atr1));
    printf("%s: %.2f | %s: %.2f -> %s\n", carta1.nomeCidade, v1_c1, carta2.nomeCidade, v1_c2,
           vencedor1 == 1 ? carta1.nomeCidade : vencedor1 == 2 ? carta2.nomeCidade : "Empate");

    printf("Atributo 2: %s\n", nomeAtributo(atr2));
    printf("%s: %.2f | %s: %.2f -> %s\n", carta1.nomeCidade, v2_c1, carta2.nomeCidade, v2_c2,
           vencedor2 == 1 ? carta1.nomeCidade : vencedor2 == 2 ? carta2.nomeCidade : "Empate");

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f | %s: %.2f\n", carta1.nomeCidade, soma1, carta2.nomeCidade, soma2);

    if (vencedorFinal == 1)
        printf("Vencedor final: %s\n", carta1.nomeCidade);
    else if (vencedorFinal == 2)
        printf("Vencedor final: %s\n", carta2.nomeCidade);
    else
        printf("Empate!\n");

    return 0;
}
