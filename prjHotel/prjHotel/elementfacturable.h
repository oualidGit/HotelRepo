#pragma once
#ifndef __ELEMENTFACTURABLE_H__
#define __ELEMENTFACTURABLE_H__
#include <string>
using namespace std;

class ElementFacturable{
	protected:
		string nom;
		float prix_base;
		int ordre_imp;
		const int TAXE_VENTE = 8;
	public:
		ElementFacturable(string le_nom, float le_prix_base, int ordre_imp) : nom(le_nom), prix_base(le_prix_base), ordre_imp(ordre_imp) {}
		string getNom() { return nom; }
		void setNom(string le_nom) { nom = le_nom; }
		float getPrixBase() { return prix_base; }
		void setPrixBase(float le_prix_base) { prix_base = le_prix_base; }
		int getOrdreImp() { return ordre_imp; }
		void setOrdreImp(int ordre_imp) { ordre_imp = ordre_imp; }
		int getTaxeVente() { return TAXE_VENTE; }
		virtual float calculerMontant() { return 0; }
		virtual string afficherElmt() { return string(); }
};
#endif