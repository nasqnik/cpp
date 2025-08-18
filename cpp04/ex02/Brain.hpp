#pragma once

#include <string>
#include <iostream>

class Brain 
{
    protected:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain &other);
        Brain(const std::string& type);
        Brain& operator=(const Brain &other);
        virtual ~Brain();

        std::string getIdea(int i) const;
        void setIdea(int i, const std::string& idea);
};