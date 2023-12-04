#ifndef RENDER_H
#define RENDER_H

typedef struct {} vec3d;

void addObj(char* filename, char* objName, float pos[3]);

void addTex(char* filename, char* objName);

void rotateObj(char* objName, float angle, float axis[3]);

void addCam(char* camName, float pos[3], float direction[3]);

void pushFrame();


#endif