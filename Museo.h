#ifndef GAME_MUSEO_H
#define GAME_MUSEO_H

#pragma once
#include "Objeto.h"

class Museo : public Objeto
{
private:

	TipoString direccion_museo;
	TipoEntero calificacion_visitantes; 
	TipoString exposicion;
	 
public:
	Museo(const TipoString& _nombre, TipoString _direccion_museo, TipoEntero _calificacion_visitantes,
		TipoString _exposicion, TipoCaracter _color, TipoEntero _posX, TipoEntero _posY);
	virtual~Museo() {};

	TipoString getDireccion_museo();
	TipoEntero getCalificacion_visitantes();
	TipoString getExposicion();

	void setExposicion(TipoCaracter _exposicion) {
		exposicion = _exposicion;
	}

	void actualizar_exposicion(string valor);
	

};

#endif