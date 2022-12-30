all:compile link run
compile:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o
	g++ -c -I "./include" ./src/Kuyruk.cpp -o ./lib/Kuyruk.o
	g++ -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o
	g++ -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -c -I "./include" ./src/ikiliAramaAgaci.cpp -o ./lib/ikiliAramaAgaci.o
	g++ -c -I "./include" ./src/Sistem.cpp -o ./lib/Sistem.o 
	g++ -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o 	
	g++ -c -I "./include" ./src/Kontrol.cpp -o ./lib/Kontrol.o 
	g++ -c -I "./include" ./src/Test.cpp -o ./lib/Test.o 

link:
	g++ -o ./bin/program ./lib/*
run:
	./bin/program

	