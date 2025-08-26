#include <stdio.h>

int main() {
    // -----------------------------
    // Cadastro das cartas
    // -----------------------------
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nomeCidade1[50], nomeCidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;

    // Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade1);
    printf("Digite a Populacao: ");
    scanf("%lu", &populacao1);
    printf("Digite a Area (em km2): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / populacao1;

    // Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Digite o Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade2);
    printf("Digite a Populacao: ");
    scanf("%lu", &populacao2);
    printf("Digite a Area (em km2): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / populacao2;

    // -----------------------------
    // Menus dinâmicos para escolher atributos
    // -----------------------------
    int opcao1, opcao2;
    float val1Carta1, val1Carta2, val2Carta1, val2Carta2;
    char nomeAttr1[30], nomeAttr2[30];

    // Primeiro atributo
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("Opcao: ");
    scanf("%d", &opcao1);

    switch(opcao1) {
        case 1: val1Carta1 = populacao1; val1Carta2 = populacao2; snprintf(nomeAttr1,30,"Populacao"); break;
        case 2: val1Carta1 = area1; val1Carta2 = area2; snprintf(nomeAttr1,30,"Area"); break;
        case 3: val1Carta1 = pib1; val1Carta2 = pib2; snprintf(nomeAttr1,30,"PIB"); break;
        case 4: val1Carta1 = pontosTuristicos1; val1Carta2 = pontosTuristicos2; snprintf(nomeAttr1,30,"Pontos Turisticos"); break;
        case 5: val1Carta1 = densidade1; val1Carta2 = densidade2; snprintf(nomeAttr1,30,"Densidade Demografica"); break;
        case 6: val1Carta1 = pibPerCapita1; val1Carta2 = pibPerCapita2; snprintf(nomeAttr1,30,"PIB per Capita"); break;
        default: printf("Opcao invalida!\n"); return 1;
    }

    // Segundo atributo
    printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
    for(int i=1;i<=6;i++){
        if(i!=opcao1){
            switch(i){
                case 1: printf("1 - Populacao\n"); break;
                case 2: printf("2 - Area\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turisticos\n"); break;
                case 5: printf("5 - Densidade Demografica\n"); break;
                case 6: printf("6 - PIB per Capita\n"); break;
            }
        }
    }
    printf("Opcao: ");
    scanf("%d", &opcao2);

    if(opcao2==opcao1 || opcao2<1 || opcao2>6){ 
        printf("Opcao invalida!\n"); 
        return 1;
    }

    switch(opcao2) {
        case 1: val2Carta1 = populacao1; val2Carta2 = populacao2; snprintf(nomeAttr2,30,"Populacao"); break;
        case 2: val2Carta1 = area1; val2Carta2 = area2; snprintf(nomeAttr2,30,"Area"); break;
        case 3: val2Carta1 = pib1; val2Carta2 = pib2; snprintf(nomeAttr2,30,"PIB"); break;
        case 4: val2Carta1 = pontosTuristicos1; val2Carta2 = pontosTuristicos2; snprintf(nomeAttr2,30,"Pontos Turisticos"); break;
        case 5: val2Carta1 = densidade1; val2Carta2 = densidade2; snprintf(nomeAttr2,30,"Densidade Demografica"); break;
        case 6: val2Carta1 = pibPerCapita1; val2Carta2 = pibPerCapita2; snprintf(nomeAttr2,30,"PIB per Capita"); break;
    }

    // -----------------------------
    // Comparação e soma dos atributos
    // -----------------------------
    float somaCarta1 = 0, somaCarta2 = 0;

    // Primeiro atributo
    if(opcao1==5){ // densidade: menor vence
        somaCarta1 += (val1Carta1 < val1Carta2) ? 1 : 0;
        somaCarta2 += (val1Carta2 < val1Carta1) ? 1 : 0;
    } else { // maior vence
        somaCarta1 += (val1Carta1 > val1Carta2) ? 1 : 0;
        somaCarta2 += (val1Carta2 > val1Carta1) ? 1 : 0;
    }

    // Segundo atributo
    if(opcao2==5){ // densidade: menor vence
        somaCarta1 += (val2Carta1 < val2Carta2) ? 1 : 0;
        somaCarta2 += (val2Carta2 < val2Carta1) ? 1 : 0;
    } else { // maior vence
        somaCarta1 += (val2Carta1 > val2Carta2) ? 1 : 0;
        somaCarta2 += (val2Carta2 > val2Carta1) ? 1 : 0;
    }

    // -----------------------------
    // Exibição do resultado
    // -----------------------------
    printf("\n--- Resultado da Comparacao ---\n");
    printf("Carta 1 - %s (%s):\n  %s = %.2f\n  %s = %.2f\n", nomeCidade1, codigo1, nomeAttr1, val1Carta1, nomeAttr2, val2Carta1);
    printf("Carta 2 - %s (%s):\n  %s = %.2f\n  %s = %.2f\n", nomeCidade2, codigo2, nomeAttr1, val1Carta2, nomeAttr2, val2Carta2);
    printf("\nSoma dos atributos vencedores: Carta 1 = %.0f, Carta 2 = %.0f\n", somaCarta1, somaCarta2);

    if(somaCarta1 > somaCarta2){
        printf("\nResultado final: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if(somaCarta2 > somaCarta1){
        printf("\nResultado final: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else{
        printf("\nResultado final: Empate!\n");
    }

    return 0;
}
