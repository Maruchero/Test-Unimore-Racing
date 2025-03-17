

#ifndef TESTUTILS_H
#define TESTUTILS_H

#include<iostream>
#include<sstream>

#include <opencv2/core.hpp>

#define FatalError(s) {                                                \
    std::stringstream _where, _message;                                \
    _where << __FILE__ << ':' << __LINE__;                             \
    _message << std::string(s) + "\n" << __FILE__ << ':' << __LINE__;\
    std::cerr << _message.str() << "\nAborting...\n";                  \
    exit(EXIT_FAILURE);                                                \
}

void printOpenCVVersion();


#endif /*TESTUTILS_H*/