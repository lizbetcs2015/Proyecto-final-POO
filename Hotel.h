#ifndef GAME_HOTEL_H
#define GAME_HOTEL_H

#pragma once
#include "Objeto.h"

class Hotel : public Objeto
{
private:
	
		TipoString direccion_hotel;
		TipoEntero estrellas;
		TipoEntero calificacion_huesped;
		TipoString disponibilidad;

public:
	Hotel(const TipoString& _nombre, TipoString _direccion_hotel, TipoEntero _estrellas,
		TipoEntero _calificacion_huesped, TipoString _disponibilidad, TipoCaracter _color,
		TipoEntero _posX, TipoEntero _posY);
	virtual~Hotel();

	TipoString getDireccion_hotel();
	TipoEntero getEstrellas();
	TipoEntero getCalificacion_huesped();
	TipoString getDisponibilidad();

	void actualizar_diponibilidad(TipoString valor);


};

#endif