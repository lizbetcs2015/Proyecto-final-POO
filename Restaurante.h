#ifndef GAME_RESTAURANTE_H
#define GAME_RESTAURANTE_H

#pragma once
#include "Objeto.h"

class Restaurante : public Objeto
{
private:
	
	TipoString direccion_restaurante;
	TipoEntero calificacion_consumo;
	TipoString tipo_comida;
	TipoString especialidad_dia;
	

public:
	Restaurante(const TipoString& _nombre, TipoString _direccion_restaurante,TipoEntero _calificacion_consumo, 
		TipoString _tipo_comida, TipoString _especialidad_dia, TipoCaracter _color,
		TipoEntero _posX, TipoEntero _posY);
	virtual ~Restaurante() {};

	TipoString getDireccion_restaurante();
	TipoEntero getCalificacion_consumo();
	TipoString getTipo_comida();
	TipoString getEspecialidad_dia();

	void setEspecialidad_dia(TipoString _especialidad_dia) {
		especialidad_dia = _especialidad_dia;
	}
	
	void actualizar_especialidad(string valor);
	
};

#endif

