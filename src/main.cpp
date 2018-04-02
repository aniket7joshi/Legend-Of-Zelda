#include "main.h"
#include "timer.h"
#include "boat.h"
#include "water.h"
#include "rock.h"
#include "barrel.h"
#include "booster.h"
#include "monster.h"
#include "fireball.h"
#include "sail.h"
using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Boat boat;
Water water;
Sail sail;
vector <Rock> rock; 
vector <Barrel> barrel;
vector <Monster> monster;
vector <Booster> booster;
Fireball fireball;
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
int camview = 4;
int boostStart = 0;
int monsterFlag = 0;
float windAngle = -180;
int numberOfMonstersKilled = 0;
int passedTime = 0;
bool drag = false;
double cxpos, pxpos, cypos, pypos;
Timer t60(1.0 / 60);
glm::vec3 helcamEye = glm::vec3(0, 60.0f, -20.0f);
glm::vec3 helcamTarget = glm::vec3(0, 1.0f, 0.0f);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
float randomfInRange(float LO, float HI) {
    return LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
}
void dispScore(){
    string e = "Boat | Health: ";
    string s = to_string(boat.health);
    string p = "  Points: ";
    string l = to_string(boat.points);
    s = e+s+p+l;
    glfwSetWindowTitle(window, const_cast<char*>(s.c_str()));
}
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    //glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    // glm::vec3 eye(0,0,0);
    // glm::vec3 target(0,0,0);
    // glm::vec3 up(0,0,0);
    // printf("camview is %d\n",camview);
    if(camview == 0)
    {
        glm::vec3 eye(0,15,20);
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (0, 0, 0);
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (0, 1, 0);
        Matrices.view = glm::lookAt( eye, target, up );
    }
    else if(camview == 1)
    {
        glm::vec3 eye(boat.position.x - 3.5*sin(boat.rotation*M_PI/180),0.5,boat.position.z-3.5*cos(boat.rotation*M_PI/180));
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (boat.position.x - 10*sin(boat.rotation*M_PI/180), boat.position.y + 0.5, boat.position.z - 10*cos(boat.rotation*M_PI/180));
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (0, 1, 0);
           
        Matrices.view = glm::lookAt( eye, target, up );
    }
    else if(camview == 2)  //Top View
    {
        glm::vec3 eye(boat.position.x,boat.position.y + 200 ,boat.position.z);
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (boat.position.x, boat.position.y, boat.position.z);
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (0, 0, -1);
        Matrices.view = glm::lookAt( eye, target, up );   
    }
    else if(camview == 3) //Tower View
    {
        glm::vec3 eye(-10,50,20);
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (boat.position.x, boat.position.y, boat.position.z);

        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (0, 1, 0);
        Matrices.view = glm::lookAt( eye, target, up );   
    }
    else if(camview == 4) //FollowCam View
    {
        glm::vec3 eye(boat.position.x +  20*sin(boat.rotation*M_PI/180), 10, boat.position.z + 20*cos(boat.rotation*M_PI/180));
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (boat.position.x - 15*sin(boat.rotation*M_PI/180), 0.0, boat.position.z - 15*cos(boat.rotation*M_PI/180));
        
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (0, 1, 0);
        Matrices.view = glm::lookAt( eye, target, up );   
    }
    else if(camview == 5)
    {
        // glm::vec3 eye(0,50.0, -15.0);
        // // Target - Where is the camera looking at.  Don't change unless you are sure!!
        // glm::vec3 target (0, 1.0, 0);
        // // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (0, 1, 0);
        Matrices.view = glm::lookAt( helcamEye, helcamTarget, up );
    }
    
    // Compute Camera matrix (view)
     // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (Backgroundsic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    
    //ball.draw(VP);

    boat.draw(VP);
    for(int i = 0;i<rock.size();i++)
        rock[i].draw(VP);
    for(int i = 0;i<barrel.size();i++)
        barrel[i].draw(VP);
    for(int i = 0;i<monster.size();i++)
        monster[i].draw(VP);
    fireball.draw(VP);
    for(int i = 0;i<booster.size();i++)
        booster[i].draw(VP);
    //sail.set_position(boat.position.x, boat.position.y, boat.position.z);
    
    sail.draw(VP, windAngle, boat.rotation);
    water.draw(VP);
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int cam1 = glfwGetKey(window, GLFW_KEY_1);
    int cam2 = glfwGetKey(window, GLFW_KEY_2);
    int cam3 = glfwGetKey(window, GLFW_KEY_3);
    int cam4 = glfwGetKey(window, GLFW_KEY_4);
    int cam5 = glfwGetKey(window, GLFW_KEY_5);
    int space = glfwGetKey(window, GLFW_KEY_SPACE);
    int shoot = glfwGetKey(window, GLFW_KEY_F);

    double deltax, deltay;

    glfwGetCursorPos(window, &cxpos, &cypos);

    if (cam1){
        camview = 1;
    }
    if (cam2){
        camview = 2;
    }
    if (cam3){
        camview = 3;
    }
    if (cam4){
        camview = 4;
    }
    if (cam5){
        camview = 5;
    }
    if(camview == 5 && drag){
        float dragx = ((float)cxpos - (float)pxpos)/10;
        float dragy = ((float)cypos - (float)pypos)/10;

        glm::vec3 delta = helcamTarget - helcamEye;
        glm::vec3 l;
        l.x += delta.x/sqrt(delta.x*delta.x + delta.y*delta.y + delta.z*delta.z);
        l.y += delta.y/sqrt(delta.x*delta.x + delta.y*delta.y + delta.z*delta.z);
        l.z += delta.z/sqrt(delta.x*delta.x + delta.y*delta.y + delta.z*delta.z);

        float coss = l.z/sqrt(l.x*l.x + l.z*l.z);
        float sinn = l.x/sqrt(l.x*l.x + l.z*l.z);

        helcamTarget.x += dragy*sinn;
        helcamTarget.z += dragy*coss;

        helcamTarget.x += dragx*coss;
        helcamTarget.z -= dragx*sinn;
    }
    pxpos = cxpos;
    pypos = cypos;
    if (up) 
    {
        if(boat.boost == 0)
        {
            if(boat.speed<1.5)
            {
                //boat.speed = 0.5;
                boat.acc = 0.01;
            }
            // boat.position.x = boat.position.x - 1*sin(boat.rotation*M_PI/180);
            // boat.position.z = boat.position.z - 1*cos(boat.rotation*M_PI/180);
            
        }
        else if(boat.boost == 1)
        {
            cout <<"boost";
            //boat.position.x = boat.position.x - 3*sin(boat.rotation*M_PI/180);
            //boat.position.z = boat.position.z - 3*cos(boat.rotation*M_PI/180);
            if(boat.speed < 3)
            {
                //boat.speed = 1;
                boat.acc = 0.1;
            }    
        }
    }
    if (down) {
        boat.acc = -0.01;
    }
    if(!up && !down && windAngle!=0)
    {
        boat.acc = -0.008;
    }
    if (right) {
        boat.rotation -=0.5;
    }if (left) {
        boat.rotation += 0.5;

    }
    if(space && boat.position.y <= 0.3){
        boat.speedy = 0.4;
        boat.accy = -0.03;
        boat.jump = 1;
    }
    if (shoot){
        if (fireball.position.y <0)
        {
            fireball.position.y = boat.position.y + 3.75;
            fireball.position.x = boat.position.x; 
            fireball.position.z = boat.position.z; 
            if(boat.boost == 0)
            {
                fireball.speedy = 0.3;
                fireball.speedx = -3.0f*sin((boat.rotation)*M_PI/180.0f);
                fireball.speedz = -3.0f*cos((boat.rotation)*M_PI/180.0f);
            }
            else if(boat.boost == 1)
            {
                fireball.speedy = 0.3;
                fireball.speedx = -9.0f*sin((boat.rotation)*M_PI/180.0f);
                fireball.speedz = -9.0f*cos((boat.rotation)*M_PI/180.0f);
            }
        }
    }
}
bool CollisionRock(int i)
{
    Rock r = rock[i];
    int diff = 0.1;
    float zcorr = boat.position.z ;
    float xcorr = boat.position.x ;
    if(xcorr>=r.position.x - r.sizeOfRock/2 - 1 && xcorr<=r.position.x + r.sizeOfRock/2 + 1)
    {
        if(zcorr>=r.position.z - r.sizeOfRock/2 - 1 && zcorr<=r.position.z + r.sizeOfRock/2 + 1)
        {
            return 1;
        }
    }
    return 0;

}

