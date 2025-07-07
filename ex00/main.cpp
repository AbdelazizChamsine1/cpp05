#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat john("John", 2);
        std::cout << john << std::endl;

        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;

        john.incrementGrade(); // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat jane("Jane", 149);
        std::cout << jane << std::endl;

        jane.decrementGrade();
        std::cout << "After decrement: " << jane << std::endl;

        jane.decrementGrade(); // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalid("Invalid", 0); // Throws at construction
    } catch (const std::exception& e) {
        std::cerr << "Construction failed: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalid2("Invalid2", 200); // Throws at construction
    } catch (const std::exception& e) {
        std::cerr << "Construction failed: " << e.what() << std::endl;
    }

    return 0;
}
