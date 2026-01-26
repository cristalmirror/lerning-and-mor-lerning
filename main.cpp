#include <iostream>
using namespace std;
extern "C" {
    void saludar(); // Replace with actual C library header
    void despedir();
    int sumar(int a, int b); // Declaration of the Rust function
    void loop_func();
}

int main() {
    saludar(); // Call the C function
    int res = sumar(5, 7); // Call the Rust function
    cout << "Resultado de sumar desde Rust: " << res <<endl <<endl;
    loop_func();
    despedir(); // Call the C function
    return 0;
}