subway_sim:
	mkdir -p bin
	g++ -o bin/subway_simulator main.cpp scripts/*.cpp
run:
	./bin/subway_simulator
address_sanitizer:
	g++ -o bin/subway_simulator main.cpp scripts/*.cpp -fsanitize=address
valgrind:
	g++ -o bin/subway_simulator main.cpp scripts/*.cpp -g
	valgrind --leak-check=full ./bin/subway_simulator