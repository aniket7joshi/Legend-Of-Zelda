#include "main.h"

// #ifndef Barrel_H
// #define Barrel_H


class Barrel {
public:
    Barrel() {}
    Barrel(float x, float y, float z, int num);
    glm::vec3 position;
    float rotation;
    int num;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
    double accy;
private:
    VAO *object;
    VAO *object1;

};


Barrel::Barrel(float x, float y, float z, int num) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->speed = 0.03;
    this->num = num;
    this->accy = -0.002;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
	static const GLfloat vertex_buffer_data[] = {
        -0.8f,-0.2f,-0.8f, // triangle 1 : begin
        -0.8f,-0.2f, 0.8f,
        -0.8f, 0.2f, 0.8f, // triangle 1 : end
         0.8f, 0.2f,-0.8f, // triangle 2 : begin
        -0.8f,-0.2f,-0.8f,
        -0.8f, 0.2f,-0.8f, // triangle 2 : end
         0.8f,-0.2f, 0.8f,
        -0.8f,-0.2f,-0.8f,
         0.8f,-0.2f,-0.8f,
         0.8f, 0.2f,-0.8f,
         0.8f,-0.2f,-0.8f,
        -0.8f,-0.2f,-0.8f,
        -0.8f,-0.2f,-0.8f,
        -0.8f, 0.2f, 0.8f,
        -0.8f, 0.2f,-0.8f,
         0.8f,-0.2f, 0.8f,
        -0.8f,-0.2f, 0.8f,
        -0.8f,-0.2f,-0.8f,
        -0.8f, 0.2f, 0.8f,
        -0.8f,-0.2f, 0.8f,
         0.8f,-0.2f, 0.8f,
         0.8f, 0.2f, 0.8f,
         0.8f,-0.2f,-0.8f,
         0.8f, 0.2f,-0.8f,
         0.8f,-0.2f,-0.8f,
         0.8f, 0.2f, 0.8f,
         0.8f,-0.2f, 0.8f,
         0.8f, 0.2f, 0.8f,
         0.8f, 0.2f,-0.8f,
        -0.8f, 0.2f,-0.8f,
         0.8f, 0.2f, 0.8f,
        -0.8f, 0.2f,-0.8f,
        -0.8f, 0.2f, 0.8f,
         0.8f, 0.2f, 0.8f,
        -0.8f, 0.2f, 0.8f,
		 0.8f,-0.2f, 0.8f

    };
    static const GLfloat vertex_buffer_data1[] = {
		-0.2, 0.75, 0.05,
		 0.2, 0.75, 0.05,
		 0.0, 1.25,0.05,
		-0.2, 0.75, 0.05,
		 0.2, 0.75, 0.05,
		 0.0, 0.25,0.05,
		-0.2, 0.75, 0.15,
		 0.2, 0.75, 0.15,
		 0.0, 1.25,0.15,
		-0.2, 0.75, 0.15,
		 0.2, 0.75, 0.15,
		 0.0, 0.25,0.15,
		-0.2, 0.75, 0.05,  //
		 0.0, 1.25,0.05,
		 0.0, 1.25,0.15,
		 0.0, 1.25,0.15,
		-0.2, 1.25,0.15,
		-0.2, 0.75, 0.05,
		 0.2, 0.75, 0.05,  //
		 0.0, 1.25,0.05,
		 0.0, 1.25,0.15,
		 0.0, 1.25,0.15,
		 0.2, 1.25,0.15,
		 0.2, 0.75, 0.05,
		-0.2, 0.75, 0.05,  //
		 0.0, 0.25,0.05,
		 0.0, 0.25,0.15,
		 0.0, 0.25,0.15,
		-0.2, 0.25,0.15,
		-0.2, 0.75, 0.05,
		 0.2, 0.75, 0.05,  //
		 0.0, 0.25,0.05,
		 0.0, 0.25,0.15,
		 0.0, 0.25,0.15,
		 0.2, 0.25,0.15,
		 0.2, 0.75, 0.05,


    }; 
    if(num == 0)
    	this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data1, COLOR_MAGNET, GL_FILL);
	if(num == 1)
    	this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data1, COLOR_DARKGREEN, GL_FILL);
    if(num == 2)
    	this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data1, COLOR_DARKBLUE, GL_FILL);


    this->object = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, COLOR_DEEPPINK, GL_FILL);
}


void Barrel::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0,1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    //rotate          = rotate * glm::translate(glm::vec3(0, -3, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);

}

void Barrel::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Barrel::tick() {
	this->position.y = this->position.y + this->speed;
	this->speed = this->speed + this->accy;
	if(this->position.y<0)
	{
		this->position.y = 0;
		this->speed = 0.03;
	}
    //this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}


