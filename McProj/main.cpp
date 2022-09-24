#include <iostream>
#include <filesystem>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <pybind11/embed.h>
namespace py = pybind11;

#include "Plugins.hpp"

int main() {

    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create main window
    GLFWwindow* window = glfwCreateWindow(800, 600, "change later", NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
        std::cout << "Couldn't create a GLFW window.";
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Couldn't initialize GLAD";
        return -1;
    }

    py::scoped_interpreter pythonInterpreter;
    py::module_ os = py::module_::import("os");
    py::module_ sys = py::module_::import("sys");

    std::string path = os.attr("getcwd")().cast<std::string>();
    sys.attr("path").attr("append")(path + "\\plugins");

    Plugins plugins = Plugins();

    plugins.loadAllPlugins();
	try {
	}
	catch (py::error_already_set e) {
		std::cout << e.what();
	}

    while (!glfwWindowShouldClose(window)) {

        glClearColor(0.471f, 0.655f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
//int main() {
//    /****************************************************************/
//    /*                  Initialize GLFW and OpenGL                  */
//    /****************************************************************/
//
//    
//    glfwMakeContextCurrent(mainWindow);
//    glfwSetFramebufferSizeCallback(mainWindow, framebufferSizeCallback);
//    glfwSetCursorPosCallback(mainWindow, mouseCallback);
//
//    glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//        addToLog("Couldn't initialize GLAD");
//        return -1;
//    }
//
//    // Set some OpenGL settings
//    glEnable(GL_DEPTH_TEST);
//
//    CubeRenderer cr = CubeRenderer("stone", 0, 0, -0.4);
//    glm::mat4 projectionMatrix = glm::perspective(glm::radians(90.0f), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
//    cr.useTransformationMatrix(projectionMatrix, mainCamera.viewMatrix());
//
//    while (!glfwWindowShouldClose(mainWindow)) {
//
//        // Timing
//        float currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - prevousFrame;
//        prevousFrame = currentFrame;
//
//        // Input Handling
//        processInput(mainWindow);
//
//        /****************************************************************/
//        /*                           Rendering                          */
//        /****************************************************************/
//        glClearColor(0.471f, 0.655f, 1.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        cr.shader.activate();
//        cr.draw();
//
//        glfwSwapBuffers(mainWindow);
//
//        glfwPollEvents();
//    }
//    glfwTerminate();
//    return 0;
//}