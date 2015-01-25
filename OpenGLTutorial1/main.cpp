#include <iostream>

#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "GL/glew.h"
#include "texture.h"
#include "transform.h"

int main(int argc, char** argv)
{
    Display display(800,600, "Hello World");

    Shader shader("./res/basicShader");

    Texture texture("./res/brick.jfif");

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
        transform.GetPos().y = cosCounter;
        transform.GetRot().z = counter;
        transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

        shader.Bind();
        shader.Update(transform);
        texture.Bind(0);
        mesh.Draw();

        GLenum myError = glGetError();

        display.Update();
        counter += 0.001f;
    }

    return 0;
}