#include "pressureplate.h"

PressurePlate::PressurePlate(float x, float y, float z, float r, float g, float b)
{
    // Dynamisk
    mVertices.push_back(Vertex{(-x * 0.4f), -y, -z, r, g, b});
    mVertices.push_back(Vertex{(x * 0.4f), -y, -z, r, g, b});
    mVertices.push_back(Vertex{(-x * 0.4f), -y, (-z * 1.6f), r, g, b});
    mVertices.push_back(Vertex{(-x * 0.4f), -y, (-z * 1.6f), r, g, b});
    mVertices.push_back(Vertex{(x * 0.4f), -y, (-z * 1.6f), r, g, b});
    mVertices.push_back(Vertex{(x * 0.4f), -y, -z, r, g, b});

    /*
    mVertices.push_back(Vertex{-0.4, -y, -z, r, g, b});
    mVertices.push_back(Vertex{0.4, -y, -z, r, g, b});
    mVertices.push_back(Vertex{-0.4, -y, -1.6, r, g, b});
    mVertices.push_back(Vertex{-0.4, -y, -1.6, r, g, b});
    mVertices.push_back(Vertex{0.4, -y, -1.6, r, g, b});
    mVertices.push_back(Vertex{0.4, -y, -z, r, g, b});
    */

    mMatrix.setToIdentity();
}

PressurePlate::~PressurePlate()
{

}

void PressurePlate::init(GLint matrixUniform)
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

    // 3rd attribute buffer : NO IDEA? NORMALS? OR SOMETHING?
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,  sizeof( Vertex ),  (GLvoid*)(6 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(2);

    //enable the matrixUniform
    // mMatrixUniform = glGetUniformLocation( matrixUniform, "matrix" );


    glBindVertexArray(0);
}

void PressurePlate::draw()
{
    if (checkScene1)
    {
        glBindVertexArray( mVAO );
        glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
        glDrawArrays(GL_TRIANGLES, 0, mVertices.size());

        // constant rotation
        //mMatrix.rotate(-1, 0, 1, 0);
    }
}
