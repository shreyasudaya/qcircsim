CXX=g++
CXXFLAGS=-std=c++17 -fopenmp -O3
LDFLAGS=

SRC=src/main.cpp src/quantum_state.cpp src/gates.cpp src/stabilizer.cpp
OBJ=$(SRC:.cpp=.o)
INCLUDE=-Iinclude

all: qsim

qsim: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

gpu:
	$(CXX) -std=c++17 -DUSE_CUQUANTUM -lcuda -lcudart -o qsim_gpu $(SRC) $(INCLUDE)

clean:
	rm -f qsim qsim_gpu $(OBJ)
