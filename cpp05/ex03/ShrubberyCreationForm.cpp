#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm("ShrubberyCreationForm", 145, 137), _target("default") {
    std::cout << "ShrubberyCreationForm Default Constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
    AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm Copy Constructor has been called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm Copy Assignment Operator has been called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
    AForm("ShrubberyCreationForm", 145, 137), _target(target)  
{
    std::cout << "ShrubberyCreationForm Constructor has been called for " << _target << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::setTarget(const std::string& target) {
    _target = target;
}

void ShrubberyCreationForm::executeForm(Bureaucrat const &executor) const {
    std::string fileName = _target + "_shrubbery";
    std::ofstream file(fileName.c_str());
    
    std::cout << executor.getName() << " created Shrubbery Form " << fileName << std::endl; 
    
    if (!file.is_open()) {
        std::cerr << "Error: Couldn't create file " << fileName << std::endl;
        return; 
    }

    file << "          &&& &&  & &&" << std::endl;
    file << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
    file << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    file << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
    file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    file << "     &&     \\|||" << std::endl;
    file << "             |||" << std::endl;
    file << "             |||" << std::endl;
    file << "             |||" << std::endl;
    file << "       , -=-~  .-^- _" << std::endl;
    
    file.close();
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form) {
    os << static_cast<const AForm&>(form);
    os << " Target: " << form.getTarget() << "." ;
    return os;
}