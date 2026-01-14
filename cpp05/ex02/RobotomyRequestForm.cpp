#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
    AForm("RobotomyRequestForm", 72, 45), _target("default") {
     std::cout << "RobotomyRequestForm Default Constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
    AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm Copy Constructor has been called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm Copy Assignment Operator has been called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : 
    AForm("RobotomyRequestForm", 72, 45), _target(target)  
{
    std::cout << "RobotomyRequestForm Constructor has been called" << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::setTarget(const std::string& target) {
    _target = target;
}

void RobotomyRequestForm::executeForm(Bureaucrat const &executor) const {

    std::cout << executor.getName() << " created Robotomy Request Form for " << _target << std::endl; 

    std::cout << "* DRILLING NOISES... *" << std::endl;
    
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << std::endl;

}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form) {
    os << static_cast<const AForm&>(form);
    os << " Target: " << form.getTarget() << "." ;
    return os;
}