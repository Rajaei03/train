/*
 *		This Code Was Created By Jeff Molofee 2000
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing This Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
 */

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "texture.h"
#include <cmath>
#include <camera.h>
#include <stdlib.h>
#include <stdio.h>
#include <3DTexture.h>
#include <math3d.h>
#include <Model_3DS.h>


HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Context
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

int size =200;
bool col = false;


class skyBox{
public : 
	int ccX,ccY,ccZ;
	int ymen,ysar,edam,wra,fo2,t7t;


	

public :
	skyBox(int cX,int cY,int cZ,int ymen,int ysar,int edam,int wra,int fo2,int t7t,bool first,bool last){
	ccX=cX;
	ccY=cY;
	ccZ=cZ;
	glColor4f(1.0f,1.0f,1.0f,1.0f);

	//----------------------------------------------------wra-------------------------------------------------------------------

	glBindTexture(GL_TEXTURE_2D,wra); //4



	if(!first){
	glBegin(GL_QUADS); //ysar
	
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-size+cX,-size+cY, size+cZ);
	
	glTexCoord2f(0.4f,0.0f);
	glVertex3f(-size/5+cX, -size+cY, size+cZ);
	
	glTexCoord2f(0.4f,1.0f);
	glVertex3f(-size/5+cX,size+cY, size+cZ);

	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-size+cX,size+cY,size+cZ);
	


	glEnd();

	glBegin(GL_QUADS); //ymen
	
	
	glTexCoord2f(0.6f,0.0f);//0,0
	glVertex3f(size/5+cX,-size+cY, size+cZ);
	
	glTexCoord2f(1.0f,0.0f);//0.4,0
	glVertex3f(size+cX, -size+cY, size+cZ);
	
	glTexCoord2f(1.0f,1.0f);//0.4,1
	glVertex3f(size+cX,size+cY, size+cZ);

	glTexCoord2f(0.6f,1.0f);//0,1
	glVertex3f(size/5+cX,size+cY,size+cZ);
	


	glEnd();


	glBegin(GL_QUADS); //n9
	
	
	glTexCoord2f(0.4f,0.375f);
	glVertex3f(-size/5+cX,-size/4+cY, size+cZ);
	
	glTexCoord2f(0.6f,0.375f);
	glVertex3f(+size/5+cX, -size/4+cY, size+cZ);
	
	glTexCoord2f(0.6f,1.0f);
	glVertex3f(size/5+cX,size+cY, size+cZ);

	glTexCoord2f(0.4f,1.0f);
	glVertex3f(-size/5+cX,size+cY,size+cZ);
	


	glEnd();
	}else{
		glBegin(GL_QUADS); 
	
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-size+cX,-size+cY, size+cZ);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(size+cX, -size+cY, size+cZ);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(size+cX,size+cY, size+cZ);

	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-size+cX,size+cY,size+cZ);

	glEnd();

	}




	//----------------------------------------------ysar----------------------------------------------------------------------

	glBindTexture(GL_TEXTURE_2D,ysar);//2




	glBegin(GL_QUADS); 
	
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(-size+cX,-size+cY, size+cZ);
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-size+cX, -size+cY, -size+cZ);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-size+cX,size+cY, -size+cZ);
	

	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-size+cX,size+cY,size+cZ);
	


	glEnd();


	//----------------------------------------------2dam----------------------------------------------------------------------

	glBindTexture(GL_TEXTURE_2D,edam);//1



	if(!last){
	glBegin(GL_QUADS); //ysar
	
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(-size+cX,-size+cY, -size+cZ);
	
	glTexCoord2f(0.6f,0.0f);
	glVertex3f(-size/5+cX, -size+cY, -size+cZ);
	
	glTexCoord2f(0.6f,1.0f);
	glVertex3f(-size/5+cX,size+cY, -size+cZ);

	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-size+cX,size+cY,-size+cZ);
	


	glEnd();

	glBegin(GL_QUADS); //ymen
	
	
	glTexCoord2f(0.4f,0.0f);
	glVertex3f(size/5+cX,-size+cY, -size+cZ);
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(size+cX, -size+cY, -size+cZ);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(size+cX,size+cY, -size+cZ);

	glTexCoord2f(0.4f,1.0f);
	glVertex3f(size/5+cX,size+cY,-size+cZ);
	


	glEnd();


	glBegin(GL_QUADS); //n9
	
	
	glTexCoord2f(0.6f,0.375f);
	glVertex3f(-size/5+cX,-size/4+cY, -size+cZ);
	
	glTexCoord2f(0.4f,0.375f);
	glVertex3f(+size/5+cX, -size/4+cY, -size+cZ);
	
	glTexCoord2f(0.4f,1.0f);
	glVertex3f(size/5+cX,size+cY, -size+cZ);

	glTexCoord2f(0.6f,1.0f);
	glVertex3f(-size/5+cX,size+cY,-size+cZ);
	


	glEnd();
	}else{
		glBegin(GL_QUADS); //ysar

		glTexCoord2f(1.0f,0.0f);
		glVertex3f(-size+cX,-size+cY, -size+cZ);
	
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(size+cX, -size+cY, -size+cZ);
	
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(size+cX,size+cY, -size+cZ);

		glTexCoord2f(1.0f,1.0f);
		glVertex3f(-size+cX,size+cY,-size+cZ);
	


	glEnd();
	}



	


	//----------------------------------------------ymen----------------------------------------------------------------------
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,ymen);//5




	glBegin(GL_QUADS); 
	
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(size+cX,-size+cY, -size+cZ);
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(size+cX, -size+cY, size+cZ);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(size+cX,size+cY, size+cZ);
	

	glTexCoord2f(1.0f,1.0f);
	glVertex3f(size+cX,size+cY,-size+cZ);
	


	glEnd();




	//--------------------------------------------------------------fo2------------------------------------------------------------


	glBindTexture(GL_TEXTURE_2D,fo2);//3




	glBegin(GL_QUADS); 
	
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-size+cX, size+cY, size+cZ);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(size+cX, size+cY, size+cZ);
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(size+cX,size+cY, -size+cZ);
	

	glTexCoord2f(1.0f,0.0f);
	glVertex3f(-size+cX,size+cY,-size+cZ);
	


	glEnd();



	//--------------------------------------------------------------t7t------------------------------------------------------------


	glBindTexture(GL_TEXTURE_2D,t7t);//6




	glBegin(GL_QUADS); 
	
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(-size+cX, -size+cY, size+cZ);
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(size+cX, -size+cY, size+cZ);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(size+cX,-size+cY, -size+cZ);
	

	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-size+cX,-size+cY,-size+cZ);
	


	glEnd();

	
	

	
	
	}
	void drawRail(int rail){
		glBindTexture(GL_TEXTURE_2D,rail);




		glBegin(GL_QUADS); 
	
	
		glTexCoord2f(5.0f,0.0f);
		glVertex3f(-size/6+ccX, -size+ccY, size+ccZ);
	
		glTexCoord2f(5.0f,1.0f);
		glVertex3f(size/6+ccX, -size+ccY, size+ccZ);
	
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(size/6+ccX,-size+ccY, -size+ccZ);
	

		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-size/6+ccX,-size+ccY,-size+ccZ);
	


		glEnd();
	}


	
};
class tunnel{
public :
	float x,y,z;
	float cX,cY,cZ;
	int ymin,ysar,fo2,t7t;
	tunnel(float ccX,float ccY,float ccZ,float xx,float yy,float zz,int img1,int img2,int img3,int img4)
	{
		x=xx;
		y=yy;
		z=zz;
		ymin=img1;
		ysar=img2;
		fo2=img3;
		t7t=img4;
		cX=ccX;
		cY=ccY;
		cZ=ccZ;
	}
	void drawTunnel(){
		//right
	glBindTexture(GL_TEXTURE_2D,ymin);
	glBegin(GL_QUADS);
	
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(x+cX,y+cY,z+cZ);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(x+cX,-y+cY,z+cZ);
		glTexCoord2f(2.0f,0.0f);
		glVertex3f(x+cX,-y+cY,-z+cZ);
		glTexCoord2f(2.0f,1.0f);
		glVertex3f(x+cX,y+cY,-z+cZ);
		glEnd();
		//left
	glBindTexture(GL_TEXTURE_2D,ysar);
	glBegin(GL_QUADS);
	
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x+cX,y+cY,-z+cZ);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x+cX,-y+cY,-z+cZ);
		glTexCoord2f(2.0f,0.0f);
		glVertex3f(-x+cX,-y+cY,z+cZ);
		glTexCoord2f(2.0f,1.0f);
		glVertex3f(-x+cX,y+cY,z+cZ);
		glEnd();
		
	glBindTexture(GL_TEXTURE_2D,fo2);
	glBegin(GL_QUADS);
	
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x+cX,y+cY,-z+cZ);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x+cX,y+cY,z+cZ);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x+cX,y+cY,z+cZ);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x+cX,y+cY,-z+cZ);
		glEnd();
		//bottom
	glBindTexture(GL_TEXTURE_2D,t7t);
	glBegin(GL_QUADS);
	
	    glTexCoord2f(0.0f,3.0f);
		glVertex3f(-x+cX,-y+cY,-z+cZ);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x+cX,-y+cY,z+cZ);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x+cX,-y+cY,z+cZ);
		glTexCoord2f(1.0f,3.0f);
		glVertex3f(x+cX,-y+cY,-z+cZ);

	glEnd();
	}
	void drawRail(int rail){
		glBindTexture(GL_TEXTURE_2D,rail);
		glBegin(GL_QUADS);
	
			glTexCoord2f(3.0f,1.0f);//0 3
			glVertex3f(-size/6+cX,-y+cY,-z+cZ);

			glTexCoord2f(0.0f,1.0f);//0 0
			glVertex3f(-size/6+cX,-y+cY,z+cZ);

			glTexCoord2f(0.0f,0.0f);//1 0
			glVertex3f(size/6+cX,-y+cY,z+cZ);

			glTexCoord2f(3.0f,0.0f);//1 3
			glVertex3f(size/6+cX,-y+cY,-z+cZ);

		glEnd();
	}
};

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 2000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}






// aya's functions ----------------------------------------------------------------------------------------------------------------------------

int wall, ground, wall2, wall3, door, wheel,control;

bool opendoor=false;


void drawWheel(float x = 0, float y = 0, float z = 0) {
	//circle 2
	glPushMatrix();
	glTranslatef(x,y,z);
	glColor3f(0.1f,0.1f,0.1f);
	double radius1 = 2;
	double ori_x1 = 0.0;
	double ori_y1 = 0.0;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 300; i++) {
	double angle1 =2*PI * i / 300;
	double x1 = cos(angle1) * radius1;
	double y1 = sin(angle1) * radius1;
	glVertex2d(ori_x1 + x1, ori_y1 + y1);
}
	glEnd();
	glPopMatrix();
	//circle 3
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.6,0.6,0.6);
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 10; i++) {
	double angle1 =2*PI * i / 10;
	double x1 = cos(angle1) * radius1;
	double y1 = sin(angle1) * radius1;
	glVertex2d(ori_x1 + x1, ori_y1 + y1);
}
	glEnd();
	glPopMatrix();
	//circle 4
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.4,0.4,0.4);
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 10; i++) {
	double angle1 =2*PI * i / 10;
	double x1 = cos(angle1) * radius1;
	double y1 = sin(angle1) * radius1;
	glVertex2d(ori_x1 + x1, ori_y1 + y1);
}
	glEnd();
	glPopMatrix();
}

