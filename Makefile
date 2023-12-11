subway_sim:
	g++ -o bin/subway_simulator main.cpp scripts/*.cpp
run:
	./bin/subway_simulator
address_sanitizer:
	g++ -o bin/subway_simulator main.cpp scripts/*.cpp -fsanitize=address