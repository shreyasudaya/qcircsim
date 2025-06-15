#pragma once
#include <vector>
#include <complex>
using Complex = std::complex<double>;

void apply_hadamard(std::vector<Complex>& state, int target, int num_qubits);
void apply_pauli_x(std::vector<Complex>& state, int target, int num_qubits);
