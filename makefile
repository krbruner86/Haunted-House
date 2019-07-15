CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

#LDFLAGS = -lboost_date_time

OBJS = main.o Menu.o getInt.o Bath.o BedRoom2.o BedRoom3.o Dining.o DownHall.o Kitchen.o Living.o MasterBR.o Player.o Space.o Study.o UpHallway.o

SRCS =  main.cpp Menu.cpp getInt.cpp Bath.cpp BedRoom2.cpp BedRoom3.cpp Dining.cpp DownHall.cpp Kitchen.cpp Living.cpp MasterBR.cpp Player.cpp Space.cpp Study.cpp UpHallway.cpp

HEADERS = Menu.hpp getInt.hpp Bath.hpp BedRoom2.hpp BedRoom3.hpp Dining.hpp DownHall.hpp Kitchen.hpp Living.hpp MasterBR.hpp Player.hpp Space.hpp Study.hpp UpHallway.hpp

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o main

clean:
	rm main

zip:
	zip $(PROJ).zip *.cpp *.hpp *.pdf *.txt makefile