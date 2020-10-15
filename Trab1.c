#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(int argn, char ** argv)
//argv – é um vetor de char que contém os argumentos, um para cada string passada na linha de comando
//int argn = numero de parametros passados
//char ** argc = array de array de caracteres com os parametros passados
{
    FILE * fp = fopen("a.txt", "r");         //ABRE O TXT
    if (!fp)                                     //CASO NÃO TENHA O TXT NÃO ABRE
        {
        printf("Não deu para abrir o arquivo\n");
        return 1;
        }

    int largura = 0;
    int altura = 0;
    int i , j;
    int matriz[largura][altura];
    fscanf(fp, "%d %d", &largura, &altura);
    printf("%d %d \n", largura, altura);
    for (i = 0; i <= largura; i++)
        {
            for(j = 0; j <=altura; j++)
            {
            printf ("matriz[%d][%d] = %d\n", i,j, i*10+j);
            matriz[largura][altura]=i*10+j;               //ESTOU TENTANDO ADICIONAR OS VALORES DENTRO DE CADA POSIÇÃO DA MATRIZ
            }
        }


    //NÃO ESTÁ SAINDO COMO DESEJADO.
    //COMO PEGAR OS VALORES E JOGAR DENTRO DE CADA VETOR DA MATRIZ?
    printf("\nMatriz gerada\n");
    for(i=0;i<largura;i++)
        {
            for(j=0;j<altura;j++)
            {
                printf("%d\t", matriz[largura][altura]);
            }
        printf("\n");
        }

    while (!feof(fp))
    {
        int x = 0;
        int y = 0;
        char direcao = '\0';
        fscanf(fp, "%d %d %c", &x, &y, &direcao);
        fgetc(fp);
        while (1)
        {
            char acao = fgetc(fp);
            if (acao == '\n' || acao == '\0' || acao == EOF)
            {
                break;
            }
            if (acao == 'L')
            {
                /*fazer alteração para caso o cursor estiver apontado para:
                N : virar para o W
                W : virar para o S
                S : virar para o E
                E : virar para o N
                */
                if (direcao == 'N')
                    direcao = 'W';
                else if (direcao == 'W')
                    direcao = 'S';
                else if (direcao == 'S')
                    direcao = 'E';
                else if (direcao == 'E')
                    direcao = 'N';
            }
            else if (acao == 'R')
            {
                /*fazer alteração para caso o cursor estiver apontado para:
                N : virar para o E
                E : virar para o S
                S : virar para o W
                W : virar para o N
                */
                if (direcao == 'N')
                    direcao = 'E';
                else if (direcao == 'E')
                    direcao = 'S';
                else if (direcao == 'S')
                    direcao = 'W';
                else if (direcao == 'W')
                    direcao = 'N';
            }
            else if (acao == 'M')
            {
                //fazer movimento
                //caso seja no eixo x (E,W) diminuir/aumentar altura
                //caso seja no eixo y (N,S) diminuir/aumentar largura
                if (direcao == 'N')
                    y = y++;
                else if (direcao == 'S')
                    y = y--;
                else if (direcao == 'E')
                    x = x++;
                else if (direcao == 'W')
                    x = x--;
            }
        }
        printf("%d %d %c\n", x, y, direcao);
    }

    fclose(fp);

    return 0;
}
