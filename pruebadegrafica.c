#include <stdio.h>
#include <complex.h>

int main (void){

    //si quiero graficar mis priopos puntos, se creara un archivos que es fpPuntos


    // FILE*popen("EJECUTABLE", "TIPO");
        //LLAMAR DE OTRA APLICACION

    // FILE*fp=popen("gnuplot -persist", "w");  w es para dacerlie que estare dandole informacion a w y r es que es solo lo voy a imprimir
    // fprintf(fp."comando valor \n");
        FILE*fp=popen("gnuplot -persist","w");
        fprintf(fp, "plot \"grafica.txt\" \n");
        fprintf(fp, "set title \"Curva de Imanacion Electrico U.S.S\"  \n");
        fprintf(fp, "set xlabel \"Campo Magnetico H, lenz (no relacionado)\" \n");
        fprintf(fp, "set ylabel \"Induccion Magnetica INTRISICA TESLAS\" \n");
        fprintf(fp, "replot \n");
        fprintf(fp, "plot \"\" u 1:2 smooth csplines \n");
        fclose(fp);


    return 0;
}