void DrawWindows(float x = 0, float y = 0, float z = 0) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glColor4f(0.0f, 1.0f, 1.0f, 0.1f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBegin(GL_QUADS);
	glVertex3f(-4, -5, -10);
	glVertex3f(4, -5, -10);
	glVertex3f(4, 5, -10);
	glVertex3f(-4, 5, -10);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
}

void DrawWall(float x = 0, float y = 0, float z = 0) {
	glPushMatrix();
	glTranslated(x, y, z);
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall3);
	glColor3f(0.4f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-0.5, -5, -10);
	glVertex3f(0.5, -5, -10);
	glVertex3f(0.5, 5, -10);
	glVertex3f(-0.5, 5, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void WallWithWindow(float x = 0, float y = 0, float z = 0) {
	//for front and back   
	glPushMatrix();
	glTranslatef(x, y, z);
	//----------------------------------------------1----t------------------------------------------------------------------
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslatef(0, 9.5, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall2);
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-17, -0.5, -10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(17, -0.5, -10);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(17, 0.5, -10);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-17, 0.5, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//----------------------------------------------2--b-------------------------------------------------------------
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslatef(0, -5.5, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall2);
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-25, -4.5, -10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25, -4.5, -10);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(25, 4.5, -10);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-25, 4.5, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//----------------------------------------------4-----r------------------------------------------------------------
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslatef(20.5, 4.5, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall3);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-4.5, -5.5, -10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(4.5, -5.5, -10);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(4.5, 5.5, -10);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-4.5, 5.5, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//----------------------------------------------4-----l------------------------------------------------------------
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslatef(-20.5, 4.5, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall3);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-4.5, -5.5, -10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(4.5, -5.5, -10);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(4.5, 5.5, -10);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-4.5, 5.5, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	DrawWindows(-12, 4, 0);
	DrawWindows(-4, 4, 0);
	DrawWindows(4, 4, 0);
	DrawWindows(12, 4, 0);
	DrawWall(-8, 4, 0);
	DrawWall(8, 4, 0);
	glPopMatrix();
}

void WallWithDoor(float x = 0, float y = 0, float z = 0) {
	glPushMatrix();
	//----------------------------------------------right1----------------------------------------------------------------------
	glPushMatrix();
	glTranslatef(0+x, 6+y, 0+z);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(25, -4, -10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25, -4, 10);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(25, 4, 10);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(25, 4, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//----------------------------------------------right2----------------------------------------------------------------------
	glPushMatrix();
	glTranslatef(0+x, -4+y, +7+z);
	glRotatef(90, 0, 1, 0);
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall3);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-3, -6, +25);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(3, -6, +25);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(3, 6, +25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-3, 6, +25);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//----------------------------------------------right3----------------------------------------------------------------------
	glPushMatrix();
	glTranslatef(0+x, -4+y, -7+z);
	glRotatef(90, 0, 1, 0);
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall3);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-3, -6, +25);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(3, -6, +25);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(3, 6, +25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-3, 6, +25);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//----------------------------------------------door----------------------------------------------------------------------
	glPushMatrix();
	if(opendoor==true) glTranslatef(0+x, -4+y, 8+z);
	else glTranslatef(0+x, -4+y, 0+z);
	glRotatef(90, 0, 1, 0);
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, door);
	glBegin(GL_QUADS);
	glVertex3f(-4, -6, +25);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(4, -6, +25);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(4, 6, +25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-4, 6, +25);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
}


