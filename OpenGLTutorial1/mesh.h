#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "obj_loader.h"

class Vertex
{
public:
    Vertex(const glm::vec3& pos, const glm::vec2& texCoord,
           const glm::vec3& normal = glm::vec3(0,0,0))
    {
        this->m_pos = pos;
        this->m_texCoord = texCoord;
        this->m_normal = normal;
    }

    inline glm::vec3* GetPos() { return &m_pos; }
    inline glm::vec2* GetTexCoord() { return &m_texCoord; }
    inline glm::vec3* GetNormal() { return &m_normal; }

private:
    glm::vec3 m_pos;
    glm::vec2 m_texCoord;
    glm::vec3 m_normal;
};

class Mesh
{
public:
    Mesh(Vertex* vertices, unsigned int numVertices,
            unsigned int* indices, unsigned int numIndices);

    Mesh(const std::string& fileName);

    void Draw();

    virtual ~Mesh();

private:

    void InitMesh(const IndexedModel& model);

    enum
    {
        POSITION_VB,
        TEXCOORD_VB,
        NORMAL_VB,
        INDEX_VB,
        NUM_BUFFERS
    };

    GLuint      m_vertexArrayObject;
    GLuint      m_vertexArrayBuffers[NUM_BUFFERS];
    uint32_t    m_drawCount;

};

