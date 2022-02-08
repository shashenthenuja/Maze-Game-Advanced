#ifndef FILEIO_H
#define FILEIO_H
#define FALSE 0
#define TRUE !FALSE

void fileRead(char * fileName, int *** metaDataTable, int * metadataAmount, int * mapRow, int * mapCol);

#endif