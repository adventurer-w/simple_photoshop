#include "selectrectwidget.h"
#include "ui_selectrectwidget.h"


#include <QPainter>
#include <QVector>
#include <QMouseEvent>


#include "qdebug.h"


int  SelectRectWidget::sDragDotWidth_ = 6;
int  SelectRectWidget::sDragDotOffset_ = 2;
int  SelectRectWidget::sCenterRectMinWidth_ = 6;
int  SelectRectWidget::sLineWidth_ = 1;


void SelectRectWidget::setRects()
{
    leftRect_.setRect(0,0,centerRect_.x(),height());
    topRect_.setRect(centerRect_.x(),0,centerRect_.width()+sLineWidth_,centerRect_.y());
    rightRect_.setRect(centerRect_.width()+centerRect_.x()+sLineWidth_,0,width()-centerRect_.width()-centerRect_.x(),height());
    bottomRect_.setRect(centerRect_.x(),centerRect_.height()+centerRect_.y()+sLineWidth_,centerRect_.width()+sLineWidth_,height()-centerRect_.height()-centerRect_.y());
}


SelectRectWidget::SelectRectWidget(QWidget *parent) :
    QWidget(parent),fixCenterRectRatio_(-1.0f),
    ui(new Ui::SelectRectWidget)
{
    ui->setupUi(this);
    //绘制区域
    setRects();
    centerRect_.setWidth(0);


    //区域内外等颜色值
    outsideColor_ = QColor(200,200,200,150);
    insideColor_ = QColor(200,200,200,0);
    dashColor_ = QColor(30,162,255,255);


    //虚线的样式
    dashPen_.setBrush(QBrush(dashColor_ , Qt::SolidPattern));
    qreal space = 2;
    dashes_ << 3 << space << 3 <<space;
    dashPen_.setDashPattern(dashes_);
    dashPen_.setWidth(sLineWidth_);


    //几个可以调整的点
    labelLeftBottom_ = new QLabel(this);
    labelLeftBottom_->setObjectName(QString::fromUtf8("labelLeftBottom"));
    labelLeftBottom_->setFixedSize(sDragDotWidth_,sDragDotWidth_);
    labelLeftBottom_->setCursor(QCursor(Qt::SizeBDiagCursor));
    labelLeftBottom_->setStyleSheet(QString::fromUtf8("background-color: rgb(30,162,255);"));
    labelRightBottom_ = new QLabel(this);
    labelRightBottom_->setObjectName(QString::fromUtf8("labelRightBottom"));
    labelRightBottom_->setFixedSize(sDragDotWidth_,sDragDotWidth_);
    labelRightBottom_->setCursor(QCursor(Qt::SizeFDiagCursor));
    labelRightBottom_->setStyleSheet(QString::fromUtf8("background-color: rgb(30,162,255);"));
    labelLeftTop_ = new QLabel(this);
    labelLeftTop_->setObjectName(QString::fromUtf8("labelLeftTop"));
    labelLeftTop_->setFixedSize(sDragDotWidth_,sDragDotWidth_);
    labelLeftTop_->setCursor(QCursor(Qt::SizeFDiagCursor));
    labelLeftTop_->setStyleSheet(QString::fromUtf8("background-color: rgb(30,162,255);"));
    labelRightTop_ = new QLabel(this);
    labelRightTop_->setObjectName(QString::fromUtf8("labelRightTop"));
    labelRightTop_->setFixedSize(sDragDotWidth_,sDragDotWidth_);
    labelRightTop_->setCursor(QCursor(Qt::SizeBDiagCursor));
    labelRightTop_->setStyleSheet(QString::fromUtf8("background-color: rgb(30,162,255);"));


    //事件监听
    labelLeftBottom_->installEventFilter(this);
    labelRightBottom_->installEventFilter(this);
    labelLeftTop_->installEventFilter(this);
    labelRightTop_->installEventFilter(this);


}


SelectRectWidget::~SelectRectWidget()
{
    labelLeftBottom_->removeEventFilter(this);
    labelRightBottom_->removeEventFilter(this);
    labelLeftTop_->removeEventFilter(this);
    labelRightTop_->removeEventFilter(this);
    delete ui;
}


