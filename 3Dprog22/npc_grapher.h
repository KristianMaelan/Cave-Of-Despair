#ifndef NPC_GRAPHER_H
#define NPC_GRAPHER_H

#include "cube.h"
#include "eigen-3.4.0/Eigen/Dense"
#include "math.h"

class NPC_grapher : public Cube
{
public:
    NPC_grapher();
    NPC_grapher(float x, float y, float z);


    void init(GLint matrixUniform) override;
    void draw() override;

    bool b_showGraph{true}; //should be false when done, so we can add npc and graphs when we wish
    bool b_showGraph_2{false}; // false show graph1, true show graph2

    // calculate graph
    float x;

    // matrices for graph1
    bool b_shouldWeIncreaseX{true};
    Eigen::MatrixXf matrix_graph1 {
        {1,5},
        {2,2},
        {3,5},
        {4,7}
    };
    Eigen::MatrixXf matrix_1_A  {
        {1, 1, 1, 1},
        {8, 4, 2, 1},
        {27, 9, 3, 1},
        {64, 16, 4, 1}
    };
    Eigen::MatrixXf matrix_1_Y  {
        {5},
        {2},
        {5},
        {7}
    };
    Eigen::MatrixXf matrix_1_X;

    float x0_1 = 1;
    float xn_1 = 4;
    float a_1;
    float b_1;
    float c_1;
    float d_1;

    // matrices for graph2
    Eigen::MatrixXf matrix_graph2   {
        {-1,4},
        {6,2},
        {5,3},
        {7,1}
    };
    Eigen::MatrixXf matrix_2_A  {
        {-1, 1, -1, 1},
        {216, 36, 6, 1},
        {125, 25, 5, 1},
        {343, 49, 7, 1}
    };
    Eigen::MatrixXf matrix_2_Y {
        {4},
        {2},
        {3},
        {1}
    };
    Eigen::MatrixXf matrix_2_X;

    float x0_2 = -1;
    float xn_2 = 7;
    float a_2;
    float b_2;
    float c_2;
    float d_2;

    // calculate a/b/c/d values
    void calculateGraphFunction();
    // move NPC
    void functionMove();
    void move(float dx, float dy, float dz) override;
    //  new positions
    float Coordinate_X;
    float Coordinate_Y;
    float Coordinate_Z;

};

#endif // NPC_GRAPHER_H
