#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EXIT_STATUS 1
#define BUFFER_SIZE 2048
#define MAX_STUDENT_NUMBER 100




struct Studenten{
    char Nachname[20]  ;
    char Vorname[20]  ;
    char MatrikuelNummer[8];
    char Semester[20] ;
    char Gruppe[20];
    float Note;

};



void readCSV( char* filename,struct Studenten *student){

    student[MAX_STUDENT_NUMBER];

    //printf("readCSV \n");
    FILE *file = fopen(filename, "r");

    if(file == NULL){
        printf("File could not be opened\n");
        exit(EXIT_STATUS);
    }

    char buf[BUFFER_SIZE];
    int i=0;
    int counter = 0;


    while(fgets(buf, sizeof(buf), file)){

        if(i==0){
           i++;
           continue;
        }

        char* token = strtok(buf,";");
        while(token != NULL){
            switch (counter) {
            case 0:
                strcpy(student[i].Nachname, token);
                counter++;
                break;
            case 1:
                strcpy(student[i].Vorname, token);
                counter++;

                break;
            case 2:
                strcpy(student[i].MatrikuelNummer, token);
                counter++;

                break;
            case 3:
                strcpy(student[i].Semester, token);
                counter++;

                break;
            case 4:
                strcpy(student[i].Gruppe, token);
                counter++;

                break;
            case 5:
                student[i].Note =  atof(token);
                counter=0;
                break;
            default:
                break;
            }
            token = strtok(NULL, ";");
        }

        i++;


    }

    strcpy(student[i].Nachname, "");


}

void readJSON( char* filename,struct Studenten *student){
    printf("readJSON \n");
}

void readXML( char* filename,struct Studenten *student){
    printf("readXML \n");

}

void NoSupportedExtentionRead( char* filename,struct Studenten *student){

    printf("\n\n=====================================================\n");
        printf("Sorry but there is no Supported Extention -___- \n");
    printf("=====================================================\n\n\n");

    exit(EXIT_STATUS);
}


void writeCSV( char* filename,const struct Studenten *student){
    printf("writeCSV \n");

}

void writeJSON( char* filename,const struct Studenten *student){
        FILE *file = fopen(filename, "w");

        if(file == NULL){
            printf("File could not be opened\n");
            exit(EXIT_STATUS);
        }

        fprintf(file, "{\n");
        fprintf(file, "  \"students\": [\n");
        int i = 1;

        while (strlen(student[i].Nachname)  > 0) {
            fprintf(file, "    {\n");
            fprintf(file, "      \"Nachname\": \"%s\",\n", student[i].Nachname);
            fprintf(file, "      \"Vorname\": \"%s\",\n", student[i].Vorname);
            fprintf(file, "      \"Matrikelnummer\": %s,\n", student[i].MatrikuelNummer);
            fprintf(file, "      \"Semester\": \"%s\",\n", student[i].Semester);
            fprintf(file, "      \"Gruppe\": \"%s\",\n", student[i].Gruppe);
            fprintf(file, "      \"Note\": %.1f\n", student[i].Note);
            fprintf(file, "    }");
            if (i < 5 - 1) {
                fprintf(file, ",");
            }
            fprintf(file, "\n");
            i++;
        }
        fprintf(file, "  ]\n");
        fprintf(file, "}\n");

        fclose(file);


}

void writeXML( char* filename,const struct Studenten *student){
    printf("writeXML \n");

}

void NoSupportedExtentionWrite( char* filename,const struct Studenten *student){

    printf("\n\n=====================================================\n");
        printf("Sorry but there is no Supported Extention -___- \n");
    printf("=====================================================\n\n\n");

    exit(EXIT_STATUS);
}





void checkCommand(int argc , char * argv[]){
    if(argc!=5){
        printf("\nNumber of Argements is not as expected \n");
        exit(EXIT_STATUS);
    }

    if(strchr(argv[2], '.') == NULL){
        printf("\nInput file ( %s ) is without extention\n",argv[2]);
        exit(EXIT_STATUS);
    }

    if(strchr(argv[4], '.') == NULL){
        printf("\nOutput file ( %s ) is without extention\n",argv[4]);
        exit(EXIT_STATUS);
    }

    if(strcmp(argv[1],"-i")!=0 || strcmp(argv[3],"-o")!=0  ){
        printf("Parameters are not as expected \nonly -i and -o are accepted");
        exit(EXIT_STATUS);
    }

        printf("\n\n=========================================\n");
            printf("command is totaly correct ^___^  \n");
        printf("=========================================\n\n\n");
}

char* getFileExtention(char *filename){

    char* extension = NULL;
    char* dot = strrchr(filename, '.');
    if (dot && dot != filename && *(dot + 1)) {
        extension = dot + 1;
    }
    return extension;
}

char* getFileName(char *x){
    return strtok(x,".");
}

enum FileExtention {
    NONE,
    CSV,
    JSON,
    XML
};

enum FileExtention convertExtentionToNumber(char* fileExtention){

    if(strcmp(fileExtention,"csv")==0){
        return CSV;
    }else if(strcmp(fileExtention,"json")==0){
        return JSON;
    }else if(strcmp(fileExtention,"xml")==0){
        return XML;
    }else{
        return NONE;
    }
}


void (*readerFuncs[])( char* filename ,struct Studenten *student) = {NoSupportedExtentionRead,readCSV, readJSON, readXML};
void (*writerFuncs[])( char* filename,const struct Studenten *student) = {NoSupportedExtentionWrite,writeCSV, writeJSON, writeXML};


int main(int argc, char* argv[])
{

    checkCommand(argc,argv);

     struct Studenten student[MAX_STUDENT_NUMBER];

     int NumberOfStudents = 0;

    char* copyInputArgument  = argv[2];
    char* copyOutputArgument = argv[4];

    char project_path_input[] = "C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\FileConverter\\";
    strcat(project_path_input,argv[2]);
    char filePath_input[strlen(project_path_input)+1];
    strcpy(filePath_input,project_path_input);

    char project_path_output[] = "C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\FileConverter\\";
    strcat(project_path_output,argv[4]);
    char filePath_output[strlen(project_path_output)+1];
    strcpy(filePath_output,project_path_output);


    char * fileInExt =  getFileExtention(copyInputArgument) ;
    char * fileOutExt = getFileExtention(copyOutputArgument) ;
    char* fileInName = getFileName(copyInputArgument) ;
    char* fileOutName = getFileName(copyOutputArgument);

    int  chooseReadFunction = convertExtentionToNumber(fileInExt);
    int  chooseWriteFunction =convertExtentionToNumber(fileOutExt);

    //printf("\n\n%s\n\n",filePath);
    if(chooseReadFunction != 0 && chooseWriteFunction!=0 ){
       readerFuncs[chooseReadFunction](filePath_input,student);
//        for (int i = 0; i <NumberOfStudents; ++i) {
//            printf("%s\n",student[i].Nachname);
//            printf("%s\n",student[i].Vorname);
//            printf("%s\n",student[i].MatrikuelNummer);
//            printf("%s\n",student[i].Semester);
//            printf("%s\n",student[i].Gruppe);
//            //printf("%s\n",student[i].Note);
//        }

        writerFuncs[chooseWriteFunction](filePath_output,student);
    }else{
        printf("Extention fehler");
    }



    return 0;
}




