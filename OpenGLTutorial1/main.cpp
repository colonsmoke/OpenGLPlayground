#include <iostream>

#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "GL/glew.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 1280
#define HEIGHT 1024
int main(int argc, char** argv)
{
    Display display(WIDTH, HEIGHT, "OpenGL Playground");
    Shader shader("./res/basicShader");
    Texture texture("./res/whiteGloss.jpg");
    Camera camera(glm::vec3(0, 0, -7), 70.0, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
    Transform transform;

    float counter = 0.0f;

    Vertex vertices[] = {   Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0,0.0)),
                            Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5,1.0)),
                            Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)) };

    unsigned int indices[] = { 0, 1, 2 };

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]),
                indices, sizeof(indices) / sizeof(indices[0]) );

    Mesh mesh2("./res/eva.obj");

    while (!display.IsClosed())
    {
        display.Clear(0.0f, 0.15f, 0.35f, 1.0f);

        float sinCounter = sinf(counter);
        float cosCounter = cosf(counter);

        transform.GetPos().x = sinCounter;
        transform.GetPos().z = cosCounter*3;
        transform.GetRot().z = counter;
        transform.GetRot().y = counter + 180.0;
        transform.GetRot().x = counter;

        shader.Bind();
        shader.Update(transform, camera);
        texture.Bind(0);
        mesh2.Draw();

        GLenum myError = glGetError();

        display.Update();
        counter += 0.001f;
    }

    return 0;
}