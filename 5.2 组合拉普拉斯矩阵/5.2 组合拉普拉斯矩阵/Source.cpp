#include <iostream>
#include "CombinatorialLaplacian.hpp"

int main(void)
{
	TriMesh mesh; 
	if (!OpenMesh::IO::read_mesh(mesh, "../../data/graph.off"))
	//if (!OpenMesh::IO::read_mesh(mesh, "../../data/simple_square.obj"))
		std::cerr << "Mesh Load Failed." << std::endl;
	else
		std::cout << "Success." << std::endl;

	// 5.1.1 ����������˹����
	std::cout << "----------5.1.1 ����������˹����----------" << std::endl;
	SpMat degreeLaplaican = buildLaplacianDegree(mesh);
	std::cout << degreeLaplaican << std::endl;
	laplacianValidate(degreeLaplaican);

	// 5.1.2 Tutte������˹����
	std::cout << "----------5.1.2 Tutte������˹����----------" << std::endl;
	SpMat tutteLaplaican = buildLaplacianTutte(mesh);
	std::cout << tutteLaplaican << std::endl;
	laplacianValidate(tutteLaplaican);

	// 5.1.3 ��һ��ͼ��������˹
	std::cout << "----------5.1.3 ��һ��ͼ��������˹----------" << std::endl;
	SpMat normalizedGraphLaplacian = builLaplacianNormalizedGraph(mesh);
	std::cout << normalizedGraphLaplacian << std::endl;
	laplacianValidate(normalizedGraphLaplacian);




	system("pause");
	return 0;
}

// ���
/*
Success.
----------5.1.1 ����������˹����----------
Nonzero entries:
(2,0) (-1,1) (-1,2) (-1,0) (3,1) (-1,2) (-1,3) (-1,0) (-1,1) (4,2) (-1,3) (-1,5) (-1,1) (-1,2) (4,3) (-1,4) (-1,5) (-1,3) (2,4) (-1,5) (-1,2) (-1,3) (-1,4) (3,5)

Outer pointers:
0 3 7 12 17 20  $

2 -1 -1 0 0 0
-1 3 -1 -1 0 0
-1 -1 4 -1 0 -1
0 -1 -1 4 -1 -1
0 0 0 -1 2 -1
0 0 -1 -1 -1 3

ÿ�к�Ϊ��.
�Գƾ���
----------5.1.2 Tutte������˹����----------
Nonzero entries:
(1,0) (-0.333333,1) (-0.25,2) (-0.5,0) (1,1) (-0.25,2) (-0.25,3) (-0.5,0) (-0.333333,1) (1,2) (-0.25,3) (-0.333333,5) (-0.333333,1) (-0.25,2) (1,3) (-0.5,4) (-0.333333,5) (-0.25,3) (1,4) (-0.333333,5) (-0.25,2) (-0.25,3) (-0.5,4) (1,5)

Outer pointers:
0 3 7 12 17 20  $

1 -0.5 -0.5 0 0 0
-0.333333 1 -0.333333 -0.333333 0 0
-0.25 -0.25 1 -0.25 0 -0.25
0 -0.25 -0.25 1 -0.25 -0.25
0 0 0 -0.5 1 -0.5
0 0 -0.333333 -0.333333 -0.333333 1

ÿ�к�Ϊ��.
�ǶԳ�
----------5.1.3 ��һ��ͼ��������˹----------
Nonzero entries:
(-0.408248,1) (-0.353553,2) (-0.408248,0) (-0.288675,2) (-0.288675,3) (-0.353553,0) (-0.288675,1) (-0.25,3) (-0.288675,5) (-0.288675,1) (-0.25,2) (-0.353553,4) (-0.288675,5) (-0.353553,3) (-0.408248,5) (-0.288675,2) (-0.288675,3) (-0.408248,4)

Outer pointers:
0 2 5 9 13 15  $

0 -0.408248 -0.353553 0 0 0
-0.408248 0 -0.288675 -0.288675 0 0
-0.353553 -0.288675 0 -0.25 0 -0.288675
0 -0.288675 -0.25 0 -0.353553 -0.288675
0 0 0 -0.353553 0 -0.408248
0 0 -0.288675 -0.288675 -0.408248 0

����ÿ�к�Ϊ��.
�Գƾ���
Press any key to continue . . .
*/