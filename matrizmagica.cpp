#include <stdio.h>
#define filas 3
#define columnas 3
//jose miguel ruiz marquez 180200
//matriz magica
void imprimirMatriz(int matriz[filas][columnas]) 
{
    for (int i = 0; i < filas; i++) 
    {
        for (int j = 0; j < columnas; j++) 
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int esMatrizMagica(int matriz[filas][columnas]) 
{
    int sumaFila = 0;
    for (int j = 0; j < columnas; j++) 
    {
        sumaFila += matriz[0][j];
    }

    for (int i = 1; i < filas; i++) 
    {
        int sumaActual = 0;
        for (int j = 0; j < columnas; j++) 
        {
            sumaActual += matriz[i][j];
        }
        if (sumaActual != sumaFila) 
        {
            return 0; 
        }
    }

    for (int j = 0; j < columnas; j++) 
    {
        int sumaActual = 0;
        for (int i = 0; i < filas; i++) 
        {
            sumaActual += matriz[i][j];
        }
        if (sumaActual != sumaFila) 
        {
            return 0; 
        }
    }

    int sumaDiagonalPrincipal = 0;
    for (int i = 0; i < filas; i++) 
    {
        sumaDiagonalPrincipal += matriz[i][i];
    }
    if (sumaDiagonalPrincipal != sumaFila) 
    {
        return 0; 
    }

    int sumaDiagonalSecundaria = 0;
    for (int i = 0; i < filas; i++) 
    {
        sumaDiagonalSecundaria += matriz[i][columnas - 1 - i];
    }
    if (sumaDiagonalSecundaria != sumaFila) 
    {
        return 0; 
    }
    return 1;
}

int main() 
{
    int matriz[filas][columnas];

    printf("Ingrese los valores de la matriz de 3x3:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz ingresada:\n");
    imprimirMatriz(matriz);

    int sumaDiagonalPrincipal = 0;
    for (int i = 0; i < filas; i++) 
    {
        sumaDiagonalPrincipal += matriz[i][i];
    }
    printf("\nSuma de la diagonal principal: %d\n", sumaDiagonalPrincipal);

    int sumaDiagonalSecundaria = 0;
    for (int i = 0; i < filas; i++) 
    {
        sumaDiagonalSecundaria += matriz[i][columnas - 1 - i];
    }
    printf("Suma de la diagonal secundaria: %d\n", sumaDiagonalSecundaria);

    if (esMatrizMagica(matriz)) 
    {
        printf("\nLa matriz es mágica :)\n");
    } else {
        printf("\nLa matriz no es mágica :(\n");
    }

    return 0;
}


