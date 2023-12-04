#include <stdio.h>
#include <string.h>
#include "user.h"
void addUser(user u){
   FILE *f;
    user u;
    f = fopen("user.txt","r");
    while(fscanf(f,"%s %s ",u.username,u.password) != EOF){
        if(strcmp(u.username,username) == 0){
            if(strcmp(u.password,password) == 0){
                return 1;
    }
  return 0;
    
}
}

