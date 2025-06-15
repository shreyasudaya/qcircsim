# Quantum Simulator

A high-performance quantum circuit simulator using C++17, OpenMP, and optional GPU acceleration (cuQuantum).

## Features
- State-vector simulation
- Stabilizer simulation
- Multithreading with OpenMP
- Optional GPU via cuQuantum

## Build
### CPU
```
make
./qsim statevector circuits/example.qc
```

### GPU
Install cuQuantum SDK, then:
```
make gpu
./qsim_gpu statevector circuits/example.qc
```