void MainRoom(float x=0,float y=0,float z=0,float t=0,float a=0,float b=0,float c=0){
	glPushMatrix();
	glTranslatef(x,y,z);
    glRotatef(t,a,b,c);
	glColor3ub(255,255,255);
	//--------------------------------------------------------------top------------------------------------------------------------
	//roof
	glPushMatrix();
	glScaled(1.2,1.5,1);
	glRotatef(10,0,0,1);
	glTranslatef(0,4,-10);
	for(int j=0;j<16;j++){
		glBegin(GL_POLYGON);
		glColor3f(0.2f,0.0f,0.0f);
		glVertex3d(10*cos((PI*j)/20),10*sin((PI*j)/20),0);
		glVertex3d(10*cos((PI*j)/20),10*sin((PI*j)/20),20);
		glVertex3d(10*cos((PI*j+8)/20),10*sin((PI*j+8)/20),20);
		glVertex3d(10*cos((PI*j+8)/20),10*sin((PI*j+8)/20),0);
		glEnd();
	}
	glPopMatrix();
	//back half circle
	glPushMatrix();
	glScalef(7.5,7,5);
	glTranslated(-0.1,1.43,2);
	glColor3f(0.2f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	double radius = 1.5;
	double ori_x = 0.0;
	double ori_y = 0.0;
	for (int i = 0; i <= 300; i++) {
	double angle =PI * i / 300;
	double x = cos(angle) * radius;
	double y = sin(angle) * radius;
	glVertex2d(ori_x + x, ori_y + y);
}
	glEnd();
	glPopMatrix();
	//front half circle
	glPushMatrix();
	glScalef(7.5,7,5);
	glTranslated(-0.1,1.43,-2);
	glColor3f(0.2f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 300; i++) {
	double angle =PI * i / 300;
	double x = cos(angle) * radius;
	double y = sin(angle) * radius;
	glVertex2d(ori_x + x, ori_y + y);
}
	glEnd();
	glPopMatrix();
	//----------------------------------------------bottom----------------------------------------------------------------------
	glPushMatrix();
	glColor3ub(255,255,255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,ground);
	glBegin(GL_QUADS);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexCoord2f(20.0f,20.0f);
	glVertex3f(-10, -10, 10);
	glTexCoord2f(10.0f,20.0f);
	glVertex3f(10, -10, 10);
	glTexCoord2f(10.0f,10.0f);
	glVertex3f(10,-10, -10);
	glTexCoord2f(20.0f,10.0f);
	glVertex3f(-10,-10,-10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	
	//----------------------------------------------front----------------------------------------------------------------------
	//----------------------------------------------1--b-------------------------------------------------------------
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(0,-5,0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,wall2);
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(1,0,0);
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(-10,-5,-10);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(10,-5,-10);
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(10,5, -10);
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-10,5,-10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//----------------------------------------------back----------------------------------------------------------------------
	//----------------------------------------------1--b-------------------------------------------------------------
	glPushMatrix();
	glColor3ub(255,255,255);
	//glTranslatef(0,-5,0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,wall2);
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(1,0,0);
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(-10,-5,10);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(10,-5,10);
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(10,5, 10);
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-10,5,10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//----------------------------------------------right----------------------------------------------------------------------
	glPushMatrix();
	glTranslatef(0,2,0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,wall);
	glBegin(GL_QUADS);
	glColor3f(1,0,0);
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(10,-7,10);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(10, -7, -10);
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(10,7, -10);
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(10,7,10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//rightwindow
	glPushMatrix();
	glColor4f(0.0f, 1.0f, 1.0f, 0.5f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBegin(GL_QUADS);
	glVertex3f(10,9,10);
	glVertex3f(10,9, -10);
	glVertex3f(10,16, -10);
	glVertex3f(10,16,10);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
	
	//to prevent function from translation
	//----------------------------------------------left-------------------------------------------------------------------
	WallWithDoor(-35,5,0);
	//----------------------------------------------front-window-------------------------------------------------------------------
	DrawWindows(4,5,0);
	DrawWindows(-4,5,0);
	//----------------------------------------------back-window---------------------------------------------------------------
	DrawWindows(4,5,20);
	DrawWindows(-4,5,20);
	//----------------------------------------------front-wall---r------------------------------------------------------------
	DrawWall(8,5,0);
	DrawWall(9,5,0);
	DrawWall(9.5,5,0);
	//----------------------------------------------front-wall---l------------------------------------------------------------
	DrawWall(-8,5,0);
	DrawWall(-9,5,0);
	DrawWall(-9.5,5,0);
	//----------------------------------------------back-wall---r------------------------------------------------------------
	DrawWall(8,5,20);
	DrawWall(9,5,20);
	DrawWall(9.5,5,20);
	//----------------------------------------------back-wall---l------------------------------------------------------------
	DrawWall(-8,5,20);
	DrawWall(-9,5,20);
	DrawWall(-9.5,5,20);
	//cylinder
	glPushMatrix();
	glTranslatef(10,-4,0);
	glRotatef(90,0,1,0);
	glScalef(1.7,1.3,1);
	for(int j=0;j<50;j++){
		glBegin(GL_POLYGON);
		glColor3f(0.1f,0.0f,0.0f);
		glVertex3d(6*cos((PI*j)/20),6*sin((PI*j)/20),0);
		glVertex3d(6*cos((PI*j)/20),6*sin((PI*j)/20),20);
		glVertex3d(6*cos((PI*j+10)/20),6*sin((PI*j+10)/20),20);
		glVertex3d(6*cos((PI*j+10)/20),6*sin((PI*j+10)/20),0);
		glEnd();
	}
	glPopMatrix();
	//chimney
	glPushMatrix();
	glTranslatef(22,10.5,0);
	glRotatef(90,1,0,0);
	for(int j=10;j<50;j++){
		glBegin(GL_POLYGON);
		glColor3f(0.2f,0.0f,0.0f);
		glVertex3d(2*cos((PI*j)/20),2*sin((PI*j)/20),0);
		glVertex3d(2*cos((PI*j)/20),2*sin((PI*j)/20),20);
		glVertex3d(2*cos((PI*j+10)/20),2*sin((PI*j+10)/20),20);
		glVertex3d(2*cos((PI*j+10)/20),2*sin((PI*j+10)/20),0);
		glEnd();
	}
	glPopMatrix();
	//circle
	glPushMatrix();
	glTranslatef(30,-4,0);
	glRotatef(90,0,1,0);
	glScalef(6.7,5,5);
	glColor3f(0.1f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 300; i++) {
	double angle =2*PI * i / 300;
	double x = cos(angle) * radius;
	double y = sin(angle) * radius;
	glVertex2d(ori_x + x, ori_y + y);
}
	glEnd();
	glPopMatrix();
	//light
	glPushMatrix();
	glTranslatef(29,4,0);
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_QUADS);
	    //front
	    glVertex3f(-1,1,1.5);
		glVertex3f(-1,-1,1.5);
		glVertex3f(1,-1,1.5);
		glVertex3f(1,1,1.5);
		//back
		glVertex3f(1,1,-1.5);
		glVertex3f(1,-1,-1.5);
		glVertex3f(-1,-1,-1.5);
		glVertex3f(-1,1,-1.5);
		//right
		glVertex3f(1,1,1.5);
		glVertex3f(1,-1,1.5);
		glVertex3f(1,-1,-1.5);
		glVertex3f(1,1,-1.5);
		//left
		glVertex3f(-1,1,-1.5);
		glVertex3f(-1,-1,-1.5);
		glVertex3f(-1,-1,1.5);
		glVertex3f(-1,1,1.5);
		//top
		glVertex3f(-1,1,-1.5);
		glVertex3f(-1,1,1.5);
		glVertex3f(1,1,1.5);
		glVertex3f(1,1,-1.5);
		//bottom
		glVertex3f(-1,-1,-1.5);
		glVertex3f(-1,-1,1.5);
		glVertex3f(1,-1,1.5);
		glVertex3f(1,-1,-1.5);
     	glEnd();
	    glPopMatrix();
		//circle of ight
	glPushMatrix();
	glTranslatef(30,4,0);
	glRotatef(90,0,1,0);
	glScalef(0.7,0.6,0.7);
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 10; i++) {
	double angle =2*PI * i / 10;
	double x = cos(angle) * radius;
	double y = sin(angle) * radius;
	glVertex2d(ori_x + x, ori_y + y);
}
	glEnd();
	glPopMatrix();
	//circle 2
	glPushMatrix();
	glTranslatef(30,-4,0);
	glRotatef(90,0,1,0);
	glScalef(4,4,4);
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 10; i++) {
	double angle =2*PI * i / 10;
	double x = cos(angle) * radius;
	double y = sin(angle) * radius;
	glVertex2d(ori_x + x, ori_y + y);
}
	glEnd();
	glPopMatrix();
	//circle 3
	glPushMatrix();
	glTranslatef(30,-4,0);
	glRotatef(90,0,1,0);
	glScalef(3,3,3);
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 10; i++) {
	double angle =2*PI * i / 10;
	double x = cos(angle) * radius;
	double y = sin(angle) * radius;
	glVertex2d(ori_x + x, ori_y + y);
}
	glEnd();
	glPopMatrix();
	//circle 4
	glPushMatrix();
	glTranslatef(30,-4,0);
	glRotatef(90,0,1,0);
	glScalef(2,2,2);
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 10; i++) {
	double angle =2*PI * i / 10;
	double x = cos(angle) * radius;
	double y = sin(angle) * radius;
	glVertex2d(ori_x + x, ori_y + y);
}
	glEnd();
	glPopMatrix();
	//-----------------------------------------left--wheel1----------------------------------------------------------------------
	drawWheel(-2, -10, -10.1);
	//------------------------------------------l----wheel2----------------------------------------------------------------------
	drawWheel(2.5, -10, -10.1);
	//-----------------------------------------right-wheel1----------------------------------------------------------------------
	drawWheel(-2, -10, 10.1);
	//------------------------------------------r----wheel2----------------------------------------------------------------------
	drawWheel(2.5, -10, 10.1);
	glPushMatrix();
	glScalef(1.5,1.5,1.5);
	//------------------------------------------l---wheel3----------------------------------------------------------------------
	drawWheel(11, -6, -6);
	//------------------------------------------l---wheel4----------------------------------------------------------------------
	drawWheel(16, -6, -6);
	//------------------------------------------r----wheel3----------------------------------------------------------------------
	drawWheel(11, -6,6);
	//------------------------------------------r----wheel4----------------------------------------------------------------------
	drawWheel(16, -6,6);
	glPopMatrix();
	glPopMatrix();
}
void drawPanel(float x=0,float y=0,float z=0,float t=0,float a=0,float b=0,float c=0){

	glPushMatrix();
	glTranslatef(x,y,z);
    glRotatef(t,a,b,c);
	//-------------------------------------------panel--------------------------------------------------------------
	
	glColor3d(1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,control);
	glBegin(GL_QUADS);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexCoord2f(1.0f,0.0f);// 1 1
	glVertex3f(4, -4, 10);
	glTexCoord2f(1.0f,1.0f);// 01
	glVertex3f(10, 0, 10);
	glTexCoord2f(0.0f,1.0f);//00
	glVertex3f(10,0, -10);
	glTexCoord2f(0.0f,0.0f);//10
	glVertex3f(4,-4,-10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void DrawEntrance(float x = 0, float y = 0, float z = 0){
	glPushMatrix();
	glTranslatef(x, y, z);
	//top
	glPushMatrix();
	glTranslatef(-20+x,-5+y,0+z);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall2);
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-5, 10, 10);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(5, 10, 10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(5, 10, -10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-5, 10, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//bottom
	glPushMatrix();
	glTranslatef(-20+x, -20+y, 0+z);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall2);
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-5, 10, 10);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(5, 10, 10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(5, 10, -10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-5, 10, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	//stair
	//front
	//1
	glPushMatrix();
	glTranslatef(-20+x, -10.5+y, 0+z);
	glRotatef(90, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall2);
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-5, 10, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(5, 10, 0.5);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(5, 10, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-5, 10, -0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslatef(-50+x, -10.5+y, 9+z);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(25, -0.5, 1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25, -0.5, -1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(25, 0.5, -1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(25, 0.5, 1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslatef(-40+x, -10.5+y, 9+z);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(25, -0.5, 1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25, -0.5, -1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(25, 0.5, -1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(25, 0.5, 1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//back
	//1
	glPushMatrix();
	glTranslatef(-20+x, -10.5+y, -20+z);
	glRotatef(90, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall2);
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-5, 10, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(5, 10, 0.5);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(5, 10, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-5, 10, -0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslatef(-50+x, -10.5+y, -9+z);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(25, -0.5, 1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25, -0.5, -1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(25, 0.5, -1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(25, 0.5, 1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslatef(-40+x, -10.5+y, -9+z);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(25, -0.5, 1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25, -0.5, -1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(25, 0.5, -1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(25, 0.5, 1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	glPopMatrix();
}

void RoomWithWindow(float x = 0, float y = 0, float z = 0) {
	glPushMatrix();
	glTranslatef(x, y, z);
	//----------------------------------------------bottom----------------------------------------------------------------------
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ground);
	glBegin(GL_QUADS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexCoord2f(20.0f, 20.0f);
	glVertex3f(-25, -10, 10);
	glTexCoord2f(10.0f, 20.0f);
	glVertex3f(25, -10, 10);
	glTexCoord2f(10.0f, 10.0f);
	glVertex3f(25, -10, -10);
	glTexCoord2f(20.0f, 10.0f);
	glVertex3f(-25, -10, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	

	//--------------------------------------------------------------top------------------------------------------------------------
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall2);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-25, 10, 10);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(25, 10, 10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25, 10, -10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-25, 10, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//----------------------------------------------front----------------------------------------------------------------------
	WallWithWindow();
	//----------------------------------------------back---------------------------------------------------------------------
	WallWithWindow(0, 0, 20);
	//----------------------------------------------right---------------------------------------------------------------------
	WallWithDoor();
	//----------------------------------------------left----------------------------------------------------------------------
	WallWithDoor(-50,0,0);
	//-----------------------------------------left--wheel1----------------------------------------------------------------------
	drawWheel(-18, -10, -10.1);
	//----------------------------------------------wheel2----------------------------------------------------------------------
	drawWheel(-13.5, -10, -10.1);
	//----------------------------------------------wheel3----------------------------------------------------------------------
	drawWheel(13.5, -10, -10.1);
	//----------------------------------------------wheel4----------------------------------------------------------------------
	drawWheel(18, -10, -10.1);
	//-----------------------------------------right-wheel1----------------------------------------------------------------------
	drawWheel(-18, -10, 10.1);
	//----------------------------------------------wheel2----------------------------------------------------------------------
	drawWheel(-13.5, -10, 10.1);
	//----------------------------------------------wheel3----------------------------------------------------------------------
	drawWheel(13.5, -10, 10.1);
	//----------------------------------------------wheel4----------------------------------------------------------------------
	drawWheel(18, -10, 10.1);
	//--------------------------------------------------------------Entrance------------------------------------------------------------
	DrawEntrance(25,0,0);

	glPopMatrix();
	glColor3f(1,1,1);

	
}

void RoomWithOutWindow(float x = 0, float y = 0, float z = 0) {
	glPushMatrix();
	glTranslatef(x, y, z);
	//----------------------------------------------bottom----------------------------------------------------------------------
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ground);
	glBegin(GL_QUADS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexCoord2f(20.0f, 20.0f);
	glVertex3f(-25, -10, 10);
	glTexCoord2f(10.0f, 20.0f);
	glVertex3f(25, -10, 10);
	glTexCoord2f(10.0f, 10.0f);
	glVertex3f(25, -10, -10);
	glTexCoord2f(20.0f, 10.0f);
	glVertex3f(-25, -10, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//--------------------------------------------------------------top------------------------------------------------------------
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall2);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-25, 10, 10);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(25, 10, 10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25, 10, -10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-25, 10, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//----------------------------------------------front----------------------------------------------------------------------
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall2);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-25,-10, -10);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(25, -10, -10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25, 10, -10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-25, 10,-10);	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	//----------------------------------------------back---------------------------------------------------------------------
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall2);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-25,-10, 10);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(25, -10, 10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25, 10, 10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-25, 10,10);	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	//----------------------------------------------right---------------------------------------------------------------------
	WallWithDoor();
	//----------------------------------------------left----------------------------------------------------------------------
	WallWithDoor(-50,0,0);
	//-----------------------------------------left--wheel1----------------------------------------------------------------------
	drawWheel(-18, -10, -10.1);
	//----------------------------------------------wheel2----------------------------------------------------------------------
	drawWheel(-13.5, -10, -10.1);
	//----------------------------------------------wheel3----------------------------------------------------------------------
	drawWheel(13.5, -10, -10.1);
	//----------------------------------------------wheel4----------------------------------------------------------------------
	drawWheel(18, -10, -10.1);
	//-----------------------------------------right-wheel1----------------------------------------------------------------------
	drawWheel(-18, -10, 10.1);
	//----------------------------------------------wheel2----------------------------------------------------------------------
	drawWheel(-13.5, -10, 10.1);
	//----------------------------------------------wheel3----------------------------------------------------------------------
	drawWheel(13.5, -10, 10.1);
	//----------------------------------------------wheel4----------------------------------------------------------------------
	drawWheel(18, -10, 10.1);
	//--------------------------------------------------------------Entrance------------------------------------------------------------
    DrawEntrance(25,0,0);

	glPopMatrix();
	glColor3f(1,1,1);
}









int image1,image2,image3,image4,image5,image6,grass;

int snow2dam,snowWra,snowYmen,snowYsar,snowFo2,snowT7t;

int mountain2dam,mountainWra,mountainYmen,mountainYsar,mountainFo2,mountainT7t;

int tunel1,roof,road2,rail;

int forest2dam,forestWra,forestYmen,forestYsar,forestFo2,forestT7t;

int night2dam,nightWra,nightYmen,nightYsar,nightFo2,nightT7t;

int desert2dam,desertWra,desertYmen,desertYsar,desertFo2,desertT7t;
	
Model_3DS*bench;
GLTexture chaitTex,chaitTex1;

Model_3DS*house;
GLTexture houseTex1,houseTex2,houseTex3,houseTex4,houseTex5,houseTex6,houseTex7;

Model_3DS*projector;
GLTexture projectorTex;

Model_3DS*armchair;
GLTexture armChairTex1,armChairTex2,armChairTex3,armChairTex4;

Model_3DS*sofa;
GLTexture sofaTex1,sofaTex2;

Model_3DS*table;
GLTexture tableTex;

Model_3DS*bookCase;
GLTexture bookCaseTex1,bookCaseTex2,bookCaseTex3;

Model_3DS*chair;
GLTexture chairTex1,chairTex2;

Model_3DS*sofaChair;
GLTexture sofaChairTex1,sofaChairTex2,sofaChairTex3;

Model_3DS*theTree;

Model_3DS*theBusStop;

Model_3DS*theCow;

Model_3DS*theSheep;

Model_3DS*theWbench;

Model_3DS*theGoat;

int bookcase,shelfWood;

int building,building2;







GLTexture leaf,bark;

GLTexture cowskin,coweye,cowcuer;

GLTexture sheeptex;

GLTexture goattex;

GLTexture WbenchTex1;

GLTexture BusStopTex1,BusStopTex2,BusStopTex3,BusStopTex4,BusStopTex5,BusStopTex6;








//anas,functions ---------------------------------------------------------------------------------------------------------------------------------

void drawCinemaSeats(float x,float y,float z){
glPushMatrix();
glTranslatef(x,y,z);
 glTranslated(0,-7.5,0);
 glRotated(90,0,1,0);
 armchair->Materials[0].tex=armChairTex2;
 armchair->Materials[1].tex=armChairTex3;
 armchair->Materials[2].tex=armChairTex1;
 armchair->Materials[3].tex=armChairTex4;
 armchair->Materials[4].tex=armChairTex1;
 //2
 armchair->pos.x=-5;
 armchair->pos.y=0;
 armchair->pos.z=0;

 armchair->scale=0.05;
 armchair->Draw();
 //3
 armchair->pos.x=+5;
 armchair->pos.y=0;
 armchair->pos.z=0;

 armchair->scale=0.05;
 armchair->Draw();
 //secondRow
 glTranslated(0,0,-5);
 
 //2
 armchair->pos.x=-5;
 armchair->pos.y=0;
 armchair->pos.z=0;

 armchair->scale=0.05;
 armchair->Draw();
 //3
 armchair->pos.x=+5;
 armchair->pos.y=0;
 armchair->pos.z=0;

 armchair->scale=0.05;
 armchair->Draw();
 //thirdRow
 glTranslated(0,0,10);
 

 armchair->scale=0.05;
 armchair->Draw();
 //2
 armchair->pos.x=-5;
 armchair->pos.y=0;
 armchair->pos.z=0;

 armchair->scale=0.05;
 armchair->Draw();
 //3
 armchair->pos.x=+5;
 armchair->pos.y=0;
 armchair->pos.z=0;

 armchair->scale=0.05;
 armchair->Draw();
 //fourthRow
 glTranslated(0,0,-15);
 
 //2
 armchair->pos.x=-5;
 armchair->pos.y=0;
 armchair->pos.z=0;

 armchair->scale=0.05;
 armchair->Draw();
 //3
 armchair->pos.x=+5;
 armchair->pos.y=0;
 armchair->pos.z=0;

 armchair->scale=0.05;
 armchair->Draw();
 //fifthRow
 glTranslated(0,0,-5);
 
 //2
 armchair->pos.x=-5;
 armchair->pos.y=0;
 armchair->pos.z=0;

 armchair->scale=0.05;
 armchair->Draw();
 //3
 armchair->pos.x=+5;
 armchair->pos.y=0;
 armchair->pos.z=0;

 armchair->scale=0.05;
 armchair->Draw();

 
 glPopMatrix();

}
void CINEMA(float x=0,float y=0,float z=0){

//screen
 glPushMatrix();
 glTranslatef(x,y,z);
 glTranslated(0,0,-24.5);
 glPopMatrix();
 //projector
 glPushMatrix();
 glTranslatef(x,y,z);
 glTranslated(0,2,0);
 glRotated(0,0,1,0);
 projector->pos.x=1;
 projector->pos.y=1;
 projector->pos.z=1;

 projector->scale=0.07;
 projector->Materials[0].tex=projectorTex;
 projector->Materials[1].tex=projectorTex;
 projector->Draw();

 
 glPopMatrix();
 //seats

 drawCinemaSeats(x,y,z);


}
void drawBox(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6){
	


	glBindTexture(GL_TEXTURE_2D,image3);
	glBegin(GL_QUADS);
	    //front
	    
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,y,z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,-y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,-y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,y,z);
		glEnd();
		//back
	glBindTexture(GL_TEXTURE_2D,image6);
	glBegin(GL_QUADS);
	
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(x,y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(x,-y,-z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(-x,-y,-z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(-x,y,-z);
		glEnd();
		//right
	glBindTexture(GL_TEXTURE_2D,image1);
	glBegin(GL_QUADS);
	
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(x,y,z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(x,-y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,-y,-z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,y,-z);
		glEnd();
		//left
	glBindTexture(GL_TEXTURE_2D,image4);
	glBegin(GL_QUADS);
	
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,-y,-z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(-x,-y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(-x,y,z);
		glEnd();
		//top
	glBindTexture(GL_TEXTURE_2D,image2);
	glBegin(GL_QUADS);
	
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,y,-z);
		glEnd();
		//bottom
	glBindTexture(GL_TEXTURE_2D,image5);
	glBegin(GL_QUADS);
	
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,-y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,-y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,-y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,-y,-z);

	glEnd();
	
	
	

};

//batoul's functions ---------------------------------------------------------------------------------------------------------------------------

int comodena,comodena2,closet,closet2,bord,imagclass1,imagclass2,coal,monalisa,food;

bool fan=true;
double fanrotate=0.0;
//------------------------------------------------ furnitures ----------------------------------------------------------------------




void drawTable(double x,double y,double z,double a,double b, double c) {
	
	 glTranslatef(x, y, z);
	glScaled(a,b,c);
	//glTranslated(x,y,z);
	glBegin(GL_QUADS);

	//Front
	//
	glColor3f(.6,.2,0);
	glVertex3f(-4.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-4.0f, 0.2f, 2.0f);

	//Back
	//;
	glVertex3f(-4.0f, -0.2f, -2.0f);
	glVertex3f(-4.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);

	//Right
	//
	glVertex3f(2.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(2.0f, -0.2f, 2.0f);


	//Left
	;
	glVertex3f(-4.0f, -0.2f, -2.0f);
	glVertex3f(-4.0f, -0.2f, 2.0f);
	glVertex3f(-4.0f, 0.2f, 2.0f);
	glVertex3f(-4.0f, 0.2f, -2.0f);

	//top
	//

	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-4.0f, 0.2f, 2.0f);
	glVertex3f(-4.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);

	//bottom
	;

	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(-4.0f, -0.2f, 2.0f);
	glVertex3f(-4.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);

	//table front leg
	//front
	//
	glColor3f(.8f, .6f, 0.0f);
	glVertex3f(1.8f, -0.2f, 1.6f);
	glVertex3f(1.4f, -0.2f, 1.6f);
	glVertex3f(1.4f, -3.0f, 1.6f);
	glVertex3f(1.8f, -3.0f, 1.6f);

	//back
	//;

	glVertex3f(1.8f, -0.2f, 1.2f);
	glVertex3f(1.4f, -0.2f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.2f);

	//right
	//

	glVertex3f(1.8f, -0.2f, 1.6f);
	glVertex3f(1.8f, -0.2f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.6f);

	//left
	//;

	glVertex3f(1.4f, -0.2f, 1.6f);
	glVertex3f(1.4f, -0.2f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.6f);

	//back leg back
	//front
	//;
	glVertex3f(1.8f, -0.2f, -1.2f);
	glVertex3f(1.4f, -0.2f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.2f);

	//back
	//;

	glVertex3f(1.8f, -0.2f, -1.6f);
	glVertex3f(1.4f, -0.2f, -1.6f);
	glVertex3f(1.4f, -3.0f, -1.6f);
	glVertex3f(1.8f, -3.0f, -1.6f);

	//right
	//

	glVertex3f(1.8f, -0.2f, -1.6f);
	glVertex3f(1.8f, -0.2f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.6f);

	//left
	//

	glVertex3f(1.4f, -0.2f, -1.6f);
	glVertex3f(1.4f, -0.2f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.6f);

	//leg left front
	//

	
	glVertex3f(-3.8f, -0.2f, 1.6f);
	glVertex3f(-3.4f, -0.2f, 1.6f);
	glVertex3f(-3.4f, -3.0f, 1.6f);
	glVertex3f(-3.8f, -3.0f, 1.6f);

	//back
	//;

	glVertex3f(-3.8f, -0.2f, 1.2f);
	glVertex3f(-3.4f, -0.2f, 1.2f);
	glVertex3f(-3.4f, -3.0f, 1.2f);
	glVertex3f(-3.8f, -3.0f, 1.2f);

	//right


	glVertex3f(-3.8f, -0.2f, 1.6f);
	glVertex3f(-3.8f, -0.2f, 1.2f);
	glVertex3f(-3.8f, -3.0f, 1.2f);
	glVertex3f(-3.8f, -3.0f, 1.6f);

	//left
	;

	glVertex3f(-3.4f, -0.2f, 1.6f);
	glVertex3f(-3.4f, -0.2f, 1.2f);
	glVertex3f(-3.4f, -3.0f, 1.2f);
	glVertex3f(-3.4f, -3.0f, 1.6f);

	//left leg back front

	//front
	;
	//glColor3f(1,1,1);
	glVertex3f(-3.8f, -0.2f, -1.2f);
	glVertex3f(-3.4f, -0.2f, -1.2f);
	glVertex3f(-3.4f, -3.0f, -1.2f);
	glVertex3f(-3.8f, -3.0f, -1.2f);

	//back
	;

	glVertex3f(-3.8f, -0.2f, -1.6f);
	glVertex3f(-3.4f, -0.2f, -1.6f);
	glVertex3f(-3.4f, -3.0f, -1.6f);
	glVertex3f(-3.8f, -3.0f, -1.6f);

	//right


	glVertex3f(-3.8f, -0.2f, -1.6f);
	glVertex3f(-3.8f, -0.2f, -1.2f);
	glVertex3f(-3.8f, -3.0f, -1.2f);
	glVertex3f(-3.8f, -3.0f, -1.6f);

	//left


	glVertex3f(-3.4f, -0.2f, -1.6f);
	glVertex3f(-3.4f, -0.2f, -1.2f);
	glVertex3f(-3.4f, -3.0f, -1.2f);
	glVertex3f(-3.4f, -3.0f, -1.6f);



	glEnd();
	glDisable(GL_TEXTURE_2D);

	
}



static GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 0.0}, //0
    {0.0, 0.0, 3.0}, //1
    {3.0, 0.0, 3.0}, //2
    {3.0, 0.0, 0.0}, //3
    {0.0, 3.0, 0.0}, //4
    {0.0, 3.0, 3.0}, //5
    {3.0, 3.0, 3.0}, //6
    {3.0, 3.0, 0.0}  //7
};

static GLubyte quadIndices[6][4] =
{
    {0, 1, 2, 3}, //bottom
    {4, 5, 6, 7}, //top
    {5, 1, 2, 6}, //front
    {0, 4, 7, 3}, // back is clockwise
    {2, 3, 7, 6}, //right
    {1, 5, 4, 0}  //left is clockwise
};
void drawfan(double x,double y,double z){
	glPushMatrix();
	glTranslated(x,y,z);

	glPushMatrix();
	glRotatef(fanrotate,0,1,0);
		glColor3f(255, 255, 255);
	glBegin(GL_QUADS); 
	glVertex3f(6,-1, -1);
		glVertex3f(6, -1, 1);
	glVertex3f(-6,-1, 1);
	glVertex3f(-6,-1,-1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(fanrotate,0,1,0);
	glColor3f(255, 255,255);
	glBegin(GL_QUADS); 
	glVertex3f(-1,-1, -6);
		glVertex3f(1, -1, -6);
	glVertex3f(1,-1,6);
	glVertex3f(-1,-1, 6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(255, 255, 255);
	glBegin(GL_QUADS); 
	glVertex3f(-0.3,-1, 0);
		glVertex3f(0.3, -1, 0);
	glVertex3f(0.3,3, 0);
	glVertex3f(-0.3,3,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(255, 255, 255);
	glBegin(GL_QUADS); 
	glVertex3f(0,-1, -0.3);
		glVertex3f(0, -1, 0.3);
	glVertex3f(0,3, 0.3);
	glVertex3f(0,3,-0.3);
	glEnd();
	glPopMatrix();


	glPopMatrix();
}


void drawcoalcupe(double x,double y,double z,double a,double b,double c){
	glPushMatrix();
	glTranslated(x,y,z);
	glScaled(a,b,c);
	glRotatef(90,0,1,0);
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,coal);
	//front
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(1,3, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,1);
	
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D,coal);
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, -1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, -1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(1,3, -1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,-1);
	
	glEnd();

	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(1,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, -1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(1,3, -1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(1,3,1);
	
	glEnd();
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(-2, -1, -1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-2,3, -1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,1);
	
	glEnd();
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(1,-1, -1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,-1,-1);
	
	glEnd();
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(1,3, -1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, 3, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-2,3, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,-1);
	
	glEnd();
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(1,-1, -1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,-1,-1);
	
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
}

void drawcoal(double x,double y,double z,double a,double b,double c){
	glPushMatrix();
	glTranslated(x,y,z);
	glScaled(a,b,c);
	 drawcoalcupe(0,0,0,1,1,1);
	 glRotated(45,0,1,0);
	 drawcoalcupe(2,0,0,1,1,1);
	 glRotated(45,0,1,1);
	 	 drawcoalcupe(3,0,0,1,1,1);
		 glRotated(45,0,1,1);
		  drawcoalcupe(0,0,3,1,1,1);
		  drawcoalcupe(-2,0,3,1,1,1);
		  drawcoalcupe(-3,0,2,1,1,1);
		  glPopMatrix();
}


void drawcloset(double x,double y,double z,double a,double b,double c){

	

	glPushMatrix();
	glTranslated(x,y,z);
	glScaled(a,b,c);
	glRotatef(90,0,1,0);
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,closet);
	//front
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(1,3, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,1);
	
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D,closet2);
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, -1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, -1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(1,3, -1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,-1);
	
	glEnd();

	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(1,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, -1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(1,3, -1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(1,3,1);
	
	glEnd();
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(-2, -1, -1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-2,3, -1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,1);
	
	glEnd();
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(1,-1, -1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,-1,-1);
	
	glEnd();
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(1,3, -1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, 3, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-2,3, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,-1);
	
	glEnd();
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(1,-1, -1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,-1,-1);
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

}


void drawcomodena(double x,double y,double z,double a,double b,double c){
	glPushMatrix();
	glTranslated(x,y,z);
	glScaled(a,b,c);
	glRotatef(90,0,1,0);
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,comodena);
	//front
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(1,3, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,1);
	
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D,comodena2);
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, -1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, -1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(1,3, -1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,-1);
	
	glEnd();

	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(1,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, -1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(1,3, -1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(1,3,1);
	
	glEnd();
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(-2, -1, -1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-2,3, -1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,1);
	
	glEnd();
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(1,-1, -1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,-1,-1);
	
	glEnd();
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(1,3, -1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, 3, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-2,3, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,-1);
	
	glEnd();
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(1,-1, -1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,-1,-1);
	
	glEnd();
	glPopMatrix();
		glDisable(GL_TEXTURE_2D);

}


void drawCube()
{
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
    }
    glEnd();
}

void drawbed(double x,double y,double z,double a,double b,double c)
{ 
	glTranslated(x,y,z);
	//glTranslatef(-5.0f, -1.0f, -10.0f); 
	glRotatef(90,0,1,0);
	glScaled(a,b,c);
    //bed headboard
    glColor3f(0.5,0.2,0.2);
    glPushMatrix();
    glScalef(0.1, 0.5, 0.9);
    glTranslatef(-2,-0.5,6);
    drawCube();
    glPopMatrix();
    
    //bed body
    glColor3f(0.824, 0.706, 0.549);
    glPushMatrix();
    glScalef(1, 0.2, 0.9); //1, 0.2, 0.9
    glTranslatef(0,-0.5,6.2);
    drawCube();
    glPopMatrix();
    
    //pillow right far
    glColor3f(255, 0, 0);
    glPushMatrix();
    glTranslatef(0.5,0.5,6);
    glRotatef(20, 0,0,1);
    glScalef(0.1, 0.15, 0.28);
    drawCube();
    glPopMatrix();
    
    //pillow left near
    glColor3f(255, 0, 0);
    glPushMatrix();
    glTranslatef(0.5,0.5,7.2);
    glRotatef(22, 0,0,1);
    glScalef(0.1, 0.15, 0.28);
    drawCube();
    glPopMatrix();
    
    //blanket
    glColor3f(255, 0, 0);
    glPushMatrix();
    glTranslatef(1.4,0.45,5.5);
    //glRotatef(22, 0,0,1);
    glScalef(0.5, 0.05, 0.95);
    drawCube();
    glPopMatrix();
    
    //blanket side left part
    glColor3f(255, 0, 0);
    glPushMatrix();
    glTranslatef(1.4,-0.3,8.15);
    //glRotatef(22, 0,0,1);
    glScalef(0.5, 0.25, 0.05);
    drawCube();
    glPopMatrix();
    glColor3d(1,1,1);
}

void drawbedsideTable()
{
    //bedside drawer *************************************
    // glTranslated(x,y,z);
	//glTranslatef(-5.0f, -1.0f, -10.0f); 
	//glScaled(a,b,c);
      //side drawer
      glColor3f(0.2,0.1,0.1); //0.5,0.2,0.2
      glPushMatrix();
      glTranslatef(0.5,-0.1,8.7); //0.5,-0.1,9
      //glRotatef(22, 0,0,1);
      glScalef(0.12, 0.2, 0.23);
      drawCube();
      glPopMatrix();
      
      //side drawer's drawer
      glColor3f(0.3,0.2,0.2);
      glPushMatrix();
      glTranslatef(0.88,0,8.8);
      //glRotatef(22, 0,0,1);
      glScalef(0.0001, 0.11, 0.18);
      drawCube();
      glPopMatrix();
      
      //side drawer's knob
      glColor3f(0.3, 0.1, 0.0);
      glPushMatrix();
      glTranslatef(0.9,0.1,9);
      //glRotatef(22, 0,0,1);
      glScalef(0.0001, 0.04, 0.04);
      drawCube();
      glPopMatrix();
	  glColor3d(1,1,1);
}

void drawlamp()
{
   
         //glTranslated(x,y,z);
	//glTranslatef(-5.0f, -1.0f, -10.0f); 
	//glScaled(a,b,c);
        //lamp base
        glColor3f(0,0,1);
        glPushMatrix();
        glTranslatef(0.6,0.5,9.1);
        glScalef(0.07, 0.02, 0.07);
        drawCube();
        glPopMatrix();
        
        //lamp stand
        glColor3f(1,0,0);
        glPushMatrix();
        glTranslatef(.7,0.35,9.2);
        glScalef(0.01, 0.2, 0.01);
        drawCube();
        glPopMatrix();
        
        //lamp shade
        glColor3f(0.000, 0.000, 0.545);
        glPushMatrix();
        glTranslatef(.7,0.9,9.2);
        glScalef(0.08, 0.09, 0.08);
        drawCube();
        glPopMatrix();
		glColor3d(1,1,1);
        
}


void drawchair(double x,double y,double z,double a,double b, double c) {
	
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	
	glScaled(a,b,c);
	glTranslated(x,y,z);
		
	glColor3f(0.4f, 0.302f, 0.0f);
	glBegin(GL_QUADS);

	//Front
	//
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);

	//Right
	//
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);

	//Back
	//;
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);

	//Left
	;
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);

	//top
	//

	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);

	//bottom
	;

	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);

	//table front leg
	//front
	//

	glVertex3f(1.8f, 0.2f, 1.6f);
	glVertex3f(1.4f, 0.2f, 1.6f);
	glVertex3f(1.4f, -3.0f, 1.6f);
	glVertex3f(1.8f, -3.0f, 1.6f);

	//back
	//;

	glVertex3f(1.8f, 0.2f, 1.2f);
	glVertex3f(1.4f, 0.2f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.2f);

	//right
	//

	glVertex3f(1.8f, 0.2f, 1.6f);
	glVertex3f(1.8f, 0.2f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.6f);

	//left
	//;

	glVertex3f(1.4f, 0.2f, 1.6f);
	glVertex3f(1.4f, 0.2f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.6f);

	//back leg back
	//front
	//;

	glVertex3f(1.8f, 0.2f, -1.2f);
	glVertex3f(1.4f, 0.2f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.2f);

	//back
	//;

	glVertex3f(1.8f, 0.2f, -1.6f);
	glVertex3f(1.4f,0.2f, -1.6f);
	glVertex3f(1.4f, -3.0f, -1.6f);
	glVertex3f(1.8f, -3.0f, -1.6f);

	//right
	//

	glVertex3f(1.8f, 0.2f, -1.6f);
	glVertex3f(1.8f, 0.2f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.6f);

	//left
	//

	glVertex3f(1.4f, 0.2f, -1.6f);
	glVertex3f(1.4f, 0.2f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.6f);

	//leg left front
	//

	glVertex3f(-1.8f, 0.2f, 1.6f);
	glVertex3f(-1.4f, 0.2f, 1.6f);
	glVertex3f(-1.4f, -3.0f, 1.6f);
	glVertex3f(-1.8f, -3.0f, 1.6f);

	//back
	//;

	glVertex3f(-1.8f, 0.2f, 1.2f);
	glVertex3f(-1.4f, 0.2f, 1.2f);
	glVertex3f(-1.4f, -3.0f, 1.2f);
	glVertex3f(-1.8f, -3.0f, 1.2f);

	//right


	glVertex3f(-1.8f, 0.2f, 1.6f);
	glVertex3f(-1.8f, 0.2f, 1.2f);
	glVertex3f(-1.8f, -3.0f, 1.2f);
	glVertex3f(-1.8f, -3.0f, 1.6f);

	//left
	;

	glVertex3f(-1.4f, 0.2f, 1.6f);
	glVertex3f(-1.4f, 0.2f, 1.2f);
	glVertex3f(-1.4f, -3.0f, 1.2f);
	glVertex3f(-1.4f, -3.0f, 1.6f);

	//left leg back front

	//front
	;

	glVertex3f(-1.8f, 0.2f, -1.2f);
	glVertex3f(-1.4f, 0.2f, -1.2f);
	glVertex3f(-1.4f, -3.0f, -1.2f);
	glVertex3f(-1.8f, -3.0f, -1.2f);

	//back
	;

	glVertex3f(-1.8f, 0.2f, -1.6f);
	glVertex3f(-1.4f, 0.2f, -1.6f);
	glVertex3f(-1.4f, -3.0f, -1.6f);
	glVertex3f(-1.8f, -3.0f, -1.6f);

	//right


	glVertex3f(-1.8f, 0.2f, -1.6f);
	glVertex3f(-1.8f, 0.2f, -1.2f);
	glVertex3f(-1.8f, -3.0f, -1.2f);
	glVertex3f(-1.8f, -3.0f, -1.6f);

	//left


	glVertex3f(-1.4f, 0.2f, -1.6f);
	glVertex3f(-1.4f, 0.2f, -1.2f);
	glVertex3f(-1.4f, -3.0f, -1.2f);
	glVertex3f(-1.4f, -3.0f, -1.6f);

	//chair back
	//front





	//;
	//chair upper part 
	glColor3f(0.902, 0.902, 0);
	glVertex3f(-1.8f, 1.2f, -1.8f);
	glVertex3f(1.8f, 1.2f, -1.8f);
	glVertex3f(1.8f, 3.5f, -1.8f);
	glVertex3f(-1.8f, 3.5f, -1.8f);

	glVertex3f(-1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -0.6f);

	//chair upper side
	glColor3f(1, 1, 0.4);
	glVertex3f(-1.8f, 1.2f, -1.80f);
	glVertex3f(-1.8f, 1.2f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -1.8f);

	glVertex3f(1.8f, 1.2f, -1.80f);
	glVertex3f(1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -1.8f);

	//chiar upper top 
	glColor3f(1, 1, 0);
	glVertex3f(-1.8f, 3.5f, -1.80f);
	glVertex3f(-1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -1.8f);

	glVertex3f(-1.8f, 1.2f, -1.80f);
	glVertex3f(-1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 1.2f, -1.8f);

	// chair top legs 

	glColor3f(0.2, 0.2, 0.0);
	//side walls
	glVertex3f(-1.2f, 1.2f, -1.20f);
	glVertex3f(-1.2f, 1.2f, -0.6f);
	glVertex3f(-1.2f, .2f, -0.6f);
	glVertex3f(-1.2f, .2f, -1.2f);

	glVertex3f(-.8f, 1.2f, -1.20f);
	glVertex3f(-.8f, 1.2f, -0.6f);
	glVertex3f(-.8f, .2f, -0.6f);
	glVertex3f(-.8f, .2f, -1.2f);

	//froont walls adnd back walls
	glVertex3f(-1.2f, 1.2f, -1.2f);
	glVertex3f(-0.8f, 1.2f, -1.2f);
	glVertex3f(-0.8f, .2f, -1.2f);
	glVertex3f(-1.2f, .2f, -1.2f);

	glVertex3f(-1.2f, 1.2f, -0.6f);
	glVertex3f(-0.8f, 1.2f, -0.6f);
	glVertex3f(-0.8f, .2f, -0.6f);
	glVertex3f(-1.2f, .2f, -0.6f);

	//side walls
	glVertex3f(1.2f, 1.2f, -1.20f);
	glVertex3f(1.2f, 1.2f, -0.6f);
	glVertex3f(1.2f, .2f, -0.6f);
	glVertex3f(1.2f, .2f, -1.2f);

	glVertex3f(.8f, 1.2f, -1.20f);
	glVertex3f(.8f, 1.2f, -0.6f);
	glVertex3f(.8f, .2f, -0.6f);
	glVertex3f(.8f, .2f, -1.2f);

	//froont walls adnd back walls
	glColor3f(0.2, 0.2, 0.0);
	glVertex3f(1.2f, 1.2f, -1.2f);
	glVertex3f(0.8f, 1.2f, -1.2f);
	glVertex3f(0.8f, .2f, -1.2f);
	glVertex3f(1.2f, .2f, -1.2f);

	glVertex3f(1.2f, 1.2f, -0.6f);
	glVertex3f(0.8f, 1.2f, -0.6f);
	glVertex3f(0.8f, .2f, -0.6f);
	glVertex3f(1.2f, .2f, -0.6f);

	//glVertex3f()

	glEnd();
	glColor3d(1,1,1);

}

void drawbord(double x,double y,double z,double a,double b, double c){
	glPushMatrix();
	glTranslated(x,y,z);
	glScaled(a,b,c);
	
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,bord);
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(4, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(4,6, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,6,1);
	
	glEnd();
	glPopMatrix();
		glDisable(GL_TEXTURE_2D);

}


void drawimageclass1(double x,double y,double z,double a,double b, double c){
	glPushMatrix();
	glTranslated(x,y,z);
	glScaled(a,b,c);
	
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,imagclass1);
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(1,3, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,1);
	
	glEnd();
	glPopMatrix();
		glDisable(GL_TEXTURE_2D);

}

void drawimageclass2(double x,double y,double z,double a,double b, double c){
	glPushMatrix();
	glTranslated(x,y,z);
	glScaled(a,b,c);
	
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,imagclass2);
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(1,3, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,1);
	
	glEnd();
	glPopMatrix();
		glDisable(GL_TEXTURE_2D);

}


void drawmonalisa(double x,double y,double z,double a,double b, double c){
	glPushMatrix();
	glTranslated(x,y,z);
	glScaled(a,b,c);
	
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,monalisa);
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-2,-1, 1);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1, -1, 1);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(1,3, 1);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-2,3,1);
	
	glEnd();
	glPopMatrix();
		glDisable(GL_TEXTURE_2D);

}


void drawfood(double x,double y,double z,double a,double b, double c){
	glPushMatrix();
	glTranslated(x,y,z);
	glScaled(a,b,c);
	
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,food);
	
	
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);
    glVertex3f(2.0f, 0.2f, -2.0f);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-4.0f, 0.2f, 2.0f);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-4.0f, 0.2f, -2.0f);
	
	glEnd();
	
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

}



