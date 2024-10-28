/*
    En un archivo disponemos de las cotas de altitud prodecentes de la digitalizacion de un
    terreno realizada mediante fotografia aerea. Este archivo tiene una cabecera que se ajusta al
    siguietne formato:

    typedef struct
    {
        unsigned int total_cotas_eje_x;
        unsigned int total_cotas_eje_y;
        float resolucion; //en m
    }cabecera;

    El resto de la información del archivo esta constituida por las cotas de altitud, en metros,
    cada una de las cuales es un numero float.

    Por ejemplo, si hemos digitalizado un terreno de 20km de ancho por 10km de largo, con una
    resolucion de 100 m de separacion entre cotas, los datos de la cabera del archivo seran:

    total de cotas del eje x = 201;
    total de cotas del eje y = 101;
    resolucion=100.0;

    A continuacion vendran un total de 201x101 =20.301 cotas de altitud.

    Se pide realizar un programa que pida el nombre de un archivo con el formato anterior y 
    presente por pantalla:

    -Ancho y largo en metros, del terreno digitalizado
    -Alturas maxima, minima y media, en metros, del terreno digitalizado
*/