//============================================================================
// Name        : Zahlenraten.cpp
// Author      : Peer Ole Rölke
// Version     : 1.7 (added a log)
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <string>

using namespace std;

int randomNumber(){
	int zuRatendeZahl, groessteZahl;
	cout <<"\nBitte geben sie die größte Zahl ein, bis zu derer Sie raten wollen: \n";
	cin >> groessteZahl;
	zuRatendeZahl = rand() % (groessteZahl + 1);
	cout <<"Die zu ratende Zahl wurde generiert. \n\n";
	return zuRatendeZahl;
}

void vereinfachterModus(int zuRatendeZahl, int gerateneZahl){
	int abst;
	int zr1, zr15, zr2;
	string zRZ = to_string(zuRatendeZahl);
	string gZ = to_string(gerateneZahl);
	if(zRZ.length() != gZ.length()){
		cout <<"Die Zahl hat nicht die richtige Anzahl an Stellen. \n";
	}
	else if(zRZ.length() != 1){
		abst = zuRatendeZahl - gerateneZahl;
		zr1 = zRZ.length();
		zr15 = zr1 - 1;
		zr2 = 10;
		for(int i = 1; i<zr15; i++){
			zr2 = zr2 * 10;
		}
		abst = abst / zr2;
		abst = abst * zr2;
		abst = abs(abst);
		if(abst != 0){
			cout <<"Die Zahl liegt um mehr als " << abst <<" daneben! \n";
		}
		else{
			cout<< "Ganz nah dran! Weniger als " <<zr2 <<" Zahlen daneben. \n";
		}
	}
	else{
		cout <<"Sie haben es fast geschafft! \n";
	}
}


void BubbleSort(int sortArray[], int l)
{
    int i, j, tempA;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < l-i-1; j++)
        {
            // Comparing consecutive elements and switching values when value at j > j+1.
            if (sortArray[j*3] > sortArray[(j*3)+3])
            {
				tempA = sortArray[(j*3)];
				sortArray[(j*3)] = sortArray[(j*3)+3];
				sortArray[(j*3)+3] = tempA;
				tempA = sortArray[(j*3)+1];
				sortArray[(j*3)+1] = sortArray[(j*3)+4];
				sortArray[(j*3)+4] = tempA;
            }
        }
    }
}

void twoPlayerMode(){

}

int onePlayerMode(int Modus){

	int zuRatendeZahl, gerateneZahl, i = 0;
	zuRatendeZahl = randomNumber();
	while(zuRatendeZahl != gerateneZahl){
		i++;
		cout <<"Dies ist ihr " << i <<". Versuch. Geben sie bitte einen Tipp ab: \n";
		cin >> gerateneZahl;
		if(gerateneZahl < zuRatendeZahl){
			cout <<"Ihre Eingabe war leider zu klein! \n";
			if(Modus == 0){
				vereinfachterModus(zuRatendeZahl, gerateneZahl);
			}
		}
		else if(gerateneZahl > zuRatendeZahl){
			cout <<"Ihre Eingabe war leider zu groß! \n";
			if(Modus == 0){
				vereinfachterModus(zuRatendeZahl, gerateneZahl);
			}
		}
		else{
			cout <<"Glückwunsch! Sie haben im " << i << ". Versuch richtig geraten! \n";
		}
	}
	return i;
}

int main() {

	int Modus, AnzahlSpiele = 0;
	char ja;
	// Hinweis: Array%3; == 0: Spielergebnis, == 1: Spieldurchlauf, == 2: welcher Spieler (noch unbesetzt)
	int historie[99];

	cout <<"Herzlich Willkommen beim Spiel: Zahlenraten \n";
	cout <<"Wollen Sie den normalen Modus (1) oder den vereinfachten Modus (0) spielen? \n";
	cin >> Modus;
	srand(time(NULL));
	do{
		int i = onePlayerMode(Modus);
		/*int zuRatendeZahl, gerateneZahl, i = 1;
		zuRatendeZahl = randomNumber();
		while(zuRatendeZahl != gerateneZahl){
			cout <<"Dies ist ihr " << i <<". Versuch. Geben sie bitte einen Tipp ab: \n";
			cin >> gerateneZahl;
			if(gerateneZahl < zuRatendeZahl){
				cout <<"Ihre Eingabe war leider zu klein! \n";
				if(Modus == 0){
					vereinfachterModus(zuRatendeZahl, gerateneZahl);
				}
			}
			else if(gerateneZahl > zuRatendeZahl){
				cout <<"Ihre Eingabe war leider zu groß! \n";
				if(Modus == 0){
					vereinfachterModus(zuRatendeZahl, gerateneZahl);
				}
			}
			else{
				cout <<"Glückwunsch! Sie haben im " << i << ". Versuch richtig geraten! \n";
				historie[(AnzahlSpiele * 3) +1] = AnzahlSpiele +1;
				historie[(AnzahlSpiele * 3)] = i;
			}
			i++;
		}*/
		historie[(AnzahlSpiele * 3) +1] = AnzahlSpiele +1;
		historie[(AnzahlSpiele * 3)] = i;
		AnzahlSpiele++;
		cout << "Wollen Sie noch einmal spielen? (j/n) \n";
		cin >> ja;
	}while(ja == 'j' || ja == 'J');
	cout << "Auf Wiedersehen!\n" <<"Historie: \n";
	BubbleSort(historie, AnzahlSpiele);
	for(int j = 0; j<AnzahlSpiele; j++){
		cout <<historie[(j*3)+1] <<". Spiel:\t";
	}
	cout <<"\n";
	for(int j = 0; j<AnzahlSpiele; j++){
		cout<< historie[(j*3)] <<" Versuche\t";
	}
	return 0;
}

