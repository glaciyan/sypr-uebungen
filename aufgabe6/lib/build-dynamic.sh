#!/usr/bin/sh

objects="benotung fachnote fachnoten_liste"
CFLAGS="-Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=c++11 -pedantic -O3 -fPIC"

for source in $objects; do
  compile_command="g++ $CFLAGS -c $source.cpp"
  echo "$compile_command"
  eval "$compile_command"
  if [ $? -ne 0 ]; then
    echo compile failed
    exit 1
  fi
done

dynamic_lib_command="g++ $CFLAGS -shared *.o -o libaufgabe6.so"
echo "$dynamic_lib_command"
eval "$dynamic_lib_command"
if [ $? -ne 0 ]; then
  echo building dynamic link failed
  exit 1
fi

rm ./*.o
echo cleaned .o files
