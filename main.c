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

void rect()