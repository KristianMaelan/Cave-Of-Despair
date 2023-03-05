#include "npc_grapher.h"
#include "iostream"
NPC_grapher::NPC_grapher()
{

}

{
    // graph 1
    // (1,5), (2,2), (3,5), (4,7)
    // graph 2
    // (-1,4), (6,2), (5,3), (7,1)

    Coordinate_X = xv;
    Coordinate_Y = yv;
    Coordinate_Z = zv;

    x = Coordinate_X;

    calculateGraphFunction();
    mMatrix.setToIdentity();

}

void NPC_grapher::init(GLint matrixUniform)
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

void NPC_grapher::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
    //update position

}

void NPC_grapher::calculateGraphFunction()
{
    // graph 1
    Eigen::MatrixXf matrix_A1inv = matrix_1_A.inverse();
    matrix_1_X = matrix_A1inv * matrix_1_Y;
    // graph 2
    Eigen::MatrixXf matrix_A2inv = matrix_2_A.inverse();
    matrix_2_X = matrix_A2inv * matrix_2_Y;
}

void NPC_grapher::functionMove()
{
    // check which graph, if we are using a graph, that should be used (a/b/c/d values) at the same time, define x0/xn values to use
    if (b_showGraph_2 == false)
    {
        // we are using graph 1
        a_1 = matrix_1_X(0);
        b_1 = matrix_1_X(1);
        c_1 = matrix_1_X(2);
        d_1 = matrix_1_X(3);

        // move this to render window? how is interactive cube moved?
     if (x <= x0_1)
     {
        x = x0_1;
        b_shouldWeIncreaseX = true;
        float y = a_1 * (x * x * x) + b_1 * (x * x) + c_1 * x + d_1;
        std::cout << x << ", " << y << '\n';
       // move(x, y, 0);
        x += 0.1;
        //move(x, y, 0);
        x += 0.01;
     }
     else if (x >= xn_1)
     {
        x = xn_1;
        b_shouldWeIncreaseX = false;
        float y = a_1 * (x * x * x) + b_1 * (x * x) + c_1 * x + d_1;
        std::cout << x << ", " << y << '\n';
       // move(x, y, 0);
        x -= 0.1;
     }
     else if (x0_1 < x && xn_1 > x)
     {
        float y = a_1 * (x * x * x) + b_1 * (x * x) + c_1 * x + d_1;
        std::cout << x << ", " << y << '\n';
       // move(x, y, 0);
        if (b_shouldWeIncreaseX)
        {
            x += 0.01;
        }
        else
        {
            x -= 0.01;
        }
     }

    }
    else if (b_showGraph_2 == true)
    {
        // we are using graph 2

        a_2 = matrix_2_X(0);
        b_2 = matrix_2_X(1);
        c_2 = matrix_2_X(2);
        d_2 = matrix_2_X(3);
        if (x <= x0_2)
        {
           x = x0_2;
           b_shouldWeIncreaseX = true;
           float y = a_2 * (x * x * x) + b_2 * (x * x) + c_2 * x + d_2;
           std::cout << x << ", " << y << '\n';
         //  move(x, y, 0);
           x += 0.1;
        }
        else if (x >= xn_2)
        {
           x = xn_1;
           b_shouldWeIncreaseX = false;
           float y = a_2 * (x * x * x) + b_2 * (x * x) + c_2 * x + d_2;
           std::cout << x << ", " << y << '\n';
          // move(x, y, 0);
           x -= 0.1;
        }
        else if (x0_2 < x && xn_2 > x)
        {
           float y = a_2 * (x * x * x) + b_2 * (x * x) + c_2 * x + d_2;
           std::cout << x << ", " << y << '\n';
          // move(x, y, 0);
           if (b_shouldWeIncreaseX)
           {
               x += 0.1;
           }
           else
           {
               x -= 0.1;
           }
        }
    }
}

void NPC_grapher::move(float dx, float dy, float dz)
{
    mMatrix.translate(dx, dy, dz);
    Coordinate_X = dx;
    Coordinate_Y = dy;
    Coordinate_Z = dz;
}

