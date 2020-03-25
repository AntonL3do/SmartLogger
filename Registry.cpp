#include "Registry.h"

// Constructor, inicializa la db
Registry::Registry() {
    this->db = {
        {0x30,0},   // 0
        {0x31,0},   // 1
        {0x32,0},   // 2
        {0x33,0},   // 3
        {0x34,0},   // 4
        {0x35,0},   // 5
        {0x36,0},   // 6
        {0x37,0},   // 7
        {0x38,0},   // 8
        {0x39,0},   // 9
        {0x41,0},   // A
        {0x42,0},   // B
        {0x43,0},   // C
        {0x44,0},   // D   
        {0x45,0},   // E
        {0x46,0},   // F
        {0x47,0},   // G
        {0x48,0},   // H
        {0x49,0},   // I
        {0x4A,0},   // J
        {0x4B,0},   // K
        {0x4C,0},   // L
        {0x4D,0},   // M
        {0x4E,0},   // N
        {0x4F,0},   // O
        {0x50,0},   // P
        {0x51,0},   // Q
        {0x52,0},   // R
        {0x53,0},   // S
        {0x54,0},   // T
        {0x55,0},   // U
        {0x56,0},   // V
        {0x57,0},   // W
        {0x58,0},   // X
        {0x59,0},   // Y
        {0x5A,0}    // Z
    };
}

// Destructor
Registry::~Registry() {
}

// Retorna la db
map<int, int> Registry::getDB() {
    return this->db;
}

// Iguala la db a la del parámetro M
void Registry::setDB(Registry *M) {
    this->db = M->getDB();
}

// Modifica la db con los parátros de 'key' y 'value'
void Registry::setDB(char K, int V) {
    this->db.at(K) = {V};
}

// Modifica la db, sumando el actual valor de 'value' al del parámtro V
void Registry::update(char K, int V) {
    this->db.at(K) = {this->db[K] + V};
}

// Registro de cada tecla
void Registry::registerKey(char key){
    map<int, int>::iterator i = this->db.begin();
    i = this->db.find(key);
    if (i != this->db.end())
        i->second++;
}