#include <stdlib.h>
#include <stdio.h>
#include "../Heathers/Parser.h"

char** par_loadTXT(char* path, int volume, int jump)
{
    char **buffer;
    int scnVls;
    int line=0;
    FILE* txtFile;
    txtFile = fopen(path,"r");
    buffer = (char**) malloc(volume * sizeof(char*));
    for(int j = 0; j<volume; j++)
    {
        buffer[j] = (char*) malloc(129 * sizeof(char));
    }
    if(txtFile!=NULL&&path!=NULL&&buffer!=NULL)
    {
        while(!feof(txtFile) && line!=jump)
        {
            for(int i = 0; i<volume; i++)
            {
                if(volume-i!=1)
                {
                    scnVls=fscanf(txtFile,"%[^,],",buffer[i]);
                }
                else
                {
                    scnVls=fscanf(txtFile,"%[^\n]\n",buffer[i]);
                }
                if(scnVls!=1)
                {
                    break;
                }
            }
            if(scnVls!=1)
            {
                buffer = NULL;
                break;
            }
            line++;
        }
        fclose(txtFile);
    }
    return buffer;
}

int par_loadBin(char* path, void* to, int volume, int jump)
{
    int isError = 1;
    int aux;
    char auxChar = '\0';
    int line = 0;
    FILE* binFile;
    binFile = fopen(path,"rb");
    if(binFile!=NULL&&to!=NULL)
    {
        while(!feof(binFile) && line!=jump)
        {
            if(line==0)
            {
                while(!feof(binFile)&&auxChar!='\n')
                {
                    auxChar=(char)fgetc(binFile);
                }
            }
            aux=fread(to,volume,1,binFile);
            if(aux==volume&&line==jump)
            {
                isError=0;
            }
            if(aux!=volume)
            {
                break;
            }
            aux=fgetc(binFile);
            line++;
        }
    }
    return isError;
}
