build:
	g++ main.cpp -o out.run `pkg-config --cflags --libs keybinder-3.0 x11`
clean:
	rm *.run