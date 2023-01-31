#include "trianglesurface.h"

TriangleSurface::TriangleSurface()
{
    Vertex v0{0.0,0.0,0.0, 1,0,0};    mVertices.push_back(v0);
    Vertex v1(0.5,0.0,0.0, 0,1,0);    mVertices.push_back(v1);
    Vertex v2{0.5,0.5,0.0, 0,0,1};    mVertices.push_back(v2);
    Vertex v3{0.0,0.0,0.0, 0,0,1};    mVertices.push_back(v3);
    Vertex v4{0.5,0.5,0.0, 0,1,0};    mVertices.push_back(v4);
    Vertex v5{0.0,0.5,0.0, 1,0,0};    mVertices.push_back(v5);

    mMatrix.setToIdentity();
}

TriangleSurface::~TriangleSurface()
{

}
// Parameternavnet er byttet ut fra leksjonen
// Koden er ellers som for XYZ::init()
void TriangleSurface::init(GLint matrixUniform)
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

void TriangleSurface::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}
