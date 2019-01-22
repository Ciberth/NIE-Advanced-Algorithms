#ifndef __SIMULANNEAL
#define __SIMULANNEAL
#include <cstdlib>
#include <memory>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
using namespace std;

//abstracte klasse voor simulated annealing
//Hier worden GEEN probleemafhankelijke functies gedefinieerd
//deze zijn allemaal virtual.
//Notaties: zie Blum and Roli
//Parameter S: De oplossing (zowel de voorlopige als de uiteindelijke)
//is een S. S staat voor Search space


template <class S>
class SimulatedAnnealing{
public:
    S oplossing(){
        T=T0();
        s=initialSolution();
        while (!terminateCond()){
            S sprime=pickAtRandom(s);
            double deltaf=f(sprime)-f(s);
            if (deltaf < 0 || rand()<p(T,deltaf)*RAND_MAX){
                s=std::move(sprime);
            }            
            updateT();
        }
        return s;
    }

protected:
    double T;//temperatuur;
    S s;//voorlopige en eindoplossing.
    virtual double T0()=0;//initi"ele temperatuur
    virtual bool terminateCond()=0;//true als stoppen met zoeken
    virtual double f(const S&)=0;//objectieffunctie. Moet > 0 blijven
    virtual S initialSolution()=0;
    virtual S pickAtRandom(const S&)=0;
    virtual double p(double T, double deltaf)=0;//probabiliteit verandering
    virtual void updateT()=0;
};

double afstand(pair<int,int> a, pair<int,int> b){
	auto x = a.first - b.first;
	auto y = a.second - b.second;
	return sqrt(x*x+y*y);
}

double afstandTest(pair<int,int> a, pair<int,int> b){
	return pow(a.first-b.first,2) + pow(a.second - b.second, 2);
}

class KerstmanAnnealing : public SimulatedAnnealing<vector<int>> {
	public:
		KerstmanAnnealing(vector<pair<int,int>> c) : coos(c) {}
		double geefAfstand(const vector<int> &v){
//			auto af = overloop(v, [](pair<int,int> p1, pair<int,int> p2){
//				return afstand(p1,p2);
//			});	
			return f(v);
		}
		float geefIteraties() {
			return iteraties;
		}
	protected:
		double T0() override;
		bool terminateCond() override;
	    double f(const vector<int>&) override;
	    vector<int> initialSolution() override;
	    vector<int> pickAtRandom(const vector<int>&) override;
	    double p(double T, double deltaf) override;
	    void updateT() override;
	    double overloop(const vector<int>& v, std::function<double(pair<int,int> p1, pair<int,int> p2)> lambda);
	private:
		vector<pair<int,int>> coos;
		unsigned long iteraties = 0;
};

double KerstmanAnnealing::T0(){
	return 1000000;// getest met 10000
}


bool KerstmanAnnealing::terminateCond(){
	if(iteraties % 100000 == 0){
		std::cout << "Temp = " << T << std::endl;
	}
	iteraties++;
	return T < 1;
}

// lamba berekent de afstand
double KerstmanAnnealing::overloop(const vector<int>& v, std::function<double(pair<int,int> p1, pair<int,int> p2)> lambda){
	double af = 0;
	for(int i=0; i < v.size()-1; i++) {
		auto current  = coos[v[i]];
		auto volgende = coos[v[i+1]];
		af += lambda(current, volgende);
	}
	
	// maak er cirtcuit van
	af += lambda(coos[v[v.size()-1]], coos[v[0]]);
	return af;
}

double KerstmanAnnealing::f(const vector<int>& v) {
//	auto af = overloop(v, [](pair<int,int> p1, pair<int,int> p2){
//		return afstand(p1,p2);
//	});	

	double af = 0;
	for(int i=0; i < v.size()-1; i++) {
		auto current  = coos[v[i]];
		auto volgende = coos[v[i+1]];
		af += afstand(current, volgende);
	}
	
	// maak er cirtcuit van
	af += afstand(coos[v[v.size()-1]], coos[v[0]]);
	return af;
}


vector<int> KerstmanAnnealing::initialSolution() { 
	
	// randomizen voor optimalisatie
	
	vector<int> sol;
	for(int i=0; i < coos.size(); i++) {
		sol.push_back(i);
	}
	
	// c++14 shuffle is depricated
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::shuffle( sol.begin(), sol.end(), std::default_random_engine(seed) );
	return sol;
}


vector<int> KerstmanAnnealing::pickAtRandom(const vector<int>& v) {
	
	vector<int> nieuw(v);
	
	auto r1 = rand() % v.size();
	auto r2 = rand() % v.size();
	
	swap(nieuw[r1],nieuw[r2]);
	
	return nieuw;
}


double KerstmanAnnealing::p(double T, double deltaf) {
	
	if(deltaf < 0) {
		return 1.0;
	} 
	
	return exp(-deltaf/T);
}


void KerstmanAnnealing::updateT() {
	T *= 0.999999; // getest met 3,4,5 9's
}



#endif























