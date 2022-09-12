#include "SistemaDeMensajes.h"

// Completar...
SistemaDeMensajes::SistemaDeMensajes():_conns() {}

void SistemaDeMensajes::registrarJugador(int id, string ip){
    if (!registrado(id)){
        // GUARDO LA DIRECCION DEL ESPACIO EN MEMORIA
        ConexionJugador* connec = new ConexionJugador(ip);
        _conns[id] = connec;
    }
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    _conns[id]->enviarMensaje(mensaje);
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

SistemaDeMensajes::~SistemaDeMensajes(){
    for (int i = 0; i < 4; ++i) {
        if (registrado(i)){
            delete _conns[i];
        }
    }
}