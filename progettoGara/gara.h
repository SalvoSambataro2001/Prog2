#ifndef GARA_H
#define GARA_H
#include "veicolo.h"
#include <cstdlib>
#include <ctime>

class Gara {
	int durata;
	int numeroPartecipanti;
	int numeroIscritti;
	void controlla(int t);
	Veicolo ** veicoli;
	Veicolo ** classifica;
	
	public:
	
	Gara(int durata, int partecipanti) : durata(durata), numeroPartecipanti(partecipanti) {
		veicoli = new Veicolo*[numeroPartecipanti];
		numeroIscritti = 0;
	}
	
	~Gara() {
		delete [] veicoli;
	}
	
	void partenza();
	void stampaClassifica();
	void aggiungiPartecipante(Veicolo& v);
};

#endif

void Gara::aggiungiPartecipante(Veicolo& v) {
	//mi serve sapere il numero dei partecipanti iscritti finora
	//A. aggiungo un parametro a questo metodo 
	//B. utilizzo una costante
	//C. aggiungo un attributo alla classe
	//D. vado al mare
	//std::cout << "Riga 37 file Gara - metodo aggiungiPartecipante" << std::endl;
	veicoli[numeroIscritti++] = &v;
}


void Gara::controlla(int t) {
	
	int massimo_temporaneo = veicoli[0]->getVelocita(); //veicoli[0].getVelocita()
	int indice_massimo = 0;
	//int massimo_temporaneo = -1;
	
	//std::cout << "Riga 48 file Gara - metodo controlla" << std::endl;

	for(int i=1; i < numeroIscritti; i++) {
		//estrarre la velocita di ogni veicolo
		//e verificare chi è più avanti
		//RICERCA se vogliamo solo trovare il massimo
		//ORDINAMENTO se vogliamo la classifica completo
		if(veicoli[i]->getVelocita() > massimo_temporaneo) {
			massimo_temporaneo = veicoli[i]->getVelocita();
			indice_massimo = i;
		}
	}
	
	std::cout << "Il veicolo piu' veloce e' " << veicoli[indice_massimo]->getMarca() << " e ha velocita'� " << massimo_temporaneo << std::endl;
	
	
}

void Gara::partenza() {
	srand(time(0));
	for(int i=0; i < durata; i++) {
		for(int j=0; j < numeroIscritti; j++) {
			
			//std::cout << "Riga 71 file Gara - metodo partenza" << std::endl;
			
			int scelta = rand() % 2;
			if(scelta == 1)
				veicoli[j]->accelera();
			else
				veicoli[j]->decelera();
			
		}
		this->controlla(i);
		this->stampaClassifica();
	}
}

void Gara::stampaClassifica() {
	
	std::cout<<"Classifica momentanea"<<std::endl;
	
	classifica = new Veicolo* [numeroIscritti];
	Veicolo * temp;

	for(int i=0; i < numeroIscritti; i++){
		classifica[i]=veicoli[i];
		//std::cout<<*classifica[i]<<std::endl;
		//std::cout<<*veicoli[i]<<std::endl;
	}

	bool flag;

	do{  //ORDINAMENTO
		flag=0;
		for(int i=0;i<numeroIscritti-1;i++){
			if(classifica[i]->getVelocita() < classifica[i+1]->getVelocita()) {
				temp=classifica[i];
				classifica[i]=classifica[i+1];
				classifica[i+1]=temp;
				flag=1;
			}
		}
	} while (flag!=0);

	for(int i=0;i<numeroIscritti;i++)
		std::cout << (i+1) << ") " << classifica[i]->getMarca() << std::endl;

	delete [] classifica;
	
	std::cout<<std::endl<< "-------------------------------"<<std::endl;
}
