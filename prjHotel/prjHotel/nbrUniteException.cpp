#include "nbruniteexception.h"

NbrUniteException::NbrUniteException(std::string nom_elmnt) {
	this->message = "Nbr d unites de " + nom_elmnt + " est inferieur ou egale a zero !";
}

std::string NbrUniteException::getMessage() {
	return this->message;
}