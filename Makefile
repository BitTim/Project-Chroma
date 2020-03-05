linux_ccfiles = $(shell find . -name \*.cc ! -path ./src/Linux/main.cc)

bin/Linux/chroma: src/Linux/main.cc $(linux_ccfiles)
	g++ -o $@ -lSDL2 -lSDL2_ttf -lSDL2_image src/Linux/main.cc $(linux_ccfiles)

runl: bin/Linux/chroma
	./bin/Linux/chroma

bin/Linux/chroma_debug: src/Linux/main.cc $(linux_ccfiles)
	g++ -g -o $@ -lSDL2 -lSDL2_ttf -lSDL2_image src/Linux/main.cc $(linux_ccfiles)

rundl: bin/Linux/chroma_debug
	./bin/Linux/chroma_debug

debugl: bin/Linux/chroma_debug
	gdb bin/Linux/chroma_debug

clean:
	rm -R bin/*
	rm -R log/

	mkdir bin/Linux
	mkdir bin/Windows
	mkdir log

	clear