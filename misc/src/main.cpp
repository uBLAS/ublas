#include "mult.cpp"

/***************************************************************************//**
 * @brief main
 * @param argc
 * @param argv
 * @return 0=success / 1=fail
 *
 */
int main( int argc, char** argv ) {

	//init time
	srand(time(NULL));

	//parameters declaration
	int n=M1S1, m=M2S2, k=M1M2, r=R;
	if( argc >= 4){
		n = atoi(argv[1]);
		m = atoi(argv[2]);
		k = atoi(argv[3]);
		if( argc == 5) r = atoi(argv[4]);
	}
	else if( argc>1 && argc<4 ) return 1;

	//test : simple and strassen multiplication
	DBL type1;
	mult(n,m,k,r,type1);
	int type2;
	//mult(n,m,k,r,type2);

	return 0;
}
