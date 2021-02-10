#include<stdio.h>
#include<string.h>

int contem(char frase[150], char caract[][50], int qtd){
    for(int i=0; i<qtd; i++){
        if(strstr(frase, caract[i]) == NULL){
            return 0;
        }
    }
    return 1;
}

int main(void) {

    char caminho[100];
    printf("Insira o caminho do bd: ");
    scanf("%s",caminho);
    FILE *file;
    file = fopen(caminho,"r");
    if (file == NULL){
        printf("Caminho invalido");
        return 0;
    }

    int qtd_pcs;
    printf("Insira a quantidade de palavras-chave: ");
    scanf("%i", &qtd_pcs);
    char pcs[qtd_pcs][50];
    for(int c=0; c<qtd_pcs; c++){
        printf("%i Insira a palavra-chave: ",c+1);
        scanf("%s",pcs[c]);
    }

    FILE *file_resultados;
    char caminho_resultados[] = "resultados.txt";
    file_resultados = fopen(caminho_resultados,"w");

    int resultado;
    int contador;
    char linha[150];
    printf("Pesquisando [...]\n");
    while(fgets(linha, 150, file) != NULL) {
        resultado = contem(linha, pcs, qtd_pcs);
        if( resultado == 1 ){
            printf("%s",linha);
            fprintf(file_resultados, "%s", linha);
            contador = contador + 1;
        }
    }

    fclose(file);
    fclose(file_resultados);
    printf("%i resultado(s) salvo(s) em %s. Fim!\n",contador,caminho_resultados);
    system("pause");
    return 0;
}

