#include "main.h"

// #ifndef Monster_H
// #define Monster_H


class Monster {
public:
    Monster() {}
    Monster(float x, float y, float z, int num);
    glm::vec3 position;
    float rotation;
    int num;
    int health;
    int numberOfTimesHit;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
    double speedx;
    double speedz;
    double accy;
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;



};


Monster::Monster(float x, float y, float z, int num) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->speed = 0.03;
    this->speedx = 0.1;
    this->speedz = 0.1;
    this->numberOfTimesHit = 0;
    this->num = num;
    this->accy = -0.002;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
	static const GLfloat vertex_buffer_data[] = {
        -1.5,0.0f,-1.5, // triangle 1 : begin
        -1.5,0.0f, 1.5,
        -0.05, 3.0f, 0.05, // triangle 1 : end
         0.05, 3.0f,-0.05, // triangle 2 : begin
        -1.5,0.0f,-1.5,
        -0.05, 3.0f,-0.05, // triangle 2 : end
         1.5,0.0f, 1.5,
        -1.5,0.0f,-1.5,
         1.5,0.0f,-1.5,
         0.05, 3.0f,-0.05,
         1.5,0.0f,-1.5,
        -1.5,0.0f,-1.5,
        -1.5,0.0f,-1.5,
        -0.05, 3.0f, 0.05,
        -0.05, 3.0f,-0.05,
         1.5,0.0f, 1.5,
        -1.5,0.0f, 1.5,
        -1.5,0.0f,-1.5,
        -0.05, 3.0f, 0.05,
        -1.5,0.0f, 1.5,
         1.5,0.0f, 1.5,
         0.05, 3.0f, 0.05,
         1.5,0.0f,-1.5,
         0.05, 3.0f,-0.05,
         1.5,0.0f,-1.5,
         0.05, 3.0f, 0.05,
         1.5,0.0f, 1.5,
         0.05, 3.0f, 0.05,
         0.05, 3.0f,-0.05,
        -0.05, 3.0f,-0.05,
         0.05, 3.0f, 0.05,
        -0.05, 3.0f,-0.05,
        -0.05, 3.0f, 0.05,
         0.05, 3.0f, 0.05,
        -0.05, 3.0f, 0.05,
         1.5,0.0f, 1.5
    };
    static const GLfloat vertex_buffer_data1[] = {
		-1.5,6.0,-1.5, // triangle 1 : begin
        -1.5,6.0, 1.5,
        -0.05, 3.0f, 0.05, // triangle 1 : end
         0.05, 3.0f,-0.05, // triangle 2 : begin
        -1.5,6.0,-1.5,
        -0.05, 3.0f,-0.05, // triangle 2 : end
         1.5,6.0, 1.5,
        -1.5,6.0,-1.5,
         1.5,6.0,-1.5,
         0.05, 3.0f,-0.05,
         1.5,6.0,-1.5,
        -1.5,6.0,-1.5,
        -1.5,6.0,-1.5,
        -0.05, 3.0f, 0.05,
        -0.05, 3.0f,-0.05,
         1.5,6.0, 1.5,
        -1.5,6.0, 1.5,
        -1.5,6.0,-1.5,
        -0.05, 3.0f, 0.05,
        -1.5,6.0, 1.5,
         1.5,6.0, 1.5,
         0.05, 3.0f, 0.05,
         1.5,6.0,-1.5,
         0.05, 3.0f,-0.05,
         1.5,6.0,-1.5,
         0.05, 3.0f, 0.05,
         1.5,6.0, 1.5,
         0.05, 3.0f, 0.05,
         0.05, 3.0f,-0.05,
        -0.05, 3.0f,-0.05,
         0.05, 3.0f, 0.05,
        -0.05, 3.0f,-0.05,
        -0.05, 3.0f, 0.05,
         0.05, 3.0f, 0.05,
        -0.05, 3.0f, 0.05,
         1.5,6.0, 1.5
    }; 
    static const GLfloat vertex_buffer_dataHeadLeft[] = {
        -1.25, 6.0, 0.0, //Bottom
        -1.00, 6.0, 0.0,
        -1.00, 6.0, 0.2,
        -1.00, 6.0, 0.2,
        -1.25, 6.0, 0.2,
        -1.25, 6.0, 0.0,
        -1.25, 6.0, 0.2, //front
        -1.25, 8.0, 0.2,
        -1.00, 8.0, 0.2,
        -1.00, 8.0, 0.2,
        -1.00, 6.0, 0.2,
        -1.25, 6.0, 0.2,
        -1.25, 6.0, 0.0, //back
        -1.25, 8.0, 0.0,
        -1.00, 8.0, 0.0,
        -1.00, 8.0, 0.0,
        -1.00, 6.0, 0.0,
        -1.25, 6.0, 0.0,
        -1.25, 8.0, 0.0, //Bottom
        -1.00, 8.0, 0.0,
        -1.00, 8.0, 0.2,
        -1.00, 8.0, 0.2,
        -1.25, 8.0, 0.2,
        -1.25, 8.0, 0.0,
        -1.25, 6.0, 0.2, //side left
        -1.25, 6.0, 0.0,
        -1.25, 8.0, 0.0,
        -1.25, 8.0, 0.0,
        -1.25, 8.0, 0.2,
        -1.25, 6.0, 0.2,
        -1.00, 6.0, 0.2, //side right
        -1.00, 6.0, 0.0,
        -1.00, 8.0, 0.0,
        -1.00, 8.0, 0.0,
        -1.00, 8.0, 0.2,
        -1.00, 6.0, 0.2,

    };
    static const GLfloat vertex_buffer_dataHeadRight[] = {
         1.25, 6.0, 0.0, //Bottom
         1.00, 6.0, 0.0,
         1.00, 6.0, 0.2,
         1.00, 6.0, 0.2,
         1.25, 6.0, 0.2,
         1.25, 6.0, 0.0,
         1.25, 6.0, 0.2, //front
         1.25, 8.0, 0.2,
         1.00, 8.0, 0.2,
         1.00, 8.0, 0.2,
         1.00, 6.0, 0.2,
         1.25, 6.0, 0.2,
         1.25, 6.0, 0.0, //back
         1.25, 8.0, 0.0,
         1.00, 8.0, 0.0,
         1.00, 8.0, 0.0,
         1.00, 6.0, 0.0,
         1.25, 6.0, 0.0,
         1.25, 8.0, 0.0, //Bottom
         1.00, 8.0, 0.0,
         1.00, 8.0, 0.2,
         1.00, 8.0, 0.2,
         1.25, 8.0, 0.2,
         1.25, 8.0, 0.0,
         1.25, 6.0, 0.2, //side left
         1.25, 6.0, 0.0,
         1.25, 8.0, 0.0,
         1.25, 8.0, 0.0,
         1.25, 8.0, 0.2,
         1.25, 6.0, 0.2,
         1.00, 6.0, 0.2, //side right
         1.00, 6.0, 0.0,
         1.00, 8.0, 0.0,
         1.00, 8.0, 0.0,
         1.00, 8.0, 0.2,
         1.00, 6.0, 0.2,

    };

    //if(num == 0)
 //    	this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data1, COLOR_MAGNET, GL_FILL);
	// if(num == 1)
 //    	this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data1, COLOR_LAVENDER, GL_FILL);
 //    if(num == 2)
 //    	this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data1, COLOR_DARKBLUE, GL_FILL);
    static GLfloat vertex_buffer_data2[9*360];
    double pi =3.1415926535897;
    float r = 2;
    double theta = 0;
    int i = 0;
    for(i = 0;i<360;i++)
    {
        vertex_buffer_data2[9 * i] = 0;
        vertex_buffer_data2[9 * i + 1] = 3.0;
        vertex_buffer_data2[9 * i + 2] = 0;
        vertex_buffer_data2[9 * i + 3] = r * cos(((theta) * pi) / 180);
        vertex_buffer_data2[9 * i + 4] = 3.0;
        vertex_buffer_data2[9 * i + 5] = r * sin(((theta) * pi) / 180);
        vertex_buffer_data2[9 * i + 6] = r * cos(((theta + 1) * pi) / 180);
        vertex_buffer_data2[9 * i + 7] = 3.0;
        vertex_buffer_data2[9 * i + 8] = r * sin(((theta + 1) * pi) / 180);
        theta = theta + 1;
    }
    static const GLfloat vertex_buffer_data3[] = {
        -2.0,-0.0f,-2.0, // triangle 1 : begin
        -2.0,-0.0f, 2.0,
        -2.0, 2.0f, 2.0, // triangle 1 : end
         2.0, 2.0f,-2.0, // triangle 2 : begin
        -2.0,-0.0f,-2.0,
        -2.0, 2.0f,-2.0, // triangle 2 : end
         2.0,-0.0f, 2.0,
        -2.0,-0.0f,-2.0,
         2.0,-0.0f,-2.0,
         2.0, 2.0f,-2.0,
         2.0,-0.0f,-2.0,
        -2.0,-0.0f,-2.0,
        -2.0,-0.0f,-2.0,
        -2.0, 2.0f, 2.0,
        -2.0, 2.0f,-2.0,
         2.0,-0.0f, 2.0,
        -2.0,-0.0f, 2.0,
        -2.0,-0.0f,-2.0,
        -2.0, 2.0f, 2.0,
        -2.0,-0.0f, 2.0,
         2.0,-0.0f, 2.0,
         2.0, 2.0f, 2.0,
         2.0,-0.0f,-2.0,
         2.0, 2.0f,-2.0,
         2.0,-0.0f,-2.0,
         2.0, 2.0f, 2.0,
         2.0,-0.0f, 2.0,
         2.0, 2.0f, 2.0,
         2.0, 2.0f,-2.0,
        -2.0, 2.0f,-2.0,
         2.0, 2.0f, 2.0,
        -2.0, 2.0f,-2.0,
        -2.0, 2.0f, 2.0,
         2.0, 2.0f, 2.0,
        -2.0, 2.0f, 2.0,
         2.0,-0.0f, 2.0
    };
    static const GLfloat vertex_buffer_data4[] = {
        -1.5,2.0,-1.5, // triangle 1 : begin
        -1.5,2.0, 1.5,
        -0.05, 4.0f, 0.05, // triangle 1 : end
         0.05, 4.0f,-0.05, // triangle 2 : begin
        -1.5,2.0,-1.5,
        -0.05, 4.0f,-0.05, // triangle 2 : end
         1.5,2.0, 1.5,
        -1.5,2.0,-1.5,
         1.5,2.0,-1.5,
         0.05, 4.0f,-0.05,
         1.5,2.0,-1.5,
        -1.5,2.0,-1.5,
        -1.5,2.0,-1.5,
        -0.05, 4.0f, 0.05,
        -0.05, 4.0f,-0.05,
         1.5,2.0, 1.5,
        -1.5,2.0, 1.5,
        -1.5,2.0,-1.5,
        -0.05, 4.0f, 0.05,
        -1.5,2.0, 1.5,
         1.5,2.0, 1.5,
         0.05, 4.0f, 0.05,
         1.5,2.0,-1.5,
         0.05, 4.0f,-0.05,
         1.5,2.0,-1.5,
         0.05, 4.0f, 0.05,
         1.5,2.0, 1.5,
         0.05, 4.0f, 0.05,
         0.05, 4.0f,-0.05,
        -0.05, 4.0f,-0.05,
         0.05, 4.0f, 0.05,
        -0.05, 4.0f,-0.05,
        -0.05, 4.0f, 0.05,
         0.05, 4.0f, 0.05,
        -0.05, 4.0f, 0.05,
         1.5,2.0, 1.5
    };
    static const GLfloat vertex_buffer_data5[] = {
        -2.0,4.0,-2.0, // triangle 1 : begin
        -2.0,4.0, 2.0,
        -2.0,5.0, 2.0, // triangle 1 : end
         2.0,5.0,-2.0, // triangle 2 : begin
        -2.0,4.0,-2.0,
        -2.0,5.0,-2.0, // triangle 2 : end
         2.0,4.0, 2.0,
        -2.0,4.0,-2.0,
         2.0,4.0,-2.0,
         2.0,5.0,-2.0,
         2.0,4.0,-2.0,
        -2.0,4.0,-2.0,
        -2.0,4.0,-2.0,
        -2.0,5.0, 2.0,
        -2.0,5.0,-2.0,
         2.0,4.0, 2.0,
        -2.0,4.0, 2.0,
        -2.0,4.0,-2.0,
        -2.0,5.0, 2.0,
        -2.0,4.0, 2.0,
         2.0,4.0, 2.0,
         2.0,5.0, 2.0,
         2.0,4.0,-2.0,
         2.0,5.0,-2.0,
         2.0,4.0,-2.0,
         2.0,5.0, 2.0,
         2.0,4.0, 2.0,
         2.0,5.0, 2.0,
         2.0,5.0,-2.0,
        -2.0,5.0,-2.0,
         2.0,5.0, 2.0,
        -2.0,5.0,-2.0,
        -2.0,5.0, 2.0,
         2.0,5.0, 2.0,
        -2.0,5.0, 2.0,
         2.0,4.0, 2.0
    };
    static const GLfloat vertex_buffer_data6[] = {
        -2.00, 5.0, -2.0, //Bottom
        -1.75, 5.0, -2.0,
        -1.75, 5.0, -1.75,
        -1.75, 5.0, -1.75,
        -2.00, 5.0, -1.75,
        -2.00, 5.0, -2.0,
        -2.00, 5.0, -1.75, //front
        -2.00, 7.0, -1.75,
        -1.75, 7.0, -1.75,
        -1.75, 7.0, -1.75,
        -1.75, 5.0, -1.75,
        -2.00, 5.0, -1.75,
        -2.00, 5.0, -2.0, //back
        -2.00, 7.0, -2.0,
        -1.75, 7.0, -2.0,
        -1.75, 7.0, -2.0,
        -1.75, 5.0, -2.0,
        -2.00, 5.0, -2.0,
        -2.00, 7.0, -2.0, //Bottom
        -1.75, 7.0, -2.0,
        -1.75, 7.0, -1.75,
        -1.75, 7.0, -1.75,
        -2.00, 7.0, -1.75,
        -2.00, 7.0, -2.0,
        -2.00, 5.0, -1.75, //side left
        -2.00, 5.0, -2.0,
        -2.00, 7.0, -2.0,
        -2.00, 7.0, -2.0,
        -2.00, 7.0, -1.75,
        -2.00, 5.0, -1.75,
        -1.75, 5.0, -1.75, //side right
        -1.75, 5.0, -2.0,
        -1.75, 7.0, -2.0,
        -1.75, 7.0, -2.0,
        -1.75, 7.0, -1.75,
        -1.75, 5.0, -1.75,
         2.00, 5.0,  2.0, //Bottom
         1.75, 5.0,  2.0,
         1.75, 5.0,  1.75,
         1.75, 5.0,  1.75,
         2.00, 5.0,  1.75,
         2.00, 5.0,  2.0,
         2.00, 5.0,  1.75, //front
         2.00, 7.0,  1.75,
         1.75, 7.0,  1.75,
         1.75, 7.0,  1.75,
         1.75, 5.0,  1.75,
         2.00, 5.0,  1.75,
         2.00, 5.0,  2.0, //back
         2.00, 7.0,  2.0,
         1.75, 7.0,  2.0,
         1.75, 7.0,  2.0,
         1.75, 5.0,  2.0,
         2.00, 5.0,  2.0,
         2.00, 7.0,  2.0, //Bottom
         1.75, 7.0,  2.0,
         1.75, 7.0,  1.75,
         1.75, 7.0,  1.75,
         2.00, 7.0,  1.75,
         2.00, 7.0,  2.0,
         2.00, 5.0,  1.75, //side left
         2.00, 5.0,  2.0,
         2.00, 7.0,  2.0,
         2.00, 7.0,  2.0,
         2.00, 7.0,  1.75,
         2.00, 5.0,  1.75,
         1.75, 5.0,  1.75, //side right
         1.75, 5.0,  2.0,
         1.75, 7.0,  2.0,
         1.75, 7.0,  2.0,
         1.75, 7.0,  1.75,
         1.75, 5.0,  1.75,
        -2.00, 5.0,  2.0, //Bottom
        -1.75, 5.0,  2.0,
        -1.75, 5.0,  1.75,
        -1.75, 5.0,  1.75,
        -2.00, 5.0,  1.75,
        -2.00, 5.0,  2.0,
        -2.00, 5.0,  1.75, //front
        -2.00, 7.0,  1.75,
        -1.75, 7.0,  1.75,
        -1.75, 7.0,  1.75,
        -1.75, 5.0,  1.75,
        -2.00, 5.0,  1.75,
        -2.00, 5.0,  2.0, //back
        -2.00, 7.0,  2.0,
        -1.75, 7.0,  2.0,
        -1.75, 7.0,  2.0,
        -1.75, 5.0,  2.0,
        -2.00, 5.0,  2.0,
        -2.00, 7.0,  2.0, //Bottom
        -1.75, 7.0,  2.0,
        -1.75, 7.0,  1.75,
        -1.75, 7.0,  1.75,
        -2.00, 7.0,  1.75,
        -2.00, 7.0,  2.0,
        -2.00, 5.0,  1.75, //side left
        -2.00, 5.0,  2.0,
        -2.00, 7.0,  2.0,
        -2.00, 7.0,  2.0,
        -2.00, 7.0,  1.75,
        -2.00, 5.0,  1.75,
        -1.75, 5.0,  1.75, //side right
        -1.75, 5.0,  2.0,
        -1.75, 7.0,  2.0,
        -1.75, 7.0,  2.0,
        -1.75, 7.0,  1.75,
        -1.75, 5.0,  1.75,
         2.00, 5.0,  -2.0, //Bottom
         1.75, 5.0,  -2.0,
         1.75, 5.0,  -1.75,
         1.75, 5.0,  -1.75,
         2.00, 5.0,  -1.75,
         2.00, 5.0,  -2.0,
         2.00, 5.0,  -1.75, //front
         2.00, 7.0,  -1.75,
         1.75, 7.0,  -1.75,
         1.75, 7.0,  -1.75,
         1.75, 5.0,  -1.75,
         2.00, 5.0,  -1.75,
         2.00, 5.0,  -2.0, //back
         2.00, 7.0,  -2.0,
         1.75, 7.0,  -2.0,
         1.75, 7.0,  -2.0,
         1.75, 5.0,  -2.0,
         2.00, 5.0,  -2.0,
         2.00, 7.0,  -2.0, //Bottom
         1.75, 7.0,  -2.0,
         1.75, 7.0,  -1.75,
         1.75, 7.0,  -1.75,
         2.00, 7.0,  -1.75,
         2.00, 7.0,  -2.0,
         2.00, 5.0,  -1.75, //side left
         2.00, 5.0,  -2.0,
         2.00, 7.0,  -2.0,
         2.00, 7.0,  -2.0,
         2.00, 7.0,  -1.75,
         2.00, 5.0,  -1.75,
         1.75, 5.0,  -1.75, //side right
         1.75, 5.0,  -2.0,
         1.75, 7.0,  -2.0,
         1.75, 7.0,  -2.0,
         1.75, 7.0,  -1.75,
         1.75, 5.0,  -1.75,


    };
    static const GLfloat vertex_buffer_data8[] = {
        -1.5,3.0,-1.5, // triangle 1 : begin
        -1.5,3.0, 1.5,
        -1.5, 6.0f, 1.5, // triangle 1 : end
         1.5, 6.0f,-1.5, // triangle 2 : begin
        -1.5,3.0,-1.5,
        -1.5, 6.0f,-1.5, // triangle 2 : end
         1.5,3.0, 1.5,
        -1.5,3.0,-1.5,
         1.5,3.0,-1.5,
         1.5, 6.0f,-1.5,
         1.5,3.0,-1.5,
        -1.5,3.0,-1.5,
        -1.5,3.0,-1.5,
        -1.5, 6.0f, 1.5,
        -1.5, 6.0f,-1.5,
         1.5,3.0, 1.5,
        -1.5,3.0, 1.5,
        -1.5,3.0,-1.5,
        -1.5, 6.0f, 1.5,
        -1.5,3.0, 1.5,
         1.5,3.0, 1.5,
         1.5, 6.0f, 1.5,
         1.5,3.0,-1.5,
         1.5, 6.0f,-1.5,
         1.5,3.0,-1.5,
         1.5, 6.0f, 1.5,
         1.5,3.0, 1.5,
         1.5, 6.0f, 1.5,
         1.5, 6.0f,-1.5,
        -1.5, 6.0f,-1.5,
         1.5, 6.0f, 1.5,
        -1.5, 6.0f,-1.5,
        -1.5, 6.0f, 1.5,
         1.5, 6.0f, 1.5,
        -1.5, 6.0f, 1.5,
         1.5,3.0, 1.5
    };
    static const GLfloat vertex_buffer_dataEye[] = {
        -1.10, 5.2, 1.5, //Bottom
        -0.70, 5.2, 1.5,
        -0.70, 5.2, 1.7,
        -0.70, 5.2, 1.7,
        -1.10, 5.2, 1.7,
        -1.10, 5.2, 1.5,
        -1.10, 5.2, 1.7, //front
        -1.10, 5.6, 1.7,
        -0.70, 5.6, 1.7,
        -0.70, 5.6, 1.7,
        -0.70, 5.2, 1.7,
        -1.10, 5.2, 1.7,
        -1.10, 5.2, 1.5, //back
        -1.10, 5.6, 1.5,
        -0.70, 5.6, 1.5,
        -0.70, 5.6, 1.5,
        -0.70, 5.2, 1.5,
        -1.10, 5.2, 1.5,
        -1.10, 5.6, 1.5, //Bottom
        -0.70, 5.6, 1.5,
        -0.70, 5.6, 1.7,
        -0.70, 5.6, 1.7,
        -1.10, 5.6, 1.7,
        -1.10, 5.6, 1.5,
        -1.10, 5.2, 1.7, //side left
        -1.10, 5.2, 1.5,
        -1.10, 5.6, 1.5,
        -1.10, 5.6, 1.5,
        -1.10, 5.6, 1.7,
        -1.10, 5.2, 1.7,
        -0.70, 5.2, 1.7, //side right
        -0.70, 5.2, 1.5,
        -0.70, 5.6, 1.5,
        -0.70, 5.6, 1.5,
        -0.70, 5.6, 1.7,
        -0.70, 5.2, 1.7,
         1.10, 5.2, 1.5, //Bottom
         0.70, 5.2, 1.5,
         0.70, 5.2, 1.7,
         0.70, 5.2, 1.7,
         1.10, 5.2, 1.7,
         1.10, 5.2, 1.5,
         1.10, 5.2, 1.7, //front
         1.10, 5.6, 1.7,
         0.70, 5.6, 1.7,
         0.70, 5.6, 1.7,
         0.70, 5.2, 1.7,
         1.10, 5.2, 1.7,
         1.10, 5.2, 1.5, //back
         1.10, 5.6, 1.5,
         0.70, 5.6, 1.5,
         0.70, 5.6, 1.5,
         0.70, 5.2, 1.5,
         1.10, 5.2, 1.5,
         1.10, 5.6, 1.5, //Bottom
         0.70, 5.6, 1.5,
         0.70, 5.6, 1.7,
         0.70, 5.6, 1.7,
         1.10, 5.6, 1.7,
         1.10, 5.6, 1.5,
         1.10, 5.2, 1.7, //side left
         1.10, 5.2, 1.5,
         1.10, 5.6, 1.5,
         1.10, 5.6, 1.5,
         1.10, 5.6, 1.7,
         1.10, 5.2, 1.7,
         0.70, 5.2, 1.7, //side right
         0.70, 5.2, 1.5,
         0.70, 5.6, 1.5,
         0.70, 5.6, 1.5,
         0.70, 5.6, 1.7,
         0.70, 5.2, 1.7,
         -1.10, 5.2,-1.5, //Bottom
        -0.70, 5.2, -1.5,
        -0.70, 5.2, -1.7,
        -0.70, 5.2, -1.7,
        -1.10, 5.2, -1.7,
        -1.10, 5.2, -1.5,
        -1.10, 5.2, -1.7, //front
        -1.10, 5.6, -1.7,
        -0.70, 5.6, -1.7,
        -0.70, 5.6, -1.7,
        -0.70, 5.2, -1.7,
        -1.10, 5.2, -1.7,
        -1.10, 5.2, -1.5, //back
        -1.10, 5.6, -1.5,
        -0.70, 5.6, -1.5,
        -0.70, 5.6, -1.5,
        -0.70, 5.2, -1.5,
        -1.10, 5.2, -1.5,
        -1.10, 5.6, -1.5, //Bottom
        -0.70, 5.6, -1.5,
        -0.70, 5.6, -1.7,
        -0.70, 5.6, -1.7,
        -1.10, 5.6, -1.7,
        -1.10, 5.6, -1.5,
        -1.10, 5.2, -1.7, //side left
        -1.10, 5.2, -1.5,
        -1.10, 5.6, -1.5,
        -1.10, 5.6, -1.5,
        -1.10, 5.6, -1.7,
        -1.10, 5.2, -1.7,
        -0.70, 5.2, -1.7, //side right
        -0.70, 5.2, -1.5,
        -0.70, 5.6, -1.5,
        -0.70, 5.6, -1.5,
        -0.70, 5.6, -1.7,
        -0.70, 5.2, -1.7,
         1.10, 5.2, -1.5, //Bottom
         0.70, 5.2, -1.5,
         0.70, 5.2, -1.7,
         0.70, 5.2, -1.7,
         1.10, 5.2, -1.7,
         1.10, 5.2, -1.5,
         1.10, 5.2, -1.7, //front
         1.10, 5.6, -1.7,
         0.70, 5.6, -1.7,
         0.70, 5.6, -1.7,
         0.70, 5.2, -1.7,
         1.10, 5.2, -1.7,
         1.10, 5.2, -1.5, //back
         1.10, 5.6, -1.5,
         0.70, 5.6, -1.5,
         0.70, 5.6, -1.5,
         0.70, 5.2, -1.5,
         1.10, 5.2, -1.5,
         1.10, 5.6, -1.5, //Bottom
         0.70, 5.6, -1.5,
         0.70, 5.6, -1.7,
         0.70, 5.6, -1.7,
         1.10, 5.6, -1.7,
         1.10, 5.6, -1.5,
         1.10, 5.2, -1.7, //side left
         1.10, 5.2, -1.5,
         1.10, 5.6, -1.5,
         1.10, 5.6, -1.5,
         1.10, 5.6, -1.7,
         1.10, 5.2, -1.7,
         0.70, 5.2, -1.7, //side right
         0.70, 5.2, -1.5,
         0.70, 5.6, -1.5,
         0.70, 5.6, -1.5,
         0.70, 5.6, -1.7,
         0.70, 5.2, -1.7,

    };
    static const GLfloat vertex_buffer_data9[] = {
      -1.25,0.0,0.25, // triangle 1 : begin
      -1.25,0.0,0.5,
      -1.25,3.0,0.5, // triangle 1 : end
      -1.00,3.0,0.25, // triangle 2 : begin
      -1.25,0.0,0.25,
      -1.25,3.0,0.25, // triangle 2 : end
      -1.00,0.0,0.5,
      -1.25,0.0,0.25,
      -1.00,0.0,0.25,
      -1.00,3.0,0.25,
      -1.00,0.0,0.25,
      -1.25,0.0,0.25,
      -1.25,0.0,0.25,
      -1.25,3.0,0.5,
      -1.25,3.0,0.25,
      -1.00,0.0,0.5,
      -1.25,0.0,0.5,
      -1.25,0.0,0.25,
      -1.25,3.0,0.5,
      -1.25,0.0,0.5,
      -1.00,0.0,0.5,
      -1.00,3.0,0.5,
      -1.00,0.0,0.25,
      -1.00,3.0,0.25,
      -1.00,0.0,0.25,
      -1.00,3.0,0.5,
      -1.00,0.0,0.5,
      -1.00,3.0,0.5,
      -1.00,3.0,0.25,
      -1.25,3.0,0.25,
      -1.00,3.0,0.5,
      -1.25,3.0,0.25,
      -1.25,3.0,0.5,
      -1.00,3.0,0.5,
      -1.25,3.0,0.5,
      -1.00,0.0,0.5,
      1.00,0.0,0.25, // triangle 1 : begin
      1.00,0.0,0.5,
      1.00,3.0,0.5, // triangle 1 : end
      1.25,3.0,0.25, // triangle 2 : begin
      1.00,0.0,0.25,
      1.00,3.0,0.25, // triangle 2 : end
      1.25,0.0,0.5,
      1.00,0.0,0.25,
      1.25,0.0,0.25,
      1.25,3.0,0.25,
      1.25,0.0,0.25,
      1.00,0.0,0.25,
      1.00,0.0,0.25,
      1.00,3.0,0.5,
      1.00,3.0,0.25,
      1.25,0.0,0.5,
      1.00,0.0,0.5,
      1.00,0.0,0.25,
      1.00,3.0,0.5,
      1.00,0.0,0.5,
      1.25,0.0,0.5,
      1.25,3.0,0.5,
      1.25,0.0,0.25,
      1.25,3.0,0.25,
      1.25,0.0,0.25,
      1.25,3.0,0.5,
      1.25,0.0,0.5,
      1.25,3.0,0.5,
      1.25,3.0,0.25,
      1.00,3.0,0.25,
      1.25,3.0,0.5,
      1.00,3.0,0.25,
      1.00,3.0,0.5,
      1.25,3.0,0.5,
      1.00,3.0,0.5,
      1.25,0.0,0.5
    };
    static const GLfloat vertex_buffer_data10[] = {
        -4.0f, 3.0f,-2.0f, // triangle 1 : begin
        -4.0f, 3.0f, 2.0f,
        -4.0f, 8.0f, 2.0f, // triangle 8 : end
         4.0f, 8.0f,-2.0f, // triangle 2 : begin
        -4.0f, 3.0f,-2.0f,
        -4.0f, 8.0f,-2.0f, // triangle 2 : end
         4.0f, 3.0f, 2.0f,
        -4.0f, 3.0f,-2.0f,
         4.0f, 3.0f,-2.0f,
         4.0f, 8.0f,-2.0f,
         4.0f, 3.0f,-2.0f,
        -4.0f, 3.0f,-2.0f,
        -4.0f, 3.0f,-2.0f,
        -4.0f, 8.0f, 2.0f,
        -4.0f, 8.0f,-2.0f,
         4.0f, 3.0f, 2.0f,
        -4.0f, 3.0f, 2.0f,
        -4.0f, 3.0f,-2.0f,
        -4.0f, 8.0f, 2.0f,
        -4.0f, 3.0f, 2.0f,
         4.0f, 3.0f, 2.0f,
         4.0f, 8.0f, 2.0f,
         4.0f, 3.0f,-2.0f,
         4.0f, 8.0f,-2.0f,
         4.0f, 3.0f,-2.0f,
         4.0f, 8.0f, 2.0f,
         4.0f, 3.0f, 2.0f,
         4.0f, 8.0f, 2.0f,
         4.0f, 8.0f,-2.0f,
        -4.0f, 8.0f,-2.0f,
         4.0f, 8.0f, 2.0f,
        -4.0f, 8.0f,-2.0f,
        -4.0f, 8.0f, 2.0f,
         4.0f, 8.0f, 2.0f,
        -4.0f, 8.0f, 2.0f,
         4.0f, 3.0f, 2.0f
    };
    static const GLfloat vertex_buffer_data11[] = {
      -3.5,0.0,1.75, // triangle 1 : begin
      -3.5,0.0,2.0,
      -3.5,3.0,2.0, // triangle 1 : end
      -3.00,3.0,1.75, // triangle 2 : begin
      -3.5,0.0,1.75,
      -3.5,3.0,1.75, // triangle 2 : end
      -3.00,0.0,2.0,
      -3.5,0.0,1.75,
      -3.00,0.0,1.75,
      -3.00,3.0,1.75,
      -3.00,0.0,1.75,
      -3.5,0.0,1.75,
      -3.5,0.0,1.75,
      -3.5,3.0,2.0,
      -3.5,3.0,1.75,
      -3.00,0.0,2.0,
      -3.5,0.0,2.0,
      -3.5,0.0,1.75,
      -3.5,3.0,2.0,
      -3.5,0.0,2.0,
      -3.00,0.0,2.0,
      -3.00,3.0,2.0,
      -3.00,0.0,1.75,
      -3.00,3.0,1.75,
      -3.00,0.0,1.75,
      -3.00,3.0,2.0,
      -3.00,0.0,2.0,
      -3.00,3.0,2.0,
      -3.00,3.0,1.75,
      -3.5,3.0,1.75,
      -3.00,3.0,2.0,
      -3.5,3.0,1.75,
      -3.5,3.0,2.0,
      -3.00,3.0,2.0,
      -3.5,3.0,2.0,
      -3.00,0.0,2.0,
      3.00,0.0,1.75, // triangle 1 : begin
      3.00,0.0,2.0,
      3.00,3.0,2.0, // triangle 1 : end
      3.50,3.0,1.75, // triangle 2 : begin
      3.00,0.0,1.75,
      3.00,3.0,1.75, // triangle 2 : end
      3.50,0.0,2.0,
      3.00,0.0,1.75,
      3.50,0.0,1.75,
      3.50,3.0,1.75,
      3.50,0.0,1.75,
      3.00,0.0,1.75,
      3.00,0.0,1.75,
      3.00,3.0,2.0,
      3.00,3.0,1.75,
      3.50,0.0,2.0,
      3.00,0.0,2.0,
      3.00,0.0,1.75,
      3.00,3.0,2.0,
      3.00,0.0,2.0,
      3.50,0.0,2.0,
      3.50,3.0,2.0,
      3.50,0.0,1.75,
      3.50,3.0,1.75,
      3.50,0.0,1.75,
      3.50,3.0,2.0,
      3.50,0.0,2.0,
      3.50,3.0,2.0,
      3.50,3.0,1.75,
      3.00,3.0,1.75,
      3.50,3.0,2.0,
      3.00,3.0,1.75,
      3.00,3.0,2.0,
      3.50,3.0,2.0,
      3.00,3.0,2.0,
      3.50,0.0,2.0,
      -3.5,0.0,-1.75, // triangle 1 : begin
      -3.5,0.0,-2.0,
      -3.5,3.0,-2.0, // triangle 1 : end
      -3.00,3.0,-1.75, // triangle 2 : begin
      -3.5,0.0,-1.75,
      -3.5,3.0,-1.75, // triangle 2 : end
      -3.00,0.0,-2.0,
      -3.5,0.0,-1.75,
      -3.00,0.0,-1.75,
      -3.00,3.0,-1.75,
      -3.00,0.0,-1.75,
      -3.5,0.0,-1.75,
      -3.5,0.0,-1.75,
      -3.5,3.0,-2.0,
      -3.5,3.0,-1.75,
      -3.00,0.0,-2.0,
      -3.5,0.0,-2.0,
      -3.5,0.0,-1.75,
      -3.5,3.0,-2.0,
      -3.5,0.0,-2.0,
      -3.00,0.0,-2.0,
      -3.00,3.0,-2.0,
      -3.00,0.0,-1.75,
      -3.00,3.0,-1.75,
      -3.00,0.0,-1.75,
      -3.00,3.0,-2.0,
      -3.00,0.0,-2.0,
      -3.00,3.0,-2.0,
      -3.00,3.0,-1.75,
      -3.5,3.0,-1.75,
      -3.00,3.0,-2.0,
      -3.5,3.0,-1.75,
      -3.5,3.0,-2.0,
      -3.00,3.0,-2.0,
      -3.5,3.0,-2.0,
      -3.00,0.0,-2.0,
      3.00,0.0,-1.75, // triangle 1 : begin
      3.00,0.0,-2.0,
      3.00,3.0,-2.0, // triangle 1 : end
      3.50,3.0,-1.75, // triangle 2 : begin
      3.00,0.0,-1.75,
      3.00,3.0,-1.75, // triangle 2 : end
      3.50,0.0,-2.0,
      3.00,0.0,-1.75,
      3.50,0.0,-1.75,
      3.50,3.0,-1.75,
      3.50,0.0,-1.75,
      3.00,0.0,-1.75,
      3.00,0.0,-1.75,
      3.00,3.0,-2.0,
      3.00,3.0,-1.75,
      3.50,0.0,-2.0,
      3.00,0.0,-2.0,
      3.00,0.0,-1.75,
      3.00,3.0,-2.0,
      3.00,0.0,-2.0,
      3.50,0.0,-2.0,
      3.50,3.0,-2.0,
      3.50,0.0,-1.75,
      3.50,3.0,-1.75,
      3.50,0.0,-1.75,
      3.50,3.0,-2.0,
      3.50,0.0,-2.0,
      3.50,3.0,-2.0,
      3.50,3.0,-1.75,
      3.00,3.0,-1.75,
      3.50,3.0,-2.0,
      3.00,3.0,-1.75,
      3.00,3.0,-2.0,
      3.50,3.0,-2.0,
      3.00,3.0,-2.0,
      3.50,0.0,-2.0
    };
    static const GLfloat vertex_buffer_data12[] = {
      -3.5,9.5,1.75, // triangle 1 : begin
      -3.5,9.5,2.0,
      -3.5,8.0,2.0, // triangle 1 : end
      -3.00,8.0,1.75, // triangle 2 : begin
      -3.5,9.5,1.75,
      -3.5,8.0,1.75, // triangle 2 : end
      -3.00,9.5,2.0,
      -3.5,9.5,1.75,
      -3.00,9.5,1.75,
      -3.00,8.0,1.75,
      -3.00,9.5,1.75,
      -3.5,9.5,1.75,
      -3.5,9.5,1.75,
      -3.5,8.0,2.0,
      -3.5,8.0,1.75,
      -3.00,9.5,2.0,
      -3.5,9.5,2.0,
      -3.5,9.5,1.75,
      -3.5,8.0,2.0,
      -3.5,9.5,2.0,
      -3.00,9.5,2.0,
      -3.00,8.0,2.0,
      -3.00,9.5,1.75,
      -3.00,8.0,1.75,
      -3.00,9.5,1.75,
      -3.00,8.0,2.0,
      -3.00,9.5,2.0,
      -3.00,8.0,2.0,
      -3.00,8.0,1.75,
      -3.5,8.0,1.75,
      -3.00,8.0,2.0,
      -3.5,8.0,1.75,
      -3.5,8.0,2.0,
      -3.00,8.0,2.0,
      -3.5,8.0,2.0,
      -3.00,9.5,2.0,
      3.00,9.5,1.75, // triangle 1 : begin
      3.00,9.5,2.0,
      3.00,8.0,2.0, // triangle 1 : end
      3.50,8.0,1.75, // triangle 2 : begin
      3.00,9.5,1.75,
      3.00,8.0,1.75, // triangle 2 : end
      3.50,9.5,2.0,
      3.00,9.5,1.75,
      3.50,9.5,1.75,
      3.50,8.0,1.75,
      3.50,9.5,1.75,
      3.00,9.5,1.75,
      3.00,9.5,1.75,
      3.00,8.0,2.0,
      3.00,8.0,1.75,
      3.50,9.5,2.0,
      3.00,9.5,2.0,
      3.00,9.5,1.75,
      3.00,8.0,2.0,
      3.00,9.5,2.0,
      3.50,9.5,2.0,
      3.50,8.0,2.0,
      3.50,9.5,1.75,
      3.50,8.0,1.75,
      3.50,9.5,1.75,
      3.50,8.0,2.0,
      3.50,9.5,2.0,
      3.50,8.0,2.0,
      3.50,8.0,1.75,
      3.00,8.0,1.75,
      3.50,8.0,2.0,
      3.00,8.0,1.75,
      3.00,8.0,2.0,
      3.50,8.0,2.0,
      3.00,8.0,2.0,
      3.50,9.5,2.0,
      -3.5,9.5,-1.75, // triangle 1 : begin
      -3.5,9.5,-2.0,
      -3.5,8.0,-2.0, // triangle 1 : end
      -3.00,8.0,-1.75, // triangle 2 : begin
      -3.5,9.5,-1.75,
      -3.5,8.0,-1.75, // triangle 2 : end
      -3.00,9.5,-2.0,
      -3.5,9.5,-1.75,
      -3.00,9.5,-1.75,
      -3.00,8.0,-1.75,
      -3.00,9.5,-1.75,
      -3.5,9.5,-1.75,
      -3.5,9.5,-1.75,
      -3.5,8.0,-2.0,
      -3.5,8.0,-1.75,
      -3.00,9.5,-2.0,
      -3.5,9.5,-2.0,
      -3.5,9.5,-1.75,
      -3.5,8.0,-2.0,
      -3.5,9.5,-2.0,
      -3.00,9.5,-2.0,
      -3.00,8.0,-2.0,
      -3.00,9.5,-1.75,
      -3.00,8.0,-1.75,
      -3.00,9.5,-1.75,
      -3.00,8.0,-2.0,
      -3.00,9.5,-2.0,
      -3.00,8.0,-2.0,
      -3.00,8.0,-1.75,
      -3.5,8.0,-1.75,
      -3.00,8.0,-2.0,
      -3.5,8.0,-1.75,
      -3.5,8.0,-2.0,
      -3.00,8.0,-2.0,
      -3.5,8.0,-2.0,
      -3.00,9.5,-2.0,
      3.00,9.5,-1.75, // triangle 1 : begin
      3.00,9.5,-2.0,
      3.00,8.0,-2.0, // triangle 1 : end
      3.50,8.0,-1.75, // triangle 2 : begin
      3.00,9.5,-1.75,
      3.00,8.0,-1.75, // triangle 2 : end
      3.50,9.5,-2.0,
      3.00,9.5,-1.75,
      3.50,9.5,-1.75,
      3.50,8.0,-1.75,
      3.50,9.5,-1.75,
      3.00,9.5,-1.75,
      3.00,9.5,-1.75,
      3.00,8.0,-2.0,
      3.00,8.0,-1.75,
      3.50,9.5,-2.0,
      3.00,9.5,-2.0,
      3.00,9.5,-1.75,
      3.00,8.0,-2.0,
      3.00,9.5,-2.0,
      3.50,9.5,-2.0,
      3.50,8.0,-2.0,
      3.50,9.5,-1.75,
      3.50,8.0,-1.75,
      3.50,9.5,-1.75,
      3.50,8.0,-2.0,
      3.50,9.5,-2.0,
      3.50,8.0,-2.0,
      3.50,8.0,-1.75,
      3.00,8.0,-1.75,
      3.50,8.0,-2.0,
      3.00,8.0,-1.75,
      3.00,8.0,-2.0,
      3.50,8.0,-2.0,
      3.00,8.0,-2.0,
      3.50,9.5,-2.0
    };
    static const GLfloat vertex_buffer_dataMonsterEye[] = {
        -4.20, 6.2, 1.5, //Bottom
        -4.00, 6.2, 1.5,
        -4.00, 6.2, 1.8,
        -4.00, 6.2, 1.8,
        -4.20, 6.2, 1.8,
        -4.20, 6.2, 1.5,
        -4.20, 6.2, 1.8, //front
        -4.20, 6.8, 1.8,
        -4.00, 6.8, 1.8,
        -4.00, 6.8, 1.8,
        -4.00, 6.2, 1.8,
        -4.20, 6.2, 1.8,
        -4.20, 6.2, 1.5, //back
        -4.20, 6.8, 1.5,
        -4.00, 6.8, 1.5,
        -4.00, 6.8, 1.5,
        -4.00, 6.2, 1.5,
        -4.20, 6.2, 1.5,
        -4.20, 6.8, 1.5, //Bottom
        -4.00, 6.8, 1.5,
        -4.00, 6.8, 1.8,
        -4.00, 6.8, 1.8,
        -4.20, 6.8, 1.8,
        -4.20, 6.8, 1.5,
        -4.20, 6.2, 1.8, //side left
        -4.20, 6.2, 1.5,
        -4.20, 6.8, 1.5,
        -4.20, 6.8, 1.5,
        -4.20, 6.8, 1.8,
        -4.20, 6.2, 1.8,
        -4.00, 6.2, 1.8, //side right
        -4.00, 6.2, 1.5,
        -4.00, 6.8, 1.5,
        -4.00, 6.8, 1.5,
        -4.00, 6.8, 1.8,
        -4.00, 6.2, 1.8,
         4.20, 6.2, 1.5, //Bottom
         4.00, 6.2, 1.5,
         4.00, 6.2, 1.8,
         4.00, 6.2, 1.8,
         4.20, 6.2, 1.8,
         4.20, 6.2, 1.5,
         4.20, 6.2, 1.8, //front
         4.20, 6.8, 1.8,
         4.00, 6.8, 1.8,
         4.00, 6.8, 1.8,
         4.00, 6.2, 1.8,
         4.20, 6.2, 1.8,
         4.20, 6.2, 1.5, //back
         4.20, 6.8, 1.5,
         4.00, 6.8, 1.5,
         4.00, 6.8, 1.5,
         4.00, 6.2, 1.5,
         4.20, 6.2, 1.5,
         4.20, 6.8, 1.5, //Bottom
         4.00, 6.8, 1.5,
         4.00, 6.8, 1.8,
         4.00, 6.8, 1.8,
         4.20, 6.8, 1.8,
         4.20, 6.8, 1.5,
         4.20, 6.2, 1.8, //side left
         4.20, 6.2, 1.5,
         4.20, 6.8, 1.5,
         4.20, 6.8, 1.5,
         4.20, 6.8, 1.8,
         4.20, 6.2, 1.8,
         4.00, 6.2, 1.8, //side right
         4.00, 6.2, 1.5,
         4.00, 6.8, 1.5,
         4.00, 6.8, 1.5,
         4.00, 6.8, 1.8,
         4.00, 6.2, 1.8,
        -4.20, 6.2,-1.5, //Bottom
        -4.00, 6.2, -1.5,
        -4.00, 6.2, -1.8,
        -4.00, 6.2, -1.8,
        -4.20, 6.2, -1.8,
        -4.20, 6.2, -1.5,
        -4.20, 6.2, -1.8, //front
        -4.20, 6.8, -1.8,
        -4.00, 6.8, -1.8,
        -4.00, 6.8, -1.8,
        -4.00, 6.2, -1.8,
        -4.20, 6.2, -1.8,
        -4.20, 6.2, -1.5, //back
        -4.20, 6.8, -1.5,
        -4.00, 6.8, -1.5,
        -4.00, 6.8, -1.5,
        -4.00, 6.2, -1.5,
        -4.20, 6.2, -1.5,
        -4.20, 6.8, -1.5, //Bottom
        -4.00, 6.8, -1.5,
        -4.00, 6.8, -1.8,
        -4.00, 6.8, -1.8,
        -4.20, 6.8, -1.8,
        -4.20, 6.8, -1.5,
        -4.20, 6.2, -1.8, //side left
        -4.20, 6.2, -1.5,
        -4.20, 6.8, -1.5,
        -4.20, 6.8, -1.5,
        -4.20, 6.8, -1.8,
        -4.20, 6.2, -1.8,
        -4.00, 6.2, -1.8, //side right
        -4.00, 6.2, -1.5,
        -4.00, 6.8, -1.5,
        -4.00, 6.8, -1.5,
        -4.00, 6.8, -1.8,
        -4.00, 6.2, -1.8,
         4.20, 6.2, -1.5, //Bottom
         4.00, 6.2, -1.5,
         4.00, 6.2, -1.8,
         4.00, 6.2, -1.8,
         4.20, 6.2, -1.8,
         4.20, 6.2, -1.5,
         4.20, 6.2, -1.8, //front
         4.20, 6.8, -1.8,
         4.00, 6.8, -1.8,
         4.00, 6.8, -1.8,
         4.00, 6.2, -1.8,
         4.20, 6.2, -1.8,
         4.20, 6.2, -1.5, //back
         4.20, 6.8, -1.5,
         4.00, 6.8, -1.5,
         4.00, 6.8, -1.5,
         4.00, 6.2, -1.5,
         4.20, 6.2, -1.5,
         4.20, 6.8, -1.5, //Bottom
         4.00, 6.8, -1.5,
         4.00, 6.8, -1.8,
         4.00, 6.8, -1.8,
         4.20, 6.8, -1.8,
         4.20, 6.8, -1.5,
         4.20, 6.2, -1.8, //side left
         4.20, 6.2, -1.5,
         4.20, 6.8, -1.5,
         4.20, 6.8, -1.5,
         4.20, 6.8, -1.8,
         4.20, 6.2, -1.8,
         4.00, 6.2, -1.8, //side right
         4.00, 6.2, -1.5,
         4.00, 6.8, -1.5,
         4.00, 6.8, -1.5,
         4.00, 6.8, -1.8,
         4.00, 6.2, -1.8,
         

    };

    if(this->num == 0)
    {
        this->object = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, COLOR_RED, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data1, COLOR_RED, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 360*3, vertex_buffer_data2, COLOR_LAWNGREEN, GL_FILL);
        this->object3 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_dataHeadLeft, COLOR_BLACK, GL_FILL);
        this->object4 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_dataHeadRight, COLOR_BLACK, GL_FILL);

        this->health = 1;
    }
    if(this->num == 1)
    {
        this->object = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data3, COLOR_INDIANRED, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data4, COLOR_RED, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data5, COLOR_DRED, GL_FILL);
        this->object3 = create3DObject(GL_TRIANGLES, 144, vertex_buffer_data6, COLOR_GREY, GL_FILL);
        //this->object4 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data7, COLOR_GREY, GL_FILL);
        this->health = 2;
    }
    if(this->num == 2)
    {
        this->object = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data8, COLOR_RED, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 72, vertex_buffer_data9, COLOR_DRED, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 144, vertex_buffer_dataEye, COLOR_BLACK, GL_FILL);
        this->object3 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_dataHeadLeft, COLOR_BLACK, GL_FILL);
        this->object4 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_dataHeadRight, COLOR_BLACK, GL_FILL);


        this->health = 3;
    }
    if(this->num == 3)
    {
        this->object = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data10, COLOR_BLACK, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 144, vertex_buffer_data11, COLOR_DRED, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 144, vertex_buffer_data12, COLOR_DRED, GL_FILL);
        this->object3 = create3DObject(GL_TRIANGLES, 144, vertex_buffer_dataMonsterEye, COLOR_DRED, GL_FILL);

        
        this->health = 4;
    }

}


