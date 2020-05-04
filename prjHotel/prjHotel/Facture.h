#pragma once
#ifndef __FACTURE_H__
#define __FACTURE_H__
#include "elementfacturable.h"
#include <map>
#include <string>

using namespace std;
typedef map<int, ElementFacturable*> map_int_fact;
class Facture{
	private:
		int numero;
		string date;
		map_int_fact map_facturables;
	public:
		Facture(int num, string datef);
		void ajouterElmtFacturable(ElementFacturable* e);
		float calculerTotal();
		string toString();
		map_int_fact& getMapFacturables();
		int getNum() const;
};
#endif