#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// PROPOSTA PARA DEIXA OS JOGO MAIS DIMANICO E DIVERTIDO SEM AFETAR O DESAFIO EXIGIDO
// DEFINIÇÃO DA ESTRUTURA DAS VARIAVEIS DE ATRIBUTOS DAS CIDADES
typedef struct
{
    char nome[30];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibCapita;
} Cidade;

// ARRAYS COM 5 CIDADES DE CADA ESTADO DO SUDESTE PARA SORTEIO ALEATORIO
Cidade cidadesSP[5] = {
    {"São Paulo", 12300000, 1521.11, 730.0, 15, 8083.0, 59268.3},
    {"Campinas", 1214000, 795.7, 65.0, 8, 1525.0, 5352.9},
    {"Santos", 433000, 280.7, 25.0, 10, 1542.0, 5773.2},
    {"São Bernardo", 844000, 409.5, 30.0, 6, 2061.0, 3553.1},
    {"Ribeirão Preto", 711000, 650.9, 28.0, 7, 1092.0, 3936.6}};

Cidade cidadesRJ[5] = {
    {"Rio de Janeiro", 6748000, 1182.3, 340.0, 20, 5707.0, 5040.2},
    {"Niterói", 515000, 133.9, 18.0, 9, 3846.0, 3495.1},
    {"Petrópolis", 306000, 795.8, 9.0, 12, 384.6, 2941.2},
    {"Volta Redonda", 273000, 182.8, 7.5, 5, 1493.0, 2747.3},
    {"Campos dos Goytacazes", 507000, 4032.0, 12.0, 6, 125.7, 2366.7}};

Cidade cidadesMG[5] = {
    {"Belo Horizonte", 2532000, 331.4, 105.0, 10, 7639.0, 4147.8},
    {"Uberlândia", 706000, 411.3, 20.0, 7, 1717.0, 2832.4},
    {"Contagem", 670000, 195.2, 15.0, 4, 3432.0, 2238.8},
    {"Juiz de Fora", 577000, 1430.6, 10.0, 6, 403.4, 1733.4},
    {"Montes Claros", 413000, 3568.0, 6.5, 5, 115.8, 1573.6}};

Cidade cidadesES[5] = {
    {"Vitória", 365000, 93.4, 15.0, 10, 3908.0, 4109.6},
    {"Vila Velha", 501000, 210.2, 10.0, 8, 2383.0, 1996.0},
    {"Serra", 527000, 553.2, 12.0, 6, 952.6, 2277.6},
    {"Cariacica", 398000, 280.9, 8.0, 4, 1416.0, 2010.1},
    {"Guarapari", 126000, 592.0, 3.5, 7, 212.8, 2777.8}};

// VARIAVEL AUXILIAR PARA ACESSAR AS INFORMAÇÕES DOS ESTADOS
Cidade *estados[4] = {cidadesSP, cidadesRJ, cidadesMG, cidadesES};
// VARIAVEL QUE DEFINE A UF SEGUINDO O MESMO INDICE DA VARIAVEL ESTADOS PARA QUE CONSEGUIMOS IDENTIFICAR AS CIDADES CORRETAMENTE
char *siglasEstados[4] = {"SP", "RJ", "MG", "ES"};

//  FUNÇÃO AUXILAR PARA COMPARAÇÃO DE ATIBUTOS
void compara(const char *atributo, double dadosCarta1, const char *uf1, double dadosCarta2, const char *uf2, int *c1, int *c2)
{
    // PRINTFS REDUNDANTES SÓ MUDA O ATRIBUTO
    printf("%s\n", atributo);
    printf("Carta 1: %s: %.2f\n", uf1, dadosCarta1);
    printf("Carta 2: %s: %.2f\n", uf2, dadosCarta2);

    // PRIMEIRO VERIFICA SE NÃO E UM EMPATE
    if (dadosCarta1 == dadosCarta2)
    {
        printf("Resultado: Empate!\n");
    }
    else
    {
        // VERIFICA QUAL SINAL DEVEMOS USAR PARA MONTAR O SE
        int comparar = strcmp(atributo, "Atributo Selecionado: Densidade Populacional") == 0
                           ? dadosCarta1 < dadosCarta2
                           : dadosCarta1 > dadosCarta2;
        if (comparar)
        {
            printf("Resultado: Carta 1: %s Venceu!\n", uf1);
            (*c1)++;
        }
        else
        {
            printf("Resultado: Carta 2: %s Venceu!\n", uf2);
            (*c2)++;
        }
    }
}

