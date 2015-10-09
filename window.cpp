#include "window.h"
#include "glwidget.h"
//#include "DataMgr.h"
//#include "GLPolyTracer.h"
//#include "GLTexPlaneTracer.h"
//#include "GLLineTracer.h"
//#include "GLLensTracer.h"
//#include "iostream"
//#include "defines.h"
//#include "MeshReader.h"
//#include "LineReader.h"
//#include "DTIVolumeReader.h"
//#include "GLSlice2DWidget.h"

//const int Window::btnSize[2] = { 60, 40 };

//QPushButton* Window::CreateRegularButton(const char* name)
//{
//	QPushButton* btn = new QPushButton(name, this);
//	btn->setMinimumSize(btnSize[0], btnSize[1]);
//	return btn;
//}

Window::Window()
{
    setWindowTitle(tr("Interactive Fiber Visualization"));
	QHBoxLayout *mainLayout = new QHBoxLayout;

	//DataMgr dataMgr;
	QSizePolicy fixedPolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);

	//this->move(100, 100);

	/********GL widget******/
	openGL = new GLWidget;
	QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(2, 0);
    format.setProfile(QSurfaceFormat::CoreProfile);
    openGL->setFormat(format); // must be called before the widget or its parent window gets shown
	
	///********cursor******/
	//MeshReader *sphere = new MeshReader();
	//sphere->SphereMesh(1.0f, 16, 16);
	//Tracer* sphereRenderable = new GLPolyTracer(sphere);//new glMeshRenderer ;
	//((GLPolyTracer*)sphereRenderable)->SetAmbientColor(0.2, 0.0, 0.0);
	//((GLPolyTracer*)sphereRenderable)->SetVisibility(false);
	//openGL->AddRenderable("cursor", sphereRenderable);

	///********slices******/
	//VolumeReader* image = new VolumeReader(dataMgr.GetConfig("image").c_str());
	//SlicePlaneRenderable0 = new GLTexPlaneTracer(image, 0);//new glMeshRenderer ;
	//openGL->AddRenderable("slice0", SlicePlaneRenderable0);
	//SlicePlaneRenderable1 = new GLTexPlaneTracer(image, 1);//new glMeshRenderer ;
	//openGL->AddRenderable("slice1", SlicePlaneRenderable1);
	//SlicePlaneRenderable2 = new GLTexPlaneTracer(image, 2);//new glMeshRenderer ;
	//openGL->AddRenderable("slice2", SlicePlaneRenderable2);

	/********tracts******/
	//DTIVolumeReader* image_dti = new DTIVolumeReader(dataMgr.GetConfig("image_dti").c_str());
	//LineReader* tract = new LineReader(dataMgr.GetConfig("tract").c_str());
	//lineRenderable = new GLLineTracer(tract);//new glMeshRenderer ;
	//((GLLineTracer*)lineRenderable)->SetDTIVolumeReader(image_dti);
	//openGL->AddRenderable("tract", lineRenderable);
	//openGL->SetLineReader(tract);

	///********lens******/
	//lensRenderable = new GLLensTracer();//new glMeshRenderer ;
	//((GLLensTracer*)lensRenderable)->SetVolumeReader(image);
	//openGL->AddRenderable("lens", lensRenderable);
	//QObject::connect((GLLensTracer*)lensRenderable, &GLLensTracer::DrawLensFinished, this, &Window::UpdateStatusLabel);

	///********slices 2D******/
	//QVBoxLayout *slice2DLayout = new QVBoxLayout;
	//GLSlice2DWidget* xSlice2DWidget = new GLSlice2DWidget((GLTexPlaneTracer*)SlicePlaneRenderable0);
	//GLSlice2DWidget* ySlice2DWidget = new GLSlice2DWidget((GLTexPlaneTracer*)SlicePlaneRenderable1);
	//GLSlice2DWidget* zSlice2DWidget = new GLSlice2DWidget((GLTexPlaneTracer*)SlicePlaneRenderable2);
	//slice2DLayout->addWidget(xSlice2DWidget);
	//slice2DLayout->addWidget(ySlice2DWidget);
	//slice2DLayout->addWidget(zSlice2DWidget);

	///********controls******/
	//QVBoxLayout *controlLayout = new QVBoxLayout;
	////controlLayout->setStretch()

	//addLensBtn = CreateRegularButton("Add Lens");
	//addNodeBtn = CreateRegularButton("Add Node");
	//QHBoxLayout* addThingsLayout = new QHBoxLayout;
	//addThingsLayout->addWidget(addLensBtn);
	//addThingsLayout->addWidget(addNodeBtn);
	//viewBtn = CreateRegularButton("Navigation");

	//QHBoxLayout* lenWidLayout = new QHBoxLayout;
	//QLabel* lensWidLabel = new QLabel("Lens Width:", this);
	//lensWidSlider = new QSlider(Qt::Horizontal);
	//lensWidSlider->setRange(1, 16);
	//lensWidSlider->setValue(((GLLensTracer*)lensRenderable)->GetLensWidth() * 10);
	//lensWidSlider->setFixedSize(120, 30);
	//lenWidLayout->addWidget(lensWidLabel);
	//lenWidLayout->addWidget(lensWidSlider);
	//connect(lensWidSlider, SIGNAL(valueChanged(int)), this, SLOT(LensWidSliderChanged(int)));

	//QHBoxLayout* transSizeLayout = new QHBoxLayout;
	//QLabel* transSizeLabel = new QLabel("Transition region size:", this);
	//QSlider* transSizeSlider = new QSlider(Qt::Horizontal);
	//transSizeSlider->setRange(0, 9);
	//transSizeSlider->setValue(((GLLineTracer*)lineRenderable)->GetTransSize() * 10);
	//transSizeSlider->setFixedSize(60, 30);
	//transSizeLayout->addWidget(transSizeLabel);
	//transSizeLayout->addWidget(transSizeSlider);
	//connect(transSizeSlider, SIGNAL(valueChanged(int)), this, SLOT(transSizeSliderChanged(int)));

	//QHBoxLayout* delThingsLayout = new QHBoxLayout;
	//QPushButton* delLens = CreateRegularButton("Delete Lens");
	//connect(delLens, SIGNAL(clicked()), this, SLOT(DeleteLens()));
	//QPushButton* delLensNode = CreateRegularButton("Delete Node");
	//connect(delLensNode, SIGNAL(clicked()), this, SLOT(DeleteLensNode()));
	//delThingsLayout->addWidget(delLens);
	//delThingsLayout->addWidget(delLensNode);

	//QPushButton* redoBtn = CreateRegularButton("Redo Deformation");
	//connect(redoBtn, SIGNAL(clicked()), this, SLOT(RedoDeform()));

	//statusLabel = new QLabel("status: Navigation");

	//QVBoxLayout *interactLayout = new QVBoxLayout;
	//QGroupBox *interactGrpBox = new QGroupBox(tr("Interactions"));
	//interactGrpBox->setSizePolicy(fixedPolicy);
	//interactLayout->addLayout(addThingsLayout);
	//interactLayout->addLayout(delThingsLayout);
	//interactLayout->addWidget(redoBtn);
	//interactLayout->addWidget(viewBtn);
	//interactLayout->addLayout(lenWidLayout);
	//interactLayout->addLayout(transSizeLayout);
	//interactLayout->addWidget(statusLabel);
	//interactGrpBox->setLayout(interactLayout);
	//controlLayout->addWidget(interactGrpBox);

	//connect(addLensBtn, SIGNAL(clicked()), this, SLOT(AddLens()));
	//connect(addNodeBtn, SIGNAL(clicked()), this, SLOT(AddLensNode()));
	//connect(viewBtn, SIGNAL(clicked()), this, SLOT(SetToNavigation()));


	///*************Lines***********/
	//QCheckBox* linesCheck = new QCheckBox("tracts", this);
	//linesCheck->setChecked(true);
	//QVBoxLayout *linesLayout = new QVBoxLayout;
	//linesLayout->addWidget(linesCheck);
	//QGroupBox *linesGrpBox = new QGroupBox(tr("Fiber Tracts"));
	//linesGrpBox->setSizePolicy(fixedPolicy);
	//linesGrpBox->setLayout(linesLayout);
	//controlLayout->addWidget(linesGrpBox);

	//connect(linesCheck, SIGNAL(clicked(bool)), this, SLOT(linesToggled(bool)));

	///*************Models***********/
	//QVBoxLayout *meshLayout = new QVBoxLayout;
	//QGroupBox *meshGrpBox = new QGroupBox(tr("3D Models"));
	//meshGrpBox->setSizePolicy(fixedPolicy);
	//meshGrpBox->setLayout(meshLayout);
	//std::map<std::string, std::string> meshFiles = dataMgr.GetMeshFiles();
	//for (auto m : meshFiles) {
	//	MeshReader *meshReader = new MeshReader();
	//	meshReader->LoadPLY(m.second.c_str());
	//	Tracer* mesh_renderable = new GLPolyTracer(meshReader);//new glMeshRenderer ;
	//	openGL->AddRenderable(m.first.c_str(), mesh_renderable);
	//	meshTracers[m.first.c_str()] = mesh_renderable;
	//	((GLPolyTracer*)mesh_renderable)->SetAmbientColor(0.0, 0.2, 0.2);

	//	QCheckBox* meshCheck = new QCheckBox(m.first.c_str(), this);
	//	meshCheck->setChecked(true);
	//	meshCheckBoxes[m.first.c_str()] = meshCheck;
	//	meshLayout->addWidget(meshCheck);
	//	connect(meshCheck, SIGNAL(clicked(bool)), this, SLOT(MeshToggled(bool)));
	//}
	//controlLayout->addWidget(meshGrpBox);

	///*************Slices***********/
	//QCheckBox* xSliceCheck = new QCheckBox("x:", this);
	//QCheckBox* ySliceCheck = new QCheckBox("y:", this);
	//QCheckBox* zSliceCheck = new QCheckBox("z:", this);
	//xSliceCheck->setStyleSheet("QCheckBox { color: red }");
	//ySliceCheck->setStyleSheet("QCheckBox { color: green }");
	//zSliceCheck->setStyleSheet("QCheckBox { color: blue }");
	//xSliceCheck->setChecked(true);
	//ySliceCheck->setChecked(true);
	//zSliceCheck->setChecked(true);
	//xSlider = CreateSliceSlider((TexPlaneTracer*)SlicePlaneRenderable0);
	//ySlider = CreateSliceSlider((TexPlaneTracer*)SlicePlaneRenderable1);
	//zSlider = CreateSliceSlider((TexPlaneTracer*)SlicePlaneRenderable2);
	//xSlider->setFixedSize(150, 30);
	//ySlider->setFixedSize(150, 30);
	//zSlider->setFixedSize(150, 30);
	//QVBoxLayout *slicerLayout = new QVBoxLayout;
	//QGroupBox *slicerGrpBox = new QGroupBox(tr("Slicer Control"));
	//slicerGrpBox->setSizePolicy(fixedPolicy);
	//QHBoxLayout *xSliceLayout = new QHBoxLayout;
	//QHBoxLayout *ySliceLayout = new QHBoxLayout;
	//QHBoxLayout *zSliceLayout = new QHBoxLayout;
	//xSliceLayout->addWidget(xSliceCheck);
	//xSliceLayout->addWidget(xSlider);
	//ySliceLayout->addWidget(ySliceCheck);
	//ySliceLayout->addWidget(ySlider);
	//zSliceLayout->addWidget(zSliceCheck);
	//zSliceLayout->addWidget(zSlider);
	//slicerLayout->addLayout(xSliceLayout);
	//slicerLayout->addLayout(ySliceLayout);
	//slicerLayout->addLayout(zSliceLayout);
	//slicerGrpBox->setLayout(slicerLayout);
	//controlLayout->addWidget(slicerGrpBox);
	//controlLayout->addStretch();

	//connect(xSlider, SIGNAL(valueChanged(int)), this, SLOT(XSliderChanged(int)));
	//connect(ySlider, SIGNAL(valueChanged(int)), this, SLOT(YSliderChanged(int)));
	//connect(zSlider, SIGNAL(valueChanged(int)), this, SLOT(ZSliderChanged(int)));

	//connect(xSliceCheck, SIGNAL(clicked(bool)), this, SLOT(xSliceToggled(bool)));
	//connect(ySliceCheck, SIGNAL(clicked(bool)), this, SLOT(ySliceToggled(bool)));
	//connect(zSliceCheck, SIGNAL(clicked(bool)), this, SLOT(zSliceToggled(bool)));
	//
	//mainLayout->addLayout(slice2DLayout, 1);
	mainLayout->addWidget(openGL, 3);
	//mainLayout->addLayout(controlLayout);
	setLayout(mainLayout);
}
//
//void Window::XSliderChanged(int i)
//{
//	((GLTexPlaneTracer*)SlicePlaneRenderable0)->SetSliceNum(i);
//	((GLTexPlaneTracer*)SlicePlaneRenderable0)->UpdateData();
//}
//
//void Window::YSliderChanged(int i)
//{
//	((GLTexPlaneTracer*)SlicePlaneRenderable1)->SetSliceNum(i);
//	((GLTexPlaneTracer*)SlicePlaneRenderable1)->UpdateData();
//}
//
//void Window::ZSliderChanged(int i)
//{
//	((GLTexPlaneTracer*)SlicePlaneRenderable2)->SetSliceNum(i);
//	((GLTexPlaneTracer*)SlicePlaneRenderable2)->UpdateData();
//}
//
//void Window::LensWidSliderChanged(int i)
//{
//	((GLLensTracer*)lensRenderable)->UpdateLensWidth(i * 0.1f);
//}
//
//void Window::transSizeSliderChanged(int i)
//{
//	((GLLineTracer*)lineRenderable)->SetTransSize( 1 - i * 0.1f);
//}
//
//
//void Window::xSliceToggled(bool b)
//{
//	((GLTexPlaneTracer*)SlicePlaneRenderable0)->SetVisibility(b);
//}
//
//void Window::linesToggled(bool b)
//{
//	((GLLineTracer*)lineRenderable)->SetVisibility(b);
//}
//
//
//void Window::ySliceToggled(bool b)
//{
//	((GLTexPlaneTracer*)SlicePlaneRenderable1)->SetVisibility(b);
//}
//
//void Window::zSliceToggled(bool b)
//{
//	((GLTexPlaneTracer*)SlicePlaneRenderable2)->SetVisibility(b);
//}
//
//void Window::MeshToggled(bool b)
//{
//	for (auto m : meshCheckBoxes) {
//		meshTracers[m.first]->SetVisibility(m.second->isChecked());
//	}
//}
//
//void Window::DeleteLens()
//{
//	bool anyLens = ((GLLensTracer*)lensRenderable)->RemoveOneLens();
//	//if (!anyLens)
//	//	viewBtn->setChecked(true);
//	openGL->SetInteractModeToTransform();
//	UpdateStatusLabel();
//}
//
//void Window::DeleteLensNode()
//{
//	((GLLensTracer*)lensRenderable)->RemoveLensNode();
//	UpdateStatusLabel();
//}
//
//void Window::RedoDeform()
//{
//	((GLLineTracer*)lineRenderable)->RedoDeformation();
//	UpdateStatusLabel();
//}
//
//void Window::AddLens()
//{
//	openGL->AddLens();
//	lensWidSlider->setValue(((GLLensTracer*)lensRenderable)->GetLensWidth() * 10);
//	UpdateStatusLabel();
//}
//
//void Window::SetToNavigation()
//{
//	openGL->SetInteractModeToTransform();
//	UpdateStatusLabel();
//}
//
////void Window::InteractModeChanged()
////{
////	if (addLensBtn->isChecked())
////	{
////	}
////	else if (viewBtn->isChecked())
////}
//
//void Window::AddLensNode()
//{
//	openGL->AddLensNode();
//	UpdateStatusLabel();
//}

Window::~Window() {
}

//QSlider* Window::CreateSliceSlider(TexPlaneTracer* renderable)
//{
//	QSlider* slider;
//	slider = new QSlider(Qt::Horizontal);
//	slider->setRange(0, renderable->GetNumOfSlices() - 1);
//	slider->setValue(renderable->GetSliceNum());
//	return slider;
//}
//
//void Window::UpdateStatusLabel()
//{
//	QString status;
//	switch (openGL->GetInteractMode())
//	{
//	case INTERACT_MODE::ADD_NODE:
//		status = QString("status: Add lens or node");
//		break;
//	case INTERACT_MODE::MODIFY_LENS:
//		status = QString("status: Manipulate lens");
//		break;
//	case INTERACT_MODE::TRANSFORMATION:
//		status = QString("status: Navigation");
//		break;
//	}
//	statusLabel->setText(status);
//}