#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ---Orthodox Canonical Form---
Bureaucrat::Bureaucrat(): 
    _name("Default"), _grade(150) {
        std::cout << "Bureaucrat Default Constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
    _name(other._name), _grade(other._grade) {
        std::cout << "Bureaucrat Copy Constructor has been called for " << _name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat Copy Assignment Operator has been called for " << _name << std::endl;
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Default Destructor has been called for " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
    _name(name), _grade(150) {

    std::cout << "Bureaucrat Constructor has been called for " << _name << std::endl;
    setGrade(grade);
        
}

// ---Getters---
const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// ---Setter---

void Bureaucrat::setGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}


// ---Exceptions---
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too Low!";
}

// ---Actions---

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    ++_grade;
}

void Bureaucrat::signForm(AForm& f) {

    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << "." << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << _name << " couldn't sign " << f.getName() 
            << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & f) const {
    try {
        f.execute(*this);
        std::cout << _name << " executed " << f.getName() << "." << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << _name << " couldn't execute " << f.getName() 
            << " because " << e.what() << std::endl;
    }
}

// ---Operator overload---

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}