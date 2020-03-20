#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <fstream>
#include "Clients.h"
#include "Movies.h"

class Raports
{
	string name_2, surname_2, tel_number_2, tittle_2, ID_2;
	int raport_number = 0;
	
public:

	Raports(string="BRAK DANYCH", string="BRAK DANYCH", string="BRAK DANYCH", string="BRAK DANYCH", string="BRAK DANYCH", int=0);

	~Raports();

	//void datum();

	void read_raport();

	void read_lending();

	void write_raports();

	void write_lendings();

	void show_lending_movies();

	void show_raports();

	void lend_movie();

	void return_movie();

};

