#include "Cube.h"

Cube::Cube() {
    transformMat = glm::mat4(1.0f);
}

Cube::~Cube() {

}


//GET MODEL VIEW PROJECTION
glm::mat4 Cube::getModelViewProjection(glm::mat4 projection, glm::mat4 camera) {
    mvpMat = projection * camera * transformMat;
    return mvpMat;
}

//GET TRANSFORM
glm::mat4 Cube::getTransform() const {
    return transformMat;
}

//GET NUMBER OF VERTICES
int Cube::getN_Vertices() const {
    return N_VERTICES;
}