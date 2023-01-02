#!/usr/bin/sh

objects="benotung fachnote fachnoten_liste"
CFLAGS="-Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=c++11 -pedantic -O3"

for source in $objects; do
  compile_command="g++ $CFLAGS -c $source.cpp"
  echo "$compile_command"
  eval "$compile_command"
  if [ $? -ne 0 ]; then
    echo compile failed
    exit 1
  fi
done

archive_cmd="ar -r lib.a *.o"
echo "$archive_cmd"
eval "$archive_cmd"

if [ $? -ne 0 ]; then
  echo building static library failed
  exit 1
fi
