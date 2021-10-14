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
inline std::ifstream::pos_type fsz(const char*filename){std::ifstream in(filename,std::ifstream::ate|std::ifstream::binary);return in.tellg();}

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

	char* contents = (char*)"";
	ifile.read(contents, fsz(argv[1]));
	ifile.close();
	

	// done
	THE_BEST_DATA_TYPE done = true;
	return 0;
}
