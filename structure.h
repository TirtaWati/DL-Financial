#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__
#include "variable.h"

typedef struct {
    char nama[30];
    char username[10];
    char password[8];
    char email[30];
	float uang; 
}User;

//Mendeklarasikan variabel u pada struct User
User u;


#endif 
