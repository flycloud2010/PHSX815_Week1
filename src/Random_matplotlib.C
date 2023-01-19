#include <iostream>
#include <vector>

#include "matplotlibcpp.h"

using namespace std;

namespace plt = matplotlibcpp;

////////////////
// Random class
////////////////
// class to generate pseudo-random numbers
class Random {
  
public:
  // constructor for class instance (has optional seed argument, with default value
  Random(unsigned long long seed = 5555){
    m_v = 4101842887655102017LL;
    m_w = 1;
    
    m_u = seed ^ m_v;
    int64();
    m_v = m_u;
    int64();
    m_w = m_v;
    int64();
  }

  // destructor for our class (no internal members that need to be deleted)
  virtual ~Random(){

  }

  // function returns a random 64 bit integer
  unsigned long long int64(){
    m_u = m_u * 2862933555777941757LL + 7046029254386353087LL;
    m_v ^= m_v >> 17;
    m_v ^= m_v << 31;
    m_v ^= m_v >> 8;
    m_w = 4294957665U*(m_w & 0xffffffff) + (m_w >> 32);
    unsigned long long x = m_u ^ (m_u << 21);
    x ^= x >> 35;
    x ^= x << 4;
    return (x + m_v) ^ m_w;
  }

  // function returns a random 32 bit integer
  unsigned int int32(){
    return (unsigned int)int64(); 
  }

  // function returns a random double between (0, 1) (uniform)
  double rand(){
    return 5.42101086242752217E-20 * int64();
  }

private:
  // private member variables stored inside class instance (random number
  // generator has an internal memory)
  unsigned long long m_seed;
  unsigned long long m_u;
  unsigned long long m_v;
  unsigned long long m_w;

};

// main function for compiled executable
int main(int argc, char* argv[]){
  bool printhelp = false;
  long seed = 5555;

  // parsing any command line options added by the user
  for(int i = 0; i < argc; i++){
    if(strncmp(argv[i],"--help", 6) == 0){
      printhelp = true;
    }
    if(strncmp(argv[i],"-h", 2) == 0){
      printhelp = true;
    }
    if(strncmp(argv[i],"-seed", 5) == 0){
      i++;
      seed = std::stol(argv[i]);
    }
  }

  // print the executable usage options if the user adds -h or --help
  if(printhelp){
    cout << "Usage: " << argv[0] << " [options]" << endl;
    cout << "  options:" << endl;
    cout << "   --help(-h)          print options" << endl;
    cout << "   -seed [number]      random seed to use" << endl;
   
    return 0;
  }

  // declare an instance of our Random class
  Random  random(seed);
  // declare an instance of our Random class, with a pointer to the instance
  Random* random_ptr = new Random(seed);
  
  int N = 5000; // 5000 random data points

  // fill a vector with pseudo-random numbers
  vector<double> x;
  for(int i = 0; i < N; ++i){
    x.push_back(random.rand());
    //x.push_back(random_ptr->rand()); // this is the syntax for using the pointer
  }

  plt::figure(); // declare a new figure (optional if only one is used)

  // formating options for our figure
  plt::hist(x, 50, "b", 0.75);
  plt::title("Uniform random number"); 
  plt::xlabel("x");
  plt::ylabel("Counts");

  plt::show();
  plt::savefig("random.pdf"); // save the figure

  // clean up memory we allocated in program
  delete random_ptr;
}

