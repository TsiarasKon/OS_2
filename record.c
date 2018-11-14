#include "headers/record.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "headers/util.h"

bool searchRecord(Record r, char *pattern) {
    if ( strstr(r.fisrtName, pattern) || strstr(r.lastName, pattern) ||
            strstr(r.street, pattern) || strstr(r.city, pattern) ||
            strstr(r.zipCode, pattern) )
        return true;
    // Checking numeric fields as well:
    char numStr[MAX_NUM_STRING_SIZE];
    sprintf(numStr, "%ld", r.am);
    if ( strstr(numStr, pattern) ) return true;
    sprintf(numStr, "%d", r.streetNum);
    if ( strstr(numStr, pattern) ) return true;
    sprintf(numStr, "%f", r.salary);
    if ( strstr(numStr, pattern) ) return true;
    return false;
}

bool readRecord(int fd, Record *record) {       // TODO: improve and use
    if (read(fd, record, sizeof(Record)) < 0) {
        return false;
    }
    return true;
}

void printRecord(Record r) {
    printf("%ld | %s %s | %s %d %s %s | %f\n", r.am, r.fisrtName, r.lastName,
           r.street, r.streetNum, r.city, r.zipCode, r.salary);
}
