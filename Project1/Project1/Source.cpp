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


HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Context
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

int size =200;

class skyBox{
public : 
	int ccX,ccY,ccZ;
	int ymen,ysar,edam,wra,fo2,t7t;


	

public :
	skyBox(int cX,int cY,int cZ,int ymen,int ysar,int edam,int wra,int fo2,int t7t){
	ccX=cX;
	ccY=cY;
	ccZ=cZ;
	glColor4f(1.0f,1.0f,1.0f,1.0f);

	//----------------------------------------------------wra-------------------------------------------------------------------

	glBindTexture(GL_TEXTURE_2D,wra); //4




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
	
	
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-size+cX, -size+cY, size+cZ);
	
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(size+cX, -size+cY, size+cZ);
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(size+cX,-size+cY, -size+cZ);
	

	glTexCoord2f(1.0f,0.0f);
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

int wall, ground, wall2, wall3, door, wheel;


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
	glTranslatef(0+x, -4+y, 0+z);
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
	
}









int image1,image2,image3,image4,image5,image6,grass;

int snow2dam,snowWra,snowYmen,snowYsar,snowFo2,snowT7t;

int mountain2dam,mountainWra,mountainYmen,mountainYsar,mountainFo2,mountainT7t;

int tunel1,roof,road2,rail;



	


int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations


	glEnable(GL_TEXTURE_2D);
	image1 = LoadTexture("skyrender0001.bmp",255);
	image2 = LoadTexture("skyrender0002.bmp",255);
	image3 = LoadTexture("skyrender0003.bmp",255);
	image4 = LoadTexture("skyrender0004.bmp",255);
	image5 = LoadTexture("skyrender0005.bmp",255);
	image6 = LoadTexture("skyrender0006.bmp",255);
	grass = LoadTexture("grass.bmp",255);

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
	



	
	

	



	return TRUE;										// Initialization Went OK
}

float angle1 = -0.5, angle2 = 0, angle3 = 0;
float xd = 0, yd = -50, zd = 200;//mkan
float looking = 0.05;
float velocity = 2;//sr3et al mshe
float cosMovingLength = 50;
float cosMovingVelocity = 0.1;

int mouseX=0,mouseY=0;
int move =-600;
bool mover = true;


bool isClicked=0,isRClicked=0;

void DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix

	gluLookAt(xd, yd, zd, (cos(angle2)*cos(angle1)) + xd, sin(angle2) + yd, (cos(angle2)*sin(angle1)) + zd, 0, 1, 0);

	glEnable(GL_TEXTURE_2D);
	

	


	//---------------------------------------------------skybox start-------------------------------------------------------------------

	skyBox thire(0,100,-1600,image5,image2,image1,image4,image3,grass);//sea
	thire.drawRail(rail);
	skyBox first(0,100,0,snowYmen,snowYsar,snow2dam,snowWra,snowFo2,snowT7t);
	first.drawRail(rail);
	skyBox seconde(0,100,-800,mountainYmen,mountainYsar,mountain2dam,mountainWra,mountainFo2,mountainT7t);
	seconde.drawRail(rail);

	tunnel firstTunnel(0,-25,-400,40,75,200,tunel1,tunel1,roof,road2);
	firstTunnel.drawTunnel();
	firstTunnel.drawRail(rail);
	tunnel secondeTunnel(0,-25,-1200,40,75,200,tunel1,tunel1,roof,road2);
	secondeTunnel.drawTunnel();
	secondeTunnel.drawRail(rail);


	//------------------------------------------------train drow----------------------------------------------------------------------
	glPushMatrix();

	glScaled(2,2,2);
	glRotated(90,0,1,0);
	
	glTranslated(move,-38,0);
	if(mover) {
		move++;
	}


	//first room
	MainRoom(255,0,0,0,0,0,0);
	//last room
	MainRoom(-315,0,0,180,0,1,0);

	DrawEntrance(-140,0,0);
    //second room
	RoomWithWindow(210,0,0);
	//third room
	RoomWithWindow(150,0,0);
	//fourth room
	RoomWithOutWindow(90,0,0);
	//fifth room
	RoomWithWindow(30,0,0);
	//sixth room
	RoomWithWindow(-30,0,0);
	//seventh room
	RoomWithOutWindow(-90,0,0);
	//eighth room
	RoomWithWindow(-150,0,0);
	//nineth room
	RoomWithWindow(-210,0,0);
	//tenth Room
	RoomWithWindow(-270,0,0);


	glPopMatrix();


	//-------------------------------------------------------keyboard---------------------------------------------------------------



	if (keys['A']) angle1 -= looking;  // look at the Left,  angle1 is on the axis: x and z 
	if (keys['D']) angle1 += looking;  // look at the Right. 
	if (keys['W']) if (angle2<1.55) angle2 += looking;  //look up,  angle2 is on the axis: x_z and y 
	if (keys['S']) if (angle2>-1.55) angle2 -= looking;  //look down. 
	if (keys['E']) yd--;  
	if (keys['Q']) yd++;  
	if (keys['F']) {
		mover = !mover;
	}


	if (keys[VK_UP]) { zd += velocity*sin(angle1); xd += velocity*cos(angle1);
					    angle3 += cosMovingVelocity; }  // moving Forward. (changing yd axis to demonstrating the steps effect!) 
	if (keys[VK_DOWN]) { zd -= velocity*sin(angle1); xd -= velocity*cos(angle1); 
						  angle3 += cosMovingVelocity; }  // moving Backward. 
	if (keys[VK_LEFT]) { zd += velocity*sin(angle1 - 1.57); xd += velocity*cos(angle1 - 1.57);
					  angle3 += cosMovingVelocity; }  //moving to the Left. (moving to Right/Left is the same as moving Forward/Backward but with a different angle. 
	if (keys[VK_RIGHT]) { zd -= velocity*sin(angle1 - 1.57);
					 xd -= velocity*cos(angle1 - 1.57); angle3 += cosMovingVelocity; }  //moving to the Right 

	














	/*if(keys['D']){
		//if(x<10){
			teta-=0.1;
		//}
		
	}
	if(keys['A']){
	//	if(x>-10){
			teta+=0.1;
		//}
	}
	if(keys['W']){
		//if(y<7){
			y+=5;
		//}
	}
	if(keys['S']){
		//if(y>-3){
			y-=5;
		//}
	}*/
	
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







