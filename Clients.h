#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

class Clients
{
	friend class Raports;
private:
	string name, surname, pesel, cli_ID, tel_number, datum;
	int client_number;
public:
	Clients(string = "BRAK DANYCH", string = "BRAK DANYCH", string = "BRAK DANYCH", string = "BRAK DANYCH", string = "BRAK DANYCH", string = "01.01.2020", int =0);

	~Clients();

	string cli_ID_Generator(); // to update

	void new_client();

	void read_clients();

	void write_clients();

	void show_all_clients();

	void find_client();


};

#pragma once
