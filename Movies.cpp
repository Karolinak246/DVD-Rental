#include "Movies.h"

using namespace std;


int k = 1000; // Number of movies


Movies::Movies(string m_tittle, string m_type, string m_director, string m_ID, string m_year, string m_actors, string m_availability, string m_amount, string m_time, int m_movie_number)
{
	tittle = m_tittle;
	type = m_type;
	director = m_director;
	ID = m_ID;
	year = m_year;
	actors = m_actors;
	availability = m_availability;
	amount = m_amount;
	movie_time = m_time;
	movie_number = m_movie_number;
}


Movies::~Movies() {}


int Movies::ID_Generator() //NIE TESTOWANE ----------------------------------------------------------------------------------------------------------------------------------------
{
	time(0);
	return int(time(0)); // return in ASCII
}



void Movies::read_movies()
{
	fstream list_of_movies;
	list_of_movies.open("Asortyment.txt", ios::in);

	if (list_of_movies.good() == false)
	{
		cout << "Failed to open" << endl;
		exit(0);
	}

	int number_line = (movie_number - 1) * 9 + 1;
	int current_number = 1;
	string line;

	while (getline(list_of_movies, line))
	{
		if (current_number == number_line) tittle = line;
		if (current_number == number_line + 1) type = line;
		if (current_number == number_line + 2) year = line;
		if (current_number == number_line + 3) movie_time = line;
		if (current_number == number_line + 4) director = line;
		if (current_number == number_line + 5) actors = line;
		if (current_number == number_line + 6) ID = line;
		if (current_number == number_line + 7) amount = line;

		current_number++;
	}

	list_of_movies.close();
}



void Movies::write_movies()
{
	cout << "Tittle:            \t" << tittle   << endl;
	cout << "Type:              \t" << type     << endl;
	cout << "Year of production:\t" << year     << endl;
	cout << "Time:              \t" << movie_time     << endl;
	cout << "Director:          \t" << director << endl;
	cout << "Main actors:       \t" << actors   << endl;
	cout << "ID:                \t" << ID       << endl;
	cout << "Amount of DVD:     \t" << amount   << endl << endl << endl;
}



void Movies::show_all_movies()
{
	int n = 0;
	int help = 0;
	//int k = 10; // Number of movies

	Movies* film = new Movies[k];
	cout << endl << "Complete list of movies" << endl << endl << endl;
	for (int i = 1; i <= k; i++) // Read and display list of films
	{
		film[n].movie_number = n + 1;
		film[n].read_movies();
		if (film[n].tittle == "BRAK DANYCH") break; 
		film[n].write_movies();
		help = help + atoi(film[n].amount.c_str());  // Count all of owned discs
		n++;
	}
	cout << "--------------------------------------------------------------------\n\nSummary:\t" << n << " movies\nSummary:\t" << help << " discs\n\n";
}


void Movies::show_movies_in_magazine()
{

	int n = 0;
	int help = 0;
	//int k = 10; // Number of movies

	Movies* film = new Movies[k];
	cout << endl << "Complete list of movies" << endl << endl << endl;
	for (int i = 1; i <= k; i++) // Read and display list of films
	{
		film[n].movie_number = n + 1;
		film[n].read_state_in_magazine();
		if (film[n].tittle == "BRAK DANYCH") break;
		film[n].write_movies();
		help = help + atoi(film[n].amount.c_str());  // Count all of owned discs
		n++;
	}
	cout << "--------------------------------------------------------------------\n\nSummary:\t" << n << " movies\nSummary:\t" << help << " discs\n\n";
}



void Movies::find_movie()
{
	string kryterium;
	int n = 0;
	bool flag = 0;


	Movies* find = new Movies[k];
	cout << endl << "Which movie are you looking for?" << endl;
	getline(cin, kryterium); 
	getline(cin, kryterium); cout << endl;
	for (int i = 1; i <= k; i++) // Read and display selected list of films
	{
		find[n].movie_number = n + 1;
		find[n].read_movies();
		if (find[n].tittle == kryterium)
		{
			cout << "We have this film (" << kryterium << ") in our base. There are information about that: \n\n";
			find[n].write_movies();
			flag = 1;
			break;
		}
		n++;
	}
	if (!flag) {
		cout << "We don't have this film (" << kryterium << ") in our base.\n\n";
	}
}

