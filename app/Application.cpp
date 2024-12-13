// ---------------------------------------------------------------------------------------------
// THIS IS A TESTING PROJECT. YOU CAN FREELY MODIFY THE CODE BELOW IN ORDER TO TEST YOUR WORK.
// ---------------------------------------------------------------------------------------------

#include "Application.h"

#include "InvalidArgumentError.h"
#include "PathFinder.h"
#include "PathNotFoundError.h"

int Application::run()
{
    runExample1();
    runExample2();
    runExample3();
    runExample4();
    runExample5();
    runExample6();
    runExample7();
    runExample8();

    // NOTE: Uncomment this example only if you have developed fast algorithm that can handle large matrices and paths.
    // runExample9();

    return 0;
}

// clang-format off

void Application::runExample1()
{
    const Matrix matrix =
    {{
        {0x3A, 0x3A, 0x10, 0x9B, 0x72},
        {0x9B, 0x72, 0x3A, 0x10, 0x72},
        {0x10, 0x3A, 0x3A, 0x3A, 0x10},
        {0x3A, 0x10, 0x3A, 0x9B, 0x72},
        {0x10, 0x10, 0x3A, 0x72, 0x72}
    }};

    const std::vector<Sequence> sequences =
    {
        Sequence({0x3A, 0x10, 0x9B}, 10)
    };

    const int maxPathLength = 3;

    const Path expectedSolution = {{{0, 1}, {3, 1}, {3, 3}}};

    runExample("example of a simple puzzle with one sequence", matrix, sequences, maxPathLength, expectedSolution);
}

void Application::runExample2()
{
    const Matrix matrix =
    {{
        {0x3A, 0x3A, 0x10, 0x9B, 0x72},
        {0x9B, 0x72, 0x3A, 0x10, 0x72},
        {0x10, 0x3A, 0x3A, 0x3A, 0x10},
        {0x3A, 0x10, 0x3A, 0x9B, 0x72},
        {0x10, 0x10, 0x3A, 0x72, 0x72}
    }};

    const std::vector<Sequence> sequences =
    {
        Sequence({0x9B, 0x3A}, 20),
        Sequence({0x10, 0x10, 0x3A}, 30)
    };

    const int maxPathLength = 5;

    const Path expectedSolution = {{{0, 3}, {2, 3}, {2, 0}, {4, 0}, {4, 2}}};

    runExample("example of a puzzle with two sequences", matrix, sequences, maxPathLength, expectedSolution);
}

void Application::runExample3()
{
    const Matrix matrix =
    {{
        {0x9B, 0x9B, 0x72, 0x9B, 0xD4},
        {0x10, 0xD4, 0xD4, 0x9B, 0x10},
        {0x72, 0x9B, 0x3A, 0x10, 0x9B},
        {0x3A, 0xD4, 0x9B, 0x3A, 0x9B},
        {0x72, 0x10, 0x10, 0xD4, 0x10}
    }};

    const std::vector<Sequence> sequences =
    {
        Sequence({0x10, 0xD4, 0x72, 0x72}, 20),
        Sequence({0x3A, 0x10, 0xD4}, 10)
    };

    const int maxPathLength = 7;

    const Path expectedSolution = {{{0, 2}, {2, 2}, {2, 3}, {4, 3}, {4, 0}, {2, 0}}};

    runExample("example of a puzzle with one wasted move", matrix, sequences, maxPathLength, expectedSolution);
}

