#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QGLWidget>

class PreviewWindow : public QGLWidget
{
    Q_OBJECT
public:
    explicit PreviewWindow(QWidget *parent = 0);
    void setImage(QString path);
    void resizeGL(int w, int h);
    void paintGL();
signals:
    
public slots:
    
};

#endif // PREVIEWWINDOW_H
