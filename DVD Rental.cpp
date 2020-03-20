// DVD Rental.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "Movies.h"
#include "Clients.h"
#include "Raports.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <ctime>

using namespace std;



using namespace std;
int main()
{
    cout<<time(0);

    int choice;
    Movies film;
    Clients person;
    Raports wyp;

    

    //time_t czas; //deklaracja zmiennej przechowującej czas
    //time(&czas);  //pobranie czasu z systemu
    //cout << "Aktualny czas: " << ctime(&czas);
    //return 0;


    for (;;)
    {
        cout << "--------------------------------------------------------------------\n";
        cout << "Welcome to program for DVD Rental!\n\n\nWhat would you like to do?\n\n";
        cout << "\t1  - Show complete list of owned movies\n\t2  - Show current state of magazine\n\t3  - Find movie (complete list)\n\t4  - Find movie (current state)\n\t5  - Add new movie\n\t6  - Delete movie (permanently)\n\n";
        cout << "\t7  - Show complete list of clients\n\t8  - Find client in base\n\t9  - Add new client\n\t10 - Lend film\n\t11 - Return movie\n\t12 - Show Lends\n\t13 - Show raport\n\t14 - EXIT\n";
        cout << "--------------------------------------------------------------------\n";
        cout << "Your choice: ";
        cin >> choice; 


        switch (choice)
        {
            case 1: {    film.show_all_movies();         break;}
            case 2: {    film.show_movies_in_magazine(); break;}
            case 3: {    film.find_movie();              break;}
            case 4: {    film.find_movie_in_magazine();  break;}
            case 5: {    film.new_movie();               break;}
            case 6: {    film.delete_movie();  
                         remove("helper.txt"); 
                         remove("helper2.txt");          break;}
            case 7: {    person.show_all_clients();      break;}
            case 8: {    person.find_client();           break;}
            case 9: {    person.new_client();            break;}
            case 10:{    wyp.lend_movie();
                         remove("helper.txt");           break;}
            case 11:{    wyp.return_movie();
                         remove("helper1.txt");          break;}
            case 12:{    wyp.show_lending_movies();      break;}
            case 13:{    wyp.show_raports();             break;}
            case 14:{    exit(0);                        break;}
            default:{    exit(0);     break;}
        }
    }
    
    system("pause");
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
