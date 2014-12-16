objectfiles = gamecenter.o hero.o cell.o monthday.o maptable.o score.o title.o celloption.o event.o mainwrapper.o
jsfiles = ../postechbegins.out.js ../postechbegins.out.js.map

postechbegins: $(objectfiles)
  emcc --bind $(objectfiles) -o ../postechbegins.out.js

gamecenter.o:
  emcc -std=c++11 -c gamecenter.cpp

hero.o:
  emcc -std=c++11 -c hero.cpp

cell.o:
  emcc -std=c++11 -c cell.cpp

monthday.o:
  emcc -std=c++11 -c monthday.cpp

maptable.o:
	emcc -std=c++11 -c maptable.cpp

score.o:
	emcc -std=c++11 -c score.cpp

title.o:
	emcc -std=c++11 -c title.cpp

celloption.o:
	emcc -std=c++11 -c celloption.cpp

event.o:
	emcc -std=c++11 -c event.cpp

mainwrapper.o:
  emcc --bind -std=c++11 -c mainwrapper.cpp

clean:
  rm $(objectfiles) $(jsfiles)

cleano:
  rm $(objectfiles)

cleanwrapper:
	rm mainwrapper.o
