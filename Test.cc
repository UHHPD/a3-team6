
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

double poisson(double mu, int k){
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
    int n_i;
    vector<int> zaehler(11);
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i] += 1;

  
  
    
   ofstream foutp("Likelihood-Quotient.txt");
    
   for(unsigned int k=0; k < zaehler.size() ; ++k){
     fin >> n_i;
     const double d = 3.11538;
     double a = pow(d,k)*exp (-d);
     double b = exp (-n_i)*exp (-n_i);
     double Quotient = b/a;

   foutp << Quotient << endl;
   }
   fin.close();
   foutp.close();
  
  
  return n_i;


    vector<int> daten;
  
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
}