void Application::runExample4()
{
    const Matrix matrix =
    {{
        {0x10, 0x10, 0x10, 0x10, 0x10},
        {0x10, 0x10, 0x10, 0x10, 0x10},
        {0x3A, 0xD4, 0x10, 0x9B, 0x72},
        {0x10, 0x10, 0x10, 0x10, 0x10},
        {0x10, 0x10, 0x10, 0x10, 0x10}
    }};

    const std::vector<Sequence> sequences =
    {
        Sequence({0x3A, 0x9B}, 10),
        Sequence({0x72, 0xD4}, 10)
    };

    const int maxPathLength = 7;

    // NOTE: There are multiple possible solutions. Uncomment the suitable one below.
    const Path expectedSolution = {{{0, 0}, {2, 0}, {2, 3}, {0, 3}, {0, 4}, {2, 4}, {2, 1}}};
    // const Path expectedSolution = {{{0, 0}, {2, 0}, {2, 3}, {1, 3}, {1, 4}, {2, 4}, {2, 1}}};
    // const Path expectedSolution = {{{0, 0}, {2, 0}, {2, 3}, {3, 3}, {3, 4}, {2, 4}, {2, 1}}};
    // const Path expectedSolution = {{{0, 0}, {2, 0}, {2, 3}, {4, 3}, {4, 4}, {2, 4}, {2, 1}}};
    // const Path expectedSolution = {{{0, 4}, {2, 4}, {2, 1}, {0, 1}, {0, 0}, {2, 0}, {2, 3}}};
    // const Path expectedSolution = {{{0, 4}, {2, 4}, {2, 1}, {1, 1}, {1, 0}, {2, 0}, {2, 3}}};
    // const Path expectedSolution = {{{0, 4}, {2, 4}, {2, 1}, {3, 1}, {3, 0}, {2, 0}, {2, 3}}};
    // const Path expectedSolution = {{{0, 4}, {2, 4}, {2, 1}, {4, 1}, {4, 0}, {2, 0}, {2, 3}}};

    runExample("example of a puzzle with three wasted moves", matrix, sequences, maxPathLength, expectedSolution);
}

void Application::runExample5()
{
    const Matrix matrix =
    {{
        {0x9B, 0x10, 0x72, 0x10, 0x10},
        {0x10, 0x3A, 0x3A, 0x3A, 0x10},
        {0x72, 0xD4, 0x10, 0x10, 0x9B},
        {0x3A, 0x72, 0xD4, 0x3A, 0x9B},
        {0x72, 0x10, 0x10, 0x10, 0x10}
    }};

    const std::vector<Sequence> sequences =
    {
        Sequence({0x9B, 0x3A, 0x72, 0xD4}, 20),
        Sequence({0x72, 0xD4, 0x3A}, 10)
    };

    const int maxPathLength = 5;

    const Path expectedSolution = {{{0, 0}, {3, 0}, {3, 1}, {2, 1}}};

    runExample("example of a puzzle with competing sequences", matrix, sequences, maxPathLength, expectedSolution);
}

void Application::runExample6()
{
    const Matrix matrix =
    {{
        {0x9B, 0x3A, 0x3A, 0x9B},
        {0x10, 0x3A, 0x3A, 0x10},
        {0x3A, 0x3A, 0x72, 0x9B}
    }};

    const std::vector<Sequence> sequences =
    {
        Sequence({0x3A, 0xD4}, 10),
        Sequence({0x72, 0x10}, 10)
    };

    const int maxPathLength = 6;

    runExampleWithoutSolution("example of a puzzle without any solution", matrix, sequences, maxPathLength);
}

void Application::runExample7()
{
    const Matrix matrix =
    {{
        {0x9B, 0x10, 0x72, 0x10, 0x10},
        {0x10, 0x3A, 0x3A, 0x3A, 0x10},
        {0x72, 0xD4, 0x10, 0x10, 0x9B},
        {0x3A, 0x72, 0xD4, 0x9B, 0x9B},
        {0x72, 0x10, 0x10, 0x10, 0x10}
    }};

    const std::vector<Sequence> sequences =
    {
        Sequence({0x9B, 0x3A, 0x72, 0xD4}, 10),
        Sequence({0x72, 0xD4, 0x3A}, 10)
    };

    const int maxPathLength = 5;

    const Path expectedSolution = {{{0, 2}, {3, 2}, {3, 0}}};

    runExample("example of a puzzle with the shortest competing sequence", matrix, sequences, maxPathLength, expectedSolution);
}

void Application::runExample8()
{
    const Matrix matrix =
    {{
        {0x3A, 0x3A, 0x10, 0x9B, 0x72},
        {0x9B, 0x72, 0x3A, 0x10, 0x72},
        {0x10, 0xD4, 0x3A, 0x3A, 0x10},
        {0x3A, 0x10, 0x3A, 0x9B, 0x72},
        {0x10, 0x10, 0x3A, 0x72, 0x72}
    }};

    const std::vector<Sequence> sequences =
    {
        Sequence({0x9B, 0x3A, 0xFF}, 30),
        Sequence({0x3A, 0xD4, 0x9B}, 30),
        Sequence({0x3A, 0x3A, 0x72}, 30)
    };

    const int maxPathLength = 6;

    const Path expectedSolution = {{{0, 0}, {3, 0}, {3, 4}}};

    runExample("example of a puzzle with one possible sequence out of three", matrix, sequences, maxPathLength, expectedSolution);
}

