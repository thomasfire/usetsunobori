// csvconverter.cpp : Defines the entry point for the application.
//

#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: csvconverter.exe input.csv output\n");
		return 1;
	}

	typedef struct {
		uint16_t d0;
		uint16_t d1;
		uint16_t d2;
		uint16_t d3;
		uint16_t d4;
	} COMBUFFT;

	COMBUFFT buffer = {};

	FILE *f_in = fopen(argv[1], "r");
	FILE *f_out = fopen(argv[2], "wb");
	if (!f_in || !f_out) {
		fprintf(stderr, "Couldn't open files\n");
		return 1;
	}

	char line[1024];
	while (fgets(line, sizeof line, f_in)) {
		if (sscanf(line, "%hu%*c%hu%*c%hu%*c%hu%*c%hu", &buffer.d0, &buffer.d1, &buffer.d2, &buffer.d3, &buffer.d4) == 5) {
			printf("Got values: %hu,%hu,%hu,%hu,%hu \n", buffer.d0, buffer.d1, buffer.d2, buffer.d3, buffer.d4);
			fwrite(&buffer, sizeof(buffer), 1, f_out);
		}
	}
	

	printf("OK, closing files...");

	fclose(f_in);
	fclose(f_out);
	return 0;
}
