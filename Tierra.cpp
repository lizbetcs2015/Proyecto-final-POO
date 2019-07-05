// Created by utec on 21/06/19.
//
#include "Tierra.h"
#include <string>
#include <iomanip>
#include <map>
#include <algorithm>
#include "Objeto.h"
#include "Tierra.h"
#include <iostream>

using namespace std;

map<char, sf::Color> listaColores = {
        {'R', sf::Color::Red},
        {'G', sf::Color::Green},
        {'B', sf::Color::Blue}};


using namespace std;

Tierra::Tierra() : altura{}, ancho{} {
	plano = nullptr;
} 

Tierra::Tierra(TipoEntero altura, TipoEntero ancho) : altura{altura}, ancho{ancho} {
    plano = new sf::RenderWindow();
}

Tierra::~Tierra() {
    delete plano;
}


void Tierra::adicionarObjeto(Objeto *objeto) {
    objetos.push_back(objeto);
} 

Objeto *Tierra::removerObjeto(string &nombre) {
// Si vector esta vacio
    if (objetos.size() == 0)

        return nullptr;
// Buscando objeto
    auto iter = find_if(begin(objetos), end(objetos),
                        [&nombre](Objeto *obj) { return obj->getNombre() == nombre; });
    if (iter != end(objetos)) {
// Eliminando la referencia al puntero objeto dentro del vector objetos
        objetos.erase(iter);
//-- si encuentra al objeto lo separa del vector,
//-- (no libera de memoria el objeto encontrado), esto se hará en el menú,
//-- donde fue asignado, debido a que el objeto no es parte sino el objeto es un visitante.
        return *iter;
    }
// Si vector esta vacio
    return nullptr;
}

void Tierra::imprimirObjetos() {
    int i = 0;
    for (auto &item: objetos) {
        cout << "* * * * * * [" << i << "] ";
        cout << " Nombre = " << item->getNombre() << " "
             << item->mostrarPosicion()
             << " Color = " << item->getColor() << '\n';
        i++;
    }
}

void Tierra::actualizarTierra() {
    plano->clear();
    for (auto obj: objetos) {
        sf::CircleShape shape(10);
        shape.setPosition(static_cast<float>(obj->getPosX()), static_cast<float>(obj->getPosY()));
		//shape.setFillColor(listaColores[obj->getColor()]);
		shape.setFillColor(sf::Color::Yellow);
		plano->draw(shape);
    }
    plano->display();
}
void Tierra::dibujarTierra() {

    // Verifica si plano ha sido creado anteriormente
    if (!plano->isOpen())
        plano->create(sf::VideoMode(ancho, altura), "Proyecto Final - Presione [ESC] para salir... ");
    else
        plano->display();

    // Bucle principal
    while (plano->isOpen()) {
        capturarEventos();
        actualizarTierra();
    }
}

TipoEntero Tierra::getAltura() {
	return altura;
}

TipoEntero Tierra::getAncho() {
    return ancho;
}

TipoEntero Tierra::getCantidadObjectos() {
    return objetos.size();
}

void Tierra::capturarEventos() {
    sf::Event event{};

    while (plano->pollEvent(event)) {

        switch (event.type) {
            case sf::Event::Closed:
                plano->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    plano->close();
                break;
        }
    }
}

void Tierra::buscar_estrellas() {
	if (Hoteles.size()>2) {
		sort(begin(Hoteles), end(Hoteles), [](Hotel* hoteles1, Hotel* hoteles2) {
			return hoteles1->getEstrellas() > hoteles2->getEstrellas();
		});
		for (int i = 0; i < 3; i++) {
			cout << Hoteles[i]->getNombre();
		}
	}
}

void Tierra::lugares_mejorcalificados() {
	if (Hoteles.size() > 2) {
		sort(begin(Hoteles), end(Hoteles), [](Hotel* hoteles1, Hotel* hoteles2) {
			return hoteles1->getCalificacion_huesped() > hoteles2->getCalificacion_huesped();
			});
	}
	if (Restaurantes.size() > 2) {
		sort(begin(Restaurantes), end(Restaurantes), [](Restaurante* restaurante1, Restaurante* restaurate2) {
			return restaurante1->getCalificacion_consumo() > restaurate2->getCalificacion_consumo();
			});
	}
	if (Museos.size() > 2) {
		sort(begin(Museos), end(Museos), [](Museo* museo1, Museo* museo2) {
			return museo1->getCalificacion_visitantes() > museo2->getCalificacion_visitantes();
			});
	}

	cout << Hoteles[Hoteles.size()]->getNombre();
	cout << Restaurantes[Restaurantes.size()]->getNombre();
	cout << Museos[Museos.size()]->getNombre();

}
void Tierra::lugares_cercanos(TipoEntero posx, TipoEntero posy)
{
	/*for (int i = 0; i < objetos.size; i++) {
		if (abs(posx - (Objeto[i]->getPosX())){
	}*/
}
;

void Tierra::mostrarrestaurantes() {
	for (int i = 0; i < Restaurantes.size(); i++) {
		cout << Restaurantes[i] ->getNombre()<< endl;
	}
}

void Tierra::mostrarmuseos() {
	for (int i = 0; i < Museos.size(); i++) {
		cout << Museos[i]->getNombre() << endl;
	}
} 

void Tierra::mostrarhoteles() {
	for (int i = 0; i < Hoteles.size(); i++) {
		cout << Hoteles[i]->getNombre()<< endl;
	}
}
