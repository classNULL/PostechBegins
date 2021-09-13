objectfiles = gamecenter.o hero.o cell.o monthday.o maptable.o score.o title.o celloption.o event.o mainwrapper.o
jsfiles = ../postechbegins.out.js ../postechbegins.out.wasm ../postechbegins.out.wasm.map

CXX = emcc
CXXFLAGS = -std=c++11 -Werror -Wno-error=potentially-evaluated-expression

postechbegins: $(objectfiles)
	$(CXX) --bind $(objectfiles) --source-map-base ./ -o ../postechbegins.out.js

gamecenter.o:
	$(CXX) $(CXXFLAGS) -c gamecenter.cpp

hero.o:
	$(CXX) $(CXXFLAGS) -c hero.cpp

cell.o:
	$(CXX) $(CXXFLAGS) -c cell.cpp

monthday.o:
	$(CXX) $(CXXFLAGS) -c monthday.cpp

maptable.o:
	$(CXX) $(CXXFLAGS) -c maptable.cpp

score.o:
	$(CXX) $(CXXFLAGS) -c score.cpp

title.o:
	$(CXX) $(CXXFLAGS) -c title.cpp

celloption.o:
	$(CXX) $(CXXFLAGS) -c celloption.cpp

event.o:
	$(CXX) $(CXXFLAGS) -c event.cpp

mainwrapper.o:
	$(CXX) $(CXXFLAGS) --bind -c mainwrapper.cpp

clean:
	rm $(objectfiles) $(jsfiles)

cleano:
	rm $(objectfiles)

cleanwrapper:
	rm mainwrapper.o
