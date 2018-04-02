#include "main.h"

// #ifndef Fireball_H
// #define Fireball_H


class Fireball {
public:
    Fireball() {}
    Fireball(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    float sizeOfFireball;
    float accy;
    float speedx, speedy,speedz;
    void draw(glm::mat4 VP);
    void set_position(float x,float y, float z);
    void tick();
private:
    VAO *object;
};

Fireball::Fireball(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->accy = -0.02f;
    this->speedx = this->speedy = this->speedz = 0.0f;
    float a,b,c,k;
    float r = 1;
    int idx = 0;

    GLfloat vertex_buffer_data[18*181*361 + 100];
    for(int i=0;i<=360;i++)
    {
        for(int j=0;j<=180;j++)
        {
            c=r*cos(M_PI*j/180);
            a=r*sin(M_PI*j/180)*cos(M_PI*i/180);
            b=r*sin(M_PI*j/180)*sin(M_PI*i/180);
            vertex_buffer_data[idx++]=r*sin(M_PI*j/180)*cos(M_PI*(i+1)/180);
            vertex_buffer_data[idx++]=r*sin(M_PI*j/180)*sin(M_PI*(i+1)/180);
            vertex_buffer_data[idx++]=r*cos(M_PI*j/180);
            vertex_buffer_data[idx++]=a;
            vertex_buffer_data[idx++]=b;
            vertex_buffer_data[idx++]=c;
            k=j+1;
            c=r*cos(M_PI*k/180);
            a=r*sin(M_PI*k/180)*cos(M_PI*i/180);
            b=r*sin(M_PI*k/180)*sin(M_PI*i/180);
            vertex_buffer_data[idx++]=a;
            vertex_buffer_data[idx++]=b;
            vertex_buffer_data[idx++]=c;
        }
    }
    for(int i=0;i<=360;i++)
    {
        for(int j=0;j<=180;j++)
        {
            c=r*cos(M_PI*(j+1)/180);
            a=r*sin(M_PI*(j+1)/180)*cos(M_PI*(i+1)/180);
            b=r*sin(M_PI*(j+1)/180)*sin(M_PI*(i+1)/180);
            vertex_buffer_data[idx++]=r*sin(M_PI*j/180)*cos(M_PI*(i+1)/180);
            vertex_buffer_data[idx++]=r*sin(M_PI*j/180)*sin(M_PI*(i+1)/180);
            vertex_buffer_data[idx++]=r*cos(M_PI*j/180);
            vertex_buffer_data[idx++]=a;
            vertex_buffer_data[idx++]=b;
            vertex_buffer_data[idx++]=c;
            k=j+1;
            c=r*cos(M_PI*k/180);
            a=r*sin(M_PI*k/180)*cos(M_PI*i/180);
            b=r*sin(M_PI*k/180)*sin(M_PI*i/180);
            vertex_buffer_data[idx++]=a;
            vertex_buffer_data[idx++]=b;
            vertex_buffer_data[idx++]=c;
        }
    }

    this->object = create3DObject(GL_TRIANGLES,idx/3, vertex_buffer_data,COLOR_DRED, GL_FILL);
    printf("Created fireball\n");
}


void Fireball::draw(glm::mat4 VP) {
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

void Fireball::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Fireball::tick() {
    if (this->position.y < -10)
        return;
    this->speedy += this->accy;
    this->position.x += this->speedx;
    this->position.y += this->speedy;
    this->position.z += this->speedz;
    //this->rotation += speed;
    // this->position.x += this->speed;
    // this->position.z += 0.0005;
    // // this->position.y -= speed;
}
