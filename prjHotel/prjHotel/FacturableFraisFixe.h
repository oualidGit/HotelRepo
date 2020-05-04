#pragma once
#ifndef __FACTURABLEFRAISFIXE_H__
#define __FACTURABLEFRAISFIXE_H__
#include "elementfacturable.h"

class FacturableFraisFixe :	public ElementFacturable{
	private:
		const int TAXEADD = 7;
	public :
		FacturableFraisFixe(string le_nom, float le_prix_base, int ordre_imp);
		float calculerMontant();
		string afficherElmt();
};
#endif