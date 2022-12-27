#include "grade_school.h"
#include <stdlib.h>
void init_roster(roster_t *roster){
    roster->size = 0;
    roster->students = NULL;
}

void free_roster(roster_t *roster){
    for(node_t *it = roster->students; it != NULL; it = it->next){
        free(it);
    }
}

bool remove_student(roster_t *roster, const char *name){
    if(roster->size == 0){
        return false;
    }
    else{
        for(node_t *it = roster->students; it != NULL; it = it->next){
            if(it->next->data.name == name){
                node_t *aux = it->next;
                it->next = it->next->next;
                free(aux);
                return true;
            }
        }
        return false;
    }
}