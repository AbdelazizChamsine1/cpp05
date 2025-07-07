#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& t)
    : AForm("PresidentialPardonForm", 25, 5), target(t) {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    checkExecute(executor);
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
