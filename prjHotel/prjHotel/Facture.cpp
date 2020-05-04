#include "facture.h"

Facture::Facture(int num, string datef) : numero(num),date(datef) {}

map_int_fact& Facture::getMapFacturables() { return map_facturables; }

int Facture::getNum() const { return numero; }

void Facture::ajouterElmtFacturable(ElementFacturable* e) {
	pair<int, ElementFacturable*> paire_facture;
	paire_facture.first = e->getOrdreImp();
	paire_facture.second = e;
	map_facturables.insert(paire_facture);
}

float Facture::calculerTotal() {
	float total = 0;
	map<int, ElementFacturable*>::iterator iter;
	for ( iter = map_facturables.begin() ; iter!= map_facturables.end(); iter++)
		total += iter->second->calculerMontant();

	return total;
}

string Facture::toString() {
	string entete = "", contenu = "", total = "";
	char buffer[100];
	sprintf_s(buffer, "%.2f", calculerTotal());

	map_int_fact::iterator iter;
	entete = "Numero de facture : " + to_string(numero) + " , Date : " + date + "\n=======================================\n";
	entete += "Nom      PrixUn   nb Taxe  S.total\n";
	entete += "------------------------------------\n";
	for (iter = map_facturables.begin(); iter != map_facturables.end(); iter++) 
		contenu += iter->second->afficherElmt() + "\n";

	total = "                       Total facture = ";
	total+= buffer;

	return entete + contenu + total;
}