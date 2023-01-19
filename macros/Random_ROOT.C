#include "TRandom.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TVector3.h"
#include "TRandom.h"
#include <iostream>

using namespace std;

// function name for a ROOT macro matches filename
void Random_ROOT(long seed = 5555){

  // declare a TRandom instance using the seed
  TRandom random(seed);

  // declare a 1D histogram
  TH1D* hist = new TH1D("hist","hist",
			100, -0.1, 1.1);

  // loop filling histogram with random numbers (uniform between (0, 1))
  int N = 1000000;
  for(int i = 0; i < N; i++){
    hist->Fill(random.Rndm());
  }

  // Draw the histogram to a canvas
  hist->Draw();

}
