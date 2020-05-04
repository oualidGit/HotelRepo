// Classe de l exception qui recupere le nbr de nuitee ou de repas selon ou elle a ete lancée... 
// pour remplacer le nbre d'unites dans le map
// elle affiche aussi un message personalisé.

#ifndef __DOUBLONUNITE_H__
#define __DOUBLONUNITE_H__
#include <string>

class DoublonUnite{
	private:
		std::string message;
		int nb;
	public:
		DoublonUnite(int nbr , std::string msg) : message(msg) , nb(nbr) {}
		std::string getMessage() { return message; }
		int getNb() { return nb; }
};
#endif