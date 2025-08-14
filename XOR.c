#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	    if (argc < 4) {
		            printf("Usage: %s <infile> <outfile> <hex-key>\n", argv[0]);

			            printf("Example: %s decrypted_input.exe encrypted_output.exe 0xAA\n", argv[0]); //Suits comms.c
				            printf("Example: %s encrypted_output.exe decrypted_input.exe 0xAA\n", argv[0]); //Suits comms.c

					            return 1;
						        }

	        FILE* in = fopen(argv[1], "rb");
		    FILE* out = fopen(argv[2], "wb");
		        if (!in || !out) { perror("File error"); return 1; }

			    unsigned char key = (unsigned char)strtol(argv[3], NULL, 16);
			        int ch;
				    while ((ch = fgetc(in)) != EOF) {
					            fputc(ch ^ key, out);
						        }
				        fclose(in);
					    fclose(out);

					        printf("XOR obfuscation done (key: 0x%02X)\n", key);
						    return 0;
}

