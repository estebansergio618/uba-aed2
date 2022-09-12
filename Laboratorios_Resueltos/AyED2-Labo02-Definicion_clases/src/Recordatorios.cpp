#include <iostream>
#include<list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    // Completar declaraciones funciones
    Fecha(int mes, int dia); //CONSTRUCTOR
    int mes();
    int dia();
    void incrementar_dia();

    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif

  private:
    //Completar miembros internos
    int _mes;
    int _dia;
};

Fecha::Fecha(int mes, int dia): _mes(mes),_dia(dia) {}

int Fecha::mes() {
    return _mes;
}

int Fecha::dia() {
    return  _dia;
}

void Fecha::incrementar_dia() {
    if (_dia == dias_en_mes(_mes)){
        _dia = 1;
        _mes = _mes + 1;
    } else{
        _dia = _dia + 1;
    }
}

// PERMITE QUE LA FECHA PUEDE IMPRIMIRSE
ostream& operator<<(ostream& os, Fecha f){
    os << f.dia() << "/" << f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia && igual_mes;
}
#endif

// Ejercicio 11, 12

// Clase Horario
class Horario{
    public:
        Horario(uint hora, uint min);
        uint hora();
        uint min();

        // OPERADOR ES PUBLICO
        bool operator==(Horario o);
        bool operator<(Horario h);
    private:
        uint _hora;
        uint _min;
};

// FUNCIONES DE LA INTERFAZ
Horario::Horario(uint hora, uint min):_hora(hora),_min(min) {}

uint Horario::hora() {
    return  _hora;
}

uint Horario::min() {
    return  _min;
}

//IMPRESION EN PANTALLA
ostream& operator<<(ostream& os, Horario h){
    os << h.hora() << ":" << h.min();
    return os;
}

//OPERADORES
bool Horario::operator<(Horario h) {
    return _hora < h.hora() || _hora == h.hora() && _min < h.min() ;
}

bool Horario::operator==(Horario o) {
    return  _hora == o.hora() && _min == o.min();
}
// Ejercicio 13

// Clase Recordatorio
using Mensaje = string;

class Recordatorio{
    public:
        Recordatorio(Fecha f, Horario h,Mensaje m);
        Mensaje msg();
        Fecha fecha();
        Horario horario();
        bool operator==(Recordatorio o);
    private:
        Mensaje _msg;
        Fecha _fecha;
        Horario _horario;
};

bool Recordatorio::operator==(Recordatorio o) {
    return _msg == o.msg() && _fecha == o.fecha() && _horario == o.horario();
}

Recordatorio::Recordatorio(Fecha f, Horario h, Mensaje m):_msg(m), _fecha(f), _horario(h) {}

Mensaje Recordatorio::msg() {
    return _msg;
}

Fecha Recordatorio::fecha() {
    return  _fecha;
}

Horario Recordatorio::horario() {
    return  _horario;
}

ostream& operator<<(ostream& os, Recordatorio r){
    os << r.msg() << " " << "@ " << r.fecha() << " " << r.horario();
    return os;
}

// Ejercicio 14

// Clase Agenda
class Agenda{
    public:
        Agenda(Fecha fecha_inicial);
        void agregar_recordatorio(Recordatorio rec);
        void incrementar_dia();
        list<Recordatorio> recordatorios_de_hoy();
        list<Recordatorio> recordatorio_general();
        Fecha hoy();
    private:
        list<Recordatorio> _recordatorios_general;
        list<Recordatorio> _recordatorios_hoy;
        Fecha _fecha_inicial;

};

Agenda::Agenda(Fecha fecha_inicial):_fecha_inicial(fecha_inicial){}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    _recordatorios_general.push_back(rec);
    if (rec.fecha() == _fecha_inicial){
        _recordatorios_hoy.push_back(rec);
    }
}

void Agenda::incrementar_dia() {
    _fecha_inicial.incrementar_dia();
}

Fecha Agenda::hoy() {
    return _fecha_inicial;
}

list<Recordatorio> Agenda::recordatorio_general() {
    return _recordatorios_general;
}

list<Recordatorio> Agenda::recordatorios_de_hoy() {

    // VACIO LOS RECORDATORIOS DE HOY
    _recordatorios_hoy = {};

    // LOS VUELVO A LLENAR
    for (Recordatorio e : _recordatorios_general) {
        if (e.fecha() == _fecha_inicial){
            _recordatorios_hoy.push_back(e);
        }
    }

    return _recordatorios_hoy;
}

// IMPRESIÓN EN PANTALLA
// 10/5
// =====
// Clase Algo2 @ 10/5 9:00
// Labo Algo2 @ 10/5 11:00
ostream& operator<<(ostream& os, Agenda a){
    os << a.hoy() << endl;
    os << "=====" << endl;

    //IMPRIME UNO POR UNO CON EL MISMO FORMATO
    for (Recordatorio e : a.recordatorio_general()) {
        if (e.fecha() == a.hoy()){
            os << e << endl;
        }
    };

    return os;
}