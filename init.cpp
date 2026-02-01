//============== init.cpp    ==================
// file init.cpp
// init(start): start = 0: cold start
//              start = 1: hot  start
//=============================================
#include "include.h"
#include <string>

//Global variables:
int L;
int N;
int XNN;
int YNN;
int *s;
int seed;
int nsweep;
int start;
double beta;
double prob [5];
double acceptance = 0.0;

std::ranlux48 rng;
std::uniform_real_distribution<double> drandom;

void init(int argc, char **argv) {
  int i;
  int OL = -1;
  double obeta = -1.0;
  std::string buf;

  L = -1; beta = -1.; nsweep = -1; start = -1; seed = -1;
  
  get_the_options(argc, argv);

  if (start == 0 || start == 1) {
    if (L < 0) locerr ("L has not been set.");
    if (seed < 0) locerr ("seed has not been set.");
    if (beta < 0) locerr ("beta has not been set.");

    N = L * L; XNN = 1; YNN = L;
  
    s = new int [ N ] ;

    if (!s) locerr ("allocation failure for s[N]");
  }

  if (start < 0) locerr ("start has not been set.");
  if (nsweep < 0) locerr ("nsweep has not been set.");

  // Initialize probabilities:
  for (i = 2; i < 5; i += 2) prob[i] = exp(-2.0 * beta * i);

  //−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
  // Initial configuration: cold (0), hot (1), old (2)
  // − − − − − − − − − − − − − − − −
  switch (start) {
    
    case 0: // cold start
      simmessage (std::cout) ;
      rng.seed(seed);
      for (i = 0; i < N; i++) s[i] = 1;
      break;
      
    case 1: // hot start
      simmessage (std::cout) ;
      rng.seed(seed);
      for (i = 0; i < N; i++){
        if ( drandom (rng) < 0.5 )
          s[i] = 1;
        else
          s[i] = -1;
      }
      break ;

    case 2 : { // old configuration
      std::ifstream conf ( "conf" ) ;

      if ( ! conf . is_open ( ) )
      locerr ( "Configuration file conf not found" ) ;
      getline ( conf , buf ) ; // discard comment line
      conf >> buf >> OL >> buf >> OL >> buf >> obeta ;
      getline ( conf , buf ) ;
      if ( L < 0 ) L=OL ;
      if ( L != OL )
      locerr ( "Given L different from the one read from conf" ) ;
      N=L * L ; XNN =1; YNN = L ;
      if ( beta < 0 . ) beta = obeta ;
      // allocate memory space for spins :
      s = new int [ N ] ;
      if ( ! s ) locerr ( "allocation failure in s[N]" ) ;
      for ( i =0;i<N ; i++)
      if ( ( ! ( conf >> s [ i ] ) ) | | ( ( s [ i ] != −1) && ( s [ i ] != 1 ) ) )
      locerr ( "conf ended before reading s[N]" ) ;
      if ( seed >=0 ) rng . seed ( seed ) ;
      if ( seed < 0 )
      if ( ! ( conf >> rng ) )
      locerr ( "conf ended before reading mxmx" ) ;
    conf . close ( ) ;
    simmessage ( std::cout ) ;
    break ;
}

    default:
      std::cout << "start= " << start
                << " not valid. Exiting....\n";
      exit(1);
      break;
  }



}