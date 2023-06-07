#include <auxiliares.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
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
void Cargar_datos(string name_file, list<vector<int>> *lista)
{

    QFile file(QString::fromStdString(name_file));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo";
        return;
    }
    int tipo, posx, posy, zvalue;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(';'); //divide de una vez en una lista
        vector<int> datos;
        int j = 0;
//        tipo = parts[0].toInt();
//        posx = parts[3].toInt();
//        posy = parts[4].toInt();
        for (const QString& part : parts) {

            switch (j) {
            case 0:
                tipo  = part.toInt();
                break;
            case 3:
                posx = part.toFloat();
                break;
            case 4:
                posy = part.toFloat();
                break;
            case 5:
                zvalue = part.toFloat();
                break;
            default:
                break;
            }
            j++;
        }
        datos.push_back(tipo);
        datos.push_back(posx);
        datos.push_back(posy);
        datos.push_back(zvalue);
        lista->push_back(datos);
    }
    file.close();

}
void Cargar_datos_enemigo(string name_file,  map<int,vector<QString>> *mapa)
{
    //guardará los datos de todos los enemigos en una mapa de vectores
    //1:enemigo que persigue
    //2:enemigo que describe trayectoria parametrica
    //3:enemigo " " " circular con proyectiles a su alrededor
    //4: enemigo que está en un rango
    QFile file(QString::fromStdString(name_file));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo";
        return;
    }
    //int tipo, posx, posy;
    QTextStream in(&file);
    int j = 1;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(';'); //divide de una vez en una lista
        vector<QString> datos;

//        tipo = parts[0].toInt();
//        posx = parts[3].toInt();
//        posy = parts[4].toInt();
        for (const QString& part : parts) {

            datos.push_back(part);

        }

        (*mapa)[j] = datos;
        j++;
    }
    file.close();

}
void Leer_paredes(string name_file, list<vector<int>>*lista){

    QFile file(QString::fromStdString(name_file));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo";
        return;
    }
    int Inicialx, Inicialy,Finalx, Finaly;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(';'); //divide de una vez en una lista
        vector<int> datos;
        int j = 0;
        for (const QString& part : parts) {

            switch (j) {
            case 0:
                Inicialx  = part.toInt();
                break;
            case 1:
                Inicialy = part.toInt();
                break;
            case 2:
                Finalx = part.toInt();
                break;
            case 3:
                Finaly = part.toInt();
                break;
            default:
                break;
            }
            j++;
        }
        datos.push_back((Inicialx));
        datos.push_back((Inicialy));
        datos.push_back((Finalx));
        datos.push_back((Finaly));

        lista->push_back(datos);
    }
    file.close();
}
void Cargar_imagen(string ruta_archivo,
              map<int, string> *Imagenes)
{
    QFile file(QString::fromStdString(ruta_archivo));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo";
        return;
    }
    QTextStream in(&file);
    int i = 0;

    string path;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(';');
        int j = 0;
        for (const QString& part : parts) {
            if(j == 1){
                //std::cout << part.toStdString() << std::endl;
                path = part.toStdString();
            }
            j++;
        }
        i++;
        //path = parts[1].toStdString();
        (*Imagenes)[i]=path;

    }
    file.close();
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

