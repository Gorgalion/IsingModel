//============== include.h   ==================
#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>

extern int L;
extern int N;
extern int XNN;
extern int YNN;
extern int *s;

extern int seed, nsweep, start;
extern double beta;
extern double prob[5];

extern std::ranlux48 rng;
extern std::uniform_real_distribution <double> drandom;

int E(),M();
void init(int ), met(), measure();

void std::simmessage(ostream&); locerr(string);
void usage(char **);
void get_the_options(int, char **), endsim();