//------------------------------------------------room object function----------------------------------------------------------------------



void bedroom(double x,double y,double z){
	glPushMatrix();
glTranslated(x,y,z);
	glPushMatrix();
	drawbed(-23,-10,10,2,5,3);
	glPopMatrix();
	glTranslated(-23,-10,9);
	glRotatef(90,0,1,0);
	glScaled(3,5,3);
	drawbedsideTable();
	drawlamp();
	glTranslated(0,0,-4.5);
	drawbedsideTable();
	drawlamp();
	//glTranslated(0,0,+1);
	//drowcomodena(5,0,10,0.3,0.3,0.3);
	
	drawcloset(0.6,0.5,6,0.7,0.7,1);
	drawcomodena(0.6,0.3,16,0.3,0.2,0.4);
	glPopMatrix();
}


void classroom(double x,double y,double z){
	glPushMatrix();
glTranslated(x,y,z);
drawfan(0,6.5,0);

drawbord(0,-1,-10,3,1.5,1);
drawimageclass1(15,2,-10,1,1,1);
drawimageclass2(-15,2,-10,1.5,1.5,1);
glPushMatrix();
drawchair(20,-4,-7.5,1,1.5,1);
glTranslated(1,0,3);
drawTable(0,0,0,1,1,1);
glPopMatrix();

glTranslated(8,0,0);
glPushMatrix();
drawchair(20,-4,-7.5,1,1.5,1);
glTranslated(1,0,3);
drawTable(0,0,0,1,1,1);
glPopMatrix();

glTranslated(8,0,0);
glPushMatrix();
drawchair(20,-4,-7.5,1,1.5,1);
glTranslated(1,0,3);
drawTable(0,0,0,1,1,1);
glPopMatrix();

glTranslated(8,0,0);
glPushMatrix();
drawchair(20,-4,-7.5,1,1.5,1);
glTranslated(1,0,3);
drawTable(0,0,0,1,1,1);
glPopMatrix();

glTranslated(8,0,0);
glPushMatrix();
drawchair(20,-4,-7.5,1,1.5,1);
glTranslated(1,0,3);
drawTable(0,0,0,1,1,1);
glPopMatrix();

glTranslated(8,0,0);
glPushMatrix();
drawchair(20,-4,-7.5,1,1.5,1);
glTranslated(1,0,3);
drawTable(0,0,0,1,1,1);
glPopMatrix();


glPopMatrix();

}