void Application::runExample9()
{
    const Matrix matrix =
    {{
        {0x00, 0x10, 0xD4, 0x9B, 0x10, 0x9B, 0xD4, 0x72, 0xF0, 0x10},
        {0x9B, 0x3A, 0x9B, 0x9B, 0x72, 0xD4, 0x10, 0xD4, 0x72, 0x72},
        {0xF9, 0x3A, 0xD4, 0xD4, 0x9B, 0x3A, 0xFA, 0x10, 0x9B, 0x10},
        {0xD4, 0x3A, 0x9B, 0x3A, 0x3A, 0x72, 0x72, 0xD4, 0xF1, 0xF2},
        {0xF8, 0x10, 0x72, 0x3A, 0xF7, 0x72, 0xD4, 0x10, 0xD4, 0x3A},
        {0x10, 0xD4, 0x9B, 0x10, 0xF6, 0xF5, 0x3A, 0x10, 0x10, 0x72},
        {0x72, 0x10, 0xD4, 0x3A, 0x72, 0x10, 0x72, 0xD4, 0x3A, 0x9B},
        {0xD4, 0x3A, 0x72, 0xD4, 0x9B, 0x9B, 0xFB, 0x3A, 0x9B, 0x72},
        {0x10, 0x10, 0x9B, 0x3A, 0x3A, 0x72, 0x10, 0x9B, 0x72, 0x9B},
        {0x9B, 0x72, 0x10, 0x10, 0xD4, 0xF4, 0x72, 0x10, 0xD4, 0xF3}
    }};

    const std::vector<Sequence> sequences =
    {
        Sequence({0xFB}, 10),
        Sequence({0xF8, 0xF9}, 20),
        Sequence({0xF2, 0xF3}, 20),
        Sequence({0xF0, 0xF1, 0xF2}, 30),
        Sequence({0xF7, 0xF8, 0xF9, 0xFA}, 40),
        Sequence({0xF4, 0xF5, 0xF6, 0xF7, 0xF8}, 50)
    };

    const int maxPathLength = 12;

    const Path expectedSolution = {{{0, 8}, {3, 8}, {3, 9}, {9, 9}, {9, 5}, {5, 5}, {5, 4}, {4, 4}, {4, 0}, {2, 0}, {2, 6}, {7, 6}}};

    runExample("example of a complex puzzle with six sequences", matrix, sequences, maxPathLength, expectedSolution);
}

// clang-format on

void Application::runExample(const std::string &name,
                             const Matrix &matrix,
                             const std::vector<Sequence> &sequences,
                             int maxPathLength,
                             const Path &expectedSolution)
{
    std::cout << "Running " << name << std::endl;

    Path actualSolution;

    try
    {
        PathFinder pathFinder(matrix, sequences, maxPathLength);
        actualSolution = pathFinder.run();
    }
    catch (const InvalidArgumentError &error)
    {
        std::cerr << "InvalidArgumentError: " << error.what() << std::endl;
        throw;
    }
    catch (const PathNotFoundError &error)
    {
        std::cerr << "PathNotFoundError: " << error.what() << std::endl;
        throw;
    }

    std::cout << "Actual solution:   " << actualSolution << std::endl;
    std::cout << "Expected solution: " << expectedSolution << std::endl;
    std::cout << std::endl;

    assert(actualSolution == expectedSolution);
}

void Application::runExampleWithoutSolution(const std::string &name,
                                            const Matrix &matrix,
                                            const std::vector<Sequence> &sequences,
                                            int maxPathLength)
{
    std::cout << "Running " << name << std::endl;

    try
    {
        PathFinder pathFinder(matrix, sequences, maxPathLength);
        pathFinder.run();
    }
    catch (const InvalidArgumentError &)
    {
        std::cout << "Actual exception:   InvalidArgumentError" << std::endl;
        std::cout << "Expected exception: PathNotFoundError" << std::endl;
        throw;
    }
    catch (const PathNotFoundError &)
    {
        std::cout << "Actual exception:   PathNotFoundError" << std::endl;
        std::cout << "Expected exception: PathNotFoundError" << std::endl;
        std::cout << std::endl;
        return;
    }

    std::cout << "Actual exception:   It throws nothing" << std::endl;
    std::cout << "Expected exception: PathNotFoundError" << std::endl;

    assert(false);
}
