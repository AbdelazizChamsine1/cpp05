#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(std::string const & formName, std::string const & target);

private:
    static AForm* createShrubbery(std::string const & target);
    static AForm* createRobotomy(std::string const & target);
    static AForm* createPresidential(std::string const & target);
};

#endif
