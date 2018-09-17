# USER_DIR = CoreSDC MapSDC SensorSDC 
GTEST_DIR = Tools/googletest
#Project name 
PROJECT = MySDCProject

CPP = g++ 
CPPFLAGS =  -std=c++14

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^


# All Directories containing source code to be built
PROJECT_SRC_DIRS = CoreSDC MapSDC SensorSDC 

# this generates all the files in the PROJECT_SRC_DIRS with their 
# appropriate subfolder prefix. 
SRCFILES = $(foreach dir, $(PROJECT_SRC_DIRS), $(wildcard $(dir)/*.cc))
# replace the .cc with .o 
OBJECTS  = $(patsubst %.cc, %.o, $(SRCFILES))
ALL_TEST_SRCFILES = $(foreach dir, $(PROJECT_SRC_DIRS), $(wildcard $(dir)/*_test.cc))

ALL_TESTS = $(patsubst %_test.cc,%_test ,$(ALL_TEST_SRCFILES))

# Build The Project 
all : $(OBJECTS) $(ALL_TESTS)

tests: $(ALL_TESTS)

# tell make to search the PROJECT_SRC_DIRS
VPATH = $(PROJECT_SRC_DIRS)
%.o : %.cc 
	$(CPP) $(CPPFLAGS) -c $< -o $@ 

# Build the TestCases
MapSDC/Map_test: MapSDC/Map.o Map_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@


# when making alltests, recompile the entire project again. 
# This can be time consuming, but it is just playing safe. 
# alltests : $(ALL_TESTS)
# when cleaning, first clean the object files in the project, the 
# clean the object files located in the tests. 

.PHONY : runtests 
runtests : 
	(cd MapSDC; ./Map_test; cd ..)

.PHONY : showme 
showme : 
	( echo $(ALL_TESTS); echo $(OBJECTS); echo $(ALL_TEST_SRCFILES))

.PHONY : clean 
clean : 
	( rm -f $(OBJECTS) $(ALL_TESTS) gtest.a gtest_main.a *.o)