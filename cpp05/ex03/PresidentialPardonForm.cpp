#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
    AForm("PresidentialPardonForm", 25, 5), _target("default") {
        std::cout << "PresidentialPardonForm Default Constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
    AForm(other), _target(other._target) {
        std::cout << "PresidentialPardonForm Copy Constructor has been called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm Copy Assignment Operator has been called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
    AForm("PresidentialPardonForm", 25, 5), _target(target) {
        std::cout << "PresidentialPardonForm Constructor has been called for " << _target << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const {
    return _target;
}

void PresidentialPardonForm::setTarget(const std::string& target) {
    _target = target;
}

void PresidentialPardonForm::executeForm(Bureaucrat const &executor) const {

    std::cout << executor.getName() << " created Presidential Pardon Form for " << _target << std::endl; 

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;

}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form) {
    os << static_cast<const AForm&>(form);
    os << " Target: " << form.getTarget() << "." ;
    return os;
}