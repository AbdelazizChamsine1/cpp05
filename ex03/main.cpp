#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        Bureaucrat bob("Bob", 1);
        bob.signForm(*rrf);
        bob.executeForm(*rrf);
        delete rrf;
    }

    AForm* bad = someRandomIntern.makeForm("coffee maker", "kitchen");
    if (bad)
        delete bad;

    return 0;
}
