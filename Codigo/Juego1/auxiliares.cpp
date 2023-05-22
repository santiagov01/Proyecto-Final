#include "auxiliares.h"
#include <math.h>
double calcular_distancia(double x1, double y1, double x2 ,double y2){
    double dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    return dist;
}

double calc_angle(double x1, double y1, double x2 ,double y2){
    double dx = x2-x1;
    double dy = y1-y2;//IMPORTANTE!! Así funciona en el plano de coordenadas

    double ang = 0;
    if(dx!=0)ang= atan2(dy,dx);
    return ang;
}
