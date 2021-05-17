#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

double poisson(double mu, int k) {
    double a = pow(mu,k)*exp(-mu);
    double b =tgamma(k+1);
    return a/b;
}

double prob(std::vector<int> daten, double mu) {
  double like=1.0;
  for(int k : daten) {
    double ver=poisson(mu,k);
    like*=ver;
  }
  return like;
}
int main() {


  
    ifstream fin("datensumme.txt");
    vector<int> daten;
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        daten.push_back(n_i);
    }
    fin.close();

    cout <<prob(daten, 3.11538)<< std :: endl ;

    ofstream fouta("likelihood.txt");
    ofstream foutb("nll.txt");
    ofstream foutc("deltanll.txt");

    for(int i = 0 ; i <= 60 ; ++i) {
      double min = i/10.0;
      double l=prob(daten, min);
      double nlogl=-2*log(l);
      double deltanll=nlogl-2*log(prob(daten, 3.11538));

      fouta << min << " " << l << endl;
      foutb << min << " " << nlogl << endl;
      foutc << min << " " << deltanll << endl;
    }
    fouta.close();
    foutb.close();
    foutc.close();


    
}