void foodroom(double x,double y,double z){
	glPushMatrix();
	glTranslated(x,y,z);
		drawfan(0,6.5,0);

	glPushMatrix();
	drawTable(0,-4,-5,3,2,1);
	glPopMatrix();
	glPushMatrix();
	//drawchair(-2,-4,0,1.5,1.5,1);
	glPopMatrix();
	glPushMatrix();
	//drawchair(4,-4,0,1.5,1.5,1);
	glPopMatrix();

	glPushMatrix();
	glRotated(90,0,1,0);
	drawchair(-4,-4,-8,1.5,1.5,1);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90,0,1,0);
	
	drawchair(4,-4,-13,1.5,1.5,1);
	glPopMatrix();
	drawfood(0,-4,-5,3,2,1);
	glPushMatrix();
	glRotated(90,0,1,0);
	drawmonalisa(8,-3,23,1.6,1.6,1.6);
	glPopMatrix();
	glPopMatrix();
}

void drivingroom(double x,double y,double z){
	glPushMatrix();
	glTranslated(x,y,z);
	drawcoal(-3,-8,-5,1,1,1);
	glPopMatrix();
}


void drawLib(float x,float y,float z){
	glPushMatrix();
	glTranslated(x,y,z);

	//sofa 
	 sofa->pos.x=-10;
	 sofa->pos.y=-7;
	 sofa->pos.z=-7;

	 sofa->scale=0.007;
	 sofa->Draw();

	 sofa->Materials[0].tex=sofaTex1;
	 sofa->Materials[1].tex=sofaTex2;
	 //sofa 2
	 sofa->pos.x=+14;
	 sofa->pos.y=-7;
	 sofa->pos.z=-7;

 
	 sofa->Draw();

	 //table
	 table->pos.x=2;
	 table->pos.y=-9;
	 table->pos.z=-7;

	 table->scale=0.005;
	 table->Draw();

	 table->Materials[0].tex=tableTex;

	 

	 //chair 1
	 glRotated(-90,0,1,0);

	 chair->pos.x=7;
	 chair->pos.y=-8;
	 chair->pos.z=18;

	 chair->scale=0.002;
	 chair->Draw();

	 chair->Materials[0].tex=chairTex1;
	 chair->Materials[1].tex=chairTex2;
	 chair->Materials[2].tex=chairTex2;
	 
	 //chair 2
	 chair->pos.x=7;
	 chair->pos.y=-8;
	 chair->pos.z=-18;

	 chair->scale=0.002;
	 chair->Draw();

	 chair->Materials[0].tex=chairTex1;
	 chair->Materials[1].tex=chairTex2;
	 chair->Materials[2].tex=chairTex2;
	 //book case
	 bookCase ->pos.x=8;
	 bookCase ->pos.y=-10;
	 bookCase ->pos.z=0;
 
	 bookCase ->scale=0.015;
	 bookCase ->Draw();
	 bookCase ->Materials[0].tex=bookCaseTex3;
	 bookCase ->Materials[1].tex=bookCaseTex2;
	 bookCase ->Materials[2].tex=bookCaseTex2;
	 bookCase ->Materials[3].tex=bookCaseTex2;
	 bookCase ->Materials[4].tex=bookCaseTex1;
	 bookCase ->Materials[5].tex=bookCaseTex1;



	glPopMatrix();
}


