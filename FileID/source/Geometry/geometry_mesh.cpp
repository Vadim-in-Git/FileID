#include "geometry_mesh.h"
#include <iostream>
#include <string>
#include <fstream>

bool GeomMesh::load(std::istream& in) {
	for (std::string str; std::getline(in, str); )
		m_data += str + '\n';
	return in.eof();
}

bool GeomMesh::save(const std::string& path_file) const {
	if (path_file.rfind(IGeometry::extension) == std::string::npos)
		throw std::runtime_error("Invalid geometry extension: " + path_file);
	std::ofstream fout(path_file);
	if (!fout) throw std::runtime_error("Can't open file: " + path_file);
	fout << "Mesh\n" << m_data;
	return fout.good();
}

static class FactoryGeomMesh : public FactoryGeom {
public:
	FactoryGeomMesh() : FactoryGeom("Mesh") {}
	std::unique_ptr<IGeometry> create() override {
		return std::make_unique<GeomMesh>();
	};
} s_factory_geom_mesh;