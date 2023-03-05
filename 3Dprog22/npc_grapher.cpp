#include "npc_grapher.h"
#include "iostream"
NPC_grapher::NPC_grapher()
{

}

NPC_grapher::NPC_grapher(float x, float y, float z) : Cube (x, y, z, 1, 0.46, 0.0)
{
    // graph 1
    // (1,5), (2,2), (3,5), (4,7)
/*
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (i == 0)
            {
                matrix_1_A(i,j) = pow(matrix_graph1(i,0), 3);
            }
            else if (i == 1)
            {
                matrix_1_A(i,j) = pow(matrix_graph1(i,0), 2);
            }
            else if (i == 2)
            {
                matrix_1_A(i,j) = pow(matrix_graph1(i,0), 1);
            }
            else if (i == 3)
            {
                matrix_1_A(i,j) = 1;
            }
            else if (i == 4)
            {
                matrix_1_Y(i) = matrix_graph1(i,1);
            }
        }
    }
    // print
    std::cout << "matrix_1_A\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << matrix_1_A(i, j) << ", ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
*/
    // graph 2
    // (-1,4), (6,2), (5,3), (7,1)
/*
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (i == 0)
            {
                matrix_2_A(i,j) = pow(matrix_graph2(i,0), 3);
            }
            else if (i == 1)
            {
                matrix_2_A(i,j) = pow(matrix_graph2(i,0), 2);
            }
            else if (i == 2)
            {
                matrix_2_A(i,j) = pow(matrix_graph2(i,0), 1);
            }
            else if (i == 3)
            {
                matrix_2_A(i,j) = 1;
            }
            else if (i == 4)
            {
                matrix_2_Y(i) = matrix_graph2(i,1);
            }
        }
    }
    // print
    std::cout << "matrix_2_A\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << matrix_2_A(i, j) << ", ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
*/
    calculateGraphFunction();

}
{

}

NPC_grapher::~NPC_grapher(){   }

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
}

void NPC_grapher::calculateGraphFunction()
{
    // graph 1
    Eigen::MatrixXf matrix_A1inv = matrix_1_A.inverse();
    matrix_1_X = matrix_A1inv * matrix_1_Y;
    // graph 2
    Eigen::MatrixXf matrix_A2inv = matrix_2_A.inverse();
    matrix_2_X = matrix_A2inv * matrix_2_Y;

    // print
    std::cout << "matrix_A1inv\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << matrix_A1inv(i, j) << ", ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void NPC_grapher::functionMove()
{
    // check which graph, if we are using a graph, that should be used (a/b/c/d values) at the same time, define x0/xn values to use
    if (b_showGraph_2 == false)
    {
        // we are using graph 1
        float x0 = 1;
        float xn = 4;
        float a = matrix_1_X(0);
        float b = matrix_1_X(1);
        float c = matrix_1_X(2);
        float d = matrix_1_X(3);

        // move this to render window? how is interactive cube moved?
        for (float x = x0; x < xn; ++x) {

            float y = a * (x * x * x) + b * (x * x) + c * x + d;

            move(x, y, 0);
        }
    }
    else if (b_showGraph_2 == true)
    {
        // we are using graph 2
        float x0 = -1;
        float xn = 7;
        float a = matrix_2_X(0);
        float b = matrix_2_X(1);
        float c = matrix_2_X(2);
        float d = matrix_2_X(3);
        for (float x = xn; x > x0; --x) {

            float y = a * (x * x * x) + b * (x * x) + c * x + d;

            move(x, y, 0);
        }
    }
}

void NPC_grapher::move(float dx, float dy, float dz)
{
    mMatrix.translate(dx, dy, dz);
}

