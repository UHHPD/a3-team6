#include<iostrean>
#include<fstream>
#include<cmath>



double poisson(double mu, int k) {
    return 0;
}

int main() {
   std::ofstream fout("hispoi.txt");
    using namespace std;
    vector<int> zaehler(11);

   ifstream fin("datensumme.txt");
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i] += 1;
    }
    for(unsigned int k=0; k < zaehler.size() ; ++k){
     const double d = 3.11538;
     double a = pow(d,k);
     double b = exp (-d);
     double c = tgamma(k);
     double P = (a*b)/c;
    double Vert = P*234.0;
    std:: cout << k << ": " << zaehler[k] << ":" << Vert << std::endl;
    fout<< k << " " << zaehler[k] << " " << Vert <<std::endl;
    }
    fin.close();
    fout.close();
} 