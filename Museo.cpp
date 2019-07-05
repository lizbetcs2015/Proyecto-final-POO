#include "Museo.h"


Museo::Museo(const TipoString& _nombre, TipoString _direccion_museo, TipoEntero _calificacion_visitantes,
	TipoString _exposicion, TipoCaracter _color, TipoEntero _posX, TipoEntero _posY)
	: Objeto(_nombre, _color, _posX, _posY) {
	direccion_museo = _direccion_museo;
	calificacion_visitantes = _calificacion_visitantes;
	exposicion = _exposicion;
}


TipoString Museo::getDireccion_museo() {
	return direccion_museo;
}
TipoEntero Museo::getCalificacion_visitantes() {
	return calificacion_visitantes;
}
TipoString Museo::getExposicion() {
	return exposicion;
}

void Museo::actualizar_exposicion(string valor){
	exposicion=valor;
}