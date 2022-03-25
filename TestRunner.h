#ifndef IMPL_REPORT_TESTRUNNER
#define IMPL_REPORT_TESTRUNNER

#include <set>
#include <string>
#include <vector>
#include <set>
#include "TestResult.h"
#include "CommandRunner.h"
#include <sstream>

/**
 * \brief   The interface that handles running the Test Executables
 *
 * \details The TestRunner class simplified the interface for running one or
 *          more testsuites and returning the results.
 */
class TestRunner
{
    private:
        std::string path;
        std::vector<std::vector<std::string>> executables;
        std::string manifest;

        size_t executable_iterator;
        CommandRunner cr;
        std::string command_output;
        std::stringstream ss;
        bool has_next_output;
        //helper methods
        bool next_executable();
        std::string find_next_result();

    public:
        // constructor
        TestRunner( std::string, std::vector<std::vector<std::string>> );
        // control methods
        void start();
        TestResult next_result();
        bool has_next() const;
};
#endif // IMPL_REPORT_TESTRUNNER
