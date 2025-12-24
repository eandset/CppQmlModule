#pragma once

#include <QQuickItem>
#include <QString>

class CppText : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    QML_ELEMENT
    
public:
    explicit CppText(QQuickItem *parent = nullptr);
    
    QString text() const;
    void setText(const QString &text);

    Q_INVOKABLE QString getText();
    
signals:
    void textChanged();
    
protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *data) override;
    
private:
    QString m_text = "Fuck";
};
