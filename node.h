/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

//To use this header file in a .cpp file, you may need to include:
//#include "TextureCubeManager.h"

#ifndef NODE_H
#define NODE_H

using namespace std;

#include <QGraphicsItem>
#include <QList>
//#include "TextureCubeManager.h"
#include "DataManager.h"

class Edge;
class GraphWidget;
class QGraphicsSceneMouseEvent;
class NodeBi;
class TextureCubeManager;

namespace Widget
{
	class Node : public QGraphicsItem
	{
	public:
		double RADIUS = 0.5;

		Node(GraphWidget *graphWidget, TextureCubeManager * textureCubeManager);

		void setNodeBiPtr(NodeBi * _nodeBiPtr) { this->nodeBiPtr = _nodeBiPtr; }
		NodeBi * getNodeBiPtr() { return nodeBiPtr; }
		void addEdge(Edge *edge);
		QList<Edge *> edges() const;

		enum { Type = UserType + 1 };
		int type() const Q_DECL_OVERRIDE{ return Type; }

		void calculateForces();
		bool advance();

		QRectF boundingRect() const Q_DECL_OVERRIDE;
		QPainterPath shape() const Q_DECL_OVERRIDE;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
		void SetChildrenVisibility(NodeBi *nd, bool _isVisible);
		void setForeDisplayColor(QColor foreDisplayColor) { this->foreDisplayColor = foreDisplayColor; }
		void setBackDisplayColor(QColor backDisplayColor) { this->backDisplayColor = backDisplayColor; }
		void setName(string name) { this->name = name; }
		string getName() { return name; }

	protected:
		QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;

		void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
		void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
		//void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
		void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE;

	private:
		QList<Edge *> edgeList;
		QPointF newPos;
		GraphWidget *graph;  //Pointer to the larger graph widget
		NodeBi * nodeBiPtr;  //Pointer to our interal tree data structure - used for either an entropy tree or a merger tree
		QColor foreDisplayColor;
		QColor backDisplayColor;
		string name;		//Name as loaded from GraphViz dot output file
		TextureCubeManager * textureCubeManager;
	};
};

#endif // NODE_H