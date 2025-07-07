#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

AForm* Intern::createShrubbery(std::string const & target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string const & target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string const & target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const & formName, std::string const & target) {
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*creators[3])(std::string const &) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern: form \"" << formName << "\" does not exist." << std::endl;
    return NULL;
}
