#include "cube.h"

#include <iostream>

Cube::Cube()
{
    // Joakim - Test1
    /*
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f,-1.0f,-1.0f, // triangle 1 : begin
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, // triangle 1 : end
        1.0f, 1.0f,-1.0f, // triangle 2 : begin
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f, // triangle 2 : end

        1.0f,-1.0f, 1.0f,   //3
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,

        1.0f, 1.0f,-1.0f,   //4
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,

        -1.0f,-1.0f,-1.0f,  //5
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,

        1.0f,-1.0f, 1.0f,   //6
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,

        -1.0f, 1.0f, 1.0f,  //7
        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,

        1.0f, 1.0f, 1.0f,   //8
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,

        1.0f,-1.0f,-1.0f,   //9
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,

        1.0f, 1.0f, 1.0f,   //10
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,

        1.0f, 1.0f, 1.0f,   //11
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,

        1.0f, 1.0f, 1.0f,   //12
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f
    };
    */

    float x = 1.0f, y = 1.0f, z = 1.0f, r = 1.0f, g = 0.0f, b = 0.0f;
    // Joakim - Test2       6 kvadrater : 12 triangler
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});  // Triangle 1 : begin
    mVertices.push_back(Vertex{-x, -y, z, r, g, b});
    mVertices.push_back(Vertex{-x, y, z, r, g, b});    // Triangle 1 : end
    mVertices.push_back(Vertex{x, y, -z, r, g, b});    // Triangle 2 : begin
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{-x, y, -z, r, g, b});   // Triangle 2 : end
    mVertices.push_back(Vertex{x, -y, z, r, g, b});    // Triangle 3 : begin
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});   // Triangle 3 : end
    mVertices.push_back(Vertex{x, y, -z, r, g, b});    // Triangle 4 : begin
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});  // Triangle 4 : end
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});  // Triangle 5 : begin
    mVertices.push_back(Vertex{-x, y, z, r, g, b});
    mVertices.push_back(Vertex{-x, y, -z, r, g, b});   // Triangle 5 : end
    mVertices.push_back(Vertex{x, -y, z, r, g, b});    // Triangle 6 : begin
    mVertices.push_back(Vertex{-x, -y, z, r, g, b});
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});  // Triangle 6 : end
    mVertices.push_back(Vertex{-x, y, z, r, g, b});    // Triangle 7 : begin
    mVertices.push_back(Vertex{-x, -y, z, r, g, b});
    mVertices.push_back(Vertex{x, -y, z, r, g, b});    // Triangle 7 : end
    mVertices.push_back(Vertex{x, y, z, r, g, b});     // Triangle 8 : begin
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{x, y, -z, r, g, b});    // Triangle 8 : end
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});   // Triangle 9 : begin
    mVertices.push_back(Vertex{x, y, z, r, g, b});
    mVertices.push_back(Vertex{x, -y, z, r, g, b});    // Triangle 9 : end
    mVertices.push_back(Vertex{x, y, z, r, g, b});     // Triangle 10 : begin
    mVertices.push_back(Vertex{x, y, -z, r, g, b});
    mVertices.push_back(Vertex{-x, y, -z, r, g, b});   // Triangle 10 : end
    mVertices.push_back(Vertex{x, y, z, r, g, b});     // Triangle 11 : begin
    mVertices.push_back(Vertex{-x, y, -z, r, g, b});
    mVertices.push_back(Vertex{-x, y, z, r, g, b});    // Triangle 11 : end
    mVertices.push_back(Vertex{x, y, z, r, g, b});     // Triangle 12 : begin
    mVertices.push_back(Vertex{-x, y, z, r, g, b});
    mVertices.push_back(Vertex{x, -y, z, r, g, b});    // Triangle 12 : end

    mMatrix.setToIdentity();
}

Cube::~Cube()
{

}

void rotation()
{
    //const float rSpeed = 10.0f;


}

void Cube::init(GLint matrixUniform)
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

    //enable the matrixUniform
    // mMatrixUniform = glGetUniformLocation( matrixUniform, "matrix" );

    glBindVertexArray(0);
}

void Cube::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    //glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
    glDrawArrays(GL_TRIANGLES, 0, 12*3);
}
