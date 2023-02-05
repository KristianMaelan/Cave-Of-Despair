#include "cube.h"
#include "qevent.h"

#include <iostream>

Cube::Cube()
{
    // Joakim - Test3_Fungerer

    float x = 1.0f, y = 1.0f, z = 1.0f, r = 1.0f, g = 0.0f, b = 0.0f;
    // Front plane
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});   // 1st
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{x, y, -z, r, g, b});
    mVertices.push_back(Vertex{x, y, -z, r, g, b});     // 2nd
    mVertices.push_back(Vertex{-x, y, -z, r, g, b});
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});

    // Back plane
    mVertices.push_back(Vertex{-x, -y, z, r, g, b});    // 3rd
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{x, y, z, r, g, b});
    mVertices.push_back(Vertex{x, y, z, r, g, b});      // 4th
    mVertices.push_back(Vertex{-x, y, z, r, g, b});
    mVertices.push_back(Vertex{-x, -y, z, r, g, b});

    // Left plane
    mVertices.push_back(Vertex{-x, y, z, r, g, b});     // 5th
    mVertices.push_back(Vertex{-x, y, -z, r, g, b});
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});   // 6th
    mVertices.push_back(Vertex{-x, -y, z, r, g, b});
    mVertices.push_back(Vertex{-x, y, z, r, g, b});

    // Right plane
    mVertices.push_back(Vertex{x, y, z, r, g, b});      // 7th
    mVertices.push_back(Vertex{x, y, -z, r, g, b});
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});    // 8th
    mVertices.push_back(Vertex{x, -y, z, r, g, b});
    mVertices.push_back(Vertex{x, y, z, r, g, b});

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


    mMatrix.setToIdentity();

    //qDebug() << "Reee";

}

Cube::Cube(float x, float y, float z, float r, float g,float b)
{
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});   // 1st
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{x, y, -z, r, g, b});
    mVertices.push_back(Vertex{x, y, -z, r, g, b});     // 2nd
    mVertices.push_back(Vertex{-x, y, -z, r, g, b});
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});

    // Back plane
    mVertices.push_back(Vertex{-x, -y, z, r, g, b});    // 3rd
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{x, y, z, r, g, b});
    mVertices.push_back(Vertex{x, y, z, r, g, b});      // 4th
    mVertices.push_back(Vertex{-x, y, z, r, g, b});
    mVertices.push_back(Vertex{-x, -y, z, r, g, b});

    // Left plane
    mVertices.push_back(Vertex{-x, y, z, r, g, b});     // 5th
    mVertices.push_back(Vertex{-x, y, -z, r, g, b});
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{-x, -y, -z, r, g, b});   // 6th
    mVertices.push_back(Vertex{-x, -y, z, r, g, b});
    mVertices.push_back(Vertex{-x, y, z, r, g, b});

    // Right plane
    mVertices.push_back(Vertex{x, y, z, r, g, b});      // 7th
    mVertices.push_back(Vertex{x, y, -z, r, g, b});
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});
    mVertices.push_back(Vertex{x, -y, -z, r, g, b});    // 8th
    mVertices.push_back(Vertex{x, -y, z, r, g, b});
    mVertices.push_back(Vertex{x, y, z, r, g, b});

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


    mMatrix.setToIdentity();

}


Cube::~Cube()
{

}

void Cube::rotation(QKeyEvent *event)
{
    qDebug() << "rotation called";
    //const float rSpeed = 10.0f;
    if (event->key() == Qt::Key_Comma)
    {
        //mMatrix.rotate(-1, 1, 0, 0);
        mMatrix.translate(-1.0f, 1.0f, 0.0f);
        qDebug() << "comma pressed";
    }


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
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());

    // Konstant rotasjon av kuben.
    //mMatrix.rotate(-1, 1, 0, 0);
}

void Cube::move(float dx, float dy, float dz)
{
    mx += dx;
    my += dy;
    mz += dz;

    mMatrix.translate(mx, my, mz);
}


