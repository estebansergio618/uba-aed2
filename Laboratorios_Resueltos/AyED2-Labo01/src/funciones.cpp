#include <vector>
#include "algobot.h"

using namespace std;

// AUXILIARES PARA MODULARIZACIÓN
int cantidadDeApariciones(int x, vector<int> v){
    int res = 0;
    for (int i = 0; i < v.size() ; ++i) {
        if (v[i] == x){
            res += 1;
        }
    }
    return res;
}

set<int> convertirSecuenciaAConjunto(vector<int> v){
    set<int> A;

    for (int e : v) {
        A.insert(e);
    }

    return A;
}

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res = {};
    set<int> A;
    // CONVERTIR SECUENCIA A CONJUNTO
    for (int e : s) {
        A.insert(e);
    }

    // CONVERTIR CONJUNTO A SECUENCIA
    for (int x : A) {
        res.push_back(x);
    }

    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> res = {};
    set<int> A;

    // CONVERTIR SECUENCIA A CONJUNTO
    for (int e : s) {
        A.insert(e);
    }

    // CONVERTIR CONJUNTO A SECUENCIA
    for (int x : A) {
        res.push_back(x);
    }

    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> A = convertirSecuenciaAConjunto(a);
    set<int> B = convertirSecuenciaAConjunto(b);

    return A == B;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> A = convertirSecuenciaAConjunto(a);
    set<int> B = convertirSecuenciaAConjunto(b);

    return A == B;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int>res;
    set<int> A = convertirSecuenciaAConjunto((s));

    // ASOCIA CON LA CANTIDAD DE APARICIONES DE x EN s
    for( int x : A){
        res[x] = cantidadDeApariciones(x,s);
    }

    return res;
}

// Ejercicio 6
vector<int> EliminaElemento(int x, vector<int> s){
    vector<int> res = {};
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != x){
            res.push_back(s[i]);
        }
    }
    return res;
}

vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res = {};
    set<int> A = convertirSecuenciaAConjunto((s));

    for (int x : A) {
        if (cantidadDeApariciones(x,s) == 1){
            res.push_back(x);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;

    for ( int x : a) {
        for (int y : b) {
            if (x == y){
                res.insert(x);
            }
        }
    }

    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;

    for (int e : s) {
        int UltimoDigito = e % 10;
        if (res.count(UltimoDigito) == 0){
            set<int> ConjuntoDeSignificados;
            ConjuntoDeSignificados.insert(e);
            res[UltimoDigito] = ConjuntoDeSignificados;
        } else {
            res[UltimoDigito].insert(e);
        }
    }

    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res = {};
    map<char,char> diccionarioDeTr;

    // CONVIERTO LA SECUENCIA tr EN UN DICCIONARIO
    for (pair<char,char> e : tr) {
        diccionarioDeTr[e.first] = e.second;
    }

    // TRADUZCO str CARACTER POR CARACTER USANDO EL DICCIONARIO DE tr.
    for (char e : str) {
        if (diccionarioDeTr.count(e) == 1){
            // CAMBIO POR SU SIGNIFICADO
            res.push_back(diccionarioDeTr[e]);
        } else{
            res.push_back(e);
        }
    }

    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    bool res = false;

    for (Mail x : s) {
        for ( Mail y : s) {
            if (x == y){
                continue;
            }

            set<LU> lib_x = x.libretas();
            set<LU> lib_y = y.libretas();

            for (LU lib1 : lib_x) {
                for (LU lib2 : lib_y) {
                    if (lib1 == lib2){
                        res = true;
                    }
                }
            }
        }
    }
    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;

    for ( Mail email : s) {
        if (email.adjunto()){
            res[email.libretas()] = email;
        } else{
            continue;
        }
    }
    return res;
}
