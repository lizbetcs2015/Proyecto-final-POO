// Created by utec on 21/06/19.
//


#include <iostream>
#include <string>
#include <cstdio>

#include "Menu.h"
#include "Museo.h"

using namespace std;
enum class Opciones {
    Agregar = 1, Remover, Mostrar
}; // se usa un tipo enumerado para indicar las opciones


/*
 ********************
 *
 * Funciones de Ayuda
 *
 ********************
 */

void limpiar() {
#ifndef WIN32
    cout << "\033[2J\033[0;0H";
#else
    system("cls");
#endif
}

void esperar() {
    TipoCaracter w;
    do {
        w = input<TipoCaracter>("Presione C y Enter para continuar...");
    } while (toupper(w) != 'C');
}

/*
 ******************************
 *
 * Metodos de clase Menu
 *
 ******************************
 */

Menu::Menu(int altura, int ancho) : tierra(altura, ancho), opcion{} {
	crearobjetos();
}

void Menu::crearobjetos() {
	
		tierra.adicionarObjeto(new Hotel("stx", "Avenido Aviacion 456",5, 6, "4 cuartos disponibles",'R', 500, 500));
		tierra.adicionarObjeto(new Hotel("sss", "Avenido BENAVIDES 134", 9, 10, "5 cuartos disponibles", 'B', 200, 100));
		tierra.adicionarObjeto(new Hotel("Finac", "Avenido Aviacion 876", 1, 3, "0 cuartos disponibles", 'R', 100, 210));

		tierra.adicionarObjeto(new Museo("Museo d or","Avenida Sagitario 123", 5, "Wari", 'G', 300, 400));
		tierra.adicionarObjeto(new Museo("Museo de utec", "Avenida Laboratorio 1.03", 5, "POO", 'B', 190, 200));
		tierra.adicionarObjeto(new Museo("Museo de Sipan", "Panamericana nortw 1236", 6, "Sipan", 'G', 300, 250));

		tierra.adicionarObjeto(new Restaurante("Especials","Calle las luciernagas 347",8,"Comida criolla", "Lomo saltado", 'R', 210, 159));
		tierra.adicionarObjeto(new Restaurante("Sazon maritimo", "Calle miguel grua", 6, "Comida marina", "Ceviche", 'G', 150, 120));
		tierra.adicionarObjeto(new Restaurante("Astrid y Gaston","San isidro 23567",10, "Comida internacional", "Arroz chaufa", 'B', 300, 240));


}

