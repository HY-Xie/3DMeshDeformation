#include <iostream>
#include "Differential_Coordinates.hpp"
#include "Validate_Differential_Coordinate.hpp"
#include <string>


int main(void)
{
	TriMesh mesh;
	//if (!OpenMesh::IO::read_mesh(mesh, "../../data/tours.obj"))
	if (!OpenMesh::IO::read_mesh(mesh, "../../data/monkey.obj"))
	//if (!OpenMesh::IO::read_mesh(mesh, "../../data/simple_square.obj"))
	//if (!OpenMesh::IO::read_mesh(mesh, "../../data/sphere_small.obj"))
	{
		std::cerr << "Model Load Error" << std::endl;
		system("pause");
		return -1;
	}
	else
		std::cout << "Model Load Success" << std::endl;

	// 1.1 ֱ�Ӱ��ն������΢������
	std::cout << "---------------1.1 ֱ�Ӱ��ն������΢������--------------" << std::endl;
	Eigen::MatrixXd diffCoord_definition = buildDifferentialCoord_fromDefinition(mesh);
	//std::cout << diffCoord_definition << std::endl;
	

	// 1.2 ���� M*P=D ����΢������
	std::cout << "---------------1.2 ���� M*P=D ����΢������--------------" << std::endl;
	Eigen::MatrixXd diffCoord_laplace = buildDifferentialCoord_laplace(mesh);
	//std::cout << diffCoord_laplace << std::endl;

	isEqual(diffCoord_definition, diffCoord_laplace);

	// ����֤1.1 �� 1.2 �ļ�������ͬ������ֻ��1.2 �Ľ������
	validate_differential_coordiate(diffCoord_laplace, mesh);

	
	computeOriginalMesh(diffCoord_laplace, mesh);



	system("pause");
	return 0;
}