int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations


	glEnable(GL_TEXTURE_2D);
	

	snow2dam = LoadTexture("snow_ft.bmp",255);
	snowWra = LoadTexture("snow_bk.bmp",255);
	snowYmen = LoadTexture("snow_rt.bmp",255);
	snowYsar = LoadTexture("snow_lf.bmp",255);
	snowFo2 = LoadTexture("snow_up.bmp",255);
	snowT7t = LoadTexture("snow_dn.bmp",255);

	mountain2dam = LoadTexture("mountain-posz.bmp",255);
	mountainWra = LoadTexture("mountain-negz.bmp",255);
	mountainYmen = LoadTexture("mointain-negx.bmp",255);
	mountainYsar = LoadTexture("mountain-posx.bmp",255);
	mountainFo2 = LoadTexture("mountain-posy.bmp",255);
	mountainT7t = LoadTexture("mountain-negy.bmp",255);

	tunel1 = LoadTexture("tunnel1.bmp",255);
	roof = LoadTexture("roof.bmp",255);
	road2 = LoadTexture("road2.bmp",255);
	rail = LoadTexture("Rail.bmp",255);

	wall = LoadTexture("Wall.bmp", 255);
	ground = LoadTexture("iron.bmp", 255);
	wall2 = LoadTexture("Wall2 (2).bmp", 255);
	wall3 = LoadTexture("Wall3.bmp", 255);
	door = LoadTexture("door.bmp", 255);
	wheel = LoadTexture("wheel.bmp", 255);

	control = LoadTexture("train-panel.bmp",255);
	
	forest2dam = LoadTexture("forest-posz.bmp",255);
	forestWra = LoadTexture("forest-negz.bmp",255);
	forestYmen = LoadTexture("forest-negx.bmp",255);
	forestYsar = LoadTexture("forest-posx.bmp",255);
	forestFo2 = LoadTexture("forest-posy.bmp",255);
	forestT7t = LoadTexture("forest-negy.bmp",255);

	night2dam = LoadTexture("night-posz.bmp",255);
	nightWra = LoadTexture("night-negz.bmp",255);
	nightYmen = LoadTexture("night-negx.bmp",255);
	nightYsar = LoadTexture("night-posx.bmp",255);
	nightFo2 = LoadTexture("night-posy.bmp",255);
	nightT7t = LoadTexture("night-negy.bmp",255);

	desert2dam = LoadTexture("desert-posz.bmp",255);
	desertWra = LoadTexture("desert-negz.bmp",255);
	desertYmen = LoadTexture("desert-negx.bmp",255);
	desertYsar = LoadTexture("desert-posx.bmp",255);
	desertFo2 = LoadTexture("desert-posy.bmp",255);
	desertT7t = LoadTexture("desert-negy.bmp",255);

	comodena = LoadTexture("comodena.bmp",255);
	comodena2 = LoadTexture("comodena2.bmp",255);
	closet = LoadTexture("closet.bmp",255);
	closet2 = LoadTexture("closet2.bmp",255);
	bord = LoadTexture("bord.bmp",255);
	imagclass1= LoadTexture("imegclass1.bmp",255);
	imagclass2= LoadTexture("imageclass2.bmp",255);
	coal = LoadTexture("coal.bmp",255);
	monalisa = LoadTexture("monalisa.bmp",255);
	food = LoadTexture("food.bmp",255);

	building = LoadTexture("building.bmp",255);
	building2 = LoadTexture("building2.bmp",255);
	
	bench = new Model_3DS();
	bench->Load("Chair Tandem Bench N210722.3ds");
	chaitTex.LoadBMP("123.bmp");
	chaitTex1.LoadBMP("chairTex.bmp");

	house = new Model_3DS();
	house->Load("House Cyprys N111220.3ds");
	houseTex1.LoadBMP("houseTex1.bmp");
	houseTex2.LoadBMP("houseTex2.bmp");
	houseTex3.LoadBMP("houseTex3.bmp");
	houseTex4.LoadBMP("houseTex4.bmp");
	houseTex5.LoadBMP("houseTex5.bmp");
	houseTex6.LoadBMP("houseTex6.bmp");
	houseTex7.LoadBMP("houseTex7.bmp");

	projector = new Model_3DS();
	projector->Load("projector.3DS");
	projectorTex.LoadBMP("houseTex5.bmp");

	armchair = new Model_3DS();
	armchair->Load("armchair.3ds");
	armChairTex1.LoadBMP("arm.bmp");
	armChairTex2.LoadBMP("armchairS.bmp");
	armChairTex3.LoadBMP("Steel.bmp");
	armChairTex3.LoadBMP("armchairW.bmp");

	sofa = new Model_3DS();
	sofa->Load("Sofa Fresh Futon Edge N071122.3ds");
	sofaTex1.LoadBMP("Plywood2.bmp");
	sofaTex2.LoadBMP("Fabric-d.bmp");

	table = new Model_3DS();
	table->Load("Table Bernhardt Estelle N251022.3ds");
	tableTex.LoadBMP("Banco_mt.bmp");

	bookCase = new Model_3DS();
	bookCase->Load("Bookcase.3DS");
	bookCaseTex1.LoadBMP("os_wood_palladio.bmp");
	bookCaseTex2.LoadBMP("palladio_wood_5.bmp");
	bookCaseTex3.LoadBMP("bookcase.bmp");

	chair = new Model_3DS();
	chair->Load("Chair fotel N251007.3DS");
	chairTex1.LoadBMP("Banco_mt.bmp");
	chairTex2.LoadBMP("Plywood2.bmp");

	sofaChair = new Model_3DS();
	sofaChair->Load("Chair N230210.3DS");
	sofaChairTex1.LoadBMP("Decoo.bmp");
	sofaChairTex2.LoadBMP("Plywood2.bmp");
	sofaChairTex3.LoadBMP("Fabric-d.bmp");

	theTree = new Model_3DS();
	theTree->Load("tree.3ds");

	theBusStop = new Model_3DS();
	theWbench = new Model_3DS();
	theCow = new Model_3DS();
	theSheep = new Model_3DS();
	theGoat = new Model_3DS();

	theBusStop->Load("BusStop.3ds");
	theWbench->Load("Wbench.3ds");
	theCow->Load("cow.3ds");
	theSheep->Load("sheep.3ds");
	theGoat->Load("goat.3ds");
	BusStopTex1.LoadBMP("wood.bmp");
	BusStopTex2.LoadBMP("steel.bmp");
	BusStopTex3.LoadBMP("steel.bmp");
	BusStopTex4.LoadBMP("wood.bmp");
	BusStopTex5.LoadBMP("steel.bmp");
	BusStopTex6.LoadBMP("steel.bmp");
	WbenchTex1.LoadBMP("os_wood_palladio.bmp");
	cowskin.LoadBMP("cowskin.bmp");
	coweye.LoadBMP("coweye.bmp");
	cowcuer.LoadBMP("cowcuer.bmp");
	sheeptex.LoadBMP("whitefur.bmp");
	goattex.LoadBMP("blackfur.bmp");
	leaf.LoadBMP("leaf.bmp");
	bark.LoadBMP("bark.bmp");

	

	return TRUE;										// Initialization Went OK
}



