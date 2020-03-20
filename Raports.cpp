#include "Raports.h"

int ka = 10000;

Raports::Raports(string m_name_2, string m_surname_2, string m_tel_number_2, string m_tittle_2, string m_ID_2, int m_raport_number) {

	name_2 = m_name_2;
	surname_2 = m_surname_2;
	tel_number_2 = m_tel_number_2;
	tittle_2 = m_tittle_2;
	ID_2 = m_ID_2;
	raport_number = m_raport_number;

}

Raports::~Raports() {}





void Raports::read_raport()
{
	string date = "DATE";
	fstream list_of_movies;
	list_of_movies.open("Raport.txt", ios::in);

	if (list_of_movies.good() == false)
	{
		cout << "Failed to open" << endl;
		exit(0);
	}

	int number_line = (raport_number - 1) * 8 + 1;
	int current_number = 1;
	string line;

	while (getline(list_of_movies, line))
	{
		if (current_number == number_line) name_2 = line;
		if (current_number == number_line + 1) surname_2 = line;
		if (current_number == number_line + 2) tel_number_2 = line;
		if (current_number == number_line + 3) tittle_2 = line;
		if (current_number == number_line + 4) ID_2 = line;
		if (current_number == number_line + 5) date = line;
		if (current_number == number_line + 6) date = line;///////////////////////////////////////////////////

		current_number++;
	}

	list_of_movies.close();
}

void Raports::read_lending()
{
	string date = "DATE";
	fstream list_of_movies;
	list_of_movies.open("Lended_movies.txt", ios::in);

	if (list_of_movies.good() == false)
	{
		cout << "Failed to open" << endl;
		exit(0);
	}

	int number_line = (raport_number - 1) * 7 + 1;
	int current_number = 1;
	string line;

	while (getline(list_of_movies, line))
	{
		if (current_number == number_line) name_2 = line;
		if (current_number == number_line + 1) surname_2 = line;
		if (current_number == number_line + 2) tel_number_2 = line;
		if (current_number == number_line + 3) tittle_2 = line;
		if (current_number == number_line + 4) ID_2 = line;
		if (current_number == number_line + 5) date = line;/////////////////////////////////////////////////

		current_number++;
	}

	list_of_movies.close();
}

void Raports::write_raports()
{
	cout << "Name:         \t" << name_2 << endl;
	cout << "Surname:      \t" << surname_2 << endl;
	cout << "Phone number: \t" << tel_number_2 << endl;
	cout << "Tittle:       \t" << tittle_2 << endl;
	cout << "Movie's ID:   \t" << ID_2 << endl;
	cout << "Lended:       \t" << "DATE" << endl;
	cout << "Returned:     \t" << "DATE" << endl << endl << endl;
}

void Raports::write_lendings()
{
	{
		cout << "Name:         \t" << name_2 << endl;
		cout << "Surname:      \t" << surname_2 << endl;
		cout << "Phone number: \t" << tel_number_2 << endl;
		cout << "Tittle:       \t" << tittle_2 << endl;
		cout << "Movie's ID:   \t" << ID_2 << endl;
		cout << "Lended:       \t" << "DATE" << endl<< endl << endl;
	}
}

void Raports::show_lending_movies()
{
	int n = 0;
	int help = 0;

	Raports* film = new Raports[ka];
	cout << endl << "Complete list of clients and lended movies" << endl << endl << endl;
	for (int i = 1; i <= ka; i++) // Read and display
	{
		film[n].raport_number = n + 1;
		film[n].read_lending();
		if (film[n].name_2 == "BRAK DANYCH") break;
		film[n].write_lendings();
		help = help++;
		n++;
	}
	cout << "--------------------------------------------------------------------\nSummary:\t" << help << " lends\n\n";
}

void Raports::show_raports()
{
	int n = 0;
	int help = 0;

	Raports* film = new Raports[ka];
	cout << endl << "Complete list of clients and lended movies" << endl << endl << endl;
	for (int i = 1; i <= ka; i++) // Read and display
	{
		film[n].raport_number = n + 1;
		film[n].read_raport();
		if (film[n].name_2 == "BRAK DANYCH") break;
		film[n].write_raports();
		help = help++;
		n++;
	}
	cout << "--------------------------------------------------------------------\nSummary:\t" << help << " lends\n\n";
}

