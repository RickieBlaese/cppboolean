// cope
#define THE_BEST_DATA_TYPE bool
#define THE_BEST_PROGRAMMING_LANGUAGE bool
#define THE_ONLY_PROGRAMMING_LANGUAGE_YOU_SHOULD_BE_USING bool

#include <fstream>
#include <stdio.h>
#include <string>

// copied from https://stackoverflow.com/a/5840160
// edited for better functionality
// inline for no fucking reason at all
inline std::ifstream::pos_type fsz(const char* filename) { std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary); return in.tellg(); }

// copied from https://stackoverflow.com/a/2390938
bool is_empty(std::ifstream& pFile) {
	// edited this to be more readable
	return
		pFile
		.

		peek
		(
		)
		==
		std::
		ifstream::
		traits_type
		::
		eof
		(

		)
		;
}

struct barray {
	bool d[1];

	barray() {
		d[0] = false;
	}
	
	barray(const bool& value) {
		d[0] = value;
	}

	bool operator[](unsigned int index) {
		return d[index];
	}

	operator bool() const {
		return d[0];
	}
};

struct ecbool {
	bool* d;

	ecbool() {
		d = new bool[1073741824];
		for (int i = 0; i < 1073741824; i++) {
			d[i] = false;
		}
	}

	ecbool(const bool& value) {
		d = new bool[1073741824];
		for (int i = 0; i < 1073741824; i++) {
			d[i] = value;
		}
	}

	~ecbool() {
		delete[] d;
	}

	operator bool() const {
		int fvalue = 0;
		for (int i = 0; i < 1073741824; i++) {
			fvalue += d[i];
		}
		return bool(fvalue / 536870912);
	}
};

struct lbool {
	bool* d;

	lbool() {
		d = new bool[1048576];
		for (int i = 0; i < 1048576; i++) {
			d[i] = false;
		}
	}

	lbool(const bool& value) {
		for (int i = 0; i < 1048576; i++) {
			d[i] = value;
		}
	}

	~lbool() {
		delete[] d;
	}

	void operator=(const bool& other) {
		for (int i = 0; i < 1048576; i++) {
			d[i] = other;
		}
	}

	operator bool() const {
		bool fvalue = false;
		for (int i = 0; i < 1048576; i++) {
			fvalue = fvalue || d[i];
		}
		return fvalue;
	}

};

// what???
// who needs a main function anyways
int main(int argc, const char** argv) {

	// dumbass
	if (argc <= 1) {
		fprintf(stderr, "usage: %s [input file]\n", argv[0]);
		return -1;
	}

	std::ifstream ifile(argv[1]);

	// checking for the other dumbasses
	if (ifile.fail()) {
		fprintf(stderr, "error: failed to open input file\n");
		return -1;
	}
	if (is_empty(ifile)) {
		fprintf(stderr, "error: input file is empty\n");
		return -1;
	}


	// read contents here or summ

	ecbool test = true;

	printf("%i", int(bool(test)));

	return 0;
}
