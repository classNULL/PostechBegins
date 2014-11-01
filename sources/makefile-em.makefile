postechbegins: manager.o
  emcc manager.o -o postechbegins.out.js

manager.o:
  emcc -std=c++11 -c manager.cpp

html: manager.o
  emcc manager.o -o postechbegins.out.html

clean:
  rm manager.o postechbegins.out.js postechbegins.out.js.map postechbegins.out.html postechbegins.out.html.map
