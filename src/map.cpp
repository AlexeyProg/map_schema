#include "map.h"

MapWidget::MapWidget(QString path, QWidget *parent) : path(path), QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    setScene(scene);
    setImage(path);
    pix_item = new QGraphicsPixmapItem(pix_map);
    scene->addItem(pix_item);
    fitInView(pix_item, Qt::KeepAspectRatio);

    this->scale(map_real_factor, map_real_factor);
}

void MapWidget::setImage(QString &image_path)
{
    pix_map.load(image_path);
    //pix_map.scaled(QSize(1000,1000),Qt::IgnoreAspectRatio);
}

MapWidget::~MapWidget()
{
}

void MapWidget::getCircle()
{
    QPixmap cir_mp(":/circle.png");
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(cir_mp);
    qreal factor = 0.3;
    item->setScale(factor);
    item_list.push_back(item);
    QRectF visibleArea = mapToScene(rect()).boundingRect();
    item->setPos(visibleArea.center());
    scene->addItem(item);
}

void MapWidget::increase_map()
{
    map_real_factor += - 0.2;
    this->scale(map_real_factor,map_real_factor);
}
