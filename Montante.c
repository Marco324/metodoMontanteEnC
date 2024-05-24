#include <stdio.h>
#define N 3

int main(){
    //Variables
    FILE *fpArchIn, *fpArchOut;
    int i, j, n, t, k;
    int piv = 1, Determinante;
    float x, y, z;
    int A[N][2*N+1] = {{0, 0, 0, 0, 1,0,0},
                       {0, 0, 0, 0, 0,1,0},
                       {0, 0, 0, 0, 0,0,1}};

    //Abrir archivos
    fpArchIn = fopen("datosEcuaciones3D.TXT", "rt");
    fpArchOut = fopen("Data.TXT", "wt");

    //Comprobacion de archivo
    if (fpArchIn == NULL){
        return 0;
    }

    while (!feof(fpArchIn)) {
        piv = 1;
        //Leer variables del archivo raices.TXT
        for (i=0; i<N; ++i){
            for (j=0; j<N+1; ++j) {
                fscanf(fpArchIn, "%d", &A[i][j]);
                } 
	    }

        //Imprime la matriz
        printf("Matriz %d\n", n);
        fprintf(fpArchOut, "Matriz %d\n", n);
        for (i=0; i<N; ++i){
            for (j=0; j<N+1; ++j) {
                printf ("%+3d ", A[i][j]);
                fprintf(fpArchOut, "%+3d ", A[i][j]);
            } 
		printf ("\n");
        fprintf(fpArchOut, "\n");
	    }

        // aplica Montante
        puts ("\naplicando el metodo Montante...");
        fprintf(fpArchOut, "\naplicando el metodo Montante...");
        for(i=0; i<N; i++) {
            for(j=0; j<N+1; j++){
                if(j!=i) {
                    t=A[j][i]; 
                    for(k=0;k<2*N+1;k++) A[j][k]=((A[i][i]*A[j][k])-(t*A[i][k]))/piv;
                }
            }
            piv=A[i][i];
        }
        Determinante = piv;

        // imprime los todos valores resueltos con Montante	
        puts ("\nSISTEMA RESUELTO MONTANTE");
        fprintf(fpArchOut, "\nSISTEMA RESUELTO MONTANTE\n");
        for (i=0; i<N; ++i){
            for (j=0; j<N+1; ++j){
                printf("%+7.2f ", (1.0*A[i][j]/Determinante));
                fprintf(fpArchOut, "%+7.2f ", (1.0*A[i][j]/Determinante));
            }
            printf ("\n");
            fprintf(fpArchOut, "\n");
        }

        //Impresion de la Determinante
        printf("\nDETERMINANTE = %d\n", Determinante);
        fprintf(fpArchOut, "\nDETERMINANTE = %d\n\n", Determinante);

        //Determinar valores de x, y y z
        x = (float)A[0][3] / A[0][0];
        y = (float)A[1][3] / A[1][1];
        z = (float)A[2][3] / A[2][2];

        printf("Valor de x: %6.2f\nValor de y: %6.2f\nValor de z: %6.2f\n\n", x, y, z);
        fprintf(fpArchOut, "Valor de x: %6.2f\nValor de y: %6.2f\nValor de z: %6.2f\n", x, y, z);
        fprintf(fpArchOut, "------------------------\n\n");
        ++n;
	}

    //Cerrar archivos
    fclose(fpArchIn);
    fclose(fpArchOut);
    
}