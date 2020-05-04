#include "facturablefraisfixe.h"

FacturableFraisFixe::FacturableFraisFixe(string le_nom, float le_prix_base, int ordre_imp) : ElementFacturable(le_nom, le_prix_base, ordre_imp) {
}

float FacturableFraisFixe::calculerMontant() {
	float montant;
	montant = prix_base * (1 + (TAXE_VENTE + (float)TAXEADD) / 100);
	return montant;
}

string FacturableFraisFixe::afficherElmt() {
	char buffer[100];
	char buffer2[100];
	
	sprintf_s(buffer, "%.2f", prix_base);
	sprintf_s(buffer2, "%.2f", calculerMontant());
	
	string retour = "";
	retour += nom + " , " + buffer + " ,     " + to_string((TAXE_VENTE + TAXEADD)) + " , " + buffer2;
	return retour;
}