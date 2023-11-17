#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "list"

using namespace std;

class MapWidget : public QGraphicsView
{
    Q_OBJECT
public:
    MapWidget(QString path, QWidget *parent = nullptr);
    QPixmap pix_map;
    void setImage(QString &image_path);
    QString path;
    qreal map_real_factor = 1.6;
    ~MapWidget();
public slots:
    void getCircle();
    void increase_map();
private:
    QGraphicsPixmapItem *pix_item;
    QGraphicsScene *scene;
    list<QGraphicsPixmapItem*>item_list;
};

#endif // MAPWIDGET_H
