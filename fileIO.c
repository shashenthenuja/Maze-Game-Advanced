/* *********************************************************************
* File:       fileIO.c
* Author:     G.G.T.Shashen
* Created:    06/09/2021
* Modified:   14/10/2021
* Desc:       FileIO implementation to extract data from map.txt
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"

void fileRead(char * fileName, int *** metaDataTable, int * metadataAmount, int * mapRow, int * mapCol)
{
    FILE * fp = fopen(fileName,"r");
    if (fp == NULL)
    {
        perror("Error opening map.txt");

    }else
    {
        int done = FALSE;
        int dataAmount;
        int row;
        int col;
        int objectRow;
        int objectCol;
        int objectCode;
        int nRead;
        int i;
        int count;
        int ** table;
        count = 0;
        nRead = fscanf(fp, "%d %d %d", &dataAmount, &row, &col);
        table = (int **) malloc(sizeof(int *) * (dataAmount));
        for(i = 0 ; i < (dataAmount) ; i++)
        {
            table[i] = (int *) malloc(sizeof(int) * 3);
        }
        while (!done)
        {
            nRead = fscanf(fp, "%d %d %d", &objectRow, &objectCol, &objectCode);
            if (nRead != 3)
            {
                done = TRUE;
            }else
            {
                table[count][0] = objectRow;
                table[count][1] = objectCol;
                table[count][2] = objectCode;
                count += 1;
            }
            
        }
        *mapRow = row;
        *mapCol = col;
        *metadataAmount = dataAmount;
        *metaDataTable = table;
        
        if (ferror(fp))
        {
            perror("Error reading from map.txt");
        }
        fclose(fp);
        fp = NULL;
    }
}