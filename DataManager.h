#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H
#include <vector>
#include <cuda/vector_types.h>
#include <cuda/vector_functions.h>
#include "OSUFlow.h"
#include "glSuperquadric.h"
#include "node.h"
#include <unordered_map>

//1 means flow data
//2 means cosmology data
const int application = 2;

namespace Widget
{
	class Node;
}

using namespace std;
//struct Node
//{
//	float *cubemap;
//	int cube_size;
//
//	int start[3];
//	int dim[3];
//	int level;	//hierarchy level
//	//int3 *data;
//	vector<Node*> children;
//	float entropy;
//	//only outgoing flux is recorded, so that we only draw the link once for the two neighboring nodes
//	float flux[6];	//0: -x  1: +x   2: -y   3: +y   4: -z   5:+z
//
//	Node* neighbor[6];
//
//	void init(
//		int _start0, int _start1, int _start2, 
//		int _dim0, int _dim1, int _dim2,
//		int _cube_size, int _level)
//	{
//		//cubemap = _cubemap;
//		cube_size = _cube_size;
//		//data = _data;
//
//		start[0] = _start0;
//		start[1] = _start1;
//		start[2] = _start2;
//
//		dim[0] = _dim0;
//		dim[1] = _dim1;
//		dim[2] = _dim2;
//		//left = nullptr;
//		//right = nullptr;
//		cubemap = nullptr;
//
//		level = _level;
//
//		for (int i = 0; i < 6; i++)	{
//			neighbor[i] = nullptr;
//			flux[6] = 0;
//		}
//	}
//
//
//
//	Node(){
//		cubemap = nullptr;
//	};
//
//	Node(
//		int _start0, int _start1, int _start2, 
//		int _dim0, int _dim1, int _dim2,
//		int _cube_size, int _level)
//	{
//		init(_start0, _start1, _start2, 
//		_dim0, _dim1, _dim2,
//		_cube_size, _level);
//	}
//
////	Node(int *_start, int *_dim, int _cube_size, int _level);
//	Node(int *_start, int *_dim, int _cube_size, int _level)
//	{
//		init(_start[0], _start[1], _start[2],
//		_dim[0], _dim[1], _dim[2],
//		_cube_size, _level);
//	}
//
//
//	~Node()
//	{
//		//delete[] data;
//		if (cubemap != nullptr)
//		{
//			delete[] cubemap;
//			//cubemap = nullptr;
//		}
//		for (auto nd : children)	{
//			delete[] nd;
//		}
//		//delete[] left;
//		//delete[] right;
//	}
//};
//
//

class AbstractNode
{
protected:
	int start[3];
	int dim[3];
	float *cubemap;
	int cube_size;
	float entropy;

	float3 eigval;
	float3 eigvec[3];

	Widget::Node * graphNode = nullptr;
	AbstractNode * haloNode = nullptr;
	GLSuperquadric* glyph;
	bool isVisible = true;
	bool isSelected = false;
public:
	bool GetVisible(){ return isVisible; }
	void SetVisible(bool b){ isVisible = b; }
	bool GetSelected() { return isSelected; }
	void SetSelected(bool isSelected) { this->isSelected = isSelected; }
	Widget::Node* GetGraphNode(){ return graphNode; }
	void SetGraphNode(Widget::Node* n) { graphNode = n; }
	AbstractNode * GetHaloNode() { return haloNode; }
	void setHaloNode(AbstractNode * haloNode) { this->haloNode = haloNode; }
	//virtual vector<AbstractNode*> GetAllNode() = 0;
	GLSuperquadric* GetGlyph(){ return glyph; }
	float* GetCubemap(){ return cubemap; }

	void GetDim(int* _dim)
	{
		for (int i = 0; i < 3; i++)
			_dim[i] = dim[i];
	}

	void GetStart(int* _start)
	{
		for (int i = 0; i < 3; i++)
			_start[i] = start[i];
	}

	AbstractNode(int _cube_size)
	{
		cube_size = _cube_size;
	}

	AbstractNode(){}

};

class DataManager
{
protected:
	int currentTimeStep = 100;
	int startTimeStep = 100;
	int cubemap_size;
	int start[3];
	int dim[3];
	int qCubePos[3], qCubeSize[3];	//queried cube position and sizes
	map<string, string> valStrings;

	bool CubeInsideVolumeX(int x, int nx);
	bool CubeInsideVolumeY(int x, int nx);
	bool CubeInsideVolumeZ(int x, int nx);
	unordered_map<int, AbstractNode *> haloTable;  //Hash table to link halo ids to Halo struct records

public:
	virtual void LoadData() = 0;
	virtual vector<AbstractNode*> GetAllNode() = 0;
	virtual AbstractNode* getRootNode() = 0/*{ return rootNode; }*/;
	virtual vector<vector<float4>> GetStreamlines() = 0;
	virtual void GenStreamInCube() = 0;
	virtual void GetBlock(int3* datablock, int x, int y, int z, int nx, int ny, int nz) = 0;
	virtual void GenCubeMap(int x, int y, int z, int nx, int ny, int nz, float* &cubemap) = 0;
	virtual void UpdateCubeMap(float* cubemap) = 0;

	int GetCubemapSize();
	void GetVolumeSize(int &nx, int &ny, int&nz);
	void GetQCube(int &x, int &y, int &z, int &nx, int &ny, int &nz);
	void SetQCube(int x, int y, int z, int nx, int ny, int nz);
	void MoveCube(int x, int y, int z);
	void LoadParameters();
	string GetStringVal(string name);
	unordered_map<int, AbstractNode *> * getHaloTable() { return &haloTable; }
	int getCurrentTimeStep() { return currentTimeStep; }
	void setCurrentTimeStep(int currentTimeStep) { this->currentTimeStep = currentTimeStep; }
	int getStartTimeStep() { return startTimeStep; }
	void setStartTimeStep(int startTimeStep) { this->startTimeStep = startTimeStep; }

	DataManager();
	~DataManager();
};

#endif //DATA_MANAGER_H