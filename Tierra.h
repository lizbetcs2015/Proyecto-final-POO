//
// Created by utec on 21/06/19.
//

#ifndef GAME_TIERRA_H
#define GAME_TIERRA_H

#include <iostream>
#include <vector>
#include "Tipos.h"
#include "Objeto.h"
#include "Museo.h"
#include "Restaurante.h"
#include "Hotel.h"
#include <SFML/Graphics.hpp>

using namespace std;

// Valores constantes
const TipoEntero ALTURA = 21;
const TipoEntero ANCHO  = 21;
const TipoCaracter COLOR ='.';

class Tierra {
private:
    int altura;
    int ancho;
    sf::RenderWindow* plano;
    vector<Objeto*> objetos;
    void actualizarTierra();
    void capturarEventos();
	vector<Hotel*> Hoteles;
	vector<Restaurante*> Restaurantes;
	vector<Museo*> Museos;
public:
    Tierra();
    Tierra(TipoEntero altura, TipoEntero ancho);
    virtual ~Tierra();
    void adicionarObjeto(Objeto* objeto);
    Objeto* removerObjeto(string& nombre);
    void imprimirObjetos();
    TipoEntero getAltura();
    TipoEntero getAncho();
    TipoEntero getCantidadObjectos();
    void dibujarTierra();
	void buscar_estrellas();
	void lugares_mejorcalificados();
	void  lugares_cercanos(TipoEntero
		posx, TipoEntero posy);
	void mostrarhoteles();
	void mostrarrestaurantes();
	void mostrarmuseos();
};


#endif

