#include <iostream>
using namespace std;
extern "C" {
    void saludar(); // Replace with actual C library header
    int sumar(int a, int b); // Declaration of the C function(Rust function)
    int loop_func();
}

int main() {
    saludar(); // Call the C function
    int res = sumar(5, 7); // Call the Rust function
    cout << "Resultado de sumar desde Rust: " << res <<endl <<endl;
    loop_func();
    return 0;
}