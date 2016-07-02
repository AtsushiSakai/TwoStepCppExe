#!/bin/sh
# get file path
cwd=`dirname "${0}"`
expr "${0}" : "/.*" > /dev/null || cwd=`(cd "${cwd}" && pwd)`

g++ ${cwd}/main.cpp -I${GTEST_DIR}/googletest/include  -L${GTEST_DIR}/googlemock/gtest -lpthread -lgtest_main -lgtest && ${cwd}/a.out

