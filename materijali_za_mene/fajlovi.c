//kada traži izlazni kod za grešku unapred zadatu (main 3,4)(funkcija 6-13)

FILE *in  = safe_fopen(in_filename,  "r", 1);
FILE *out = safe_fopen(out_filename, "w", 2);
    
FILE *safe_fopen(char *filename, char *mode, int error_code) {
    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        printf("Can't open '%s'!\n", filename);
        exit(error_code);
    }
    return fp;
}

//obavezno ovo na samom kraju u main-u
    fclose(in);
    fclose(out);

