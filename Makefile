CXX=g++
CPPFLAGS=-Wall -Werror -O2 -fopenmp

TARGETS=my_parallel

all: ${TARGETS}


test: my_parallel
	-chmod a+rx ./test.*
	-./test.17
	-./test.39
	-./test.55
	-./test.101
	-./test.1001
	-./test.s.10000
	-./test.s.9837
	-./test.s.10211
	-./test.s.10017
	-./test.s.9978
	-./test.s.20000
	-./test.s.39119
	-./test.s.40000
	-./test.s.100000
	-./test.s.1M
	
efftest: my_parallel
	-chmod +rx timetest
	-./timetest test.s.20000
	-./timetest test.s.39119
	-./timetest test.s.40000
	-./timetest test.s.100000
	-./timetest test.s.1M
	-./timetest test.s.10M
	-./timetest test.s.100M


clean:
	rm -f *.o test.*.myoutput test.*.correct
