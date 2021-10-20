Project6: main.o Island.o NodeList.o Archipelago.o 
	g++ -o Project6 main.o Island.o NodeList.o Archipelago.o 

main.o: main.cpp Header.h Island.h Archipelago.h
	g++ -c main.cpp

Island.o: Island.cpp Header.h Island.h Archipelago.h
	g++ -c Island.cpp

NodeList.o: NodeList.cpp Header.h Island.h Archipelago.h
	g++ -c NodeList.cpp

Archipelago.o: Archipelago.cpp Header.h Island.h Archipelago.h
	g++ -c Archipelago.cpp

clean:
	rm main.o Island.o NodeList.o Archipelago.o Project6