void Raports::lend_movie() 
{

	string kryterium;
	int n = 0;
	bool flag = 0; // To know if the movie is in base
	bool flag_2 = 0; //To know if we can lend movie
	int help_a;


	Movies* find = new Movies[ka];
	fstream helper, islending;
	helper.open("helper.txt", ios::out);
	cout << endl << "Which movie are you looking for?" << endl;
	islending.open("Lended_movies.txt", ios::app);
	getline(cin, kryterium);
	getline(cin, kryterium); cout << endl;
	for (int i = 1; i <= ka; i++) // Read and display selected list of lends
	{
		find[n].movie_number = n + 1;
		find[n].read_state_in_magazine();

		if (find[n].tittle == "BRAK DANYCH") break;
		if (find[n].tittle == kryterium)
		{
			help_a = atoi(find[n].amount.c_str());
			if (help_a != 0)
			{
				find[n].write_movies();
				help_a--;
				stringstream ss; // 3 lines - convert int to string
				ss << help_a;
				find[n].amount = ss.str();


				helper << find[n].tittle << endl;
				helper << find[n].type << endl;
				helper << find[n].year << endl;
				helper << find[n].movie_time << endl;
				helper << find[n].director << endl;
				helper << find[n].actors << endl;
				helper << find[n].ID << endl;
				helper << find[n].amount << endl << endl;

				tittle_2 = find[n].tittle;
				ID_2 = find[n].ID;
				cout << "We can lend this film (" << kryterium << ").\n";

				cout << "Enter data:\n\n\t";
				cout << "\nName:            \t";	getline(cin, name_2);
				cout << "\nSurname:         \t";	getline(cin, surname_2);
				cout << "\nTelephone Number:\t";	getline(cin, tel_number_2);
				
				islending << name_2 << endl;
				islending << surname_2 << endl;
				islending << tel_number_2 << endl;
				islending << tittle_2 << endl;
				islending << ID_2 << endl;
				islending<<"DATA"<< endl<<endl; /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			}
			else if (help_a == 0)
			{
				stringstream ss; // 3 lines - convert int to string
				ss << help_a;
				find[n].amount = ss.str();


				helper << find[n].tittle << endl;
				helper << find[n].type << endl;
				helper << find[n].year << endl;
				helper << find[n].movie_time << endl;
				helper << find[n].director << endl;
				helper << find[n].actors << endl;
				helper << find[n].ID << endl;
				helper << find[n].amount << endl << endl;
				flag_2 = 1;
				cout << "We don't have this film (" << kryterium << ") right now.\n\n";
			}
			find[n].write_movies();
			flag = 1;

		}
		else {

			helper << find[n].tittle << endl;
			helper << find[n].type << endl;
			helper << find[n].year << endl;
			helper << find[n].movie_time << endl;
			helper << find[n].director << endl;
			helper << find[n].actors << endl;
			helper << find[n].ID << endl;
			helper << find[n].amount << endl << endl;
		}
		n++;
	}
	helper.close();
	islending.close();

	if (!flag) { cout << "We don't have this film (" << kryterium << ") in our base.\n\n"; }



	fstream Current_state_of_magazine;
	Current_state_of_magazine.open("Current_state_of_magazine.txt", ios::trunc);
	Current_state_of_magazine.close();


	ifstream input("helper.txt", ios::binary);           // This three lines - copying files
	ofstream output("Current_state_of_magazine.txt", ios::binary);
	output << input.rdbuf();

	helper.open("helper.txt", ios::out);
	helper.close();

} // po ID bedzie

void Raports::return_movie()
{

	string kryterium, kryterium1, kryterium2, kryterium3;
	int n = 0;
	int choice;


	Raports* find = new Raports[ka];
	Movies film;
	fstream helper, helper1;
	helper1.open("helper1.txt", ios::out);
	helper.open("Raport.txt", ios::out | ios::app);
	getline(cin, kryterium);
	cout << "\nWho is returning?\n";
	cout << "\n\tName:   \t";		getline(cin, kryterium1); //cout << kryterium1; // check 
	cout << "\n\tSurname:\t";		getline(cin, kryterium2); //cout << kryterium2; // check
	cout << "\n\nWhich movie?\n";
	cout << "\n\tTittle:\t";		getline(cin, kryterium3); //cout << kryterium3; //check
	for (int i = 1; i <= ka; i++) // Read and display selected list of lends
	{
		find[n].raport_number = n + 1;
		find[n].read_lending();

		if (find[n].name_2 == "BRAK DANYCH") break;
		if (find[n].name_2 == kryterium1 && find[n].surname_2 == kryterium2 && find[n].tittle_2 == kryterium3)
		{
			cout << "Are you sure about the returning";
			cout << "\n\t1 - Yes\n\t2 - No\n\nYour choice: "; cin >> choice;
			while (1) {
				if (choice == 1)
				{
					helper << find[n].name_2 << endl;
					helper << find[n].surname_2 << endl;
					helper << find[n].tel_number_2 << endl;
					helper << find[n].tittle_2 << endl;
					helper << find[n].ID_2 << endl;
					helper << "data" << endl;
					helper << "data" << endl << endl;
					film.update_after_return(kryterium3);

					break;
				}
				else if (choice == 2) {
					helper1 << find[n].name_2 << endl;
					helper1 << find[n].surname_2 << endl;
					helper1 << find[n].tel_number_2 << endl;
					helper1 << find[n].tittle_2 << endl;
					helper1 << find[n].ID_2 << endl;
					helper1 << "data" << endl << endl;

					break;
				}
				else
				{
					helper1 << find[n].name_2 << endl;
					helper1 << find[n].surname_2 << endl;
					helper1 << find[n].tel_number_2 << endl;
					helper1 << find[n].tittle_2 << endl;
					helper1 << find[n].ID_2 << endl;
					helper1 << "data" << endl << endl;

					cout << "There is no such choice. Try once again\n\nYour choice: "; cin >> choice;
				}
			}

		}
		else {

			helper1 << find[n].name_2 << endl;
			helper1 << find[n].surname_2 << endl;
			helper1 << find[n].tel_number_2 << endl;
			helper1 << find[n].tittle_2 << endl;
			helper1 << find[n].ID_2 << endl;
			helper1 << "data" << endl << endl;

		}
		n++;
	}
	helper.close();
	helper1.close();

	ifstream input("helper1.txt", ios::binary);           // This three lines - copying files
	ofstream output("Lended_movies.txt", ios::binary);
	output << input.rdbuf();
	//remove("helper1.txt");
}