#
# Makefile
#
# Autor: Kevin Trautvetter
# Erstellt am: 02.01.2023
#

LIBNAME = aufgabe6

#--------------- Kommando-Variablen
CXX = g++
CPPFLAGS = -I.
CXXFLAGS = -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=c++11 -pedantic -O3 -fpic
RM = rm -f
AR = ar -r

#--------------- Hilfsvariablen
LIBTYPE = a
OBJECTS = benotung.o fachnote.o fachnoten_liste.o
SOURCES = $(OBJECTS:.o=.cpp)
HEADERS = $(OBJECTS:.o=.h)

#--------------- Musterregeln
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

#--------------- Standardziele
.PHONY: all clean depends

all: depends lib$(LIBNAME).$(LIBTYPE)

clean:
	$(RM) lib$(LIBNAME).a lib$(LIBNAME).so $(OBJECTS) depends

depends: $(SOURCES) $(HEADERS)
	$(CXX) $(SOURCES) $(CPPFLAGS) -MM > $@

#--------------- Ziele zur Erstellung
lib$(LIBNAME).a: $(OBJECTS)
	$(AR) $@ $^

lib$(LIBNAME).so: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -shared $^ -o $@

include depends