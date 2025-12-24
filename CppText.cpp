#include "CppText.h"
#include <QSGSimpleRectNode>
#include <QSGSimpleTextureNode>
#include <QQuickWindow>
#include <QPainter>
#include <QFont>
#include <ctime>

CppText::CppText(QQuickItem *parent)
    : QQuickItem(parent)
{
    setFlag(ItemHasContents, true);
}

QString CppText::text() const
{
    return m_text;
}

void CppText::setText(const QString &text)
{
    if (m_text != text) {
        m_text = text;
        update();
        emit textChanged();
    }
}

QString CppText::getText()
{
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);

    return asctime(timeinfo);
}

QSGNode *CppText::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *data)
{
    Q_UNUSED(data);
    
    if (!window()) return oldNode;
    
    // Создаем текстуру для отрисовки текста
    QSGSimpleTextureNode *node = static_cast<QSGSimpleTextureNode*>(oldNode);
    if (!node) {
        node = new QSGSimpleTextureNode();
    }
    
    // Создаем изображение с текстом
    QImage image(boundingRect().size().toSize(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // Рисуем текст
    painter.setPen(Qt::white);
    painter.setFont(QFont("Arial", 16));

    painter.drawText(image.rect(), Qt::AlignCenter, m_text);
    
    painter.end();
    
    if (node->texture()) {
        delete node->texture();
    }
    
    QSGTexture *texture = window()->createTextureFromImage(image);
    node->setTexture(texture);
    node->setRect(boundingRect());
    
    return node;
}

