
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

double prob2(std::vector<int> daten){
  double like=1;
  for(int k : daten) {
    double ver=poisson(k,k);
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

   cout <<prob(daten, 3.11538)<< endl ;
  
   
   ofstream foutp("Likelihood-Quotient.txt");
   double Lambda = prob(daten, 3.11538)/prob2(daten);
   double LNLambda=-2*log(Lambda);

   cout << LNLambda << endl;
     
    int e = 233;
    double z = (-2*log(Lambda)-e)/sqrt(2*e);
    
    
    foutp << Lambda << endl;
    cout << z << endl;
   
    fin.close();
    foutp.close();
    

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