void Monster::draw(glm::mat4 VP) {
    this->rotation+=3.0;
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0,1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    //rotate          = rotate * glm::translate(glm::vec3(0, -3, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(this->num == 0){
            draw3DObject(this->object);
            draw3DObject(this->object1);
            draw3DObject(this->object2);
            draw3DObject(this->object3);
            draw3DObject(this->object4);

        }
    else if(this->num == 1){
            draw3DObject(this->object);
            draw3DObject(this->object1);
            draw3DObject(this->object2);    
            draw3DObject(this->object3);
            //draw3DObject(this->object4);
    }    
    else if(this->num == 2)
    {
        draw3DObject(this->object);
        draw3DObject(this->object1);
        draw3DObject(this->object2);
        draw3DObject(this->object3);
        draw3DObject(this->object4);


    }
    else if(this->num == 3)
    {
      draw3DObject(this->object);
      draw3DObject(this->object1);
      draw3DObject(this->object2);
      draw3DObject(this->object3);
    }
        // draw3DObject(this->object);
        // draw3DObject(this->object1);
        
    
}

void Monster::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Monster::tick() {
	this->position.y = this->position.y + this->speed;
	this->speed = this->speed + this->accy;
	if(this->position.y<0 && this->position.y>-5 && this->num == 3)
  {
    this->position.y = 0;
    this->speed = 0.2;
  }
  if(this->position.y<0 && this->position.y>-5 && this->num!=3)
	{
		this->position.y = 0;
		this->speed = 0.05;
	}
  if(this->num == 3)
  {
    this->position.x+=this->speedx;
    this->position.z+=this->speedz;
    if(this->position.x>=1000 || this->position.x<=-1000)
    {
      this->speedx = -1*this->speedx;
    }
    if(this->position.z>=1000 || this->position.z<=-1000)
    {
      this->speedz = -1*this->speedz;
    }
  }
    //this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}


