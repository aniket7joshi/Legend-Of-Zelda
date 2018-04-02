#include "main.h"

#ifndef Boat_H
#define Boat_H


class Boat {
public:
    Boat() {}
    Boat(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    float speedy;
    float speed;
    float acc;
    int points;
    float accy;
    int jump;
    int health;
    int boost;
    float cannon_roty;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick(float wind_angle);
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
    VAO *object7;
    VAO *object8;

};

Boat::Boat(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0;
    this->speedy = 0.02;
    this->boost = 0;
    this->speed = 0;
    this->jump = 0;
    this->acc = 0;
    this->accy = -0.001;
    this->points = 0;
    this->health = 20;
    this->cannon_roty = 45.0f;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        0.5, 0.0, -3,          //Right side Trapezium
        1, 1.5, -3.5,
        0.5, 0.0, 3,
        0.5, 0.0, 3,
        1, 1.5, -3.5,
        1, 1.5, 3.5,

     	-0.5, 0.0, -3,          //Left side Trapezium
        -1, 1.5, -3.5,
        -0.5, 0.0, 3,
        -0.5, 0.0, 3,
        -1, 1.5, -3.5,
        -1, 1.5, 3.5,

	};

	static const GLfloat vertex_buffer_data1[] = {
     	-0.5, 0.0, -3,          //Bottom Rectangle
        -0.5, 0.0, 3,
         0.5, 0.0, -3,
         0.5, 0.0, -3,
        -0.5, 0.0, 3,
        0.5, 0.0, 3,
    };

    static const GLfloat vertex_buffer_data2[] = {
		0.5, 0.0, -3,          //Front side trapezium for pentagon
		1, 1.5, -3.5,
        -1, 1.5, -3.5,
        -1, 1.5, -3.5,
		-0.5, 0.0, -3,
		0.5, 0.0, -3,        
        1, 1.5, -3.5,			//Triangle in front
        -1, 1.5, -3.5,
        0, 3, -3,
        // 0.5, 0.0, 2,
        // 0.5, 0.0, 2,
        // 1, 1.5, -2.5,
        // 1, 1.5, 2.5,

  		0.5, 0.0, 3,          //Back side trapezium
        1, 1.5, 3.5,
        -1, 1.5, 3.5,
        -1, 1.5, 3.5,
		-0.5, 0.0, 3,
		0.5, 0.0, 3,

	};
	static GLfloat vertex_buffer_data3[9*180];
	double pi =3.1415926535897;
    double r = 1;
    double theta = 0;
    int j = 0;
    for(int i = 0;i<180;i++)
    {
        vertex_buffer_data3[9 * i] = 0;
        vertex_buffer_data3[9 * i + 1] = 1.5;
        vertex_buffer_data3[9 * i + 2] = 3.5;
        vertex_buffer_data3[9 * i + 3] = r * cos(((theta) * pi) / 180);
        vertex_buffer_data3[9 * i + 4] = 1.5 + r * sin(((theta) * pi) / 180);
        vertex_buffer_data3[9 * i + 5] = 3.5;
        vertex_buffer_data3[9 * i + 6] = r * cos(((theta + 1) * pi) / 180);
        vertex_buffer_data3[9 * i + 7] = 1.5 + r * sin(((theta + 1) * pi) / 180);
        vertex_buffer_data3[9 * i + 8] = 3.5;
        theta = theta + 1;
    }

    

	static const GLfloat vertex_buffer_data6[] = {
    	-0.2, 0.0,-1.5,         //Cannon  The vertical cuboid
    	 0.2, 0.0,-1.5,
    	 0.2, 4.0,-1.5,
    	 0.2, 4.0,-1.5,         
    	-0.2, 4.0,-1.5,
    	-0.2, 0.0,-1.5,
		-0.2, 0.0,-1.9,         
    	 0.2, 0.0,-1.9,
    	 0.2, 4.0,-1.9,
    	 0.2, 4.0,-1.9,         
    	-0.2, 4.0,-1.9,
    	-0.2, 0.0,-1.9,
    	-0.2, 0.0,-1.5,
    	-0.2, 0.0,-1.9,         
    	-0.2, 4.0,-1.9,         
    	-0.2, 4.0,-1.9,         
    	-0.2, 4.0,-1.5,         
    	-0.2, 0.0,-1.5,
    	 0.2, 0.0,-1.5,
    	 0.2, 0.0,-1.9,         
    	 0.2, 4.0,-1.9,         
    	 0.2, 4.0,-1.9,         
    	 0.2, 4.0,-1.5,         
    	 0.2, 0.0,-1.5,         
    	 0.2, 4.0,-1.5,         //Horizontal Cuboid
    	 1.3, 4.0,-1.5,		
    	 1.3, 3.5,-1.5,		
    	 1.3, 3.5,-1.5,
    	 0.2, 3.5,-1.5,
    	 0.2, 4.0,-1.5,		
		 0.2, 4.0,-1.9,         
    	 1.3, 4.0,-1.9,		
    	 1.3, 3.5,-1.9,		
    	 1.3, 3.5,-1.9,
    	 0.2, 3.5,-1.9,
    	 0.2, 4.0,-1.9,
    	 1.3, 4.0,-1.9,
    	 1.3, 3.5,-1.9,
    	 1.3, 4.0,-1.5,
    	 1.3, 4.0,-1.5,
    	 1.3, 3.5,-1.5,
    	 1.3, 3.5,-1.9,
    	 0.2, 4.0,-1.5,
    	 0.2, 4.0,-1.9,
    	 1.3, 4.0,-1.9,
    	 1.3, 4.0,-1.9,
    	 1.3, 4.0,-1.5,
    	 0.2, 4.0,-1.5,

	};

