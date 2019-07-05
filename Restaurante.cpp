#include "Restaurante.h"


Restaurante::Restaurante(const TipoString& _nombre, TipoString _direccion_restaurante, TipoEntero _calificacion_consumo,
	TipoString _tipo_comida, TipoString _especialidad_dia, TipoCaracter _color, TipoEntero _posX, TipoEntero _posY)
	: Objeto(_nombre, _color, _posX, _posY) {

	direccion_restaurante=_direccion_restaurante;
	calificacion_consumo=_calificacion_consumo;
	tipo_comida=_tipo_comida;
	especialidad_dia=_especialidad_dia;

}


TipoString Restaurante::getDireccion_restaurante() {
	return direccion_restaurante;
}
TipoEntero Restaurante::getCalificacion_consumo() {
	return calificacion_consumo;
}
TipoString Restaurante::getTipo_comida() {
	return tipo_comida;
}
TipoString Restaurante::getEspecialidad_dia() {
	return especialidad_dia;
}

void Restaurante::actualizar_especialidad(string valor){
	especialidad_dia = valor;
}