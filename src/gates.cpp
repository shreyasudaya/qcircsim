#include "gates.hpp"
#include <cmath>

void apply_hadamard(std::vector<Complex>& state, int target, int num_qubits) {
    size_t size = state.size();
    #pragma omp parallel for
    for (size_t i = 0; i < size; i++) {
        if ((i >> target) & 1) continue;
        size_t j = i | (1 << target);
        Complex tmp = state[i];
        state[i] = (tmp + state[j]) / std::sqrt(2);
        state[j] = (tmp - state[j]) / std::sqrt(2);
    }
}

void apply_pauli_x(std::vector<Complex>& state, int target, int num_qubits) {
    size_t size = state.size();
    #pragma omp parallel for
    for (size_t i = 0; i < size; i++) {
        if (((i >> target) & 1) == 0) {
            size_t j = i | (1 << target);
            std::swap(state[i], state[j]);
        }
    }
}