void SelectRectWidget::checkCenterRect()
{
    centerRect_ = centerRect_.intersected(this->rect());
    if(centerRect_.bottom() >= this->rect().bottom()){
        centerRect_.setBottom(this->rect().bottom());
    }
    if(centerRect_.right() >= this->rect().right()){
        centerRect_.setRight(this->rect().right()-sLineWidth_);
    }
}


QRect SelectRectWidget::centerRect() const
{
    return centerRect_;
}


void SelectRectWidget::setSelectRectChange(const std::function<void (QRect rect)> &selectRectChange)
{
    selectRectChange_ = selectRectChange;
}


void SelectRectWidget::setFixCenterRectRatio(float ratio)
{
    fixCenterRectRatio_ = ratio;


    float widthBHeight = this->width()*1.0f/this->height();
    int tmpWidth = 0;
    int tmpHeight = 0;
    if(widthBHeight > ratio){
        tmpHeight = this->height();
        tmpWidth = ratio * tmpHeight;
    }else{
        tmpWidth = this->width();
        tmpHeight = tmpWidth/ratio;
    }


    //设置选择框值
    centerRect_.setRect((this->width() - tmpWidth)/2 , (this->height() - tmpHeight)/2 , tmpWidth , tmpHeight);
    this->update();
}


void SelectRectWidget::mousePressEvent(QMouseEvent *e)
{


    if(centerRect_.contains(e->pos(),true)){
        press_ = true;
        startPos_ = e->pos();
        dragMoveLocation_ = centerRect_;
    }
}


void SelectRectWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (press_){
        QPoint movePos = e->pos()-startPos_;
        centerRect_.setRect(std::max(std::min(dragMoveLocation_.x()+movePos.x(), rect().width()-dragMoveLocation_.width()-sLineWidth_) , 0) ,
                            std::max(std::min(dragMoveLocation_.y()+movePos.y(), rect().height()-dragMoveLocation_.height()-sLineWidth_) , 0) ,
                            centerRect_.width() , centerRect_.height() );
        this->update();
    }
}


void SelectRectWidget::mouseReleaseEvent(QMouseEvent *e)
{
    press_ = false;
}
void SelectRectWidget::paintEvent(QPaintEvent *event)
{
    checkCenterRect();
    setRects();
    if(selectRectChange_ && (centerRect_ != preCenterRect_) ){
        selectRectChange_(centerRect_);
        preCenterRect_ = centerRect_;
    }
    QPainter painter(this);
    //绘制区域
    painter.fillRect(leftRect_, outsideColor_);
    painter.fillRect(topRect_, outsideColor_);
    painter.fillRect(rightRect_, outsideColor_);
    painter.fillRect(bottomRect_, outsideColor_);


    //绘制中间区域和边框虚线
//    dashPen_.setBrush(QBrush(dashColor_));
    painter.setPen(dashPen_);
    painter.fillRect(centerRect_, insideColor_);
    painter.drawRect(centerRect_);


    //move zoomdot
    labelLeftBottom_->move(centerRect_.x()-sDragDotWidth_/2+sDragDotOffset_,centerRect_.y()+centerRect_.height()-sDragDotWidth_/2-sDragDotOffset_);
    labelRightBottom_->move(centerRect_.x()+centerRect_.width()-sDragDotWidth_/2-sDragDotOffset_,centerRect_.y()+centerRect_.height()-sDragDotWidth_/2-sDragDotOffset_);
    labelLeftTop_->move(centerRect_.x()-sDragDotWidth_/2+sDragDotOffset_,centerRect_.y()-sDragDotWidth_/2+sDragDotOffset_);
    labelRightTop_->move(centerRect_.x()+centerRect_.width()-sDragDotWidth_/2-sDragDotOffset_,centerRect_.y()-sDragDotWidth_/2+sDragDotOffset_);




}


