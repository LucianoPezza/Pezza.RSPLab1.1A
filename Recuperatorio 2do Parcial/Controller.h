#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
int controller_ListBicis(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

#endif // CONTROLLER_H_INCLUDED
