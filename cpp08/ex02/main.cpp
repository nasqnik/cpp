#include "MutantStack.hpp"

#include <iostream>
#include <stack>

static void sep() { std::cout << "\n----------------------------------------\n"; }

static void printForward(const MutantStack<int>& m, const std::string& name)
{
    std::cout << name << " (forward): ";
    MutantStack<int>::const_iterator it = m.begin();
    MutantStack<int>::const_iterator end = m.end();
    while (it != end)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";
}

static void printReverse(const MutantStack<int>& m, const std::string& name)
{
    std::cout << name << " (reverse): ";
    MutantStack<int>::const_reverse_iterator it = m.rbegin();
    MutantStack<int>::const_reverse_iterator end = m.rend();
    while (it != end)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";
}

int main()
{
    {
        sep();
        std::cout << "---Test from Subject---"<< std::endl;
    
        MutantStack<int> mstack;
    
        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;

        mstack.pop();

        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    {
        sep();
        std::cout << "---Print forward and Print reverse test---"<< std::endl;
        MutantStack<int> m;
        m.push(1);
        m.push(2);
        m.push(3);
        m.push(4);

        printForward(m, "m");
        printReverse(m, "m");

    }
    {
        sep();
        std::cout << "--Copy constructor + const iteration test---\n";

        MutantStack<int> m;
        for (int i = 10; i <= 50; i += 10)
            m.push(i);

        printForward(m, "m");
        MutantStack<int> copy(m); 
        const MutantStack<int> cm(copy);

        printForward(cm, "cm");
        std::cout << "cm.top(): " << cm.top() << "\n";
        std::cout << "cm.size(): " << cm.size() << "\n";
    }
    {
        sep();
        std::cout << "---Assignment operator test---\n";

        MutantStack<int> a;
        a.push(42);
        a.push(43);
        printForward(a, "a");

        MutantStack<int> b;
        b.push(-1);
        printForward(b, "b /before/");

        b = a;

        printForward(b, "b /after/");
        std::cout << "b.top(): " << b.top() << "\n";
        b.pop();
        std::cout << "b.top() after pop: " << b.top() << "\n";
    }
    return 0;
}