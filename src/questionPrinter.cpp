#include "questionPrinter.h"
#include <iostream>

void QuestionPrinter::printQuestion(const Question &q, int spaces)
{
    std::string spaceStr{};
    if (spaces)
    {
        for (int i = 0; i < spaces; i++)
            spaceStr += " ";
        if ((int)spaceStr.size() > 2)
            spaceStr += "  ";
        std::cout << spaceStr << "|\n";
        std::cout << spaceStr << "==";
    }

    if (q.getAnon())
        std::cout << "Question(id:" << q.getId() << "): " << q.getText() << '\n';
    else
        std::cout << "Question(id:" << q.getId() << ") from user(id:" << q.getFromId() << "): " << q.getText() << '\n';
    if (spaces)
        std::cout << spaceStr << "  Answer: " << q.getAns() << '\n';
    else
        std::cout << spaceStr << "Answer: " << q.getAns() << '\n';
}

void QuestionPrinter::printAskedQuestion(const Question &q)
{
    if (q.getAnon())
        std::cout << "Question(id:" << q.getId() << ") to user(id:" << q.getToId() << "): " << q.getText() << "\n";
    else
        std::cout << "Question(id:" << q.getId() << ") !AQ to user(id:" << q.getToId() << "): " << q.getText() << "\n";
    std::cout << "Answer: " << q.getAns() << "\n";
}

void QuestionPrinter::printAnsweredQuestion(const Question &q)
{
    if (q.getThreadId() != -1)
    {
        std::cout << "Parent(id: " << q.getThreadId() << ") ";
    }

    std::cout << "Question(id:" << q.getId() << ") ";
    if (!q.getAnon())
    {
        std::cout << "from user(id:" << q.getFromId() << ") ";
    }

    std::cout << "to user(id:" << q.getToId() << "): " << q.getText() << "\n";
    std::cout << "Answer: " << q.getAns() << "\n";
}
