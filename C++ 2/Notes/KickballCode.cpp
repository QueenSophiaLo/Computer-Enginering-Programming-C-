/*
KICKBALL
-create a class (stats we want to track)
	-homeruns
	-kick distance
	-catches/outs
One instance of a game played by each team
*/

#include<string>
#include <iostream>

using namespace std;

class Kickball {
	public:
	void SetHR(int HR);
	void SetOuts(int Outs);
	void SetKD(double KD);
	int GetHR();
	int GetOuts();
	double GetKD();
	private:
	int homeruns;
	int outs;
	double kickDistance;
};

void Kickball::SetHR(int HR) {
	this->homeruns;
	homeruns = HR;
}
void Kickball::SetOuts(int Outs) {
	this->outs;
	outs = Outs;
}
void Kickball::SetHR(int KD) {
	this->kickDistance;
	kickDistance = KD;
}
int Kickball::GetHR() {
	return homeruns;
}
int Kickball::GetOuts() {
	return outs;
}
double Kickball::GetKD() {
	return kickDistance;
}

int main() {
	
	// FIXME Not done

	return 0;
}
