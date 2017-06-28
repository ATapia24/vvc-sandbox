#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <fstream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

class Cube {
    public:
        Cube();
        ~Cube();
        glm::mat4 getModelViewProjection(glm::mat4 projection, glm::mat4 camera);
        glm::mat4 getTransform() const;
        int getN_Vertices() const;

    private:
        glm::mat4 transformMat, mvpMat;
        const int N_VERTICES = 36;
};