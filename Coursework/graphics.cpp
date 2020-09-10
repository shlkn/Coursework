#ifndef GRAPHICS_h
#define _CRT_SECURE_NO_WARNINGS 
#include "graphics.h"
extern float* vct_a, * vct_b, * vct_c;
void graphic_init(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(1500, 1000);
	glutCreateWindow("your vectors");
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
}
void ScreenShot(int W, int H)
{
	const int imSize = W * H * 3;
	unsigned char* image = new unsigned char[imSize];
	memset(image, 0, imSize);
	glReadPixels(0, 0, W, H, GL_RGB, GL_UNSIGNED_BYTE, image);
	BITMAPINFO bmi;
	memset(&bmi, 0, sizeof(BITMAPINFOHEADER));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biHeight = H;
	bmi.bmiHeader.biWidth = W;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 24;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = imSize;
	FILE* F = fopen("screen.bmp", "w");
	int nBitsOffset = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	LONG lImageSize = imSize;
	LONG lFileSize = nBitsOffset + lImageSize;
	BITMAPFILEHEADER bmfh;
	bmfh.bfType = 'B' + ('M' << 8);
	bmfh.bfOffBits = nBitsOffset;
	bmfh.bfSize = lFileSize;
	bmfh.bfReserved1 = bmfh.bfReserved2 = 0;

	UINT nWrittenFileHeaderSize = fwrite(&bmfh, 1, sizeof(BITMAPFILEHEADER), F);
	UINT nWrittenInfoHeaderSize = fwrite(&bmi, 1, sizeof(BITMAPINFOHEADER), F);
	UINT nWrittenDIBDataSize = fwrite(image, 1, imSize, F);
	UINT total = nWrittenDIBDataSize + nWrittenInfoHeaderSize + nWrittenFileHeaderSize;
	delete[]image;
	fclose(F);
}
void displayText(float x, float y, int r, int g, int b, char string) {
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string);
}
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(750, 500);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(750, 950);
	glEnd();
	displayText(780, 820, 0, 0, 0, 'Z');

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(750, 500);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(100, 50);
	glEnd();
	displayText(70, 70, 0, 0, 0, 'X');

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(750, 500);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(1400, 50);
	glEnd();
	displayText(1420, 70, 0, 0, 0, 'Y');

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(750, 500);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(vct_c[0], vct_c[1]);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(750, 500);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(vct_a[0], vct_a[1]);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(750, 500);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(vct_b[0], vct_b[1]);
	glEnd();
	ScreenShot(1500, 840);
	glutSwapBuffers();
}
#endif