void Menu::agregarObjeto(TipoCaracter Entrada) {
	if (Entrada == 'H') {

		auto    nombre = input<TipoString>("Ingrese Nombre : ");
		auto    direccion_hotel = input<TipoString>("Ingrese la direccion:");
		auto    estrellas = input<TipoCaracter>("Ingrese cantidad de estrellas:");
		auto    calificacion_huesped = input<TipoEntero>("Ingrese la calificacion del local(1-10): ");
		auto    disponibilidad = input<TipoString>("Disponibilidad:");

		auto color = input<TipoCaracter>("Ingrese color (Un caracter): ");

		auto x = input<TipoEntero>("Ingrese posicion X : ");


		while (x < 0 || x >= tierra.getAncho()) {
			cout << "Posicion X Incorrecta, los limites son: 0, "
				<< tierra.getAncho() - 1 << "\n";
			x = input<TipoEntero>("Ingrese posicion X : ");
		}

		TipoEntero y = input<TipoEntero>("Ingrese posicion Y : ");
		while (y < 0 || y >= tierra.getAncho()) {
			cout << "Posicion Y Incorrecta, los limites son: 0, "
				<< tierra.getAltura() - 1 << "\n";
			y = input<TipoEntero>("Ingrese posicion Y : ");
		}

		tierra.adicionarObjeto(new Hotel(nombre,direccion_hotel,estrellas,calificacion_huesped,disponibilidad,color, x, y));
	}
	if (Entrada == 'M') {
		auto    nombre = input<TipoString>("Ingrese Nombre : ");
		auto    direccion_museo = input<TipoString>("Ingrese la direccion:");
		auto    calificacion_visitantes = input<TipoEntero>("Ingrese la calificacion del local(1_10): ");
		auto    exposicion = input<TipoString>("Ingrese el nombre de la  exposicion de Arte:");
		auto color = input<TipoCaracter>("Ingrese color (Un caracter): ");

		auto x = input<TipoEntero>("Ingrese posicion X : ");


		while (x < 0 || x >= tierra.getAncho()) {
			cout << "Posicion X Incorrecta, los limites son: 0, "
				<< tierra.getAncho() - 1 << "\n";
			x = input<TipoEntero>("Ingrese posicion X : ");
		}

		TipoEntero y = input<TipoEntero>("Ingrese posicion Y : ");
		while (y < 0 || y >= tierra.getAncho()) {
			cout << "Posicion Y Incorrecta, los limites son: 0, "
				<< tierra.getAltura() - 1 << "\n";
			y = input<TipoEntero>("Ingrese posicion Y : ");
		}

		tierra.adicionarObjeto(new Museo(nombre,direccion_museo,calificacion_visitantes,exposicion,color, x, y));
	}
	if (Entrada == 'R') {
		auto    nombre = input<TipoString>("Ingrese Nombre : ");
		auto    direccion_restaurante = input<TipoString>("Ingrese la direccion:");
		auto    calificacion_comida = input<TipoEntero>("Ingrese la calificacion del local(1_10): ");
		auto    tipo_comida = input<TipoString>("Ingrese el tipo de plato:");
		auto    especialidad_dia = input<TipoString>("Ingrese el menu del dia:");
		auto color = input<TipoCaracter>("Ingrese color (Un caracter): ");

		auto x = input<TipoEntero>("Ingrese posicion X : ");


		while (x < 0 || x >= tierra.getAncho()) {
			cout << "Posicion X Incorrecta, los limites son: 0, "
				<< tierra.getAncho() - 1 << "\n";
			x = input<TipoEntero>("Ingrese posicion X : ");
		}

		TipoEntero y = input<TipoEntero>("Ingrese posicion Y : ");
		while (y < 0 || y >= tierra.getAncho()) {
			cout << "Posicion Y Incorrecta, los limites son: 0, "
				<< tierra.getAltura() - 1 << "\n";
			y = input<TipoEntero>("Ingrese posicion Y : ");
		}

		tierra.adicionarObjeto(new Restaurante(nombre,direccion_restaurante,calificacion_comida,tipo_comida,especialidad_dia,color, x, y));
	}

	if (Entrada == 4) {
		tierra.buscar_estrellas();
	}

	if (Entrada == 5) {
		tierra.lugares_mejorcalificados();
	}
	if (Entrada == 6) {
		tierra.mostrarhoteles();
	}
	if (Entrada == 7) {
		tierra.mostrarrestaurantes();
	}
	if (Entrada == 8) {
		tierra.mostrarmuseos();
	}
}	

	

void Menu::removerObjeto() {
}

void Menu::dibujarMapa() {
    limpiar();
    tierra.dibujarTierra();
}

void Menu::mostrarMenu() {
    limpiar();
    cout << "Menu\n";
    cout << string(13, '-') << "\n\n";
    cout << "1. Agregar un nuevo objeto\n";
    cout << "2. Remover objeto\n";
    cout << "3. Dibujar Mapa\n";
	cout << "4. Tres mejores hoteles \n";
	cout << "5. Tres lugares con mayor calificacion \n";
	cout << "6. Mostrar hoteles:\n";
	cout << "7. Mostrar restaurantes:\n";
	cout << "8. Mostrar museos:\n";

    cout << "0. Para Salir\n\n";
}

void Menu::seleccionarOpcion() {
    limpiar();
    switch(Opciones(opcion)) {
        case Opciones::Agregar:// Agregar Objeto
         
			cout << "Menu\n";
			cout << string(4, '-') << "\n\n";
			cout << "1. (H)otel\n";
			cout << "2. (R)estaurante\n";
			cout << "3. (M)useo\n\n";
			cout << "0. Para Salir\n\n";
			Entrada = input<TipoCaracter>("Ingrese H, M, o R: ");
			agregarObjeto(Entrada);

            break;
        case Opciones::Remover:  // Remover Objeto
            removerObjeto();
            break;
        case  Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;
    }
}

void Menu::ejecutar() {
    do {
        mostrarMenu();
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 0);
    cout << "Fin del programa...\n";
}
