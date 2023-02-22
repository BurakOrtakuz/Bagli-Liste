derlebaglacalistir: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -c -I "./include" ./src/YoneticiDugum.cpp -o ./lib/YoneticiDugum.o
	g++ -c -I "./include" ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o

bagla:
	g++  ./lib/Dugum.o ./lib/SatirListesi.o ./lib/YoneticiDugum.o ./lib/YoneticiListesi.o ./lib/main.o -o ./bin/program.exe
calistir:
	./bin/program.exe