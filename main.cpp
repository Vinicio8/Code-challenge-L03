# Code-challenge-L03

#include < iostream >

#include < tuple >

#include < string >

#include < map >

#include < type_traits >

template <typename T>
void checkLvalue(const T&) {
    std::cout << "Lvalue\n";
}

template <typename T>
void checkLvalue(T&&) {
    if constexpr (std::is_lvalue_reference_v<T>) {
        std::cout << "Lvalue\n";
    } else {
        std::cout << "Rvalue\n";
    }
}

int main() {
    int x1 = 10;      
    double x2 (20.5); 
    std::string x3{"Hello"}; 
    bool x4 = {true}; 
    
    std::cout << "Initial values:\n";
    std::cout << "int: " << x1 << ", double: " << x2 << ", string: " << x3 << ", bool: " << x4 << std::endl;

    int& ref1 = x1;
    x1 = 18;
    double& ref2 = x2;
    x2 = 13.2;
    std::string& ref3 = x3;
    x3 = "Bye";
    bool& ref4 = x4;
    x4 = false;

    std::cout << "Modified values:\n";
    std::cout << "int: " << x1 << ", double: " << x2 << ", string: " << x3 << ", bool: " << x4 << std::endl;
    
    int a = 42;
    int b = 10;
    int x = a + b;
    std::string c = "Hello";
    std::string s = c + " World";
    int& refX = x;
    int&& rref = 100;

    std::cout << "\nExpression 1 (a): ";
    checkLvalue(a);

    std::cout << "Expression 2 (a + b): ";
    checkLvalue(a + b);

    std::cout << "Expression 3 (&a): ";
    std::cout << "Lvalue (Address-of operator always applied to lvalues)\n";

    std::cout << "Expression 4 (c + \" World\"): ";
    checkLvalue(c + " World");

    std::cout << "Expression 5 (refX): ";
    checkLvalue(refX);

    std::cout << "Expression 6 (rref): ";
    checkLvalue(rref);

    return 0;
}
