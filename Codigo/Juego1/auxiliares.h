
#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <QFile>

using namespace std;



#include <math.h>
double calcular_distancia(double x1, double y1, double x2 ,double y2);
double calc_angle(double x1, double y1, double x2 ,double y2);
void Cargar_datos(string name_file, list<vector<int>> *lista);
void Leer_paredes(string name_file, list<vector<int>> *lista);
int saltos(string name_file);
void Cargar_imagen(string ruta_archivo, map<int, string> *Imagenes);

#endif // AUXILIARES_H
