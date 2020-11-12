CXX        = clang++
CXXFLAGS   = -std=c++11 \
             -Weverything -Wall -Wextra -Werror -Wpointer-arith -Wcast-qual \
             -Wno-missing-braces -Wempty-body -Wno-error=uninitialized \
             -Wno-error=deprecated-declarations \
             -pedantic-errors -pedantic \
             -Os

Bunny : Bunny.o Brain.o Offence.o Defence.o Dislay.o
	$(CXX) -o $(CXXFLAGS) Bunny Bunny.o Brain.o Offence.o Defence.o Dislay.o

Bunny.o: Bunny.cpp  BunnBrain/Brain.o
	$(CXX) -c -g $(CXXFLAGS) Bunny.cpp

Brain.o: BunnBrain/Brain.cpp BunnBrain/Brain.h BunnBrain/Offence.h BunnBrain/Defence.h BunnBrain/Screen/Display.h
	$(CXX) -c -g $(CXXFLAGS) BunnBrain/Brain.cpp 

BunnBrain/Offence.o: BunnBrain/Offence.cpp BunnBrain/Offence.h
	$(CXX) -c -g $(CXXFLAGS) BunnBrain/Offence.cpp 

BunnBrain/Defence.o: BunnBrain/Defence.cpp BunnBrain/Defence.h
	$(CXX) -c -g $(CXXFLAGS) BunnBrain/Defence.cpp 

BunnBrain/Display.o: BunnBrain/Screen/Display.cpp BunnBrain/Screen/Display.h
	$(CXX) -c -g $(CXXFLAGS) BunnBrain/Screen/Display.cpp

RM         = rm -f

.PHONY: clean
clean: 
	$(RM) Bunny *.o *~
