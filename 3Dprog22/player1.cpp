#include "player1.h"

Player1::Player1(){

}


Player1::Player1(float x, float y, float z, float r, float g, float b)
{
//x = 0.5 * x;
//y = 0.5 * y;
//z = 0.5 * z;

    { //Cubemode
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

    }

    {
//    mVertices.push_back(Vertex{-x, -y, -z, r, g, b, 0*u, 0*v});   // 1st
//    mVertices.push_back(Vertex{x, -y, -z, r, g, b, 1*u, 0*v});
//    mVertices.push_back(Vertex{x, y, -z, r, g, b, 1*u, 1*v});
//    mVertices.push_back(Vertex{x, y, -z, r, g, b, 1*u, 1*v});     // 2nd
//    mVertices.push_back(Vertex{-x, y, -z, r, g, b, 0*u, 1*v});
//    mVertices.push_back(Vertex{-x, -y, -z, r, g, b, 0*u, 0*v});

//    // Back plane
//    mVertices.push_back(Vertex{-x, -y, z, r, g, b, 0*u, 0*v});    // 3rd
//    mVertices.push_back(Vertex{x, -y, z, r, g, b, 1*u, 0*v});
//    mVertices.push_back(Vertex{x, y, z, r, g, b, 1*u, 1*v});
//    mVertices.push_back(Vertex{x, y, z, r, g, b, 1*u, 1*v});      // 4th
//    mVertices.push_back(Vertex{-x, y, z, r, g, b, 0*u, 1*v});
//    mVertices.push_back(Vertex{-x, -y, z, r, g, b, 0*u, 0*v});

//    // Left plane
//    mVertices.push_back(Vertex{-x, y, z, r, g, b, 0*u, 0*v});     // 5th
//    mVertices.push_back(Vertex{-x, y, -z, r, g, b, 1*u, 0*v});
//    mVertices.push_back(Vertex{-x, -y, -z, r, g, b, 1*u, 1*v});
//    mVertices.push_back(Vertex{-x, -y, -z, r, g, b, 1*u, 1*v});   // 6th
//    mVertices.push_back(Vertex{-x, -y, z, r, g, b, 0*u, 1*v});
//    mVertices.push_back(Vertex{-x, y, z, r, g, b, 0*u, 0*v});

//    // Right plane
//    mVertices.push_back(Vertex{x, y, z, r, g, b, 0*u, 0*v});      // 7th
//    mVertices.push_back(Vertex{x, y, -z, r, g, b, 1*u, 0*v});
//    mVertices.push_back(Vertex{x, -y, -z, r, g, b, 1*u, 1*v});
//    mVertices.push_back(Vertex{x, -y, -z, r, g, b, 1*u, 1*v});    // 8th
//    mVertices.push_back(Vertex{x, -y, z, r, g, b, 0*u, 1*v});
//    mVertices.push_back(Vertex{x, y, z, r, g, b, 0*u, 0*v});

//    // Bottom plane
//    mVertices.push_back(Vertex{-x, -y, -z, r, g, b, 0*u, 0*v});   // 9th
//    mVertices.push_back(Vertex{x, -y, -z, r, g, b, 1*u, 0*v});
//    mVertices.push_back(Vertex{x, -y, z, r, g, b, 1*u, 1*v});
//    mVertices.push_back(Vertex{x, -y, z, r, g, b, 1*u, 1*v});     // 10th
//    mVertices.push_back(Vertex{-x, -y, z, r, g, b, 0*u, 1*v});
//    mVertices.push_back(Vertex{-x, -y, -z, r, g, b, 0*u, 0*v});

//    // Top plane
//    mVertices.push_back(Vertex{-x, y, -z, r, g, b, 0*u, 0*v});   // 11th
//    mVertices.push_back(Vertex{x, y, -z, r, g, b, 1*u, 0*v});
//    mVertices.push_back(Vertex{x, y, z, r, g, b, 1*u, 1*v});
//    mVertices.push_back(Vertex{x, y, z, r, g, b, 1*u, 1*v});   //12th
//    mVertices.push_back(Vertex{-x, y, z, r, g, b, 0*u, 1*v});
//    mVertices.push_back(Vertex{-x, y, -z, r, g, b, 0*u, 0*v});
}

    mMatrix.setToIdentity();

}

Player1::~Player1(){


}

void Player1::init(GLint matrixUniform){
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

    if (bRunTexture)
    {
    QOpenGLTexture* textureCube;

    QImage image;
    //image.load("../3Dprog22/Wonky.bmp");
    image.load("../3Dprog22/Shaggy.jpg");
    textureCube = new QOpenGLTexture(QOpenGLTexture::Target2D);
    textureCube->setData(image);
    textureCube->setWrapMode(QOpenGLTexture::Repeat);
    textureCube->setMinificationFilter(QOpenGLTexture::Nearest);
    textureCube->setMagnificationFilter(QOpenGLTexture::Nearest);
    textureCube->bind(1);
    }


}

void Player1::draw(){

    if(checkScene1)
    {
//        glBindVertexArray( mVAO );
//        glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData()); // can this be used for the shaders?
//        glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
//        glBindVertexArray(0);


    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
       }
}

void Player1::move(float dx, float dy, float dz){

    mMatrix.translate(dx, dy, dz);
    Coordinate_X = dx;
    Coordinate_Y = dy;
    Coordinate_Z = dz;
}
