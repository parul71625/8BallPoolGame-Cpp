#ifndef POOLGAME_H
#define POOLGAME_H

#include "Utilities\glew\glew.h"
#include "Utilities\glm\glm.hpp"

class ball{
private:
	int slices;
	int stacks;
public:
	glm::vec3 *vertex;
	int vertexNum;
	glm::vec3 *normal;
	glm::vec2 *texcoord;

	ball(int slc, int stk);
	void ballMesh();
};

class table{
public:
	float length;
	float width;
	float height;
	int vertexNum;
	glm::vec3 *vertex;
	glm::vec3 *normal;
	glm::vec3 *points;
	int id;
	glm::vec2 *texcoord;
	glm::vec2 tex[4];
	table(float l, float w, float h);
	void quad(int a, int b, int c, int d);
	void tableMesh();

};


GLuint setVBO(glm::vec3 *points, glm::vec3 *normal, glm::vec2 *texcoord, int vertexNum);



void initBallPos(glm::vec3 *pos, float diameter);

class setShotVelocity
{
public:
	int last_mx;
	int last_my;
	int cur_mx;
	int cur_my;
	int tracking;
	int ballID;
	glm::vec3 velocity;
	glm::vec3 angVel;

	void setVelocity();
};

class ballPhysics
{
public:
	glm::vec3 ballPos[16];
	glm::mat4 translate[16];
	glm::mat4 rotate[16];
	glm::vec3 ballVel[16];
	glm::vec3 ballAngVel[16];
	glm::vec3 pocket[6];

	float ratio;
	float m = 0.5; // kg
	float k = 10; // kg.m/s^2
	float dt = 0.001; // s
	float g = 9.8; // m/s^2
	float mus = 0.5;
	float mur = 0.01;
	float dv = -mus*g*dt;
	float dw = 2.5*dv;
	float wall;

	void setInitBallPos();
	void setInitVelocity();
	void setPocketCenter();
	void collisionWall(int i);
	void collisionBall(int i, int j);
	void pocketTest(int i);

};

#endif