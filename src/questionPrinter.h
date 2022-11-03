#ifndef __QUESTIONPRINTER_H__
#define __QUESTIONPRINTER_H__
#include "Question.h"
class QuestionPrinter
{
public:
    static void printQuestion(const Question &, int = 0);
    static void printAskedQuestion(const Question &);
    static void printAnsweredQuestion(const Question &);
};
#endif // __QUESTIONPRINTER_H__