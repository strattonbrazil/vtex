#ifndef SOURCEIMAGE_H
#define SOURCEIMAGE_H

#include <QWidget>

class SourceImage : public QWidget
{
    Q_OBJECT
public:
    explicit SourceImage(QWidget *parent = 0);
    void setImage(QString path);
    void paintEvent(QPaintEvent *);
    void _validateScaledImage();


    const int IMAGE_MARGIN = 4;
signals:
    
public slots:
private:
    QImage _srcImage;
    QImage _scaledImage;
    bool _tallImage;
    
};

#endif // SOURCEIMAGE_H