float angle1 = 180, angle2 = 0, angle3 = 0;
float xd = 0, yd = -75, zd = 40	;//mkan //0 -75 40
float looking = 0.05;
float velocity = 3;//sr3et al mshe
float cosMovingLength = 50;
float cosMovingVelocity = 0.1;
bool myCamera = true;
int mouseX=0,mouseY=0;
int move =250,roomDetect=0;
bool direction = true;
bool mover = true;



bool isClicked=0,isRClicked=0;

void forest(){
	//trees
	glPushMatrix();
	glTranslated(100,-15,+80);
	theTree->pos.x=0;
	theTree->pos.y=0;
	theTree->pos.z=0;
	theTree->scale=0.5;
	theTree->Materials[0].tex=bark;
	theTree->Materials[1].tex=leaf;
	//1
	theTree->Draw();
	glPopMatrix();

	//2
	glPushMatrix();
	glTranslated(100,-15,-80);
	theTree->Draw();
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslated(-100,-15,+80);
	theTree->Draw();
	glPopMatrix();
	//4
	glPushMatrix();
	glTranslated(-100,-15,-80);
	theTree->Draw();
	glPopMatrix();


	//Wbench
	glPushMatrix();
	glTranslated(80,-92,-0);
	glRotated(-90,0,1,0);
	theTree->pos.x=0;
	theTree->pos.y=0;
	theTree->pos.z=0;
	theTree->scale=0.02;
	theTree->Materials[0].tex=WbenchTex1;
	theTree->Materials[1].tex=BusStopTex3;
	theTree->Materials[2].tex=BusStopTex3;
	theTree->Materials[3].tex=WbenchTex1;
	//1
	theTree->Draw();
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslated(-80,-92,-0);
	glRotated(+90,0,1,0);
	theTree->Draw();
	glPopMatrix();}
void city(){
glPushMatrix();
	glTranslated(+150,-10,-0);
	drawBox(40,80,80,building,roof,building,building,building,building);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-150,-10,-0);
	drawBox(40,80,80,building2,roof,building2,building2,building2,building2);
	glPopMatrix();
	//BusStop
	glPushMatrix();
	glTranslated(+50,-100,-0);
	glRotated(-90,0,1,0);
	theBusStop->pos.x=0;
	theBusStop->pos.y=0;
	theBusStop->pos.z=0;
	theBusStop->scale=0.008;
	theBusStop->Materials[0].tex=BusStopTex1;
	theBusStop->Materials[1].tex=BusStopTex2;
	theBusStop->Materials[2].tex=BusStopTex3;
	theBusStop->Materials[3].tex=BusStopTex4;
	theBusStop->Materials[4].tex=BusStopTex5;
	theBusStop->Materials[5].tex=BusStopTex6;
	//1
	theBusStop->Draw();
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslated(-50,-100,-0);
	glRotated(+90,0,1,0);
	theBusStop->Draw();
	glPopMatrix();
}
void snowy(){
//benches
	glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(60,-95,-50);
	bench->pos.x=0;
	bench->pos.y=0;
	bench->pos.z=0;
	bench->scale=0.001;
	bench->Materials[0].tex=chaitTex1;
	bench->Materials[1].tex=chaitTex;
	bench->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(0,-95,-50);
	bench->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(-60,-95,-50);
	bench->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(-60,-95,-50);
	bench->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(0,-95,-50);
	bench->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(+60,-95,-50);
	bench->Draw();
	glPopMatrix();


	//houses
	glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(+120,-70,-120);
	house->pos.x=0;
	house->pos.y=0;
	house->pos.z=0;
	house->scale=8;
	house->Materials[0].tex=houseTex1;
	house->Materials[1].tex=houseTex2;
	house->Materials[2].tex=houseTex3;
	house->Materials[3].tex=houseTex4;
	house->Materials[4].tex=houseTex5;
	house->Materials[5].tex=houseTex6;
	house->Materials[6].tex=houseTex7;
	house->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(-120,-70,-120);
	house->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(+120,-70,-120);
	house->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(-120,-70,-120);
	house->Draw();
	glPopMatrix();
}
void fogg(){
float fogColor[5]={1,1,1,1};
	glEnable(GL_FOG);
    glFogi(GL_FOG_MODE,GL_LINEAR);
    glFogfv(GL_FOG_COLOR,fogColor);
    glFogf(GL_FOG_DENSITY,0.6);
    glHint(GL_FOG_HINT,GL_NICEST);
    glFogf(GL_FOG_START,0.1);
    glFogf(GL_FOG_END,200);
	glDisable(GL_FOG);
}
void barn(){
glPushMatrix();
	glTranslated(+120,-70,-0);
	glRotated(-90,0,1,0);
	house->pos.x=0;
	house->pos.y=0;
	house->pos.z=0;
	house->scale=8;
	house->Materials[0].tex=houseTex2;
	house->Materials[1].tex=houseTex2;
	house->Materials[2].tex=houseTex3;
	house->Materials[3].tex=houseTex3;
	house->Materials[4].tex=houseTex2;
	house->Materials[5].tex=houseTex3;
	house->Materials[6].tex=houseTex2;
	house->Draw();
	glPopMatrix();
	

	//cow
	glPushMatrix();
	glTranslated(-120,-100,+0);
	glRotated(-180,0,1,0);
	theCow->pos.x=0;
	theCow->pos.y=0;
	theCow->pos.z=0;
	theCow->scale=0.1;
	theCow->Materials[0].tex=cowskin;
	theCow->Materials[1].tex=coweye;
	theCow->Materials[2].tex=cowcuer;
	theCow->Draw();
	glPopMatrix();

	//sheep
	glPushMatrix();
	glTranslated(-120,-92,-120);
	theSheep->pos.x=0;
	theSheep->pos.y=0;
	theSheep->pos.z=0;
	theSheep->scale=5;
	theSheep->Materials[0].tex=sheeptex;
	theSheep->Materials[1].tex=sheeptex;
	theSheep->Materials[2].tex=sheeptex;
	//1
	theSheep->Draw();
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslated(-120,-92,+60);
	theSheep->Draw();
	glPopMatrix();
	//goat
	glPushMatrix();
	glTranslated(-120,-90,+120);
	theGoat->pos.x=0;
	theGoat->pos.y=0;
	theGoat->pos.z=0;
	theGoat->scale=5;
	theGoat->Materials[0].tex=goattex;
	theGoat->Materials[1].tex=goattex;
	theGoat->Materials[2].tex=goattex;
	theGoat->Materials[3].tex=goattex;
	theGoat->Materials[4].tex=goattex;
	//1
	theGoat->Draw();
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslated(-120,-92,-60);
	theGoat->Draw();
	glPopMatrix();
}

void DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix

	//col detect ------------------------------------------------------------------------------------------------------
	if(xd>5){
		xd-=3;
	}
	
	if(xd<-5){
		xd+=3;
	}
	if(zd>130+roomDetect){
			zd-=3;
		}
	if(zd<-1010+roomDetect){
			zd+=3;
		}
	 


	if(opendoor == false){
		//front collision
		if(zd<0+roomDetect && zd>-5+roomDetect){
			zd+=3;
		}
		if(zd<-120+roomDetect && zd>-125+roomDetect){
			zd+=3;
		}
		if(zd<-240+roomDetect && zd>-245+roomDetect){
			zd+=3;
		}
		if(zd<-360+roomDetect && zd>-365+roomDetect){
			zd+=3;
		}
		if(zd<-480+roomDetect && zd>-485+roomDetect){
			zd+=3;
		}
		if(zd<-600+roomDetect && zd>-605+roomDetect){
			zd+=3;
		}
		if(zd<-720+roomDetect && zd>-725+roomDetect){
			zd+=3;
		}
		if(zd<-840+roomDetect && zd>-845+roomDetect){
			zd+=3;
		}
		if(zd<-960+roomDetect && zd>-965+roomDetect){
			zd+=3;
		}
		


		//back collision

		if(zd>80+roomDetect && zd<85+roomDetect){
			zd-=3;
		}
		if(zd>-40+roomDetect && zd<-35+roomDetect){
			zd-=3;
		}
		if(zd>-160+roomDetect && zd<-155+roomDetect){
			zd-=3;
		}
		if(zd>-280+roomDetect && zd<-275+roomDetect){
			zd-=3;
		}
		if(zd>-400+roomDetect && zd<-395+roomDetect){
			zd-=3;
		}
		if(zd>-520+roomDetect && zd<-515+roomDetect){
			zd-=3;
		}
		if(zd>-640+roomDetect && zd<-635+roomDetect){
			zd-=3;
		}
		if(zd>-760+roomDetect && zd<-755+roomDetect){
			zd-=3;
		}
		if(zd>-880+roomDetect && zd<-875+roomDetect){
			zd-=3;
		}
		
	}



	if(myCamera){
	gluLookAt(xd, yd, zd, (cos(angle2)*cos(angle1)) + xd, sin(angle2) + yd, (cos(angle2)*sin(angle1)) + zd, 0, 1, 0);
	}
	if(!myCamera){
		gluLookAt(xd, yd+60, zd, (cos(angle2)*cos(angle1)) + xd, sin(angle2) + yd+60, (cos(angle2)*sin(angle1)) + zd, 0, 1, 0);
	}
	glEnable(GL_TEXTURE_2D);
	

	


	//---------------------------------------------------skybox start-------------------------------------------------------------------

	skyBox third(0,100,-1600,forestYmen,forestYsar,forest2dam,forestWra,forestFo2,forestT7t,0,0);
	third.drawRail(rail);
	
	if(zd<-1200&&zd>-2000){
		glPushMatrix();
		glTranslated(0,0,-1600);
		forest();
		glPopMatrix();
	}
	


	skyBox first(0,100,0,snowYmen,snowYsar,snow2dam,snowWra,snowFo2,snowT7t,1,0);
	first.drawRail(rail);

	if(zd<0&&zd>-400){
		snowy();
	}



	skyBox seconde(0,100,-800,mountainYmen,mountainYsar,mountain2dam,mountainWra,mountainFo2,mountainT7t,0,0);
	seconde.drawRail(rail);



	skyBox fourth(0,100,-2400,desertYmen,desertYsar,desert2dam,desertWra,desertFo2,desertT7t,0,0);
	fourth.drawRail(rail);
	if(zd<-2000 && zd>-2800){
		glPushMatrix();
		glTranslated(0,0,-2400);
		barn();
		glPopMatrix();
	}


	skyBox fifth(0,100,-3200,nightYmen,nightYsar,night2dam,nightWra,nightFo2,nightT7t,0,1);
	fifth.drawRail(rail);
	if(zd<-2800&&zd>-3600){
		glPushMatrix();
		glTranslated(0,0,-3200);
		city();
		glPopMatrix();
	}
	
	




	tunnel firstTunnel(0,-25,-400,40,75,200,tunel1,tunel1,roof,road2);
	firstTunnel.drawTunnel();
	firstTunnel.drawRail(rail);

	tunnel secondeTunnel(0,-25,-1200,40,75,200,tunel1,tunel1,roof,road2);
	secondeTunnel.drawTunnel();
	secondeTunnel.drawRail(rail);

	tunnel thirdTunnel(0,-25,-2000,40,75,200,tunel1,tunel1,roof,road2);
	thirdTunnel.drawTunnel();
	thirdTunnel.drawRail(rail);

	tunnel fourthTunnel(0,-25,-2800,40,75,200,tunel1,tunel1,roof,road2);
	fourthTunnel.drawTunnel();
	fourthTunnel.drawRail(rail);


	//------------------------------------------------train drow----------------------------------------------------------------------
	glPushMatrix();

	glScaled(2,2,2);
	glRotated(90,0,1,0);
	
	glTranslated(move,-38,0);


	if(mover) {
		if(direction){
			
			zd-=2;
		
			move++;
			roomDetect-=2;
		}else{
			
			zd+=2;
		
			move--;
			roomDetect+=2;
		}
		if(move==250 || move == 1400){
			direction = !direction;
		}
		
		
	}

	if(fan) {
		fanrotate=fanrotate+8;
	}


	//first room
	MainRoom(255,0,0,0,0,0,0);
	drawPanel(255,0,0,0,0,0,0);
	drivingroom(255,0,0);

	//last room
	MainRoom(-315,0,0,180,0,1,0);
	drawPanel(-315,0,0,180,0,1,0);

	drivingroom(-315,0,0);


	DrawEntrance(-140,0,0);
    //second room
	RoomWithWindow(210,0,0);
	bedroom(210,0,0);

	//third room
	RoomWithWindow(150,0,0);
	drawLib(150,0,0);
	//fourth room
	
	RoomWithOutWindow(90,0,0);
	CINEMA(90,0,0);

	//fifth room
	RoomWithWindow(30,0,0);
	classroom(30,0,0);

	//sixth room
	RoomWithWindow(-30,0,0);
	foodroom(-30,0,0);

	//seventh room
	RoomWithOutWindow(-90,0,0);
	bedroom(-90,0,0);

	//eighth room
	RoomWithWindow(-150,0,0);
	drawLib(-150,0,0);

	//nineth room
	RoomWithWindow(-210,0,0);
	foodroom(-210,0,0);

	//tenth Room
	RoomWithWindow(-270,0,0);


	glPopMatrix();





	






	//-------------------------------------------------------keyboard---------------------------------------------------------------



	if (keys['A']) angle1 -= looking;  // look at the Left,  angle1 is on the axis: x and z 
	if (keys['D']) angle1 += looking;  // look at the Right. 
	if (keys['W']) if (angle2<1.55) angle2 += looking;  //look up,  angle2 is on the axis: x_z and y 
	if (keys['S']) if (angle2>-1.55) angle2 -= looking;  //look down. 
	
	if (keys['F']) {
		mover = !mover;
	}
	if(keys['H']){
		myCamera = !myCamera;
	}
	if (keys['R']) {
		fan = !fan;
	}
	if (keys['G']) {
		opendoor = !opendoor;
	}

	if(myCamera ==1){

	if (keys[VK_UP]) { zd += velocity*sin(angle1); xd += velocity*cos(angle1);
					    angle3 += cosMovingVelocity; }  // moving Forward. (changing yd axis to demonstrating the steps effect!) 
	if (keys[VK_DOWN]) { zd -= velocity*sin(angle1); xd -= velocity*cos(angle1); 
						  angle3 += cosMovingVelocity; }  // moving Backward. 
	if (keys[VK_LEFT]) { /*zd += velocity*sin(angle1 - 1.57); xd += velocity*cos(angle1 - 1.57);
					  angle3 += cosMovingVelocity;*/ }  //moving to the Left. (moving to Right/Left is the same as moving Forward/Backward but with a different angle. 
	if (keys[VK_RIGHT]) { /*zd -= velocity*sin(angle1 - 1.57);
					 xd -= velocity*cos(angle1 - 1.57); angle3 += cosMovingVelocity;*/ }  //moving to the Right 
	}
	


	
	









	
	
	//DO NOT REMOVE THIS
	SwapBuffers(hDC);
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "NeHe GL", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
	case WM_PAINT:
		DrawGLScene();
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_TIMER:
		DrawGLScene();
		return 0;

	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
		if (!HIWORD(wParam))					// Check Minimization State
		{
			active = TRUE;						// Program Is Active
		}
		else
		{
			active = FALSE;						// Program Is No Longer Active
		}

		return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
		switch (wParam)							// Check System Calls
		{
		case SC_SCREENSAVE:					// Screensaver Trying To Start?
		case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
			return 0;							// Prevent From Happening
		}
		break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
		PostQuitMessage(0);						// Send A Quit Message
		return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
		keys[wParam] = TRUE;					// If So, Mark It As TRUE
		return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
		keys[wParam] = FALSE;					// If So, Mark It As FALSE
		return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;								// Jump Back
	}
	case WM_MOUSEMOVE:
{
	mouseX = (int)LOWORD(lParam);   mouseY = (int)HIWORD(lParam);
	isClicked   = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
	isRClicked  = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
	break;
}
case WM_LBUTTONUP:
	isClicked   = false; 	 break;
case WM_RBUTTONUP:
	isRClicked  = false;   break;
case WM_LBUTTONDOWN:
	isClicked   = true; 	break;
case WM_RBUTTONDOWN:
	isRClicked  = true;	break;
  

	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	char c[] = "";
	if (!CreateGLWindow(c, 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


	//Set drawing timer to 20 frame per second
	UINT timer = SetTimer(hWnd, 0, 50, (TIMERPROC)NULL);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;

}







