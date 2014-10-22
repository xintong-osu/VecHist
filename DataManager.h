#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H
#include <vector>
#include <vector_types.h>

class DataManager
{
	float* data;
	std::vector<std::vector<double> > vV;
	std::vector<std::vector<int> > vF;
	std::vector<float> vertexValue;
	std::vector<std::vector<double> > vVScaled;
public:
	void LoadVec(char* filename);
	std::vector<std::vector<double> > GetVertexPos();
	std::vector<std::vector<double> > GetScaledVertexPos();
	std::vector<std::vector<int> > GetFaceVertices();
	std::vector<float> GetVertexValue();
	std::vector<float3> GetBlock(int x, int y, int z, int nx, int ny, int nz);
	~DataManager();
};

#endif //DATA_MANAGER_H