#include "Structure.h"

void Transitions::ArcIn(Arcs* in){
	In.push_back(in);
};

void Transitions::ArcOut(Arcs* out){
	Out.push_back(out);
};

bool Transitions::CheckFire(){
		
	//Check all arcs in to see if their places have a token. If all places have a token, can fire = true!
	int ArcCounter = 0;

	for (int i = 0; i < In.size(); i++)
	{
		if (In[i]->Question())
			ArcCounter++;
	}
	
	if (ArcCounter >= In.size()) {
		return true;
	}	
	else{
		return false;
	}
};

void Transitions::FireInDaHole(){

	//Remove a token from every arcin, add a token to every arcout.
	for (int i = 0; i < In.size(); i++)
	{
		In[i]->TokenMath(-1);
	}
	for (int i = 0; i < Out.size(); i++)
	{
		Out[i]->TokenMath(1);
	}
};

void Places::ArcIn(Arcs* in){

	//Adds a pointer to an arc, to the arcin vector.
	In.push_back(in);
};

void Places::ArcOut(Arcs* out){

	//Adds a pointer to an arc, to the arcout vector.
	Out.push_back(out);
};

void Places::TokenMath(int TokenIncrease){

	//Adds or removes a token from a place.
	TokenCount += TokenIncrease;
};

bool Places::TokenCheck(int TokenCheck){

	//Checks to see if a place has a token.
	if (TokenCount >= TokenCheck)
		return true;
	else
		return false;
};

void Arcs::AddPlace(Places* Add){

	//Adds a pointer to a place.
	Place = Add;
};

void Arcs::AddTransition(Transitions* Add){

	//Adds a transition to a place.
	Transition = Add;
};

bool Arcs::Question(){

	//Checks if the arc place has a token.
	return Place->TokenCheck(1);
};

void Arcs::TokenMath(int NoOfTokens){

	//Adds or removes a token from an arcs place.
	Place->TokenMath(NoOfTokens);

};

