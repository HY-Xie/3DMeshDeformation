#pragma once

#include <Helper/Helper.hpp>

void laplacianValidate(const SpMat & L);

// 5.3.1 ����������˹
SpMat buildLaplacianCot(const TriMesh &mesh);


// 5.3.2 �������������˹
SpMat buildLaplacianCotArea(const TriMesh &mesh);

// 5.3.3 ��ֵ������˹
SpMat buildLaplacianMeanValue(const TriMesh &mesh);
