//============== main.cpp    ==================
#include "include.h"

int main(int argc, char **argv) {

  init(argc, argv);

  for(int isweep = 0; isweep < nsweep; isweep++){
    met();

    // for (int i = 0; i < N; i++)
    //   std::cout << s[i] << " ";
    
    // std::cout << std::endl;

    measure();
  }

  endsim();
}
