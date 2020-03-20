#include "Clients.h"



using namespace std;

int kl = 10000;

Clients::Clients(string m_name, string m_surname, string m_pesel, string m_cli_ID, string m_tel_number, string m_datum, int m_client_number)
{
	name = m_name;
	surname = m_surname;
	pesel = m_pesel;
	cli_ID = m_cli_ID;
	tel_number = m_tel_number;
	client_number = m_client_number;
	datum = m_datum;
}


Clients::~Clients(){}


/*
string Clients::cli_ID_Generator()
{

	stringstream stream;
	stream.fill('0');
	stream.width(10);
	stream << n;
	return stream.str();


	string help = "000001";
	read_clients();
	while (help == cli_ID)
	{
		help = help + '1';//atoi(film[n].amount.c_str());  // Count all of owned discs
	}
	return help;
}
*/

void Clients::new_client() 
{
	string end_of;
	getline(cin, end_of);
	

	cout << "Add new client:\n\n";
	cout << "Name:                              ";	getline(cin, name); 
	cout << "Surname:                           ";	getline(cin, surname); 
	cout << "PESEL:                             ";	getline(cin, pesel); 
	cout << "Client's ID:                       ";	getline(cin, cli_ID); // Jak bêdzie funkcja generuj¹ca, to do kosza
	cout << "Telephone number:                  ";  getline(cin, tel_number); 
	cout << "Datum of add [day].[month].[year]: ";	getline(cin, datum);  // jak komentarz wy¿ej
	//cli_ID = cli_ID_Generator(); - jak funkcja bedzie dobrze - odkomentowac
	//datum = generate_datum(); - jak wy¿ej

	fstream list_of_clients;
	list_of_clients.open("Clients.txt", ios::app);

	list_of_clients <<endl <<name << endl;	cout << endl;
	list_of_clients << surname << endl;			cout << endl;
	list_of_clients << pesel << endl;			cout << endl;
	list_of_clients << cli_ID << endl;			cout << endl;
	list_of_clients << tel_number << endl;		cout << endl;
	list_of_clients << datum << endl;	        cout << endl << endl;

	list_of_clients.close();

	cout << "Client: " << name <<" "<<surname<< " has been successfuly saved in base.\n";
}

void Clients::read_clients()
{
	fstream list_of_clients;
	list_of_clients.open("Clients.txt", ios::in);

	if (list_of_clients.good() == false)
	{
		cout << "Failed to open" << endl;
		exit(0);
	}

	int number_line = (client_number - 1) * 7 + 1;
	int current_number = 1;
	string line;

	while (getline(list_of_clients, line))
	{
		if (current_number == number_line) name = line;
		if (current_number == number_line + 1) surname = line;
		if (current_number == number_line + 2) pesel = line;
		if (current_number == number_line + 3) cli_ID = line;
		if (current_number == number_line + 4) tel_number = line;
		if (current_number == number_line + 5) datum = line;


		current_number++;
	}

	list_of_clients.close();
}

void Clients::write_clients()
{
	cout << "Name:              \t" << name << endl;
	cout << "Surname:           \t" << surname << endl;
	cout << "PESEL:             \t" << pesel << endl;
	cout << "Client's ID:       \t" << cli_ID << endl;
	cout << "Telephone number:  \t" << tel_number << endl;
	cout << "Datum of add:      \t" << datum << endl << endl << endl;

}


void Clients::show_all_clients()
{
	int n = 0; int p = 0;
	//int k = 10; // Number of clients
	string help = "BRAK DANYCH";

	Clients* person = new Clients[kl];
	cout << endl << "Complete list of clients" << endl << endl << endl;
	for (int i = 1; i <= kl; i++) // Read and display list of clients
	{
		person[n].client_number = n + 1;
		person[n].read_clients();
		if (person[n].name == help) break;
		person[n].write_clients();
		n++;
	}
	cout << "--------------------------------------------------------------------\n\nSummary:\t" << n << " positions\n\n";
}


void Clients::find_client()
{
	string name_kryterium, surname_kryterium;
	int n = 0;
	//int k = 4; // Number of clients
	bool flag = 0;


	Clients* find = new Clients[kl];
	cout << endl << "Please, write name and surname of searching client: \n\n";
	cout <<"Name:    \t"; 
	getline(cin, name_kryterium);
	getline(cin, name_kryterium);
	cout << "Surname:\t";
	getline(cin, surname_kryterium);
	for (int i = 1; i <= kl; i++) // Read and display selected list of clients
	{
		find[n].client_number = n + 1;
		find[n].read_clients();
		if (find[n].name == name_kryterium && find[n].surname == surname_kryterium)
		{
			cout << "\nWe have " << name_kryterium << " "<< surname_kryterium <<" in our base.\nThere are information about this client: \n\n";
			find[n].write_clients();
			flag = 1;
			break;
		}
		n++;
	}
	if (!flag) {
		cout << "\nWe don't have " << name_kryterium << " " << surname_kryterium << " in our base.\n\n";
	}
}
/*
string generate_datum()
{

}
*/
