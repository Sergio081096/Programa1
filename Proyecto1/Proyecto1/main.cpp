/* Este programa dibuja una "Tetera", este objeto esta definido
 * en GLUT, se crea una fuente de luz, y un material */

//Incluimos las librerias
//#include <GL/glut.h>
//#include <stdlib.h>
#include "Main.h"
float rot = 0.0;
float movKit = 0.0;
float orientacion = 180.0;
float desicion = 1.0;
float camaraZ = 0.0;
float camaraY = 0.0;
float camaraX = 0.0;
float colorX = 0.0;
float colorY = 1.0;
float colorZ = 0.5;
bool animaD = true;
bool animaI = false;
bool anima = false;

void init(void)
{
	 // Ubicamos la fuente de luz en el punto (1.0, 1.0, 1.0)
	 //GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	 // Activamos la fuente de luz
	 /*glEnable(GL_LIGHTING);
	 glEnable(GL_LIGHT0);*/

	 glClearDepth(1.0f);					// Activamos el valor de inicio del buffer de profundidad
	 glEnable(GL_DEPTH_TEST);				// Hacemos la prueba de profundidad
	 glDepthFunc(GL_LEQUAL);				// Tipo de prueba de profundidad a hacer
	 return;
}

void reshape(int w, int h)
{
	 if (!h)
		return;

	 glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
	 // Activamos la matriz de proyeccion.
	 glMatrixMode(GL_PROJECTION);
	 // "limpiamos" esta con la matriz identidad.
	 glLoadIdentity();
	 // Usamos proyeccion ortogonal
	  //glOrtho(-200, 200, -200, 200, -200, 200);
	 gluPerspective(30.0f, (GLfloat)800/(GLfloat)600, 0.03, 1000.0);
	 // Activamos la matriz de modelado/visionado. //
	 glMatrixMode(GL_MODELVIEW);
	 // "Limpiamos" la matriz
	 glLoadIdentity();
	 //gluLookAt(camaraX, camaraY, -5.0 + camaraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	 return;
}
void cubo(float color1, float color2, float color3)
{
	GLfloat vertice[8][3] = 
	{
		{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
		{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
		{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
		{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
		{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
		{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
		{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
		{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glColor3f(color1, color2, color3);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(color3, color1, color2);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(color2, color3, color1);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);	//Left
	glColor3f(color1, color3, color2);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);	//Abajo
	glColor3f(color3, color2, color1);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);	//Arriba
	glColor3f(color2, color1, color3);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}
// Aqui ponemos lo que queremos dibujar.
void display(void)
{ 
	 // Propiedades del material
	 /*GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	 GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	 GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	 GLfloat mat_shininess[] = { 100.0f };*/

	 // "Limpiamos" el frame buffer con el color de "Clear", en este 
	 // caso negro. 
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 glMatrixMode( GL_MODELVIEW_MATRIX );
	 glLoadIdentity();
	 gluLookAt( -0.65*movKit+camaraY, 0*camaraY, camaraZ,
		 -0.09*movKit + 1*camaraX, 0.0, -5.0 ,
				0.0, 0.5, 0.0);
		 
	 glTranslatef(0.0, 0.0, -20.0);
	 glRotated(30.0, 1.0, 0.0, 0.0);

	 glPushMatrix();
		 glTranslatef(0.0, -0.75,0.0);
		 glScalef(7.0, 0.5, 7.0);
		 cubo(0.0, 0.0, 1.0);
	 glPopMatrix();
	 glPushMatrix();
	    glRotatef(90, 0, 1, 0);
		glTranslatef(0.0, 0.0, movKit);
		glRotatef(orientacion, 0.0, 1.0, 0.0);
		cubo(colorX, colorY, colorZ);
	 glPopMatrix();
	 
	 //glTranslatef(camaraX, camaraY, -5.0 + camaraZ);
	
	 // Rotacion de -30 grados en torno al eje y
	 //glRotated(-30.0, 0.0, 1.0, 0.0);
	 //glRotated(-rot, 0.0, 1.0, 0.0);
	 // Dibujamos una "Tetera" y le aplico el material

	 /*glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	 glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);*/
	 //glutSolidTeapot(1.0);
	 //glColor3f(colorX, colorY, colorZ);
	 
	 
	 //glutWireSphere(5,20,20);
	 //glutSolidSphere(5, 20, 20);
	 //glutWireCube(2.0f);

	 //glFlush();
	 glutSwapBuffers ( );
	 return;
} 

void animacion()
{
	if (anima)
	{
		if (movKit == 3)
		{
			desicion = 0.0;
		}
		if (movKit == -3)
		{
			desicion = 1.0;
		}


		if (desicion == 1.0)
		{
			if (movKit >= 3.0)
			{
				if (orientacion > 0)
				{
					orientacion -= 10.0;
				}
				else
					movKit = 2.9;
			}
			else
			{
				movKit += 0.1;
			}

		}

		if (desicion == 0.0)
		{
			if (movKit <= -3.0)
			{
				if (orientacion < 180)
				{
					orientacion += 10.0;
				}
				else
					movKit = -2.9;
			}
			else
			{
				movKit -= 0.1;
			}
		}

	}
	glutPostRedisplay();
}


// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{	
	if ((glutGetModifiers() == GLUT_ACTIVE_CTRL))// && key == 'q')
	{
		rot = 0;
		anima = false;
	}
	 switch (key) 
	 {
		case 27: exit(0);
			break;

		case 'x':
			animaD ^= true;
			animaI ^= true;
			break;
		case 'z':
			animaI ^= true;
			animaD ^= true;
			break;
		case 'c':
			anima^= true;
			break;
		default:
			break;
	 }
	glutPostRedisplay();
	  return;
}    

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys)
	{
		case GLUT_KEY_PAGE_UP:     
			camaraY += 0.5f;
			//glLoadIdentity();
			//gluLookAt(camaraX, camaraY, -5.0 + camaraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			break;
		case GLUT_KEY_PAGE_DOWN:     
			camaraY -= 0.5f;
			//glLoadIdentity();
			//gluLookAt(camaraX, camaraY, -5.0 + camaraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			break;
		case GLUT_KEY_UP:
			camaraZ += 0.5f;
			//glLoadIdentity();
			//gluLookAt(camaraX, camaraY, -5.0 + camaraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			break;
		case GLUT_KEY_DOWN:  
			camaraZ -= 0.5f;
			//glLoadIdentity();
			//gluLookAt(camaraX, camaraY, -5.0 + camaraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			break;
		case GLUT_KEY_LEFT:
			camaraX -= 0.5f;
			//glLoadIdentity();
			//gluLookAt(camaraX, camaraY, -5.0 + camaraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			break;
		case GLUT_KEY_RIGHT:
			camaraX += 0.5f;
			glLoadIdentity();
			//gluLookAt(camaraX, camaraY, -5.0 + camaraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			break;
		case GLUT_KEY_F1:
			colorX = 1.0;
			colorY = 0.0;
			colorZ = 0.5;
			break;
		case GLUT_KEY_F2:
			colorX = 0.0;
			colorY = 0.5;
			colorZ = 1.0;
			break;
		case GLUT_KEY_F3:
			colorX = 0.5;
			colorY = 1.0;
			colorZ = 0.0;
			break;
		case GLUT_KEY_F4:
			colorX = 1.0;
			colorY = 1.0;
			colorZ = 0.0;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
	}		
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) 
	{
		
	}
}
// Main del programa.
int main(int argc, char **argv)
{ 
	 // Inicializo OpenGL
	 glutInit(&argc, argv);
	 
	 // Activamos buffer simple y colores del tipo RGB  
	 //glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB| GLUT_DEPTH);
	 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);

	 // Definimos una ventana de medidas 300 x 300 como ventana 
	 // de visualizacion en pixels
	 glutInitWindowSize (500, 500);
	 
	 // Posicionamos la ventana en la esquina superior izquierda de 
	 // la pantalla.
	 glutInitWindowPosition (0, 0);

	 // Creamos literalmente la ventana y le adjudicamos el nombre que se
	 // observara en su barra de titulo.
	 glutCreateWindow ("Tetera");

	 // Inicializamos el sistema 
	 init();

	 glutDisplayFunc(display); 
	 glutReshapeFunc(reshape);
	 glutKeyboardFunc(keyboard);
	 glutSpecialFunc(arrow_keys);	 
	 glutIdleFunc(animacion);
	 glutMouseFunc(mouse);
	 
	 glutMainLoop();

	 
	 // ANSI C requiere que main retorne un valor entero.
	 return 0;
}