void tick_elements() {
    boat.tick(windAngle);
    for(int i = 0;i<rock.size();i++)
    {
        int val = CollisionRock(i);
        if(val == 1)
        {
            rock[i].position.x = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
            rock[i].position.z = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
            boat.health-=1;
            cout<<"health = "<<boat.health << endl;
            
            break;
        }
    }
    for(int i = 0;i<barrel.size();i++)
    {
        barrel[i].tick();
        if (abs(boat.position.x - barrel[i].position.x) < 3.5 && abs(boat.position.z - barrel[i].position.z) < 7 && boat.position.y > 0.0f && boat.jump == 1)
        {
            if (barrel[i].num == 2)
                boat.points+=50;
            else if (barrel[i].num == 1)
                boat.points+=40;
            else
                boat.points+=30;
            barrel[i].position.x = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
            barrel[i].position.y = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
            cout <<"points = " << boat.points << endl;
            break;
        }
    }
    fireball.tick();
    for(int i = 0;i<100;i++)
    {
        if (abs(fireball.position.x - monster[i].position.x) < 2 && abs(fireball.position.y - monster[i].position.y) < 6 && fireball.position.y>0 && abs(fireball.position.z - monster[i].position.z) < 2)
        {
            numberOfMonstersKilled++;
            if(numberOfMonstersKilled%5 == 0)
            {
                monsterFlag = 1;
            }
            Booster b;
            b = Booster(monster[i].position.x, 0.0, monster[i].position.z,0);
            booster.push_back(b);
            monster[i].position.z = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
            monster[i].position.x = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
            
            printf("Monster killed\n");
            break;
        }          
    }
    for(int i = 100;i<monster.size();i++)
    {
        if (abs(fireball.position.x - monster[i].position.x) < 2 && abs(fireball.position.y - monster[i].position.y) < 6 && fireball.position.y>0 && abs(fireball.position.z - monster[i].position.z) < 2)
        {
            monster[i].numberOfTimesHit++;
            if(monster[i].numberOfTimesHit>=3)
            {
                monster[i].position.y = -100;
                for(int j = 0;j<5;j++)
                {
                    Booster b;
                    float posx = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
                    float posz = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
                    if(j == 0)
                        b = Booster(monster[i].position.x, 0.0, monster[i].position.z,1);
                    else
                        b = Booster(posx,0.0,posz,1);
                    booster.push_back(b);
                }
                break;
            }
        }
    }
    if(numberOfMonstersKilled%5 == 0 && monsterFlag == 1)
    {
        printf("Made\n");
        for(int i = 0;i<10;i++)
        {
            Monster m;
            float posx = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
            float posz = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
            m = Monster(posx, 0.0, posz, 3);
            printf("posx is %f and posz is %f",posx,posz);
            monster.push_back(m);
            printf("haha\n");
            int x = monster.size();
            printf("%d\n",x);
        }   
    }
    for(int i = 0 ;i<monster.size();i++)
    {
        monster[i].tick();

        if (abs(boat.position.x - monster[i].position.x) < 3.5 && abs(boat.position.y - monster[i].position.y) < 3 && boat.position.y>=0 && abs(boat.position.z - monster[i].position.z) < 6)   
        {
            monster[i].position.z = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
            monster[i].position.x = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
            boat.health = boat.health - monster[i].health;
            printf("health = %d\n",boat.health);
            break;
        }
    }
    monsterFlag = 0;
    for(int i = 0;i<booster.size();i++)
    {
        if (abs(booster[i].position.x - boat.position.x) < 3.75 && abs(booster[i].position.y - boat.position.y) < 2 && booster[i].position.y>=0 && abs(booster[i].position.z - boat.position.z) < 3.75)
        {
            if(booster[i].flag == 1)
            {    
                booster[i].position.y = -100;
                boat.boost = 1;
                boostStart = 0;
                break;
            }
            else
            {
                boat.health+=1;
                booster[i].position.y = -100;
            }
        }
    }
    boostStart++;
    if(boostStart >= 300)
    {
        boat.boost = 0;
        boostStart = 0;
    }
    if(boat.health<=0)
    {
        exit(0);
    }
    sail.tick(boat.position);
}
    //camera_rotation_angle += 1;


