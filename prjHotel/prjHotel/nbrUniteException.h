// Classe associee a l'exception lanc�e lorsque un nbre d'unite est inferieur ou egale a zero

#pragma once
#ifndef __NBRUNITEEXCEPTION_H__
#define __NBRUNITEEXCEPTION_H__

#include <string>
class NbrUniteException{
	private:
		std::string message;
	public:
		NbrUniteException(std::string nom_elmnt);
		std::string getMessage();
};
#endif