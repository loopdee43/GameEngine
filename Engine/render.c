#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include "nuklear.h"
#include "loadShader.h"
#include <cglm/cglm.h>

int objCount;

typedef struct{
    unsigned int VBO;
    unsigned int VAO;
    char* name;

}Object

Object* objects;

void addObj(char* filename, char* objName, float pos[3]){
    objCount++;
    glm->vec3 v;

    v.x = pos[0];
    v.y = pos[1];
    v.z = pos[2];

    objects[objCount].name = objName;

    vertices = {0}; // load with assimp

    glGenVertexArrays(1, &VAO); 
   
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);




    



}