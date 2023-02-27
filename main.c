#include<GL/glut.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
float inpvals[] = {100,200,130,450,130,400,150,200,440,330,340,200,100,100,200,130,450,130,400,150,200,440,330,340,200,100,100,200,130,450,130,400,150,200,440,330,340,200,100,100,200,130,450,130,400,150,200,440,330,340,200,100};
int it=0;
float adapted_inpvals[28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void adapt(float iarr[],int it) {
  int arrleng=(sizeof iarr / sizeof *iarr)-8;
  for(int i=0;i<28;i++)
  {
    if((it+27)<arrleng)
      adapted_inpvals[i]=iarr[i+it];
    else
      adapted_inpvals[i]=iarr[(i+it)-arrleng];
  }
}

void key(unsigned char d,int x,int y) {
  if(d=='d') {
    it++;
    if(it>6) {
      it=0;
    }
    display();
  }
  if(d=='a') {	
    it--;
    if(it<0) {
      it=6;
    }
    display();
  }
}

void rect() {
  glBegin(GL_LINE_LOOP);
  glVertex2f(100,100);
  glVertex2f(700,100);
  glVertex2f(700,500);
  glVertex2f(100,500);
  glEnd();
}

void graph(float arr[]) {
  glBegin(GL_LINE_LOOP);
  glVertex2f(100,100);
  glVertex2f(700,100);
  for(int i=700;i>=100;i-=25) {
    glVertex2f(i,arr[(i/25)-1]);
  }
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
  rect();
  adapt(inpvals,it);
  graph(adapted_inpvals);
  glFlush();
}

void init() {
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,750,0,550);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(800,600);
  glutInitWindowPosition(10,10);
  glutCreateWindow("demo");
  glutKeyboardFunc(key);
  glutDisplayFunc(display);
  init();
  glutMainLoop();
  return 0;
}