#include "main.h"

class Booster {
public:
    Booster() {}
    Booster(float x, float y, float z, int flag);
    glm::vec3 position;
    float rotation;
    int flag;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick(glm::vec3);
private:
    VAO *object;
    VAO *object2;
};

Booster::Booster(float x, float y, float z, int flag) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->flag = flag;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    if(this->flag)
    {
        static const GLfloat vertex_buffer_data1[] = {
            -1.9, 2.0, 0.05,
             1.9, 2.0, 0.05,
             0.0, 4.00,0.05,
            -1.9, 2.0, 0.05,
             1.9, 2.0, 0.05,
             0.0, 0.10,0.05,
            -1.9, 2.0, 0.15,
             1.9, 2.0, 0.15,
             0.0, 4.00,0.15,
            -1.9, 2.0, 0.15,
             1.9, 2.0, 0.15,
             0.0, 0.10,0.15,
            -1.9, 2.0, 0.05,  //
             0.0, 4.00,0.05,
             0.0, 4.00,0.15,
             0.0, 4.00,0.15,
            -1.9, 4.00,0.15,
            -1.9, 2.0, 0.05,
             1.9, 2.0, 0.05,  //
             0.0, 4.00,0.05,
             0.0, 4.00,0.15,
             0.0, 4.00,0.15,
             1.9, 4.00,0.15,
             1.9, 2.0, 0.05,
            -1.9, 2.0, 0.05,  //
             0.0, 0.10,0.05,
             0.0, 0.10,0.15,
             0.0, 0.10,0.15,
            -1.9, 0.10,0.15,
            -1.9, 2.0, 0.05,
             1.9, 2.0, 0.05,  //
             0.0, 0.10,0.05,
             0.0, 0.10,0.15,
             0.0, 0.10,0.15,
             1.9, 0.10,0.15,
             1.9, 2.0, 0.05,


        }; 

        this->object = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data1, COLOR_DARKORANGE, GL_FILL);
    }
    else
    {
        static const GLfloat vertex_buffer_data[] = {
                -1.0f, 1.85f, -0.25f, // triangle 1 : begin
                -1.0f, 1.85f, 0.25f,
                -1.0f, 2.35f, 0.25f, // triangle 1 : end
                1.0f, 2.35f, -0.25f, // triangle 2 : begin
                -1.0f, 1.85f, -0.25f,
                -1.0f, 2.35f, -0.25f, // triangle 2 : end
                1.0f, 1.85f, 0.25f,
                -1.0f, 1.85f, -0.25f,
                1.0f, 1.85f, -0.25f,
                1.0f, 2.35f, -0.25f,
                1.0f, 1.85f, -0.25f,
                -1.0f, 1.85f, -0.25f,
                -1.0f, 1.85f, -0.25f,
                -1.0f, 2.35f, 0.25f,
                -1.0f, 2.35f, -0.25f,
                1.0f, 1.85f, 0.25f,
                -1.0f, 1.85f, 0.25f,
                -1.0f, 1.85f, -0.25f,
                -1.0f, 2.35f, 0.25f,
                -1.0f, 1.85f, 0.25f,
                1.0f, 1.85f, 0.25f,
                1.0f, 2.35f, 0.25f,
                1.0f, 1.85f, -0.25f,
                1.0f, 2.35f, -0.25f,
                1.0f, 1.85f, -0.25f,
                1.0f, 2.35f, 0.25f,
                1.0f, 1.85f, 0.25f,
                1.0f, 2.35f, 0.25f,
                1.0f, 2.35f, -0.25f,
                -1.0f, 2.35f, -0.25f,
                1.0f, 2.35f, 0.25f,
                -1.0f, 2.35f, -0.25f,
                -1.0f, 2.35f, 0.25f,
                1.0f, 2.35f, 0.25f,
                -1.0f, 2.35f, 0.25f,
                1.0f, 1.85f, 0.25f // end of monster body
        };

        this->object = create3DObject(GL_TRIANGLES, 12 * 3, vertex_buffer_data, COLOR_CRIMSON, GL_FILL);

        static const GLfloat vertex_buffer_data2[] = {
                -0.25f, 1.1f, -0.25f, // triangle 1 : begin
                -0.25f, 1.1f, 0.25f,
                -0.25f, 3.1f, 0.25f, // triangle 1 : end
                0.25f, 3.1f, -0.25f, // triangle 2 : begin
                -0.25f, 1.1f, -0.25f,
                -0.25f, 3.1f, -0.25f, // triangle 2 : end
                0.25f, 1.1f, 0.25f,
                -0.25f, 1.1f, -0.25f,
                0.25f, 1.1f, -0.25f,
                0.25f, 3.1f, -0.25f,
                0.25f, 1.1f, -0.25f,
                -0.25f, 1.1f, -0.25f,
                -0.25f, 1.1f, -0.25f,
                -0.25f, 3.1f, 0.25f,
                -0.25f, 3.1f, -0.25f,
                0.25f, 1.1f, 0.25f,
                -0.25f, 1.1f, 0.25f,
                -0.25f, 1.1f, -0.25f,
                -0.25f, 3.1f, 0.25f,
                -0.25f, 1.1f, 0.25f,
                0.25f, 1.1f, 0.25f,
                0.25f, 3.1f, 0.25f,
                0.25f, 1.1f, -0.25f,
                0.25f, 3.1f, -0.25f,
                0.25f, 1.1f, -0.25f,
                0.25f, 3.1f, 0.25f,
                0.25f, 1.1f, 0.25f,
                0.25f, 3.1f, 0.25f,
                0.25f, 3.1f, -0.25f,
                -0.25f, 3.1f, -0.25f,
                0.25f, 3.1f, 0.25f,
                -0.25f, 3.1f, -0.25f,
                -0.25f, 3.1f, 0.25f,
                0.25f, 3.1f, 0.25f,
                -0.25f, 3.1f, 0.25f,
                0.25f, 1.1f, 0.25f // end of monster body
        };
        this->object2 = create3DObject(GL_TRIANGLES, 12 * 3, vertex_buffer_data2, COLOR_CRIMSON, GL_FILL);
        printf("object made\n");
    }
    
}

void Booster::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    this->rotation += 2;
    glm::mat4 translate = glm::translate(this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(this->flag)
        draw3DObject(this->object);
    else
    {
        draw3DObject(this->object);
        draw3DObject(this->object2);

    }

}

void Booster::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Booster::tick(glm::vec3 boatpos) {
    //this->position = boatpos;
//    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

