// 3D-programmering 2022
#include "vertex.h"
#include <fstream>
Vertex::Vertex()
{


}
Vertex::Vertex(float x, float y, float z)
{
    m_xyz[0] = x; m_xyz[1] = y; m_xyz[2] = z;
}
Vertex::Vertex(float x, float y, float z, float r, float g, float b)
{
    m_xyz[0] = x; m_xyz[1] = y; m_xyz[2] = z;
    m_normal[0] = r; m_normal[1] = g; m_normal[2] = b;
    m_st[0] = 0.0; m_st[1] = 1.0;
}
Vertex::Vertex(float x, float y, float z, float r, float g, float b, float u, float v)
{
    m_xyz[0] = x; m_xyz[1] = y; m_xyz[2] = z;
    m_normal[0] = r; m_normal[1] = g; m_normal[2] = b;
    m_st[0] = u; m_st[1] = v;
}

Vertex::Vertex(QVector3D position, QVector3D colour, QVector2D uv, QVector3D normal)
{
    m_xyz[0] = position.x(); m_xyz[1] = position.y(); m_xyz[2] = position.z();
    m_colour[0] = colour.x(); m_colour[1] = colour.y(); m_colour[2] = colour.z();
    m_st[0] = uv.x(); m_st[1] = uv.y();
    m_normal[0] = normal.x(); m_normal[1] = normal.y(); m_normal[2] = normal.z();
}

Vertex::Vertex(float x, float y, float z, float r, float g, float b, float u, float v, float n1, float n2, float n3)
{
    m_xyz[0] = x; m_xyz[1] = y; m_xyz[2] = z;
   m_colour[0] = r; m_colour[1] = g; m_colour[2] = b;
    m_st[0] = u; m_st[1] = v;
    m_normal[0] = n1; m_normal[1] = n2; m_normal[2] = n3;

}

std::ostream& operator<< (std::ostream& os, const Vertex& v) {
  os << std::fixed;
  os << "(" << v.m_xyz[0] << ", " << v.m_xyz[1] << ", " << v.m_xyz[2] << ") ";
  os << "(" << v.m_normal[0] << ", " << v.m_normal[1] << ", " << v.m_normal[2] << ") ";
  os << "(" << v.m_st[0] << ", " << v.m_st[1] << ") ";
  return os;
}
std::istream& operator>> (std::istream& is, Vertex& v) {
// Trenger fire temporære variabler som kun skal lese inn parenteser og komma
  char dum, dum2, dum3, dum4;
  is >> dum >> v.m_xyz[0] >> dum2 >> v.m_xyz[1] >> dum3 >> v.m_xyz[2] >> dum4;
  is >> dum >> v.m_normal[0] >> dum2 >> v.m_normal[1] >> dum3 >> v.m_normal[2] >> dum4;
  is >> dum >> v.m_st[0] >> dum2 >> v.m_st[1] >> dum3;
  return is;
}
