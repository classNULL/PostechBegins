postechbegins: gamecenter.o hero.o cell.o mainwrapper.o
  emcc --bind gamecenter.o hero.o cell.o mainwrapper.o -o ../postechbegins.out.js

gamecenter.o:
  emcc -std=c++11 -c gamecenter.cpp

hero.o:
  emcc --bind -std=c++11 -c hero.cpp

cell.o:
  emcc -std=c++11 -c cell.cpp

mainwrapper.o:
  emcc --bind -std=c++11 -c mainwrapper.cpp

html: gamecenter.o hero.o cell.o mainwrapper.o
  emcc --bind gamecenter.o hero.o mainwrapper.o cell.o -o ../postechbegins.out.html

clean:
  rm gamecenter.o hero.o cell.o mainwrapper.o
  rm ../postechbegins.out.js ../postechbegins.out.js.map
  rm ../postechbegins.out.html ../postechbegins.out.html.map

cleano:
  rm gamecenter.o hero.o cell.o mainwrapper.o
