#pragma once
#include <vector>
#include <complex>
class QuantumState {
public:
    QuantumState(int n);
    void apply_gate(const std::string& name, int target);
    void print_state() const;
private:
    std::vector<std::complex<double>> state_;
    int num_qubits_;
};
