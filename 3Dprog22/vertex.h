// 3D-programmering 2022
#ifndef VERTEX_H
#define VERTEX_H
#include <fstream>
#include <qvector3d.h>

class Vertex {
   //! Overloaded ostream operator which writes all vertex data on an open textfile stream
   friend std::ostream& operator<< (std::ostream&, const Vertex&);

   //! Overloaded ostream operator which reads all vertex data from an open textfile stream
   friend std::istream& operator>> (std::istream&, Vertex&);

public:
   float m_xyz[3];       	// position i 3D
   float m_normal[3];    // normal in 3D or rgb colors
   float m_st[2];        	// texture coordinates if used
   float m_colour[3]; //in heightmap Vertex, we use this one for colour and m_normal for normals. sorry

public:
   Vertex();
   Vertex(float x, float y, float z);
   Vertex(float x, float y, float z, float r, float g, float b);
   Vertex(float x, float y, float z, float r, float g, float b, float u, float v);
   Vertex(QVector3D position, QVector3D colour, QVector2D uv, QVector3D normal);
   Vertex(float x, float y, float z, float r, float g, float b, float u, float v, float n1, float n2, float n3);
};


#endif // VERTEX_H
