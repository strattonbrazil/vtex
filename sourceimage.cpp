#include "sourceimage.h"

#include <iostream>
#include <QPainter>

SourceImage::SourceImage(QWidget *parent) :
    QWidget(parent)
{
}

void SourceImage::setImage(QString path)
{
    _srcImage = QImage(path);
}

void SourceImage::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);

    QLinearGradient grad1(0, 20, 0, 110);

    grad1.setColorAt(0.0, QColor(64, 64, 64));
    grad1.setColorAt(1, QColor(99, 99, 99));
    painter.fillRect(0, 0, this->width(), this->height(), grad1);

    _validateScaledImage();

    int xOffset = 0;
    int yOffset = 0;
    if (_tallImage)
        xOffset += (this->width() - _scaledImage.width()) / 2;
    else
        yOffset += (this->height() - _scaledImage.height()) / 2;

    painter.drawImage(xOffset + SourceImage::IMAGE_MARGIN, yOffset + SourceImage::IMAGE_MARGIN, _scaledImage);

    painter.end();
}

void SourceImage::_validateScaledImage()
{
    if (_srcImage.isNull())
        return;

    if (_scaledImage.isNull() || _scaledImage.width() != this->width() || _scaledImage.height() != this->height()) {
        float frameAspect = this->width() / (float)this->height();
        float imgAspect = _srcImage.width() / (float)_srcImage.height();
        _tallImage = frameAspect > imgAspect;
        if (_tallImage)
            _scaledImage = _srcImage.scaledToHeight(this->height() - SourceImage::IMAGE_MARGIN*2);
        else
            _scaledImage = _srcImage.scaledToWidth(this->width() - SourceImage::IMAGE_MARGIN*2);
    }
}
