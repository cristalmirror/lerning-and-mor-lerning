#include <iostream>
#include <string>

using namespace std;

struct Obj;

// Declarations of external C and Rust functions
extern "C" {
    void saludar(); // Replace with actual C library header
    void despedir();
    int sumar(int a, int b); // Declaration of the Rust function
    void loop_func();
    Obj *create_object(int id);
    int object_comand(Obj* obj, int command,int num);
    void destroy_object(Obj* obj);
    void graph_function(char **data_graph);
    void digraph_function(char **data_graph);
    void tree_function(char **data_graph);
}

// Main function
int main(int argc,char *argv[]) {
    saludar(); // Call the C function
    int comand,comand_res,num,res;    
    Obj* obj = create_object(42); 
    switch (stoi(argv[1])) {
        case 1: graph_function(&argv[2]); break;
        case 2: digraph_function(&argv[2]); break;
        case 3: tree_function(&argv[2]); break;
        case 4: //Rust operations.
            res = sumar(stoi(argv[2]), stoi(argv[3])); // Call the Rust function
            cout << "Resultado de sumar desde Rust: " << res <<endl <<endl;
        break;
        case 5:
            comand = stoi(argv[2]), num = stoi(argv[3]);
            comand_res = object_comand(obj, comand, num);
            cout << "Resultado de object_comand: " << comand_res << endl << endl;
            destroy_object(obj);
        break;
        default: cerr << "Error: arguments are invalid " <<endl; break;
    }
    
    loop_func();
    despedir(); // Call the C function
    return 0;
}