/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    boat  = Boat(0, 0,0, COLOR_RED);
    water = Water(0,0,COLOR_AQUA);
    fireball = Fireball(10,-20,-10);
    sail = Sail(boat.position.x, boat.position.y, boat.position.z);
    int numberOfRocksClose = 0;
    for (int i = 0; i < 1000; ++i) 
    {
        float posx = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
        float posz = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
        float SLO = 5;
        float SHI = 8;
        float sizeOfRock = 5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(3)));

        while(abs(posx) < 10)
            posx = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
        while(abs(posz) < 10)
            posz = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
        Rock r;
        if(i%3 == 0)
            r = Rock(posx,0.0, posz, sizeOfRock,COLOR_BROWN);
        if(i%3 == 1)
            r = Rock(posx,0.0, posz, sizeOfRock,COLOR_CHOCOLATE);
        if(i%3 == 2)
            r = Rock(posx,0.0, posz, sizeOfRock,COLOR_GOLDENROD);
        rock.push_back(r);
    }
    for (int i = 0; i < 500;i++)
    {
        int num = i%3;
        float posx = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
        float posz = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
        while(abs(posx) < 10)
            posx = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
        while(abs(posz) < 10)
            posz = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
        Barrel b;
        b = Barrel(posx, 0.0, posz, num);
        barrel.push_back(b);
    }
    for (int i = 0; i < 100;i++)
    {
        //int num = i%3;
        float posx = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
        float posz = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
        while(abs(posx) < 10)
            posx = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
        while(abs(posz) < 10)
            posz = -1000 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2000)));
        Monster m;
        m = Monster(posx, 0.0, posz, (i%3));
        monster.push_back(m);
    }
    //ball = Ball(0,0,COLOR_CORNSILK);
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");
    Matrices.trans = glGetUniformLocation(programID, "tr"); 


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    audio_init();
    while (!glfwWindowShouldClose(window)) {
        // Process timers
        audio_play();
        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
            dispScore();
            passedTime++;
            if(passedTime == 300)
            {
                windAngle = -90 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(180)));
            }
            if(passedTime>300)
            {
                passedTime = 0;
                windAngle = 0;
            }
            
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}


bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::perspective(1.0f, 1.0f, 1.0f, 500.0f);
}

void dragS() {
    drag = true;
}

void dragE() {
    drag = false;
}
void scroll_call(double x_scroll, double y_scroll){
    glm::vec3 delta = helcamTarget - helcamEye;
    helcamEye.x += (y_scroll)*delta.x/sqrt(delta.x*delta.x + delta.y*delta.y + delta.z*delta.z);
    helcamEye.y += (y_scroll)*delta.y/sqrt(delta.x*delta.x + delta.y*delta.y + delta.z*delta.z);
    helcamEye.z += (y_scroll)*delta.z/sqrt(delta.x*delta.x + delta.y*delta.y + delta.z*delta.z);
}