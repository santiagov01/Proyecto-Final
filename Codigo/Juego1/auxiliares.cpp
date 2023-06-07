#include <auxiliares.h>
#include <QFile>

int saltos(string name_file){
    ifstream fin;
    int saltos = 0;
    try{

        fin.open(name_file);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }

        while(fin.good()){ //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                if(temp == '\n'){
                    saltos++;//contar saltos de linea (cantidad cursos)
                }

            }
        }
        fin.close();
        return saltos;
    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='2'){
            cout<<"Error al abrir el archivo para escritura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }
    return 1;


}
void Leer_paredes(string name_file, list<vector<int>>*lista){


    string linea;
    ifstream fin;
    string Inicialx, Inicialy,Finalx, Finaly;
    char delimitador = ';';
    int salto;
    salto = saltos(name_file);
    try{

        fin.open(name_file);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }
        getline(fin,linea); //ELIMINAR encabezdo

        for(int i = 1; i<=salto;i++){
            getline(fin,linea);
            stringstream inputstringstream(linea); //convierte linea a sstream
            getline(inputstringstream,Inicialx,delimitador);
            getline(inputstringstream,Inicialy,delimitador);
            getline(inputstringstream,Finalx,delimitador);
            getline(inputstringstream,Finaly,delimitador);

            vector<int> datos;
            datos.push_back(stoi(Inicialx));
            datos.push_back(stoi(Inicialy));
            datos.push_back(stoi(Finalx));
            datos.push_back(stoi(Finaly));

            lista->push_back(datos);
        }
        fin.close();


    }
    catch (char c){
        cout<<"Error # "<<c<<": ";

        if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }

}




void Cargar_datos(string name_file, list<vector<int>> *lista)
{
    string linea;
    ifstream fin;
    string tipo, casillaX,casillaY, posX, posY,Zvalue;
    char delimitador = ';';
    int salto;
    salto = saltos(name_file);
    try{

        fin.open(name_file);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }
        getline(fin,linea); //ELIMINAR encabezdo

        for(int i = 1; i<=salto;i++){
            getline(fin,linea);
            stringstream inputstringstream(linea); //convierte linea a sstream
            getline(inputstringstream,tipo,delimitador);
            getline(inputstringstream,casillaX,delimitador);
            getline(inputstringstream,casillaY,delimitador);
            getline(inputstringstream,posX,delimitador);
            getline(inputstringstream,posY,delimitador);
            getline(inputstringstream,Zvalue,delimitador);

            // Crear vector temporal y cargar datos
            vector<int> datos;
            datos.push_back(stoi(tipo));
            datos.push_back(stoi(posX));
            datos.push_back(stoi(posY));
            datos.push_back(stoi(Zvalue));

            // Agregar vector a la lista
            lista->push_back(datos);

            //En este espacio falta hacer un llamado a una función que agregue los elementos a una Qlist o map

        }
        fin.close();


    }
    catch (char c){
        cout<<"Error # "<<c<<": ";

        if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }

}
void Cargar_imagen(string ruta_archivo,
              map<int, string> *Imagenes)
{
    string linea;
    ifstream fin;
    string tipo,path;
    char delimitador = ';';
    int salto;
    salto = saltos(ruta_archivo);
    try{

        fin.open(ruta_archivo);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }

        for(int i = 1; i<=salto;i++){
            getline(fin,linea);
            stringstream inputstringstream(linea); //convierte linea a sstream
            getline(inputstringstream,tipo,delimitador);
            getline(inputstringstream,path,delimitador);
            (*Imagenes)[i]=path;
        }
        fin.close();


        }
        catch (char c){
            cout<<"Error # "<<c<<": ";

            if(c=='2'){
                cout<<"Error al abrir el archivo para lectura.\n";
            }
        }
        catch (...){
            cout<<"Error no definido\n";
        }

       }


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

