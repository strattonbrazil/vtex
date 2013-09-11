#include "previewwindow.h"
#include <iostream>

PreviewWindow::PreviewWindow(QWidget *parent) :
    QGLWidget(parent)
{
}

void PreviewWindow::setImage(QString path)
{

}

void PreviewWindow::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void PreviewWindow::paintGL()
{
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    float aspect = this->width() / (float)this->height();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -1, 1, -1, 1);



    glEnable(GL_TEXTURE_2D);


    glBegin(GL_QUADS);
    {
        glTexCoord2f(0, 0);
        glVertex2f(-1, -1);
        glTexCoord2f(1, 0);
        glVertex2f(1, -1);
        glTexCoord2f(1, 1);
        glVertex2f(1, 1);
        glTexCoord2f(0, 1);
        glVertex2f(-1, 1);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
