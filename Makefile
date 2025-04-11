.PHONY: all build test clean

all: build

build:
	cmake -S . -B build
	cmake --build build

test: build
	cd build/tests && ctest --output-on-failure

clean:
	rm -rf build
