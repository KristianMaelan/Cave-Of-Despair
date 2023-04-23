#include "heightmap.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

heightmap::heightmap()
{

}

heightmap::heightmap(const char *imgPath)
{
    int width, height, channels;
    unsigned char* data = stbi_load(imgPath, &width, &height, &channels, 1);

    // Legge til i constructor?
    float heightMultiplier{-0.2};
    // endre?
    int vert{}; // run through image data array

    for (float x = -width / 2; x < (width / 2); x ++)
    {
        for (float z  = -height / 2; z < (height / 2); z ++)
        {
            float y = (float)data[vert] * heightMultiplier;
            mVertices.push_back(Vertex{x, y, z});

            y = (float)data[vert + width] * heightMultiplier;
            mVertices.push_back(Vertex{x + 1.0f, y, z});

            y = (float)data[vert + 1] * heightMultiplier;
            mVertices.push_back(Vertex{x, y, z + 1.0f});
            mVertices.push_back(Vertex{x, y, z + 1.0f});

            y = (float)data[vert + width] * heightMultiplier;
            mVertices.push_back(Vertex{x + 1.0f, y, z});

            y = (float)data[vert + width + 1] * heightMultiplier;
            mVertices.push_back(Vertex{x + 1.0f, y, z + 1.0f});

            vert++;
        }
    }

    stbi_image_free(data);
}

heightmap::heightmap(const char *imgPath, float r, float g, float b, bool yes)
{
    int width, height, channels;
    unsigned char* data = stbi_load(imgPath, &width, &height, &channels, 1);

    // Legge til i constructor?
    float heightMultiplier{-0.2};
    // endre?
    int vert{}; // run through image data array



    for (float x = -width / 2; x < (width / 2); x ++)
    {
        for (float z  = -height / 2; z < (height / 2); z ++)
        {
            QVector3D vec1,  vec2,  vec3,  vec4,   vec5,  vec6;
            float y = (float)data[vert] * heightMultiplier;
            vec1.setX(x);
            vec1.setY(y);
            vec1.setZ(z);
            //mVertices.push_back(Vertex{x, y, z, r, g, b, 0, 0});

            y = (float)data[vert + width] * heightMultiplier;
            //mVertices.push_back(Vertex{x + 1.0f, y, z, r, g, b, 1, 0});
            vec2.setX(x);
            vec2.setY(y);
            vec2.setZ(z);

            y = (float)data[vert + 1] * heightMultiplier;
            //mVertices.push_back(Vertex{x, y, z + 1.0f, r, g, b, 1, 1});
            vec3.setX(x);
            vec3.setY(y);
            vec3.setZ(z);
            //mVertices.push_back(Vertex{x, y, z + 1.0f, r, g, b, 1, 1});
            vec4.setX(x);
            vec4.setY(y);
            vec4.setZ(z);

            y = (float)data[vert + width] * heightMultiplier;
            //mVertices.push_back(Vertex{x + 1.0f, y, z, r, g, b, 0, 1});
            vec5.setX(x);
            vec5.setY(y);
            vec5.setZ(z);

            y = (float)data[vert + width + 1] * heightMultiplier;
            //mVertices.push_back(Vertex{x + 1.0f, y, z + 1.0f, r, g, b, 0, 0});
            vec6.setX(x);
            vec6.setY(y);
            vec6.setZ(z);

            QVector3D hoyreBein, venstreBein;
            QVector3D normal1, normal2, normal3, normal4, normal5, normal6;

            hoyreBein = vec2 - vec1;
            venstreBein = vec3 - vec1;
            normal1 = getNormal(hoyreBein, venstreBein);
            mVertices.push_back(Vertex{vec1.x(), vec1.y(), vec1.z(), r, g, b, 0, 0, normal1.x(), normal1.y(), normal1.z()});
            //mVertices.push_back(Vertex{vec1, QVector3D(r, g, b), QVector2D(0, 0), normal1} );

            hoyreBein = vec3 - vec2;
            venstreBein = vec1 - vec2;
            normal2 = getNormal(hoyreBein, venstreBein);
            mVertices.push_back(Vertex{vec2.x() + 1.0f, vec2.y(), vec2.z(), r, g, b, 1, 0, normal2.x(), normal2.y(), normal2.z()});
            //mVertices.push_back(Vertex{vec2, QVector3D(r, g, b), QVector2D(0, 0), normal2} );

            hoyreBein = vec1 - vec3;
            venstreBein = vec2 - vec3;
            normal3 = getNormal(hoyreBein, venstreBein);
            mVertices.push_back(Vertex{vec3.x(), vec3.y(), vec3.z() + 1.0f, r, g, b, 1, 1, normal3.x(), normal3.y(), normal3.z()});
            //mVertices.push_back(Vertex{vec3, QVector3D(r, g, b), QVector2D(0, 0), normal3} );

            /*
            hoyreBein = vec6 - vec4;
            venstreBein = vec5 - vec4;
            normal4 = getNormal(hoyreBein, venstreBein);
            mVertices.push_back(Vertex{vec4.x(), vec4.y(), vec4.z() + 1.0f, r, g, b, 1, 1, normal4.x(), normal4.y(), normal4.z()});
            //mVertices.push_back(Vertex{vec4, QVector3D(r, g, b), QVector2D(0, 0), normal4} );

            hoyreBein = vec4 - vec5;
            venstreBein = vec6 - vec5;
            normal5 = getNormal(hoyreBein, venstreBein);
            mVertices.push_back(Vertex{vec5.x() + 1.0f, vec5.y(), vec5.z(), r, g, b, 0, 1, normal5.x(), normal5.y(), normal5.z()});
           // mVertices.push_back(Vertex{vec5, QVector3D(r, g, b), QVector2D(0, 0), normal5} );

            hoyreBein = vec5 - vec6;
            venstreBein = vec4 - vec6;
            normal6 = getNormal(hoyreBein, venstreBein);
            mVertices.push_back(Vertex{vec6.x() + 1.0f, vec6.y(), vec6.z() + 1.0f, r, g, b, 0, 0, normal6.x(), normal6.y(), normal6.z()});
            //mVertices.push_back(Vertex{vec6, QVector3D(r, g, b), QVector2D(0, 0), normal6} );
*/
            vert++;
        }
    }

    stbi_image_free(data);
}

