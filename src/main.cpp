#include "quantum_state.hpp"
#include "stabilizer.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: ./qsim <mode> <circuit_file>" << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    std::string file = argv[2];

    if (mode == "statevector") {
        QuantumState qs(3); // 3 qubits for example
        qs.apply_gate("h", 0);
        qs.apply_gate("x", 1);
        qs.print_state();
    } else if (mode == "stabilizer") {
        simulate_stabilizer(file);
    }

    return 0;
}
