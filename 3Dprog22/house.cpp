#include "house.h"

house::house()
{

}

house::house(float x, float y, float z, float r, float g, float b)
{
    // Front plane left
    mVertices.push_back(Vertex{-x, -y, -z, r, 1, b});
    mVertices.push_back(Vertex{-x * 0.4f, -y, -z, r, 1, b});
    mVertices.push_back(Vertex{-x * 0.4f, y, -z, r, 1, b});
    mVertices.push_back(Vertex{-x * 0.4f, y, -z, r, 1, b});
    mVertices.push_back(Vertex{-x, y, -z, r, 1, b});
    mVertices.push_back(Vertex{-x, -y, -z, r, 1, b});

    // Front plane right
    mVertices.push_back(Vertex{x * 0.4f, -y, -z, r, 1, b});
    mVertices.push_back(Vertex{x, -y, -z, r, 1, b});
    mVertices.push_back(Vertex{x, y, -z, r, 1, b});
    mVertices.push_back(Vertex{x, y, -z, r, 1, b});
    mVertices.push_back(Vertex{x * 0.4f, y, -z, r, 1, b});
    mVertices.push_back(Vertex{x * 0.4f, -y, -z, r, 1, b});

    // Front plane doorframe
    mVertices.push_back(Vertex{-x * 0.4f, y * 0.2f, -z, r, 1, b});
    mVertices.push_back(Vertex{x * 0.4f, y * 0.2f, -z, r, 1, b});
    mVertices.push_back(Vertex{x * 0.4f, y, -z, r, 1, b});
    mVertices.push_back(Vertex{x * 0.4f, y, -z, r, 1, b});
    mVertices.push_back(Vertex{-x * 0.4f, y, -z, r, 1, b});
    mVertices.push_back(Vertex{-x * 0.4f, y * 0.2f, -z, r, 1, b});

    // Back plane
    mVertices.push_back(Vertex{-x, -y, z, 1, g, b});    // 3rd
    mVertices.push_back(Vertex{x, -y, z, 1, g, b});
    mVertices.push_back(Vertex{x, y, z, 1, g, b});
    mVertices.push_back(Vertex{x, y, z, 1, g, b});      // 4th
    mVertices.push_back(Vertex{-x, y, z, 1, g, b});
    mVertices.push_back(Vertex{-x, -y, z, 1, g, b});

    // Left plane
    mVertices.push_back(Vertex{-x, y, z, r, 1, b});     // 5th
    mVertices.push_back(Vertex{-x, y, -z, r, 1, b});
    mVertices.push_back(Vertex{-x, -y, -z, r, 1, b});
    mVertices.push_back(Vertex{-x, -y, -z, r, 1, b});   // 6th
    mVertices.push_back(Vertex{-x, -y, z, r, 1, b});
    mVertices.push_back(Vertex{-x, y, z, r, 1, b});

    // Right plane
    mVertices.push_back(Vertex{x, y, z, r, g, 1});      // 7th
    mVertices.push_back(Vertex{x, y, -z, r, g, 1});
    mVertices.push_back(Vertex{x, -y, -z, r, g, 1});
    mVertices.push_back(Vertex{x, -y, -z, r, g, 1});    // 8th
    mVertices.push_back(Vertex{x, -y, z, r, g, 1});
    mVertices.push_back(Vertex{x, y, z, r, g, 1});

    // Bottom plane
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});   // 9th
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{x, -y, z, r, g, b});
    mVertices.push_back(Vertex{x, -y, z, r, g, b});     // 10th
    mVertices.push_back(Vertex{-x, -y, z, r, g, b});
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});

    // Top plane
    mVertices.push_back(Vertex{-x, y, -z, r, g, b});   // 11th
    mVertices.push_back(Vertex{x, y, -z, r, g, b});
    mVertices.push_back(Vertex{x, y, z, r, g, b});
    mVertices.push_back(Vertex{x, y, z, r, g, b});   //12th
    mVertices.push_back(Vertex{-x, y, z, r, g, b});
    mVertices.push_back(Vertex{-x, y, -z, r, g, b});

    //mMatrix.rotate(-1 , 0, 1, 0);
    //mMatrix.translate(0, 90, 0);
    //mMatrix.rotate(180, 0, 1, 0);
    //setRotation(180, 0, 1, 0);

    mMatrix.setToIdentity();

}

house::~house()
{

}

void house::init(GLint matrixUniform)
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

void house::draw()
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

void house::move(float dx, float dy, float dz)
{
    mMatrix.translate(dx, dy, dz);
}