void Movies::find_movie_in_magazine()
{

	string kryterium;
	int n = 0;
	bool flag = 0;


	Movies* find = new Movies[k];
	cout << endl << "Which movie are you looking for?" << endl;
	getline(cin, kryterium);
	getline(cin, kryterium); cout << endl;
	for (int i = 1; i <= k; i++) // Read and display selected list of films
	{
		find[n].movie_number = n + 1;
		find[n].read_state_in_magazine();
		if (find[n].tittle == kryterium)
		{
			cout << "We have this film (" << kryterium << ") in our base. There are information about that: \n\n";
			find[n].write_movies();
			flag = 1;
			break;
		}
		n++;
	}
	if (!flag) {
		cout << "We don't have this film (" << kryterium << ") in our base.\n\n";
	}
}



void Movies::new_movie() 
{
	string end_of;
	getline(cin, end_of);


	cout << "Add new movie:\n";
	cout << "Tittle:                              ";	getline(cin, tittle);
	cout << "Type                                 ";	getline(cin, type);
	cout << "Year of production:                  ";	getline(cin, year);
	cout << "Time:                                ";	getline(cin, movie_time);
	cout << "Director:                            ";	getline(cin, director);
	cout << "Main actors [actor1], [actor2],... : ";	getline(cin, actors);
	cout << "Amount of discs:                     ";	getline(cin, amount);
	ID = ID_Generator();

	ofstream list_of_movies;
	list_of_movies.open("Asortyment.txt", ios::app);


	list_of_movies <<endl<< tittle << endl;		cout << endl;
	list_of_movies << type <<	  endl;			cout << endl;
	list_of_movies << year <<	  endl;			cout << endl;
	list_of_movies << movie_time <<	  endl;			cout << endl;
	list_of_movies << director << endl;			cout << endl;
	list_of_movies << actors <<	  endl;			cout << endl;
	list_of_movies << ID <<		  endl;			cout << endl;
	list_of_movies << amount <<   endl;			cout << endl << endl;

	list_of_movies.close();

	ofstream list_of_state;
	list_of_state.open("Current_state_of_magazine.txt", ios::app);


	list_of_state << endl << tittle << endl;		cout << endl;
	list_of_state << type << endl;			cout << endl;
	list_of_state << year << endl;			cout << endl;
	list_of_state << movie_time << endl;			cout << endl;
	list_of_state << director << endl;			cout << endl;
	list_of_state << actors << endl;			cout << endl;
	list_of_state << ID << endl;			cout << endl;
	list_of_state << amount << endl;			cout << endl << endl;

	list_of_state.close();

	cout << "Movie with tittle: " << tittle << " has been successfuly saved in base.\n";
}

void Movies::read_state_in_magazine()
{

		fstream list_of_movies;
		list_of_movies.open("Current_state_of_magazine.txt", ios::in);

		if (list_of_movies.good() == false)
		{
			cout << "Failed to open" << endl;
			exit(0);
		}

		int number_line = (movie_number - 1) * 9 + 1;
		int current_number = 1;
		string line;

		while (getline(list_of_movies, line))
		{
			if (current_number == number_line) tittle = line;
			if (current_number == number_line + 1) type = line;
			if (current_number == number_line + 2) year = line;
			if (current_number == number_line + 3) movie_time = line;
			if (current_number == number_line + 4) director = line;
			if (current_number == number_line + 5) actors = line;
			if (current_number == number_line + 6) ID = line;
			if (current_number == number_line + 7) amount = line;

			current_number++;
		}

		list_of_movies.close();
	
}


