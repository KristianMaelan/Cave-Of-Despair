#include "scene1_plan.h"

Scene1_plan::Scene1_plan()
{
    /*
    float heightY = 1;
    float dimension = 10;

    mVertices.push_back(Vertex{0, heightY, 0, 1, 0, 0});                    // 1st
    mVertices.push_back(Vertex{0, heightY, dimension, 1, 0, 0});
    mVertices.push_back(Vertex{dimension, heightY, 0, 1, 0, 0});
    mVertices.push_back(Vertex{dimension, heightY, 0, 1, 0, 0});
    mVertices.push_back(Vertex{dimension, heightY, dimension, 1, 0, 0});
    mVertices.push_back(Vertex{0, heightY, dimension, 1, 0, 0});

    mVertices.push_back(Vertex{0, heightY, 0, 0, 1, 0});                    // 2nd
    mVertices.push_back(Vertex{0, heightY, -dimension, 0, 1, 0});
    mVertices.push_back(Vertex{dimension, heightY, 0, 0, 1, 0});
    mVertices.push_back(Vertex{dimension, heightY, 0, 0, 1, 0});
    mVertices.push_back(Vertex{dimension, heightY, -dimension, 0, 1, 0});
    mVertices.push_back(Vertex{0, heightY, -dimension, 0, 1, 0});
    */

}

Scene1_plan::Scene1_plan(float x, float y, float z, float r, float g, float b)
{
    mVertices.push_back(Vertex{-x, y, -z, r, g, b});
    mVertices.push_back(Vertex{-x, y, z, r, g, b});
    mVertices.push_back(Vertex{x, y, z, r, g, b});
    mVertices.push_back(Vertex{x, y, z, r, g, b});
    mVertices.push_back(Vertex{x, y, -z, r, g, b});
    mVertices.push_back(Vertex{-x, y, -z, r, g, b});

    mMatrix.setToIdentity();
}

Scene1_plan::~Scene1_plan()
{

}

void Scene1_plan::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;

    initializeOpenGLFunctions();

    //Vertex Array Object - VAO
    glGenVertexArrays( 1, &mVAO );
    glBindVertexArray( mVAO );

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO );

    glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof( Vertex ), mVertices.data(), GL_STATIC_DRAW );

    // 1rst attribute buffer : vertices
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof( Vertex ),  (GLvoid*)(3 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Scene1_plan::draw()
{
    if (checkScene1)
    {
        glBindVertexArray( mVAO );
        glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
        glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
    }
}
