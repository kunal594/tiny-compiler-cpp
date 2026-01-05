#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ---------------- IR Definition ----------------
struct Instruction {
    string op;        // ADD, MUL, CONST
    int val1;
    int val2;
    int result;
};

// ---------------- Tiny Compiler ----------------
class TinyCompiler {
public:
    vector<Instruction> ir;

    // Frontend: Create IR
    void addInstruction(string op, int v1, int v2) {
        ir.push_back({op, v1, v2, 0});
    }

    // Print IR
    void printIR() {
        cout << "\n--- Intermediate Representation (IR) ---\n";
        for (auto &inst : ir) {
            cout << inst.op << " " << inst.val1 << " " << inst.val2 << endl;
        }
    }

    // Optimization: Constant Folding
    void constantFolding() {
        cout << "\nRunning Optimization Pass: Constant Folding...\n";
        for (auto &inst : ir) {
            if (inst.op == "ADD") {
                inst.result = inst.val1 + inst.val2;
                inst.op = "CONST";
            }
            else if (inst.op == "MUL") {
                inst.result = inst.val1 * inst.val2;
                inst.op = "CONST";
            }
        }
    }

    // Backend: Generate pseudo machine code
    void generateCode() {
        cout << "\n--- Generated Machine-like Code ---\n";
        int memAddr = 100;
        for (auto &inst : ir) {
            if (inst.op == "CONST") {
                cout << "LOAD_CONST " << inst.result << endl;
                cout << "STORE R1 -> MEM[" << memAddr++ << "]\n";
            }
        }
    }
};

// ---------------- Main ----------------
int main() {
    TinyCompiler compiler;

    // Example Expression:
    // (2 * 5) + (3 * 4)
    compiler.addInstruction("MUL", 2, 5);
    compiler.addInstruction("MUL", 3, 4);
    compiler.addInstruction("ADD", 10, 12);

    compiler.printIR();
    compiler.constantFolding();
    compiler.generateCode();

    return 0;
}
