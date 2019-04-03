#ifndef QOPENWIDGET_H
#define QOPENWIDGET_H

#include <qopenglwidget.h>
#include <qopenglfunctions_3_3_compatibility>
#include <qopenglfunctions_4_3_compatibility>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <qopenglvertexarrayobject.h>
#include <qpushbutton.h>
#include <qtimer.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class QOPenWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Compatibility
{
	Q_OBJECT
public:
	QOPenWidget(QWidget *parent = 0);
	~QOPenWidget();
private:
	float QOPenWidget::getQtTime();
private:
	bool firstMouse;
	float yaw;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
	float pitch;
	float lastX;
	float lastY;
	float fov;
protected:
	void mouseMoveEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);
private:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();
	//dhlu
	GLuint texture[2];
	QImage tex1, tex2, tex3, buf1, buf2, buf3;//you must put them here,because opengl use their mem at other place.
	void ReadImage();
	//end dhlu
	//加载着色器程序
	void CompileShader(unsigned int *id, const char* vertexPath, const char* fragmentPath, const char* geometryPath = NULL);
private:
	//缓存对象
	unsigned int VBO, VAO, EBO;

	//着色器程序ID
	unsigned int ID;

	//定时器
	QTimer timer;
};

#endif 