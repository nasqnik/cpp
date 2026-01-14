#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
    
    private:
        std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        RobotomyRequestForm(const std::string& target);

        const std::string& getTarget() const;
        void setTarget(const std::string& target);

    protected:
        virtual void executeForm(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form);

#endif