#include "Utility.h"
#include <algorithm>
#include <clocale>

// Verifica la entrada
int getMenuInput() {
    int op;
    string input;

    cout << "Opción: ";
    cin >> input;

    if (!input.empty() && all_of(input.begin(), input.end(), ::isdigit)) {
        stringstream ObjOp(input);
        ObjOp >> op;
        return op;
    }
}

// Menú del modo persistente
void persistentModeMenu(Utility *U, string intro) {
    bool loopP = true;
    string optionsP = "Menú:\n1. Iniciar/Continuar con el registro\n2. Consultar estadísticas acumuladas\n3. Volver\n";

    while (loopP) {
        system("cls");
        cout << intro << optionsP;

        switch (getMenuInput()) {
            case 1:         // Iniciar/Continuar con el registro
                U->keylogger();
                U->addRtoDB();
                U->exportDB();
                loopP = false;
                break;
            case 2:         // Consultar estadisticas acumuladas
                U->readDB();
            case 3:         // Volver
                loopP = false;
            default: 
                system("cls"); 
                break;
        }
    }
}

void help() {
    string help =
        "Nombre del programa: SmartLogger\nAutor: Anton Ledo\nÚltima fecha de modificación: 25 de Marzo del 2020\n\nInformación:\n"
        "SmartLogger es una aplicación que permite generar estadísticas sobre las pulsaciones del teclado.\n"
        "Sus modos de operación son:\n"
        "\t- Modo Live -> Se activa automáticamente el detector de pulsaciones y, posteriormente,\n"
        " genera un estadístico sobre los datos registrados tras presionar [ESC]. En este modo las\n"
        " estadísticas no serán guardadas y solo podrán ser visibles en ese momento.\n"
        "\t- Modo Live con registro -> Similiar al Modo Live, genera un archivo al finalizar el\n"
        " registro de pulsaciones. El archivo se identifica con la fecha y hora de creación.\n"
        "\t- Modo persistente -> El más completo de todos, si es la primera vez que se ejecuta,\n"
        " generará un archivo de registro y las próximas veces que se ejecute, actualizará sus valores\n"
        " con las nuevas pulsaciones. Al guardar un registro actualizable, permite generar estadísticas\n"
        " más completas. Dentro de este modo se podrá iniciar o continuar con el registro, y consultar\n"
        " las estadísticas acumuladas del archivo 'log_DB.txt'.\n\n"
        "Todos los registros se guardarán en el mismo directorio donde se encuentre el programa, y de la\n"
        "misma forma, solo podrán ser leídos si se encuentran en el directorio del programa.\n\n"
        "(!)AVISO: En ningún caso modifique el archivo de registro 'log_DB.txt', de lo contrario causará un\n"
        "error en el programa. Si desea eliminar el registro acumulado simplemente elimine el archivo o\n"
        "cambie su nombre.\n";

    system("cls");
    cout << help << endl;
    system("pause");
}

// Menú principal
int main() {
    bool loop = true;
    setlocale(LC_ALL, "es_ES");
    string intro="\n*******************************************************\n" 
        "********************* SmartLogger *********************\n"
        "*******************************************************\n";
    string options = "Menú:\n1. Modo Live\n2. Modo Live con registro\n3. Modo Persistente\n4. Ayuda\n5. Salir\n";

    while (loop) {
        Utility* U;
        Utility utility;
        U = &utility;
        system("cls");
        cout << intro << options;

        switch (getMenuInput()) {
            case 1:         // Modo Live
                U->keylogger();
                U->readR();
                break;
            case 2:         // Modo Live con Registro
                U->keylogger();
                U->readR();
                U->exportR();
                break;
            case 3:         // Modo Persistente
                persistentModeMenu(U, intro);
                break;
            case 4:         // Ayuda
                help();
                break;
            case 5:         // Salir
                loop = false;
            default:
                system("cls");
                break;
        }
        U->~Utility();
    }

    return 0;
}