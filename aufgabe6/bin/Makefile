#
# Makefile
#
# Autor: Kevin Trautvetter
# Erstellt am: 02.01.2023
#

#--------------- Kommando-Variablen
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=c++11 -pedantic -O3
CPPFLAGS = -I. -I../lib
LDFLAGS = -L../lib
LDLIBS = -l:libaufgabe6.a
RM = rm -f

#--------------- Hilfsvariablen
TARGET = notenspiegel
OBJECTS = $(TARGET).o
SOURCES = $(OBJECTS:.o=.cpp)

#--------------- Musterregeln
%.o: %.cpp
	$(CXX) -c $< -o $@ $(CPPFLAGS) $(CXXFLAGS)

#--------------- Standardziele
.PHONY: all clean depends

all: $(TARGET)

clean:
	$(RM) $(OBJECTS) $(TARGET) depends

depends: $(SOURCES)
	$(CXX) $(SOURCES) $(CPPFLAGS) -MM > $@

#--------------- Ziele zur Erstellung
$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@ $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

include depends