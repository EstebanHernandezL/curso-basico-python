#include <stdio.h>


int main (){

    float l,a,x,y,z,p,fa,lineasO,n; /* ESTOS SON LOS DATOS PRINCIPALES SOBRE LA LONGITUD Y EL NUMERO DE VUELTAS*/
    float GAUSS, TESLA=0.0001, Az, Bz, Hz, Uz, Lmz,Hy, Lmy,By, Py, Ay, Px, Pz, Bx, Ux, Lmx, Hx, fmm, I;  /*ESTOS SON LOS DATOS PARA PODER HACER LAS OPERACIONES O LAS QUE SE TIENEN QUE BUSCAR*/
    float Ltotal, Atotal;
    int menu, men, op=1;



    printf ("\tBIENVENIDO AL PROYECTO INTEGRADOR DE MAQUNAS ELECTRICAS\n");

    printf ("Por favor seleccione algunas de las opciones para conocer el proyecto o resolver el problema\n");
    printf ("1) PORTADA (DATOS DE LOS INTEGRANTES DEL EQUIPO\n");
    printf ("2) INFORMACION SOBRE EL PROBLEMA\n");
    printf ("3) RESOLVER EL PROBLEMA\n");
    printf ("4) SALIR DEL PROGRAMA\n");
    scanf ("%i",&menu);

    switch (menu)
    {
    case 1:
        printf ("\t\tUNIVERSIDAD AUTONOMA DE NUEVO LEON\n");
        printf ("\t\tFACULTAD DE INGENIERIA MECANICA Y ELECTRICA\n");
        printf ("\n\n");
        printf ("\t\tPRODUCTO INTEGRADOR DE APRENDIZAJE\n");
        printf ("\t\tCICLO ESCOLAR\n");
        printf ("\t\tENERO - JUNIO 2022\n");
        printf ("JESUS GUADALUPE MONSIVAIS BELMARES\n");
        printf ("ESTEBAN MOISES HERNANDEZ LOZA\n");
        printf ("DIEGO ORLANDO VALERO GOMEZ\n");
        printf ("ADRIAN GONZALEZ GARZA\n");

        break;

    case 2:
        printf ("PROBLEMA SOBRE NUCLEO DE TRES COLUMNAS\n");
        printf ("\n\n");
        printf ("El circuito Magnetico esta construido de material llamado acero electrico y tiene un factor de apilamiento de 0.9.\n");
        printf ("¿Que corriente se requiere en la bobina para establecer un Pz= 100, lineas en la rama extrema a la derecha o rama Z?\n");

        break;
    case 3:
        
        while (op==1)
        {
            system ("cls");   /* code */
        
        


        printf ("PORFAVOR DIGITE LOS DATOS PARA PODER RESOLVER EL PROBLEMA:  \n");
        
        printf ("DIGITE LA LONGITUD EN EL DATO L (el dato debe estar en METROS (m) ): \n  ");
        scanf ("%f", &l);

        printf ("DIGITE LA ALTURA EN EL DATO DE A: \n");
        scanf ("%f", &a);

        printf ("DIGITE LA LONGITUD EN EL DATO DE X: \n");
        scanf ("%f", &x);

        printf ("DIGITE LA LONGITUD EN EL DATO DE Y: \n");
        scanf ("%f", &y);

        printf ("DIGITE LA LONGITUD EN EL DATO DE Z: \n");
        scanf ("%f", &z);

        printf ("DIGITE LA LONGITUD EN EL DATO DE P: \n");
        scanf ("%f", &p);

        printf ("DIGITE EL FACTO DE APILAMIENTO (F.A): \n");
        scanf ("%f", &fa);

        printf ("DIGITE LA BOBINA: \n");  /* este el Pz*/
        scanf ("%f", &lineasO);

        printf ("DIGITE LOS N: \n");
        scanf ("%f", &n);
        
        Az=z*p*fa;
    
        Bz=lineasO/Az;

        printf ("EL Bz tiene un valor de: %f TESLAS\n", Bz);





        printf ("INGRESE EL VALOR DE Hz que se encuentra en la grafica: \n");
        scanf ("%f", &Hz);


        FILE*fp=popen("gnuplot -persist","w");
        fprintf(fp, "plot \"grafica.txt\" \n");
        fprintf(fp, "set title \"Curva de Imanacion Electrico U.S.S\"  \n");
        fprintf(fp, "set xlabel \"Campo Magnetico H, lenz (no relacionado)\" \n");
        fprintf(fp, "set ylabel \"Induccion Magnetica INTRISICA TESLAS\" \n");
        fprintf(fp, "replot \n");
        fprintf(fp, "plot \"\" u 1:2 smooth csplines \n");
        fclose(fp);



        /*INICIO LA PARTE PARA OBTENER EL 16.5 DE X y Y, se sabe que X es de anchura y Y DE altura pero en el ejericio z seria los 4cm de profundidad pero se toma en cuenta*/

        l*=100; /*se multiplica por 100 debido que desde un principio lo agregamos a metros pero aqui vamos a cm*/
        l/=2;/*AQUI SE DIVIDE ENTRE 2 SOBRE LA LOGITUD DEBIO QUE ES EL VALOR DE 16.5 RESTANDO LOS 2.5*/
        l-=2.5;

        printf ("Recordemos que lo dividimos entre 2 dado que uno es para el punto X y Y, ademas se le resta 2.5 debido que lo hacemos desde el centro de 5 que es el ancho que tiene\n");
        
        printf ("El valor de la LONGITUD PARA X y Y es de: %f\n\n",l);
        
        /*HASTA AQUI ES PROCEDIMIENTO PARA PODER OBTENER EL 16.5 DE X y Y ya que falta aun la altura que debe ser de 15*/

        a*=100;
        a-=5;

        printf ("LA ALTURA TOTAL es de: %f\n", a);

        printf ("Recordando que tambien se le resta 2.5 arriba y abajo\n");

        Lmz=l*2;
        Lmz+=a;

        printf ("El valor de Lmz es de: \n%f", Lmz);

        Lmz/=100;  /* al paracer se puede usar para Lmz, Lmx y Lmy, bueno ESTE FUE EL DATO QUE USE TAMBIEN PARA LA ULTIMA VEZ QUE SE USA QUE ES PARA LMZ*/

        Uz=Hz*Lmz;

        printf("El valor de Uz es de: %f A-v \n", Uz);

        printf ("Teniendo el valor de Uz recordemos que Uz=Uy\n");

        a/=100;

        Hy=Uz/a;

        printf ("El valor de Hy es de: %f Lenz \n\n", Hy);



        printf ("DIGITE EL VALOR DE BY: \n");
        scanf ("%f", &By);

        Az=z*p*fa;  /*Volvi a pegar la formula del area debido que asi pueda volver a hagarrar los valores guardados de z, p y fa que se ponen desde principio*/
        Py=By*Az;  /*segun en la formula es Ay pero tienen el mismo valor en las fotos, a no ser que cuando cambie las variales el profe sea destinto*/

        printf ("Valor de Py es de: %f\n", Py);

        Px=Py+lineasO; /*Lineas0 se expresa desde el principio como 0.001, desde el principio tiene que expresarse asi para que salga bien el resultado*/

        printf ("Valor de Px es de: %f wb \n", Px);

        Bx=Px/Az;  /*Aqui pasa lo mismo que con Ay se aplica la misma area entocnes en lo mismo para Az, Ax y Ay*/

        printf ("Valor de Bx es de:  %f Tesla\n", Bx);

        printf ("Ingrese el valor de Hx: \n");
        scanf ("%f", &Hx);

        Ux=Hx*Lmz;

        printf ("Valor de Ux: %f A-v \n", Ux);

    
        Uz=Hz*Lmz;
        I= Ux+Uz;
        I/=n;


        printf ("La corriente es de: %f A\n", I);

        printf ("\n\nEste es el fin del programa, \n Quieres volver a ejecutar el programa ?");
        printf ("\n 1.Si \n2. No\n Escriba 1 para si y 2 para no: ");
        scanf ("%d", &op);
        }

        system ("cls");
        printf("Muchas Gracias por utilizar el program");
        break;

    
    default:
        printf ("OPCION NO VALIDA, SELECCIONE UNA DE LAS QUE APRACE EN LA PANTALLA");

        break; 
    }


    return 0;
}