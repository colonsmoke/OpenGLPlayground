#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
    Vertex(const glm::vec3& pos, const glm::vec2& texCoord)
    {
        this->m_pos = pos;
        this->m_texCoord = texCoord;
    }

    inline glm::vec3* GetPos() { return &m_pos; }
    inline glm::vec2* GetTexCoord() { return &m_texCoord; }

private:
    glm::vec3 m_pos;
    glm::vec2 m_texCoord;
};

class Mesh
{
public:
    Mesh(Vertex* vertices, unsigned int numVertices);

    void Draw();

    virtual ~Mesh();

private:
    enum
    {
        POSITION_VB,
        TEXCOORD_VB,
        NUM_BUFFERS
    };

    GLuint      m_vertexArrayObject;
    GLuint      m_vertexArrayBuffers[NUM_BUFFERS];
    uint32_t    m_drawCount;

};

