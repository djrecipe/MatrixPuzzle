// ---------------------------------------------------------------------------------------------
// THIS IS A TESTING PROJECT. YOU CAN FREELY MODIFY THE CODE BELOW IN ORDER TO TEST YOUR WORK.
// ---------------------------------------------------------------------------------------------

#pragma once

#include "Common.h"
#include "Matrix.h"
#include "Path.h"
#include "Sequence.h"

class Application
{
public:
    int run();

private:
    void runExample1();
    void runExample2();
    void runExample3();
    void runExample4();
    void runExample5();
    void runExample6();
    void runExample7();
    void runExample8();
    void runExample9();

    void runExample(const std::string &name,
                    const Matrix &matrix,
                    const std::vector<Sequence> &sequences,
                    int maxPathLength,
                    const Path &expectedSolution);
    void runExampleWithoutSolution(const std::string &name,
                                   const Matrix &matrix,
                                   const std::vector<Sequence> &sequences,
                                   int maxPathLength);
};
