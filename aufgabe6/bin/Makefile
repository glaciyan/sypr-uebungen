#
# Makefile
#
# Autor: Kevin Trautvetter
# Erstellt am: 02.01.2023
#

LIBNAME = aufgabe6

#--------------- Kommando-Variablen
CXX = g++
CPPFLAGS = -I. -I../lib
CXXFLAGS = -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=c++11 -pedantic -O3
LDFLAGS = -L../lib
LDLIBS = -l:libaufgabe6.a
RM = rm -f

#--------------- Hilfsvariablen
TARGET = notenspiegel
OBJECTS = $(TARGET).o
SOURCES = $(OBJECTS:.o=.cpp)

#--------------- Musterregeln
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS) $(LDLIBS)

#--------------- Standardziele
.PHONY: all clean depends

all: depends $(TARGET)

clean:
	$(RM) $(OBJECTS) $(TARGET)

depends: $(SOURCES)
	$(CXX) $(SOURCES) $(CPPFLAGS) -MM > $@

#--------------- Ziele zur Erstellung
$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@ $(CPPFLAGS) $(CXXFLAGS)

include depends