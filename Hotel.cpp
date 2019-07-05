#include "Hotel.h"


Hotel::Hotel(const TipoString& _nombre, TipoString _direccion_hotel, TipoEntero _estrellas,
	TipoEntero _calificacion_huesped, TipoString _disponibilidad, TipoCaracter _color,
	TipoEntero _posX, TipoEntero _posY)
	: Objeto(_nombre, _color, _posX, _posY) {

	direccion_hotel=_direccion_hotel;
	estrellas=_estrellas;
	calificacion_huesped=_calificacion_huesped;
	disponibilidad=_disponibilidad;

}

Hotel::~Hotel()
{
}


TipoString Hotel::getDireccion_hotel() {
	return direccion_hotel;
}
TipoEntero Hotel:: getEstrellas() {
	return estrellas;
}
TipoEntero Hotel::getCalificacion_huesped() {
	return calificacion_huesped;
}
TipoString Hotel::getDisponibilidad() {
	return disponibilidad;
}

void Hotel::actualizar_diponibilidad(TipoString valor){
	disponibilidad = valor;

}

