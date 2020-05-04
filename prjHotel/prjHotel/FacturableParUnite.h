#pragma once
#ifndef __FACTURABLEPARUNITE_H__
#define __FACTURABLEPARUNITE_H__
#include "elementfacturable.h"
class FacturableParUnite : public ElementFacturable{
	private:
		const int TAXEHEBERGEMENT = 5;
		int nbr_unites;
	public:
		FacturableParUnite(string le_nom, float le_prix_base, int ordre_imp, int le_nbr_unites);
		float calculerMontant();
		string afficherElmt();
		void setNbrUnites(int nbr_unites);
		int getNbrUnites() const;
};
#endif