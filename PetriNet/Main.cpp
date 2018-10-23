#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "Structure.h"

#define MAX_DFA_STATES 10
#define MAX_ALPHABET_SIZE 10

using namespace std;
int transitions[MAX_DFA_STATES][MAX_ALPHABET_SIZE];
bool finalStates[MAX_DFA_STATES];
char input_string[100000];

int main() {

	//Holder values
	vector<Places> HPlaces;
	vector<Transitions> HTransitions;
	vector<Arcs> HArcs;

	//Places, Transitions, Arcs, Places2Transitions,Transitions2Places, Tokens
	int P, T, A, P2T, T2P, Tokes;
	//Temp Tokens, Arcs, Places & Transitions
	int TTokes, TArcs, TPlaces, TTransitions;
	
	char* p;
	ifstream fin("DFA.txt");
	fin >> P >> T >> A >> P2T >> T2P >> Tokes;
	for (int i = 0; i < P; i++) {
		Places *TempPlace = new Places();
		HPlaces.push_back(*TempPlace);
	}
	for (int i = 0; i < T; i++) {
		Transitions *TempPlace = new Transitions();
		HTransitions.push_back(*TempPlace);
	}
	for (int i = 0; i < A; i++) {
		Arcs *TempPlace = new Arcs();
		HArcs.push_back(*TempPlace);
	}
	for (int i = 0; i < P2T; i++){
		fin >> TPlaces >> TArcs >> TTransitions;
		HPlaces[TPlaces].ArcOut(HArcs[TArcs]);
		HArcs[TArcs].AddPlace(HPlaces[TPlaces]);
		HArcs[TArcs].AddTransition(*HTransitions[TTransitions]);
		HTransitions[TTransitions].ArcIn(*HArcs[TArcs]);
	}
	for (int i = 0; i < T2P; i++){
		fin >> TTransitions >> TArcs >> TPlaces;
		HTransitions[TTransitions].ArcOut(HArcs[TArcs]);
		HPlaces[TPlaces].ArcIn(HArcs[TArcs]);
		HArcs[TArcs].AddPlace(HPlaces[TPlaces]);
		HArcs[TArcs].AddTransition(HTransitions[TTransitions]);
	}
	for (int i = 0; i < Tokes; i++){
		fin >> TTokes >> TPlaces;
		HPlaces[TPlaces].TokenMath(1);
	}
	fin.close();
	//In a while loop, choose a transition, check if it can fire, and fire it if it can. Else pick another transition. Print tokens, Ask to step. 
	
	while ()
	{

	}

	while (input_string[0] != '.') {
		state = 0;
		p = strtok(input_string, " ");
		while (p) {
			symbol = atoi(p);
			if (symbol <= 0 || symbol > M) {
				printf("Invalid input symbol %d.\n", symbol);
				return -1;
			}
			else {
				state = transitions[state][symbol];
			}
			p = strtok(NULL, " ");
		}
		if (finalStates[state])
			printf("String accepted.\n");
		else
			printf("String rejected.\n");
		printf("Enter a string ('.' to exit) : ");
		scanf("%[^\n]%*c", input_string);
}