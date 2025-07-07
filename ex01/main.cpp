#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat a("Alice", 40);
        Bureaucrat b("Bob", 145);

        Form formA("FormA", 50, 100);
        Form formB("FormB", 140, 100);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        a.signForm(formA); // should succeed
        b.signForm(formA); // should fail
        b.signForm(formB); // should succeed

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        Form invalid("BadForm", 0, 160); // throws
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
