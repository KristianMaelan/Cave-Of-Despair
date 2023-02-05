#include "interaction.h"

Interaction::Interaction() : moveX{0.0f}, moveY{0.0f}, moveZ{0.0f}
{
    mVertices.push_back(Vertex{0,0,0,1,1,0});
    mVertices.push_back(Vertex{1,0,0,1,1,0});
    mVertices.push_back(Vertex{0,1,1,1,1,0});

    mMatrix.setToIdentity();
}

Interaction::~Interaction()
{

}

void Interaction::init(GLint matrixUniform)
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

void Interaction::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

void Interaction::move(float x, float y, float z)
{
    moveX += x;
    moveY += y;
    moveZ += z;

    mMatrix.translate(moveX, moveY, moveZ);

}