bool SelectRectWidget::eventFilter(QObject * obj, QEvent * e)
{
    if (obj == labelLeftBottom_
            || obj == labelLeftTop_
            || obj == labelRightBottom_
            || obj == labelRightTop_){
        //实现拖动右下角缩放窗口
        if(e->type() == QEvent::MouseButtonPress){
            QMouseEvent *event = (QMouseEvent *)e;
            // NoButton: fix frist press is NoButton bugs
            if (event->buttons() & Qt::LeftButton || event->buttons() == Qt::NoButton){
                dragZoomRunning_ = true;
                dragZoomLocation_ = centerRect_;
                dragZoomPos_ = event->globalPos();
                return true;
            }
        }
        else if(e->type() == QEvent::MouseMove){
            QMouseEvent *event = (QMouseEvent *)e;
            if (dragZoomRunning_ && (event->buttons() & Qt::LeftButton)){
                int dx = event->globalPos().x() - dragZoomPos_.x();
                int dy = event->globalPos().y() - dragZoomPos_.y();


                QRect rc = dragZoomLocation_;
                if (obj == labelLeftBottom_){
                    if(fixCenterRectRatio_ > 0){
                        if(std::abs(dx) > std::abs(dy)){
                            centerRect_.setLeft(std::max(rc.left() + dx , 0));
                            if(centerRect_.left()+sCenterRectMinWidth_ > centerRect_.right()){
                                centerRect_.setLeft(centerRect_.right() - sCenterRectMinWidth_);
                            }
                            centerRect_.setBottom(rc.top() + centerRect_.width()/fixCenterRectRatio_);
                            if(centerRect_.bottom() > this->height()-sLineWidth_){
                                centerRect_.setBottom(this->height() - sLineWidth_);
                                centerRect_.setLeft(rc.right() - centerRect_.height()*fixCenterRectRatio_);
                            }
                        }else{
                            centerRect_.setBottom(std::min(rc.bottom() + dy , this->height()-sLineWidth_));
                            if(centerRect_.bottom()-sCenterRectMinWidth_ < centerRect_.top()){
                                centerRect_.setBottom(rc.top() + sCenterRectMinWidth_);
                            }
                            centerRect_.setLeft(rc.right() - centerRect_.height()*fixCenterRectRatio_);
                            if(centerRect_.left() < 0){
                                centerRect_.setLeft(0);
                                centerRect_.setBottom(rc.top() + centerRect_.width()/fixCenterRectRatio_);
                            }
                        }
                    }else{
                        centerRect_.setLeft(rc.left() + dx);
                        centerRect_.setBottom(rc.bottom() + dy);
                        if(centerRect_.left()+sCenterRectMinWidth_ > centerRect_.right()){
                            centerRect_.setLeft(centerRect_.right() - sCenterRectMinWidth_);
                        }
                        if(centerRect_.bottom()-sCenterRectMinWidth_ < centerRect_.top()){
                            centerRect_.setBottom(centerRect_.top() + sCenterRectMinWidth_);
                        }
                    }


                }else if (obj == labelLeftTop_){
                    if(fixCenterRectRatio_ > 0){
                        if(std::abs(dx) > std::abs(dy)){
                            centerRect_.setLeft(std::max(rc.left() + dx , 0));
                            if(centerRect_.left()+sCenterRectMinWidth_ > centerRect_.right()){
                                centerRect_.setLeft(centerRect_.right() - sCenterRectMinWidth_);
                            }
                            centerRect_.setTop(rc.bottom() - centerRect_.width()/fixCenterRectRatio_);
                            if(centerRect_.top() < 0){
                                centerRect_.setTop(0);
                                centerRect_.setLeft(rc.right() - centerRect_.height()*fixCenterRectRatio_);
                            }
                        }else{
                            centerRect_.setTop(std::max(rc.top() + dy , 0));
                            if(centerRect_.bottom()-sCenterRectMinWidth_ < centerRect_.top()){
                                centerRect_.setTop(rc.bottom() - sCenterRectMinWidth_);
                            }
                            centerRect_.setLeft(rc.right() - centerRect_.height()*fixCenterRectRatio_);
                            if(centerRect_.left() < 0){
                                centerRect_.setLeft(0);
                                centerRect_.setTop(rc.bottom() - centerRect_.width()/fixCenterRectRatio_);
                            }
                        }
                    }else{
                        centerRect_.setLeft(rc.left() + dx);
                        centerRect_.setTop(rc.top() + dy);
                        if(centerRect_.left()+sCenterRectMinWidth_ > centerRect_.right()){
                            centerRect_.setLeft(centerRect_.right() - sCenterRectMinWidth_);
                        }
                        if(centerRect_.bottom()-sCenterRectMinWidth_ < centerRect_.top()){
                            centerRect_.setTop(centerRect_.bottom() - sCenterRectMinWidth_);
                        }
                    }


                }else if (obj == labelRightBottom_){
                    if(fixCenterRectRatio_ > 0){
                        if(std::abs(dx) > std::abs(dy)){
                            centerRect_.setRight(std::min(rc.right() + dx , this->width()-sLineWidth_));
                            if(centerRect_.left()+sCenterRectMinWidth_ > centerRect_.right()){
                                centerRect_.setRight(centerRect_.left() + sCenterRectMinWidth_);
                            }
                            centerRect_.setBottom(rc.top() + centerRect_.width()/fixCenterRectRatio_);
                            if(centerRect_.bottom() > this->height()-sLineWidth_){
                                centerRect_.setBottom(this->height() - sLineWidth_);
                                centerRect_.setRight(rc.left() + centerRect_.height()*fixCenterRectRatio_);
                            }
                        }else{
                            centerRect_.setBottom(std::min(rc.bottom() + dy , this->height()-sLineWidth_));
                            if(centerRect_.bottom()-sCenterRectMinWidth_ < centerRect_.top()){
                                centerRect_.setBottom(rc.top() + sCenterRectMinWidth_);
                            }
                            centerRect_.setRight(rc.left() + centerRect_.height()*fixCenterRectRatio_);
                            if(centerRect_.right() > this->width()-sLineWidth_){
                                centerRect_.setRight(this->width()-sLineWidth_);
                                centerRect_.setBottom(rc.top() + centerRect_.width()/fixCenterRectRatio_);
                            }
                        }
                    }else{
                        centerRect_.setRight(rc.right() + dx);
                        centerRect_.setBottom(rc.bottom() + dy);
                        if(centerRect_.left()+sCenterRectMinWidth_ > centerRect_.right()){
                            centerRect_.setRight(centerRect_.left() + sCenterRectMinWidth_);
                        }
                        if(centerRect_.bottom()-sCenterRectMinWidth_ < centerRect_.top()){
                            centerRect_.setBottom(centerRect_.top() + sCenterRectMinWidth_);
                        }
                    }


                }else if (obj == labelRightTop_){
                    if(fixCenterRectRatio_ > 0){
                        if(std::abs(dx) > std::abs(dy)){
                            centerRect_.setRight(std::min(rc.right() + dx , this->width()-sLineWidth_));
                            if(centerRect_.left()+sCenterRectMinWidth_ > centerRect_.right()){
                                centerRect_.setRight(centerRect_.left() + sCenterRectMinWidth_);
                            }
                            centerRect_.setTop(rc.bottom() - centerRect_.width()/fixCenterRectRatio_);
                            if(centerRect_.top() < 0){
                                centerRect_.setTop(0);
                                centerRect_.setRight(rc.left() + centerRect_.height()*fixCenterRectRatio_);
                            }
                        }else{
                            centerRect_.setTop(std::max(rc.top() + dy , 0));
                            if(centerRect_.bottom()-sCenterRectMinWidth_ < centerRect_.top()){
                                centerRect_.setTop(rc.bottom() - sCenterRectMinWidth_);
                            }
                            centerRect_.setRight(rc.left() + centerRect_.height()*fixCenterRectRatio_);
                            if(centerRect_.right() > this->width()-sLineWidth_){
                                centerRect_.setRight(this->width()-sLineWidth_);
                                centerRect_.setTop(rc.bottom() - centerRect_.width()/fixCenterRectRatio_);
                            }
                        }
                    }else{
                        centerRect_.setRight(rc.right() + dx);
                        centerRect_.setTop(rc.top() + dy);
                        if(centerRect_.left()+sCenterRectMinWidth_ > centerRect_.right()){
                            centerRect_.setRight(centerRect_.left() + sCenterRectMinWidth_);
                        }
                        if(centerRect_.bottom()-sCenterRectMinWidth_ < centerRect_.top()){
                            centerRect_.setTop(centerRect_.bottom() - sCenterRectMinWidth_);
                        }
                    }
                }
                this->update();
                return true;
            }
        }
        else if(e->type() == QEvent::MouseButtonRelease){
            dragZoomRunning_ = false;
            return true;
        }
    }
    return QWidget::eventFilter(obj, e);
}


