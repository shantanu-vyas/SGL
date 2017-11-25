#include <time.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>


#include "initShader.h"
#include "VecLib.h"
//#include "ShaderModel.h"
#include "Model.h"
#include "GLToolkit.h"
#include "Main.h"


/*Template for simple lighting model */

#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))
#define FPS 60.f

clock_t global_clock_prev; // last time rendered/physics ticked


GLuint pj_location;
GLuint mv_location;
GLuint tr_location;
GLuint is_shadow;

Mat4 pj_matrix =
  {{1.f, 0.f, 0.f, 0.f},
   {0.f, 1.f, 0.f, 0.f},
   {0.f, 0.f, 1.f, 0.f},
   {0.f, 0.f, 0.f, 1.f}};
Mat4 mv_matrix =
  {{1.f, 0.f, 0.f, 0.f},
   {0.f, 1.f, 0.f, 0.f},
   {0.f, 0.f, 1.f, 0.f},
   {0.f, 0.f, 0.f, 1.f}};
Mat4 tr_matrix =
  {{1.f, 0.f, 0.f, 0.f},
   {0.f, 1.f, 0.f, 0.f},
   {0.f, 0.f, 1.f, 0.f},
   {0.f, 0.f, 0.f, 1.f}};


Vec4 eye = {0.f, 30.f, 0.f, 1.f};
Vec4 at =  {0.f, 0.f, 0.f, 1.f};
Vec4 up =  {0.f, -1.f, 0.f, 0.f};


Vec4* vertices;
Vec4* colors;
int num_vertices;

Model * model_list;
int num_models;


void init(void)
{
  int size = sizeof(Vec4)*num_vertices; 

  GLuint program = initShader("shaders/vshader.glsl", "shaders/fshader.glsl");
  glUseProgram(program);

  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  GLuint buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, 2 * size, NULL, GL_STATIC_DRAW);
  glBufferSubData(GL_ARRAY_BUFFER, 0, size, vertices);
  glBufferSubData(GL_ARRAY_BUFFER, size, size, vertices);

  GLuint vPosition = glGetAttribLocation(program, "vPosition");
  glEnableVertexAttribArray(vPosition);
  glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vec4), BUFFER_OFFSET(0));

  GLuint vNormal = glGetAttribLocation(program, "vNormal");
  glEnableVertexAttribArray(vNormal);
  glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_TRUE, sizeof(Vec4), (GLvoid *) size);

  pj_location = glGetUniformLocation(program, "projection");
  mv_location = glGetUniformLocation(program, "model_view");
  tr_location = glGetUniformLocation(program, "transformation");

  glEnable(GL_DEPTH_TEST);
  glClearColor(0.f, 0.f, 0.f, 1.f);
  glDepthRange(1,0);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glUniformMatrix4fv(pj_location, 1, GL_FALSE, (GLfloat *) &pj_matrix);
  glUniformMatrix4fv(mv_location, 1, GL_FALSE, (GLfloat *) &mv_matrix);

  glDrawArrays(GL_TRIANGLES, 0, num_vertices);

  glutSwapBuffers();
}

void idle_func()
{

}


void keyboard(unsigned char key, int mousex, int mousey)
{
  if (key == 'q') exit(0);

}

void genModels()
{
}

int main(int argc, char **argv)
{
  genModels();
  flattenModelList(&model_list,&vertices,&colors,&num_vertices,&num_models);

  genPerspective(&pj_matrix, 30.f , 1.f, .01f, 10.f);
  genLookAt(&mv_matrix,&eye,&at,&up);


  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("Main");
  glewInit();
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(idle_func);
  glutMainLoop();

  return 0;
}
