#include "facturableparunite.h"
#include <iomanip>
#include <iostream>

FacturableParUnite::FacturableParUnite(string le_nom, float le_prix_base, int ordre_imp, int le_nbr_unites) :ElementFacturable(le_nom, le_prix_base, ordre_imp) {
	nbr_unites = le_nbr_unites;
}

float FacturableParUnite::calculerMontant() {
	float montant;
	montant = (prix_base * nbr_unites) * (1 + (TAXE_VENTE + (float)TAXEHEBERGEMENT) / 100);
	return montant;
}

string FacturableParUnite::afficherElmt() {
	char buffer[100];
	char buffer2[100];
	string retour = "";
	sprintf_s(buffer, "%.2f", prix_base);
	sprintf_s(buffer2, "%.2f", calculerMontant());
	retour += nom + " , " + buffer + " , " +  to_string(nbr_unites)  + " , " + to_string((TAXE_VENTE + TAXEHEBERGEMENT)) + " , " + buffer2;
	return retour;
}

void FacturableParUnite::setNbrUnites(int le_nbr_unites) {
	nbr_unites = le_nbr_unites;
}

int FacturableParUnite::getNbrUnites() const {
	return nbr_unites;
}