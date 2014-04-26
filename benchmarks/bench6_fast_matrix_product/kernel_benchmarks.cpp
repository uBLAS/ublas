#include "tests.hpp"
#include <functional>
#include <iostream>
#include <fstream>
#include <ios>
#include <omp.h>

using std::cout;    using std::cerr;   using std::endl;

int main() {

    cout << "Kernels heurestics benchmark suite" << endl;

    for ( std::size_t n = 0; n != 12; n++)
    {
        std::size_t N = std::pow( 2, n );
        for ( std::size_t m = 0; m != 12; m++)
        {
            std::size_t M = std::pow( 2, m );
            for ( std::size_t l = 0; l != 12; l++)
            {
                std::size_t L = std::pow( 2, l );
                cout << "N = " << N << ", M = " << M << ", L = " << L << "-------------" << endl;
                for ( std::size_t i = 1; i != 5; i++ )
                {
                    omp_set_num_threads( i );
                    cout << "No. of threads: " << i << endl;

                    auto ps = runTests( N, M, L);

                    std::ofstream ofile;
                    ofile.open ("bench.txt", std::ios::app);
                    for ( std::size_t q = 0; q != ps.size(); q++)
                    {
                        ofile << N << ", " << M << ", " << L << ", " << ps[q].N << ", " << ps[q].M << ", " <<ps[q].L << ", " <<  i << ", " << ps[q].mflops << endl;
                    }
                    ofile.close();
                }
                cout << "\n" << endl;
            }
        }
    }

    return 0;
}