int main()
{
    // FUNÇÃO PARA GERAR NUMEROS RANDÔMICOS
    srand(time(NULL));

    // VARIAVEIS PARA O MENU
    int opcao1, opcao2, aposta;
    // VARIAVEIS PARA DEFINIR GANHADOR
    int c1 = 0, c2 = 0;
    float soma1 = 0.00, soma2 = 0.00;
    // VARIAVEL RANDÔMICA PARA DEFINIR O ESTADO DA CARTA 1
    int indiceEstado1 = rand() % 4;
    // VARIAVEL RANDÔMICA PARA DEFINIR A CIDADE DA CARTA 1
    int indiceCidade1 = rand() % 5;
    // DEFINI OS INDICES DENTRO DOS ARRAYS PARA A CARTA 1
    Cidade carta1 = estados[indiceEstado1][indiceCidade1];

    // VARIAVEL RANDÔMICA PARA DEFINIR O ESTADO DA CARTA 2
    int indiceEstado2 = rand() % 4;
    // VARIAVEL RANDÔMICA PARA DEFINIR A CIDADE DA CARTA 2, AQUI TEMOS UMA VERIFICAÇÃO TERNARIA, POIS O INDICE 2 NÃO PODE SER IGUAL AO INDICE 1
    int indiceCidade2 = (rand() % 4 == indiceCidade1) ? 4 : rand() % 4;
    // DEFINI OS INDICES DENTRO DOS ARRAYS PARA A CARTA 2
    Cidade carta2 = estados[indiceEstado2][indiceCidade2];

    // BREVE EXPLICAÇÃO DO JOGO
    printf("\nBem Vindo ao SUPER TRUNFO! \n\nCom o intuito de deixar o jogo mais dinâmico as cartas serão preenchidas de forma automática. \n\nEspero que se Divirta! \n\n");

    // MENU INICIAL
    printf("Escolha o primeiro atributo:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per capita\n");
    scanf("%d", &opcao1);

    // VALIDA SE ESTÁ DENTRO DO PERMITIDO
    if (opcao1 < 1 || opcao1 > 6)
    {
        printf("Opção inválida. Encerrando...\n");
        return 1;
    }

    // SEGUNDO MENU DINAMICO EXCLUIDO A OPÇÃO SELECIONADA NO PRIMEIRO MENU
    printf("\nEscolha o segundo atributo:\n");
    switch (opcao1)
    {
    case 1:
        printf("2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per capita\n");
        break;
    case 2:
        printf("1. População\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per capita\n");
        break;
    case 3:
        printf("1. População\n2. Área\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per capita\n");
        break;
    case 4:
        printf("1. População\n2. Área\n3. PIB\n5. Densidade Populacional\n6. PIB per capita\n");
        break;
    case 5:
        printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n6. PIB per capita\n");
        break;
    case 6:
        printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n");
        break;
    }

    scanf("%d", &opcao2);

    // VALIDA SE ESTÁ DENTRO DO PERMITIDO E SE E DIFERENTE DO PRIMEIRO
    if (opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1)
    {
        printf("Opção inválida. Encerrando...\n");
        return 1;
    }

    // MENU DA SORTE ONDE VOCÊ APOSTA EM QUAL CARTA VAI GANHAR
    printf("\nHora de testar a sorte, qual carta você acha que vai ganhar?\n");
    printf("1. para Carta N°1\n2. para Carta N°2\n");
    scanf("%d", &aposta);
    switch (aposta)
    {
    case 1:
        printf("Carta N°1 Selecionada\n");
        break;
    case 2:
        printf("Carta N°2 Selecionada\n");
        break;
    default:
        printf("Opção inválida. Tente novamente.\n");
        return 1;
    }

    printf("\nHORA DO COMPARATIVO!\n\n");

    printf("CARTA 1\n");
    printf("Estado: %s\n", siglasEstados[indiceEstado1]);
    printf("Cidade: %s\n", carta1.nome);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta1.pibCapita);

    printf("\nCARTA 2\n");
    printf("Estado: %s\n", siglasEstados[indiceEstado2]);
    printf("Cidade: %s\n", carta2.nome);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta2.pibCapita);

    // COMPARATIVO 1
    printf("\nComparativo para primeira opção selecionada:\n\n");
    switch (opcao1)
    {
    case 1:
        compara("Atributo Selecionado: População", (double)carta1.populacao, siglasEstados[indiceEstado1], (double)carta2.populacao, siglasEstados[indiceEstado2], &c1, &c2);
        soma1 += carta1.populacao;
        soma2 += carta2.populacao;
        break;
    case 2:
        compara("Atributo Selecionado: Área", (double)carta1.area, siglasEstados[indiceEstado1], (double)carta2.area, siglasEstados[indiceEstado2], &c1, &c2);
        soma1 += carta1.area;
        soma2 += carta2.area;
        break;
    case 3:
        compara("Atributo Selecionado: PIB", (double)carta1.pib, siglasEstados[indiceEstado1], (double)carta2.pib, siglasEstados[indiceEstado2], &c1, &c2);
        soma1 += carta1.pib;
        soma2 += carta2.pib;
        break;
    case 4:
        compara("Atributo Selecionado: Pontos Turísticos", (double)carta1.pontosTuristicos, siglasEstados[indiceEstado1], (double)carta2.pontosTuristicos, siglasEstados[indiceEstado2], &c1, &c2);
        soma1 += carta1.pontosTuristicos;
        soma2 += carta2.pontosTuristicos;
        break;
    case 5:
        compara("Atributo Selecionado: Densidade Populacional", (double)carta1.densidadePopulacional, siglasEstados[indiceEstado1], (double)carta2.densidadePopulacional, siglasEstados[indiceEstado2], &c1, &c2);
        soma1 += carta1.densidadePopulacional;
        soma2 += carta2.densidadePopulacional;
        break;
    case 6:
        compara("Atributo Selecionado: PIB per Capita", (double)carta1.pibCapita, siglasEstados[indiceEstado1], (double)carta2.pibCapita, siglasEstados[indiceEstado2], &c1, &c2);
        soma1 += carta1.pibCapita;
        soma2 += carta2.pibCapita;
        break;
    }

    // COMPARATIVO 2
    printf("\nComparativo para segunda opção selecionada:\n\n");
    switch (opcao2)
    {
    case 1:
        compara("Atributo Selecionado: População", (double)carta1.populacao, siglasEstados[indiceEstado1], (double)carta2.populacao, siglasEstados[indiceEstado2], &c1, &c2);
        soma1 += carta1.populacao;
        soma2 += carta2.populacao;
        break;
    case 2:
        compara("Atributo Selecionado: Área", (double)carta1.area, siglasEstados[indiceEstado1], (double)carta2.area, siglasEstados[indiceEstado2], &c1, &c2);
        soma1 += carta1.area;
        soma2 += carta2.area;
        break;
    case 3:
        compara("Atributo Selecionado: PIB", (double)carta1.pib, siglasEstados[indiceEstado1], (double)carta2.pib, siglasEstados[indiceEstado2], &c1, &c2);
        soma1 += carta1.pib;
        soma2 += carta2.pib;
        break;
    case 4:
        compara("Atributo Selecionado: Pontos Turísticos", (double)carta1.pontosTuristicos, siglasEstados[indiceEstado1], (double)carta2.pontosTuristicos, siglasEstados[indiceEstado2], &c1, &c2);
        soma1 += carta1.pontosTuristicos;
        soma2 += carta2.pontosTuristicos;
        break;
    case 5:
        compara("Atributo Selecionado: Densidade Populacional", (double)carta1.densidadePopulacional, siglasEstados[indiceEstado1], (double)carta2.densidadePopulacional, siglasEstados[indiceEstado2], &c1, &c2);
        soma1 += carta1.densidadePopulacional;
        soma2 += carta2.densidadePopulacional;
        break;
    case 6:
        compara("Atributo Selecionado: PIB per Capita", (double)carta1.pibCapita, siglasEstados[indiceEstado1], (double)carta2.pibCapita, siglasEstados[indiceEstado2], &c1, &c2);
        soma1 += carta1.pibCapita;
        soma2 += carta2.pibCapita;
        break;
    }

    printf("\nComparativo Final soma dos atributos selecionados:\n\n");
    compara("Soma dos Atributo:", (double)soma1, siglasEstados[indiceEstado1], (double)soma2, siglasEstados[indiceEstado2], &c1, &c2);

    printf("\nResultado Final:\n");
    if (c1 > c2)
    {
        printf("Carta 1: %s é a vencedora do duelo!\n", siglasEstados[indiceEstado1]);
        if (aposta == 1)
        {
            printf("Aposta certeira, parabéns!");
        }
        else
        {
            printf("Não foi dessa vez quem sabe na próxima!");
        }
    }
    else
    {
        printf("Carta 2: %s é a vencedora do duelo!\n", siglasEstados[indiceEstado2]);
        if (aposta == 2)
        {
            printf("Aposta certeira, parabéns!");
        }
        else
        {
            printf("Não foi dessa vez quem sabe na próxima!");
        }
    }

    printf("\nObrigado por jogar!\n");

    return 0;
}
