#include "quantum_state.hpp"
#include "gates.hpp"
#include <iostream>
#include <cmath>
QuantumState::QuantumState(int n) : num_qubits_(n) {
    state_.resize(1 << n, {0.0, 0.0});
    state_[0] = {1.0, 0.0};
}

void QuantumState::apply_gate(const std::string& name, int target) {
    if (name == "h") apply_hadamard(state_, target, num_qubits_);
    else if (name == "x") apply_pauli_x(state_, target, num_qubits_);
}

void QuantumState::print_state() const {
    for (size_t i = 0; i < state_.size(); i++)
        std::cout << i << ": " << state_[i] << std::endl;
}
