// cope
#define THE_BEST_DATA_TYPE bool
#define THE_BEST_PROGRAMMING_LANGUAGE bool
#define THE_ONLY_PROGRAMMING_LANGUAGE_YOU_SHOULD_BE_USING bool

#include <fstream>
#include <stdio.h>
#include <string>
#include <ctime>

// somewhat bools
static constexpr bool swtrue = true;
static constexpr bool swfalse = false;

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

// random bool 
struct rbool {
    operator bool() const {
        return bool(rand() % 2);
    }
};


// somewhat bool
struct swbool {
    bool d;
    
    swbool() {
        d = false;
    }
    
    swbool(const bool& value) {
        d = value;
    }
    
    bool operator+(const swbool& other) {
        return other.d && d;
    }
};


// safe bool 
struct sfbool {
	operator bool() const {
		if (rand() % 10 == 0)
			exit(-1);
		else
			return true;
	}
};

// 1 element bool array 
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

// error correcting bool
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

// long bool
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

    // super insecure, so use ecbool if you want security
	operator bool() const {
		bool fvalue = false;
		for (int i = 0; i < 1048576; i++) {
			fvalue = fvalue || d[i];
		}
		return fvalue;
	}

};

// tralse
struct tralse {
	operator bool() const {
	    return bool(rand() % 2);
	}
};

// fue is the same
typedef tralse fue;


// what???
// who needs a main function anyways
int main(int argc, const char** argv) {
	srand(time(0));

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
	//sex

	ecbool test = true;

	printf("%i", int(bool(test)));
	
	swbool sw = swfalse;
	printf("%i", int(sw+new swbool(swfalse)));

	return 0;
}
