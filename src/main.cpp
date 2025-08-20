// Imports
#include <cstdio>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Need error events before creating windows in GLFW

/*
 in the first arguement it recieves the error code, 
and in the seocnd it gets the error desc as utf8 ecode
*/

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

// main function

int main(){

    glfwSetErrorCallback(error_callback);

    // initialise GLFW

    if(!glfwInit())
    {
        return -1;
    }

    // Create Window, with arguements size, x,y, Name, and values

    GLFWwindow* window = glfwCreateWindow(640,480, "Space Invaders", NULL, NULL);
    
    glfwMakeContextCurrent(window);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    // Null is used for when its full screen and 640, 480 is the small screen window size
    if (!window)
    {
        glfwTerminate(); // destroys the window if there is issue creating it
        return -1;
    }

    // init GLEW
    GLenum err = glewInit();

    if(err != GLEW_OK)
    {
        fprintf(stderr, "Error initializing GLEW.\n");
        glfwTerminate();
        return -1;

    }

    int glVersion[2] = {-1, 1};
    glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
    glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);

    printf("Using OpenGL: %d.%d\n", glVersion[0], glVersion[1]);

    glClearColor(1.0, 0.0, 0.0, 1.0);

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
