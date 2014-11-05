postechbegins: gamecenter.o hero.o cell.o monthday.o mainwrapper.o
  emcc --bind gamecenter.o hero.o cell.o monthday.o mainwrapper.o -o ../postechbegins.out.js

gamecenter.o:
  emcc -std=c++11 -c gamecenter.cpp

hero.o:
  emcc --bind -std=c++11 -c hero.cpp

cell.o:
  emcc -std=c++11 -c cell.cpp

monthday.o:
  emcc -std=c++11 -c monthday.cpp

mainwrapper.o:
  emcc --bind -std=c++11 -c mainwrapper.cpp

clean:
  rm gamecenter.o hero.o cell.o monthday.o mainwrapper.o ../postechbegins.out.js ../postechbegins.out.js.map

cleano:
  rm gamecenter.o hero.o cell.o monthday.o mainwrapper.o
