//============================================================================
// Name        : Zahlenraten.cpp
// Author      : Peer Ole Rölke
// Version     : 2.0 (added a competitive more player mode  1.7 (added a log)
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <string>
#include <tuple>

using namespace std;

int randomNumber(){
	int zuRatendeZahl, groessteZahl;
	srand(time(NULL));
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


void BubbleSort(int sortArray[], int l, int AnzahlSpieler)
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
				if(AnzahlSpieler != 1){
					tempA = sortArray[(j*3)+2];
					sortArray[(j*3)+2] = sortArray[(j*3)+5];
					sortArray[(j*3)+5] = tempA;
				}
            }
        }
    }
}

tuple<int, int> morePlayerMode(int AnzahlSpieler){
	int zuRatendeZahl, gerateneZahl, Gewinner, i = 0;
	zuRatendeZahl = randomNumber();
	while(zuRatendeZahl != gerateneZahl){
		i++;
		if(AnzahlSpieler >= 2){
			for(int j = 1; j<= AnzahlSpieler; j++){
				cout <<"Dies ist ihr " << i <<". Versuch, Spieler " <<j <<". Geben sie bitte einen Tipp ab: \n";
				cin >> gerateneZahl;
				if(gerateneZahl < zuRatendeZahl){
					cout <<"Ihre Eingabe war leider zu klein! \n";
				}
				else if(gerateneZahl > zuRatendeZahl){
					cout <<"Ihre Eingabe war leider zu groß! \n";
				}
				else{
					cout <<"Glückwunsch, Spieler " << j <<"! Sie haben im " << i << ". Versuch richtig geraten! \n";
					Gewinner = j;
					j = AnzahlSpieler +1;
				}
			}
		}
		else{

		}
	}
	return {i, Gewinner};
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

	int Modus, AnzahlSpiele = 0, AnzahlSpieler = 1;
	char ja;
	// Hinweis: Array%3; == 0: Spielergebnis, == 1: Spieldurchlauf, == 2: welcher Spieler (noch unbesetzt)
	int historie[99];

	cout <<"Herzlich Willkommen beim Spiel: Zahlenraten \n";
	cout <<"Wollen Sie den normalen Modus (1), den vereinfachten Modus (0), den Mehrspielermodus (2) oder gegen den Computer (3) spielen? \n";
	cin >> Modus;
	if(Modus == 2){
		cout <<"Mit wievielen Spielern wollen sie spielen?\n";
		cin >> AnzahlSpieler;
	}
	do{
		int i, winningPlayer;
		if(Modus == 0 || Modus == 1){
			i = onePlayerMode(Modus);
		}else if(Modus == 2){
			tie(i, winningPlayer) = morePlayerMode(AnzahlSpieler);
		}else if(Modus == 3){

		}
		historie[(AnzahlSpiele * 3) +1] = AnzahlSpiele +1;
		historie[(AnzahlSpiele * 3)] = i;
		if(AnzahlSpieler != 1){
			historie[(AnzahlSpiele * 3) +2] = winningPlayer;
		}
		AnzahlSpiele++;
		cout << "Wollen Sie noch einmal spielen? (j/n) \n";
		cin >> ja;
	}while(ja == 'j' || ja == 'J');
	cout << "Auf Wiedersehen!\n" <<"Historie: \n";
	BubbleSort(historie, AnzahlSpiele, AnzahlSpieler);
	for(int j = 0; j<AnzahlSpiele; j++){
		cout <<historie[(j*3)+1] <<". Spiel:\t";
	}
	cout <<"\n";
	for(int j = 0; j<AnzahlSpiele; j++){
		cout<< historie[(j*3)] <<" Versuche\t";
	}
	cout <<"\n";
	if(Modus == 2){
		for(int j = 0; j<AnzahlSpiele; j++){
			cout <<historie[(j*3)+2] << ". Spieler\t";
		}
	}
	return 0;
}

