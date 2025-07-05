#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat bob("Bob", 1);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("target A");
    PresidentialPardonForm pres("target B");

    bob.signForm(shrub);
    bob.signForm(robo);
    bob.signForm(pres);

    bob.executeForm(shrub);
    bob.executeForm(robo);
    bob.executeForm(pres);

    return 0;
}
