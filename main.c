#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <cglm/cglm.h>



int main(){
    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Game", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        return -1;
    }



    

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);


	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

    GLuint programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

    GLuint MatrixID = glGetUniformLocation(programID, "MVP");
    
    mat4 Projection;
    glm_perspective(glm_rad(45.0f), 4.0f/3.0f, 0.1f, 100.0f, Projection);

    mat4 View;


    glm_lookat((vec3){4, 3, 3}, (vec3){0, 0, 0}, (vec3){0, 1, 0}, View);


    mat4 Model;

    glm_mat4_identity(Model);



    mat4 MVP = Projection * View * Model;




    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
    }



        // This will identify our vertex buffer
    GLuint vertexbuffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    
    do{
            glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glUseProgram(programID);

            glUniformMatrixfv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

                        // 1st attribute buffer : vertices
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
            glVertexAttribPointer(
               0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
               3,                  // size
               GL_FLOAT,           // type
               GL_FALSE,           // normalized?
               0,                  // stride
               (void*)0            // array buffer offset
            );
            // Draw the triangle !
            glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
            glDisableVertexAttribArray(0);
            
            glfwSwapBuffers(window);
            glfwPollEvents();
    }while( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );

    	// Cleanup VBO and shader
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
    
