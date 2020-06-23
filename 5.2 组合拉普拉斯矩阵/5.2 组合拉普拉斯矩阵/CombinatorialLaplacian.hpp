#pragma once
//#include <Helper/Helper.hpp>
#include <Vertex2Vertex.hpp>
// ��֤
void laplacianValidate(const SpMat & L);

// 5.1.1 ����������˹����
SpMat buildLaplacianDegree(const TriMesh &mesh);

// 5.1.2 Tutte������˹
SpMat buildLaplacianTutte(const TriMesh &mesh);


// 5.1.3 ��һ��ͼ��������˹
SpMat builLaplacianNormalizedGraph(const TriMesh &mesh);





