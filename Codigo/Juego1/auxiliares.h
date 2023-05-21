
#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <QFile>

using namespace std;




void Cargar_datos(string name_file, list<vector<int>> *lista);
int saltos(string name_file);
void Cargar_imagen(string ruta_archivo, map<int, string> *Imagenes);

#endif // AUXILIARES_H
