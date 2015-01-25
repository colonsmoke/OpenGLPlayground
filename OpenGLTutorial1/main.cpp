#include <iostream>

#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "GL/glew.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600
int main(int argc, char** argv)
{
    Display display(WIDTH, HEIGHT, "OpenGL Playground");

    Shader shader("./res/basicShader");

    Texture texture("./res/brick.jfif");

    Camera camera(glm::vec3(0, 0, -3), 70.0, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);

    Transform transform;

    float counter = 0.0f;

    Vertex vertices[] = {   Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0,0.0)),
                            Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5,1.0)),
                            Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)) };

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

    while (!display.IsClosed())
    {
        display.Clear(0.0f, 0.15f, 0.35f, 1.0f);

        float sinCounter = sinf(counter);
        float cosCounter = cosf(counter);

        transform.GetPos().x = sinCounter;
        transform.GetPos().z = cosCounter;
        transform.GetRot().z = counter;
        transform.GetRot().y = counter;
        transform.GetRot().x = counter;
        // transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

        shader.Bind();
        shader.Update(transform, camera);
        texture.Bind(0);
        mesh.Draw();

        GLenum myError = glGetError();

        display.Update();
        counter += 0.001f;
    }

    return 0;
}