# C++ compiler
CXX = g++ 

# Paths to the folders with the necessary header files for compilation
CXX += -I/Users/christopherrogan/GitHub/matplotlib-cpp/
CXX += -I/usr/local/Cellar/python\@3.9/3.9.1_6/Frameworks/Python.framework/Versions/3.9/include/python3.9/
CXX += -I/usr/local/lib/python3.9/site-packages/numpy/core/include

# Path to the folder with the Python shared library
GLIBS =  -L/usr/local/Cellar/python\@3.9/3.9.1_6/Frameworks/Python.framework/Versions/3.9/lib/
# Flag to let the compiler know which shared library to use
GLIBS += -lpython3.9

# some compiler flags
CXXFLAGS = -std=c++14

# location of source code
SRCDIR = ./src/

# targets to make
all: Random_matplotlib.x

# recipe for building Random_matplotlib.x
Random_matplotlib.x:  $(SRCDIR)Random_matplotlib.C
	$(CXX) $(CXXFLAGS) -o Random_matplotlib.x $(GLIBS) $ $<
	touch Random_matplotlib.x

# clean-up target (make clean)
clean:
	rm -f *.x
	rm -rf *.dSYM
