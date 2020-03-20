#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <sstream>
#include <ctime>

using namespace std;
class Movies
{
	friend class Raports;
private:
	string tittle, type, director, ID, year, actors, availability, amount, movie_time;
	int movie_number;

public:

	Movies(string = "BRAK DANYCH", string = "BRAK DANYCH", string = "BRAK DANYCH", string = "BRAK DANYCH", string = "BRAK DANYCH", string = "BRAK DANYCH", string = "BRAK DANYCH", string = "BRAK DANYCH", string = "BRAK DANYCH", int=0 );

	~Movies();

	int ID_Generator(); //do rozbudowy

	void read_movies();

	void write_movies();

	void show_all_movies();

	void show_movies_in_magazine();

	void find_movie();

	void find_movie_in_magazine();

	void new_movie();

	void read_state_in_magazine();

	void update_after_return(string kryterium);

	void delete_movie();

};

