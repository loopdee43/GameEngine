#ifndef RENDER_H
#define RENDER_H

typedef struct {} vec3d;

void addObj(char* filename, char* objName, float[3] pos);

void addTex(char* filename, char* objName);

void rotateObj(char* objName, float angle, float[3] axis);

void addCam(char* camName, float[3] pos, float[3] direction);

void pushFrame();


#endif