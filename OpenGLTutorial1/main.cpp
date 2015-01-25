#include <iostream>

#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "GL\glew.h"

int main(int argc, char** argv)
{
    Display display(800,600, "Hello World");

    Shader shader("./res/basicShader");

    Vertex vertices[] = {   Vertex(glm::vec3(-0.5, -0.5, 0)),
                            Vertex(glm::vec3(0, 0.5, 0)),
                            Vertex(glm::vec3(0.5, -0.5, 0)) };

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

    while (!display.IsClosed())
    {
        display.Clear(0.0f, 0.15f, 0.35f, 1.0f);

        shader.Bind();

        mesh.Draw();

        GLenum myError = glGetError();

        display.Update();
    }

    return 0;
}