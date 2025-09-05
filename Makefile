# John Sipahioglu
# Kent State University - Computer Science 2 - Lab 2
# Makefile

# All of your tests should be buildable from this makefile
# You should create unit tests for:
#	- Default Constructor - already done for you
#	- Hour Constructor
# 	- Hour & Minute Constructor
#	- Hour, Minute, & Second Constructor
# 	- increment
#	- decrement
# 	- add
#	- diff

CPP = g++ # change to clang++ if you are on Mac
OPTS = -g -Werror -W -Wunused -Wuninitialized -Wshadow -std=c++17

# add your tests to the list
TESTS = test_tp_equals test_default_ctor

msg:
	@echo 'Targets are: '
	@echo '	- tests'
	@echo '	- test_tp_equals'
	@echo '	- test_default_ctor'

tests: $(TESTS)
	./test_tp_equals
	./test_default_ctor
# 	add ./your_test here for each of your tests

# using % as a wildcard will have it build anything that starts with test_
test_%: time.o test_%.o
#	this is a bash prompt so it uses * as a wildcard instead of %
	$(CPP) $(OPTS) -o test_$* time.o test_$*.o

test_%.o: time.hpp test_%.cpp
	$(CPP) $(OPTS) -c test_$*.cpp

# if you want to build a specific test you need to create a rule for it like this
test_tp_equals: time.o test_tp_equals.o
	$(CPP) $(OPTS) -o test_tp_equals time.o test_tp_equals.o
	./test_tp_equals

test_tp_equals.o: test_tp_equals.cpp time.hpp
	$(CPP) $(OPTS) -c test_tp_equals.cpp

test_default_ctor: time.o test_default_ctor.o
	$(CPP) $(OPTS) -o test_default_ctor test_default_ctor.o time.o
	./test_default_ctor

test_default_ctor.o: time.hpp test_default_ctor.cpp
	$(CPP) $(OPTS) -c test_default_ctor.cpp

time.o: time.cpp time.hpp
	g++ -g -c time.cpp

# call this to delete .o files and executables
clean:
	rm -f test_*.o time.o $(TESTS)