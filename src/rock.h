#include "main.h"

// #ifndef Rock_H
// #define Rock_H


class Rock {
public:
    Rock() {}
    Rock(float x, float y, float z, float sizeOfRock, color_t color);
    glm::vec3 position;
    float rotation;
    float sizeOfRock;
    void draw(glm::mat4 VP);
    void set_position(float x,float y, float z);
    void tick();
private:
    VAO *object;
};

Rock::Rock(float x, float y, float z, float sizeOfRock, color_t color) {
    this->position = glm::vec3(x,y, z);
    this->rotation = 0;
    this->sizeOfRock = sizeOfRock;
    
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        -this->sizeOfRock/2,-1.0f,-this->sizeOfRock/2, // triangle 1 : begin
        -this->sizeOfRock/2,-1.0f, this->sizeOfRock/2,
        -0.05, this->sizeOfRock/1.5, 0.05, // triangle 1 : end
         0.05, this->sizeOfRock/1.5,-0.05, // triangle 2 : begin
        -this->sizeOfRock/2,-1.0f,-this->sizeOfRock/2,
        -0.05, this->sizeOfRock/1.5,-0.05, // triangle 2 : end
         this->sizeOfRock/2,-1.0f, this->sizeOfRock/2,
        -this->sizeOfRock/2,-1.0f,-this->sizeOfRock/2,
         this->sizeOfRock/2,-1.0f,-this->sizeOfRock/2,
         0.05, this->sizeOfRock/1.5,-0.05,
         this->sizeOfRock/2,-1.0f,-this->sizeOfRock/2,
        -this->sizeOfRock/2,-1.0f,-this->sizeOfRock/2,
        -this->sizeOfRock/2,-1.0f,-this->sizeOfRock/2,
        -0.05, this->sizeOfRock/1.5, 0.05,
        -0.05, this->sizeOfRock/1.5,-0.05,
         this->sizeOfRock/2,-1.0f, this->sizeOfRock/2,
        -this->sizeOfRock/2,-1.0f, this->sizeOfRock/2,
        -this->sizeOfRock/2,-1.0f,-this->sizeOfRock/2,
        -0.05, this->sizeOfRock/1.5, 0.05,
        -this->sizeOfRock/2,-1.0f, this->sizeOfRock/2,
         this->sizeOfRock/2,-1.0f, this->sizeOfRock/2,
         0.05, this->sizeOfRock/1.5, 0.05,
         this->sizeOfRock/2,-1.0f,-this->sizeOfRock/2,
         0.05, this->sizeOfRock/1.5,-0.05,
         this->sizeOfRock/2,-1.0f,-this->sizeOfRock/2,
         0.05, this->sizeOfRock/1.5, 0.05,
         this->sizeOfRock/2,-1.0f, this->sizeOfRock/2,
         0.05, this->sizeOfRock/1.5, 0.05,
         0.05, this->sizeOfRock/1.5,-0.05,
        -0.05, this->sizeOfRock/1.5,-0.05,
         0.05, this->sizeOfRock/1.5, 0.05,
        -0.05, this->sizeOfRock/1.5,-0.05,
        -0.05, this->sizeOfRock/1.5, 0.05,
         0.05, this->sizeOfRock/1.5, 0.05,
        -0.05, this->sizeOfRock/1.5, 0.05,
         this->sizeOfRock/2,-1.0f, this->sizeOfRock/2
    };

    this->object = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, color, GL_FILL);
}


void Rock::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0,1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    //rotate          = rotate * glm::translate(glm::vec3(0, -3, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Rock::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Rock::tick() {
    //this->rotation += speed;
    // this->position.x += this->speed;
    // this->position.z += 0.0005;
    // // this->position.y -= speed;
}