heightmap::heightmap(const char* imgPath, float r, float g, float b)
{
    int width, height, channels;
    unsigned char* data = stbi_load(imgPath, &width, &height, &channels, 1);

    // Legge til i constructor?
    float heightMultiplier{-0.2};
    // endre?
    int vert{}; // run through image data array

    QVector3D vec1, v1, vec2, v2, vec3, v3;

    for (float x = -width / 2; x < (width / 2); x ++)
    {
        for (float z  = -height / 2; z < (height / 2); z ++)
        {
            float y = (float)data[vert] * heightMultiplier;
            mVertices.push_back(Vertex{x, y, z, r, g, b, 0, 0});

            y = (float)data[vert + width] * heightMultiplier;
            mVertices.push_back(Vertex{x + 1.0f, y, z, r, g, b, 1, 0});

            y = (float)data[vert + 1] * heightMultiplier;
            mVertices.push_back(Vertex{x, y, z + 1.0f, r, g, b, 1, 1});
            mVertices.push_back(Vertex{x, y, z + 1.0f, r, g, b, 1, 1});

            y = (float)data[vert + width] * heightMultiplier;
            mVertices.push_back(Vertex{x + 1.0f, y, z, r, g, b, 0, 1});

            y = (float)data[vert + width + 1] * heightMultiplier;
            mVertices.push_back(Vertex{x + 1.0f, y, z + 1.0f, r, g, b, 0, 0});

            vert++;
        }
    }

    stbi_image_free(data);
}

heightmap::~heightmap()
{

}

void heightmap::init(GLint matrixUniform)
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

    glBindVertexArray(0);
}

void heightmap::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData()); // can this be used for the shaders?

//    if (bWireframe)
//    {
//        glDrawArrays(GL_LINES, 0, mVertices.size());
//    }
//    else
//    {
//        glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
//    }

    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
    glBindVertexArray(0);
}

float heightmap::getTerrainHeight(const QVector2D pointInSpace)
{
    QVector3D v1{}, v2{}, v3{};
    QVector3D barycentric{-1.f, -1.f, -1.f};

    for (size_t i = 0; i < mVertices.size() - 2; i += 3)
    {
        v1 = QVector3D(mVertices[i].m_xyz[0], mVertices[i].m_xyz[1], mVertices[i].m_xyz[2]);
        v2 = QVector3D(mVertices[i + 1].m_xyz[0], mVertices[i + 1].m_xyz[1], mVertices[i + 1].m_xyz[2]);
        v3 = QVector3D(mVertices[i + 2].m_xyz[0], mVertices[i + 2].m_xyz[1], mVertices[i + 2].m_xyz[2]);

        barycentric = getBary(QVector2D(v1.x(), v1.z()), QVector2D(v2.x(), v2.z()), QVector2D(v3.x(), v3.z()), pointInSpace);

        if (barycentric.x() >= 0 && barycentric.y() >= 0 && barycentric.z() >= 0)
        {
            break;
        }
    }

    float height = v1.y() * barycentric.x() + v2.y() * barycentric.y() + v3.y() * barycentric.z();

    return height;
}

QVector3D heightmap::getBary(const QVector2D &a, const QVector2D &b, const QVector2D &c, const QVector2D &x)
{
    QVector2D v0 = b - a;
    QVector2D v1 = c - a;
    QVector2D v2 = x - a;

    float d00 = QVector2D::dotProduct(v0, v0);
    float d01 = QVector2D::dotProduct(v0, v1);
    float d11 = QVector2D::dotProduct(v1, v1);
    float d20 = QVector2D::dotProduct(v2, v0);
    float d21 = QVector2D::dotProduct(v2, v1);
    float denom = d00 * d11 - d01 * d01;

    float v = (d11 * d20 - d01 * d21) / denom;
    float w = (d00 * d21 - d01 * d20) / denom;
    float u = (1.0f - v - w);

    QVector3D barycentric3D = QVector3D(u, v, w);

    return barycentric3D;
}

QVector3D heightmap::getNormal(QVector3D hb, QVector3D vb)
{
    hb.normalize();
    vb.normalize();
    return QVector3D::crossProduct(hb, vb);

}
