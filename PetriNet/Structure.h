#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

class Transitions;
class Arcs;
class Places;

class Transitions{

private:
	vector<Arcs*>In;
	vector<Arcs*>Out;
public:
	Transitions(){};
	void ArcIn(Arcs*);
	void ArcOut(Arcs*);
	bool CheckFire();
	void FireInDaHole();
};

class Places{

private:
	vector<Arcs*>In;
	vector<Arcs*>Out;
	int TokenCount;
public:
	Places(){};
	void ArcIn(Arcs*);
	void ArcOut(Arcs*);
	void TokenMath(int);
	bool TokenCheck(int);
};

class Arcs{

private:
	Places* Place;
	Transitions* Transition;
public:
	void AddPlace(Places*);
	void AddTransition(Transitions*);
	bool Question();
	void TokenMath(int);
};
