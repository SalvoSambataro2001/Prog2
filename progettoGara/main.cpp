#include "moto.h"
#include "automobile.h"
#include "gara.h"

int main() {
	
	std::string * array;
	std::string array2[10];
	array = new std::string[10];
	
	for(int i=0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
	
	std::cout << std::endl;
	
	for(int i=0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
	
	std::cout << std::endl;
	
	
	Moto ducati(140, 10000, "Ducati", "1000cc");
	Auto punto(120, 8000, "Fiat Punto", "diesel", "1.300 MTJ");
	Moto ninja(200, 10000, "Kawasaki Ninja", "1000cc");
	Auto lambo(300, 8000, "Lamborghini Murcielago", "diesel", "1.300 MTJ");
	Auto suzuki(120, 8000, "suzuki swift", "diesel", "1.300 MTJ");
	Auto ferrari(320, 8000, "Ferrari bella", "diesel", "1.300 MTJ");

	std::cout << ducati << std::endl;
	std::cout << punto << std::endl;
	std::cout << ninja << std::endl;
	std::cout << lambo << std::endl;
	std::cout << suzuki << std::endl;
	std::cout << ferrari << std::endl;
	
	Gara gara(10, 10);
	gara.aggiungiPartecipante(ducati);
	gara.aggiungiPartecipante(punto);
	gara.aggiungiPartecipante(ninja);
	gara.aggiungiPartecipante(lambo);
	gara.aggiungiPartecipante(suzuki);
	gara.aggiungiPartecipante(ferrari);

	gara.partenza();
}