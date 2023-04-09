#include "door.h"

Door::Door(float x, float y, float z, float r, float g, float b)
{
    // Dynamisk
    /*
    mVertices.push_back(Vertex{(-x * 0.4f), -y, -z, r, g, b});
    mVertices.push_back(Vertex{(x * 0.4f), -y, -z, r, g, b});
    mVertices.push_back(Vertex{(x * 0.4f), (y * 0.2f), -z, r, g, b});
    mVertices.push_back(Vertex{(x * 0.4f), (y * 0.2f), -z, r, g, b});
    mVertices.push_back(Vertex{(-x * 0.4f), (y * 0.2f), -z, r, g, b});
    mVertices.push_back(Vertex{(-x * 0.4f), -y, -z, r, g, b});
    */

    if (!doorOpen)
    {
        Vertex v0{(-x * 0.4f), -y, -z, r, g, b};             mVertices.push_back(v0);
        Vertex v1((x * 0.4f), -y, -z, r, g, b);              mVertices.push_back(v1);
        Vertex v2{(x * 0.4f), (y * 0.2f), -z, r, g, b};      mVertices.push_back(v2);
        Vertex v3{(x * 0.4f), (y * 0.2f), -z, r, g, b};      mVertices.push_back(v3);
        Vertex v4{(-x * 0.4f), (y * 0.2f), -z, r, g, b};     mVertices.push_back(v4);
        Vertex v5{(-x * 0.4f), -y, -z, r, g, b};             mVertices.push_back(v5);
    }

    // Tried rotating the door when opened. WIP

    if (doorOpen)
    {
        qDebug() << "doorOpen";
        Vertex v0{(x * 0.4f), -y, (-z * 1.8f), r, g, b};             mVertices.push_back(v0);
            Vertex v1((x * 0.4f), -y, -z, r, g, b);              mVertices.push_back(v1);
            Vertex v2{(x * 0.4f), (y * 0.2f), -z, r, g, b};      mVertices.push_back(v2);
            Vertex v3{(x * 0.4f), (y * 0.2f), -z, r, g, b};      mVertices.push_back(v3);
        Vertex v4{(x * 0.4f), (y * 0.2f), (-z * 1.8f), r, g, b};     mVertices.push_back(v4);
        Vertex v5{(-x * 0.4f), -y, (-z * 1.8f), r, g, b};             mVertices.push_back(v5);
        //v0 * QVector3D{}
    }


    /* Funker
    mVertices.push_back(Vertex{-0.4, -y, -z, r, g, b});
    mVertices.push_back(Vertex{0.4, -y, -z, r, g, b});
    mVertices.push_back(Vertex{0.4, 0.2, -z, r, g, b});
    mVertices.push_back(Vertex{0.4, 0.2, -z, r, g, b});
    mVertices.push_back(Vertex{-0.4, 0.2, -z, r, g, b});
    mVertices.push_back(Vertex{-0.4, -y, -z, r, g, b});
    */

    mMatrix.setToIdentity();
}

Door::~Door()
{

}

void Door::init(GLint matrixUniform)
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

void Door::draw()
{
    if (checkScene1)
    {
        glBindVertexArray( mVAO );
        glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
        glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
    }
}