void Movies::update_after_return(string kryterium) // lend_movie
{

	string end_of;
	int n = 0;
	bool flag = 0;
	int help_a;


	Movies* find = new Movies[k];
	fstream helper;
	helper.open("helper.txt", ios::out);
	cout << endl << "Which movie are you looking for?" << endl;
	getline(cin, end_of);

	//getline(cin, kryterium); cout << endl;
	for (int i = 1; i <= k; i++) // Read and display selected list of films
	{
		find[n].movie_number = n + 1;
		find[n].read_state_in_magazine();

		if (find[n].tittle == "BRAK DANYCH") break;
		if (find[n].tittle == kryterium)
		{
			help_a = atoi(find[n].amount.c_str());

				help_a++;
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

				cout << "The movie (" << kryterium << ")has returned.\n\n";

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

	if (!flag) {
		cout << "We don't have this film (" << kryterium << ") in our base.\n\n";
	}

	fstream Current_state_of_magazine;
	Current_state_of_magazine.open("Current_state_of_magazine.txt", ios::trunc);
	Current_state_of_magazine.close();


	ifstream input("helper.txt", ios::binary);           // This three lines - copying files
	ofstream output("Current_state_of_magazine.txt", ios::binary);
	output << input.rdbuf();

	helper.open("helper.txt", ios::out);
	helper.close();
	//remove("helper.txt");
}



void Movies::delete_movie()
{
	string kryterium;
	int n = 0;
	int choice;


	Movies* find = new Movies[k];
	Movies* find2 = new Movies[k];
	fstream helper, helper2;
	helper.open("helper.txt", ios::out);
	helper2.open("helper2.txt", ios::out);
	cout << endl << "Which movie are you looking for?" << endl;
	getline(cin, kryterium);
	getline(cin, kryterium); cout << endl;
	for (int i = 1; i <= k; i++) // Read and display selected list of films
	{
		find[n].movie_number = n + 1;
		find2[n].movie_number = n + 1;
		find[n].read_state_in_magazine();
		find2[n].read_movies();

		if (find[n].tittle == "BRAK DANYCH") break;
		if (find[n].tittle == kryterium)
		{
			cout << "We found this film in our base. Are you sure, that you want to delete it?";
			cout << "\n\t1 - Yes\n\t2 - No\n\nYour chosie: "; cin >> choice;
			while (1) {
				if (choice == 2)
				{
					helper << find[n].tittle << endl;
					helper << find[n].type << endl;
					helper << find[n].year << endl;
					helper << find[n].movie_time << endl;
					helper << find[n].director << endl;
					helper << find[n].actors << endl;
					helper << find[n].ID << endl;
					helper << find[n].amount << endl << endl;

					helper2 << find2[n].tittle << endl;
					helper2 << find2[n].type << endl;
					helper2 << find2[n].year << endl;
					helper2 << find2[n].movie_time << endl;
					helper2 << find2[n].director << endl;
					helper2 << find2[n].actors << endl;
					helper2 << find2[n].ID << endl;
					helper2 << find2[n].amount << endl << endl;

					break;
				}
				else if (choice == 1) { break; }
				else
				{
					cout << "There is no such choice. Try once again\n\nYour choice: "; cin >> choice;
				}
			}

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

			helper2 << find2[n].tittle << endl;
			helper2 << find2[n].type << endl;
			helper2 << find2[n].year << endl;
			helper2 << find2[n].movie_time << endl;
			helper2 << find2[n].director << endl;
			helper2 << find2[n].actors << endl;
			helper2 << find2[n].ID << endl;
			helper2 << find2[n].amount << endl << endl;

		}
		n++;
	}
	helper.close();

	fstream Current_state_of_magazine;
	Current_state_of_magazine.open("Current_state_of_magazine.txt", ios::trunc);
	Current_state_of_magazine.close();

	fstream magazine;
	magazine.open("Asortyment.txt", ios::trunc);
	magazine.close();


	ifstream input("helper.txt", ios::binary);           // This three lines - copying files
	ofstream output("Current_state_of_magazine.txt", ios::binary);
	output << input.rdbuf();

	ifstream input2("helper2.txt", ios::binary);           // This three lines - copying files
	ofstream output2("Asortyment.txt", ios::binary);
	output2 << input2.rdbuf();
	
	helper.open("helper.txt", ios::out);
	helper.close();

	helper2.open("helper2.txt", ios::out);
	helper2.close();

	//remove("helper.txt");
	//emove("helper2.txt");

	
}