	static GLfloat vertex_buffer_data7[9*360];
	pi =3.1415926535897;
	r = 0.22;
	theta = 0;
    j = 0;
    for(int i = 0;i<360;i++)
    {
        vertex_buffer_data7[9 * i] = 0.7;
        vertex_buffer_data7[9 * i + 1] = 3.75;
        vertex_buffer_data7[9 * i + 2] = -1.5;
        vertex_buffer_data7[9 * i + 3] = r * cos(((theta) * pi) / 180) + 0.7;
        vertex_buffer_data7[9 * i + 4] = 3.75 + r * sin(((theta) * pi) / 180);
        vertex_buffer_data7[9 * i + 5] = -1.5;
        vertex_buffer_data7[9 * i + 6] = r * cos(((theta + 1) * pi) / 180) + 0.7;
        vertex_buffer_data7[9 * i + 7] = 3.75 + r * sin(((theta + 1) * pi) / 180);
        vertex_buffer_data7[9 * i + 8] = -1.5;
        theta = theta + 1;
    }
    static GLfloat vertex_buffer_data8[9*360];
	pi =3.1415926535897;
	r = 0.22;
	theta = 0;
    j = 0;
    for(int i = 0;i<360;i++)
    {
        vertex_buffer_data8[9 * i] = 0.7;
        vertex_buffer_data8[9 * i + 1] = 3.75;
        vertex_buffer_data8[9 * i + 2] = -1.9;
        vertex_buffer_data8[9 * i + 3] = r * cos(((theta) * pi) / 180) + 0.7;
        vertex_buffer_data8[9 * i + 4] = 3.75 + r * sin(((theta) * pi) / 180);
        vertex_buffer_data8[9 * i + 5] = -1.9;
        vertex_buffer_data8[9 * i + 6] = r * cos(((theta + 1) * pi) / 180) + 0.7;
        vertex_buffer_data8[9 * i + 7] = 3.75 + r * sin(((theta + 1) * pi) / 180);
        vertex_buffer_data8[9 * i + 8] = -1.9;
        theta = theta + 1;
    }


    this->object = create3DObject(GL_TRIANGLES, 12 , vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 6 , vertex_buffer_data1, COLOR_GREEN, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 15 , vertex_buffer_data2, COLOR_BROWN, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 180*3 , vertex_buffer_data3, COLOR_BROWN, GL_FILL);
    //this->object4 = create3DObject(GL_TRIANGLES, 6 , vertex_buffer_data4, COLOR_LIGHTSEAGREEN, GL_FILL);
    //this->object5 = create3DObject(GL_TRIANGLES, 9 , vertex_buffer_data5, COLOR_GREY, GL_FILL);
    this->object6 = create3DObject(GL_TRIANGLES, 48 , vertex_buffer_data6, COLOR_BLACK, GL_FILL);
    this->object7 = create3DObject(GL_TRIANGLES, 360*3 , vertex_buffer_data7, COLOR_DARKORANGE, GL_FILL);
    this->object8 = create3DObject(GL_TRIANGLES, 360*3 , vertex_buffer_data8, COLOR_DARKORANGE, GL_FILL);

}

void Boat::draw(glm::mat4 VP) {
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
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    //draw3DObject(this->object4);
    //draw3DObject(this->object5);
    draw3DObject(this->object6);
    draw3DObject(this->object7);
    draw3DObject(this->object8);


}

void Boat::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Boat::tick(float wind_angle) {
    wind_angle += 180.0f;
    float brot = this->rotation + 180.0f;
    if (cos((wind_angle - brot) * M_PI / 180.0f) > 0) 
    {
        this->acc = this->acc + 0.005 * (float) cos((wind_angle - brot) * M_PI / 180.0f);
    }
    //this->rotation += speed;
    // this->position.x -= speed;
    this->position.y += this->speedy;
    this->speedy = this->speedy + this->accy;
    if(this->position.y<=0.0)
    {
        this->jump = 0;
    	this->position.y = 0;
    	this->speedy = 0.05;
    	this->accy = -0.004;
    }
    this->speed += this->acc;
    this->position.x = this->position.x - this->speed*sin(this->rotation*M_PI/180);
    this->position.z = this->position.z - this->speed*cos(this->rotation*M_PI/180);
    if(this->speed < 0)
    {
        this->speed = 0;
    }
    if(this->speed>1.5 && this->boost == 0)
    {
        this->speed = 1.5;  
    }
    if(this->speed>3 && this->boost == 1)
    {
        this->speed = 3;
    }

}
#endif