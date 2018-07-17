// Apache 2.0 License

// Copyright (c) 2018 Juliana Hildebrandt, TU Dresden, juliana.hildebrandt@tu-dresden.de


#include <iostream>
#include <math.h>
#include <stdint.h>

using namespace std;


int main(int argc, char* argv[]){

  // setting of desired minimum hamming distance of the code words
  uint64_t dmin = 6;

	// derived desired bit flip weight
	uint64_t bfw = dmin-1;

	// iterate over different sizes of information word lengths
	for (uint64_t n = 4; n <=32; n+=4) {

		// output info about actual information word length
    cout <<"================================="<<endl;
		cout <<"information word length l = "<<n<<endl;

		// output info about desired minimum code word hamming distance
		cout <<"minimum hamming distance dmin = "<<dmin<<endl;

		uint64_t A   =(pow(2,2*bfw-1)+1) / 3 < 3? 3: (pow(2,2*bfw-1)+1) / 3;
		uint64_t k    = ceil(log(A)/log(2));

		// no parameter value for A found so far
		bool found = false;
		while (!found) {

			// bit width of A
			k    = ceil(log(A)/log(2));

			// output investigated A and bit width of A
			cout << A <<"/" << k;
			for (int i = 0; i < log(k)/log(10) + log (A)/log(10) + 2; i++) {
				cout << "\b";
			}
			uint64_t l    = n+k;

			// Initialisierung Hamminddistanz
			uint64_t d_H  = (l-ceil(log(pow(2,l)-A)/log(2))) + __builtin_popcountll(
 									(uint64_t) ( 3*( A + pow(2,ceil(log(pow(2,l)-A)/log(2))) - pow(2,l) ) ) ^
									(uint64_t)     ( A + pow(2,ceil(log(pow(2,l)-A)/log(2))) - pow(2,l) )
								);
			// erstes zu testendes Vielfaches nach Initialisierung
			uint64_t m    = 3*A;

			// Initialisierung maximales Vielfaches

			uint64_t pmax = (pow(2,n)-1)*A < pow(2,l)- pow(2,l-d_H+1) ? (pow(2,n)-1)*A : pow(2,l)-pow(2,l-d_H+1);
			//cout << "\tx:                  " << x << "\n";
			//cout << "\tInit pmax lastpos:  " << pow(2,n+k)-pow(2,n+k-bfw) << "\n";
			//cout << "\tInit pmax mult:     " << (pow(2,n)-1)*A << "\n";
			// Iteration über ungerade Vielfache
			while (m <= pmax) {
				uint64_t b = (l-ceil(log(pow(2,l)-m)/log(2))) + __builtin_popcountll(
 									(uint64_t) ( 3*( m + pow(2,ceil(log(pow(2,l)-m)/log(2))) - pow(2,l) ) ) ^
									(uint64_t)     ( m + pow(2,ceil(log(pow(2,l)-m)/log(2))) - pow(2,l) )
								);
				if (b < d_H) {
					d_H = b;
				  //cout << "Neues d_H für m = " << m << ": " << d_H << "\n";
				  if (pmax > pow(2,l)- pow(2,l-d_H+1)) {
						pmax = pow(2,l)- pow(2,l-d_H+1);
					}
				}

				m = m + 2*A;
			}

			if ( d_H >= bfw + 1)  {
				found = true;
			}
			else {
				A = A + 2;
			}
		}
	  cout <<"lower bound-oriented parameter value for A = "<<A<<endl;
	  cout <<"parameter value length k = "<<k<<endl;
	}
}
