#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;


void LeerRed(string name_file);
int saltos(string name_file);
int main()
{
    string nombre_archivo = "ArbolesPrueba.csv";
    LeerRed(nombre_archivo);
    return 0;
}
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
void LeerRed(string name_file)
{
    string linea;
    ifstream fin;
    string tipo, casillaX,casillaY, posX, posY;
    char delimitador = ';';
    int salto;
    salto = saltos(name_file);
    try{

        fin.open(name_file);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }
        getline(fin,linea); //ELIMINAR encabezdo

        for(int i = 1; i<salto;i++){
            getline(fin,linea);
            stringstream inputstringstream(linea); //convierte linea a sstream
            getline(inputstringstream,tipo,delimitador);
            getline(inputstringstream,casillaX,delimitador);
            getline(inputstringstream,casillaY,delimitador);
            getline(inputstringstream,posX,delimitador);
            getline(inputstringstream,posY,delimitador);
          
            cout << "ARBOL " << i << endl;
            cout << "\tTipo " << tipo << endl;
            cout << "\tcasillaX " << casillaX << endl;
            cout << "\tcasillaY " << casillaY << endl;
            cout << "\tposX " << posX << endl;
            cout << "\tposY " << posY << endl;
          
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
